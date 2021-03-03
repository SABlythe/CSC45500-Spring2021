#include <fstream>
#include <iostream>

#include "Grammar.hpp"
#include "Token.hpp"

using namespace std;


int main(int argc, char * argv[])
{
  Token tok;

  string fname;

  cout << "Enter a filename: ";
  cin >> fname;
  
  ifstream ifile(fname);

  /*
  ifile >> tok;

  while(ifile)
    {
      cout << tok << endl;
      ifile >> tok;
    }
  */

  Grammar parser;

  cout << parser.expr(ifile) << endl;
  
  return 0;
}
