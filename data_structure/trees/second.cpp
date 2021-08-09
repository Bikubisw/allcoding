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
struct larNode{
	int lar;
	int slar;
};
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
larNode second_largest(TreeNode<int>*root){
	if(root==NULL){
		larNode p;
		p.lar=INT_MIN;
		p.slar=INT_MIN;
		return p;
	}
	larNode ans;
	ans.lar=root->data;
	ans.slar=INT_MIN;
	for(int i=0;i<root->children.size();i++){
		larNode temp=second_largest(root->children[i]);
		if(ans.lar<temp.lar){
			if(temp.slar==INT_MIN){
				ans.slar=ans.lar;
				ans.lar=temp.lar;
			}else{
				if(ans.lar<temp.slar){
					ans.slar=temp.slar;
					ans.lar=temp.lar;
				}else{
					ans.slar=ans.lar;
					ans.lar=temp.lar;

				}
			}


		}else{
			if(ans.lar!=temp.lar&&(ans.slar==INT_MIN)||(temp.lar>ans.slar)){
				ans.slar=temp.lar;
			}
		}

	}
	return ans;
}

int main()
{
    IOS;
    TreeNode<int>*root=takeInputLevelWise();
    larNode ans=second_largest(root);
    cout<<ans.lar<<" "<<ans.slar<<endl;
    return 0;
}