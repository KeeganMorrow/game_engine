#!/usr/bin/env sh
DIR=$(dirname $0)
RET=0
${DIR}/sdlwrap_sdl_test
EXIT=$?
if [ $EXIT -ne 0 ]; then
    RET=$EXIT
fi
${DIR}/sdlwrap_surface_test
EXIT=$?
if [ $EXIT -ne 0 ]; then
    RET=$EXIT
fi
${DIR}/sdlwrap_render_test
EXIT=$?
if [ $EXIT -ne 0 ]; then
    RET=$EXIT
fi
${DIR}/sdlwrap_window_test
EXIT=$?
if [ $EXIT -ne 0 ]; then
    RET=$EXIT
fi
exit $RET
