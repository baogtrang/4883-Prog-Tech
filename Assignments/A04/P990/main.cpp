#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Treasure {
    int depth, gold;
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int t, w, n;
    while (inputFile >> t >> w >> n) {
        vector<Treasure> treasures(n);
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        vector<vector<bool>> taken(n + 1, vector<bool>(t + 1, false));

        for (int i = 0; i < n; i++) {
            inputFile >> treasures[i].depth >> treasures[i].gold;
        }

        // 0/1 Knapsack DP
        for (int i = 1; i <= n; i++) {
            int timeCost = 3 * w * treasures[i - 1].depth;
            for (int j = 0; j <= t; j++) {
                if (timeCost <= j) {
                    if (dp[i - 1][j - timeCost] + treasures[i - 1].gold > dp[i - 1][j]) {
                        dp[i][j] = dp[i - 1][j - timeCost] + treasures[i - 1].gold;
                        taken[i][j] = true;
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Backtracking to find the solution path
        vector<Treasure> solution;
        for (int i = n, j = t; i > 0; i--) {
            if (taken[i][j]) {
                solution.push_back(treasures[i - 1]);
                j -= 3 * w * treasures[i - 1].depth;
            }
        }

        // Output
        outputFile << dp[n][t] << endl << solution.size() << endl;
        for (auto it = solution.rbegin(); it != solution.rend(); ++it) {
            outputFile << it->depth << " " << it->gold << endl;
        }

        if (!inputFile.eof()) {
            outputFile << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
