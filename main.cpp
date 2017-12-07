#include "DAG.h"

#include <iostream>


using namespace std;

int main()
{
  while(true)
  {
    cout << "(1) Open input file\n"
       << "(2) Topological Sort\n"
       << "(3) Quit\n"
       << ":";

    int choice = 0;

    while(choice != 1 && choice != 2 && choice != 3)
      cin >> choice;
    switch(choice)
    {
      case 1 : readFile();
        break;
      case 2 : topSort();
        break;
      case 3 : return 0;
    }
    cout << '\n';
  }
}
