#!/bin/sh
set -e
if [ -z "$SYSROOT" ]; then export SYSROOT="$(realpath "$(dirname "$0")/../sysroot")"; fi

export LDFLAGS=""
export CFLAGS="-Werror -fvisibility=hidden -mcmodel=large -mstack-protector-guard=global -no-pie -fno-pic -fno-pie" # TODO: Add -flto
export AR="gcc-ar"
export RANLIB="gcc-ranlib"
./configure --target=waterbox --build=waterbox --disable-shared --prefix="$SYSROOT" --syslibdir="$SYSROOT/syslib"
