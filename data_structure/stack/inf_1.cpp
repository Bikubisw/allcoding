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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int preference(char c){
	if(c=='+'||c=='-'){
		return 1;
	}
	return 2;
}
int evaluation(char c,int v1,int v2){
	if(c=='+'){
		return v1+v2;
	}else if(c=='-'){
		return v1-v2;
	}else if(c=='*'){
		return v1*v2;
	}
	return v1/v2;
}
int main(){
IOS;
string s;
getline(cin,s);
stack <int> operand;
stack<char> operator1;
for(int i=0;i<(int)s.length();i++){
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			while(!operator1.empty()&&operator1.top()!='('&&preference(s[i])<=preference(operator1.top())){
			char ope=operator1.top();
			operator1.pop();
			int  v2=operand.top();
			operand.pop();
			int  v1=operand.top();
			operand.pop();
			int ans=evaluation(ope,v1,v2);
			operand.push(ans);
			}
			operator1.push(s[i]);
		
	}else if(s[i]=='('){
		operator1.push(s[i]);
		
	}else if(s[i]==')'){
		while(operator1.top()!='('&&!operator1.empty()){
			char ope=operator1.top();
			operator1.pop();
			int  v2=operand.top();
			operand.pop();
			int  v1=operand.top();
			operand.pop();
			int ans=evaluation(ope,v1,v2);
			operand.push(ans);
		}
		operator1.pop();
		
	}else if(s[i]==' '){
		
		
	}
	else {
		operand.push(s[i]-'0');
	}
}
while(!operator1.empty()){
	     char ope=operator1.top();
			operator1.pop();
			int  v2=operand.top();
			operand.pop();
			int  v1=operand.top();
			operand.pop();
			int ans=evaluation(ope,v1,v2);
			operand.push(ans);
}
cout<<operand.top()<<endl;

return 0;
}

