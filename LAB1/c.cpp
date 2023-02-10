#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<char>deq1;
    deque<char>deq2;
    string s1;
    string s2;
    for(int i = 0; i <s1.size(); i++){
        if(s1[i] != '#'){
            deq1.push_back(s1[i]);
        }else{
            deq1.pop_back();
        }
    }
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] != '#'){
            deq2.push_back(s2[i]);
        }else{
            deq2.pop_back();
        }
    }
    if(deq1.size() != deq2.size()){
        cout << "NO" << endl;
    }else{
        for(int i = 0; i < deq2.size(); i++){
            if(deq1[i] != deq2[i]){
                cout << "NO" << endl;
            }
        }
        cout << "YES" << endl;
    }
}
