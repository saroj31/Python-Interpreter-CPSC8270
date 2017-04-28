//  Declarations for an AST calculator
//  From "flex & bison", fb3-1, by John Levine
//  Adapted by Brian Malloy

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
extern void yyerror(const char*);
extern void yyerror(const char*, const char);
class SymbolTable;


//Declaration and definition both written here.
//TODO: make it an abstract class
class Ast {
public:
  Ast(int n) : nodetype(n) {}
  virtual ~Ast() {}
  char getNodetype() const { return nodetype; }
  virtual Ast* getLeft() const {  return NULL; }
  virtual Ast* getRight() const {  return NULL; }
  virtual double getNumber() const { return 0; }
  virtual const Ast* eval() const {	return NULL;}
  virtual const char *GetSymbol() {
    return NULL;
  }
  private:
  char nodetype;
};

//Declaration and definition both written here.
//TODO: make it an abstract class
class AstNode : public Ast {
public:
  AstNode(char nodetype, Ast* l, Ast* r) : 
  Ast(nodetype), left(l), right(r) { }
  virtual ~AstNode() { }
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  virtual const Ast* eval() const;
  
private:
  Ast *left;
  Ast *right;
};

//For Float & Int numbers both
class AstNumber : public Ast {
public:
  AstNumber(char nodetype, double n) : Ast(nodetype), number(n) {} 
  virtual ~AstNumber() {}
  virtual double getNumber() const { return number;}
  virtual const Ast* eval() const;
private:
  double number;

};

//ForSymbol the type of symbol is decided by the NUmber that is corresponding to it in the Symbol Table
class AstSymbol : public AstNumber{

public:
	AstSymbol(char nodetype,std::string sName );
	virtual ~AstSymbol() {}
  virtual const char *GetSymbol();// { char *c = strdup(symName.c_str());  return c; }
  virtual std::string *GetsSymbol() { std::string *s = new std::string(symName); return s; }
	virtual double getNumber() const ;
	virtual const Ast* eval() const ;

private:
	std::string symName;
	bool isInt;
};

//For AstPrintNode
class AstPrintNode : public AstNode {
public:
  AstPrintNode(char nodetype, Ast* l) :
    AstNode(nodetype, l, NULL) {
          _pRes = dynamic_cast<const AstNumber*>(l);
      }
  virtual ~AstPrintNode() { }
  virtual const Ast* eval() const;
  virtual void show(const Ast *) const;

private:
  const AstNumber *_pRes;

};

//FuncNode needed
class AstFuncNode : public AstNode {
public:
  AstFuncNode(char nodetype,int scope,std::string sfName);
  virtual ~AstFuncNode() { }
  virtual const Ast* eval() const;
  virtual void addstmt(Ast *istmt);
  virtual std::string GetFName() { return _sFName; };
  virtual int GetScope() { return _scop; }
private:
  SymbolTable *_pST;
  std::vector<Ast *> _vecStmt;
  int _scop;
  std::string _sFName;
};

//For Plus Node
class AstPlusNode : public AstNode{
	public:
		AstPlusNode(char nodetype, Ast* l, Ast* r) : AstNode(nodetype,l,r) {}
		virtual const Ast* eval() const;
};

//Node for Minus Operation
class AstMinusNode : public AstNode{
	public:
		AstMinusNode(char nodetype, Ast* l, Ast* r) : 
		AstNode(nodetype,l,r) {}
		
		virtual const Ast* eval() const;
};

//Node for Multiply Node
class AstMultNode : public AstNode{
	public:
		AstMultNode(char nodetype, Ast* l, Ast* r) : 
		AstNode(nodetype,l,r) {}
		
		virtual const Ast* eval() const;
};

//Node for Divide operation
class AstDivNode : public AstNode{
	public:
		AstDivNode(char nodetype, Ast* l, Ast* r) : 
		AstNode(nodetype,l,r) {}
		
		virtual const Ast* eval() const;
};

class AstIntDivNode : public AstNode{
	
	public:
		AstIntDivNode(char nodetype, Ast* l, Ast *r) : AstNode(nodetype,l,r){}
	
		virtual const Ast* eval() const { 
			Ast* oAstRes = NULL;
			double oRes = 0;
			const Ast *tl = getLeft()->eval();
			const Ast *tr = getRight()->eval();
			
			if( 0.0 == tr->getNumber())
			{
				std::cout<<"ZeroDivisionError"<<std::endl;
				return tr;
			}
			
			oRes = tl->getNumber() / tr->getNumber();
			oRes = floor(oRes);
			
			if( ('I' == tl->getNodetype()) && ('I' == tr->getNodetype()))
				oAstRes = new AstNumber('I',oRes);
			else
				oAstRes = new AstNumber('F',oRes);
			
			//delete tl;
			//delete tr;

			return oAstRes;
		}

};

class AstModNode : public AstNode{
	
	public:
		AstModNode(char nodetype, Ast* l, Ast *r) : AstNode(nodetype,l,r){}
		
		virtual const Ast* eval() const;
};

class AstUnPlusNode : public AstNode{
	public:
		AstUnPlusNode(char nodetype, Ast* l) : 
			AstNode(nodetype,l,NULL) {}
		
		virtual const Ast* eval() const;
};

//Eval operation for Unary Minus Node
class AstUnMinusNode : public AstNode{
	public:
		AstUnMinusNode(char nodetype, Ast* l) : AstNode(nodetype,l,NULL) {}
		virtual const Ast* eval() const;
};


//Eval operation for Power Node
class AstPowNode : public AstNode{
	
	public:
		AstPowNode(char nodetype, Ast* l, Ast *r) : AstNode(nodetype,l,r){}
		
		virtual const Ast* eval() const;
};

double eval(Ast*);   // Evaluate an AST
void treeFree(Ast*); // //delete and free an AST

void handleOperation(char c, Ast *l,Ast *r);
void setScope(int scope);
bool HandleFunction(std::string sFName);
//void makeGraph(Ast *);
//void makeGraph(const AstNode* node, std::fstream& output);

 


