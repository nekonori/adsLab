#include <bits/stdc++.h>

using namespace std;

void printQ(queue<string> &q){
    int sz = q.size();
    for(int i=0;i<sz;i++){
        string temp = q.front(); q.pop();
        cout<<temp<<" ";
        q.push(temp);
    }
    cout<<endl;
}

int main(){
    queue<string> q({"milk", "sugar", "coffee", "water"});
    printf("Initial queue: "); printQ(q);
    int sz = q.size();
    for(int i=0;i<sz;i++){
        string temp = q.front(); q.pop();
        if(temp=="coffee") q.push("tea");
        else q.push(temp);
    }
    printf("Modified queue: "); printQ(q);
	return 0;
}
