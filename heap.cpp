// heap.cpp
// Diba Mirza
// Xianze Gu: I learned how to construct a heap using heapify way, and its time complexcity is O(n).

#include "heap.h"
#include <iostream>
#include <algorithm>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
vdata.assign(start, end);
n = vdata.size();
for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(i);
    }
}

void Heap::siftDown(int i){
   int left=2i+1;
 int right=2i+2;
 int smallest=i;
  while(true){
 if (left < n && vdata[left] < vdata[smallest])
        smallest = left;
 if (right < n && vdata[right] < vdata[smallest])
        smallest = right;
 if (smallest != i) {
        std::swap(vdata[i], vdata[smallest]);
        i = smallest;
 }
  else {
        break;
    }
}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
        vdata.push_back(value);
        if(vdata.size()==1)
                return;
        int curr=vdata.size()-1;
        int parent=(curr-1)/2;
        while(curr > 0 && vdata[curr]<vdata[parent]){
                std::swap(vdata[curr],vdata[parent]);
                curr=parent;
                parent=(curr-1)/2;
        }
                
        
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
n = vdata.size();
if (n == 0) {
  throw std::runtime_error("Heap is empty");
    }
int top=vdata[0];
vdata[0]=vdata[n-1]；
vdata.pop_back();
if(vdata.size()>0){
  siftdown(0);
return top;
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
   return vdata.empty();
}
    
