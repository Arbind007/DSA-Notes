#include <bits/stdc++.h>
using namespace std;

bool findCycle(int K,vector <int> adj[]){
    vector <int> indegree(K,0);
    queue <int> q;
    for(int i=0;i<K;i++){
        for(auto &it:adj[i]){
            indegree[it]++;
        }
    }
    
    for(int i=0;i<K;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto &it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    if(cnt == K)
        return false;
    return true;
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
    cout << findCycle(V,adj);
    return 0;
}

// 3 3
// 0 1
// 1 2
// 2 0

// 3 2
// 0 1
// 1 2