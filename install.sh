#!/bin/bash

FOLDER=$(pwd)
ln -s $FOLDER/dwm $HOME/.dwm
ln -s $FOLDER/slstatus $HOME/.slstatus
# ln -s $FOLDER/dotconfig/* $HOME/.config/ # I don't know how it will work.

make -C $FOLDER/dwm
make -C $FOLDER/slstatus

