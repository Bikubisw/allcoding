#include<iostream>
using namespace std;
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
			if(node->isterminal==true){
				return true;
			}else{
				return false;
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
	private:
	 void removeword(TrieNode* node,string s){
		 if((int)s.length()==0){
			 node->isterminal=false;
			 return ;
		 }
		 int index=s[0]-'a';
		TrieNode* child;
		if(node->children[index]!=NULL){
		child=node->children[index];	
		}
		else{
			return;
		}
		removeword(child,s.substr(1));
		if(child->isterminal==false){
			for(int i=0;i<26;i++){
				if(child->children[i]!=NULL){
					return;
				}
			}
			delete child;
			node->children[index]=NULL;
		}
		 
	 }
	 public:
	 void removeword(string s){
		 removeword(root,s);
	 }
	
};
int main(){
	Trie t;
	t.insert("aac");
	t.insert("abe");
	t.insert("adg");
	cout<<(t.find("aac")?"true\n":"false\n");
	
	t.removeword("aac");
	
	cout<<(t.find("aac")?"true\n":"false\n");
	return 0;
}
