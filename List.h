#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H
#include <iostream>
struct node{
    int data{};
    node* nextNode=nullptr;
};
class List {
private:
    node* root= nullptr;
    bool sorted=false;
    void destructor(node* pNode);
    void appendValue(int data);
    node* getlocation(int index);
    void mergeSort(int start, int end);
    void merge(int start, int mid, int end);
    int binarySearch(int start, int end, int goal);
public:
    List();
    ~List();
    void addValue(int data);
    void removeValue(int index);
    int getValue(int index);
    void print();
    int sizeOf();
    void sort();
    int search(int goal);
    void swap(int first, int second);
    void modifyValue(int index, int newValue);
    void clear();
};
#endif