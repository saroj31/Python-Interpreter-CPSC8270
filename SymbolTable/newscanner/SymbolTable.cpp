#include "SymbolTable.h"
#include <iostream>
#include "ast.h"

//SingleTon class
SymbolTable& SymbolTable::getInstance(){

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
	
	AstSymbol *Symbol = dynamic_cast<AstSymbol*>(iSymbol);
	AstNumber *astVal = new AstNumber(iNumber->getNodetype(),iNumber->getNumber());
	//check if its already there in the map
	it = iMap.find(Symbol->GetSymbol());
	
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
	
	AstNumber *oVal;
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

double SymbolTable::giveDValue(std::string iSymName){
	
	double oVal;
	oVal = idMap[iSymName];
		
	return oVal;
	
}