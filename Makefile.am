# Makefile.am - Run-hooks plugin for the OpenRC init system
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

plugindir=$(DESTDIR)/lib/rc/plugins
plugin_LTLIBRARIES=openrc-runhooks-plugin.la
openrc-runhooks-plugin_la_SOURCES = src/openrc-runhooks-plugin.c
openrc-runhooks-plugin_la_LDFLAGS=-module -avoid-version -shared
