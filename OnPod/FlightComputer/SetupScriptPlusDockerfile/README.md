# README.md

cd into folder with Dockerfile
" docker build -t PI_FC:v1 ."
" docker run -it -v /c/hyperloop/docker/new/:/home/data raspbian/stretch /bin/bash "

# docker cmds
docker images -a // list images
docker ps -a // list containers
docker run -it <image> bin/bash

# script interpreter error fix // doz2unix equivalent
"sed -i.bak 's/\r$//' piSetup.sh"

# Remote SSH setup
turn on ssh via gui
ifconfig // to get ip address
Default: user=pi password=raspberry


