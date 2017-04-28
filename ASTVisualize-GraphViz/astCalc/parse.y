//  Source code for "flex & bison", by John Levine
//  Declarations for an AST calculator fb3-1
//  Adapted by Brian Malloy
%{
#include <iostream>
#include "ast.h"

  extern int yylex();
  void yyerror(const char *s) { std::cout << s << std::endl; }
  void yyerror(const char *s, const char ch) {
    std::cout << s << ch << std::endl;
  }
%}

%union {
  Ast* ast;
  double d;
}

%token <d> NUMBER
%token EOL

%left PLUS MINUS
%left MULT DIV
%left E

%type <ast> exp

%%

calclist 
       : calclist exp EOL {
           std::cout << "= " << eval($2) << std::endl;
           makeGraph($2);
           treeFree($2);
		   std::cout << "> ";
         }
       | calclist EOL // blank line or a comment
       | // empty
       ;

exp    : exp PLUS exp  		{ $$ = new AstNode('+', $1,$3); }
       | exp MINUS exp    	{ $$ = new AstNode('-', $1,$3); }
       | exp MULT exp  		{ $$ = new AstNode('*', $1,$3); }
       | exp DIV exp  		{ $$ = new AstNode('/', $1,$3); }
       | exp E exp    		{ $$ = new AstNode('E', $1,$3); }
       | NUMBER       		{ $$ = new AstNumber('K', $1); }
       | '(' exp ')'  		{ $$ = $2; }
       | MINUS exp     		{ $$ = new AstNode('M', $2, NULL); }
       ;
%%
