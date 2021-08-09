#include <iostream>
#include <queue>
#include<climits>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int>* root,int &k){
	if(root==NULL)return NULL;
	if(root->data==k)return root;

	if(k<root->data){
		return searchInBST(root->left,k);
	}else{
		return searchInBST(root->right,k);
	}

}
int minimumhelper(BinaryTreeNode<int>*root){
	if(root==NULL)return INT_MAX;
	return min(root->data,min(minimumhelper(root->left),minimumhelper(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
	if(root->left==NULL){
		return root->data;
	}
	int min=minimum(root->left);
	return min;

}
int miaximum(BinaryTreeNode<int>* root){
	if(root->right==NULL){
		return root->data;
	}
	int max=miaximum(root->right);
	return max;
}
int main() {
    BinaryTreeNode<int> *root = takeInput();
    // int k;
    // cin >> k;
    // cout << ((searchInBST(root, k)) ? "true" : "false");
    cout<<minimum(root)<<endl;
    cout<<miaximum(root)<<endl;
    delete root;
}