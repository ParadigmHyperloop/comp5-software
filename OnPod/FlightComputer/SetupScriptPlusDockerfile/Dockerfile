FROM raspbian/stretch:latest

RUN sudo apt update -y && \
        sudo apt upgrade -y

RUN sudo apt-get install -y \
        git \
        make \
        curl \
        xz-utils \
        libstdc++6-4.6-dev

COPY clangSetup.sh /home
COPY helloTest.sh /home
RUN sed -i.bak 's/\r$//' /home/clangSetup.sh && \
        ./home/clangSetup.sh && \
        sed -i.bak 's/\r$//' /home/helloTest.sh && \
        ./home/helloTest.sh

#RUN echo 'alias helloTest="clang++ /home/data/SetupScriptPlusDockerfile/test_main.cpp; ./home/data/SetupScriptPlusDockerfile/a.out"' >> ~/.bashrc
