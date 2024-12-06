# base image
FROM ubuntu:24.04

# compiler version
ARG LLVM=18

# install dependencies
RUN apt-get update && apt-get install -y lsb-release wget software-properties-common && \
      DEBIAN_FRONTEND=noninteractive apt-get install -y \
      clang-${LLVM} \
      clangd-${LLVM} \
      cmake \
      g++ \
      gfortran \
      git \
      vim \
      lldb-${LLVM} \
      hdf5-tools \
      libboost-dev \
      libclang-${LLVM}-dev \
      libc++-${LLVM}-dev \
      libc++abi-${LLVM}-dev \
      libomp-${LLVM}-dev \
      libfftw3-dev \
      libgfortran5 \
      libgmp-dev \
      libhdf5-dev \
      libopenblas-dev \
      libopenmpi-dev \
      openmpi-bin \
      openmpi-common \
      openmpi-doc \
      pandoc \
      python3-clang-${LLVM} \
      python3-dev \
      python3-mako \
      python3-matplotlib \
      python3-mpi4py \
      python3-numpy \
      python3-numpydoc \
      python3-pip \
      python3-scipy \
      python3-ipython \
      python3-sphinx \
      python3-sphinx-rtd-theme \
      python3-nbsphinx \
      python3-myst-parser \
      python3-linkify-it

# set up user, home directory and environment
ARG NB_USER=thahn
ARG NB_UID=983
RUN useradd -u $NB_UID -m $NB_USER && \
    echo 'thahn ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER $NB_USER
ENV HOME=/home/${NB_USER}

# clone personal dotfiles repo for specific configurations
RUN git clone https://github.com/Thoemi09/dotfiles.git --branch main ${HOME}/dotfiles && \
    mkdir -p ${HOME}/.config/git && cp ${HOME}/dotfiles/git/ignore ${HOME}/.config/git && \
    cp ${HOME}/dotfiles/vim/.vimrc ${HOME}

# set working directory
WORKDIR ${HOME}