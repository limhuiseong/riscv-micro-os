FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y \
    clang \
    llvm \
    lld \
    qemu-system-riscv32 \
    curl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["bash"]