mykernel 2.0
==========
Develop your own OS kernel by reusing Linux infrastructure, based on x86-64/Linux Kernel 5.4.34.

## Set up mykernel 2.0 in Ubuntu 18.04

```
sudo apt install build-essential
sudo apt install axel
sudo apt install qemu # install QEMU
sudo apt install libncurses-dev bison flex libssl-dev libelf-dev
wget https://raw.github.com/mengning/mykernel/master/mykernel-2.0_for_linux-5.3.34.patch
axel -n 20 https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/linux-5.4.34.tar.xz
xz -d linux-5.4.34.tar.xz
tar -xvf linux-5.4.34.tar
cd linux-5.4.34
patch -p1 < ../mykernel-2.0_for_linux-5.3.34.patch
make defconfig # Default configuration is based on 'x86_64_defconfig'
make -j$(nproc)
qemu-system-x86_64 -kernel arch/x86/boot/bzImage
```
