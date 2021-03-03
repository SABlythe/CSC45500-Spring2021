#include "Grammar.hpp"
#include "Token.hpp"
using namespace std;

/*
<expr> -> <term> PLUS <expr>  |  <term> MINUS <expr>   |  <term>
<term> -> <factor> MULTIPLY <term> | <factor> DIVIDE <term>  | <factor>
<factor> -> INTEGER |  LPAREN <expr> RPAREN 


class Grammar
{
public:
  Grammar() {}

  int expr(istream &is);
  int term(istream &is);
  int factor(istream &is);
};

*/


int
Grammar::expr(istream &is)
{
  //<expr> -> <term> PLUS <expr>  |  <term> MINUS <expr>   |  <term>
  int value1 = term(is);

  int filePosition = is.tellg();
  
  Token tok;
  is >> tok;

  if (tok.type() == PLUS)
    {
      int value2 = expr(is);
      return value1 + value2;
    }
  else if (tok.type() == MINUS)
    {
      int value2 = expr(is);
      return value1 - value2;
    }
  else
    {
      is.seekg(filePosition);
      
      return value1;
    }
  
  return 0;
}
  
int
Grammar::term(istream &is)
{
  //<term> -> <factor> MULTIPLY <term> | <factor> DIVIDE <term>  | <factor>
  int value1 = factor(is);

  int filePosition = is.tellg();
  
  Token tok;
  is >> tok;

  if (tok.type() == MULTIPLY)
    {
      int value2 = term(is);
      return value1 * value2;
    }
  else if (tok.type() == DIVIDE)
    {
      int value2 = term(is);
      return value1 / value2;
    }
  else
    {
      is.seekg(filePosition);
      
      return value1;
    }

  return 0;
}

int
Grammar::factor(istream &is)
{
  //<factor> -> INTEGER |  LPAREN <expr> RPAREN

  Token tok;

  is >> tok;

  if (tok.type()==INTEGER)
    {
      return atoi(tok.value().c_str());
    }
  else if (tok.type()==LPAREN )
    {
      int value = expr(is);
      
      is >> tok; // assume this will be an RPAREN ....

      return value;
    }
  
  return 0;
}
