%defines
%skeleton "lalr1.cc"
%parse-param{TBuilder& tb}
%parse-param{Node*& troot}

%code requires{

/**
 * Parser bison specification
 *
 * Author: Angel Zúñiga
 * email: azunigac@iingen.unam.mx
 *
 * Date: October 2019
 *
 **/

    class TBuilder;
    class Node;
 }

%{
#include <iostream>
#include "tbder.h"
#include "tvisitor.h"
using std::string;
%}

%define api.value.type union			

%code{
    
extern yy::parser::token_type yylex_aux(yy::parser::semantic_type* yylval);    
    
namespace yy{  

   parser::token_type yylex(parser::semantic_type* yylval){
       return yylex_aux(yylval);
   }
    
   void parser::error(const std::string& m){
       std::cerr << "Error: " << m << std::endl;
   }
  
}

}

%code provides{

    namespace yy{
	class enparser: public parser{
	public:
	   enparser(TBuilder& tb): parser(tb,tree){}

	   Node* getTree() const{
	       return tree;
	   }

	private:
	   Node* tree;
        };

    }
}
			
			

%token<std::string*> VERB PREP DET ADJ NOUN ADV CCNJ CM WHADV

%type<Node*> n jj d p v nom np pp vp s r cv cc whadvp wr sb ss cm

%token END 0

%%


input: 	s  { troot = $1;}
	|	sb { troot = $1;}
	;


sb:		whadvp ss {$$ = tb.bSBNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);}
	;

ss:		s cm s {$$ = tb.bSNode(); tb.setFChild($$,$1); tb.setSChild($$,$2); tb.setTChild($$,$3);}
	;

s:		vp { $$ = tb.bSNode(); tb.setFChild($$,$1); }
	|	cv { $$ = tb.bSNode(); tb.setFChild($$,$1); }	
	;

whadvp:	wr { $$ = tb.bWHPNode(); tb.setFChild($$,$1); }
	;

cv:		vp cc vp {$$ = tb.bCVNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);
                              tb.setTChild($$,$3);}
	;

vp:		v np { $$ = tb.bVPNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);}
	|	v np r { $$ = tb.bVPNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);
                            tb.setTChild($$,$3);}
	|	v pp { $$ = tb.bVPNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);}
	|	v {$$= tb.bVPNode(); tb.setFChild($$,$1);}
	;

pp:		p np { $$ = tb.bPPNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);}
	;

np:		d nom { $$ = tb.bNPNode(); tb.setFChild($$,$1); tb.setSChild($$,$2);}
	|	nom { $$ = tb.bNPNode(); tb.setFChild($$,$1);}
	;

nom:	jj n { $$ = tb.bNomNode(); tb.setFChild($$,$1); tb.setSChild($$,$2); }
	|	n { $$ = tb.bNomNode(); tb.setFChild($$,$1);}
	;

v:		 VERB { $$ = tb.bVNode(*$1); }
	;

p:		PREP { $$ = tb.bPrNode(*$1); }
	;

d:		DET {$$ = tb.bDNode(*$1); }
	;

jj:		ADJ {$$ = tb.bJNode(*$1); }
	;

n:		NOUN {$$ = tb.bNNode(*$1);}
	;

r:		ADV {$$ = tb.bRNode(*$1);}
	;

cc:		CCNJ { $$= tb.bCCNode(*$1);}
	;

wr:		WHADV { $$ = tb.bWRNode(*$1);}
	;

cm:		CM { $$ = tb.bCMNode(*$1);} 
	;

%%

