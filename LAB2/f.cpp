#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node * prev;

    Node(int val){
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
    Node * head;
    Node * tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    Node * find(int n){
        Node * cur = head;
        while(n > 0){
            cur = cur -> next;
            n--;
        }
        return cur;
    }

    void insert(int pos, int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            Node * need = find(pos);
            if(need == nullptr){
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
            }
            else if(need -> prev){
                need -> prev -> next = newNode;
                newNode -> prev = need -> prev;
                newNode -> next = need;
                need -> prev = newNode;
            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
            }
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
        list.push(x);
    }
    int k, pos;
    cin >> k >> pos;
    list.insert(pos, k);
    list.print();
}