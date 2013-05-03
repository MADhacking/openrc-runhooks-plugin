# configure.ac - Run-hooks plugin for the OpenRC init system
#
# Copyright (C) 2013 Hacking Networked Solutions Ltd
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

dnl Ensure a recent version of Autoconf.
AC_PREREQ([2.68])

dnl Initialise the Autoconf system.
AC_INIT(openrc-runhooks-plugin, 1.0)

dnl Configure m4 macro directory.
AC_CONFIG_MACRO_DIR([m4])

dnl Configure auxillary directory.
AC_CONFIG_AUX_DIR([aux_dir])

dnl Determine system type.
AC_CANONICAL_SYSTEM

dnl Initialize automake.
AM_INIT_AUTOMAKE([])

dnl Locate suitable tools.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P
AM_PROG_CC_C_O 

dnl Initialize Libtool.
LT_INIT

dnl Check if Libtool is present.
AC_PROG_LIBTOOL

dnl Check for correct source directory.
AC_CONFIG_SRCDIR([src/openrc-runhooks-plugin.c])

nl Set the location of the autoconf generated config.h.
AM_CONFIG_HEADER(include/config.h:aux_dir/config.in)

dnl Set the location of the makefiles.
AC_CONFIG_FILES([Makefile])

dnl Generate config.status and launch it.
AC_OUTPUT
