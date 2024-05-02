#!/bin/sh
slstatus &
picom &
nm-applet &
pasystray &
blueman-applet &
flameshot & 
lxpolkit &
feh --bg-fill --randomize /home/kamil/.config/wallpapers &
nextcloud &

#Touchpad xinput settings
#Tap to click
xinput set-prop 13 'libinput Tapping Enabled' 1

#Natural scrolling
xinput set-prop 13 'libinput Natural Scrolling Enabled' 1
