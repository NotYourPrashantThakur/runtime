#!/bin/sh

# Specify the package name of the app
PACKAGE_NAME="com.pubg.imobile"

# Find the process ID (PID) of the app
PID=$(ps -A | grep $PACKAGE_NAME | awk '{print $2}')

# Check if the app process is running
if [ -n "$PID" ]; then
  echo "App process found. PID: $PID"
else
  echo "App process not found."
  exit 1
fi

# Get the runtime classes of the app using the PID
echo "Runtime classes of the app:"
adb shell "cat /proc/$PID/maps" | awk '/\.dex$|\.jar$|\.apk$/{print $6}' | sort -u

# Disconnect from the device
adb disconnect
