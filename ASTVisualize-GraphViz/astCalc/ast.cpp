// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
#  include <iostream>
#  include <stdlib.h>
#  include "ast.h"
#  include <cmath>
#  include <fstream>

double eval(Ast *a) {
  double v = 0;
  switch( a->getNodetype() ) {
  case 'K': v = a->getNumber(); break;
  case '+': v = eval(a->getLeft()) + eval(a->getRight()); break;
  case '-': v = eval(a->getLeft()) - eval(a->getRight()); break;
  case '*': v = eval(a->getLeft()) * eval(a->getRight()); break;
  case '/': v = eval(a->getLeft()) / eval(a->getRight()); break;
  case 'E': v = pow(eval(a->getLeft()),eval(a->getRight())); break;
  case 'M': v = -eval(a->getLeft()); break;
  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  return v;
}

void treeFree(Ast *a) {
  switch(a->getNodetype()) {
   // two subtrees
  case '+':
  case '-':
  case '*':
  case '/':
  case 'E':
           treeFree(a->getRight());

   // one subtrees
  case 'M':
           treeFree(a->getLeft());

   //no subtree
  case 'K':
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
           output<<a->getCtr()<<" [shape=box label=\""<<a->getNodetype()<<"\"]"<<std::endl;
		   WriteLabels(a->getLeft(),output);
		   WriteLabels(a->getRight(),output);
		   break;

   // one subtrees
  case 'M':
           output<<a->getCtr()<<" [shape=circle label=\" - \"]"<<std::endl;
		   WriteLabels(a->getLeft(),output);
		   break;

   //no subtree
  case 'K':
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


