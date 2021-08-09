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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int canReachhelper(string s,int minjump,int maxjump,int c,vector<int>&store){
	if(c==(int)s.length()-1){
		return 1;
	}
	if(store[c]!=-1){
		return store[c];
	}
	bool ans=false;
	for(int k=c+minjump;k<=c+maxjump;k++){
		if(!ans){
		if(s[k]=='0'){
			if(store[k]!=-1){
			ans=store[k];
			break;
			}else{
				ans=ans||canReachhelper(s,minjump,maxjump,k,store);
			}
		}
	}else{
		break;
	}
	}
	
	return store[c]=ans;
	
}
bool canReach(string s, int minJump, int maxJump) {
	if(s[0]=='1')return false;
	 vector<int> store(s.length(),-1);
     return canReachhelper(s,minJump,maxJump,0,store);
  }
int main()
{
    IOS;
    string s;
    cin>>s;
    int min,maxi;
    cin>>min>>maxi;
    if(canReach(s,min,maxi)){
		cout<<"true"<<endl;
	}else cout<<"false"<<endl;
   
    return 0;
}
