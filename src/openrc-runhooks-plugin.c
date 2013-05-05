/* openrc-runhooks-plugin.c - Run-hooks plugin for the OpenRC init system
 *
 * Copyright (C) 2013 Hacking Networked Solutions Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>
#include <einfo.h>
#include <rc.h>
#include <dirent.h>
#include <sys/stat.h>
#include "include/config.h"


//#define DEBUG


RC_STRINGLIST * ls_dir(const char *dir)
{
	DIR *dp;
	struct dirent *d;
	struct stat buf;
	size_t l;
	char file[PATH_MAX];
	int r;
	RC_STRINGLIST *list;

	list = rc_stringlist_new();

	if ((dp = opendir(dir)) == NULL)
		return list;

	while (((d = readdir(dp)) != NULL))
	{
		if (d->d_name[0] != '.')
		{
			/* Check that our file really exists.  This is important as a hook link may be
			 * in a directory, but the actual script could have been removed. */
			snprintf(file, sizeof(file), "%s/%s", dir, d->d_name);
			r = stat(file, &buf);
			if (r != 0)
				continue;

			rc_stringlist_add(list, d->d_name);
		}
	}
	closedir(dp);
	return list;
}

void run_scripts_in_dir(const char *dir, const char *name)
{
	RC_STRING 		*script;
	RC_STRINGLIST 	*script_list;
	char 			file[PATH_MAX];
	int				rv;

	#ifdef DEBUG
		einfo(PACKAGE " run_scripts_in_dir(%s)", dir);
	#endif

	script_list = ls_dir(dir);

	TAILQ_FOREACH(script, script_list, entries)
	{
		snprintf(file, PATH_MAX, "%s/%s %s", dir, script->value, name);
		rv = system(file);
		#ifdef DEBUG
			einfo(PACKAGE " script [%s] returned %d ", file, rv);
		#endif
	}

	rc_stringlist_free(script_list);
}


int rc_plugin_hook(const RC_HOOK hook, const char *name)
{
	switch(hook)
	{
		case RC_HOOK_SYSTEM_START_FINISHED:
			/* We have finished starting up */
			run_scripts_in_dir(RC_HOOKS_DIR "/post-startup", name);
			break;
		case RC_HOOK_SYSTEM_STOP_INITIATED:
			/* We are starting to shut down */
			run_scripts_in_dir(RC_HOOKS_DIR "/pre-shutdown", name);
			break;
		default:
			break;
	}

	return 0;
}
