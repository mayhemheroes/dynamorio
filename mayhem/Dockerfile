FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake g++ g++-multilib doxygen git zlib1g-dev libunwind-dev libsnappy-dev liblz4-dev clang

COPY . /repo
WORKDIR /repo/build
RUN cmake ..
RUN make -j8

RUN clang++ /repo/mayhem/fuzz_hashtable_num_bits.cpp -fsanitize=fuzzer,address /repo/build/lib64/release/libdynamorio_static.a /repo/build/lib64/*.a -o /fuzz

FROM ubuntu:20.04 as package

COPY --from=builder /fuzz /fuzz_hashtable_num_bits
COPY --from=builder /repo/build/clients/bin64/drdisas /repo/build/clients/bin64/drdisas
