#!/bin/bash

# Auto detect and apply configurations
xrandr --auto

# Check if DisplayPort-0 is connected
DP0_CONNECTED=$(xrandr | grep "DisplayPort-0 connected")

# Check if DisplayPort-1 is connected
DP1_CONNECTED=$(xrandr | grep "DisplayPort-1 connected")

# Set up the primary monitor configuration based on which DisplayPort is connected
if [ -n "$DP0_CONNECTED" ]; then
    xrandr --output eDP --mode 1920x1080 --pos 0x1440 --rotate normal \
           --output HDMI-A-0 --off \
           --output DisplayPort-0 --primary --mode 3440x1440 --pos 1040x0 --rotate normal \
           --output DisplayPort-1 --off
elif [ -n "$DP1_CONNECTED" ]; then
    xrandr --output eDP --mode 1920x1080 --pos 0x1440 --rotate normal \
           --output HDMI-A-0 --off \
           --output DisplayPort-1 --primary --mode 3440x1440 --pos 1040x0 --rotate normal \
           --output DisplayPort-0 --off
else
    # If no DisplayPort is connected, just use the laptop screen
    xrandr --output eDP --mode 1920x1080 --pos 0x0 --rotate normal \
           --output HDMI-A-0 --off \
           --output DisplayPort-0 --off \
           --output DisplayPort-1 --off
fi

# Set the background using feh
feh --bg-fill /home/kamil/.config/wallpapers/disco-elysium.webp &

