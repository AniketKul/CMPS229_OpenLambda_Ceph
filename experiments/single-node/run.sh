#!/bin/bash
set -ex

#CEPH_PUBLIC_NETWORK=128.114.53.0/24
#CEPH_PUBLIC_NETWORK=192.168.0.0/24
CEPH_PUBLIC_NETWORK=175.20.0.0/16
MON_IP=175.20.0.12
#MON_IP=10.0.0.219
#MON_IP=192.168.0.20
#MON_IP=192.168.99.1

docker network create --subnet=175.20.0.0/16 mynet123

docker run -d --name=cephdaemon \
--net mynet123 \
--ip 175.20.0.12 \
-e MON_IP=$MON_IP \
-e CEPH_PUBLIC_NETWORK=$CEPH_PUBLIC_NETWORK \
openlambda-ceph

#-v /tmp/ceph:/var/lib/ceph \

#docker run -d --name=cephdaemon \
#  --net=host \
#  -e MON_IP=$MON_IP \
#  -e CEPH_PUBLIC_NETWORK=$CEPH_PUBLIC_NETWORK \
#  openlambda-ceph

docker exec -ti cephdaemon ceph -s

# TODO: add other here ^^^^^^^
#
# e.g. invoke your client or something else
