#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = nullptr;
    }
};

class LinkedList{
    int size;
public:
    Node * head;
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void push(int val){
        Node * newNode = new Node(val);
        if (head == nullptr){ head = newNode; }
        else{
            Node * cur = head;
            while(cur->next != nullptr){
                cur = cur->next;
//                cur = *(cur.next);
            }
            cur -> next = newNode;
        }
        size++;
    }
    void addFront(int val){
        Node * newNode = new Node(val);
        if (head == nullptr){ head = newNode; }
        else{
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }
    void print(){
        Node * cur = head;
        while(cur -> next != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << cur -> val << endl;
    }

    void del(int val){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        if (head -> val == val){
            head = head -> next;
        }
        else{
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if (cur -> val == val){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
            }
            cout << "No such element " << val << endl;
        }
    }


    void del1(int pos){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        if (pos == 1){
            head = head -> next;
        }
        else{
            int i = 1;
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if (i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
            cout << "No such pos " << pos << endl;
        }
    }
};

int main(){
    LinkedList list;
    list.push(1);
    list.push(3);
    list.push(6);
    list.push(8);
    list.push(10);
    list.push(123);
    list.push(22);
    list.print();
    list.del1(2);
    list.print();
    list.del1(5);
    list.print();
    list.del1(-123);

    //Merge sort


}