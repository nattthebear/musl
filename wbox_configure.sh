#!/bin/sh
set -e
if [ -z "$SYSROOT" ]; then export SYSROOT="$(realpath "$(dirname "$0")/../sysroot")"; fi

export CC="clang"
export LDFLAGS="-Wl,-no-pie -fuse-ld=lld"
export CFLAGS="-Werror -fvisibility=hidden -mcmodel=large -mstack-protector-guard=global -fno-pic -fno-pie" # TODO: Add -flto
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
./configure --target=waterbox --build=waterbox --disable-shared --prefix="$SYSROOT" --syslibdir="$SYSROOT/syslib"
