#!/usr/bin/env bash

echo "TDMS2ROOT convertor - ISOLDE CERN 2024 - MBecvar"

if [ $# -ne 2 ]; then
    echo "Incorrect number of parameters, use-cases:"
    echo " - tdms2root <tdms_file> <output_dir>"
    echo " - tdms2root <dir_of_tdms_files> <output_dir>"
    exit 1
fi

TODIR=$2
# check for existance of output_dir 
if [ ! -d $TODIR ]; then

    # do not create directory if the name corresponds to an existing file!!!
    if [ -f $TODIR ]; then
        echo "$TODIR cannot be an existing file"
        exit 1
    fi

    echo "Didn't find directory $TODIR -> CREATED"
    mkdir -p $TODIR
fi

INPUT_PATH=$1
if [ ! -d $INPUT_PATH ]; then
    # if input path is not a directory - convert selected file
    echo "Conversion of one file"

    if [[ ! $INPUT_PATH == *.tdms ]]; then
        echo "Aborting - Selected file $INPUT_PATH is not a tdms file!"
        exit 2
    fi

    _tdms2root $INPUT_PATH $TODIR 1
    exit 0
else
    echo "Conversion of all tdms files in $INPUT_PATH"

    FILECOUNT=$(ls -d $INPUT_PATH/* | grep .tdms | wc -l)
    ### if progress bar is wanted - needs pv to be installed
    # ls -d $INPUT_PATH/* | grep .tdms | xargs -P 0 --replace=@ _tdms2root @ $TODIR 0 | pv -p -l -e -s $(($FILECOUNT*2)) 
    ls -d $INPUT_PATH/* | grep .tdms | xargs -P 0 --replace=@ _tdms2root @ $TODIR 0
    exit 0
fi
