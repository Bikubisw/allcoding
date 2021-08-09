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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int solution(string *arr,int*score,int *farr,int n){
	if(n==0)return 0;
	
	int smallans1=solution(arr+1,score,farr,n-1);
	bool flag=true;
	int sword=0;
	for(int i=0;i<(int)arr[0].length();i++){
		char ch=arr[0][i];
		if(farr[ch-'a']==0){
			flag=false;
		}
		--farr[ch-'a'];
		sword+=score[ch-'a'];
	}
	int smallans2=0;
	if(flag){
		smallans2=sword+solution(arr+1,score,farr,n-1);
	}
	for(int i=0;i<(int)arr[0].length();i++){
		char ch=arr[0][i];
		++farr[ch-'a'];
	}
	return max(smallans1,smallans2);
}
int main()
{
    IOS;
	int n;
	cin>>n;
	string *arr=new string[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}
	int l;
	cin>>l;
	int farr[26]={0};
	for(int i=0;i<l;i++){
		char c;cin>>c;
		++farr[c-'a'];
	}
	int score[26];
	for(int i=0;i<26;i++){
		cin>>score[i];
	}
	cout<<solution(arr,score,farr,n)<<endl;	
	delete[] arr;
    return 0;
}
