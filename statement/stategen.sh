#!/bin/bash

CONTAINER_NAME="freshmanicpc-stategen"

script_path="$(realpath $0)"

if [ "$(docker ps -aq -f status=exited -f name=$CONTAINER_NAME)" ]; then
    docker rm $CONTAINER_NAME
fi
if [ ! "$(docker ps -a -q -f name=$CONTAINER_NAME)" ]; then
    docker build "${script_path%/*}" -t $CONTAINER_NAME
    docker run -d --name $CONTAINER_NAME -v "$(realpath "${script_path%/*}/.."):/FreshmanICPC2024" $CONTAINER_NAME
fi

if [ ! "$(docker ps -a -q -f name=$CONTAINER_NAME)" ]; then
    echo "Could not start docker container."
    exit 1
fi

container_script="cd /FreshmanICPC2024; python statement/stategen.py $@"
docker exec -it "$CONTAINER_NAME" bash -c "$container_script"
