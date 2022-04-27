#include <bits/stdc++.h>
#define deb(x) cout<<#x<<"="<<x<<" ";
using namespace std;

template <typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

template <typename T> T myMin(T x, T y)
{
	return (x > y) ? y : x;
}

template <typename T> void bubbleSort(vector<T> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

void printArray(vector<int> arr){
    for(auto x: arr)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
	int a = 10, b = 20;
    float c = 1.2, d = 3.4;
    deb(a); deb(b); deb(c); deb(d);
    cout<<"\nMax of a & b is "<<myMax(a, b)<<"\n";
    cout<<"Min of c & d is "<<myMin(c, d)<<endl;
    vector<int> arr({10, 50, 30, 40, 20});
    cout<<"Initial array: "; printArray(arr);
    bubbleSort(arr);
    cout<<"Array after sorting: ";printArray(arr);
	return 0;
}
