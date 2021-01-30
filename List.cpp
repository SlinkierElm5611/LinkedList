#include "List.h"
void List::destructor(node *pNode) {
    if(pNode->nextNode != nullptr){
        destructor(pNode->nextNode);
    }
    delete pNode;
}
List::~List() {
    destructor(root);
}
List::List() {
    root=new node;
}
void List::appendValue(int data){
    node* temp=root;
    while(temp->nextNode!= nullptr){
        temp=temp->nextNode;
    }
    temp->nextNode=new node;
    temp=temp->nextNode;
    temp->data=data;
    sorted=false;
}
void List::addValue(int data) {
    appendValue(data);
}
void List::removeValue(int index) {
    if(index>=1&&index<=sizeOf()) {
        node *temp = root;
        for (int i = 0; i < index; i++) {
            temp = temp->nextNode;
        }
        getlocation(index - 1)->nextNode = temp->nextNode;
        delete temp;
    }else{
        std::cerr<<"Index "<<index<<" is invalid"<<std::endl;    }
}
int List::getValue(int index) {
    node* temp=root;
    for(int i=0; i<index; i++){
        temp=temp->nextNode;
    }
    return temp->data;
}
void List::print() {
    node* temp=root;
    do{
        temp=temp->nextNode;
        std::cout<<temp->data<<std::endl;
    }while(temp->nextNode!= nullptr);
    std::cout<<std::endl;
}
int List::sizeOf() {
    node *temp = root;
    if(root== nullptr){
        return 0;
    }
    int counter = 0;
    while (temp->nextNode != nullptr){
        counter++;
        temp=temp->nextNode;
    }
    return counter;
}
void List::mergeSort(int start, int end) {
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(start, mid);
        mergeSort(mid+1, end);
        merge(start, mid, end);
    }
}
void List::merge(int start, int mid, int end) {
    node* temp=new node;
    node* begin=temp;
    int pos1=start;
    int pos2=mid+1;
    while(!(pos1>mid&&pos2>end)){
        temp->nextNode=new node;
        temp=temp->nextNode;
        if((pos1>mid)||((pos2<=end)&&(getValue(pos2)<getValue(pos1)))){
            temp->data=getValue(pos2);
            pos2++;
        }else{
            temp->data=getValue(pos1);
            pos1++;
        }
    }
    temp=begin->nextNode;
    for(int i=start; i<=end; i++){
        getlocation(i)->data=temp->data;
        temp=temp->nextNode;
    }
    destructor(begin);
}
void List::sort() {
    mergeSort(1, sizeOf());
    sorted=true;
}
void List::swap(int first, int second) {
    node* temp= getlocation(first);
    node* temp1= getlocation(second);
    node* temporary=temp->nextNode;
    temp->nextNode=temp1->nextNode;
    temp1->nextNode=temporary;
    getlocation(first-1)->nextNode=temp1;
    getlocation(second-1)->nextNode=temp;
    sorted=false;
}
node *List::getlocation(int index) {
    node* temp=root;
    for(int i=0; i<index; i++){
        temp=temp->nextNode;
    }
    return temp;
}
int List::search(int goal) {
    if(!sorted){
        std::cout<<"Called Sort"<<std::endl;
        sort();
    }
    return binarySearch(1, sizeOf(), goal);
}
int List::binarySearch(int start, int end, int goal) {
    if(start>end){
        return (-1);
    }else{
        int mid=(start+end)/2;
        if(goal==getValue(mid)) {
            return mid;
        }else if(goal>getValue(mid)){
            return binarySearch(mid+1, end, goal);
        }else{
            return binarySearch(start, mid-1, goal);
        }
    }
}
void List::modifyValue(int index, int newValue) {
    if(index>0&&index<=sizeOf()){
        node* temp=root;
        for(int i=0; i<index; i++){
            temp=temp->nextNode;
        }
        temp->data=newValue;
    }else{
        std::cerr<<"Index "<<index<<" is invalid"<<std::endl;
    }
}
void List::clear() {
    destructor(root->nextNode);
    root->nextNode= nullptr;
}