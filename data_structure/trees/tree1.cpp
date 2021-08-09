#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Treenode{
	public:
		T data;
		vector<Treenode<T>*> child;
		Treenode(T data){
			this->data=data;
		}
};
Treenode<int>* takeinput(){
	int rootdata;
	cout<<"Enter data:"<<endl;
	cin>>rootdata;
	Treenode<int>* root=new Treenode<int>(rootdata);
	int n;
	cout<<"Enter number of child of root data"<<rootdata<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	Treenode<int>* children=takeinput();
	root->child.push_back(children);	
	}
	Treenode<int>* temp=root;
	delete root;
	return temp;	
}
void printTree(Treenode<int>*root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->child.size();i++){
		cout<<root->child[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->child.size();i++){
		printTree(root->child[i]);
	}
}
int countnodes(Treenode<int>*root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans+=countnodes(root->children[i]);
	}
	return ans;
}
int main(){
//	Treenode<int>*root=new Treenode<int>(10);
//	Treenode<int>*node1=new Treenode<int>(20);
//	Treenode<int>*node2=new Treenode<int>(30);
//	Treenode<int>*node3=new Treenode<int>(40);
//	root->child.push_back(node1);
//	root->child.push_back(node2);
//	node1->child.push_back(node3);
	Treenode<int>*root= takeinput();
	printTree(root);
	// TODO delete the tree
	//cout<<countnodes(root)<<endl;
	return 0;
}