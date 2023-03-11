FROM ubuntu:22.10

RUN apt-get update && apt-get -y install cmake \
        build-essential \
        libboost-all-dev