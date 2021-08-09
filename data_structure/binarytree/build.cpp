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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
template<typename T>
class BianaryTreeNode{
public:
	T data;
	BianaryTreeNode<T>* left;
	BianaryTreeNode<T>* right;
	BianaryTreeNode(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BianaryTreeNode(){
		delete left;
		delete right;
	}

};
BianaryTreeNode<int>* takeinput(){
	int rootdata;
	cout<<"Enter rootdata: ";
	cin>>rootdata;
	BianaryTreeNode<int>*root=new BianaryTreeNode<int>(rootdata);
	if(rootdata==-1){
		return NULL;
	}
	BianaryTreeNode<int>* left=takeinput();
	BianaryTreeNode<int>* right=takeinput();
	root->left=left;
	root->right=right;
	return root;
}
void print(BianaryTreeNode<int>* root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<":";
	if(root->left){
		cout<<root->left->data<<" ";
	}
	if(root->right){
		cout<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
BianaryTreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	BianaryTreeNode<int>* root=new BianaryTreeNode<int>(rootdata);
	queue<BianaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		BianaryTreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int lchild,rchild;
		cin>>lchild;
		if(lchild!=-1){
			BianaryTreeNode<int>* lnode=new BianaryTreeNode<int>(lchild);
			front->left=lnode;
			pendingnodes.push(lnode);
		}
		cin>>rchild;
		if(rchild!=-1){
			BianaryTreeNode<int>* rnode=new BianaryTreeNode<int>(rchild);
			front->right=rnode;
			pendingnodes.push(rnode);
		}

	}
	return root;


}
void printlevel(BianaryTreeNode<int>* root){
	queue<BianaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		BianaryTreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left){
			cout<<"L->"<<front->left->data<<",";
			pendingnodes.push(front->left);
		}else{
			cout<<"L->"<<-1<<",";
		}
		if(front->right){
			cout<<"R->"<<front->right->data<<endl;
			pendingnodes.push(front->right);
		}else{
			cout<<"R->"<<-1<<endl;
		}

	}

}
int size(BianaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int ans=size(root->left)+size(root->right);
	return 1+ans;
}
int sum(BianaryTreeNode<int>*root){
	if(root==NULL){
		return 0;
	}
	int tsum=sum(root->left)+sum(root->right);
	return root->data+tsum;
}
int maxi(BianaryTreeNode<int>*root){
	if(root==NULL){
		return INT_MIN;
	}
	return max(max(maxi(root->left),maxi(root->right)),root->data);
}
int height(BianaryTreeNode<int>*root){
	if(root==NULL)return 0;
	return 1+max(height(root->left),height(root->right));
}
void printlevelwise(BianaryTreeNode<int>*root){
	queue<BianaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	pendingnodes.push(NULL);
	while(!pendingnodes.empty()){
		BianaryTreeNode<int>*front=pendingnodes.front();
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
		if(front->left){
			pendingnodes.push(front->left);
		}if(front->right){
			pendingnodes.push(front->right);
		}
	}

}
vector<int>* find_node_to_root(BianaryTreeNode<int>*root,int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data==data){
		vector<int> *output=new vector<int>();
		output->push_back(data);
		return output;
	}
	vector<int> *leftoutput=find_node_to_root(root->left,data);
	if(leftoutput!=NULL){
		leftoutput->push_back(root->data);
		return leftoutput;
	}
	vector<int> *rightoutput=find_node_to_root(root->right,data);
	if(rightoutput!=NULL){
		rightoutput->push_back(root->data);
		return rightoutput;
	}
	return NULL;
}
bool find(BianaryTreeNode<int>*root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		return true;
	}
	if(find(root->left,data)||find(root->right,data)){
		return true;
	}
	return false;
}
void printk_level(BianaryTreeNode<int>*root,int k){
	if(root==NULL)return;
	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	printk_level(root->left,k-1);
	printk_level(root->right,k-1);
}
int main()
{
    BianaryTreeNode<int>*root=takeinputlevelwise();
    int k;
    cin>>k;
    printk_level(root,k);
    // int data;
    // cin>>data;
    //printlevel(root);
    // cout<<size(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<<maxi(root)<<endl;
    // cout<<height(root)<<endl;
    //printlevelwise(root);

//     vector<int>* output=find_node_to_root(root,data);
//     if(output!=NULL){
//     for(int i=0;i<output->size();i++){
//     	cout<<output->at(i)<<endl;
//     }
// // }
//     if(find(root,data))cout<<"Element is present"<<endl;
//     else cout<<"NOT preset"<<endl;
    delete root;
    //delete output;
    return 0;

}