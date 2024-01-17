# Start with a base image containing the necessary tools
FROM ubuntu:latest

RUN echo $USERNAME

ARG USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Install C/C++ compiler and utils
RUN apt-get install -y \
      g++ \
      cmake \
      gdb-multiarch \
      gcc-arm-none-eabi \
      libnewlib-arm-none-eabi \
      libstdc++-arm-none-eabi-newlib

# Install tools
RUN apt-get install -y \
      git \
      python3 \
      vim 

# Install OpenOCD dependencies
RUN apt-get install -y \
      automake \
      autoconf \
      build-essential \
      texinfo \
      libtool \
      libftdi-dev \
      libusb-1.0-0-dev \
      pkg-config \
      usbutils
      
      
# Clone the Raspberry Pi Pico SDK repository
RUN git clone https://github.com/raspberrypi/pico-sdk /opt/sdk/pico-sdk \
    && cd /opt/sdk/pico-sdk \
    && git submodule update --init \
    && cd -

# Install OpenOCD
RUN git clone https://github.com/raspberrypi/openocd.git --branch rp2040-v0.12.0 --depth=1 --no-single-branch /opt/tools/openocd \
    && cd /opt/tools/openocd \
    && mkdir -p /etc/udev/rules.d/ \
    && cp contrib/60-openocd.rules /etc/udev/rules.d/ \
    && ./bootstrap \
    && ./configure \
    && make -j4 \
    && make install


# Setup minicom
RUN apt-get install -y minicom \
    && usermod -a -G plugdev $USERNAME

# Set the default user
USER $USERNAME

# Set the PICO_SDK_PATH environment variable
ENV PICO_SDK_PATH=/opt/sdk/pico-sdk