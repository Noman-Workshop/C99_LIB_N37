
from gcc:7

RUN apt-get update && \
	apt-get install -y cmake && \
	apt-get install -y gdb && \
	apt-get -y upgrade

WORKDIR /home/Official/

