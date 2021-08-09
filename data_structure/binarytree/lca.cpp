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
BinaryTreeNode<int>* lca(BinaryTreeNode<int>*root,int a,int b){
	if(root==NULL)return NULL;
	if(root->data==a||root->data==b){
		return root;
	}
	BinaryTreeNode<int>*leftans=lca(root->left,a,b);
	BinaryTreeNode<int>* rightans=lca(root->right,a,b);
	if(leftans==NULL&&rightans==NULL)return NULL;
	else if(leftans!=NULL&&rightans==NULL)return leftans;
	else if(rightans!=NULL&&leftans==NULL)return rightans;
	else return root;

}
int main()
{
    IOS;
    BinaryTreeNode<int>* root=takeInput();
    int n1,n2;
    cin>>n1>>n2;
    BinaryTreeNode<int>*node=lca(root,n1,n2);
    if(node!=NULL){
    	cout<<node->data<<endl;
    }else{
    	cout<<-1<<endl;
    }
   
    return 0;
}