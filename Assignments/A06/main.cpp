#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream inFile("input.txt");
  ofstream outFile("output.txt");

  int t; // the number of test cases
  inFile >> t;
  // skip the next 2 blank lines
  inFile.ignore();
  inFile.ignore();

  while (t--) {
    map<string, int> speciesCount;
    string tree;
    int totalTrees = 0;

    while (getline(inFile, tree) && !tree.empty()) {
      speciesCount[tree]++;
      totalTrees++;
    }

    // Convert the map into a vector of pairs for easier sorting
    vector<pair<string, double>> results;
    for (const auto &entry : speciesCount) {
      double percentage =
          (static_cast<double>(entry.second) / totalTrees) * 100.0;
      results.push_back({entry.first, percentage});
    }

    // Sort the results based on the tree name
    sort(results.begin(), results.end(),
         [](const pair<string, double> &a, const pair<string, double> &b) {
           return a.first < b.first;
         });

    for (const auto &result : results) {
      outFile << result.first << " " << fixed << setprecision(4)
              << result.second << endl;
    }

    if (t > 0)
      outFile << endl; // Only print a newline between test cases, not after the
                       // last one
  }

  inFile.close();
  outFile.close();

  return 0;
}
