#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    
    Node(int val){
        this -> val = val;
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

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }        
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    int offset(int k){
        Node*cur = head;
         int mn = abs(cur -> val - k), ind = 0, i = 0;
        while(cur != nullptr){
            int dis = abs(cur -> val - k);
            if(dis < mn){
                mn = dis;
                ind = i;
            }
            cur = cur -> next;
            i++;
        }
        return ind;
    }
    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};
int main(){
    Linkedlist list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.push(x);
    }
    int k;
    cin >> k;
    cout << list.offset(k);
}

