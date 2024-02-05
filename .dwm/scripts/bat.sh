#!/bin/bash

while true; do
	bat_perc=$(acpi -b | awk '{print $4}' | tr -d '%,')
	bat_stat=$(acpi -b | awk '{print $3}')
	bat_stat=${bat_stat%?}

	if [ "$bat_perc" -le 20 ] && [ "$bat_stat" == "Discharging" ]; then
		rem_time=$(acpi -b | awk '{print $5}')
		notify-send --expire-time=60000 --icon="$HOME/.dwm/icons/battery-020.svg" --urgency=critical "low battery (remaining time: $rem_time)"
		sleep 60

	elif [ "$bat_stat" == "Charging" ]; then
		if [ "$bat_perc" -gt 80 ] && [ "$bat_perc" -lt 99 ]; then
			notify-send --expire-time=60000 --icon="$HOME/.dwm/icons/battery-080.svg" --urgency=normal "80% is enough"
		elif [ "$bat_perc" -ge 99 ]; then
			notify-send --expire-time=60000 --icon="$HOME/.dwm/icons/battery-100.svg" --urgency=critical "the battery is full"
		fi

	elif [ "$bat_stat" == "Full" ]; then
		 notify-send --expire-time=60000 --icon="$HOME/.dwm/icons/battery-100.svg" --urgency=critical "the battery is full"
	fi

	sleep 1

done
