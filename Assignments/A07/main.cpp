#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int N, coach;

    while (inFile >> N, N) {
        while (true) {
            stack<int> station;
            //keeps track of the next coach number pushed into the station
            int current = 1;
            bool possible = true;

            inFile >> coach;
            if (coach == 0) {
                outFile << endl;  // separate cases with a blank line
                break;  // go to next test case
            }

            for (int i = 1; i <= N; ++i) {
                if (i != 1) {
                    inFile >> coach;
                }

                while (current <= N && (station.empty() || station.top() != coach)) {
                    station.push(current);
                    current++;
                }

              //If the required coach is at the top of the station, it's removed
                if (station.top() == coach) {
                    station.pop();
                } else {
                    possible = false;
                }
            }

            if (possible) {
                outFile << "Yes" << endl;
            } else {
                outFile << "No" << endl;
            }
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}
