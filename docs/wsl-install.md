# Install QNX SDP 8.0 on WSL

Typically, QNX SDP 8.0 can be installed on Windows or Linux, but it is also possible to install it on WSL.

## Prerequisites
* [You need a license for QNX SDP 8.0](https://www.qnx.com/products/everywhere/)
* You need one of the following Linux distributions installed on WSL

| Linux distribution | Tested with QNX SDP 8.0 |
| ------------------ |:-----------------------:|
| Ubuntu-22.04       | :white_check_mark:      |
| Ubuntu-24.04       | :white_check_mark:      |

## Step 1: Download and decompress the QNX Software Center
Unfortunately, we can't download the **QNX Software Center** directly with `cURL` because authentication is required. You will need to use an internet browser to download it ([link](https://www.qnx.com/download/group.html?programid=29178)). Download the variant for Linux.

```bash
# Assuming you downloaded the QNX Software Center to your 'Downloads' folder on Windows

cd $HOME
cp /mnt/c/Users/<username>/Downloads/qnx-setup-<version>-linux.run .
mkdir qnx
./qnx-setup-<version>-linux.run --tar xvf -C qnx
```

## Step 2: Install QNX SDP 8.0

```bash
LICENSE_KEY="FILL_ME_IN"
QNX_USER="FILL_ME_IN"
QNX_PASSWORD="FILL_ME_IN"

cd $HOME

./qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt \
    --addLicenseKey $LICENSE_KEY

./qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt \
    -myqnx.user $QNX_USER -myqnx.password $QNX_PASSWORD \
    -mirrorBaseline qnx800

./qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt \
    -myqnx.user $QNX_USER -myqnx.password $QNX_PASSWORD \
    -installBaseline com.qnx.qnx800 \
    -destination qnx/qnx800 \
    -cleanInstall

echo "source $HOME/qnx/qnx800/qnxsdp-env.sh" >> $HOME/.bashrc

source $HOME/.bashrc
```

## Step 3: Install QEMU and other dependencies
If you don't have a device compatible with QNX 8.0 (like a RaspBerry Pi 4), you probably need to run QNX on a virtual machine. So, some dependencies will need to be installed on your Linux distribution.

```bash
sudo apt update
sudo apt install -y qemu-system-x86 \
                    bridge-utils \
                    net-tools \
                    libvirt-clients \ 
                    libvirt-daemon-system
```

## Step 4: Validate your installation
We will use the command ```mkqnximage``` to validate our installation of QNX SDP 8.0 by running a virtual machine.

```bash
# We need to create an empty folder before running 'mkqnximage'
mkdir $HOME/qnx-test
cd $HOME/qnx-test

mkqnximage --run
```
A virtual machine with QNX 8.0 should be created, and you will be able to use it.

## Final step: Configure VS Code
Finally we will install and configure the [QNX Toolkit extension for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=qnx.qnx-vscode).

```bash
code --install-extension qnx.qnx-vscode

code .
```

In VS Code you will need to configure the ```qnx.sdpPath``` setting in order to provide the path to QNX SDP.