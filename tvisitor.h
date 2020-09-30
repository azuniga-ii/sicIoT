#ifndef TVISITOR_H
#define TVISITOR_H

/***************************************
 *                                                                * 
 * Tree Visitor                                               *
 *                                                               *
 * It includes:                                               *
 *                                                               *
 * 1) the Derivation Tree Render and               *
 *                                                               *
 * 2) the Code Generator                               *
 *                                                               *
 * It follows the Visitor pattern                        *
 *                                                               *
 * Author: Angel Zúñiga                                 *
 * email: azunigac@iingen.unam.mx                *
 *                                                               *
 *                                                               *
 * Date: October 2019                                   *
 *                                                               *
 ***************************************/

#include <cstdlib>
#include <gvc.h>
#include <iostream>
#include <string>
#include "node.h"

using std::cout;
using std::endl;
using std::ostream;

using std::string;


/* Tree Visitor */
class TVisitor{
public:

  virtual void visit(MSNode*)= 0;
  virtual void visit(MSBNode*)=0;
  virtual void visit(MWHPNode*)=0;
  virtual void visit(MNPNode*)= 0;
  virtual void visit(MSRNode*)=0;
  virtual void visit(MNomNode*)= 0;
  virtual void visit(MVPNode*)= 0;
  virtual void visit(MCVNode*)=0;
  virtual void visit(MPPNode*)= 0;
  virtual void visit(MNNode*)= 0;
  virtual void visit(MDNode*)= 0;
  virtual void visit(MJNode*)= 0;
  virtual void visit(MRNode*)= 0;
  virtual void visit(MCNode*)= 0;
  virtual void visit(MCCNode*)= 0;
  virtual void visit(MVNode*)= 0;
  virtual void visit(MPrNode*)= 0;
  virtual void visit(MWRNode*)=0;
  virtual void visit(MCMNode*)=0;
  
protected:
  TVisitor(){}
  
};


/* Print Visitor */
class PVisitor: public TVisitor{
public:

  virtual void visit(MSNode* n);
  virtual void visit(MSBNode* n);
  virtual void visit(MWHPNode*);
  virtual void visit(MNPNode* n);
  virtual void visit(MSRNode*); 
  virtual void visit(MNomNode* n);
  virtual void visit(MVPNode* n);
  virtual void visit(MCVNode*); 
  virtual void visit(MPPNode* n);
  virtual void visit(MNNode* n);
  virtual void visit(MDNode* n);
  virtual void visit(MJNode* n);
  virtual void visit(MRNode*); 
  virtual void visit(MCNode*);
  virtual void visit(MCCNode*); 
  virtual void visit(MVNode* n);
  virtual void visit(MPrNode* n);
  virtual void visit(MWRNode* n);
  virtual void visit(MCMNode* n);
  
};


/* Derivation Tree Visitor */
class DTVisitor: public TVisitor{
public:

  DTVisitor(string fname): oftname(fname){
    G = agopen(NULL,Agdirected,NULL);
  }
  
  virtual void printTree();

  virtual void visit(MSNode* n);
  virtual void visit(MSBNode* n);
  virtual void visit(MWHPNode* n);
  virtual void visit(MNPNode* n);
  virtual void visit(MSRNode* n){
    cout << "Error: Node not supported" << endl;
    exit(EXIT_FAILURE);
  }
  virtual void visit(MNomNode* n);
  virtual void visit(MVPNode* n);
  virtual void visit(MCVNode*);
  virtual void visit(MPPNode* n);
  virtual void visit(MNNode* n);
  virtual void visit(MDNode* n);
  virtual void visit(MJNode* n);
  virtual void visit(MRNode* n);
  virtual void visit(MCNode*){
    cout << "Error: Node not supported" << endl;
    exit(EXIT_FAILURE);
  }
  virtual void visit(MCCNode*); 
  virtual void visit(MVNode* n);
  virtual void visit(MPrNode* n);
  virtual void visit(MWRNode*);
  virtual void visit(MCMNode*);
  
private:
  string oftname;
  Agraph_t* G;
  Agnode_t* c;
};


/* Code Generator Visitor */
class CGVisitor: public TVisitor{
public:

  CGVisitor(ostream& o): os(o), cg(""), il(""){
  }
  
  CGVisitor(): os(cout), cg(""), il(""){
  }


  virtual void visit(MSNode* n);
  virtual void visit(MSBNode* n);
  virtual void visit(MWHPNode* n);
  virtual void visit(MNPNode* n);
  virtual void visit(MSRNode* n){
    cout << "Error: Node not supported" << endl;
    exit(EXIT_FAILURE);
  }
  virtual void visit(MNomNode* n);
  virtual void visit(MVPNode* n);
  virtual void visit(MCVNode*);
  virtual void visit(MPPNode* n);
  virtual void visit(MNNode* n);
  virtual void visit(MDNode* n);
  virtual void visit(MJNode* n);
  virtual void visit(MRNode* n);
  virtual void visit(MCNode*){
    cout << "Error: Node not supported" << endl;
    exit(EXIT_FAILURE);
  }
  virtual void visit(MCCNode* n);
  virtual void visit(MVNode* n);
  virtual void visit(MPrNode* n);
  virtual void visit(MWRNode*);
  virtual void visit(MCMNode*);
  
private:
  ostream& os; //output stream
  string cg; //generated code
  string il; //indentation level
};





#endif //TVISITOR_H
