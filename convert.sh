#!/usr/bin/env sh

echo "This is the conversion program" 

if [ $# -ne 2 ]; then
    echo "Incorrect number of parameters - use convert.sh FROM_DIR TO_DIR"
    exit 1
fi

FROMDIR=$1
echo $FROMDIR
if [ ! -d $FROMDIR ]; then
    echo "$FROMDIR is not a directory"
    exit 1
fi

TODIR=$2
echo $TODIR
if [ ! -d $TODIR ]; then
    echo "$TODIR is not a directory"
    exit 1
fi

# echo "ALL GOOD SO FAR"

files=$(ls -d $FROMDIR/* | grep .tdms)

ls -d $FROMDIR/* | grep .tdms | xargs -P 0 --replace=@ build/tdms2root @ $TODIR
