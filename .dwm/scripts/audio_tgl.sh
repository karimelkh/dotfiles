#!/bin/bash

# last_volume=100

# Get the current volume
current_volume=$(amixer get Master | grep -oP '\d+%' | head -n1 | cut -d'%' -f1)

# Toggle between 0% and previous volume
if [ "$current_volume" -eq 0 ]; then
    # If current volume is 0%, set to previous volume (stored in the last_volume variable)
    amixer set Master "${last_volume}%"
else
    # Store the current volume before muting
    last_volume="$current_volume"
    # Mute the audio
    amixer set Master 0%
fi

# gnome-terminal -- bash -c 'echo "you have toggled the audio"; exec bash'
