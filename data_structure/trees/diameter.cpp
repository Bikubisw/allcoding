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
int dia=0;
int diameter(TreeNode<int>* root){
	int lh=0,slh=0;
	for(int i=0;i<root->children.size();i++){
		int chei=diameter(root->children[i]);
		if(chei>lh){
			slh=lh;
			lh=chei;
		}else if(chei>slh){
			slh=chei;
		}
	}
	if(lh+slh>dia){
		dia=slh+lh;
	}
	return 1+lh;
}
TreeNode<int>* pre=NULL;
TreeNode<int>* succ=NULL;
int state=0;
void pre_succ(TreeNode<int>*root,int data){
	if(state==0){
		if(root->data==data){
			state++;
		}
		else{
			pre=root;
		}
	}else if(state==1){
		succ=root;
		state++;
	}
	 for(int i=0;i<root->children.size();i++){
	 	pre_succ(root->children[i],data);
	 }


}
TreeNode<int>* sumnode=NULL;
int  maxsum=INT_MIN;
int maxumnode(TreeNode<int>*root){
	if(root->children.size()==0){
		return root->data;
	}
	int sum=0;
	for(int i=0;i<root->children.size();i++){
		sum+=maxumnode(root->children[i]);
	}
	if(sum+root->data>maxsum){
		maxsum=sum+root->data;
		sumnode=root;
	}
	return sum+root->data;

}
int main()
{
    IOS;
 	   
    TreeNode<int>*root=takeinputlevelwise();
    // diameter(root);
    // cout<<dia<<endl;
    // int data;
    // cin>>data;
    // pre_succ(root,data);
    // cout<<pre->data<<endl;
    // if(succ!=NULL)cout<<succ->data<<endl;
    maxumnode(root);
    cout<<sumnode->data<<"@"<<maxsum<<endl;
    delete root;
    return 0;
}