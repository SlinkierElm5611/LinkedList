#include "List.h"
int main() {
    List* linkedList=new List;
    for(int i=0; i<10000; i++){
        linkedList->addValue(rand());
    }
    linkedList->print();
    linkedList->sort();
    linkedList->print();
    delete linkedList;
}