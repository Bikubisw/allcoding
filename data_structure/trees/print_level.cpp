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
template <typename T>
class TreeNode{
public:
	T data;
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
TreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*>pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		TreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int childnum;
		cin>>childnum;
		for(int i=0;i<childnum;i++){
			int data;
			cin>>data;
			TreeNode<int>* child=new TreeNode<int>(data);
			front->children.push_back(child);
			pendingnodes.push(child);
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
int countnodes(TreeNode<int>*root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=countnodes(root->children[i]);
	}
	return ans;
}
int sumnnodes(TreeNode<int>* root){
	int sum=root->data;
	for(int i=0;i<root->children.size();i++)sum+=sumnnodes(root->children[i]);

	return sum;
}
int maxdatanode(TreeNode<int>*root){
	int maxvalue=INT_MIN;
	for(int i=0;i<root->children.size();i++){
		int maxi=maxdatanode(root->children[i]);
		maxvalue=max(maxi,maxvalue);
	}
	return max(maxvalue,root->data);
}
int findheight(TreeNode<int> *root){
	int height=0;
	for(int i=0;i<root->children.size();i++){
		int childhei=findheight(root->children[i]);
		height=max(childhei,height);
	}
	return 1+height;
}
void preorder(TreeNode<int>*root){
	cout<<root->data<<endl;
	for(int i=0;i<root->children.size();i++){
		preorder(root->children[i]);
	}
}
void postorder(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		postorder(root->children[i]);
	}
	cout<<root->data<<endl;

}
void printLevelATNewLine(TreeNode<int>*root){
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	pendingnodes.push(NULL);
	while(!pendingnodes.empty()){
		TreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		if(front==NULL){
			if(pendingnodes.empty()){
				break;
			}
			cout<<endl;
			pendingnodes.push(NULL);
			continue;
		}
		cout<<front->data<<" ";
		for(int i=0;i<front->children.size();i++){
			pendingnodes.push(front->children[i]);	
		}
	}
}
void zigzag(TreeNode<int>*root){
stack<TreeNode<int>*> s1;
stack<TreeNode<int>*> s2;
s1.push(root);
while(!s1.empty()||!s2.empty()){
	while(!s1.empty()){
		TreeNode<int>*top=s1.top();
		s1.pop();
		cout<<top->data<<" ";
		for(int i=0;i<top->children.size();i++){
			s2.push(top->children[i]);
		}
	}
	cout<<endl;
		while(!s2.empty()){
		TreeNode<int>*top=s2.top();
		s2.pop();
		cout<<top->data<<" ";
		for(int i=top->children.size()-1;i>=0;i--){
			s1.push(top->children[i]);
		}
	}
	cout<<endl;	
}
}
bool find(TreeNode<int>* root,int data){
	if(root->data==data){
		return true;
	}
	for(int i=0;i<root->children.size();i++){
		bool ans=find(root->children[i],data);
		if(ans){
			return true;
		}
	}
	return false;
}
vector<int>* nodeto_root(TreeNode<int>*root,int k){
if(root->data==k){
	vector<int>*output=new vector<int>();
	output->push_back(root->data);
	return output;
}
for(int i=0;i<root->children.size();i++){

vector<int>*smalloutput=nodeto_root(root->children[i],k);
if(smalloutput!=NULL){
	smalloutput->push_back(root->data);
	return smalloutput;
}
}
return NULL;
}
int main()
{
    IOS;
    
    TreeNode<int>*root=takeinputlevelwise();
    //print(root);
  	//printLevelATNewLine(root);
    // cout<<countnodes(root)<<endl;
    //  // cout<<sumnnodes(root)<<endl;
    //  cout<<findheight(root)<<endl;
    // cout<<maxdatanode(root)<<endl;
    //postorder(root);
    // zigzag(root);
    // int data;
    // cin>>data;
    // if(find(root,data)){
    // 	cout<<"element is present"<<endl;
    // }else cout<<"not Present"<<endl;
    print(root);
    delete root;
    return 0;
}