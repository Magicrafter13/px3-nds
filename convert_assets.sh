#!/usr/bin/bash

SRC=./assets

case "$1" in
	convert)
		convert gfx/menu.ppm gfx/menu.png
		;;
	clean)
		rm gfx/menu.ppm
		;;
	*)
		# Title screen
		./build/vga-convert 320 200 < "$SRC"/menu.vga | sed -r '/P3/s/320/256/;s/([0-9]{1,3} ){96}(.*)( [0-9]{1,3}){96}/\2/' > gfx/menu.ppm
		;;
esac
