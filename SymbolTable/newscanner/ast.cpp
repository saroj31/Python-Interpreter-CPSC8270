// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
#  include <iostream>
#  include <stdlib.h>
#  include "ast.h"
# include "SymbolTable.h" 
#  include <fstream>


const Ast* AstNode::eval() const { 
  Ast *oResNode = new AstNode(this->getNodetype(),left,right);
  return oResNode;
  
 }
 
const Ast* AstNumber::eval() const { 
  
	//std::cout<<"AstNumber eval "<<number<<std::endl;
	AstNumber *oResNode = new AstNumber(this->getNodetype(),number);
	return oResNode;
}


AstSymbol::AstSymbol(char nodetype,std::string sName ) : AstNumber(nodetype,0), symName(sName) {
		
		isInt = false;
		//std::cout<<"astSymbol b4: "<<symName<<std::endl;
		if(std::string::npos != symName.find('='))
			symName.erase(symName.length()-1,1);
		//std::cout<<"astSymbol ftr: "<<symName<<std::endl;
};

double AstSymbol::getNumber() const {
			
			double oVal = 0;
			SymbolTable& sT = SymbolTable::getInstance(); //gets the singleton SymbolTable
			
			//std::cout<<"symName: "<<symName<<std::endl;
			//AstNumber *oAst = sT.giveValue(symName);
			//std::cout<<"symValue: "<<oAst->getNumber()<<std::endl;
			//oVal = oAst->getNumber();
			oVal = sT.giveDValue(symName);
			
			return oVal;
			}

const Ast* AstSymbol::eval() const {
	
		Ast *oAst;
		
		SymbolTable& sT = SymbolTable::getInstance();
		
		double nb;
		nb = sT.giveDValue(symName);
		
		AstNumber *astRes = sT.giveValue(symName);
		nb = astRes->getNumber();
		
		if(astRes && 'I' == astRes->getNodetype())
		{
			//std::cout<<"AstSymbol:eval : IsInt "<<nb<<std::endl;
			oAst = new AstNumber('I',nb);
		}
		else if(astRes && 'F' == astRes->getNodetype()){
			//std::cout<<"AstSymbol:eval : IsFloat "<<nb<<std::endl;
			oAst = new AstNumber('F',nb);
		}
		
		return oAst;
}




//EVAL of a Plus Node
const Ast* AstPlusNode::eval() const { 
			
	Ast* oAstRes = NULL;
	double oRes = 0;
			
	const Ast *tl = getLeft()->eval();
	const Ast *tr = getRight()->eval();
		
	oRes= tl->getNumber() + tr->getNumber();
			
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
			
	delete tl;
	delete tr;
			
	return oAstRes;
}

//Eval for AstMinusNode
const Ast* AstMinusNode::eval() const { 
			
	Ast* oAstRes = NULL;
	double oRes = 0;

	if( NULL == getLeft() ) 
		std::cout<<"left operand of Minus is NULL"<<std::endl;
	
	if( NULL == getRight() ) 
		std::cout<<"Right operand of Minus is NULL"<<std::endl;
	
	 const Ast *tl = getLeft()->eval();
	 const Ast *tr = getRight()->eval();
	
	if( NULL == tl ) 
		std::cout<<"tl is NULL"<<std::endl;
	
	if( NULL == tr ) 
		std::cout<<"tr is NULL"<<std::endl;
	
	oRes =tl->getNumber() - tr->getNumber();
	
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
	
	delete tl;
	delete tr;
			
	return oAstRes;
}


//Eval for Multiply Node
const Ast* AstMultNode::eval() const { 
		
	Ast* oAstRes = NULL;
	double oRes = 0;
	const Ast *tl = getLeft()->eval();
	const Ast *tr = getRight()->eval();

	oRes = tl->getNumber() * tr->getNumber();
		
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
		
	delete tl;
	delete tr;
		
	return oAstRes;
}
	

//Eval functioon of AstDivNode	
const Ast* AstDivNode::eval() const
{ 
	Ast* oAstRes = NULL;
	double oRes = 0;
			
	const Ast *tl = getLeft()->eval();
	const Ast *tr = getRight()->eval();
			
	if( 0.0 == tr->getNumber())
	{
		std::cout<<"ZeroDivisionError"<<std::endl;
		delete tl;
		return tr;
	}
			
	
	oRes = tl->getNumber() / tr->getNumber();			
	
			
	
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()))
		oRes = floor(oRes);
						
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
			
	delete tl;
	delete tr;
			
	return oAstRes;
		
}


//Eval function for Modulus operation
const Ast* AstModNode::eval() const {
			
	Ast* oAstRes = NULL;
	double oRes = 0;
	const Ast *tl = getLeft()->eval();
	const Ast *tr = getRight()->eval();
			
	if( 0.0 == tr->getNumber())
	{
		std::cout<<"ZeroDivisionError"<<std::endl;
		return tr;
			}
			
			oRes = tl->getNumber() - (floor(tl->getNumber() / tr->getNumber()) * tr->getNumber());
					
			
			if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()))
				oAstRes = new AstNumber('I',oRes);
			else
				oAstRes = new AstNumber('F',oRes);
			
			delete tl;
			delete tr;
			//std::cout<<"AstUnMinusNode eval "<<oRes<<std::endl;
			return oAstRes;
}


//Eval function for Unary Plus operation
const Ast* AstUnPlusNode::eval() const { 
			
	Ast* oAstRes = NULL;
	double oRes = 0;
	const Ast *tl = getLeft()->eval();
			
	oRes = tl->getNumber();
			
	if( ('I' == tl->getNodetype()))
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
			
	delete tl;
		
	return oAstRes;
}

//Unary Minus Node Evaluation
const Ast* AstUnMinusNode::eval() const { 

		Ast* oAstRes = NULL;
		double oRes = 0;
		const Ast *tl = getLeft()->eval();
		oRes = -tl->getNumber();
			
		if( ('I' == tl->getNodetype()))
			oAstRes = new AstNumber('I',oRes);
		else
			oAstRes = new AstNumber('F',oRes);
			
		delete tl;
			
		return oAstRes;
}


//eval operation of Exponent Node
const Ast* AstPowNode::eval() const {
	
	Ast* oAstRes = NULL;
	double oRes = 0;
	const Ast *tl = getLeft()->eval();
	const Ast *tr = getRight()->eval();
	
	oRes = pow(tl->getNumber(),tr->getNumber());
			
	
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) && (0 <= tr->getNumber()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
	
			
	delete tl;
	delete tr;
	//std::cout<<"AstUnMinusNode eval "<<oRes<<std::endl;
	return oAstRes;
}

//Handle Operation
void handleOperation(char c, Ast *l,Ast *r){
	
	Ast *OperNode = NULL;
	
	switch(c)
	{
		case '+':	OperNode = new AstPlusNode(c,l,r); break;
		case '-':	OperNode = new AstMinusNode(c,l,r); break;
		case '*':	OperNode = new AstMultNode(c,l,r); break;
		case '/': 	OperNode = new AstDivNode(c,l,r); break;
		case 'D': 	OperNode = new AstIntDivNode(c,l,r); break;
		case '%':   OperNode = new AstModNode(c,l,r); break;
	}
	
	if(NULL == OperNode) {
		std::cout<<"invalid operand"<<std::endl;
		return;
	}
	const Ast *res = OperNode->eval();
	
	SymbolTable& sT = SymbolTable::getInstance();
	
	//sT.insertDSymbol(l->GetSymbol(),res->getNumber());
	
	sT.insertDSymbol(l,res);
	
	delete OperNode;
	delete res;

	return;
}
	
void treeFree(Ast *a) {
  switch(a->getNodetype()) {
   // two subtrees
  case '+':
  case '-':
  case '*':
  case '/':
  case 'E':
  case 'D':
  case '%':
           treeFree(a->getRight());

   // one subtrees
  case 'M':
  case 'P':
           treeFree(a->getLeft());

   //no subtree
  case 'I':
  case 'F':
  case 'S':
		if(NULL != a)
			delete a;
        break;

  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  
  
}




