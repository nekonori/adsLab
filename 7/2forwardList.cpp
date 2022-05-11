#include <bits/stdc++.h>

using namespace std;

vector<int> st;

int main(){
	forward_list<int> first = {10, 20, 30};
	forward_list<int> second = {100, 200};
	printf("Initially: \nfirst list: ");
	for(int x: first) cout<<x<<" ";
	printf("\nsecond list: ");
	for(int x: second) cout<<x<<" ";
	first.swap(second);
	printf("\n\nAfter swap: \nfirst list: ");
	for(int x: first) cout<<x<<" ";
	printf("\nsecond list: ");
	for(int x: second) cout<<x<<" ";
	return 0;
}
