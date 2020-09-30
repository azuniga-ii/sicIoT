/*************************************************
 *                                                                                 * 
 * A simple instruction compiler for the IoT                         *
 * main driver                                                                *
 *                                                                                 *
 * Author: Angel Zúñiga                                                   *
 * email: azunigac@iingen.unam.mx                                  *
 *                                                                                 *
 *                                                                                 *
 * Date: October 2019                                                     *
 *                                                                                 *
 *************************************************/

#include <iostream>
#include <fstream>
#include <sstream>


#include "tbder.h"
#include "lex.h"
#include "grm.tab.hh"

#include "tvisitor.h"


using std::cout;
using std::endl;

using std::ofstream;
using std::stringstream;


void pusagemsg(void){
  stringstream ss("");

  ss << "Usage: sicIoT inputfile\n";
  ss <<"Options:\n";
  ss << "-o outputfile" << "\t\tby default the outputfile name is <out.c>\n";
  ss << "-tree" << "\t\t\trender the derivation tree into <outputfile.png>\n";
  ss << "--help" << "\t\t\tdisplay this information\n\n";
  ss << "Examples: sicIoT turn_on_the_light.nl\n";
  ss << "          sicIoT turn_on_the_light.nl -o turn_on_the_light.c\n";
  ss << "          sicIoT -tree turn_on_the_light.nl -o turn_on_the_light.c\n";
  
  cout << ss.str();
  exit(EXIT_SUCCESS);
}


int main(int argc,char* argv[]){
  boolean tg = false;
  string ifname = "";
  string ofname = "";
  string oftname = "";
  
  
  if(argc == 1){
    pusagemsg();
  }

  
  for(int i=1; i < argc; i++){
    if (string(argv[i]) == "-tree"){
      tg = true;
    } else if (string(argv[i]) == "-o"){
      i++;
      if(i < argc){
	ofname = string(argv[i]);
	if(ofname[0] == '-'){
	  pusagemsg();
	}
	if( (ofname.size() > 2) && (ofname.substr(ofname.size()-2, ofname.size()) == ".c")){
	  oftname = ofname.substr(0,ofname.size()-2) + ".png";
	}else{
	    oftname = ofname + ".png";
	}
      } else{
	pusagemsg();
      }
      continue;
    } else if (string(argv[i]) == "--help"){
      pusagemsg();
    } else if (string(argv[i]).substr(0,2) == "--"){
      pusagemsg();
    }

    else{
      ifname = string(argv[i]);
    }
  }

  if(ifname == ""){
    pusagemsg();
  }

  if(ofname == ""){
    ofname = "out.c";
    oftname = "out.png";
  }
  
  MTBuilder b;

    yyin = fopen(ifname.c_str(),"r");
    if(yyin == NULL){
      cout << "Error: input file " << ifname << " does not exist\n" << endl;
      pusagemsg();
    }
    yy::enparser enp(b);
    enp.parse();
    Node* entree = enp.getTree();
    if(tg){
      DTVisitor dtven(oftname);
      entree->pass(dtven);
      dtven.printTree();
    }
    ofstream of(ofname.c_str());
    CGVisitor cgen(of);
    entree->pass(cgen);
    of.flush();
    of.close();

}

