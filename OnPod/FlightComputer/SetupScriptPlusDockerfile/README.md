# README.md
install docker // differes per platform, google it \n
cd into folder with Dockerfile \n
" docker build -t pi_fc:v1 . " \n
" docker run -it -v <path-to-FlightComputer-Dir>:/home/data pi_fc /bin/bash "  \n
// <path-to-FlightComputer-Dir> = /c/hyperloop/comp5-software/OnPod/FlightComputer on my windows machine \n

# General docker cmds
docker images -a // list images \n
docker ps -a // list containers \n
docker run -it <image> bin/bash // run container and open a bash terminal  \n

# Fix for script interpreter error // doz2unix equivalent for pi
"sed -i.bak 's/\r$//' piSetup.sh"

# Remote SSH setup
turn on ssh via gui \n
ifconfig // to get ip address \n 
Default: user=pi password=raspberry \n
