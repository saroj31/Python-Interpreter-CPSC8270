// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
//astServices.cpp
#  include <iostream>
#  include <stdlib.h>
#  include "ast.h"
#  include <cmath>
#  include <fstream>

double eval(Ast*);   // Evaluate an AST
AstNumber * eval(AstNode*);
void treeFree(Ast*); // delete and free an AST

AstNumber *Divide(Ast *l,Ast *r);

void makeGraph(Ast *);
void makeGraph(const AstNode* node, std::fstream& output);


double eval(Ast *a) {
  double v = 0;
  double lval=0,rval=0;
  switch( a->getNodetype() ) {
  case 'K': v = trunc(a->getNumber()); break; //Integer Number
  case 'F': v = a->getNumber(); break;	//Float Number
  case '+': v = eval(a->getLeft()) + eval(a->getRight()); break;	//Sum Operation
  case '-': v = eval(a->getLeft()) - eval(a->getRight()); break;	//Minus Operation
  case '*': v = eval(a->getLeft()) * eval(a->getRight()); break;
  case '/': 
			//divide(a->getLeft(),a->getRight());
			if( (a->getLeft()->getNodetype() == 'K') && (a->getRight()->getNodetype() == 'K') )
			{
				v = (int)eval(a->getLeft()) / (int)eval(a->getRight());
				std::cout<<"/ division int"<<std::endl;
			}
			else{
				v = eval(a->getLeft()) / eval(a->getRight());
				std::cout<<"/ float int"<<std::endl;
			}
			
			break;

  case '%':	
			lval = eval(a->getLeft()); 
			rval = eval(a->getRight());
			v = (lval - (trunc(lval/rval) * rval)); break;
			
  case 'E': v = pow(eval(a->getLeft()),eval(a->getRight())); break;   //Exonential Operation
  case 'D': 
			if( (a->getLeft()->getNodetype() == 'K') && (a->getRight()->getNodetype() == 'K') )
				v = (int)eval(a->getLeft()) / (int)eval(a->getRight());
			else
				v = eval(a->getLeft()) / eval(a->getRight());
			v = floor(v);
			break;
			
  case 'M': v = -eval(a->getLeft()); break;		//unary Minus Operation
  case 'P': v = eval(a->getLeft()); break;		//unary Add Operation
  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  return v;
}

AstNumber * eval(AstNode*){
	
	AstNumber *oRes;
	
	return oRes; 
}

AstNumber *Divide(Ast *l,Ast *r){
	
	AstNumber *oRes;
	
	return oRes;
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
           treeFree(a->getRight());

   // one subtrees
  case 'M':
  case 'P':
           treeFree(a->getLeft());

   //no subtree
  case 'K':
  case 'F':
        delete a;
        break;

  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  
  
}

void WriteLabels(Ast *a,std::fstream& output) {
  switch(a->getNodetype()) {
   // two subtrees
  case '+':
  case '-':
  case '*':
  case '/':
  case 'E':
  case 'D':
           output<<a->getCtr()<<" [shape=box label=\""<<a->getNodetype()<<"\"]"<<std::endl;
		   WriteLabels(a->getLeft(),output);
		   WriteLabels(a->getRight(),output);
		   break;

   // one subtrees
  case 'M':
  case 'P':
           output<<a->getCtr()<<" [shape=circle label=\" - \"]"<<std::endl;
		   WriteLabels(a->getLeft(),output);
		   break;

  
   //no subtree
  case 'K':
  case 'F':
        output<<a->getCtr()<<" [label=\""<<a->getNumber()<<"\"]"<<std::endl;
        break;

  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
}

void makeGraph(const Ast *node, std::fstream& output){
  
 
  if (node) {
	
    switch (node->getNodetype()) {
	
    case 'K':    //Terminal
			output << node->getCtr()<<std::endl;
			break;   //No nodes

    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case 'E': 
	case 'D': 
			output << node->getCtr()<< "->";  //sentence not finished yet
            if (node->getLeft()) {

              if ('K' != node->getLeft()->getNodetype())
				output << node->getLeft()->getCtr()<<std::endl; //sentence finishes here
            }

            makeGraph(node->getLeft(), output);
			
			//The above line will return only after the line is printed. So now we traverse Right
			output << node->getCtr()<< "->";
            if (node->getRight()) {

              if ('K' != node->getRight()->getNodetype()) 
				  output << node->getRight()->getCtr()<<std::endl;
            }

            makeGraph(node->getRight(), output);
            break;

    case 'M':
	case 'F':
      
			output<<node->getCtr()<<"->";
			makeGraph(node->getLeft(), output);
			break;
    }

    }
      
}


void makeGraph(Ast *root){

  std::fstream output;
  output.open("graph.gv", std::ios::out);
  output << "digraph G {" << std::endl;
  WriteLabels(root,output);
  makeGraph(root, output);
  output << "}" << std::endl;
  output.close();

}


