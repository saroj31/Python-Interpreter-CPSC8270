#include "SymbolTable.h"
#include <iostream>
#include "ast.h"

//SingleTon class
SymbolTable& SymbolTable::getInstance1(){

	static SymbolTable symT;
	return symT;
	
}

void SymbolTable::insertDSymbol(std::string iSymName,double dVal){
	
	std::map<std::string, double>::iterator it;
	
	//check if its already there in the map
	it = idMap.find(iSymName);
	
	if(it != idMap.end())
		idMap.erase(it);
	
	idMap[iSymName] = dVal;
	
	return;
}

void SymbolTable::insertDSymbol(Ast *iSymbol,const Ast *iNumber){
	
	std::map<std::string, AstNumber*>::iterator it;
	

  if ('S' != iSymbol->getNodetype())
    return;
  
  if (('I' != iSymbol->getNodetype()) && ('F' != iSymbol->getNodetype()))
    return;
  
  AstSymbol *Symbol = dynamic_cast<AstSymbol*>(iSymbol);
  const AstNumber *Number = dynamic_cast<const AstNumber*>(iNumber);

  if (NULL == Number) {
    std::cout << " Number is NULL" << std::endl;
    return;
  }

  //std::cout << "SymbolTable::insertDSymbol GetSymbol " << Symbol->GetSymbol() << std::endl;
  //std::cout << "SymbolTable::insertDSymbol getNumber" << Number->getNumber() << std::endl;

  int x = Number->getNumber();
  char c = Number->getNodetype();
  AstNumber *astVal = new AstNumber(c, x);
  const char *s = Symbol->GetSymbol();
  
  std::string st = s;

  it = iMap.find(st);
  //std::cout << "SymbolTable::insertDSymbol 44 "<<std::endl;// << it->first << " : " << it->second << std::endl;
  

	if(it != iMap.end())
	{
		AstNumber *tmp = it->second;
		iMap.erase(it);
		if(NULL != tmp)
			delete tmp;
	}
	
	iMap[Symbol->GetSymbol()] = astVal;
	
	return;
}

//Gives the allocated AstNumber *
AstNumber* SymbolTable::giveValue(std::string iSymName){
	
	AstNumber *oVal = NULL;

  std::map<std::string, AstNumber*>::iterator it;

  //check if its already there in the map
  it = iMap.find(iSymName);

  //iSymName found
  if( it != iMap.end())
    oVal = iMap[iSymName];
		
	return oVal;
	
}


void SymbolTable::free(){
	
	//clean the memory captured by the map
	if( 0 == iMap.size()) return; //Nothing to do so return.
		
	std::map<std::string, AstNumber*>::iterator it = iMap.begin();
	
	while( iMap.end() != it){
		AstNumber *tmp = it->second;
		
		if(NULL != tmp)
			delete tmp;
		
		it++;
	
	}
	return;
}


int SymbolTable::GetScope() {


  return scope;
}



double SymbolTable::giveDValue(std::string iSymName){
	
	double oVal;
	oVal = idMap[iSymName];
		
	return oVal;
	
}

//don't free the memory
SymbolTable *SymbolTable::GetParentST() {

  return parentST;
}