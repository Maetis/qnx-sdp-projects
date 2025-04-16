# Install QNX SDP 8.0 on openSUSE Tumbleweed

## Prerequisites
* [You need a license for QNX SDP 8.0](https://devblog.qnx.com/how-to-get-a-free-qnx-license/)


## Step 1: Download and decompress the QNX Software Center
Unfortunately, we can't download the **QNX Software Center** directly with `cURL` because authentication is required. You will need to use an internet browser to download it ([link](https://www.qnx.com/download/group.html?programid=29178)). Download the variant for Linux.

```bash
cd $HOME
cp <your-download-folder>/qnx-setup-<version>-linux.run .
mkdir qnx
chmod +x qnx-setup-<version>-linux.run
./qnx-setup-<version>-linux.run --tar xvf -C qnx
```

## Step 2: Install QNX SDP 8.0

```bash
LICENSE_KEY="FILL_ME_IN"
QNX_USER="FILL_ME_IN"
QNX_PASSWORD="FILL_ME_IN"

cd $HOME

./qnx/qnxsoftwarecenter/qnxsoftwarecenter_clt \
    -addLicenseKey $LICENSE_KEY

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
sudo zypper install bridge-utils net-tools binutils net-tools-deprecated which git libvirt 
```

With openSUSE Tumbleweed, you will need to perform some additional steps in order to configure the bridge networking.

```bash
sudo chmod 4755 /usr/libexec/qemu-bridge-helper

# Run dnsmaq before running this command, if you have a port conflict run it.
sudo sh -c 'echo "port=0" >> /etc/dnsmasq.conf'

sudo systemctl enable libvirtd.service
sudo systemctl start libvirtd.service

sudo systemctl start dnsmasq.service
sudo systemctl enable dnsmasq.service

sudo virsh net-autostart default
sudo virsh net-start default

# Add /sbin to your PATH environment variable.
echo "export PATH=$PATH:/sbin" >> .bashrc
source .bashrc

# Then run this tool from QNX SDP to configure the bridge networking.
./qnx/qnx800/host/common/mkqnximage/qemu/check-net
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
code --install-extension ms-vscode.cpptools

code .
```
