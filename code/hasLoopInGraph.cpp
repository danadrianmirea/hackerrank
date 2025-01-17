#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // Maximum number of nodes in the graph

bool dfs(int node, const vector<vector<int>>& adjMatrix, vector<bool>& visited, int parent) {
    visited[node] = true;

    for (int i = 0; i < adjMatrix[node].size(); i++) {
        if (adjMatrix[node][i] == 1) { // Check if there's an edge
            if (!visited[i]) {
                // Recur for the adjacent node
                if (dfs(i, adjMatrix, visited, node))
                    return true;
            }
            else if (i != parent) {
                // If the adjacent node is visited and not the parent, there's a cycle
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adjMatrix, visited, -1))
                return true;
        }
    }
    return false;
}

int TestGraphLoop() {
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    if (hasCycle(adjMatrix)) {
        cout << "The graph contains a cycle.\n";
    }
    else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
