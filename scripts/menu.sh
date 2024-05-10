#!/bin/bash
# show menu of the available scripts for controlling the system

# dmenu
font="Roboto Mono Nerd Font"
prompt="󰍜 "
nbr_col=4
nbr_lin=2

# scripts
wp_sh="$HOME/scripts/menu/wallpapers.sh"
conky_sh="$HOME/scripts/menu/conky.sh"
bar_sh="$HOME/scripts/menu/bar.sh"
ws_sh="$HOME/scripts/menu/websearch.sh"
# _sh="$HOME/scripts/menu/"
exit_sh="$HOME/scripts/menu/exit.sh"

# options
wp_opt="change wallpaper"
conky_opt="show/hide conky"
bar_opt="change bar"
ws_opt="web search"
# _opt=""
exit_opt="exit"

# menu_opts="$wp_opt\n$conky_opt\n$bar_opt\n$exit_opt\n$ws_opt"
menu_opts=$(ls $HOME/scripts/menu)

# main
selected_opt=$(echo -e "$menu_opts" | dmenu -i -fn "$font" -p "$prompt")

$HOME/scripts/menu/"$selected_opt"

#case $selected_opt in
#	"$wp_opt")
#		"$wp_sh"
#		;;
#
#	"$conky_opt")
#		"$conky_sh"
#		;;
#
#	"$bar_opt")
#		"$bar_sh"
#		;;
#
#	"$ws_opt")
#		"$ws_sh"
#		;;
#	
#	"$exit_opt")
#		"$exit_sh"
#		;;
#
#	*)
#		echo "[menu] invalid choice: $selected_opt" >&2
#		;;		
#esac

