#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#include<unordered_set>
#include<set>
#include<cmath>
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
template<typename T>
class Node{
public:
	T data;
	Node<T>* next;
	Node(T data){
		this->data=data;
		next=NULL;
	}
};
template<typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BinaryTreeNode(){
		if(left) delete left;
		if(right) delete right;
	}


};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
struct Pair{
	Node<int>* head;
	Node<int>* tail;
};
Pair constructhelpaer(BinaryTreeNode<int>* root){
	if(root==NULL){
		Pair ans;
		ans.head=NULL;
		ans.tail=NULL;
		return ans;
	}
	Pair leftans=constructhelpaer(root->left);
	Pair rightans=constructhelpaer(root->right);
	Node<int>* newnode=new Node<int>(root->data);
	if(leftans.tail!=NULL){
		leftans.tail->next=newnode;
	}
	newnode->next=rightans.head;
	Pair finalans;
	if(leftans.head!=NULL){
		finalans.head=leftans.head;
	}else{
		finalans.head=newnode;
	}
	if(rightans.tail!=NULL){
		finalans.tail=rightans.tail;
	}else{
		finalans.tail=newnode;
	}
	return finalans;
}
Node<int>* construct(BinaryTreeNode<int>*root){
	Pair ans=constructhelpaer(root);
	return ans.head;
} 
int main()
{
    IOS;
    BinaryTreeNode<int>*root=takeInput();
    Node<int>* head=construct(root);
    while(head!=NULL){
    	cout<<head->data<<" ";
    	head=head->next;
    }
    



    delete root;
    return 0;
}