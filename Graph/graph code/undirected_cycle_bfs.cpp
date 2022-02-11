#include <bits/stdc++.h>
using namespace std;

bool helper(int node,vector <int> adj[],vector <int> &vis){
    vis[node] = 1;
    queue <pair<int,int>> q;
    q.push({node,-1});
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto &it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,node});
            }
            else if(it != par)
                return true;
        }
    }
    return false;
}

bool isCycle(int K,vector <int> adj[]){
    vector <int> vis(K+1); 
    for(int i=1;i<=K;i++){
        if(!vis[i])
            if(helper(i,adj,vis))
                return true;
    }
    return false;
}

int main(){
    
return 0;    
}