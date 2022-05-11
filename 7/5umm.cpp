#include <bits/stdc++.h>

using namespace std;

void printUmm(unordered_multimap<string, int> &umm){
    for(auto i=umm.begin();i!=umm.end();i++)
        cout<<i->first<<": "<<i->second<<"\n";
}

int main(){
    unordered_multimap<string, int> umm;
    umm.insert({"apple", 1});
    umm.insert({"orange", 2});
    umm.insert({"orange", 5});
    umm.insert({"banana", 6});
    printf("unordered multimap content:\n");
    printUmm(umm);
    cout<<"Size of unordered multimap is "<<umm.size();
    cout<<"\nValues associated with orange in unordered multimap is "<<umm.count("orange");
    umm.erase("orange");
    cout<<"\nSize after deleting orange: "<<umm.size();
}
