#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* left, *right;
};

template <typename T>
class BinaryTree{
public:
    BinaryTree();
    BinaryTree(node<T>* const&);
    BinaryTree(const BinaryTree&);
    BinaryTree& operator=(const BinaryTree&);
    ~BinaryTree();
    
    bool empty() const;
    node<T>* getRoot() const;
    T rootTree() const;
        
    BinaryTree leftBinaryTree() const;
    BinaryTree rightBinaryTree() const;
        
    void prettyPrint();

private:
    node<T>* root;
    
    void copyBinaryTree(const BinaryTree&);
    void copyBinaryTreeHelper(node<T>*&, node<T>* const&);
    
    void deleteBinatyTree(node<T>*&);
    
    void prettyPrintHelper(node<T>*, int);
};

template <typename T>
void BinaryTree<T>::copyBinaryTree(const BinaryTree<T>& other){
    copyBinaryTreeHelper(root, other.root);
}

template <typename T>
void BinaryTree<T>::copyBinaryTreeHelper(node<T>*& currentRoot, node<T>* const& other){
    currentRoot=NULL;
    if(other){
        currentRoot=new node<T>;
        assert(currentRoot!=NULL);
        currentRoot->inf=other->inf;
        copyBinaryTreeHelper(currentRoot->left, other->left);
        copyBinaryTreeHelper(currentRoot->right, other->right);
    }
}

template <typename T>
void BinaryTree<T>::deleteBinatyTree(node<T>*& currentRoot){
    if(currentRoot){
        deleteBinatyTree(currentRoot->left);
        deleteBinatyTree(currentRoot->right);
        delete currentRoot;
        currentRoot=NULL;
    }
}

template <typename T>
void BinaryTree<T>::prettyPrintHelper(node<T>* currentRoot, int level){
    if(currentRoot == nullptr){
        return;
    }
    prettyPrintHelper(currentRoot->right,level+1);
    cout<< setw(level*2) << " " << currentRoot->inf<<endl;
    prettyPrintHelper(currentRoot->left, level+1);
}

template <typename T>
BinaryTree<T>::BinaryTree(){
    root=NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(node<T>* const& r){
    copyBinaryTreeHelper(root, r);
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other){
    copyBinaryTree(other);
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other){
    if(this!=&other){
        deleteBinatyTree(root);
        copyBinaryTree(other);
    }
    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
    deleteBinatyTree(root);
}

template <typename T>
bool BinaryTree<T>::empty() const{
    return root==NULL;
}

template <typename T>
node<T>* BinaryTree<T>::getRoot() const{
    return root;
}

template <typename T>
T BinaryTree<T>::rootTree() const{
    return root->inf;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::leftBinaryTree() const{
    return root->left;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::rightBinaryTree() const{
    return root->right;
}

template <typename T>
void BinaryTree<T>::prettyPrint(){
    prettyPrintHelper(root, 0);
}
