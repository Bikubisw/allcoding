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
		data=d;
		children=new TrieNode*[26];
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		isterminal=false;
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
	private:
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
	public:
	void insert(string s){
	insert(root,s);	
	}
	private:
	bool find(TrieNode *node,string s){
		if((int)s.length()==0){
			if(node->isterminal==true||node->isterminal==false){
				return true;
			}
		}
		int index=s[0]-'a';
		TrieNode* child;
		if(node->children[index]!=NULL){
		child=node->children[index];	
		}
		else{
			return false;
		}
		bool ans=find(child,s.substr(1));
		return ans;
		
	}
	public:
	bool find(string s){
	return find(root,s);	
	}
};
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<string>s;
    for(int i=0;i<n;i++){
		string q;
		cin>>q;
		s.push_back(q);
	}
	string patt;
	cin>>patt;
	Trie t;
	for(int i=0;i<(int)s.size();i++){
		int j=0;
		while(j<(int)s[i].length()){
		t.insert(s[i].substr(j));
		j++;	
		}
	}
	if(t.find(patt)){cout<<"true"<<endl;
	}
	else {cout<<"false"<<endl;
	}
    return 0;
}
