#include <iostream>
using namespace std;

struct Node{
    string soz;
    Node * next;
    Node(string soz){
        this -> soz = soz;
        next = nullptr;
    }
};

class Linkedlist{
    Node * head;
    Node * tail;
public:
    Linkedlist(){
        head = nullptr;
    }

    void push(string soz){
        Node * newNode = new Node(soz);
        if(head == nullptr){
            head = tail = newNode;
        }        
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void delet(){
        head = head -> next;
        }
    
    Node * getHead(){
        return head;
    }
    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> soz << " ";
            cur = cur -> next;
        }
    }
};
int main(){
    Linkedlist list;
    int n, k; 
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        list.push(x);
    }
    for(int i = 0; i < n; i++){
        list.push(list.getHead() -> val);
        list.delet();
    }
    list.print();
}