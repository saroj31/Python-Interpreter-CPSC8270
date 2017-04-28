#include "TableManager.h"
#include "SymbolTable.h"
#include "ast.h"

TableManager& TableManager::getInstance() {

  //std::cout << "Table Manager::getInstance" << std::endl;
  static TableManager tMgr;
  
  return tMgr;
};

void TableManager::SetFuncNode(Ast *ipFNode, std::string sFName) {

  _vecFuncNode[currScope] = ipFNode;

  sFName.erase(sFName.length() - 1, 1);
  //std::cout << "TableManager::SetFuncNode set " << sFName << std::endl;
  Map4FNode[sFName] = ipFNode;
  //_vecFuncNode.push_back(ipFNode);
}


TableManager::TableManager() {
 
  currScope = 0;
  //std::cout << "TableManager::TableManager " << currScope << std::endl;
  //_vecScopeST.reserve(10);
  //_vecFuncNode.reserve(10);
  SymbolTable *gST = new SymbolTable();
  //std::cout << "TableManager::SetCurrentScope created = " << scope << std::endl;
  _vecScopeST.push_back(gST);
  //_vecFuncNode.push_back(NULL);
  _vecFuncNode[0] = NULL;
  //_vecScopeST[0] = gST;
  
}

Ast *TableManager::GetFuncNode(int scope) {

  AstFuncNode *pFuncNode = NULL;
  pFuncNode = dynamic_cast<AstFuncNode *>(_vecFuncNode[scope]);
  //_vecFuncNode.push_back(ipFNode);

  return pFuncNode;
}

//Will check for the current scope
int TableManager::GetCurrentScope() {
  
  //std::cout << "TableManager::SetCurrentScope = " << currScope << std::endl;
  return currScope;

}

//Will check for the size of the ST if the scope number is not there then it will make a new scope
void TableManager::SetCurrentScope(int scope) {
  
  //std::cout << "TableManager::SetCurrentScope = " << scope << std::endl;
  SymbolTable *pST = NULL;
  
  if(NULL == _vecScopeST[scope]){
    
    pST = new SymbolTable(_vecScopeST[currScope],scope);
    _vecScopeST.push_back(pST);
    //_vecScopeST[scope] = pST;
    
  }

  //std::cout << "TableManager::SetCurrentScope scope set = " << scope << std::endl;
  currScope = scope;
 
  return;

}

//Checks in the current Symbol Table if not found then it checks for parent symbol table and so on and returns the value
AstNumber* TableManager::GetSymbolValue(std::string iSym) {

  AstNumber *iNumVal = NULL;
  if (currScope > 10/*_vecScopeST.size()*/)
    std::cout<<"invalid operation in Tablemanager:29" << std::endl;
  
  SymbolTable *pcurrST = _vecScopeST[currScope];
  while ((NULL != pcurrST) )
  {
    iNumVal = _vecScopeST[currScope]->giveValue(iSym);
    if (iNumVal != NULL)
      pcurrST = NULL; //Symbol found in this ST
    else
      pcurrST = pcurrST->GetParentST(); //Symbol not found in this ST so going to parent ST.
  }

  return iNumVal;
  
}

//inserts the symbol in the current Symbol Table. It obtains the value through the curr Scope index
void TableManager::InsertSymbol(Ast* iSym, AstNumber *ipNum) {

  if (currScope > 10/*_vecScopeST.size()*/)
    std::cout << "invalid operation in Tablemanager:29" << std::endl;

  SymbolTable *pCurrST = _vecScopeST[currScope];

  if (pCurrST)
    pCurrST->insertDSymbol(iSym,ipNum);
}
  
SymbolTable *TableManager::GetCurrentST(){

  //std::cout << "Tablemanager getCurrentST " << std::endl;
  if (currScope > _vecScopeST.size())
  {
    std::cout << "currScope Outbounded" << std::endl;
    return NULL;
    }
  
  //std::cout << "TableManager::GetCurrentST  currScope " << currScope << std::endl;
  SymbolTable *pST = _vecScopeST[currScope];
  if (NULL == pST) std::cout << "Symbol Table is not found" << std::endl;

  //std::cout << "TableManager::GetCurrentST scope is " << pST->GetScope() << std::endl;
  return pST;

}


Ast* TableManager::GetFuncNode(std::string isFName) {

  AstFuncNode *mtchFNode = NULL;
  
  std::map<std::string, Ast*>::iterator it;

  it = Map4FNode.find(isFName);

  if (it != Map4FNode.end())
    mtchFNode = dynamic_cast<AstFuncNode *>(it->second);
  //else
  //  std::cout << "Function " << isFName << " not found" << std::endl;


  return mtchFNode;

}

SymbolTable *TableManager::GetSymbolTable(int scope) {

  if (scope > _vecScopeST.size())
  {
    std::cout << "currScope Outbounded" << std::endl;
    return NULL;
  }

  SymbolTable *pST = _vecScopeST[scope];
  if (NULL == pST)
  {
   
    std::cout << "TableManager::GetSymbolTable ST not found in index" << scope<< std::endl;
    //pST = _vecScopeST[scope - 1];
  }

  return pST;

}
