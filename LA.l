%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
#include <string>
void yyerror(char *);
%}

%%
0                                               {yylval.iValue = atoi(yytext); return FLOAT;}

[0-9]+(\.[0-9]+)?([eE][0-9]+)?                  {yylval.iValue = atof(yytext); return FLOAT;}
[01]+B                                          {yylval.s = (char*)malloc(sizeof(yytext)); strcpy(yylval.s,yytext); return BIN;}
"sin"                                           {return SIN;}
"cos"                                           {return COS;}
"pi"                                            {return PI;}
"fac"                                           {return FAC;}
"B2D"                                           {return B2D;}

[-()<>=+*/;{}.^]                                { return *yytext;}

">="        return GE;
"<="        return LE;
"=="        return EQ;
"!="        return NE;
"while"     return WHILE;
"if"        return IF;
"else"      return ELSE;
"print"     return PRINT;

[_[:alpha:]][_[:alnum:]]*                       {yylval.s = (char*)malloc(sizeof(yytext)); strcpy(yylval.s,yytext);   return VARIABLE;}

[ \t\n]+ ;
.                                               yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}

