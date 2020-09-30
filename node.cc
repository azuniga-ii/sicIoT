/***************************************
 *                                                               * 
 * Derivation Tree node hierarchy                    *
 *                                                               *
 * It follows the Composite pattern                  *
 *                                                               *
 * Author: Angel Zúñiga                                 *
 * email: azunigac@iingen.unam.mx                *
 *                                                               *
 *                                                               *
 * Date: October 2019                                  *
 *                                                                *
 ***************************************/


#include "node.h"
#include "tvisitor.h"

void MSNode::pass(TVisitor& v){
  v.visit(this);
}

void MSBNode::pass(TVisitor& v){
  v.visit(this);
}

void MWHPNode::pass(TVisitor& v){
  v.visit(this);
}


void MNPNode::pass(TVisitor& v){
  v.visit(this);
}

void MSRNode::pass(TVisitor& v){
  v.visit(this);
}

void MNomNode::pass(TVisitor& v){
  v.visit(this);
}

void MPPNode::pass(TVisitor& v){
  v.visit(this);
}

void MVPNode::pass(TVisitor& v){
  v.visit(this);
}

void MCVNode::pass(TVisitor& v){
  v.visit(this);
}

void MNNode::pass(TVisitor& v){
  v.visit(this);
}

void MDNode::pass(TVisitor& v){
  v.visit(this);
}

void MJNode::pass(TVisitor& v){
  v.visit(this);
}

void MRNode::pass(TVisitor& v){
  v.visit(this);
}

void MCNode::pass(TVisitor& v){
  v.visit(this);
}

void MCCNode::pass(TVisitor& v){
  v.visit(this);
}

void MVNode::pass(TVisitor& v){
  v.visit(this);
}

void MPrNode::pass(TVisitor& v){
  v.visit(this);
}

void MWRNode::pass(TVisitor& v){
  v.visit(this);
}

void MCMNode::pass(TVisitor& v){
  v.visit(this);
}
