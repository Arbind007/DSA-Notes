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
	for(int i=0;i<N-1;i++){
	    int mini = INT_MAX,u;
	    for(int j=0;j<N;j++)
	         if(!mSet[j] && key[j] < mini)
	            mini = key[j],u = j;
	    mSet[u] = true;
	    for(auto &it:adj[u]){
	        int v = it.first;
	        int weight = it.second;
	        if(!mSet[v] && weight<key[v])
	            parent[v] = u, key[v] = weight;
	    }
	}
	for(int i=1;i<N;i++)
	    cout << i << " - " << parent[i] << endl; 
	return 0;
}