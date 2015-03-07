#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRCDIR="${DIR}/src"
INCDIR="${DIR}/inc"
EXINCDIR="${DIR}/lib/entityx"
GTESTINCDIR="${DIR}/lib/gtest/include"
GMOCKINCDIR="${DIR}/lib/gmock/include"
echo "Running cppcheck on directory: \"$SRCDIR\""
cppcheck --enable=all --inconclusive -I $INCDIR -I $EXINCDIR -I $GTESTINCDIR -I $GMOCKINCDIR $SRCDIR $@
