#include<iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x),left(NULL),right(NULL){}
};
Node* Search(Node* root,int key){
    if (root == NULL || root->key == key){
        return root;
    }
    if (key < root->key){
        Search(root->left,key);
    }
    else{
        Search(root->right,key);
    }
}
Node* FindMin(Node* root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}
void Insert(Node* &root,int key){
    if (root == NULL){
        root  =  new  Node(key);    //若为空，则新建节点
        return;
    }
    if (key < root->key){
        Insert(root->left,key);
    }
    else if (key > root->key){
        Insert(root->right,key);
    }
}
Node* Delete(Node* &root,int key){
    if (root == NULL){
        return root;
    }
    if (key < root->key){
        root->left = Delete(root->left,key);
    }
    else if (key > root->key){
        root->right = Delete(root->right,key);
    }
    else{
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = FindMin(root->right);
        root->key = temp->key;
        root->right = Delete(root->right,temp->key);
    }
    return root;
}
void  InorderTraversal(Node  *root){    
      if(root  !=  NULL){    
                InorderTraversal(root->left);    
                cout  <<  root->key  <<  "  ";    
                InorderTraversal(root->right);    
      }    
}
int main()
{
    Node* root = NULL;
    int keys[] = {2,8,1,4,6,3,5,7};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0;i < n;i++){
        Insert(root,keys[i]);
    }
    InorderTraversal(root);
    cout << endl;

    Node* node = Search(root,6);
    if (node != NULL){
        cout << "Find 6" << endl;;
    }
    else{
        cout << "Not find 6" << endl;
    }
    root = Delete(root,6);
    InorderTraversal(root);
    return 0;
}