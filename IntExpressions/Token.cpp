#include "Token.hpp"

using namespace std;

static int **DFA=nullptr; 

std::istream&
Token::read(std::istream &is)
{
  // if we need to build state diagram table ....
  if (DFA==nullptr)
    {
      DFA = new int* [DIVIDE+1];
      for (int state=0; state<=DIVIDE; state++)
	{
	  DFA[state] = new int[256];
	  for (int ch=0; ch<256; ch++)
	    {
	      DFA[state][ch] = ERROR;
	    }
	}

      // state 0 tarnsitions
      for (char ch = '0'; ch <='9'; ch++)
	DFA[0][(int) ch] = INTEGER;

      DFA[0]['('] = LPAREN;
      DFA[0][')'] = RPAREN; 
      DFA[0]['+'] = PLUS;
      DFA[0]['-'] = MINUS;
      DFA[0]['*'] = MULTIPLY;
      DFA[0]['/'] = DIVIDE;

      // state 1 tarnsitions
      for (char ch = '0'; ch <='9'; ch++)
	DFA[1][(int) ch] = INTEGER;      
    }

  _value="";
  _type=ERROR;

  int curr=0;
  int prev=ERROR;
  
  char ch;
  is >> ch; // skips whtespace ... which mght be an issue if you care about spaces.
  if (!is)
    return is;

  is.putback(ch);

  while(curr!=ERROR)
    {
      ch = is.get(); // does not skip whitespace   2   4  would
                     // end up with only 2 as token!

      prev = curr;
      curr = DFA[curr][(int) ch];

      if (curr!=ERROR)
	_value += ch; 
    }

  if (is)
    is.putback(ch);
  
  _type = prev;
  
  return is;
}


std::ostream& operator<<(std::ostream &os, const Token &t)
{
  return t.print(os);
}

std::istream& operator>>(std::istream &is, Token &t)
{
  return t.read(is);
}
