#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *next;
    
    Node(int val){
        this->val = val;
        next = nullptr;
    }

};
class LinkedList{
    Node *head;
    public:
        LinkedList(){
            head = nullptr;
        }
    void push(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        } else {
            Node *cur = head;
            while(cur->next!= nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }
    
    void print(){
        Node *cur = head;
        while( cur != nullptr){
            cout << cur->val << " " ;
            cur = cur->next;  
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i % 2 == 0){
            list.push(x);
        }
    }
    list.print();
}