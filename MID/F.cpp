#include <iostream>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};
int cnt = 0;
class BST{
    // int level = 0;
    Node*root;
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
            cnt++;
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
    Node*lev(Node*cur, int level){
        if(cur != nullptr){
            int num = cur->val - level;
            cnt+= num;
            // level ++;
            lev(cur->right, level + 1);
            lev(cur->left, level + 1);
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

    void printLeaf(){
        printLeaf(root);
    }
    void lev(){
        lev(root, 0);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.lev();
    cout << cnt;
}