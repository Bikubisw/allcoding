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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int preference(char c){
	if(c=='+'||c=='-'){
		return 1;
	}
	return 2;
}
int main()
{
    IOS;
    string s;
    getline(cin,s);
    stack<string> pre;
    stack<string> post;
    stack<char> ope;
    for(int i=0;i<(int)s.length();i++){
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
		while(!ope.empty()&&ope.top()!='('&&preference(s[i])<=preference(ope.top())){
			char op=ope.top();
			ope.pop();
			string prefix_v2=pre.top();
			pre.pop();
			string prefix_v1=pre.top();
			pre.pop();
			string a;
			a+=op;
			a+=(prefix_v1+prefix_v2);
			pre.push(a);
			string postfix_v2=post.top();
			post.pop();
			string postfix_v1=post.top();
			post.pop();
			a="";
			a+=(postfix_v1+postfix_v2+op);
			post.push(a);
		}
		ope.push(s[i]);
	}else if(s[i]=='('){
		ope.push(s[i]);
	}else if(s[i]==')'){
		while(ope.top()!='('&&!ope.empty()){
		char op=ope.top();
			ope.pop();
			string prefix_v2=pre.top();
			pre.pop();
			string prefix_v1=pre.top();
			pre.pop();
			string a;
			a+=op;
			a+=(prefix_v1+prefix_v2);
			pre.push(a);
			string postfix_v2=post.top();
			post.pop();
			string postfix_v1=post.top();
			post.pop();
			a="";
			a+=(postfix_v1+postfix_v2+op);
			post.push(a);
		
		}
		ope.pop();
		
	}else if(s[i]==' '){
		
		
	}else{
		string a="";
		a+=s[i];
		pre.push(a);
		post.push(a);
	}	
	}
	while(!ope.empty()){
			char op=ope.top();
			ope.pop();
			string prefix_v2=pre.top();
			pre.pop();
			string prefix_v1=pre.top();
			pre.pop();
			string a;
			a+=op;
			a+=(prefix_v1+prefix_v2);
			pre.push(a);
			string postfix_v2=post.top();
			post.pop();
			string postfix_v1=post.top();
			post.pop();
			a="";
			a+=(postfix_v1+postfix_v2+op);
			post.push(a);
	}
	cout<<post.top()<<endl;
	cout<<pre.top()<<endl;
	
    




    return 0;
}
