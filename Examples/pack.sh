#!/usr/bin/bash

if [[ -z "$1" ]]; then
    echo
    echo "Usage: pack.sh <target>"
    echo
else
    for target in "$@"
    do
	tar cfv ${target}.tar ${target}
	gzip ${target}.tar
   done
fi
