#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Edge {
    int u, v;
    double weight;
};

bool compareEdge(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findRoot(vector<int>& parent, int i) {
    if (i == parent[i]) return i;
    return parent[i] = findRoot(parent, parent[i]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = findRoot(parent, a);
    b = findRoot(parent, b);
    if (rank[a] < rank[b]) {
        parent[a] = b;
    } else if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int cases;
    inputFile >> cases;

    while (cases--) {
        int n;
        inputFile >> n;

        vector<Point> freckles(n);
        for (int i = 0; i < n; ++i) {
            inputFile >> freckles[i].x >> freckles[i].y;
        }

        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({i, j, distance(freckles[i], freckles[j])});
            }
        }

        sort(edges.begin(), edges.end(), compareEdge);

        double totalLength = 0.0;
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (Edge& e : edges) {
            if (findRoot(parent, e.u) != findRoot(parent, e.v)) {
                totalLength += e.weight;
                unionSets(parent, rank, e.u, e.v);
            }
        }

        outputFile << fixed << setprecision(2) << totalLength << endl;
        if (cases) outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
