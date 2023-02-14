# Planet X3 for Nintendo DS

## About
At present, this does not aim to be a 1:1 ASM to C conversion. I want this to
stay faithful when possible, but otherwise feel no obligation to use all of the
original source code. All of my own code is considered to be under the GPL v3
license.

## Compiling
Currently you need to run the provided `./get_assets.sh` script to uncompress
the game assets, as I have not yet implemented the decompression myself. If you
are on Arch you can install z88dk from the AUR.  
After this you must run my `./convert_assets.sh` script which will convert the
binary graphics data into easily loaded PNG files. First, make sure the game
files are in the assets directory, or modify the script to point to whatever
directory you placed them in. Second, compile `vga-convert.c` using
`gcc -o build/vga-convert vga-convert.c` (or using Clang). Third, run
`./convert_assets.sh` to create ppm files (an intermediate, text based image
format), then `./convert_assets.sh convert` to convert them into png files
(requires the imagemagick package), and optionally `./convert_assets.sh clean`
to cleanup the ppm files.  
Finally run `make` to compile the nds ROM.

- - -
# ORIGINAL README CONTENTS
- - -

Planet X3 Open Source Edition
=============================

This is the game engine of Planet X3, a real time strategy game originally
written for MS-DOS compatible computers.

The version contained in this source code repository is written in 8086 assembly
language and is thus only suitable for IBM PCs and similar platforms.

See `assets/manual.txt` for the engine manual.

Further information, especially concerning the build process, can be found in
the accompanying wiki.

License
-------

GNU GPL version 2 or later for original source code.  The license for
third-party components may differ.
