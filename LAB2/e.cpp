#include <bits/stdc++.h>

using namespace std;

struct node{
    string soz;
    node * next;
    node * prev;

    node(string soz){
       this->soz = soz;
       next = NULL; 
       prev = NULL;
    }
};
struct ll{
    node * head;   
    node * tail;

    ll(){
        head = NULL;
        tail = NULL;
    }
    bool find(string x){
        node * temp = head;
        while(temp != NULL){
            if(temp->soz == x){
                return false;
            }
            temp = temp->next;
        }   
        return true;
    }

    void add(string x){
        node * newNode = new node(x);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;   
        }
    }
 

    void print(){
        node * temp = tail;
        while(temp != NULL){
            cout << temp->soz <<endl;;
            temp = temp->prev;
        }
    }

};


ll * l = new ll();

int main(){

    int n;
    cin>>n;
    string s2;
    string s;
    int cnt = 1;
    cin>>s;
    l->add(s);
    for(int i=0;i<n-1;i++){
        cin>>s;
        if(s!=l->tail->soz){
            l->add(s);
            cnt++;
        }
    }

    cout<<"All in all: "<<cnt<<endl;
    cout<<"Students:"<<endl;;
    l->print();

    return 0;
}