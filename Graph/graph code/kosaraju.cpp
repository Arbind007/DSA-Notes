#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector <int> &vis,stack <int> &s,vector <int> adj[]){
    vis[node] = 1;
    for(auto &it : adj[node])
        if(!vis[it])
            dfs(it,vis,s,adj);
    s.push(node);
}

void revDfs(int node,vector <int> &vis,vector <int> trans[]){
    cout << node << " ";
    vis[node] = 1;
    for(auto &it : trans[node])
        if(!vis[it])
            revDfs(it,vis,trans);
}

int main(){
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	vector <int> vis(n,0);
	stack <int> s;
	for(int i=0;i<n;i++)
	    if(!vis[i])
	        dfs(i,vis,s,adj);
	vector <int> trans[n];
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        trans[it].push_back(i); 
	    }
	}
	
	while(!s.empty()){
	    int node = s.top();
	    s.pop();
	    if(!vis[node]){
	        cout << "SCC: ";
	        revDfs(node,vis,trans);
	        cout << endl;
	    }
	}
    
    return 0;
}

// 5 5 
// 0 1 
// 1 2 
// 2 0 
// 1 3 
// 3 4 