#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector <int> &vis,vector <int> adj[],vector <int> &ans){
    ans.push_back(node);
    vis[node] = 1;
    for(auto &i:adj[node])
        if(!vis[node])
            dfs(i,vis,adj,ans);
}

vector<int> dfsg(int K,vector <int> adj[]){
    vector <int> ans;
    vector <int> vis(K+1); 
    for(int i=1;i<=K;i++){
        if(!vis[i])
            dfs(i,vis,adj,ans);
    }
    return ans;
}

int main(){
    
return 0;    
}