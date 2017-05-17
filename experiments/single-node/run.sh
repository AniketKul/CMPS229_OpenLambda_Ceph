#!/bin/bash
set -ex

CEPH_PUBLIC_NETWORK=128.114.53.0/24
MON_IP=128.114.53.161

docker run --rm --name=cephdaemon \
  --net=host \
  -e CEPH_PUBLIC_NETWORK=$CEPH_PUBLIC_NETWORK \
  -e MON_IP=$MON_IP \
  openlambda-ceph

docker exec cephdaemon ceph -s
# TODO: add other here ^^^^^^^
#
# e.g. invoke your client or something else
