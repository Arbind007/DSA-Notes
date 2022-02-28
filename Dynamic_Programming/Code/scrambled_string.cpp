#include <bits/stdc++.h>
using namespace std;

bool solve(string a,string b){
    if(a.compare(b) == 0)
        return true;
    if(a.length() <= 1)
        return false;
    int n = a.length();
    bool flag = false;
    for(int i=1;i<=n-1;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i))) && solve(a.substr(i,n-i),b.substr(0,n-i)) || 
          (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))){
            flag = true;
            break;
        }
    }
    return flag;
}

int isScramble(const string A, const string B) {
    if(A.length() != B.length())
        return false;
    return solve(A,B);
}


int main(){
    string a,b;
    a = "great";
    b = "rgeat";
    cout << isScramble(a,b) << endl;
    return 0;
}

// Memorization
#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> mp;

bool solve(string a,string b){
    if(a.compare(b) == 0)
        return true;
    if(a.length() <= 1)
        return false;
    string temp = a;
    temp.push_back(' ');
    temp.append(b);
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    int n = a.length();
    bool flag = false;
    for(int i=1;i<=n-1;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i))) && solve(a.substr(i,n-i),b.substr(0,n-i)) || 
            (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))){
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}

int isScramble(const string A, const string B) {
    if(A.length() != B.length())
        return false;
    return solve(A,B);
}


int main(){
    string a,b;
    a = "qmfcwwzbqkf";
    b = "wfcmbzwqqkf";
    cout << isScramble(a,b) << endl;
    return 0;
}