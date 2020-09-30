#ifndef TBDER_H
#define TBDER_H

/***************************************
 *                                                                * 
 * Tree builder                                               *
 *                                                                *
 * It follows the Builder pattern                        *
 *                                                                *
 * Author: Angel Zúñiga                                  *
 * email: azunigac@iingen.unam.mx                 *
 *                                                                *
 *                                                                *
 * Date: October 2019                                    *
 *                                                                *
 ***************************************/




#include <gvc.h>
#include <string>
#include <sstream>

#include "node.h"

using std::cout;
using std::endl;

class TBuilder{
public:

  virtual Node* bSNode()=0;
  virtual Node* bSBNode()=0;
  virtual Node* bWHPNode()=0;
  virtual Node* bNPNode()=0;
  virtual Node* bSRNode()=0;
  virtual Node* bDNode(string t)=0;
  virtual Node* bJNode(string t)=0;
  virtual Node* bRNode(string t)=0;
  virtual Node* bCNode(string t)=0;
  virtual Node* bCCNode(string t)=0;
  virtual Node* bVPNode()=0;
  virtual Node* bCVNode()=0;
  virtual Node* bNomNode()=0;
  virtual Node* bNNode(string t)=0;
  virtual Node* bVNode(string t)=0;
  virtual Node* bPPNode()=0;
  virtual Node* bPrNode(string t)=0;
  virtual Node* bWRNode(string t)=0;
  virtual Node* bCMNode(string t)=0;
  

  virtual void setFChild(Node* p, Node* c)=0;
  virtual void setSChild(Node* p, Node* c)=0;
  virtual void setTChild(Node* p, Node* c)=0;
  
  virtual void setLMChild(Node* p, Node* c)=0;

};

/* Memory Tree Builder */
class MTBuilder: public TBuilder{
public:

  MTBuilder(){
  }

  virtual Node* bSNode(){
    return new MSNode;
  }

  virtual Node* bSBNode(){
    return new MSBNode;
  }

  virtual Node* bWHPNode(){
    return new MWHPNode;
  }

  virtual Node* bNPNode(){
    return new MNPNode;
  }

  virtual Node* bSRNode(){
    return new MSRNode;
  }

  virtual Node* bDNode(string t){
    return new MDNode(t);
  }

  virtual Node* bJNode(string t){
    return new MJNode(t);
  }

  virtual Node* bRNode(string t){
    return new MRNode(t);
  }

  virtual Node* bCNode(string t){
    return new MCNode(t);
  }

  virtual Node* bCCNode(string t){
    return new MCCNode(t);
  }

  virtual Node* bVPNode(){
    return new MVPNode;
  }

  virtual Node* bCVNode(){
    return new MCVNode;
  }

  virtual Node* bNomNode(){
    return new MNomNode;
  }

  virtual Node* bNNode(string t){
    return new MNNode(t);
  }

  virtual Node* bVNode(string t){
    return new MVNode(t);
  }

  virtual Node* bPPNode(){
    return new MPPNode;
  }
  
  virtual Node* bPrNode(string t){
    return new MPrNode(t);
  }

  virtual Node* bWRNode(string t){
    return new MWRNode(t);
  }

  virtual Node* bCMNode(string t){
    return new MCMNode(t);
  }

  virtual void setFChild(Node* p, Node* c){
    p->setFChild(c);
  }

  virtual void setSChild(Node* p, Node* c){
    p->setSChild(c);
  }

  virtual void setTChild(Node* p, Node* c){
    p->setTChild(c);
  }
  
  virtual void setLMChild(Node* p, Node* c){
    Node* tmp = p;
    while(tmp->hasFChild()){
      tmp = tmp->getFChild();
    }
    tmp->setFChild(c);
  }

};


#endif //TBDER_H
