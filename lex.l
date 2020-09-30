%option noyywrap
%option outfile="lex.c" header-file="lex.h"

%{

/**
 * Lexer flex specification
 *
 * Author: Angel Zúñiga
 * email: azunigac@iingen.unam.mx
 *
 * Date: October 2019
 *
 **/

#include "grm.tab.hh"

#define YY_DECL yy::parser::token_type yylex_aux(yy::parser::semantic_type* yylval)

typedef yy::parser::token token;

#define yyterminate() return yy::parser::token::END

%}

VERB [Tt]"urn"|[Mm]"easure"|[Ss]"end"|[Rr]"eceive"|"reply"|"pressing"
PREP "on"
DET "the"
ADJ "red"|"green"|"blue"
ADV "periodically"
WHADV [Ww]"hen"			
NOUN "light"|"led"|"temperature"|"humidity"|"luminosity"|"messages"|"button"
CCNJ "and"
CM ","
NL "\n"
WS [ \t]

%%

{VERB} { yylval->VERB = new std::string(yytext); return token::VERB;}
{PREP} { yylval->PREP = new std::string(yytext); return token::PREP;}
{DET}  { yylval->DET = new std::string(yytext); return token::DET;}
{ADJ}  { yylval->ADJ = new std::string(yytext); return token::ADJ;}
{ADV}  { yylval->ADV = new std::string(yytext); return token::ADV;}
{WHADV} { yylval->WHADV = new std::string(yytext); return token::WHADV;}
{NOUN} {yylval->NOUN = new std::string(yytext); return token::NOUN;}
{CCNJ}  { yylval->CCNJ = new std::string(yytext); return token::CCNJ;}
{CM} { yylval->CM = new std::string(yytext); return token::CM;}
{NL} {}
{WS} {}
