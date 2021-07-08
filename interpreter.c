#include <stdio.h> 
#include "calc3.h" 
#include "y.tab.h" 
#include "math.h"
float factorial(float fac);
float BtoD(char* bin);
float res;
int count = 0;
std::map<char *, float, cmp_str>::iterator it;
float ex(nodeType *p) {
    if (!p) return 0;
    switch(p->type) {
        case typeCon:
            return p->con.value;
        case typeStr:
            return 0; //meaningless
        case typeId:
            return sym[p->id.idName];
        case typeOpr:
            switch(p->opr.oper) {
                case WHILE:
                    while(ex(p->opr.op[0]))
                        ex(p->opr.op[1]);
                    return 0;
                case IF:
                    if (ex(p->opr.op[0]))
                        ex(p->opr.op[1]);
                    else if (p->opr.nops > 2)
                        ex(p->opr.op[2]);
                    return 0;
                case PRINT:
                    printf("%.4f\n", ex(p->opr.op[0]));
                    return 0;
                case ';':
                    ex(p->opr.op[0]); return ex(p->opr.op[1]);
                case '=':
                    it = sym.find(p->opr.op[0]->id.idName);
                    if(it!=sym.end()){
                        sym[p->opr.op[0]->id.idName] = ex(p->opr.op[1]);
                    }
                    else
                    {
                        sym.insert(std::pair<char*, float>(p->opr.op[0]->id.idName, ex(p->opr.op[1])));
                    }
                    
                    return ex(p->opr.op[1]);
                case UMINUS:      return -ex(p->opr.op[0]);
                case '+':         return ex(p->opr.op[0]) + ex(p->opr.op[1]);
                case '-':         return ex(p->opr.op[0]) - ex(p->opr.op[1]);
                case '*':         return ex(p->opr.op[0]) * ex(p->opr.op[1]);
                case '/':         return ex(p->opr.op[0]) / ex(p->opr.op[1]);
                case '<':         return ex(p->opr.op[0]) < ex(p->opr.op[1]);
                case '>':         return ex(p->opr.op[0]) > ex(p->opr.op[1]);
                case '^':         return pow(ex(p->opr.op[0]), ex(p->opr.op[1]));
                case GE:          return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
                case LE:          return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
                case NE:          return ex(p->opr.op[0]) != ex(p->opr.op[1]);
                case EQ:          return ex(p->opr.op[0]) == ex(p->opr.op[1]);
                case SIN:         return sin(ex(p->opr.op[0]));
                case COS:         return cos(ex(p->opr.op[0]));
                case B2D:         return BtoD(p->opr.op[0]->str.value);
                case FAC:         
                    res = factorial(ex(p->opr.op[0]));
                    if(res==-1&&count==0){
                        printf("Fraction number is not allowed.\n");
                        count++;
                        return res;
                    } 
                    else if(res==-2&&count==0){
                        printf("Negative number is not allowed.\n");
                        count++;
                        return res;
                    } 
                    if(count==1) count = 0;
                    return res;
            }
    }
    return 0;
}

float BtoD(char* bin)
{
 int i = 0;
    int dec = 0;
    while(bin[i]!='B'){
        if (bin[i] == '1') dec = dec * 2 + 1; 
        else if (bin[i] == '0') dec *= 2; 
        i++;
    }
    return dec;
}

float factorial(float fac){
    if(fac<0){
        return -2;
    }
    int fac2 = (int)fac;
    if (fac2!=fac){
        return -1;
    }
    float sum = 1;
    while(fac!=0){
	sum*=fac;
	fac--;
    }
    return sum;
}
