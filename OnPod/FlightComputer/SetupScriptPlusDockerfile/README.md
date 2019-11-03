# README.md
install docker // differes per platform, google it

cd into folder with Dockerfile

`docker build -t pi_fc:vb .` 

`docker run -it -v /c/hyperloop/comp5-software/OnPod/FlightComputer:/home/data pi_fc:vd --entrypoint /bin/bash helloTest` 
  
// path-to-FlightComputer-Dir = /c/hyperloop/comp5-software/OnPod/FlightComputer on my windows machine
  
# General docker cmds
`docker images -a` // list images 

`docker ps -a` // list containers 

`docker run -it pi_fc:v1 bin/bash` // run container and open a bash terminal 
  
# Fix for script interpreter error // doz2unix equivalent for pi
`sed -i.bak 's/\r$//' fileToFix.sh`

# Remote SSH setup
`sudo systemctl enable ssh`
`sudo systemctl start ssh`

`ifconfig` // to get ip address
Default: user=pi password=raspberry
