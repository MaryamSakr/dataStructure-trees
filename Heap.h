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
            name(name),depart(depart),gpa(Gpa), id(id) {}
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
    getline(fin, dummy);
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

void addStudent(){
    read_file();
    vector<string> departments = {"DS", "IS", "CS", "AI","IT"};
    string name;
    string depart;
    int id;
    float gpa;
    cout<<"Please enter thr student information:\nId:";
    cin>>id;
    for(int i=0;i < students.size();i++){
        if(students[i].id == id){
            cout<<"Invalid id.\nPlease enter Non repeated id\n";
            addStudent();
            return;
        }
        if(i == students.size()-1 && students[i].id != id) {
            break;
        }
    }
    cout<<"Name:";
    getline(cin,name);
    getline(cin,name);
    cout<<"GPA:";
    cin>>gpa;
    while (gpa > 4 || gpa<0)
    {
        cout << "Enter Valid Gpa. ( gpa< 4 )";
        cin >> gpa;
    }
    cout<<"Department:";
    cin>>depart;
    transform(depart.begin(), depart.end(), depart.begin(), ::toupper);
    auto found= find(departments.begin(),departments.end(),depart);
    while (found == end(departments)){
        cout << "Enter Valid department:";
        cin >> depart;
        transform(depart.begin(), depart.end(), depart.begin(), ::toupper);
        found = find(departments.begin(),departments.end(),depart);
    }
    student s(name,depart,gpa,id);
    students.push_back(s);
    cout<<"The student is added.\n";
    return;
}

#endif //DATA_STRUCTURE_ASS3_HEAP_H
