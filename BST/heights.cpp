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

int cnt = 0;
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

    void inOrder(Node * cur){
        if (cur != nullptr){
            cnt++;
            inOrder(cur -> left);
//            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
    }

    void printLeaf(Node * cur){
        if (cur != nullptr){
            printLeaf(cur -> left);
            if (cur -> left == nullptr && cur -> right == nullptr) cout << cur -> val << endl;
            printLeaf(cur -> right);
        }
    }

    void printForks(Node * cur){
        if (cur != nullptr){
            printForks(cur -> left);
            if (cur -> left != nullptr && cur -> right != nullptr) cout << cur -> val << endl;
            printForks(cur -> right);
        }
    }

    void printBranches(Node * cur){
        if (cur != nullptr){
            printBranches(cur -> left);
            if (cur -> left != nullptr && cur -> right == nullptr) cout << cur -> val << endl;
            if (cur -> left == nullptr && cur -> right != nullptr) cout << cur -> val << endl;
            printBranches(cur -> right);
        }
    }

    Node * postOrder(Node * cur){
        if (cur != nullptr){
            postOrder(cur -> right);
            cout << cur -> val << " ";
            postOrder(cur -> left);
        }
    }

    int height(Node * cur){
        if (cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
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

    void printLeaf(){
        printLeaf(root);
    }

    void printForks(){
        printForks(root);
    }

    void printBranches(){
        printBranches(root);
    }

    int height(){
        return height(root);
    }

};



int main(){
    BST tree;
    int x;
    while (cin >> x && x != 0){
        tree.push(x);
    }
    cout << tree.height() << endl;
}
