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
#include<unordered_set>
#include<set>
#include<cmath>
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
int main()
{
    IOS;
 	string s;
 	getline(cin,s);
 	string output="";
 	for(int i=0;i<s.length();i++){
 		if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'||(s[i]>='0'&&s[i]<='9'))){
 			if(s[i]>='A'&&s[i]<='Z'){
 				s[i]=s[i]-'A'+'a';
 			}
 			output+=s[i];
 		}
 	}   
 	cout<<output<<endl;
 	int i=0;
 	int j=output.length()-1;
 	while(i<j){
 		if(s[i]!=s[j]){
 			return false;
 		}
 		i++;
 		j--;
 	}
 	return true;




    return 0;
}