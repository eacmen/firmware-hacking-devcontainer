# Firmware Hacking & CTF Devcontainer
# Based on Debian with security/RE tools for overthewire.org challenges

FROM debian:bookworm-slim

# Avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install base development tools and utilities
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    nasm \
    binutils \
    git \
    openssh-client \
    wget \
    curl \
    socat \
    netcat-openbsd \
    gdb \
    gdbserver \
    strace \
    file \
    xxd \
    hexedit \
    p7zip-full \
    unzip \
    gzip \
    bzip2 \
    xz-utils \
    lzop \
    lz4 \
    cpio \
    cabextract \
    squashfs-tools \
    mtd-utils \
    sleuthkit \
    e2fsprogs \
    dosfstools \
    python3 \
    python3-pip \
    python3-venv \
    python3-dev \
    libffi-dev \
    libssl-dev \
    ca-certificates \
    pkg-config \
    tmux \
    vim \
    nano \
    less \
    tree \
    jq \
    sudo \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    && rm -rf /var/lib/apt/lists/*

# Install Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

# Install binwalk (Rust version) from crates.io
# RUN cargo install binwalk

# Install Python security/CTF tools
RUN pip3 install --break-system-packages \
    pwntools \
    ropper \
    capstone \
    keystone-engine \
    unicorn \
    z3-solver \
    pycryptodome \
    requests 

# Create workspace directory
WORKDIR /workspace

# Default shell
CMD ["/bin/bash"]
