#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
BinaryTreeNode<int>*buidtree(vector<int>&in,vector<int>&pre,int instart,int inend,int prestart,int preend){
    if(instart>inend){
        return NULL;
    }
    int rootData=pre[prestart];
    int rootindex=-1;
    for(int i=instart;i<=inend;i++){
        if(in[i]==rootData){
            rootindex=i;
            break;
        }
    }
    int leftinstart=instart;
    int leftinend=rootindex-1;
    int leftprestart=prestart+1;
    int leftpreend=leftinend-leftinstart+leftprestart;
    int rightinstart=rootindex+1;
    int rightinend=inend;
    int rightpreend=preend;
    int rightprestart=leftpreend+1;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftans=buidtree(in,pre,leftinstart,leftinend,leftprestart,leftpreend);
    BinaryTreeNode<int>* rightans=buidtree(in,pre,rightinstart,rightinend,rightprestart,rightpreend);
    root->left=leftans;
    root->right=rightans;
    return root;
}
BinaryTreeNode<int>*buildtreeHelper(vector<int>&in,vector<int>&pre,int n){
    return buidtree(in,pre,0,n-1,0,n-1);
}
int main() {
    int n;
    cin>>n;
    vector<int>inorder(n),preorder(n);
    for(auto&it:preorder){
        cin>>it;
    }
    for(auto&it:inorder){
        cin>>it;
    }
    BinaryTreeNode<int>*root=buildtreeHelper(inorder,preorder,n);
    printLevelATNewLine(root);
}