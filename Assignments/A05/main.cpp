#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

//
bool isGreen(int t, int cycle) {
  int mod = t % (2 * cycle);
  return mod < cycle - 5; // Check if signal is green (considering the last 5
                          // seconds as orange).
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  if (!fin || !fout) {
    cerr << "Error opening files!" << endl;
    return 1;
  }

  vector<int> cycles;

  int val;
  while (true) {
    fin >> val;
    if (val == 0) {         // End of a scenario
      if (cycles.empty()) { // End of all scenarios
        break;
      }

      int end =
          2 * *max_element(cycles.begin(), cycles.end()); // maximum cycle time
      bool found = false;

      for (int t = end; t <= 5 * 3600; t++) {
        bool allGreen = true;
        for (int cycle : cycles) {
          if (!isGreen(t, cycle)) {
            allGreen = false;
            break;
          }
        }

        if (allGreen) {
          found = true;
          fout << setfill('0') << setw(2) << t / 3600 << ":" << setfill('0')
               << setw(2) << (t / 60) % 60 << ":" << setfill('0') << setw(2)
               << t % 60 << "\n";
          break;
        }
      }

      if (!found) {
        fout << "Signals fail to synchronise in 5 hours" << endl;
      }

      cycles.clear(); // Clear for the next scenario.
    } else {
      cycles.push_back(val);
    }
  }

  fin.close();
  fout.close();

  return 0;
}
