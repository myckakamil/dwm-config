#!/bin/bash

# check if script is run as sudo
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

# Linux distro
DISTRO=$(cat /etc/os-release | grep -w ID | cut -d= -f2 | sed 's/"//g')

# if debian run this
if [ $DISTRO == "debian" ]
then
    apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg wget lightdm
    # firefox instalation
    install -d -m 0755 /etc/apt/keyrings
    wget -q https://packages.mozilla.org/apt/repo-signing-key.gpg -O- | tee /etc/apt/keyrings/packages.mozilla.org.asc > /dev/null
    echo "deb [signed-by=/etc/apt/keyrings/packages.mozilla.org.asc] https://packages.mozilla.org/apt mozilla main" | tee -a /etc/apt/sources.list.d/mozilla.list > /dev/null
    echo '
    Package: *
    Pin: origin packages.mozilla.org
    Pin-Priority: 1000
    ' | tee /etc/apt/preferences.d/mozilla 
    apt-get update &&  apt-get install firefox
fi
if [ $DISTRO != "debian" ]
then
    echo "Disto not supported yet. Exiting."
    exit
fi

FOLDER=$(pwd)
ln -s $FOLDER/dwm $HOME/.dwm
ln -s $FOLDER/slstatus $HOME/.slstatus
ln -s $FOLDER/.Xresources $HOME/.Xresources

# Doesn't work
# make -C $FOLDER/dwm
# make -C $FOLDER/slstatus

cp dwm.desktop /usr/share/xsessions/

systemctl enable lightdm
