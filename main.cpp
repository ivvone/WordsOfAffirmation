#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime> 

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

void select_color();
void random_color(string& practice);
string cheerleader();

int main() {

srand(time(NULL));

string userString;
cout << "Please input a line: ";
getline(cin, userString);
random_color(userString);
cout << endl;
userString = cheerleader();
random_color(userString);

return 0;
}

string cheerleader() {
  ifstream fin("motivation.txt");
  string line;

  srand(time(NULL));

  int a;
  a = rand() % 18;

  for (int i = 1; i <= a + 1; i++)
  {
    getline(fin , line);
  }

  return line;
}

void random_color(string& practice){
  for (int i = 0; i < practice.length(); i++){
    select_color();
    cout << practice.at(i);
  }
  cout << endl;
}

void select_color(){

  int color = rand() % 15;

  switch (color){
    case 1:
      cout << RED;
      break;
    case 2:
      cout << GREEN;
      break;
    case 3:
      cout << YELLOW;
      break;
    case 4:
      cout << BLUE;
      break;
    case 5:
      cout << MAGENTA;
      break;
    case 6:
      cout << CYAN;
      break;
    case 7:
      cout << WHITE;
      break;
    case 8:
      cout << BOLDGREEN;
      break;
    case 9:
      cout << BOLDBLUE;
      break;
    case 10:
      cout << BOLDRED;
      break;
    case 11:
      cout << BOLDYELLOW;
      break;
    case 12:
      cout << BOLDMAGENTA;
      break;
    case 13:
      cout << BOLDCYAN;
      break;
    case 14:
      cout << BOLDWHITE;
      break;
    default:    
      cout << RESET;
      break;
  }
}


