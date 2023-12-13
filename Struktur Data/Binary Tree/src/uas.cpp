#include <iostream>
using namespace std;

/**
 * Nama : I Made Dwika Putra Riswanda
 * NIM  : 123200112
 * Struktur Data IF-C
 * 
 */

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewData(BstNode*, int);
BstNode* insert(BstNode*, int );
void preOrder(BstNode* rootPtr);
void inOrder(BstNode* rootPtr);
void postOrder(BstNode* rootPtr);

int main(int argc, char const *argv[])
{
    BstNode* root = NULL;
    // misal nim = 123190087 --> 0123789
    root = insert(root,3); 
    root = insert(root,1); 
    root = insert(root,8); 
    root = insert(root,0); 
    root = insert(root,2); 
    root = insert(root,7); 
    root = insert(root,9);

    cout << "Preorder : "; preOrder(root);
    cout << "\nInorder : "; inOrder(root);
    cout << "\nPostorder : "; postOrder(root); 
    return 0;
}

// Method to get data with use pointer of the root
BstNode* getNewData(BstNode* rootPtr, int data){
    rootPtr = new BstNode();
    rootPtr->left = rootPtr -> right = NULL;
    rootPtr ->data = data;  
    return rootPtr;
}
// Method to insert data with use pointer of the root
BstNode* insert(BstNode* rootPtr, int data){
    if(rootPtr == NULL){
        rootPtr = getNewData(rootPtr,data);
    }else if(data <= rootPtr->data){
        rootPtr->left = insert(rootPtr->left,data);
    }else{
        rootPtr->right = insert(rootPtr -> right, data); 
    }

    return rootPtr;
}
// display Binary tree in preorder
void preOrder(BstNode* rootPtr){
    cout << rootPtr-> data << " ";
    if(rootPtr -> left != NULL) preOrder(rootPtr->left);
    if(rootPtr -> right != NULL) preOrder(rootPtr->right);
}
// display Binary tree in inorder
void inOrder(BstNode* rootPtr){
    if(rootPtr -> left != NULL) inOrder(rootPtr->left);
    cout << rootPtr-> data << " ";
    if(rootPtr -> right != NULL) inOrder(rootPtr->right);
}
// display Binary tree in postorder
void postOrder(BstNode* rootPtr){
    if(rootPtr -> left != NULL) postOrder(rootPtr->left);
    if(rootPtr -> right != NULL) postOrder(rootPtr->right);
    cout << rootPtr-> data << " ";
}