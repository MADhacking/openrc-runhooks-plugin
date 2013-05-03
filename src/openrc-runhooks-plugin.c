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

#include <einfo.h>
#include <rc.h>


#ifdef DEBUG
#    define DBG(x) einfo("[openrc-runhooks-plugin] " x)
#else
#    define DBG(x)
#endif


int rc_plugin_hook(const RC_HOOK hook, const char *name)
{
    int rv = 0;
    char* runlevel = rc_runlevel_get();
    const char* bootlevel = getenv("RC_BOOTLEVEL");
    const char* defaultlevel = getenv("RC_DEFAULTLEVEL");

#ifdef DEBUG
    einfo("hook=%d name=%s runlvl=%s", hook, name, runlevel);
#endif

exit:
    free(runlevel);
    return rv;
}
