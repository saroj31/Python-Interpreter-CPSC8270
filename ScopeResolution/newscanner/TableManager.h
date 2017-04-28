#include <vector>
#include <string>
#include <map>

class Ast;
class SymbolTable;
class AstNumber;

class TableManager {
public:
  static TableManager& getInstance();

  int GetCurrentScope();   //Will check for the current scope
  void SetCurrentScope(int scope);  //Will check for the size of the ST if the scope number is not there then it will make a new scope
  AstNumber* GetSymbolValue(std::string iSym); //Checks in the current Symbol Table if not found then it checks for parent symbol table and so on and returns the value
  void InsertSymbol(Ast* iSym,AstNumber *ipNum); //inserts the symbol in the current Symbol Table. It obtains the value through the curr Scope index
  SymbolTable *GetCurrentST();
  SymbolTable *GetSymbolTable(int scope);
  void SetFuncNode(Ast *ipFNode,std::string sFName);
  Ast* GetFuncNode(int scope);
  Ast* GetFuncNode(std::string isFName);
  
private:
  TableManager();
  //std::vector<Ast *> _vecFuncNode;     //each index contains the function Node which defines that scope.
  Ast *_vecFuncNode[10];
  std::vector<SymbolTable *> _vecScopeST; //each index contains the SymbolTable for the scope of that index.
  //SymbolTable *_vecScopeST[10];
  std::map<std::string, Ast*> Map4FNode;
  unsigned int currScope;
};