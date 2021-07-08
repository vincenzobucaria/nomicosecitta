

#! /bin/sh
chmod +x make.sh
gcc -c main.c
gcc -o nomicosecitta main.o partita.o classifica.o classifica_partita.o giocatori.o turni.o
./nomicosecitta
