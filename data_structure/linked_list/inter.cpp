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
#define rall(x) (x).rbegin(),(x).rend()
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
int size(Node* head){
	Node*temp=head;
	int c=0;
	while(temp!=NULL){
		++c;
		temp=temp->next;
	}
	return c;
}
Node* intersection(Node* head1,Node* head2){
	if(head1==NULL||head2==NULL)return NULL;
	int s1=size(head1);
	int s2=size(head2);
	Node* biggerlist=s1>s2?head1:head2;
	Node*smallerlist=s1>s2?head2:head1;
	
	int diff=max(s1,s2)-min(s1,s2);
	while(diff--){
		biggerlist=biggerlist->next;
	}
	while(biggerlist!=smallerlist){
		smallerlist=smallerlist->next;
		biggerlist=biggerlist->next;
	}
	return biggerlist;
}
int main()
{
    IOS;
    int n;;
    cin>>n;
    Node* head1=takeinput(n);
    int idx;
    cin>>idx;
    if(idx<0){
		cout<<-1<<endl;
		return 0;
	}
    int m;
    cin>>m;
    Node* head2=takeinput(m);
    Node*curr=head1;
    while(idx--){
		curr=curr->next;
	}
	Node* prev=head2;
	while(prev->next){
		prev=prev->next;
	}
	prev->next=curr;
	Node* ans=intersection(head1,head2);
	cout<<ans->data<<endl;
    return 0;
}
