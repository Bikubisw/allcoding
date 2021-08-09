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
int main()
{
    IOS;
 int t;
 cin>>t;
 while(t--){
 	int n;
 	cin>>n;
 	vector<int>boy(n),girl(n);
 	for(int i=0;i<n;i++){
 		cin>>boy[i];
 	}
 	for(int i=0;i<n;i++){
 		cin>>girl[i];
 	}
 	sort(boy.begin(),boy.end());
 	sort(girl.begin(),girl.end());
 	vector<int> ans(n);
 	for(int i=0;i<n;i++){
 		ans[i]=boy[i]+girl[i];
 	}
 	unordered_map<int,int> mymap;
 	for(int i=0;i<n;i++){
 		mymap[ans[i]]++;
 	}
 	int fans=mymap[ans[n-1]];
 	int value=ans[n-1];
 	if(n>1){
 	for(int i=n-2;i>=0;i--){
 		if(mymap[ans[i]]<fans){
 			value=ans[i];
 			break;
 		}
 	}
 }
 	cout<<value<<endl;

}

    return 0;
}