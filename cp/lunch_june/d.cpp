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
#include <functional>
#include <numeric>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	string s;
	cin>>s;
	if(s[0]!='<'||s[1]!='/'||s[s.length()-1]!='>'){
		cout<<"Error"<<endl;
		continue;
	}
	int c1=0,c2=0,c3=0;
	bool flag=true;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]=='<'&&s[i+1]!='/'){
			flag=false;
			break;	
		}
		else if(s[i]=='>'&&s[i+1]=='/'){
			flag=false;
			break;
		}
		else if(s[i]=='<'){
			c1++;
		}
		else if(s[i]=='/')c2++;
		else if(s[i]=='>')c3++;
		
		else if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')){
			continue;
		}
		else{
			flag=false;
			break;
		}
	}
	if((c1==c2&&c2==c3&&c3==c1)&&flag){
		cout<<"Success"<<endl;
	}else{
			cout<<"Error"<<endl;
	}
	
    }
    return 0;
}
