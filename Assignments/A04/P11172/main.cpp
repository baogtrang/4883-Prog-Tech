#include <iostream>
#include <fstream>
using namespace std;
int main(){
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");
  if (!inputFile.is_open()||!outputFile.is_open()){
    cerr <<"Error opening files!" <<endl;
    return 1;
  }
  int numCases, a, b;
  inputFile >> numCases;
  while (numCases-- > 0 && inputFile >>a>>b){
    if (a<b) {
      outputFile << "<" <<endl;
    } else if (a>b){
      outputFile << ">" <<endl;
    } else {
      outputFile <<"=" <<endl; 
    }
  }
  inputFile.close();
  outputFile.close();
  return 0;
}