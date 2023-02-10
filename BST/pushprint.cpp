#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if (cur == nullptr){
            return new Node(val);
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    Node * inOrder(Node * cur){
        if (cur != nullptr){
            inOrder(cur -> left);
            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
    }

    Node * postOrder(Node * cur){
        if (cur != nullptr){
            postOrder(cur -> right);
            cout << cur -> val << " ";
            postOrder(cur -> left);
        }
    }
public:

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

};

int main(){
    BST tree;
    tree.push(3);
    tree.push(5);
    tree.push(6);
    tree.push(7);
    tree.push(9);
    tree.push(2);
    tree.inOrder();
    cout << endl;
    tree.postOrder();
}
