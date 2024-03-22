#!/usr/bin/env bash
echo "Patch antigrain"
patchdir="$(dirname "$0")/agg_patch_files"
aggdir="$(pwd)/$1"
echo "Copy patch files from $patchdir to $aggdir"
cp -Rv "$patchdir"/* "$aggdir"
