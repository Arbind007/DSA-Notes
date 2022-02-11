#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node n1,node n2){
    return n1.wt < n2.wt;
}

int findPar(int u,vector <int> &parent){
    if(u == parent[u])
        return u;
    return findPar(parent[u],parent);
}

void unionn(int u,int v,vector <int>&parent,vector <int>&rank){
    u = findPar(u,parent);
    v = findPar(v,parent);
    if(rank[u] > rank[v])
        parent[v] = u;
    else if(rank[v] > rank[u])
        parent[u] = v;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(),edges.end(),comp);
	vector <int> parent(N);
	for(int i=0;i<N;i++)
	    parent[i] = i;
	vector <int> rank(N,0);
	int cost = 0;
	vector <pair<int,int>> mst;
	for(auto &it:edges){
	    if(findPar(it.v,parent) != findPar(it.u,parent)){
	        cost += it.wt;
	        mst.push_back({it.v,it.u});
	        unionn(it.u,it.v,parent,rank);
	    }
	}
	cout << cost << endl;
	for(auto &it:mst){
	    cout << it.first << " - " << it.second << endl;
	}
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