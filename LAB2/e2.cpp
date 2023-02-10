#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    int cnt;
    Node* next;
    Node* prev;

    Node(string val){
        this -> val = val;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class Linkedlist{
    Node* head;
    Node* tail;
    int size;

public:
    Linkedlist(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void push_front(string val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            size = 1;
        } else {
            if(head -> val == val){
                head -> cnt++;
            }
            else if(head -> prev == nullptr){
                head -> prev = newNode;
                newNode -> next = head;
                head = newNode;
                size++;
            }
        }
    }

    void print(){
        Node* cur = head;
        cout <<"All in all: " << size << endl;
        cout <<"Students:" << endl;
        while(cur!=nullptr){
            cout << cur->val << endl;
            cur=cur->next;
        }
    }
};
int main(){
    Linkedlist list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;   
        cin >> s;
        list.push_front(s);
    }
    list.print();
}