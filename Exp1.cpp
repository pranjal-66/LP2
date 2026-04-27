/*
name: Pranjal karande
rollno : 35
exp1: Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected graph and develop a recursive algorithm for searching all the vertices of a graph or tree data structure 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, adj, visited);
        }
    }
}
void BFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // Undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<bool> visited(n, false);
    int choice;
    do{
    cout << "Choose traversal method: ";
    cout << "\n1. DFS ";
    cout << "\n2. BFS ";
    cout << "\n3. Exit ";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            visited.assign(n, false); // Reset visited
            cout << "DFS traversal: ";
            DFS(0, adj, visited);
            cout << endl;
            break;

        case 2:
            visited.assign(n, false); // Reset visited
            cout << "BFS traversal: ";
            BFS(0, adj, visited);
            cout << endl;
            break;   

        default:
            cout << "Invalid choice!" << endl;
    }
    }while(choice != 3);
    return 0;
}

