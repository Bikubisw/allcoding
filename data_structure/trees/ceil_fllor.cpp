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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int ceilval=INT_MAX;
int fllorval=INT_MIN;
template<typename T>
class TreeNode{
public:
	int data;
	vector<TreeNode<T>*> children;
	TreeNode(T data){
		this->data=data;
	}
	~TreeNode(){
		for(int i=0;i<children.size();i++){
			delete children[i];
		}
	}

};
TreeNode<int>* takeinput(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		TreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int child;
		cin>>child;
		for(int i=0;i<child;i++){
			int childdata;
			cin>>childdata;
			TreeNode<int>*childi=new TreeNode<int>(childdata);
			front->children.push_back(childi);
			pendingnodes.push(childi);
		}


	}
	return root;
}
void print(TreeNode<int>* root){
	if(root==NULL)return;
	queue<TreeNode<int>*>pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		TreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++){
			cout<<front->children[i]->data<<",";
			pendingnodes.push(front->children[i]);
		}
		cout<<endl;

	}

}
void ceil_fllor(TreeNode<int>*root,int data){
	if(root->data>data){
		if(root->data<ceilval)ceilval=root->data;
	}
	if(root->data<data){
		if(root->data>fllorval)fllorval=root->data;
	}


for(int i=0;i<root->children.size();i++){
	ceil_fllor(root->children[i],data);
}

}
int main()
{
    IOS;
 	TreeNode<int>*root=takeinput();
 	int data;
 	cin>>data;
 	ceil_fllor(root,data);
 	cout<<"CEIL "<<ceilval<<endl;
 	cout<<"FLOOR "<<fllorval<<endl;
 	delete root;
    return 0;
}