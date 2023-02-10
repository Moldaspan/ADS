#include<bits/stdc++.h>

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
    map<int, int> levelSum;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    } 

    void getLevelsSum(Node* cur, int level) {
        if (!cur) return;
        levelSum[level] += cur -> val;
        getLevelsSum(cur -> right, level + 1);
        getLevelsSum(cur -> left, level + 1);
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int height(){
        return height(root);
    }

    void getLevelsSum(){
        getLevelsSum(root, 0);
    }

    vector<int> res(){
        vector<int> ans;
        for(auto i : levelSum){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.getLevelsSum();
    for(auto i : tree.res()) cout << i << " ";
}

#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};
int depth = 0;
int maxi = 0;
int a[10000] = {0};

struct bst{
    
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    // void print(){
    //     this->print(this->root);
    // }

    // private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    node * find(node * current, int x){
        if(x < current->val){
            return find(current->left,x);
        }else if(x == current->val){
            return current;
        }else if(x > current->val){
            return find(current->right,x);
        }
    }
    
    void sum_of_levels( int level, node * current){
        if(current == NULL){
            // depth--;
            return;
        }
        a[level] += current->val;
        depth++;
        sum_of_levels(level + 1,current->left);
        if(depth > maxi){
            maxi = depth;
        }
        sum_of_levels(level + 1,current->right);
    }
};

bst * b = new bst();


int main(){

    int n;
    cin>>n;
    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        int k; cin>>k;
        b->add(k);
    }
    
    
   
    b->sum_of_levels(0,b->root);
    // int aaa = 0;
    vector <int> v;
    for(int i=0;i<10000;i++){
        if(a[i]!=0){
            v.push_back(a[i]);

        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;