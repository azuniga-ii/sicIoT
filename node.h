#ifndef NODE_H
#define NODE_H

/***************************************
 *                                                                * 
 * Derivation Tree node hierarchy                     *
 *                                                                *
 * It follows the Composite pattern                   *
 *                                                                *
 * Author: Angel Zúñiga                                  *
 * email: azunigac@iingen.unam.mx                 *
 *                                                                *
 *                                                                *
 * Date: October 2019                                    *
 *                                                                *
 ***************************************/


#include <cstdlib>
#include <gvc.h>
#include <string>
#include <iostream>


using std::string;

using std::cout;
using std::endl;


class TVisitor;

class Node{
public:

  virtual void pass(TVisitor&)=0;
  virtual void setFChild(Node* const c)=0;
  virtual void setSChild(Node* const c)=0;
  virtual void setTChild(Node* const c)=0;
  virtual bool hasFChild() const=0;
  virtual bool hasSChild() const=0;
  virtual bool hasTChild() const=0;
  virtual Node* getFChild() const=0;
  virtual Node* getSChild() const=0;
  virtual Node* getTChild() const=0;
  virtual string getWord() const=0;

protected:

  Node(){
  }

};

/* Memory Node*/
class MNode: public Node{
public:
  MNode(){
  }
  
};

/* Memory Unary Node*/
class MUNode: public MNode{
public:
  MUNode():fc(NULL){}

  virtual void setFChild(Node* const c){
    fc = c;
  }

  virtual void setSChild(Node* const c){
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual void setTChild(Node* const c){
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasFChild() const{
    return fc != NULL;
  }

  virtual bool hasSChild() const{
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasTChild() const{
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getFChild() const{
    return fc;
  }

  virtual Node* getSChild() const{
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getTChild() const{
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual string getWord() const {
    cout << "Error: operation not supported. This is an unary node" << endl;
    exit(EXIT_FAILURE);
  }
  
private:
  Node* fc;
};


class MWHPNode: public MUNode{
public:
  virtual void pass(TVisitor& v);
};


/*Memory Binary Node*/
class MBNode: public MNode{
public:

  MBNode(): fc(NULL), sc(NULL){}

  virtual void pass(TVisitor& v)=0;
  
  virtual void setFChild(Node* const c){
    fc = c;
  }

  virtual void setSChild(Node* const c){
    sc = c;
  }

  virtual void setTChild(Node* const c){
    cout << "Error: operation not supported. This is a binary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasFChild() const{
    return fc != NULL;
  }

  virtual bool hasSChild() const{
    return sc != NULL;
  }

  virtual bool hasTChild() const{
    cout << "Error: operation not supported. This is a binary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getFChild() const{
    return fc;
  }

  virtual Node* getSChild() const{
    return sc;
  }

  virtual Node* getTChild() const{
    cout << "Error: operation not supported. This is a binary node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual string getWord() const {
    cout << "Error: operation not supported. This is a binary node" << endl;
    exit(EXIT_FAILURE);
  }
  
private:
  Node* fc;
  Node* sc;
};



class MSBNode: public MBNode{
public:
  virtual void pass(TVisitor& v);
};

class MNPNode: public MBNode{
public:
  virtual void pass(TVisitor& v);
};



class MNomNode: public MBNode{
public:
  virtual void pass(TVisitor& v);
};


class MPPNode: public MBNode{
public:
  virtual void pass(TVisitor& v);
};


/*Memory Ternary Node*/
class MTrNode: public MNode{
public:

  MTrNode(): fc(NULL), sc(NULL), tc(NULL){}

  virtual void pass(TVisitor& v)=0;
  
  virtual void setFChild(Node* const c){
    fc = c;
  }

  virtual void setSChild(Node* const c){
    sc = c;
  }

  virtual void setTChild(Node* const c){
    tc = c;
  }

  virtual bool hasFChild() const{
    return fc != NULL;
  }

  virtual bool hasSChild() const{
    return sc != NULL;
  }

  virtual bool hasTChild() const{
    return tc != NULL;
  }
  
  virtual Node* getFChild() const{
    return fc;
  }

  virtual Node* getSChild() const{
    return sc;
  }

  virtual Node* getTChild() const{
    return tc;
  }

  virtual string getWord() const {
    cout << "Error: operation not supported. This is a ternary node" << endl;
    exit(EXIT_FAILURE);
  }
  
private:
  Node* fc;
  Node* sc;
  Node* tc;
};

class MSNode: public MTrNode{
public:
  virtual void pass(TVisitor& v);
};

class MVPNode: public MTrNode{
public:
  virtual void pass(TVisitor& v);
};


class MSRNode: public MTrNode{
public:
  virtual void pass(TVisitor& v);
};

class MCVNode: public MTrNode{
public:
  virtual void pass(TVisitor& v);
};



/* Leaf Node */
class MLNode: public MNode{
public:
  MLNode(string s): word(s) {}
  virtual void pass(TVisitor& v)=0;

  virtual void setFChild(Node* const c){
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual void setSChild(Node* const c){
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual void setTChild(Node* const c){
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasFChild() const{
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasSChild() const{
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual bool hasTChild() const{
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getFChild() const {
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getSChild() const {
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }

  virtual Node* getTChild() const {
    cout << "Error: operation not supported. This is a leaf node" << endl;
    exit(EXIT_FAILURE);
  }
  
  virtual string getWord() const{
    return word;
  }
  
private:
  string word;
};

class MNNode: public MLNode{
public:
  MNNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MDNode: public MLNode{
public:
  MDNode(string t): MLNode(t){}
  
  virtual void pass(TVisitor& v);
};

class MJNode: public MLNode{
public:
  MJNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MRNode: public MLNode{
public:
  MRNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MCNode: public MLNode{
public:
  MCNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MCCNode: public MLNode{
public:
  MCCNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};


class MVNode: public MLNode{
public:
  MVNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MPrNode: public MLNode{
public:
  MPrNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MWRNode: public MLNode{
public:
  MWRNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

class MCMNode: public MLNode{
public:
  MCMNode(string t): MLNode(t){}

  virtual void pass(TVisitor& v);
};

#endif //NODE_H
