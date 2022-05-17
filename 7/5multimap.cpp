#include <bits/stdc++.h>
using namespace std;

int main()
{
	multimap<int, int> gquiz1; 

	gquiz1.insert(pair<int, int>(1, 40));
	gquiz1.insert(pair<int, int>(2, 40));
	gquiz1.insert(pair<int, int>(1, 30));
	
	unordered_multimap<int, int> umm;
	umm.insert(pair<int, int>(1, 30));
	umm.insert(pair<int, int>(2, 40));
	umm.insert(pair<int, int>(1, 40));

	multimap<int, int>::iterator itr;
	cout << "\nSorted multimap: \n";
	cout << "KEY\tELEMENT\n";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		cout << itr->first << '\t' << itr->second
			<< '\n';
	}
	cout << "\nUnsorted multimap: \n";
	cout << "KEY\tELEMENT\n";
	for(auto i=umm.begin();i!=umm.end();i++)
        cout<<i->first<<"\t"<<i->second<<"\n";
	return 0;
}
