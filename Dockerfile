FROM ubuntu
MAINTAINER Philip Peterson

# RUN apt-get install -y software-properties-common python
# RUN add-apt-repository ppa:chris-lea/node.js
# RUN echo "deb http://us.archive.ubuntu.com/ubuntu/ precise universe" >> /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y git
RUN mkdir /var/source

ADD . /var/source
