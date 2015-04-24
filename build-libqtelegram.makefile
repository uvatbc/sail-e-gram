# Place this makefile in the directory where you wish to checkout and compile libqtelegram
# Run using 'make -f build-libqtelegram.makefile all'
# To create a container with the necessary dependancies to compile libqtelegram: 'make -f build-libqtelegram.makefile prepare_docker_container'
# Find build files are collected in ./libqtelegram/bld/lib/

DEPS=make bzr cppcheck dh-exec cmake libphonon4qt5-dev qtmultimedia5-dev libthumbnailer-dev libssl-dev qtdeclarative5-dev-tools qtdeclarative5-private-dev pkg-config libmediainfo-dev libsqlite3-dev

all:
	echo '#!/bin/bash' > tmp.sh
	echo 'apt-get update ; apt-get upgrade --assume-yes ; apt-get --assume-yes install make ; cd /mnt/src/ ; make -f build-libqtelegram.makefile inside_docker' >> tmp.sh
	chmod +x tmp.sh
	docker run -it --rm -v `pwd`:/mnt/src 192.168.15.51:5000/libqtelegram:v1 /mnt/src/tmp.sh
	rm tmp.sh

from_scratch:
	echo '#!/bin/bash' > tmp.sh
	echo 'apt-get update ; apt-get upgrade --assume-yes ; apt-get --assume-yes install make ; cd /mnt/src/ ; make -f build-libqtelegram.makefile inside_docker' >> tmp.sh
	chmod +x tmp.sh
	docker run -it --rm -v `pwd`:/mnt/src 192.168.15.51:5000/ubuntu:15.04 /mnt/src/tmp.sh
	rm tmp.sh

prepare_docker_container:
	echo '#!/bin/bash' > tmp.sh
	echo 'apt-get update ; apt-get upgrade --assume-yes ; apt-get --assume-yes install $(DEPS)' >> tmp.sh
	chmod +x tmp.sh
	docker run -it -v 192.168.15.51:5000/ubuntu:15.04 /mnt/src/tmp.sh
	rm tmp.sh

# This is the compilation step that runs inside the docker container
inside_docker:
	apt-get install --assume-yes $(DEPS)
	cd /mnt/src
	rm -rf libqtelegram ; bzr branch lp:libqtelegram
	cd libqtelegram ; rm -rf bld ; mkdir bld ; cd bld
	cd libqtelegram/bld ; cmake -DCMAKE_INSTALL_PREFIX=./usr -DCMAKE_INSTALL_LIBDIR=lib/x86_64-linux-gnu/ ..
	cd libqtelegram/bld ; make
