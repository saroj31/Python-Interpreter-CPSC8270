#include <iostream>
#include "parse.tab.h"

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

void printInfo(void)
{
  std::cout << "keywords: " << keywords << std::endl;
  std::cout << "identifiers: " << identifiers << std::endl;
  std::cout << "numbers: " << numbers << std::endl;
  std::cout << "lines: " << yylineno << std::endl;
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
  return 0;
}

int oldMain() {
  yylex();
  printInfo();
  return 0;
}
