#include <string>
#include <map>
#include <iostream>

class AstNumber;
class Ast;

class SymbolTable{
	
public:
	static SymbolTable& getInstance1();
  SymbolTable() { parentST = NULL;  scope = 0; } //For Golbal Symbol table
  SymbolTable(SymbolTable *parent, int sc) { 
                                  parentST = parent; scope = sc;
                                  //std::cout<<"SymbolTable::SymbolTable scope = "<<scope<<std::endl;
                                  }
	void insertDSymbol(std::string iSymName,double dVal);
	void insertDSymbol(Ast *iSymbol,const Ast *iNumber);
	double giveDValue(std::string iSymName);
	AstNumber* giveValue(std::string iSymName);
  SymbolTable *GetParentST(); //don't free the memory will be managed in the destructor
  int GetScope();
	
	void free();
	
private:
	
	std::map<std::string, AstNumber*> iMap;  //this did not work second  time iteration of value caus
	std::map<std::string, double> idMap;
  SymbolTable *parentST;
  int scope;
	
};