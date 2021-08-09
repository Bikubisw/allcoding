#include <iostream>
#include <queue>
#include <vector>
#include<climits>
#include<utility>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
pair<TreeNode<int>*,int> maxSumNodehelper(TreeNode<int>*root){
	if(root==NULL){
	pair<TreeNode<int>*,int> p;
    p.first=NULL;
    p.second=INT_MIN;
        return p;
    
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
	sum+=root->children[i]->data;
    }
    pair<TreeNode<int>*,int> p1;
    p1.first=root;
    p1.second=sum;
    for(int i=0;i<root->children.size();i++){
    	pair<TreeNode<int>*,int> ans=maxSumNodehelper(root->children[i]);
    	if(ans.second>p1.second){
    		p1=ans;
    	}
    }
    return p1;

}

TreeNode<int>*maxSumNode(TreeNode<int>*root){
	return maxSumNodehelper(root).first;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
    delete root;
}