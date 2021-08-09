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
int calculate(string s){
	stack<int> st;
	int currnum=0;
	char ope='+';
	for(int i=0;i<(int)s.length();i++){
		char ch=s[i];
		if(isdigit(ch)){
			currnum=(currnum*10)+(ch-'0');
		}if((ch!=' '&&!isdigit(ch))||(i==(int)s.length()-1)){
			if(ope=='+'){
				st.push(currnum);
			}else if(ope=='-'){
				st.push(-currnum);
			}else if(ope=='*'){
				int num=st.top()*currnum;
				st.pop();
				st.push(num);
			}else {
				int num=st.top()/currnum;
				st.pop();
				st.push(num);
			}
			ope=ch;
			currnum=0;
		}
	}
	int ans=0;
	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}
	return ans;
}
int main()
{
    IOS;
    string s;
    cin>>s;
    cout<<calculate(s)<<endl;
    return 0;
}
