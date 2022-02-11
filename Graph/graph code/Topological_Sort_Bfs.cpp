#include <bits/stdc++.h>
using namespace std;

vector <int> topoSort(int K,vector <int> adj[]){
    queue <int> q;
    vector <int> indegree(K,0);
    for(int i=0;i<K;i++){
        for(auto &it:adj[i])
            indegree[it]++;
    }
    vector <int> ans;
    for(int i=0;i<K;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it:adj[node]){
            indegree[it]--;
            if(!indegree[it])
                q.push(it);
        }
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