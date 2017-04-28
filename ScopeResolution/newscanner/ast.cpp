// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
#  include <iostream>
#  include <stdlib.h>
#  include "ast.h"
#  include "SymbolTable.h" 
#  include "TableManager.h"
# include <string.h>
#  include <fstream>

unsigned int g_scope = 0;

void setScope(int scope) {

  g_scope = scope;
  return;
}

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


const char *AstSymbol::GetSymbol() {
  
  const char *c = strdup(symName.c_str());
  return c; 

}


double AstSymbol::getNumber() const {
			
			double oVal = 0;
      TableManager &tMgr = TableManager::getInstance();
      SymbolTable *pST = tMgr.GetCurrentST();
			
      
			oVal = pST->giveDValue(symName);
			
			return oVal;
			}

const Ast* AstSymbol::eval() const {
	
		Ast *oAst = NULL;
		
    TableManager &tMgr = TableManager::getInstance();
    SymbolTable *pST = tMgr.GetCurrentST();
    ///std::cout << "AstSymbol::eval g_scope = " << g_scope << std::endl;
    //SymbolTable *pST = tMgr.GetSymbolTable(g_scope);
    
    if (NULL == pST) std::cout << "AstSymbol" << std::endl;
    //else std::cout << "AstSymbol::eval ST scope" << pST->GetScope() << std::endl;
		
		double nb;
		nb = pST->giveDValue(symName);
		
		AstNumber *astRes = pST->giveValue(symName);
		nb = astRes->getNumber();

    //std::cout << "AstSymbol::eval Symbol Value" << nb << std::endl;
		
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


const Ast* AstPrintNode::eval() const {

  //std::cout << "PrintNode Eval" << std::endl;
  const Ast *oResNode = _pRes->eval();

  //_pRes = oResNode;

  show(oResNode);

  return oResNode;

}

void AstPrintNode::show(const Ast *oResNode) const {

  //Todo: Check for current scope and if 
  //std::cout<<"line 19"<<std::endl;
  const Ast *l = oResNode;

  //std::cout<<"line 21"<<std::endl;
  if ('I' == l->getNodetype())
  {
    //std::cout<<"line 24"<<std::endl;
    int res = (int)trunc(l->getNumber());
    std::cout << res << std::endl;
  }
  else {
    float diff = l->getNumber() - trunc(l->getNumber());
    if (0.0 == diff)
      std::cout << l->getNumber() << ".0" << std::endl;   //very silly way to show float value ;)
    else
      std::cout << l->getNumber() << std::endl;   //Precision handling needs to be done
  }

  return;

}


AstFuncNode::AstFuncNode(char nodetype, int scope, std::string sFName) : AstNode(nodetype, NULL, NULL) {

  TableManager &TMgr = TableManager::getInstance();
  _scop = scope;
  //std::cout << "AstFuncNode: _scop " << scope << std::endl;
  _pST = TMgr.GetSymbolTable(_scop);
  _sFName = sFName;
}


void AstFuncNode::addstmt(Ast *istmt) {


  _vecStmt.push_back(istmt);
  
  
  return;
}

const Ast* AstFuncNode::eval() const {

  int size = _vecStmt.size();

  TableManager &Tmngr = TableManager::getInstance();

  int prevScope = Tmngr.GetCurrentScope();

  Tmngr.SetCurrentScope(_scop);

  for(int i=0; i<size ; i++)
  {
    //std::cout << "AstFuncNode::eval i=" << i << std::endl;
    Ast *p = _vecStmt[i];
    p->eval();
  }

  Tmngr.SetCurrentScope(prevScope);

  return NULL;
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
			
	//delete tl;
	//delete tr;
			
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
	
	//delete tl;
	//delete tr;
			
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
		
	//delete tl;
	//delete tr;
		
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
		//delete tl;
		return tr;
	}
			
	
	oRes = tl->getNumber() / tr->getNumber();			
	
			
	
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()))
		oRes = floor(oRes);
						
	if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()) )
		oAstRes = new AstNumber('I',oRes);
	else
		oAstRes = new AstNumber('F',oRes);
			
	//delete tl;
	//delete tr;
			
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
			
			//delete tl;
			//delete tr;
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
			
	//delete tl;
		
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
			
		//delete tl;
			
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
	
			
	//delete tl;
	//delete tr;
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
	
  TableManager &tMgr = TableManager::getInstance();
  SymbolTable *pST = tMgr.GetCurrentST();
	
	//sT.insertDSymbol(l->GetSymbol(),res->getNumber());
  //std::cout << "handleOperation: SymbolTable scope " << pST->GetScope() << std::endl;
	
	pST->insertDSymbol(l,res);
	
	//delete OperNode;
	//delete res;

	return;
}


bool HandleFunction(std::string iFuncName) {

  //std::cout << "Function handle " << iFuncName << std::endl;

  bool iOK = false;
  iFuncName = iFuncName + "()";
  //std::cout << "Function handle " << iFuncName << std::endl;
  TableManager &TMngr = TableManager::getInstance();
  AstFuncNode *pFuncNode = dynamic_cast<AstFuncNode*>(TMngr.GetFuncNode(iFuncName));
    
  if (NULL != pFuncNode)
  {
    //std::cout << "Match Found" << pFuncNode->GetFName();
    pFuncNode->eval();
    iOK = true;
  }
  //else
  //  std::cout << "Node not found" << std::endl;

  
  //if(iOK == true)
  //  std::cout << "Function is Evaluated. " << std::endl;
  
  return iOK;
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
  case 'p':
           treeFree(a->getLeft());

   //no subtree
  case 'I':
  case 'F':
  case 'S':
		if(NULL != a)
			//delete a;
        break;

  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  
  
}




