#include <bits/stdc++.h>
using namespace std;

vector<int> bfsg(int K,vector <int> adj[]){
    vector <int> bfs;
    vector <int> vis(K+1,0);
    for(int i=1;i<=K;i++){
        if(!vis[i]){
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto &i:adj[node]){
                if(!vis[i]){
                q.push(i);
                vis[i] = 1;
                }
            }
        }
        }
    }
    return bfs;
}

int main(){
    
return 0;    
}