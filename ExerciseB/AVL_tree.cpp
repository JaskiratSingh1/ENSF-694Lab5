//
//  AVL tree.cpp
//  AVL tree
//
//  Created by Mahmood Moussavi on 2024-05-22.
//

#include "AVL_tree.h"

AVLTree::AVLTree() : root(nullptr), cursor(nullptr){}

int AVLTree::height(const Node* N) {
    //If N is nullptr then return height = 0
    if(N == nullptr) return 0;
    return N->height;
}

int AVLTree::getBalance(Node* N) {
    //If N is nullptr then return height = 0
    if(N == nullptr) return 0;
    //Balance = left height - right height
    return height(N->left) - height(N->right);
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    //Rotate
    x->right = y;
    y->left = T2;
    
    //New height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
 }

 Node* AVLTree::leftRotate(Node* x) {
     Node* y = x->right;
     Node* T2 = y->left;
     
     //Rotate
     y->left = x;
     x->right = T2;
     
     //New height
     x->height = max(height(x->left), height(x->right)) + 1;
     y->height = max(height(y->left), height(y->right)) + 1;
     
     return y;
 }

void AVLTree::insert(int key, Type value) {
    root = insert(root, key, value, nullptr);
}

//Recursive function
 Node* AVLTree::insert(Node* node, int key, Type value, Node* parent) {
     if (node == nullptr) {return new Node(key, value, parent);} // Node(left, right, parent) format
         
     //Call insert function with left or right node depending on key value
     if (key < node->data.key) {node->left = insert(node->left, key, value, node);}
     else if (key > node->data.key) {node->right = insert(node->right, key, value, node);}
     else {return node;} // No duplicate keys
     
     //Update height to the larger value
     node->height = 1 + max(height(node->left), height(node->right));
     
     //Balance tree
     int balance = getBalance(node);
     
     //Balance > 1
     if (balance > 1 && key < node->left->data.key)
         return rightRotate(node);

     //Balance < -1
     if (balance < -1 && key > node->right->data.key)
         return leftRotate(node);

     //Left Right Case
     if (balance > 1 && key > node->left->data.key) {
         node->left = leftRotate(node->left);
         return rightRotate(node);
     }

     //Right Left Case
     if (balance < -1 && key < node->right->data.key) {
         node->right = rightRotate(node->right);
         return leftRotate(node);
     }

     return node;
 }

// Recursive function
void AVLTree::inorder(const Node* root) {
    if(root != nullptr){
        inorder(root->left);
        cout << root->data.key << " ";
        inorder(root->right);
    }
}

// Recursive function
void AVLTree::preorder(const Node* root) {
    if(root != nullptr){
        cout << root->data.key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive function
void AVLTree::postorder(const Node* root) {
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->data.key << " ";
    }
}

const Node* AVLTree::getRoot(){
    cursor = root;
    return root;
}

void AVLTree::find(int key) {
    go_to_root();
    if(root != nullptr)
        find(root, key);
    else
        std::cout << "It seems that tree is empty, and key not found." << std::endl;
}

// Recursive funtion
void AVLTree::find(Node* root, int key){
    if(root == nullptr){
        cout << "Key not found" << endl;
        return;
    }
    //Recursively call the function until root is the desired node
    if(key < root->data.key) {find(root->left, key);}
    else if(key > root->data.key) {find(root->right, key);}
    else{
        //Point cursor to the desired node
        cursor = root;
        cout << "Key:" << root->data.key << " Value: " << root->data.value << endl;
    }
}

AVLTree::AVLTree(const AVLTree& other) : root(nullptr), cursor(nullptr) {
    root = copy(other.root, nullptr);
    cursor = root;
}

AVLTree::~AVLTree() {
    destroy(root);
    root = nullptr;
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this == &other) return *this;
    destroy(root);
    root = copy(other.root, nullptr);
    cursor = root;
    return *this;
}

// Recursive funtion
Node* AVLTree::copy(Node* node, Node* parent) {
    if(node == nullptr) { return nullptr; }
    
    //Create new node
    Node* newNode = new Node(node->data.key, node->data.value, parent);
    newNode->left = copy(node->left, newNode);
    newNode->right = copy(node->right, newNode);
    newNode->height = node->height;
    
    return newNode;
}

// Recusive function
void AVLTree::destroy(Node* node) {
    if(node){
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

const int& AVLTree::cursor_key() const{
    if (cursor != nullptr)
        return cursor->data.key;
    else{
        std::cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

const Type& AVLTree::cursor_datum() const{
    if (cursor != nullptr)
        return cursor->data.value;
    else{
        std::cout << "looks like tree is empty, as cursor == Zero.\n";
        exit(1);
    }
}

int AVLTree::cursor_ok() const{
    if(cursor == nullptr)
        return 0;
    return 1;
}

void AVLTree::go_to_root(){
    cursor = root;
}

