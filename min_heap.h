//
// Created by Lenovo on 5/10/2023.
//

#ifndef DATA_STRUCTURE_ASS3_MIN_HEAP_H
#define DATA_STRUCTURE_ASS3_MIN_HEAP_H

#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;


void min_heapfiy(vector<student>& stud,int i,int n){
    int left=(2*i)+1;
    int right=(2*i)+2;
    int max=i;
    if(i<n){
        if(left<n && stud[left].gpa < stud[max].gpa){
            max=left;
        }if(right<n && stud[right].gpa < stud[max].gpa){
            max=right;
        }
        if(max != i){
            swap(stud[i],stud[max]);
            min_heapfiy(stud,max,n);
        }
    }
}

void buildMin_Heap(vector<student> &stud){
    read_file();
    int n=stud.size();
    for(int i=(n/2)-1;i>=0;i--){
        min_heapfiy(stud,i,n);
    }
}

void min_heapSort(vector<student> &stud){
    buildMin_Heap(stud);
    int n=stud.size();
    for(int i=n-1;i>=0;i--){
        swap(stud[0],stud[i]);
        min_heapfiy(stud,0,i);
    }
}

void printMinHeap(vector<student>& stud){
    min_heapSort(stud);
    int n=stud.size();
    cout<<"Print "<<n<<" students.\n";
    for(int i=0;i<n;i--){
        cout << "["<<stud[i].id<<","<<stud[i].name<<","<<stud[i].gpa<<","<<stud[i].depart<<"]"<<endl;
    }
}

void MinHeapMenu(){
    cout<<"1)Add student\n2)Print All (sorted by gpa)\n3)Return to main menu\n";
    int ch;
    cin>>ch;
    if(ch==1){
        addStudent();
        cout<<"1)If you want to shoe Min Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MinHeapMenu();
        if(choose==2)
            exit(0);
        if(choose==3){

        }
        else{
            cout<<"invalid chose.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==2){
        printMinHeap(students);
        cout<<"1)If you want to shoe Max Heap menu again\n2)If you want to close program\n3)Return to main menu\n";
        int choose;
        cin>>choose;
        if(choose==1)
            MinHeapMenu();
        if(choose==2)
            exit(0);
        else{
            cout<<"invalid chose.\nthe program will close.\n";
            exit(0);
        }
    }
    if(ch==3){

    }
}


#endif //DATA_STRUCTURE_ASS3_MIN_HEAP_H
