#!/bin/sh

export WANT_AUTOCONF=2.5

libtoolize --force --copy --quiet
aclocal -I m4
autoheader
automake --add-missing --copy --foreign
autoconf
rm -rf autom4te.cache
