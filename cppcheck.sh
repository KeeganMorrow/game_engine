#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRCDIR=$DIR"/src"
INCDIR=$SRCDIR"/include/"
echo "Running cppcheck on directory: \"$SRCDIR\""
cppcheck --enable=all --inconclusive -I $INCDIR $SRCDIR 
