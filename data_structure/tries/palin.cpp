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
	bool checkremainingelements(TrieNode * node,string word){
		if(node->isterminal){
			if(palindromeword(word)){
				return true;
			}
		}
		for(int i=0;i<26;i++){
		TrieNode* child=node->children[i];
		if(child==NULL){
			continue;
		}	
		string fwd=word+child->data;
		if(checkremainingelements(child,fwd)){
			return true;
		}
		}
		return false;	
	}
		bool palindromeword(string s){
		int i=0;
		int j=s.length()-1;
		while(i<j){
			if(s[i]!=s[j]){
				return false;
			}
			i++;j--;
		}
		return true;
	}
	bool ispalindromepair(TrieNode* node,string word,int startindex){
		if(word.length()==0){
			return true;
		}
		if(startindex==(int)word.length()){
			if(node->isterminal==true){
				return true;
			}
			return checkremainingelements(node,"");
		}
		int index=word[startindex]-'a';
		TrieNode* child;
		if(node->children[index]!=NULL){
			child=node->children[index];
		}
		else{
			if(node->isterminal){
				return palindromeword(word.substr(startindex));
			}
			return false;
		}
		return ispalindromepair(child,word,startindex+1);
	}
	bool ispalindromepair(string word){
		return ispalindromepair(root,word,0);
	}
};
string reverse_st(string &s){
	string output="";
	for(int i=(int)s.length()-1;i>=0;i--){
		output+=s[i];
	}
	return output;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<string> st;
    for(int i=0;i<n;i++){
		string s;
		cin>>s;
		st.push_back(s);
	}
	Trie t;
	for(int i=0;i<(int)st.size();i++){
		string output=reverse_st(st[i]);
		t.insert(output);
	}
	bool flag=false;
	for(int i=0;i<(int)st.size();i++){
		if(t.ispalindromepair(st[i])){
			flag=true;
			break;
		}
	}
	cout<<(flag==true?"true\n":"false\n");
	return 0;
}
