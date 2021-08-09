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
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data){
		this->data=data;
	}
};
TreeNode<int>* takeinput(){
	int rootdata;
	cout<<"Enter the root data :";
	cin>>rootdata;
	TreeNode<int>*root=new TreeNode<int>(rootdata);
	int n;
	cout<<"Enter the num of children of "<<rootdata<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int>* child=takeinput();
		root->children.push_back(child);
	}
	return root;

}
void printtree(TreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":" ;
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printtree(root->children[i]);
	}
	
}
int main()
{
    
    TreeNode<int>* root=takeinput();
    printtree(root);

    return 0;
}