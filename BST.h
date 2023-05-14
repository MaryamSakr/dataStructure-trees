//
// Created by More on 06/05/2023.
//

#ifndef ASSI3_BST_H
#define ASSI3_BST_H
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name,depart;
    float GPA;
    int id;
    Node* left;
    Node* right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(const string &name, const string &depart, float gpa, int id) :
    name(name),depart(depart),GPA(gpa), id(id),left(NULL),right(NULL) {}
};

class BST {
private:
    Node * root;
    int length;
    map<string, int> sheet;
    void insert_node(string name,string depart,float GPA, int id);
    void search(int id);
    void deleteNode();
    void print();
    void help_print(Node* node);
    void read_file();
public:
    BST()
    {
        root = NULL;
        length = 0;
    }
    void work();
};


#endif //ASSI3_BST_H
