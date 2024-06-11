#!/bin/sh
xrandr --auto && \
xrandr --output eDP --mode 1920x1080 --pos 0x1440 --rotate normal --output HDMI-A-0 --off --output DisplayPort-0 --primary --mode 3440x1440 --pos 1040x0 --rotate normal --output DisplayPort-1 --off || \
xrandr --output eDP --mode 1920x1080 --pos 0x1440 --rotate normal --output HDMI-A-0 --off --output DisplayPort-1 --primary --mode 3440x1440 --pos 1040x0 --rotate normal --output DisplayPort-0 --off &&
feh --bg-fill /home/kamil/.config/wallpapers/disco-elysium.webp &

