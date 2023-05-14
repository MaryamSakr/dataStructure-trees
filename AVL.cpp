#include <vector>
#include <fstream>
#include <algorithm>
#include "iostream"
using namespace std;

struct student {

    student() {}

    int id=0;
    string name;
    string department;
    float GPA;
    string departments[5] = {"DS", "IS", "CS", "AI","IT"};
    student(const string &name, const string &depart, float Gpa, int id){
        this->name=name;
        this->department=depart;
        this->GPA=Gpa;
        this->id=id;

    }
};


struct node{
    student s;
    node* left , * right;
    int height=1;
    node( const student & s, node *lt, node *rt, int h = 0 ):s{ s }, left{ lt }, right{ rt }, height{ h } { }
};

class AVL{
private:
    student s;
    node* root;
    int choose=0;
    vector<student> students;

public:
    AVL() {
        root=NULL;
    }

    void work(){
        read_file();
        while(choose!=5) {
            cout<<"please choose one of the following options:\n1)Add student\n2) Remove student\n3) Search student\n4) Print All (sorted by id)\n5) Return to main menu\n";
            cin>>choose;
            if(choose==5) {

            }
            switch (choose) {
                case 1:
                    bool flag;
                    cout<<"we need a little information to add student please enter:\nstudent ID: ";
                    cin>>s.id;
                    for(int i=0 ; i<students.size() ; i++) {
                        while(s.id==students[i].id) {
                            cout<<"the id is already exist please enter another id.\nstudent ID:";
                            cin>>s.id;
                        }
                    }
                    cout<<"\nstudent name: ";
                    cin>>s.name;
                    cout<<"\nstudent Department: ";
                    cin>>s.department;
                    transform(s.department.begin(), s.department.end(), s.department.begin(), ::toupper);
                    for(int i=0 ; i<5 ; i++) {
                        if(s.departments[i]==s.department) {
                            flag = true;
                            break;
                        }
                    }
                    while (flag== false) {
                        cout<<"please enter a valid department";
                        cout<<"\nstudent Department: ";
                        cin>>s.department;
                        transform(s.department.begin(), s.department.end(), s.department.begin(), ::toupper);
                        for(int i=0 ; i<5 ; i++) {
                            if(s.departments[i]== (s.department)) {
                                flag = true;
                                break;
                            }
                        }
                    }
                    cout<<"\nstudent GPA: ";
                    cin>>s.GPA;
                    while (s.GPA > 4 || s.GPA<0)
                    {
                        cout << "Enter Valid Gpa. ( gpa< 4 )";
                        cin >> s.GPA;
                    }
                    students.push_back(s);
                    add_student(root , s);
                    cout<<"student is added.\n__________________\n";
                    break;
                case 2:
                    int id;
                    bool check;
                    cout << "please enter the id of student that you want to delete: ";
                    cin >> id;
                    for(int i=0 ; i<students.size() ; i++) {
                        if (students[i].id == id) {
                            check = true;
                            break;
                        }
                    }
                    if(check== false) {
                        cout<<"the student is not exist\n_________________\n";
                        break;
                    }
                    else {
                        Delete_Student(root, id);
                        cout<<"student is removed\n____________________________\n";
                        break;
                    }
                case 3:
                    int id2;
                    bool check2;
                    cout << "please enter the id of student that you want to delete: ";
                    cin >> id2;
                    for(int i=0 ; i<students.size() ; i++) {
                        if (students[i].id == id2) {
                            check2 = true;
                            break;
                        }
                    }
                    if(check2== false) {
                        cout<<"the student is not exist\n___________________\n";
                        break;
                    }
                    else {
                        Search_Student(root, id2);
                        break;
                    }
                case 4:
                    printAVL(root);
                    break;
                default:
                    cout<<"please enter a valid choice";
            }
        }
    }

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
            student std(name, depart, gpa, id);
            students.push_back(std);
            add_student(root,std);
        }
        fin.close();
    }

    int max(int a, int b) {
        if(a>b) {
            return a;
        }
        else{
            return b;
        }
    }

    node * mini(node * node1) {
        node *node2 = node1;
        int temp=(node1->right)->s.id;
        while (node2->right!= nullptr) {
            if((node2->right)->s.id<temp) {
                temp=(node2->right)->s.id;
            }
            else {
                continue;
            }
        }
        return node2;
    }


    int get_height( node* node1)
    {
        if (node1 == NULL){
            return 0;
        }
        else{
            return node1->height;
        }
    }


    void right_rotate(node * & node1) {
        node* node2=node1->left;
        node* node3=node2->right;
        node2->right=node1;
        node1->left=node3;
        node1->height= max(get_height(node1->left) , get_height(node1->right)) + 1;
        node2->height= max(get_height(node2->left) , get_height(node2->right)) + 1;

    }

    void left_rotate(node * & node1) {

        node* node2=node1->right;
        node* node3=node2->left;
        node2->left=node1;
        node1->right=node3;
        node1->height= max(get_height(node1->left) , get_height(node1->right)) + 1;
        node2->height= max(get_height(node2->left) , get_height(node2->right)) + 1;

    }




    void balance( node * & node1)
    {
         if( node1 == nullptr )
             return;
         if(get_height(node1->left ) -get_height( node1->right ) > 1 ){
             if( get_height( node1->left->left ) >= get_height( node1->left->right ) )
                 right_rotate( node1 );
             else{
                 right_rotate( node1 );
                 left_rotate(node1);
             }

         }

         else{
             if( get_height( node1->right ) - get_height( node1->left ) > 1){
                 if( get_height( node1->right->right ) >= get_height( node1->right->left ) )
                 {
                     left_rotate( node1 );

                 }

                 else {

                     left_rotate(node1);
                     right_rotate(node1);
                 }
             }



         }
         //node1->height = max( get_height( node1->left ), get_height( node1->right ) ) + 1;
         }


        void add_student(node* & node1 , student & s) {
            if (node1 == NULL) {
                node1 = new node{s, nullptr, nullptr};
            } else if (s.id < (node1->s.id)) {
                add_student(node1->left, s);

            } else if (s.id > (node1->s.id)) {
                add_student(node1->right, s);
            }
            balance(node1);

        }


        void Delete_Student(node * & node1 , int id) {
            node* node2=node1;
            if( node1 == nullptr ) {
                return;
            }

            if( id < node1->s.id ) {
                Delete_Student( node1->left, id );
            }
            else if(id>node1->s.id) {
                Delete_Student(node1->right , id);
            }
            else if( node1->left != nullptr && node1->right != nullptr ){
                node1->s.id = mini( node1->right )->s.id;
                Delete_Student( node1->right, id );
            }
            else
            {
                if(node1->left!= nullptr) {
                    node1=node1->left;
                }
                else{
                    node1=node1->right;
                }
                delete node2;
            }
            balance(node1);
            for(int i=0 ; i<students.size() ; i++) {
                if(id==students[i].id) {
                    students.erase(students.begin()+i);
                    break;
                }
                else{
                    continue;
                }
            }


    }


    void Search_Student(node * & node1 , int id) {
        if (node1 != NULL)
        {
            if (id > node1->s.id)
            {
                Search_Student(node1->right ,id);
            }
            else if (id < node1->s.id)
            {
                Search_Student(node1->left , id);
            }
            else
            {
                cout<<"- ID:"<<node1->s.id<<"\n  Name: "<<node1->s.name<<"\n  GPA: "<<node1->s.GPA<<"\n  Department: "<<node1->s.department<<endl;
                cout << "-------------------------------\n";
                return;
            }
        }


    }


    void AVLSort(vector<student> &stud  , int n) {
        for(int i=0 ; i<n-1 ; i++) {
            for (int j= i+1 ; j<n ;j++) {
                if(stud[j].id>stud[i].id) {
                    swap(stud[j] , stud[i]);
                }
            }
        }
    }


    void printAVL(node * node1){

            if(node1 != NULL)
            {

                printAVL(node1->left);
                cout<<"- ID:"<<node1->s.id<<"\n  Name: "<<node1->s.name<<"\n  GPA: "<<node1->s.GPA<<"\n  Department: "<<node1->s.department<<endl;
                cout<<"__________________________________\n";
                printAVL(node1->right);//4
            }
    }
};
