FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake g++ g++-multilib doxygen git zlib1g-dev libunwind-dev libsnappy-dev liblz4-dev

ADD . /repo
WORKDIR /repo/build
RUN cmake ..
RUN make -j8

RUN mkdir -p /deps
RUN ldd /repo/build/clients/bin64/drdisas | tr -s '[:blank:]' '\n' | grep '^/' | xargs -I % sh -c 'cp % /deps;'

FROM ubuntu:20.04 as package

COPY --from=builder /deps /deps
COPY --from=builder /repo/build/clients/bin64/drdisas /repo/build/clients/bin64/drdisas
ENV LD_LIBRARY_PATH=/deps
