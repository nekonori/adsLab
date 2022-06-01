#include <bits/stdc++.h>

using namespace std;

template <typename T>
void ph(vector<T> &heap){
    for(T x: heap)
        cout<<x<<" ";
    cout<<endl;
}

template <typename T>
void heapify(vector<T> &heap, int i){
    int sz = heap.size(), largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if(l<sz&&heap[l]>heap[largest])
        largest = l;
    if(r<sz&&heap[r]>heap[largest])
        largest = r;
    if(largest!=i){
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

template <typename T>
void ih(vector<T> &heap, T n){
    int sz = heap.size();
    heap.push_back(n);
    if(sz>0)
        for(int i=(sz+1)/2-1;i>=0;i--)
            heapify(heap, i);
}

template <typename T>
void dn(vector<T> &hT, T num)
{
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
        break;
  }
  swap(hT[i], hT[size - 1]);
  hT.pop_back();
  for (int i = (size-1) / 2 - 1; i >= 0; i--)
    heapify(hT, i);
}

int main(){
    vector<int> heap;
    ih(heap, 12); printf("Initial heap: "); ph(heap);
    ih(heap, 90); printf("+ 90: "); ph(heap);
    ih(heap, 89); printf("+ 89: "); ph(heap);
    ih(heap, 2); printf("+ 2: "); ph(heap);
    ih(heap, 54); printf("+ 54: "); ph(heap);
    dn(heap, 90); printf("- 90: "); ph(heap);
    dn(heap, 89); printf("- 89: "); ph(heap);
    dn(heap, 12); printf("- 12: "); ph(heap);
    dn(heap, 2); printf("- 2: "); ph(heap);
    dn(heap, 54); printf("- 54: "); ph(heap);
    return 0;
}
