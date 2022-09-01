ARG TAG

FROM ubuntu:$TAG

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update

RUN apt install build-essential -y

RUN apt install libgtk-3-dev -y

RUN apt install libxml2-utils -y

RUN mkdir app && mkdir ./app/src && mkdir ./app/releases

COPY ./src ./app/src

COPY ./build_app.sh ./app

RUN chmod +x ./app/build_app.sh

COPY ./infinity_loop.c ./app/

RUN gcc -o ./app/infinity_loop ./app/infinity_loop.c

ENTRYPOINT "./app/infinity_loop" 

# TODO: create a volume bind to ../release to save the binary