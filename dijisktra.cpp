// using vector
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cost;
int n = 0;

void display(vector<int> dist, vector<int> parent)
{
  for (int i = 0; i < n; i++)
  {
    int temp = i;
    cout << "Path to node " << i << ": ";
    while (temp != -1)
    {
      cout << temp;
      temp = parent[temp];
      if (temp != -1)
        cout << " <- ";
    }
    cout << " | Distance: " << dist[i] << endl;
  }
}

int minimumValue(vector<int> dist, vector<bool> visited)
{
  int min = INT_MAX, index = -1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && dist[i] < min)
    {
      min = dist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int src)
{
  vector<int> dist(n, INT_MAX);
  vector<int> parent(n, -1);
  dist[src] = 0;

  vector<bool> visited(n, false);

  for (int i = 0; i < n - 1; i++)
  {
    int u = minimumValue(dist, visited);
    if (u == -1)
      break; // In case no more reachable nodes

    visited[u] = true;

    for (int v = 0; v < n; v++)
    {
      if (!visited[v] && cost[u][v] != 999 && dist[u] + cost[u][v] < dist[v])
      {
        dist[v] = dist[u] + cost[u][v];
        parent[v] = u;
      }
    }
  }

  display(dist, parent);
}

int main()
{
  cout << "Enter the total number of nodes: ";
  cin >> n;
  cost.resize(n, vector<int>(n)); // Initialize cost matrix

  cout << "Enter the cost matrix (use 999 for no direct path):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cost[i][j];
    }
  }

  cout << "Enter the source node: ";
  int src;
  cin >> src;

  dijkstra(src);

  return 0;
}

// Dijkstra's Algorithm in C++
// using arr[100]

/*
#include<bits/stdc++.h>
using namespace std;

int cost[100][100], N;

int getMin(int dist[],bool visited[]){
  int min = INT_MAX,index{};

  for(int i=0; i<N; i++){
    if(!visited[i] && dist[i] < min){
      min = dist[i];
      index = i;
    }
  }
  return index;
}

void display(int par[],int dist[]){
  for(int i=0; i<N; i++){
    int temp = par[i];
    while(temp != -1){
      cout << temp << "<- ";
      temp = par[temp];
    }
    cout << endl;
    cout << "Distance = " << dist[i];
    cout << endl;
  }
}

void dijkstra(int src){
  int dist[100],parent[100];
  bool visited[100] = {0};
  fill(dist,dist+N, INT_MAX);

  dist[src] = 0;
  parent[src] = -1;

  for(int i=0; i<N-1; i++){
    int u = getMin(dist,visited);
    visited[u] = true;
    cout << "min = " << u << endl;
    for(int  v=0; v<N; v++){
      if(!visited[v] && dist[u] + cost[u][v] < dist[v] && cost[u][v] != 999){
        parent[v] = u;
        dist[v] = dist[u] + cost[u][v];
      }
    }
  }
  display(parent,dist);
}

int main(){
  cout << "Enter the number of nodes: ";
  cin >> N;
  cout << "Enter the cost matrix: \n";
  for(int i=0; i<N; i++){
    for(int j=0; j<N; i++){
      cin >> cost[i][j];
    }
  }
  int src;
  cout << "Enter the source node: ";
  cin >> src;
  dijkstra(src);
}

*/

// #include <iostream>
// #include <vector>

// #define INT_MAX 10000000

// using namespace std;

// void DijkstrasTest();

// int main() {
//   DijkstrasTest();
//   return 0;
// }

// class Node;
// class Edge;

// void Dijkstras();
// vector<Node*>* AdjacentRemainingNodes(Node* node);
// Node* ExtractSmallest(vector<Node*>& nodes);
// int Distance(Node* node1, Node* node2);
// bool Contains(vector<Node*>& nodes, Node* node);
// void PrintShortestRouteTo(Node* destination);

// vector<Node*> nodes;
// vector<Edge*> edges;

// class Node {
//    public:
//   Node(char id)
//     : id(id), previous(NULL), distanceFromStart(INT_MAX) {
//     nodes.push_back(this);
//   }

//    public:
//   char id;
//   Node* previous;
//   int distanceFromStart;
// };

// class Edge {
//    public:
//   Edge(Node* node1, Node* node2, int distance)
//     : node1(node1), node2(node2), distance(distance) {
//     edges.push_back(this);
//   }
//   bool Connects(Node* node1, Node* node2) {
//     return (
//       (node1 == this->node1 &&
//        node2 == this->node2) ||
//       (node1 == this->node2 &&
//        node2 == this->node1));
//   }

//    public:
//   Node* node1;
//   Node* node2;
//   int distance;
// };

// ///////////////////
// void DijkstrasTest() {
//   Node* a = new Node('a');
//   Node* b = new Node('b');
//   Node* c = new Node('c');
//   Node* d = new Node('d');
//   Node* e = new Node('e');
//   Node* f = new Node('f');
//   Node* g = new Node('g');

//   Edge* e1 = new Edge(a, c, 1);
//   Edge* e2 = new Edge(a, d, 2);
//   Edge* e3 = new Edge(b, c, 2);
//   Edge* e4 = new Edge(c, d, 1);
//   Edge* e5 = new Edge(b, f, 3);
//   Edge* e6 = new Edge(c, e, 3);
//   Edge* e7 = new Edge(e, f, 2);
//   Edge* e8 = new Edge(d, g, 1);
//   Edge* e9 = new Edge(g, f, 1);

//   a->distanceFromStart = 0;  // set start node
//   Dijkstras();
//   PrintShortestRouteTo(f);
// }

// ///////////////////

// void Dijkstras() {
//   while (nodes.size() > 0) {
//     Node* smallest = ExtractSmallest(nodes);
//     vector<Node*>* adjacentNodes =
//       AdjacentRemainingNodes(smallest);

//     const int size = adjacentNodes->size();
//     for (int i = 0; i < size; ++i) {
//       Node* adjacent = adjacentNodes->at(i);
//       int distance = Distance(smallest, adjacent) +
//                smallest->distanceFromStart;

//       if (distance < adjacent->distanceFromStart) {
//         adjacent->distanceFromStart = distance;
//         adjacent->previous = smallest;
//       }
//     }
//     delete adjacentNodes;
//   }
// }

// // Find the node with the smallest distance,
// // remove it, and return it.
// Node* ExtractSmallest(vector<Node*>& nodes) {
//   int size = nodes.size();
//   if (size == 0) return NULL;
//   int smallestPosition = 0;
//   Node* smallest = nodes.at(0);
//   for (int i = 1; i < size; ++i) {
//     Node* current = nodes.at(i);
//     if (current->distanceFromStart <
//       smallest->distanceFromStart) {
//       smallest = current;
//       smallestPosition = i;
//     }
//   }
//   nodes.erase(nodes.begin() + smallestPosition);
//   return smallest;
// }

// // Return all nodes adjacent to 'node' which are still
// // in the 'nodes' collection.
// vector<Node*>* AdjacentRemainingNodes(Node* node) {
//   vector<Node*>* adjacentNodes = new vector<Node*>();
//   const int size = edges.size();
//   for (int i = 0; i < size; ++i) {
//     Edge* edge = edges.at(i);
//     Node* adjacent = NULL;
//     if (edge->node1 == node) {
//       adjacent = edge->node2;
//     } else if (edge->node2 == node) {
//       adjacent = edge->node1;
//     }
//     if (adjacent && Contains(nodes, adjacent)) {
//       adjacentNodes->push_back(adjacent);
//     }
//   }
//   return adjacentNodes;
// }

// // Return distance between two connected nodes
// int Distance(Node* node1, Node* node2) {
//   const int size = edges.size();
//   for (int i = 0; i < size; ++i) {
//     Edge* edge = edges.at(i);
//     if (edge->Connects(node1, node2)) {
//       return edge->distance;
//     }
//   }
//   return -1;  // should never happen
// }

// // Does the 'nodes' vector contain 'node'
// bool Contains(vector<Node*>& nodes, Node* node) {
//   const int size = nodes.size();
//   for (int i = 0; i < size; ++i) {
//     if (node == nodes.at(i)) {
//       return true;
//     }
//   }
//   return false;
// }

// ///////////////////

// void PrintShortestRouteTo(Node* destination) {
//   Node* previous = destination;
//   cout << "Distance from start: "
//      << destination->distanceFromStart << endl;
//   while (previous) {
//     cout << previous->id << " ";
//     previous = previous->previous;
//   }
//   cout << endl;
// }

// // these two not needed
// vector<Edge*>* AdjacentEdges(vector<Edge*>& Edges, Node* node);
// void RemoveEdge(vector<Edge*>& Edges, Edge* edge);

// vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node) {
//   vector<Edge*>* adjacentEdges = new vector<Edge*>();

//   const int size = edges.size();
//   for (int i = 0; i < size; ++i) {
//     Edge* edge = edges.at(i);
//     if (edge->node1 == node) {
//       cout << "adjacent: " << edge->node2->id << endl;
//       adjacentEdges->push_back(edge);
//     } else if (edge->node2 == node) {
//       cout << "adjacent: " << edge->node1->id << endl;
//       adjacentEdges->push_back(edge);
//     }
//   }
//   return adjacentEdges;
// }

// void RemoveEdge(vector<Edge*>& edges, Edge* edge) {
//   vector<Edge*>::iterator it;
//   for (it = edges.begin(); it < edges.end(); ++it) {
//     if (*it == edge) {
//       edges.erase(it);
//       return;
//     }
//   }
// }
