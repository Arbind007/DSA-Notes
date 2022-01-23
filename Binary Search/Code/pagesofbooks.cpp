#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector <int> &v,int n,int k,int stu){
    int student = 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(sum > k){
            student++;
            sum = v[i];
        }
        if(student > stu){
            return false;
        }
    }
    return true;
}

int maxpage(vector <int> &v,int start,int end,int stu){
    int ans = -1,mid;
    while(start<=end){
        mid = start + (end - start)/2;
        if(isvalid(v,v.size(),mid,stu)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n,maxele=INT_MIN,sum=0,stu;
    vector <int> v(n);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
        maxele = max(maxele,v[i]);
        sum += v[i];
    }
    cin >> stu;
    if(stu > n){
        cout << -1 << endl;
        return 0;
    }
    // cout << maxele << " " << sum;
    cout << maxpage(v,maxele,sum,stu) << endl;
    
    return 0;
}





// 4
// 10 20 30 40 
// 2