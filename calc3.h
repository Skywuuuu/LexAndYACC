#include <map>
#include <utility>
#include <string.h>
typedef enum { typeCon, typeId, typeOpr, typeStr} nodeEnum; 
 
/* constants */ 
typedef struct { 
    float value;                  /* value of constant */ 
} conNodeType;  

typedef struct { 
    char* value;                  /* value of constant */ 
} strNodeType;

/* identifiers */ 
typedef struct { 
    char* idName;                      /* subscript to sym array */ 
} idNodeType;  

/* operators */ 
typedef struct { 
    int oper;                   /* operator */
    int nops;                   /* number of operands */ 
    struct nodeTypeTag *op[1];  /* operands, extended at runtime */ 
} oprNodeType; 

typedef struct nodeTypeTag { 
    nodeEnum type;              /* type of node */ 
     union { 
      conNodeType con;        /* constants */ 
      strNodeType str;        /* string */
      idNodeType id;          /* identifiers */ 
      oprNodeType opr;        /* operators */ 
    }; 
} nodeType;  

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};

extern std:: map<char *, float, cmp_str> sym;



