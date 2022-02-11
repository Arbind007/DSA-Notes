#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node,int vis[],stack <int>&s, vector <pair<int,int>> adj[]){
    vis[node] = 1;
    for(auto &it:adj[node])
        if(!vis[it.first])
            findTopoSort(it.first,vis,s,adj);
    s.push(node);
}

void mindis(int src,int N,vector<pair<int,int>> adj[]){
    int vis[N] = {0};
    stack <int> s;
    for(int i=0;i<N;i++){
        if(!vis[i])
            findTopoSort(i,vis,s,adj);       
    }
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i] = 1e9;
    }
    dist[src] = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(dist[node] != 1e9){
            for(auto &it:adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist[i] == 1e9){
            cout << "INF ";
        }
        else{
            cout << dist[i] << " ";
        }
    }
}

int main(){  
    return 0;
}