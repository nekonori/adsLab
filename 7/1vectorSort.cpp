#include <bits/stdc++.h>

using namespace std;

void printArr(vector<int> arr){
	for(int x: arr)
		cout<<x<<" ";
	cout<<endl;
}

int main(){
	vector<int> arr({12,31,1,56,78,98});
	printf("Initial array: ");
	printArr(arr);
	sort(arr.begin(), arr.end());
	printf("Sorted array: ");
	printArr(arr);
	sort(arr.begin(), arr.end(), [](const int &a, const int &b){return b < a ? true : false;});
	printf("Sorted array (desc): ");
	printArr(arr);
}
