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
			tail=newnode;// or tail=tail->next;
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
    IOS;
    int n;
    cin>>n;
    Node* head=takeinput(n);
    Node* ohead=NULL;
    Node* otail=NULL;
    Node* lhead=NULL;
    Node* ltail=NULL;
    Node* twohead=NULL;
    Node* twotail=NULL;
    
    Node*curr=head;
    while(curr!=NULL){
		if(curr->data==0){
		ohead==NULL?ohead=curr,otail=curr:otail->next=curr,otail=curr;
		}else if(curr->data==1){
		lhead==NULL?lhead=curr,ltail=curr:ltail->next=curr,ltail=curr;
		}else{
		twohead==NULL?twohead=curr,twotail=curr:twotail->next=curr,twotail=curr;
		}
		curr=curr->next;
	}
	if(twotail!=NULL){
		twotail->next=NULL;
	}
	if(ltail!=NULL){
		ltail->next=NULL;
	}
	if(otail!=NULL){
		otail->next=lhead;
	}
	if(ltail!=NULL){
		ltail->next=twohead;
	}
	if(ltail==NULL&&otail!=NULL){
		otail->next=twohead;
	}
	if(ohead!=NULL)print(ohead);
	if(lhead!=NULL&&ohead==NULL){
		print(lhead);
	}
	if(ohead==NULL&&lhead==NULL)print(twohead);
	if(ohead!=NULL){
	delete ohead;
	}
	if(lhead!=NULL&&ohead==NULL){
		delete lhead;
	}
	if(ohead==NULL&&lhead==NULL&&twohead!=NULL){
		delete twohead;
	}

    return 0;
}
