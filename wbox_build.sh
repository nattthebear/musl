#!/bin/sh
set -e
if [ -z "$SYSROOT" ]; then export SYSROOT="$(realpath "$(dirname "$0")/../sysroot")"; fi

mkdir -p "$SYSROOT"
make
make install
# To uselibclang-rt (and libunwind), we need to evict the gcc libs, but musl automatically puts that in the specs file and has no setting to remove it. Fix that now by clearing the 13th line.
cd "$SYSROOT/lib"
cp "musl-gcc.specs" "musl-gcc.broken.specs"
awk 'NR==13{print""};NR!=13' "musl-gcc.broken.specs" >"musl-gcc.specs" # clears the line after "*libgcc:"
rm "musl-gcc.broken.specs"
