#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Representation of a road connection (Edge)
struct Edge {
    int to;
    int weight;
    string type; 
};

const int INF = 1e9;

void solve() {
    int mode;
    cin >> mode;

    int n = 4; 
    vector<vector<Edge>> adj(n);

    // Defining the Road Network weights (travel time in mins)
    adj[0].push_back({1, 12, "Ground"});   
    adj[1].push_back({2, 10, "Ground"});   
    adj[2].push_back({3, 5, "Ground"});    
    adj[0].push_back({3, 18, "Flyover"});  

    // Dynamic AI Penalties & Traffic Logic
    for (int i = 0; i < n; i++) {
        for (auto &edge : adj[i]) {
            if (mode == 0 && edge.type == "Ground") edge.weight *= 3; // Express: Penalize Ground
            if (mode == 1 && edge.type == "Flyover") edge.weight *= 3; // Service: Penalize Flyover
            if (mode == 2 && edge.type == "Flyover") edge.weight = INF; // Surge: FORCE ground route
            if (mode == 3 && edge.type == "Ground") edge.weight = INF;  // 🚧 Broken Road: Ground blocked, FORCE Flyover
        }
    }

    // Dijkstra's Algorithm implementation
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0; 
    int target = 3; 

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                parent[edge.to] = u;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    // Data Bridge: Write to route_result.txt
    ofstream outFile("route_result.txt");
    if (dist[target] == INF) {
        outFile << "No Route Found" << endl;
    } else {
        outFile << dist[target] << endl; 
        
        if (mode == 0) outFile << "Express Strategy (Flyover Focus)" << endl;
        else if (mode == 1) outFile << "Service Strategy (Ground Focus)" << endl;
        else if (mode == 2) outFile << "Station Surge Reroute (Via Nangi)" << endl;
        else if (mode == 3) outFile << "Emergency Detour (Broken Road Avoidance)" << endl; // NEW MODE
        
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); i++) {
            outFile << path[i] << (i == path.size() - 1 ? "" : ",");
        }
    }
    outFile.close();
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        int m = stoi(argv[1]);
        streambuf* orig = cin.rdbuf();
        string s = to_string(m);
        istringstream iss(s);
        cin.rdbuf(iss.rdbuf());
        solve();
        cin.rdbuf(orig);
    } else {
        solve();
    }
    return 0;
}
