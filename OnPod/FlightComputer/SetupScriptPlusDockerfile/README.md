# README.md
install docker // differes per platform, google it
cd into folder with Dockerfile
" docker build -t pi_fc:v1 . "
" docker run -it -v <path-to-FlightComputer-Dir>:/home/data pi_fc /bin/bash " 
// <path-to-FlightComputer-Dir> = /c/hyperloop/comp5-software/OnPod/FlightComputer on my windows machine

# General docker cmds
docker images -a // list images
docker ps -a // list containers
docker run -it <image> bin/bash // run container and open a bash terminal 

# Fix for script interpreter error // doz2unix equivalent for pi
"sed -i.bak 's/\r$//' piSetup.sh"

# Remote SSH setup
turn on ssh via gui
ifconfig // to get ip address
Default: user=pi password=raspberry
