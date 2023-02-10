#include <iostream>
#include <vector>
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
public:
    Node*head;
    Node*tail;
    int size = 0;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push(int val){
        Node*newNode = new Node(val);
        if(head == nullptr){
            head = tail =  newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void sort(){
        Node * first = head;
        Node * second = nullptr;
        if (head == nullptr){
            return;
        }
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if (first -> val > second -> val){
                    swap(first->val, second->val);
                }
                second = second -> next;
            }
            first = first -> next;
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
    LinkedList list, list2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.push(x);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int k; 
        cin >> k;
        list2.push(k);
    }
    list.tail -> next = list2.head;
    list.sort();
    list.print();
}

