#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right=left=NULL;
    }
};
int a[100005];
class BST{
private:
    Node* root;
    Node*push(Node*cur, int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(val < cur->val){
            cur->left = push(cur->left, val);
        }
        if(val > cur->val){
            cur->right = push(cur->right, val);
        }
        return cur;
    }
    Node*inOrder(Node*cur){
        if(cur != nullptr){
            // cnt++;
            inOrder(cur->left);
            // cout << cur->val << " ";
            inOrder(cur->right);
        }
    }
    Node*postOrder(Node*cur){
        if(cur != nullptr){
            postOrder(cur->right);
            cout << cur->val << " ";
            postOrder(cur->left);
        }
    }
    Node*printLeaf(Node*cur){
        if(cur != nullptr){
            printLeaf(cur->left);
            if(cur->left == nullptr and cur->right == nullptr){
                cout << cur->val << endl;;
            }
            printLeaf(cur->right);
        }
    }

    int solga(Node* cur){
        if(cur == nullptr){
            return 0;
        }
        return solga(cur->left)+1;
    }

    int onga(Node* cur){
        if(cur == nullptr){
            return 0;
        }
        return onga(cur->right)+1;
    }

    void ushburysh(Node* cur){
        if(cur == nullptr){
            return;
        }
        int l = solga(cur->left);
        int r = onga(cur->right);

        for(int i = 1; i <= min(l, r); i++){
            a[i]++;
        }
        ushburysh(cur->left);
        ushburysh(cur->right);
    }

    void print(Node* cur){
        if(cur != nullptr){
            print(cur->left);
            cout << cur->val << " ";
            print(cur->right);
        }
    }

public:
    BST(){
        root=NULL;
    }

    void push(int val){
        root=push(root, val);
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
    void ushburysh(){
        ushburysh(root);
    }

    void print(){
        print(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.ushburysh();

    for(int i = 1; i < n; i++){
        cout << a[i] << " ";
    }
}