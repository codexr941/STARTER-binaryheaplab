// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza
// Xianze Gu: I added a private function siftdown, while helps to arrange the heap by consistently comparing current element with its childs, until it is at correct position.


#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    Heap() {}  // default constructor
    Heap(std::vector<int>::iterator start, std::vector<int>::iterator end); // build a heap from a range using heapify
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element
    int top();
    bool empty();

 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
    void siftDown(int i);
};

#endif
