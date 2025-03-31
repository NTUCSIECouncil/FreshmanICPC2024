#!/bin/bash

problem="group"
memory=262144  # 256MB
stack_size=262144  # 256MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
