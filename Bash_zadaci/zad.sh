#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 [suspend|hibernate]"
    exit 1
fi

case "$1" in
    suspend)
        echo "Suspending the system..."
        pmset sleepnow
        ;;
    hibernate)
        echo "Hibernating the system..."
        sudo pmset hibernatemode 25 && sudo pmset sleepnow
        ;;
    *)
        echo "Invalid argument. Use 'suspend' or 'hibernate'."
        exit 1
        ;;
esac

