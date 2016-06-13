#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/freddy/Github/LIT/Arduino/arduino_ws/src/rosserial/rosserial_xbee"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/freddy/Github/LIT/Arduino/arduino_ws/install/lib/python2.7/dist-packages:/home/freddy/Github/LIT/Arduino/arduino_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/freddy/Github/LIT/Arduino/arduino_ws/build" \
    "/usr/bin/python" \
    "/home/freddy/Github/LIT/Arduino/arduino_ws/src/rosserial/rosserial_xbee/setup.py" \
    build --build-base "/home/freddy/Github/LIT/Arduino/arduino_ws/build/rosserial/rosserial_xbee" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/freddy/Github/LIT/Arduino/arduino_ws/install" --install-scripts="/home/freddy/Github/LIT/Arduino/arduino_ws/install/bin"
