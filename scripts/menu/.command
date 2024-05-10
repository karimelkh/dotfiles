#!/bin/dash

font="Roboto Mono Nerd Font"
prompt=" "

cmd=$(echo "" | dmenu -fn "$font" -p "$prompt")

notify-send "$cmd"

/bin/bash $cmd &

