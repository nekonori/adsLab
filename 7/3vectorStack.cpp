#include <bits/stdc++.h>

using namespace std;

vector<int> st;

int main(){
	int c;
	while(true){
		printf("0 for help>>"); cin>>c;
		if(c==0){
			printf("1 -> push\n2 -> pop\n3 -> top\n-1 -> exit\n");
		} else if(c==1){
			int n;
			printf("Enter num: "); cin >>n;
			st.push_back(n);
		} else if(c==2||c==3){
			if(st.size()==0) printf("Stack is empty\n");
			else {
				cout<<st.back()<<endl;
				if(c==2) st.pop_back();			
			}
		} else if(c==-1) break;
	}
	return 0;
}
