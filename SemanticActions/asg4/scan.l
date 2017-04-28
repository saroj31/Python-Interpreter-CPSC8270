%{
// This scanner is written by James Power, Chris Malloy, and Brian Malloy
// During Fall, 2016 (some of it was also done in Autumn). 
// Most of the definitions and specifications were taken from:
// https://docs.python.org/2.7/reference/index.html
// All copyright belongs to ?  Don't mess with ?


#include <iostream>
#include "parse.tab.h"
#include <stack>

#define QUIET

#ifndef QUIET
  #define IWASINTHEAREA(a) {std::cout << #a << std::endl;}
  #define LINENO {std::cout << __LINE__ << std::endl;}
#else
  #define IWASINTHEAREA(a) {;}
  #define LINENO {;}
#endif

  std::stack<int> indentations;

  int keywords = 0;
  int identifiers = 0;
  int numbers = 0;
  int currIndent = 0;
  int encmatching = 0;

  void leftenclose();
  void rightenclose();
  void mkSOL();
  void renewline();
  int iced(int);
  void displayError(void);
  int doIndent(int);
  int controlSpaces(const int);
  int controlChars();
%}
%option yylineno

number    {integer}|{longinteger}|{floatnumber}|{imagnumber}

imagnumber     {imaghead}[jJ]
imaghead       {floatnumber}|{intpart}

floatnumber    {pointfloat}|{expfloat}
expfloat       {expfloat_1}{exponent}
expfloat_1     {expfloat_2}|{pointfloat}
expfloat_2     {nonzero}{digit}*
pointfloat     {pointfloat_1}|{pointfloat_2}
pointfloat_1   {intpart}?{fraction}
pointfloat_2   {intpart}\.
intpart        {nzintpart}|0
nzintpart      {nonzero}{digit}*
fraction       \.{digit}+
exponent       [eE][+-]?{digit}+

longinteger    {integer}[lL]
integer        {decinteger}|{octinteger}|{hexinteger}|{bininteger}
decinteger     {nzointeger}|0
nzointeger     {nonzero}{digit}*
hexinteger     0[xX]{hexdigit}+
octinteger     0[oO]{octdigit}+|0{octdigit}+
bininteger     0[bB]{bindigit}+

digit          [0-9]
nonzero        [1-9]
octdigit       [0-7]
bindigit       [01]
hexdigit       [0-9a-fA-F]

string        {stringprefix}?{stringbody}
stringbody    {shortstring}

stringprefix  [rRuUbB]|{dubstrprefix} 
dubstrprefix  [uUbB][rR]

shortstring       {shortstring1tck}|{shortstring2tck}
shortstring2tck   \"{shortitem2tck}*\"
shortstring1tck   \'{shortitem1tck}*\'
longstring        {longstring1tck}|{longstring2tck}
longstring2tck    \"\"\"{longitem}*\"\"\"
longstring1tck    \'\'\'{longitem}*\'\'\'

shortitem2tck     {shortchar2tck}|{escapeseq}
shortitem1tck     {shortchar1tck}|{escapeseq}
longitem          {longchar}|{escapeseq}
shortchar2tck     [^\n\r\f\"\\]
shortchar1tck     [^\n\r\f\'\\]
longchar          [^\\]
escapeseq         \\.|\\\n

name      [_a-zA-Z][_a-zA-Z0-9]*

ws        [ \t\f]
spaces    {ws}+
stringQQ  [ru]?\"([^\\\"]|\\.)*\"
stringQ   [ru]?\'([^\\\']|\\.)*\'

newline   [\n\r]

printfunction from{spaces}__future__{spaces}import{spaces}print_function


/***** Start state for comments *****/
%x COMMENT
%x FULL_COMMENT
%x RAW_STRING
%x RAW_STRING2
%x INDENTING
%x FLUSH_INDENT
%x REALLY_FINISH

%%

<INITIAL,INDENTING>^{ws}*#           { BEGIN(FULL_COMMENT); }
<FULL_COMMENT>{newline}     { BEGIN(INDENTING); }
<FULL_COMMENT>.      { ; }
 
"#"                  { BEGIN(COMMENT); }
<COMMENT>{newline}          { BEGIN(INDENTING); if(encmatching <= 0) return NEWLINE; }
<COMMENT>.           { ; }

{stringprefix}?"'''"     { BEGIN(RAW_STRING); }
<RAW_STRING>"'''"        { BEGIN(INITIAL); return STRING; }
<RAW_STRING>{newline}           { ; }
<RAW_STRING>{escapeseq}  { ; }
<RAW_STRING>.            { ; }

{stringprefix}?"\"\"\""  { BEGIN(RAW_STRING2); }
<RAW_STRING2>"\"\"\""    { BEGIN(INITIAL); return STRING; }
<RAW_STRING2>{newline}          { ; }
<RAW_STRING2>{escapeseq} { ; }
<RAW_STRING2>.           { ; }

<INDENTING>^{spaces} { 
  int t = controlSpaces(yyleng);
  if( t > 0 ) return t;
}
<INDENTING>^.        { 
  int t = controlChars();
  if( t > 0 ) return t;
}
<INDENTING>^{ws}*{newline} {
             ; 
}
{spaces}   { ;  }
{string}   { return(STRING);  }

"\\"{newline}     {  /* throw continuation away */ ;  }
"("        { leftenclose();  return(LPAR); }
")"        { rightenclose(); return(RPAR); }
"["        { leftenclose();  return(LSQB);  }
"]"        { rightenclose(); return(RSQB); }

":"        { return(COLON); }
","        { return(COMMA); }
";"        { return(SEMI); }

"+"        { return(PLUS); }
"-"        { return(MINUS); }
"*"        { return(STAR); }
"/"        { return(SLASH); }

"<"        { return(LESS); }
">"        { return(GREATER); }
"="        { return(EQUAL); }

"."        { return(DOT); }
"%"        { return(PERCENT); }
"`"        { return(BACKQUOTE); }
"{"        { leftenclose();  return(LBRACE); }
"}"        { rightenclose(); return(RBRACE); }

"=="       { return(EQEQUAL); }
"!="       { return(NOTEQUAL); }
"<="       { return(LESSEQUAL); }
">="       { return(GREATEREQUAL); }
"<>"       { return(GRLT); }

"~"        { return(TILDE); }
"^"        { return(CIRCUMFLEX); }
"<<"       { return(LEFTSHIFT); }
">>"       { return(RIGHTSHIFT); }
"**"       { return(DOUBLESTAR); }

"+="       { return(PLUSEQUAL); }
"-="       { return(MINEQUAL); }
"*="       { return(STAREQUAL); }
"/="       { return(SLASHEQUAL); }
"%="       { return(PERCENTEQUAL); }
"&="       { return(AMPEREQUAL); }
"|"        { return(BAR); }
"|="       { return(VBAREQUAL); }
"^="       { return(CIRCUMFLEXEQUAL); }
"<<="      { return(LEFTSHIFTEQUAL); }
">>="      { return(RIGHTSHIFTEQUAL); }
"**="      { return(DOUBLESTAREQUAL); }
"//"       { return(DOUBLESLASH); }
"//="      { return(DOUBLESLASHEQUAL); }

"@"        { return(AT); }

"and"      { return(AND); }
"&"        { return(AMPERSAND); }
"not"      { return(NOT); }
"or"       { return(OR); }
"as"       { return(AS); }
"assert"   { return(ASSERT); }
"break"    { return(BREAK); }
"class"    { return(CLASS); }
"continue" { return(CONTINUE); }
"def"      { return(DEF); }
"del"      { return(DEL); }
"elif"     { return(ELIF); }
"else"     { return(ELSE); }
"except"   { return(EXCEPT); }
"exec"     { return(EXEC); }
"finally"  { return(FINALLY); }
"for"      { return(FOR); }
"from"     { return(FROM); }
"global"   { return(GLOBAL); }
"if"       { return(IF); }
"import"   { return(IMPORT); }
"in"       { return(IN); }
"is"       { return(IS); }
"lambda"   { return(LAMBDA); }
"pass"     { return(PASS); }
"print"    { return(PRINT); }
"raise"    { return(RAISE); }
"return"   { return(RETURN); }
"try"      { return(TRY); }
"while"    { return(WHILE); }
"with"     { return(WITH); }
"yield"    { return(YIELD); }

{number}   { ++numbers; yylval = atoi(yytext); return(NUMBER); }
{name}     { ++identifiers; return(NAME); }

"^{ws}*"{newline} { BEGIN(INDENTING); }
{newline}       { BEGIN(INDENTING); if(encmatching <= 0) return(NEWLINE); }

<FLUSH_INDENT><<EOF>> {
             int t = doIndent(0);
             if(t<0){
               return iced(t);
             }
             BEGIN(REALLY_FINISH);
             return(ENDMARKER);
           }
<REALLY_FINISH><<EOF>> {
             yyterminate();
           }

<*><<EOF>> { 
             BEGIN(FLUSH_INDENT);
             int t = doIndent(0);
             if(t!=0) return iced(t);
           }


<*>.       { displayError(); }
<*>{newline}       { displayError(); }

%%
int yywrap() { return 1; }

void displayError(void) { 
  std::cerr << yylineno-1 << ": lexical error with [" << yytext 
            << "]" << std::endl; 
  exit(1);
}

//                          { Z+ | iff indenting
// doIndent(thisIndent) -> { 0  | iff no indentation
//                          { Z- | iff dedenting
int doIndent(int thisIndent) { 
  int delta  = thisIndent-currIndent;
  if(delta == 0 || encmatching > 0) return 0; //No indent

  bool sign  = delta >= 0;
  if(sign){
    // Positive indent
    currIndent = thisIndent;
    indentations.push(delta);
    return delta;
  }
  // Else, dedent. Possibly many
  if( indentations.empty() ){ //Indentation mismatch
    std::cerr << "Lexical error: internal error in indentation stack." << std::endl;
    yyterminate();
    return 0;
  }
  int ind = indentations.top(); indentations.pop();
  delta += ind;
  if( delta > 0 ){ //Indentation mismatch
    std::cerr << "Lexical error: indentation mismatch.  " 
              << "Got " << thisIndent << " but was expecting " << ind
              << std::endl;
    yyterminate();
    return 0;
  }
  currIndent -= ind;
  return -ind;
}

int iced(int t) { return t<0?DEDENT:INDENT; }

int controlSpaces(const int len){
  int t = doIndent(len);
  if(t>=0){
    BEGIN(INITIAL);
  }else{
    renewline();
  }
  return t!=0 ? iced(t) : -1; 
}

int controlChars(){
  int t = doIndent(0); 
  renewline();
  if(t>=0) BEGIN(INITIAL);
  return t!=0 ?  iced(t) : -1;
}

void mkSOL(){
  unput('\n'); yyinput();
}

void renewline(){
  yyless(0);
  mkSOL();
}

void leftenclose(){
  ++encmatching;
}

void rightenclose(){
  --encmatching;
}
