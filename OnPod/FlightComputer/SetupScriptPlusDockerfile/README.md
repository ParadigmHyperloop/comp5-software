# README.md
install docker // differes per platform, google it

cd into folder with Dockerfile

`docker build -t pi_fc:v1 .` 

`docker run -it -v <path-to-flight-computer-dir>:/home/data --entrypoint /bin/bash pi_fc:v1` 
  
// my windows machine
// `docker run -it -v /c/hyperloop/comp5-software/OnPod/FlightComputer:/home/data --entrypoint /bin/bash pi_fc:v1` 
  
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
