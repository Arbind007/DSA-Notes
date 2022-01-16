#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int minele;

void push(int n){
    if(s.size() == 0)
        minele = n,s.push(minele);
    else{
        if(n >= minele)
            s.push(n);
        else
            s.push(2 * n - minele),minele = n;
    }
}

void pop(){
    if(s.size() == 0)
        return;
    if(s.top() >= minele)
        s.pop();
    else
        minele = 2 * minele - s.top(),s.pop();
}

int mine(){
    if(s.size() == 0)
        return -1;
    return minele;
}

int top(){
    if(s.size() == 0){
        return -1;
    } 
    if(s.top() >= minele)
        return s.top();
    return minele;
}

int main(){
    push(5);
    cout << top() << endl; //5
    push(7);
    push(3);
    cout << top() << endl; //3
    cout << mine() << endl; //3
    push(2);
    cout << mine() << endl; //2
    pop();
    pop();
    cout << top() << endl; //7
    cout << mine() << endl; //5
    return 0;
}

