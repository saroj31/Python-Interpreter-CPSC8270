#include <iostream>
#include "ast.h"
#include "parse.tab.hpp"
#include "SymbolTable.h"
#include "TableManager.h"

extern FILE * yyin;
extern int keywords;
extern int identifiers;
extern int numbers;
extern int yydebug;
extern int yylineno;

int yylex(void);
extern int yyparse();


void openFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
      std::cerr << "Could not open file \"" 
                << filename 
                << "\"" << std::endl;
      exit(1);
    }
    yyin = file;
}

int main(int argc, char * argv[]) {
  if (argc > 1) { // user-supplied filename
    openFile(argv[1]);
  }
  yydebug = 0;
  int parseErrors = yyparse();
  if ( parseErrors ) {
    std::cerr << "Abnormal termination" << std::endl;
    return 1;
  }
  
  //printInfo();
  //int returnCode = yyparse();
  
  //SymbolTable sT = SymbolTable::getInstance();
  TableManager tMgr = TableManager::getInstance();
  //SymbolTable *pST = tMgr.GetCurrentST();
  
  //pST->free();   //will put the code later
  
  return 0;
}

int oldMain() {
  yylex();
  return 0;
}
