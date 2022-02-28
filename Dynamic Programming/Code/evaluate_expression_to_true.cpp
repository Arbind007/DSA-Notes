#include <bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,bool isTrue){
    if(i > j)
        return false;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int sum = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lT = solve(s,i,k-1,true);
        int lF = solve(s,i,k-1,false);
        int rT = solve(s,k+1,j,true);
        int rF = solve(s,k+1,j,false);
        if(s[k] == '^'){
            if(isTrue)
                sum += lT * rF + lF * rT;
            else
                sum += lT * rT + lF * rF;
        }
        else if(s[k] == '|'){
            if(isTrue)
                sum += lT * rT + lT * rF + lF * rT; 
            else
                sum += lF * rF;
        }
        else if(s[k] == '&'){
            if(isTrue)
                sum += lT * rT;
            else
                sum += lF * rT + lT * rF + lF * rF;
        }
    }
    return sum;
}

int main(){
    string s = "T|T&F^T";
    cout << solve(s,0,s.length()-1,true);
    return 0;
}

//memorization using maps
#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> mp;

int solve(string s,int i,int j,bool isTrue){
    if(i > j)
        return false;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp) != mp.end())
        return mp[temp];
    int sum = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lT = solve(s,i,k-1,true);
        int lF = solve(s,i,k-1,false);
        int rT = solve(s,k+1,j,true);
        int rF = solve(s,k+1,j,false);
        if(s[k] == '^'){
            if(isTrue)
                sum += lT * rF + lF * rT;
            else
                sum += lT * rT + lF * rF;
        }
        else if(s[k] == '|'){
            if(isTrue)
                sum += lT * rT + lT * rF + lF * rT; 
            else
                sum += lF * rF;
        }
        else if(s[k] == '&'){
            if(isTrue)
                sum += lT * rT;
            else
                sum += lF * rT + lT * rF + lF * rF;
        }
    }
    return mp[temp] = sum;
}

//memorization using 3d Matrix`time
int main(){
    string s = "T|T&F^T";
    cout << solve(s,0,s.length()-1,true);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001][2];

int solve(string s,int i,int j,bool isTrue){
    if(i > j)
        return false;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int sum = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lT = solve(s,i,k-1,true);
        int lF = solve(s,i,k-1,false);
        int rT = solve(s,k+1,j,true);
        int rF = solve(s,k+1,j,false);
        if(s[k] == '^'){
            if(isTrue)
                sum += lT * rF + lF * rT;
            else
                sum += lT * rT + lF * rF;
        }
        else if(s[k] == '|'){
            if(isTrue)
                sum += lT * rT + lT * rF + lF * rT; 
            else
                sum += lF * rF;
        }
        else if(s[k] == '&'){
            if(isTrue)
                sum += lT * rT;
            else
                sum += lF * rT + lT * rF + lF * rF;
        }
    }
    return dp[i][j][isTrue] = sum;
}

int main(){
    string s = "T|T&F^T";
    memset(dp,-1,sizeof dp);
    cout << solve(s,0,s.length()-1,true);
    return 0;
}