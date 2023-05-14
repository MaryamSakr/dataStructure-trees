#include "BST.h"
#include "max_heap.h"
#include "min_heap.h"
#include "AVL.cpp"

void menu();
void MinHeapMenu();
void MaxHeapMenu();

int main() {
    menu();
    return 0;
}

void menu(){
    cout<<"1. BST\n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:
            break;
        case 2:
            AVL a1();
            break;
        case 3:
            MinHeapMenu();
            break;
        case 4:
            MaxHeapMenu();
            break;
        case 5:
            exit(0);
        default:
            cout<<"Invalid choice\nPlease enter your choice again\n";
            menu();
    }
}

void MinHeapMenu(){
    cout<<"1)Add student\n2)Print All (sorted by gpa)\n3)Return to main menu\n";
    int ch;
    cin>>ch;
    if(ch==1){
        addStudent();
        cout<<"1)If you want to show Min Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MinHeapMenu();
        if(choose==2)
            exit(0);
        if(choose==3){
            menu();
        }
        else{
            cout<<"invalid choice.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==2){
        printMinHeap(students);
        cout<<"1)If you want to show Min Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MinHeapMenu();
        if(choose==2)
            exit(0);
        if(choose==3){
            menu();
        }
        else{
            cout<<"invalid choice.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==3){
        menu();
    }
    else{
        cout<<"invalid choice.\nthe program will close.\n";
        exit(0);
    }
}


void MaxHeapMenu(){
    cout<<"1)Add student\n2)Print All (sorted by gpa)\n3)Return to main menu\n";
    int ch;
    cin>>ch;
    if(ch==1){
        addStudent();
        cout<<"1)If you want to show Max Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MaxHeapMenu();
        if(choose==2)
            exit(0);
        if(choose==3){
            menu();
        }
        else{
            cout<<"invalid choice.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==2){
        printMaxHeap(students);
        cout<<"1)If you want to show Max Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MaxHeapMenu();
        if(choose==2)
            exit(0);
        if(choose==3){
            menu();
        }
        else{
            cout<<"invalid chose.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==3){
        menu();
    }
}