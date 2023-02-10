#include <iostream>
using namespace std;
struct Node{
    int val;
    Node*next;

    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class LinkedList{
    Node*head;
    Node*tail;
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
            tail = newNode;
        }
    }
    Node* middle(){
           Node*fast = head;
           Node*slow = head; 
           while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
           }
           return slow;
        }
    }
    void print(){
        Node*cur = head;
        while(cur != nullptr){
            cout << cur->val << " ";
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
        list.push(x);
    }
    cout << list.middle();
    list.print();
}