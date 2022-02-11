#include <bits/stdc++.h>
using namespace std;

bool helper(int node,int parent,vector <int> adj[],vector <int> vis){
    vis[node] = 1;
    for(auto &it : adj[node]){
        if(!vis[it])
            if(helper(it,node,adj,vis))
                return true;
        else if(it != parent)
            return true;
    }
    return false;
}

bool isCycle(int V,vector <int> adj[]){
    vector <int> vis(V+1,0);
    for(int i=1;i<=V;i++)
    if(!vis[i])
       if(helper(i,-1,adj,vis))
           return true;
    return false;
}

int main(){
    
    return 0;
}