#include <bits/stdc++.h>
using namespace std;

stack <int> s,ss;

void push(int n){
    s.push(n);
    if(ss.empty() || ss.top() >= n)
        ss.push(n);
}
int pop(){
    if(s.size() == 0)
        return -1;
    int temp = s.top();
    s.pop();
    if(temp == ss.top())
        ss.pop();
    return temp;
}
int mine(){
    if(ss.size() == 0)
        return -1;
    return ss.top();
}

int main(){
    push(18);
    push(19);
    push(29);
    cout << mine() << " "; //18
    push(15);
    cout << mine() << " "; //15
    cout << pop() << " "; //15
    cout << mine() << " "; //18
    push(16);
    cout << mine() << " "; //16 
    cout << pop() << " "; //16
    cout << mine() << " "; //18
    return 0;
}

// 6
// 3 0 0 2 0 4