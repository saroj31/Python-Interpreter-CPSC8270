#include <string>
#include <map>

class AstNumber;
class Ast;

class SymbolTable{
	
public:
	static SymbolTable& getInstance();
	void insertDSymbol(std::string iSymName,double dVal);
	void insertDSymbol(Ast *iSymbol,const Ast *iNumber);
	double giveDValue(std::string iSymName);
	AstNumber* giveValue(std::string iSymName);
	
	void free();
	
private:
	SymbolTable(){}
	std::map<std::string, AstNumber*> iMap;  //this did not work second  time iteration of value caus
	std::map<std::string, double> idMap;
	
};