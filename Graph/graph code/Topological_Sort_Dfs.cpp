#include <bits/stdc++.h>
using namespace std;

void helperTopoSort(int node,stack <int> &s,vector <int> &vis,vector <int> adj[]){
    vis[node] = 1;
    for(auto &it:adj[node]){
        if(!vis[it])
            helperTopoSort(it,s,vis,adj);
    }
    s.push(node);
}

vector <int> topoSort(int K,vector <int> adj[]){
    vector <int> vis(K);
    stack <int> s;
    for(int i=0;i<K;i++){
        if(!vis[i])
            helperTopoSort(i,s,vis,adj);
    }
    vector <int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
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
    vector <int> ans = topoSort(V,adj);
    cout << endl;
    for(auto &it:ans)
        cout << it << " ";
    cout << endl;
    return 0;
}

// 6 6
// 2 3
// 3 1
// 4 0
// 4 1
// 5 0
// 5 2