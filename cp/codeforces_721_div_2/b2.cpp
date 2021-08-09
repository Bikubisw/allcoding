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
bool ispalindrome(string &s){
	int i=0;
	int j=(int)s.length()-1;
	while(i<j){
		if(s[i++]!=s[j--])return false;
	}
	return true;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int count0=0;
	for(int i=0;i<(int)s.length();i++){
			if(s[i]=='0')count0++;
	}
		if(ispalindrome(s)){
	//if(count1==n){cout<<"DRAW"<<endl;}
	 if(count0%2!=0&&count0!=1){
		cout<<"ALICE"<<endl;
	}
	else {cout<<"BOB"<<endl;}
    }
		else{
			if(s[n/2]=='0'&&count0==2&&n%2==1){
				cout<<"DRAW"<<endl;
				continue;
			}
			
			cout<<"ALICE"<<endl;
		}





    }
    return 0;
}
