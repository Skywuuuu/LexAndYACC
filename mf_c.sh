#!/bin/sh
flex LA.l
yacc -dtv SA.y
g++ -c compiler.c 
g++ -c lex.yy.c
g++ -c y.tab.c
g++ -o a_c.out y.tab.o lex.yy.o compiler.o
