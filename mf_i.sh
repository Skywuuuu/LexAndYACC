#!/bin/sh 
flex LA.l
yacc -dtv SA.y
g++ -c interpreter.c
g++ -c lex.yy.c
g++ -c y.tab.c
g++ -o a_i.out y.tab.o lex.yy.o interpreter.o

