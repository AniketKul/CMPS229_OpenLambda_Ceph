FROM ceph/demo:tag-build-master-luminous-ubuntu-16.04

ARG DEBIAN_FRONTEND=noninteractive

ADD *.cc /root/

RUN \
# remove initialization of unused components from demo image
    sed -i -e 's/^bootstrap_mds.*//' \
           -e 's/^bootstrap_rgw.*//' \
           -e 's/^bootstrap_demo_user.*//' \
           -e 's/^bootstrap_rest_api.*//' \
           -e 's/^bootstrap_rbd_mirror*//' entrypoint.sh && \
# install gcc and build class
    apt-get update && \
    apt-get install -y gcc wget && \
    cd /root && \
# remove GCC and dependencies
    apt-get purge -y gcc && \
    apt-get autoremove --purge -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
