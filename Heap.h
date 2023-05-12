//
// Created by Lenovo on 5/10/2023.
//

#ifndef DATA_STRUCTURE_ASS3_HEAP_H
#define DATA_STRUCTURE_ASS3_HEAP_H
#include <bits/stdc++.h>
using namespace std;

struct student{
    string name;
    string depart;
    int id;
    float gpa;
    student(const string &name, const string &depart, float Gpa, int id) :
            name(name),depart(depart),gpa(Gpa), id(id) {

    }
};
vector<student> students;
void read_file() {
    fstream fin;
    fin.open("D:\\Clion projects\\data structure ass3\\input.txt", ios::in);
    if (!fin.is_open()) {
        cout << "Error opening file\n";
        return;
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
        student s(name, depart, gpa, id);
        students.push_back(s);
    }
    fin.close();
}

void addStudent(vector<student>&stud){
    vector<string> departments = {"DS", "IS", "CS", "AI","IT"};
    string name;
    string depart;
    int id;
    float gpa;
    cout<<"Please enter thr student information:\nId:";
    cin>>id;
    cout<<"Name:";
    getline(cin,name);
    getline(cin,name);
    cout<<"GPA:";
    cin>>gpa;
    while (gpa > 4)
    {
        cout << "Enter Valid Gpa. ( gpa< 4 )";
        cin >> gpa;
    }
    cout<<"Department:";
    cin>>depart;
    bool d = find(departments.begin(), departments.end(), depart);
    while ()
    student s(name,depart,gpa,id);
    stud.push_back(s);
}

#endif //DATA_STRUCTURE_ASS3_HEAP_H
