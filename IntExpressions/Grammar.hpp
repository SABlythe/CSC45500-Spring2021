#ifndef _GRAMMAR_HPP_
#define _GRAMMAR_HPP_

#include <fstream>

/*
<expr> -> <term> PLUS <expr>  |  <term> MINUS <expr>   |  <term>
<term> -> <factor> MULTIPLY <term> | <factor> DIVIDE <term>  | <factor>
<factor> -> INTEGER |  LPAREN <expr> RPAREN 
 */

class Grammar
{
public:
  Grammar() {}

  int expr(std::istream &is);
  int term(std::istream &is);
  int factor(std::istream &is);
};


#endif
