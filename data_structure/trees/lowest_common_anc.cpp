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
vector<int>* nodetorootpath(TreeNode<int>* root,int k){

if(root==NULL){
	return NULL;
}
if(root->data==k){
	vector<int>* output=new vector<int>();
	output->push_back(root->data);
	return output;
}
for(int i=0;i<root->children.size();i++){
	vector<int>*small=nodetorootpath(root->children[i],k);
	if(small!=NULL){
		small->push_back(root->data);
		return small;
	}
}
	return NULL;
}
void  removeleves(TreeNode<int>*root){
	for(int i=0;i<root->children.size();i++){
		if(root->children[i]->children.size()==0){
			for(int j=i;j<root->children.size();j++){
				root->children[j]=root->children[j+1];
			}
			root->children.pop_back();
			i--;
		}
	}
	for(int i=0;i<root->children.size();i++){
		removeleves(root->children[i]);
	}

}
void mirrortree(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		mirrortree(root->children[i]);
	}
	reverse(root->children.begin(),root->children.end());


}
int main()
{
    IOS;
    TreeNode<int>*root=takeinput();
    mirrortree(root);
    print(root);
    // removeleves(root);
    // print(root);
    // // int a,b;
    // cin>>a>>b;
   //  vector<int>*output1=nodetorootpath(root,a);
   //  vector<int>* output2=nodetorootpath(root,b);
   //  int i=output1->size()-1;
   //  int j=output2->size()-1;
   //  while(i>=0&&j>=0&&output1->at(i)==output2->at(j)){
   //  	i--;
   //  	j--;
   //  }
    
  	// i++;
  	// j++;
  	// cout<<i+j<<endl;
   //  delete root;
   //  delete output1;
   //  delete output2;
    //10 3 20 30 40 2 50 60 2 70 80 1 90 0 0 0 1 100 2 110 120 0 0 0
    delete root;
    return 0;
}