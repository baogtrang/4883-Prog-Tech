#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <fstream>
using namespace std;

//  perform BFS and find the maximum capacity path
int bfs(int start, int end, vector<vector<pair<int, int>>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    vector<int> minCapacity(n + 1, 0);
    queue<int> q;

    q.push(start);
    minCapacity[start] = INT_MAX;  // Start with the maximum possible capacity

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited[current] = true;

        if (current == end) break;  // Reached the destination

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int capacity = edge.second;

            // Update if the next node is not visited or a better path is found
            if (!visited[next] && capacity > minCapacity[next]) {
                minCapacity[next] = min(minCapacity[current], capacity);
                q.push(next);
            }
        }
    }

    return minCapacity[end];  // Return the maximum capacity to the destination
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n, r, scenario = 0;

    while (inputFile >> n >> r && n) {
        scenario++;
        vector<vector<pair<int, int>>> graph(n + 1);
        int c1, c2, p;

        for (int i = 0; i < r; i++) {
            inputFile >> c1 >> c2 >> p;
            graph[c1].push_back({c2, p - 1});  // Reduce capacity by 1 for the guide
            graph[c2].push_back({c1, p - 1});
        }

        int start, end, tourists;
        inputFile >> start >> end >> tourists;

        int maxCapacity = bfs(start, end, graph, n);
        int trips = (tourists % maxCapacity == 0) ? tourists / maxCapacity : tourists / maxCapacity + 1;

        outputFile << "Scenario #" << scenario << "\n";
        outputFile << "Minimum Number of Trips = " << trips << "\n\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
