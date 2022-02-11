#include <bits/stdc++.h>
using namespace std;

void minDIs(int K,vector <int> adj[],int src){
    vector <int> dist(K);
    for(int i=0;i<K;i++){
        dist[i] = INT_MAX;
    }
    queue <int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &it:adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<K;i++){
        cout << dist[i] << " ";
    }
    return;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++)
    {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    minDIs(V,adj,0);
    return 0;
}

/*
 4 4
 0 1
 0 3
 2 3

    1----2
   /      \
  0--------3 
  
*/
