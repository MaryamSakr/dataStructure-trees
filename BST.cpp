//
// Created by More on 06/05/2023.
//

#include "BST.h"

void BST::insert_node(string name,string depart,float GPA, int id) {
    Node* new_node = new Node(name,depart,GPA,id);
    if (root == NULL) {
        root = new_node;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        Node* current = root;
        bool  is_added = false;
        while (!is_added)
        {
            if (id > current->id)
            {
                if (current->right == NULL)
                {
                    current->right = new_node;
                    is_added = true;
                }
                else
                    current = current->right;
            }
            else
            {
                if (current->left == NULL)
                {
                    current->left = new_node;
                    is_added = true;
                }
                else
                    current = current->left;
            }
        }
    }
    cout << "The student is added.\n";
    cout << "-------------------------------\n";
    length++;
    if (sheet.count(depart))
        sheet[depart]++;
    else
        sheet[depart] = 1;
}

void BST::search(int id) {
    Node* current = root;
    while (current != NULL)
    {
        if (id > current->id)
        {
            current = current->right;
        }
        else if (id < current->id)
        {
            current = current->left;
        }
        else
        {
            cout << "Student is found.\n";
            cout <<'[' << current->id << ", " << current->name << ", " ;
            cout << current->GPA << ", " << current->depart << "]\n";
            return;
        }
    }
    cout << "Student is not found.\n";
    cout << "-------------------------------\n";
}


void BST::deleteNode() {
    Node* curr = root;
    Node* parent = nullptr;
    int val; cout <<"id:"; cin >> val;
    search(val);
    // Find the node to be deleted and its parent
    while (curr != nullptr && curr->id != val) {
        parent = curr;
        if (val < curr->id) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // If the node wasn't found, return
    if (curr == nullptr) {
        return;
    }

    sheet[curr->depart]--;

    // The node has no children
    if (curr->left == nullptr && curr->right == nullptr) {
        if (curr == root) {
            root = nullptr;
        } else if (curr == parent->left) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete curr;
    }

        // The node has one child
    else if (curr->left == nullptr) {
        if (curr == root) {
            root = curr->right;
        } else if (curr == parent->left) {
            parent->left = curr->right;
        } else {
            parent->right = curr->right;
        }
        delete curr;
    }
    else if (curr->right == nullptr) {
        if (curr == root) {
            root = curr->left;
        } else if (curr == parent->left) {
            parent->left = curr->left;
        } else {
            parent->right = curr->left;
        }
        delete curr;
    }

        // The node has two children
    else {
        Node* successor = curr->right;
        parent = curr;
        while (successor->left != nullptr) {
            parent = successor;
            successor = successor->left;
        }
        curr->id = successor->id;
        curr->name = successor->name;
        curr->GPA = successor->GPA;
        curr->depart = successor->depart;
        if (parent->left == successor) {
            parent->left = successor->right;
        } else {
            parent->right = successor->right;
        }
        delete successor;
    }
    cout << "Student is deleted.\n";
    cout << "-------------------------------\n";
    length--;

}

void BST::print() {
    cout << "print: " << length << " students\n";
    help_print(root);
    cout << "Students per Departments: \n";
    for(auto it : sheet)
    {
        cout << it.first << " " << it.second << " students" << endl;
    }
}

void BST::help_print(Node *current) {
    if (current != nullptr) {
        help_print(current->left);
        cout <<'[' << current->id << ", " << current->name << ", " ;
        cout << current->GPA << ", " << current->depart << "]\n";
        help_print(current->right);
    }
}

void BST::work() {
    read_file();
    cout << "Choose one of the following options:\n";
    cout << "\t1. Add student \n";
    cout << "\t2. Remove student\n";
    cout << "\t3. Search student\n";
    cout << "\t4. Print All (sorted by id)\n";
    cout << "\t5. Return to main menu\n";
    bool stop = false;
    while (!stop)
    {
        int choose; cout << "Enter number of option:"; cin >> choose;
        switch (choose)
        {
            case 1:
            {
                string name,depart;
                float GPA;
                int id;
                cout << "id:"; cin >> id;
                cin.ignore();
                cout << "Name:"; getline(cin, name);
                cout << "GPA:"; cin >>GPA;
                cout << "Department:"; cin >> depart;
                insert_node(name , depart, GPA , id);
                break;
            }
            case 2:
                deleteNode();
                break;
            case 3:
                int id; cout << "id:"; cin >>id;
                search(id);
                break;
            case 4:
                print();
                break;
            case 5:
                stop = true;
                break;
        }
        }
}

void BST::read_file() {
    fstream fin;
    fin.open("D:\\second year\\second term\\data structure\\code\\assi3\\input.txt", ios::in);
    if (!fin.is_open()) {
        cout << "Error opening file\n";
    }
    int n;
    fin >> n;
    string dummy;
    getline(fin, dummy); // skip over the newline character after n
    for (int i = 0; i < n; i++) {
        int id;
        float gpa;
        string name, depart, temp;
        getline(fin, temp) ;
        id = stoi(temp);
        getline(fin, name);
        getline(fin, temp) ;
        gpa = stof(temp);
        getline(fin, depart) ;
        insert_node(name, depart, gpa, id);
    }
    fin.close();
}




