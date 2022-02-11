#include<bits/stdc++.h>
using namespace std;

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }
    int src;
    cin >> src;
    vector<int> dist(N, 1e6); 
    dist[src] = 0;
    for(int i=0;i<N-1;i++)
        for(auto &it: edges)
            if(dist[it.u] + it.wt < dist[it.v])
                dist[it.v] = dist[it.u] + it.wt;
    bool flag = 1;
    for(auto &it:edges)
        if(dist[it.u] + it.wt < dist[it.v]){
            flag = 0;
            cout << "Negative Cycle" << endl;
            break;
        }
    
    if(flag){
        for(int i=0;i<N;i++){
            cout << i << " - " << dist[i] << endl;
        }
    }
    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/