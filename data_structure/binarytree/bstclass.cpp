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
#include <cassert>
#include <utility>
#include <unordered_set>
#include <set>
#include<cmath>
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
template <typename T>
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
		if(right)delete right;
	}
};
template<typename T>
class BST{
	BinaryTreeNode<int>* root;
	BST(){
		root==NULL;
	}
	~BST(){
		delete root;
	}
private:
	void printtree(BinaryTreeNode<int>* node){
		if(node==NULL)return;
		cout<<node->data<<":";
		if(node->left){
			cout<<node->left->data<<",";
		}else{
			cout<<-1<<",";
		}
		if(node->right)cout<<node->right->data<<endl;
		else cout<<-1<<endl;

		printtree(node->left);
		printtree(node->right);
	}
public:
	void printtree(){
		printtree(root);
	}
private:
		bool hasdata(int val,BinaryTreeNode<int>*node){
			if(node==NULL)return false;
			if(node->data==val)return true;
			else if(val<node->data){
				return hasdata(val,root->left);
			}else{
				return hasdata(val,root->right);
			}
		}
public:
	bool hasdata(int val){
		return hasdata(val,root);
	}
private:
	void insertdata(int data,BinaryTreeNode<int>*node){
		if(node==NULL){
			BinaryTreeNode<int>*newnode=new BinaryTreeNode<int>(data);
			return newnode;
		}
		if(data<root->data){
			node->left=insertdata(data,node->left);
		}else{
			node->right=insertdata(data,node->right);
		}
		return node;
	}
public:
	void insertdata(int data){
		this->root=insertdata(data,root);
	}
private:
	BinaryTreeNode<int>* deletedata(BinaryTreeNode<int>*node,int data){
		if(node==NULL)return NULL;
		if(node->data<data){
			node->right=deletedata(node->right,data);
			return node;
		} 
		if(node->data>data){
			node->left=deletedata(node->left,data);
			return node;
		}
		else{
			if(node->left==NULL&&node->right==NULL){
				delete node;
				return NULL;
			}
			else if(node->left!=NULL){
				BinaryTreeNode<int>*temp=node->left;
				node->left=NULL;
				delete node;
				return temp;
			}else if(node->right!=NULL){
			BinaryTreeNode<int>*temp=node->right;
				node->right=NULL;
				delete node;
				return temp;
			}else{
				BinaryTreeNode<int>*minnode=node->right;
				while(minnode!=NULL){
					minnode=minnode->left;
				}
				node->data=minnode->data;
				node->right=deletedata(node->right,minnode->data);
				return node;
			}
		}
	}
public:
	void deletedata(int data){
		this->root=deletedata(root,data);
	}


};
int main()
{
    IOS;
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
    return 0;
}