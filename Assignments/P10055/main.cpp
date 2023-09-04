#include <iostream>
#include <cstdlib> 
#include <fstream>
using namespace std;

int main() {
  ifstream fin ("input.txt"); //input file stream
  ofstream fout ("output.txt"); //output file stream
  
  long long a,b; //long long for 2^32
  while (fin >> a>> b) {
    fout << abs(a-b) <<endl; //compute and pring the absolute difference
  }
  return 0;
}