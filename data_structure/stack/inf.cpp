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
stack<char> opeator;
stack<int> operand;
for(int i=0;i<(int)s.length();i++){
	if(s[i]=='('){
		opeator.push(s[i]);
	}else if(s[i]==')'){
		while(opeator.top()!='('&& !opeator.empty()&&operand.size()!=0){
			char c=opeator.top();
			opeator.pop();
			int v2=operand.top();
			operand.pop();
			int v1=operand.top();
			operand.pop();
			int eval=evaluation(c,v1,v2);
			operand.push(eval);
		}
		opeator.pop();
	}else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
		while(!opeator.empty()&&opeator.top()!='('&&preference(s[i])<=preference(opeator.top())){
			char c=opeator.top();
			opeator.pop();
			int v2=operand.top();
			operand.pop();
			int v1=operand.top();
			operand.pop();
			int eval=evaluation(c,v1,v2);
			operand.push(eval);
		}
		opeator.push(s[i]);


	}else if(s[i]==' '){
		
	}
	else {
		operand.push(s[i]-'0');
	}
}
while(!opeator.empty()){
char c=opeator.top();
opeator.pop();
int v2=operand.top();
operand.pop();
int v1=operand.top();
operand.pop();
int eval=evaluation(c,v1,v2);
operand.push(eval);
}
cout<<operand.top()<<endl;


return 0;
}
