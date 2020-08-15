![](https://3.bp.blogspot.com/-3d4xFr2NI1U/UbOz4PnO23I/AAAAAAAAAGY/LhJe9cMRFlg/s1600/logoTS.png)

# Docker Day Of Defeat Server

This is our contribution with the day of defeat community


## TLTR

```shell
docker build --pull --rm -f "Dockerfile.dods" -t dods:latest "."

docker run --rm -d -p 27015:27015/udp dods:latest          
```

## Description

This is a docker container pre configured to run competitive matches
This version uses DodsBrasil Rules.

## Requirements
- Docker


## Install
1. Install Docker

2. Clone this reposiroty

3. Run the following commands

```shell
docker build --pull --rm -f "Dockerfile.dods" -t dods:latest "."

docker run --rm -d -p 27015:27015/udp dods:latest          
```

### References
This project is based using resources from https://github.com/Gonzih/docker-csgo-server