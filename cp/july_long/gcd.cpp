#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(a<b){
		return gcd(b,a);
	}
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	// for(int i=1;i<=min(a,b);i++){
	// 	if(a%i==0&&b%i==0){
	// 		gcd=i;
	// 	}
	// }
	// cout<<gcd<<"\n";

	return 0;
}
