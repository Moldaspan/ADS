#include <iostream>
using namespace std;

struct student{
    int age;
    string name;
    string fac;
    double gpa;
};

int main(){
    //student alish;
    // int alish_age; ---->  alish.age = 19;
    // string alish_name; ----> alish.name = "Alisher";
    // string alish_fac; ----> alish.fac = "FIT";
    // double alish_gpa; ----> alish.gpa = 2.45;

    //student yers;
    // int yers_age; ---->  yers.age = 18;
    // string yers_name; ---->  yers.name = "Yersultan";
    // string yers_fac; ----> yers.fac = "FIT";
    // double yers_gpa; ----> yers.gpa = 3.74;


 //Дано число N. А затем информация об N студентах (имя, факультет, возраст, гпа)
    //Вывести количетсво студентов, обучающихся на факультете FIT, чей gpa > 3.0

    //alish fit 19 2.9
    //yers fit 18 3.74
    //bala git 20 2.7

    //output 1

    int n;
    cin >> n;
    student a[n];
    for(int i = 0 ; i < n; i++){
        cout << "Age: ";
        cin >> a[i].name;
        cout << "Name: ";
        cin >> a[i].name;
        cout << "Faculty: ";
        cin >> a[i].fac;
        cout << "GPA: ";
        cin >> a[i].gpa;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i].fac == "FIT" and a[i].gpa > 3.0){
            cnt++;
        }
    }
    cout << cnt << " ";
}