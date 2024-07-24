#!/usr/bin/env sh

echo "This is the conversion program" 

if [ $# -ne 2 ]; then
    echo "Incorrect number of parameters"
    echo " - use convert.sh <tdms_file> <output_dir>"
    echo " - use convert.sh <dir_of_tdms_files> <output_dir>"
    exit 1
fi

TODIR=$2
echo $TODIR
if [ ! -d $TODIR ]; then
    echo "$TODIR is not a directory"
    exit 1
fi

INPUT_PATH=$1
echo $INPUT_PATH
if [ ! -d $INPUT_PATH ]; then
    echo "Conversion of one file"

    tdms2root $INPUT_PATH $TODIR
else
    echo "Conversion of all tdms files in $INPUT_PATH"

    files=$(ls -d $FROMDIR/* | grep .tdms)
    ls -d $FROMDIR/* | grep .tdms | xargs -P 0 --replace=@ build/tdms2root @ $TODIR
fi
