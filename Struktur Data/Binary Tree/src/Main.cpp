#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

// operation using pointer in the function or local variable doesn't affect the valu in main
// example in function we do looping
// loop{root = root->left} --> this root change the pointer address in local variable only no in main

void getNewData(BstNode** rootPtr, int data);
void insert(BstNode** rootPtr, int data);
BstNode* getNewData(BstNode* rootPtr, int data);
BstNode* insert(BstNode* rootPtr, int data);
int findMax(BstNode* rootPtr);
int findMin(BstNode* rootPtr);
BstNode* findMinNode(BstNode* rootPtr);
int findHeight(BstNode* rootPtr);
int findDepth(BstNode* rootPtr, int data);
void preOrder(BstNode* rootPtr);
void inOrder(BstNode* rootPtr);
void postOrder(BstNode* rootPtr);
void levelOrder(BstNode* rootPtr);
bool search(BstNode* rootPtr, int data);
bool isBinarySearchTree(BstNode* rootPtr);
bool isBinaryTree(BstNode*);
bool isSubtreeLesser(BstNode*, int);
bool isSubtreeGreater(BstNode*,int);
BstNode* deleteData(BstNode*, int);
BstNode* inorderSuccessor(BstNode*,int);
BstNode* searchNode(BstNode*,int);

int menu(){
    int num;
    cout << "===== Menu Binary Tree =====\n";
    cout << "1. Insert\n2. Display\n3. Delete\n4. Is Binary Tree?\n5. Find Depth\n6. Find Inorder Successor\nChoose : "; cin >> num;
    return num;
}

int main(int argc, char const *argv[])
{

    BstNode* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 17);
    root = insert(root, 21);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root,3);
    insert(&root, 4);
    insert(&root, 16);
    insert(&root, 18);
    insert(&root, 28);
    insert(&root, 1);
    insert(&root, 11);
    insert(&root, 14);
    insert(&root, 9);

    while(true){
        int num;
        int choose = menu();
        switch(choose){
            case 1:
            break;
            case 2:
                cout << "Height of the Tree : " << findHeight(root) << endl;
                cout << "Max Value of Tree : " << findMax(root) << endl;
                cout << "Min Value of Tree : " << findMin(root) << endl;
                cout << "PreOrder Tree : "; preOrder(root); cout << "\n";
                cout << "Inorder Tree : "; inOrder(root); cout << "\n";
                cout << "Postorder Tree : "; postOrder(root); cout << "\n";
                cout << "Level Order : "; levelOrder(root); cout << "\n";
            break;
            case 3:
                cout << "\nDelete data : "; cin >> num;
                root = deleteData(root,num);
                break;
            case 4:{
                string isBinarySearch = (isBinarySearchTree(root)) ? "Yes" : "No";
                string isBinary = (isBinaryTree(root)) ? "Yes" : "No";
                cout << "\nIs this Binary Search Tree : " << isBinarySearch << "\n\n";
                cout << "Is this Binary Search Tree : " << isBinary << "\n\n";
            }
            break;
            case 5:
                cout << "Find Depth of Node : "; cin >> num;
                cout << "The Depth of Node " << num << " is " << findDepth(root,num) << endl;
            break;
            case 6:{
                cout << "Search indorder successor : "; cin >> num;
                BstNode* successor = inorderSuccessor(root,num);
                cout << "inorder successor of " << num << " is " << successor->data << endl;
            }
            break;
            case 7:
                cout << "Enter Number : "; cin >> num;
                if(search(root, num) == true) cout << "Found\n";
                else cout << "Not Found\n";
            break;
        }
        system("pause"); 
        system("cls");
    }

    return 0;
}

// Method to get data with use address of the root
void getNewData(BstNode** rootPtr, int data){
    *rootPtr = new BstNode();
    (*rootPtr)->left = (*rootPtr)->right = NULL;
    (*rootPtr)->data = data; 
}
// Method to insert data with use address of the root
void insert(BstNode** rootPtr, int data){
    if(*rootPtr == NULL){
        getNewData(*rootPtr,data);
    }else if(data <= (*rootPtr)->data){
        insert((*rootPtr)->left,data);
    }else{
        insert((*rootPtr)->right, data); 
    }
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
// Find Minimun value of the all node in binary tree
int findMax(BstNode* rootPtr){
    if(rootPtr->right == NULL) return rootPtr->data;
    else return findMax(rootPtr->right);
}
// Find Maximum value of the all node in binary tree
int findMin(BstNode* rootPtr){
    if(rootPtr->left == NULL) return rootPtr->data;
    else return findMin(rootPtr->left);
}
// Find Maximum value of the all node in binary tree
BstNode* findMinNode(BstNode* rootPtr){
    while(rootPtr->left != NULL) rootPtr = rootPtr->left;
    return rootPtr;
}
// find the height of the tree
int findHeight(BstNode* rootPtr){
    if(rootPtr == NULL)
        return -1;
    int heightLeft = findHeight(rootPtr->left);
    int heightRight = findHeight(rootPtr->right);

    return max(heightRight,heightLeft) + 1;
}
// find the depht of the node from root tree
int findDepth(BstNode* rootPtr, int data){
    BstNode* root;
    if(rootPtr->data == data) return 0;
    else if(rootPtr->data >= data) root = rootPtr->left;
    else root = rootPtr->right;
    return findDepth(root,data) + 1;
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
// Display binary tree in level order (depends on the depth)
void levelOrder(BstNode* rootPtr){
    if(rootPtr == NULL) return;
    int depth = findDepth(rootPtr,rootPtr->data);
    cout << "\nDepth : " << depth << "\n";
    queue<BstNode*> Q;
    Q.push(rootPtr);
    while(!Q.empty()){
        BstNode* current = Q.front();
        if(depth!=findDepth(rootPtr,current->data)){
            depth = findDepth(rootPtr,current->data);
            cout << "\nDepth : " << depth << "\n";
        }
        cout << current->data << " ";
        if(current -> left != NULL) Q.push(current->left);
        if(current -> right != NULL) Q.push(current->right);
        Q.pop();
    }
}
BstNode* deleteData(BstNode* rootPtr, int data){
    if(rootPtr == NULL) return rootPtr;
    else if(rootPtr->data < data) rootPtr->right = deleteData(rootPtr->right, data);
    else if(rootPtr->data > data) rootPtr->left = deleteData(rootPtr->left, data);
    else{ // situation for rootPtr->data == data and will delete node
        if(rootPtr->left == NULL && rootPtr->right == NULL){ // leaf node
            delete rootPtr; // deallocation memory for pointer in the heap
            rootPtr = NULL;
        }else if(rootPtr->left == NULL){ // have one chile at right subtree
            BstNode* temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }else if(rootPtr->right == NULL){ // have one child at left subtree
            BstNode* temp = rootPtr;
            rootPtr = rootPtr->left; 
            delete temp;
        }else{ // have two child at left and righr subtree and choose the min of right subtree to be the value of the root
            BstNode* temp = findMinNode(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->right = deleteData(rootPtr->right, temp->data);
        }
    }
    return rootPtr;
}
// find next successor of node in inorder way
BstNode* inorderSuccessor(BstNode* rootPtr, int data){
    BstNode* current = searchNode(rootPtr,data);
    if(rootPtr != NULL) return rootPtr;
    if(rootPtr->right != NULL) return findMinNode(rootPtr->right);
    else{
        BstNode* successor = NULL;
        BstNode* ancestor = rootPtr;
        while(ancestor!=current){
            if(current->data < ancestor->data){
                successor = ancestor; // this is the deepest node for which current node is left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right; // deepest last node for which current in right
        }
        return successor;
    }
}
// Search the data if its exist in binary tree or not
bool search(BstNode* rootPtr, int data){
    if(rootPtr == NULL) return false;
    else if(rootPtr->data == data) return true; 
    else if(data <= rootPtr->data){
        cout << "Left\n";
        return search(rootPtr->left, data);  
    } 
    else{
        cout << "Right\n";
        return search(rootPtr->right, data);
    } 
}
BstNode* searchNode(BstNode* rootPtr, int data){
    if(rootPtr == NULL) return NULL;
    else if(rootPtr->data == data) return rootPtr; 
    else if(data <= rootPtr->data){
        cout << "Left\n";
        return searchNode(rootPtr->left, data);  
    } 
    else{
        cout << "Right\n";
        return searchNode(rootPtr->right, data);
    } 
}

// only min max will check
bool isBinarySearchTree(BstNode* rootPtr){
    BstNode* leftTree;
    BstNode* rightTree;
    leftTree = rootPtr->left;
    rightTree = rootPtr->right;
    if(rootPtr == NULL) return true;
    if(leftTree->data >= findMin(leftTree) && leftTree->data < findMax(leftTree) 
    && rightTree->data >= findMin(rightTree) && rightTree->data < findMax(rightTree))
        return true;
    else 
        return false;
}

// overall check data
bool isBinaryTree(BstNode* rootPtr){
    if(rootPtr == NULL) return true;
    if(isSubtreeLesser(rootPtr->left, rootPtr->data)
    && isSubtreeGreater(rootPtr->right, rootPtr->data)
    && isBinaryTree(rootPtr->left)
    && isBinaryTree(rootPtr->right))
        return true;
    else
        return false;
}
// check binary tree at left subtree
bool isSubtreeLesser(BstNode* rootPtr, int data){
    if(rootPtr == NULL) return true;
    if( rootPtr -> data <= data
        && isSubtreeLesser(rootPtr->left,data)
        && isSubtreeLesser(rootPtr->right, data))
        return true;
    else
        return false;
}
// check binary tree at rigth subtree
bool isSubtreeGreater(BstNode* rootPtr, int data){
    if(rootPtr == NULL) return true;
    if( rootPtr -> data > data
        && isSubtreeGreater(rootPtr->left,data)
        && isSubtreeGreater(rootPtr->right, data))
        return true;
    else
        return false;
}