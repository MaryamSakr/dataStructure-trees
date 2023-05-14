//
// Created by Lenovo on 5/10/2023.
//

#ifndef DATA_STRUCTURE_ASS3_MIN_HEAP_H
#define DATA_STRUCTURE_ASS3_MIN_HEAP_H

#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;


void min_heapfiy(vector<Student>& stud,int i,int n){
    int left=(2*i)+1;
    int right=(2*i)+2;
    int min=i;
    if(i<n){
        if(left < n && stud[left].gpa > stud[min].gpa){
            min=left;
        }if(right < n && stud[right].gpa > stud[min].gpa){
            min=right;
        }
        if(min != i){
            swap(stud[i],stud[min]);
            min_heapfiy(stud,min,n);
        }
    }
}

void buildMin_Heap(vector<Student> &stud){
    if(stud.size()==0){
        read_file();
    }
    int n=stud.size();
    for(int i=(n/2)-1;i>=0;i--){
        min_heapfiy(stud,i,n);
    }
}

void min_heapSort(vector<Student> &stud){
    buildMin_Heap(stud);
    int n=stud.size();
    for(int i=n-1;i>=0;i--){
        swap(stud[0],stud[i]);
        min_heapfiy(stud,0,i);
    }
}

void printMinHeap(vector<Student>& stud){
    min_heapSort(stud);
    int n=stud.size();
    int cs=0,is=0,ds=0,ai=0,it=0;
    cout<<"Print "<<n<<" students.\n";
    for(int i=0;i < n;i++){
        cout << "["<<stud[i].id<<","<<stud[i].name<<","<<stud[i].gpa<<","<<stud[i].depart<<"]"<<endl;
    }
    for(int i=0;i < n;i++){
        if(stud[i].depart=="IS")
            is++;
        else if(stud[i].depart=="CS")
            cs++;
        else if(stud[i].depart=="IT")
            it++;
        else if(stud[i].depart=="DS")
            ds++;
        else if(stud[i].depart=="AI")
            ai++;
    }
    cout<<"Students per Departments:\n";
    cout<<"CS "<<cs<<" students\n";
    cout<<"IT "<<it<<" students\n";
    cout<<"DS "<<ds<<" students\n";
    cout<<"IS "<<is<<" students\n";
    cout<<"AI "<<ai<<" students\n";
}



#endif //DATA_STRUCTURE_ASS3_MIN_HEAP_H