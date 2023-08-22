#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum process ID: $pid_max"
