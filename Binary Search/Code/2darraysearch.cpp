#include <bits/stdc++.h>
using namespace std;

int main(){
int n,m,key,i,j;
cin >> n >> m;
vector <vector<int>> v(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> v[i][j];
    }
}

cin >> key;
j=m-1,i=0;
while(i >= 0 && i < n && j >= 0 && j < n){
    if(v[i][j] == key){
        cout << i << " " << j << endl;
        return 0;
    }
    else if(v[i][j] > key){
        j--;
    }
    else{
        i++;
    }
}
cout << - 1 << endl;
return 0;    
}

// 4 4
// 10 20 30 40
// 15 25 35 45
// 27 29 37 48
// 32 33 39 50