FROM ceph/demo:tag-build-master-luminous-ubuntu-16.04

ARG DEBIAN_FRONTEND=noninteractive

RUN mkdir -p /gtest-master

ADD *.cc /root/
ADD *.py /root/
ADD *.h /root/
COPY gtest-master /gtest-master
COPY boost /root/boost
COPY include /root/include
COPY common /root/common
COPY json_spirit /root/json_spirit
COPY crush /root/crush
COPY log /root/log
COPY msg /root/msg
ADD entrypoint.sh /

RUN chmod 777 /entrypoint.sh 

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
    apt-get install -y g++ wget && \
    apt-get install -y python2.7-dev && \
    apt-get install -y vim && \
    apt-get install librados-dev && \
    apt-get install -y gdb && \
    apt-get install -y less && \
    apt-get install -y libgtest-dev && \
    apt-get install -y make && \
    apt-get install -y libboost-all-dev && \
    apt-get install -y cmake && \
    apt-get install -y upstart && \
    #cp /usr/lib/librados.so /root/ && \
    mv /root/objclass.h /usr/include/rados/ && \
    cp /root/cls_lambda_RADOS.cc /usr/include/rados/ && \
    cd /usr/include/rados/ && \
    g++ -std=c++11 -c -fpic cls_lambda_RADOS.cc -o cls_lambda_rados.so && \
    g++ -std=c++11 -shared -L/usr/lib/rados-classes -lrados -lcls_user -lcls_sdk -o libcls_lambda.so cls_lambda_rados.so && \
    mv /usr/include/rados/libcls_lambda.so /usr/lib/rados-classes && \
    cp /usr/lib/ceph/libceph-common.so /usr/lib/ && \
    cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp *.a /usr/lib && \
    ldconfig && \
    cd /root 
    #gcc -Wall -o test main.c -librados
    #gcc -o cls_lambda_RADOS cls_lambda_RADOS.cc -librados && \
    #g++ -o cls_lambda_RADOS -L. cls_lambda_RADOS.o -librados && \

 #remove GCC and dependencies
 #   apt-get purge -y gcc && \
 #   apt-get autoremove --purge -y && \
 #   apt-get clean && \
 #   rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*