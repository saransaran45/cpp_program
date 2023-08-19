TOPOLOGICAL SORT

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int numVertices;               
    vector<vector<int>> adjacencyList;  

public:
    Graph(int V) {
        numVertices = V;
        adjacencyList.resize(numVertices);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(numVertices, 0);  
        vector<int> result;  
        queue<int> q;  

        
        for (int u = 0; u < numVertices; u++) {
            for (int v : adjacencyList[u]) {
                inDegree[v]++;
            }
        }

        // Enqueue vertices with in-degree 0
        for (int u = 0; u < numVertices; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }

        // Perform BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // Reduce in-degree of adjacent vertices and enqueue if in-degree becomes 0
            for (int v : adjacencyList[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

int main() {
    int numVertices = 6;
    Graph g(numVertices);

    // Add edges to the graph
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Perform topological sort
    vector<int> sortedVertices = g.topologicalSort();

    // Print the sorted vertices
    cout << "Topological Sort: ";
    for (int v : sortedVertices) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

//OUTPUT

Topological Sort: 5 4 2 3 0 1







GRAPH TRAVERSAL (BFS AND DFS)

#include<iostream>
#include<vector>
#include<queue> 
using namespace std;
class graph{
private:
    
    int numVertices;
    vector< vector< int> > adjacencyList;
    
public:
    graph(int num){
        numVertices=num;
        adjacencyList.resize(num);
    }
    void edge(int src, int dest){
        adjacencyList[src].push_back(dest);
    }
    
   void bfs(int startVertex){
        vector<bool> visited (numVertices,false);
        visited[startVertex]=true;
        queue<int> q;
        q.push(startVertex);
        while (!q.empty()){
            int current_vertex=q.front();
            cout<<current_vertex<<" ";
            q.pop();
            
            for(int i=0;i<adjacencyList[current_vertex].size();i++){
                int adjacency_vertex=adjacencyList[current_vertex][i];
                if (!visited[adjacency_vertex]){
                    visited[adjacency_vertex]=true;
                    q.push(adjacency_vertex);
                }
            }
            
        }
    }
    
    void dfs_recur(int current_vertex, vector<bool> &visited){
        cout<<current_vertex<<" ";
        visited[current_vertex]=true;
        for(int i=0;i<adjacencyList[current_vertex].size();i++){
            int adjacent_vertex=adjacencyList[current_vertex][i];
            if(!visited[adjacent_vertex]){
                dfs_recur(adjacent_vertex, visited);
            }
        }
    }
    void dfs(int start_vertex){
        vector<bool> visited (numVertices,false);
        dfs_recur(start_vertex,visited);
    }
};
int main(){
    cout<<"Enter the number of vertices: ";
    int n;
    cin>>n;
    cout<<"Enter the number of edges:  ";
    int e;
    cin>>e;
    graph g(n);
    int s,d;
    for(int i=0;i<e;i++){
        cout<<"Enter the start and dest of the edge: ";
        cin>>s>>d;
        g.edge(s, d);
        
    }
    cout<<"The bfs version of the graph is: \n";
    g.bfs(0);
    cout<<"\n\nThe dfs version of the graph is: \n";
    g.dfs(0);
    cout<<"\n\nThank you:)\n\n";
}
//OUTPUT
Enter the number of vertices: 6
Enter the number of edges:  8
Enter the start and dest of the edge: 0 1
Enter the start and dest of the edge: 0 2
Enter the start and dest of the edge: 1 3
Enter the start and dest of the edge: 2 3
Enter the start and dest of the edge: 2 4
Enter the start and dest of the edge: 3 4
Enter the start and dest of the edge: 3 5
Enter the start and dest of the edge: 4 5
The bfs version of the graph is: 
0 1 2 3 4 5 

The dfs version of the graph is: 
0 1 3 4 5 2 



SHORTEST PATH ALGORITHM

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int source, destination, weight;
};

// Graph class representing a directed, weighted graph
class Graph {
    int numVertices;                     // Number of vertices in the graph
    vector<vector<pair<int, int>>> adjacencyList;  // Adjacency list representation

public:
    Graph(int V) {
        numVertices = V;
        adjacencyList.resize(numVertices);
    }

    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(v, weight));
    }

    // Dijkstra's algorithm for single source shortest path
    vector<int> dijkstra(int source) {
        vector<int> distance(numVertices, numeric_limits<int>::max()); // Distance array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue for minimum distance

        distance[source] = 0; // Distance to source vertex is 0
        pq.push(make_pair(0, source)); // Enqueue the source vertex

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (pair<int, int> neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path is found, update the distance and enqueue the vertex
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        return distance;
    }

    // Bellman-Ford algorithm for single source shortest path with negative weight cycles
    vector<int> bellmanFord(int source) {
        vector<int> distance(numVertices, numeric_limits<int>::max()); // Distance array

        distance[source] = 0; // Distance to source vertex is 0

        // Relax edges V-1 times
        for (int i = 1; i < numVertices - 1; i++) {
            for (int u = 0; u < numVertices; u++) {
                for (pair<int, int> neighbor : adjacencyList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    // If a shorter path is found, update the distance
                    if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < numVertices; u++) {
            for (pair<int, int> neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path is found, it indicates a negative weight cycle
                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return distance;
                }
            }
        }

        return distance;
    }
};

int main() {
    int numVertices = 5;
    Graph g(numVertices);

    // Add edges to the graph
    g.addEdge(0, 1, 6);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 0, 2);
    g.addEdge(4, 2, 5);

    int source = 0;

    // Perform Dijkstra's algorithm
    vector<int> shortestPathsDijkstra = g.dijkstra(source);

    // Print the shortest paths from the source vertex
    cout << "Dijkstra's Algorithm:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Shortest path from " << source << " to " << i << " is " << shortestPathsDijkstra[i] << endl;
    }

    cout << endl;

    // Perform Bellman-Ford algorithm
    vector<int> shortestPathsBellmanFord = g.bellmanFord(source);

    // Print the shortest paths from the source vertex
    cout << "Bellman-Ford Algorithm:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Shortest path from " << source << " to " << i << " is " << shortestPathsBellmanFord[i] << endl;
    }

    return 0;
}


//OP

Dijkstra's Algorithm:
Shortest path from 0 to 0 is 0
Shortest path from 0 to 1 is 3
Shortest path from 0 to 2 is 7
Shortest path from 0 to 3 is 1
Shortest path from 0 to 4 is 3

Bellman-Ford Algorithm:
Shortest path from 0 to 0 is 0
Shortest path from 0 to 1 is 3
Shortest path from 0 to 2 is 7
Shortest path from 0 to 3 is 1
Shortest path from 0 to 4 is 3






























SPANNING TREE 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Graph class representing an undirected, weighted graph
class Graph {
    int numVertices;                     // Number of vertices in the graph
    vector<Edge> edgeList;               // List of edges in the graph

public:
    Graph(int V) {
        numVertices = V;
    }

    void addEdge(int u, int v, int weight) {
        edgeList.push_back({u, v, weight});
    }

    // Kruskal's algorithm for Minimum Spanning Tree
    vector<Edge> kruskalMST() {
        vector<Edge> MST; // Minimum Spanning Tree
        vector<int> parent(numVertices); // Parent array for Union-Find
        vector<int> rank(numVertices, 0); // Rank array for Union-Find

        // Sort the edges based on weight in ascending order
        sort(edgeList.begin(), edgeList.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        // Initialize parent array
        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
        }

        int edgesAdded = 0;
        int edgeIndex = 0;

        while (edgesAdded < numVertices - 1 && edgeIndex < edgeList.size()) {
            Edge currentEdge = edgeList[edgeIndex++];
            int u = currentEdge.source;
            int v = currentEdge.destination;
            int uParent = find(parent, u);
            int vParent = find(parent, v);

            // Check if including the edge creates a cycle
            if (uParent != vParent) {
                MST.push_back(currentEdge);
                edgesAdded++;
                // Perform Union operation
                unionSets(parent, rank, uParent, vParent);
            }
        }

        return MST;
    }

    // Helper function to find the parent of a vertex using path compression
    int find(vector<int>& parent, int vertex) {
        if (parent[vertex] != vertex) {
            parent[vertex] = find(parent, parent[vertex]);
        }
        return parent[vertex];
    }

    // Helper function to perform Union of two sets using rank
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }

    // Prim's algorithm for Minimum Spanning Tree
    vector<Edge> primMST() {
        vector<Edge> MST; // Minimum Spanning Tree
        vector<bool> visited(numVertices, false); // Visited array to track visited vertices
        vector<int> key(numVertices, INT_MAX); // Key values to determine minimum edge weight
        vector<int> parent(numVertices, -1); // Parent array to track the MST

        // Choose the first vertex as the starting vertex
        key[0] = 0;
        parent[0] = 0;

        for (int i = 0; i < numVertices - 1; i++) {
            int minKeyVertex = getMinKeyVertex(key, visited);
            visited[minKeyVertex] = true;

            // Update key values and parent array for adjacent vertices
            for (const Edge& edge : edgeList) {
                if (edge.source == minKeyVertex && !visited[edge.destination] && edge.weight < key[edge.destination]) {
                    key[edge.destination] = edge.weight;
                    parent[edge.destination] = minKeyVertex;
                } else if (edge.destination == minKeyVertex && !visited[edge.source] && edge.weight < key[edge.source]) {
                    key[edge.source] = edge.weight;
                    parent[edge.source] = minKeyVertex;
                }
            }
        }

        // Construct the MST from the parent array
        for (int i = 1; i < numVertices; i++) {
            MST.push_back({parent[i], i, key[i]});
        }

        return MST;
    }

    // Helper function to get the vertex with the minimum key value
    int getMinKeyVertex(const vector<int>& key, const vector<bool>& visited) {
        int minKey = INT_MAX;
        int minKeyVertex = -1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minKeyVertex = v;
            }
        }

        return minKeyVertex;
    }
};

int main() {
    int numVertices = 6;
    Graph g(numVertices);

    // Add edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);

    // Kruskal's algorithm
    vector<Edge> kruskalMST = g.kruskalMST();
    cout << "Kruskal's Algorithm (Minimum Spanning Tree):" << endl;
    for (const Edge& edge : kruskalMST) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
    }

    cout << endl;

    // Prim's algorithm
    vector<Edge> primMST = g.primMST();
    cout << "Prim's Algorithm (Minimum Spanning Tree):" << endl;
    for (const Edge& edge : primMST) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
    }

    return 0;
}

//OUTPUT

Kruskal's Algorithm (Minimum Spanning Tree):
1 -- 2 : 1
0 -- 1 : 2
3 -- 4 : 3
4 -- 5 : 1
0 -- 2 : 3

Prim's Algorithm (Minimum Spanning Tree):
0 -- 1 : 2
0 -- 2 : 3
2 -- 3 : 2
3 -- 4 : 3
4 -- 5 : 1
