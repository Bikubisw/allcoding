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
	Node(int d){
		data=d;
		next=NULL;
	}
	~Node(){
		delete next;
	}
};
Node* takeinput(int n){
	int data;
	Node *head=NULL;
	Node* tail=NULL;
	while(n--){
		cin>>data;
		Node* newnode=new Node(data);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}else{
			tail->next=newnode;
			tail=newnode;
		}
	}
	return head;
	
}
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
    //IOS;
	int n;
	cin>>n;
	Node* head=takeinput(n);
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	Node* pivot=temp;
	Node*smallhead=NULL;
	Node*smalltail=NULL;
	Node* larhead=NULL;
	Node* lartail=NULL;
	Node*curr=head;
	while(curr!=NULL){
		if(curr->data<=pivot->data){
			smallhead==NULL?smallhead=curr,smalltail=curr:smalltail->next=curr,smalltail=curr;
		}else{
		larhead==NULL?larhead=curr,lartail=curr:lartail->next=curr,lartail=curr;

		}
		curr=curr->next;
	}
	if(lartail!=NULL){
		lartail->next=NULL;
	}
	if(smalltail!=NULL){
		smalltail->next=larhead;
	}
	print(pivot);
	if(smallhead!=NULL){
		delete smallhead;
	}
	if(smallhead==NULL&&larhead!=NULL){
		delete larhead;
	}
    return 0;
}
