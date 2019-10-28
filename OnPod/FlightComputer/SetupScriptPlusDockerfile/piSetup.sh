#!/bin/bash
# PI setup script
echo 'Starting pi setup script'

sudo apt update -y
sudo apt upgrade -y

sudo apt-get install -y \
    git \
    make \
    curl \
    xz-utils

# clang++ setup
cd ~
wget http://releases.llvm.org/9.0.0/clang+llvm-9.0.0-armv7a-linux-gnueabihf.tar.xz
tar -xvf clang+llvm-9.0.0-armv7a-linux-gnueabihf.tar.xz
rm clang+llvm-9.0.0-armv7a-linux-gnueabihf.tar.xz
mv clang+llvm-9.0.0-armv7a-linux-gnueabihf clang_9.0.0
sudo mv clang_9.0.0 /usr/local
echo 'export PATH=/usr/local/clang_9.0.0/bin:$PATH' >> .bashrc
echo 'export LD_LIBRARY_PATH=/usr/local/clang_9.0.0/lib:$LD_LIBRARY_PATH' >> .bashrc
. .bashrc
clang++ --version
# end clang setup

sudo systemctl enable ssh
sudo systemctl start ssh

echo 'Done pi setup script'
