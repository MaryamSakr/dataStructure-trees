#include <iostream>
using namespace std;

int main() {
    int choose=0;
    while (choose!=5) {
        cout<<"Hello in our application \nyou can choose your desired data structure\n1)BST\n2)AVL\n3)Min Heap\n4)Max Heap\n5)Exit Program\n";
        cin>>choose;
        if(choose==5) {
            break;
        }
        switch (choose) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout<<"please enter a right choice";

        }

    }
}
