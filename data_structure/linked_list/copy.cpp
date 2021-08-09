#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
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
#define dbg(x) cerr<<"["<<x<<"]"<<","<<endl;
#define dbg1(x,y) cerr<<"["<<x<<","<<y<<"]"<<","<<endl;
#define all(x) (x).begin(),(x).end()
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
struct Node{
	int data;
	Node* next;
	Node* random;
	Node(int d){
		this->data=d;
		this->next=NULL;
		this->random=NULL;
	}
	~Node(){
		delete next;
	}
};
int main()
{
    //IOS;
    int n;
    cin>>n;
    vector<Node*>arr(n);
    Node *prev=NULL;
    for(int i=0;i<n;i++){
		arr[i]=new Node(0);
		if(prev!=NULL){
			prev->next=arr[i];
		}
		prev=arr[i];
	}
	for(int i=0;i<n;i++){
		int val,idx;
		cin>>val>>idx;
		arr[i]->data=val;
		if(idx!=-1){
			arr[i]->random=arr[idx];
		}
	}
	Node* head=arr[0];
	unordered_map<Node*,Node*>mp;
	Node* newhead=NULL;
	Node* newtail=NULL;
		Node* curr=head;
		while(curr!=NULL){
		Node* newnode=new Node(curr->data);
		if(newhead==NULL){
			newhead=newnode;
			newtail=newnode;
		}else{
			newtail->next=newnode;
			newtail=newnode;
		}
		mp[curr]=newnode;
		curr=curr->next;
	}
	Node* chead=newhead;
	Node* ohead=head;
	while(chead!=NULL){
		if(ohead->random!=NULL){
			chead->random=mp[ohead->random];
		}
		ohead=ohead->next;
		chead=chead->next;
	}
	Node*p=newhead;
	while(p!=NULL){
		cout<<(p->random!=NULL?"("+to_string(p->data)+", "+to_string(p->random->data)+")":"("+to_string(p->data)+", "+"-1"+")")<<" ";
		p=p->next;
	}
	cout<<endl;
	delete head;
	delete newhead;

    return 0;
}
