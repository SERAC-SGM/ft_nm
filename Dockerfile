FROM ubuntu:latest

RUN apt update -y && apt install zsh binutils man-db build-essential -y

ENTRYPOINT [ "/bin/zsh" ]
