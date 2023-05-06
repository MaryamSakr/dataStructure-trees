#include <iostream>
using namespace std;
void display_menu() {
    int choose=0;
    while (choose!=5) {
        cout<<"welcome in our program \nchoose your desired data structure:\n1)BST\n2) AVL\n3) Min Heap\n4) Max Heap\n5) Exit Program\n";
        cin>>choose;
        if(choose==5) {
            cout<<"we are happy to see you :)";
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
                cout<<"please enter a right choice\n";

        }
    }
}


int main() {
    display_menu();
    return 0;
}
