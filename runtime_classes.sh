#!/data/data/com.termux/files/usr/bin/bash

# Specify the package name of the app you want to inspect
PACKAGE_NAME="com.pubg.krmobile"

# Specify the library name you want to analyze (without the lib prefix and .so extension)
LIB_NAME="anogs"

# Get the PID of the app
PID=$(ps -A | grep "$PACKAGE_NAME" | awk '{print $2}')

if [ -z "$PID" ]; then
  echo "No running process found for $PACKAGE_NAME"
  exit 1
fi

# Get the shared library path loaded by the process
LIB_PATH=$(ls -l /proc/$PID/maps | awk '/'"$LIB_NAME"'\.so/{print $NF}')

if [ -z "$LIB_PATH" ]; then
  echo "Library $LIB_NAME not found in the process"
  exit 1
fi

# Extract the absolute path of the library
ABS_PATH=$(readlink -f $LIB_PATH)

# Get the class names from the library using strings command
CLASS_NAMES=$(strings $ABS_PATH | grep -E "\bL[a-zA-Z0-9_/;<>$]+;" | sed -e 's#^L\(.*\);#\1#g')

# Output the class names
echo "Classes in $LIB_NAME:"
echo "$CLASS_NAMES"
