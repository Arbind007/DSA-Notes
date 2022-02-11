#include <bits/stdc++.h>
using namespace std;

bool helperCycle(int node,vector <int> adj[],int vis[],int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto &it : adj[node]){
        if(!vis[it]){
            if(helperCycle(it,adj,vis,dfsVis))
                return true;
        }
        else if(dfsVis[it]){
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int K,vector <int> adj[]){
    int vis[K],dfsVis[K];
    memset(vis,0,sizeof vis);
    memset(dfsVis,0,sizeof dfsVis);
    for(int i=0;i<K;i++){
        if(!vis[i]){
            if(helperCycle(i,adj,vis,dfsVis))
                return true;
        }
    }
    return false;
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
    }
    cout << isCycle(V, adj) << endl;
    return 0;
}

// 3 3
// 0 1 
// 1 2
// 2 0