######################################################################
#  Project
######################################################################


target = main.bin
SRCFILES = main.c vga.c graphics.c pieces.c screen.c game.c serial.c

INCLUDE = ../include
LOAD_SCRIPT = ../stm32f103c8t6.ld

include ../Makefile.incl
