#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 
	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	int parent[N],key[N],mSet[N];
	for(int i=0;i<N;i++)
	    key[i] = INT_MAX,mSet[i] = false;
	    
	key[0] = 0, parent[0] = -1;
	priority_queue <pair<int,int> , vector <pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	while(!pq.empty()){
	    int u = pq.top().second;
	    pq.pop();
	    mSet[u] = true;
	    for(auto &it:adj[u]){
	        int v = it.first;
	        int weight = it.second;
	        if(!mSet[v] && weight<key[v]){
	            parent[v] = u;
	            pq.push({key[v],v});
	            key[v] = weight;
	        }
	    }
	}
	for(int i=1;i<N;i++)
	    cout << i << " - " << parent[i] << endl; 
	return 0;
}

// 6 7 
// 0 1 5 
// 0 2 10 
// 0 3 100 
// 1 3 50 
// 1 4 200
// 3 4 250
// 4 5 50 