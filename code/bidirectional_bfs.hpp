#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

// Function to reconstruct the path from source to target
vector<int> reconstructPath(int intersection,
                            unordered_map<int, int> &parent_source,
                            unordered_map<int, int> &parent_target) {
  vector<int> path;

  // Path from source to intersection
  int node = intersection;
  while (node != -1) {
    path.push_back(node);
    node = parent_source[node];
  }
  reverse(path.begin(), path.end()); // Reverse to get correct order

  // Path from intersection to target
  node = parent_target[intersection];
  while (node != -1) {
    path.push_back(node);
    node = parent_target[node];
  }

  return path;
}

// Bidirectional BFS implementation
vector<int> bidirectionalBFS(unordered_map<int, list<int>> &graph, int source,
                             int target) {
  if (source == target) {
    return {source};
  }

  // Queues for BFS
  queue<int> queue_source, queue_target;

  // Parent maps to track paths
  unordered_map<int, int> parent_source, parent_target;

  // Visited sets
  unordered_set<int> visited_source, visited_target;

  // Initialize BFS from both sides
  queue_source.push(source);
  parent_source[source] = -1;
  visited_source.insert(source);

  queue_target.push(target);
  parent_target[target] = -1;
  visited_target.insert(target);

  while (!queue_source.empty() && !queue_target.empty()) {
    // Expand BFS from the source side
    int current_source = queue_source.front();
    queue_source.pop();

    for (int neighbor : graph[current_source]) {
      if (visited_source.find(neighbor) == visited_source.end()) {
        visited_source.insert(neighbor);
        parent_source[neighbor] = current_source;
        queue_source.push(neighbor);

        // Check for intersection with the other BFS
        if (visited_target.find(neighbor) != visited_target.end()) {
          return reconstructPath(neighbor, parent_source, parent_target);
        }
      }
    }

    // Expand BFS from the target side
    int current_target = queue_target.front();
    queue_target.pop();

    for (int neighbor : graph[current_target]) {
      if (visited_target.find(neighbor) == visited_target.end()) {
        visited_target.insert(neighbor);
        parent_target[neighbor] = current_target;
        queue_target.push(neighbor);

        // Check for intersection with the other BFS
        if (visited_source.find(neighbor) != visited_source.end()) {
          return reconstructPath(neighbor, parent_source, parent_target);
        }
      }
    }
  }

  return {}; // Return empty path if no path exists
}

int TestBidirectionalBFS() 
{
  // Example graph as an adjacency list
  unordered_map<int, list<int>> graph;

  // Add edges (undirected graph)
  graph[0] = {1, 3};
  graph[1] = {0, 2, 4};
  graph[2] = {1, 5};
  graph[3] = {0, 4};
  graph[4] = {1, 3, 5};
  graph[5] = {2, 4};

  int source = 0;
  int target = 5;

  // Perform Bidirectional BFS
  vector<int> path = bidirectionalBFS(graph, source, target);

  // Output the shortest path
  if (!path.empty()) {
    cout << "Shortest path: ";
    for (int node : path) {
      cout << node << " ";
    }
    cout << endl;
  } else {
    cout << "No path exists between " << source << " and " << target << endl;
  }

  return 0;
}
