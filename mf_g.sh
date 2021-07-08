#!/bin/sh
flex LA.l
yacc -dtv SA.y
g++ -c graph.c 
g++ -c lex.yy.c
g++ -c y.tab.c
g++ -o a_g.out y.tab.o lex.yy.o graph.o
