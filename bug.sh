#!/bin/sh

touch test/exist
./ioctl 0
touch test/notexist 2>/dev/null
./ioctl -1

if [ ! -e "test/exist" ]
then
	echo "Error: Intended file not created"
	exit 1
fi

if [ -e "test/notexist" ]
then
	echo "Error: Unintended file created"
	exit 1
fi

rm test/exist