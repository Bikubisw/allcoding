#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <unordered_set>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
class TrieNode{
	public:
	char data;
	TrieNode** children;
	bool isterminal;
	TrieNode(char d){
		this->data=d;
		children=new TrieNode*[26];
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		this->isterminal=false;
	}
	~TrieNode(){
		for(int i=0;i<26;i++){
			delete children[i];
		}	
		delete[] children;
	}
};
class Trie{
	public:
	TrieNode* root;
	Trie(){
	root=new TrieNode('\0'); 
	}
	~Trie(){
		delete root;
	}
	void insert(TrieNode* node,string s){
		if((int)s.length()==0){
			node->isterminal=true;
			return;
		}
		int index=s[0]-'a';
		TrieNode* child;
		if(node->children[index]==NULL){
		child=new TrieNode(s[0]);
		node->children[index]=child;	
		}
		else{
		child=node->children[index];	
		}
		insert(child,s.substr(1));
	}
	void insert(string word){
		insert(root,word);
	}
	TrieNode* findword(TrieNode*node,string word){
		if(word.length()==0){
			return node;
		}
		int index=word[0]-'a';
		TrieNode*child;
		if(node->children[index]!=NULL){
			child=node->children[index];
		}
		else{
			return NULL;
		}
		TrieNode* ans=findword(child,word.substr(1));
		return ans;
	}
	TrieNode* findword(string word){
		return findword(root,word);
	}
	
};
void printallpossible(TrieNode*root,string patt,string output){
	if(root->isterminal){
		cout<<patt+output<<endl;
	}
	for(int i=0;i<26;i++){
		TrieNode* child=root->children[i];
		if(child!=NULL){
			
			printallpossible(child,patt,output+child->data);
		}
	}
	
}
int main()
{
    IOS;
    int n;
    cin>>n;
    Trie t;
    vector<int> st;
    for(int i=0;i<n;i++){
		string s;
		cin>>s;
		t.insert(s);
	}
	string patt;
	cin>>patt;
	TrieNode* node=t.findword(patt);
	if(node!=NULL){
		printallpossible(node,patt,"");
	}
	  return 0;
}
