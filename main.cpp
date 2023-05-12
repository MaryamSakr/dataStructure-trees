#include "BST.h"
#include "min_heap.h"
#include "max_heap.h"
int main() {
//    BST tree;
//    tree.work();
    int choose;
    cout<<"1)MAx Heap\n2)Min Heap\n";
    cin>>choose;
    if(choose ==1){
        MaxHeapMenu();
    }
    if(choose==2){
        MinHeapMenu();
    }
    return 0;
}
