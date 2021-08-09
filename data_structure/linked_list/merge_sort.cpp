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
	Node* head=NULL;
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
Node *mid(Node* head){
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node *merge(Node* head1,Node* head2){
	Node *newhead=NULL,*newtail=NULL;
    Node* temp1=head1,*temp2=head2;
    while(temp1!=NULL&&temp2!=NULL){
		if(temp1->data<=temp2->data){
			if(newhead==NULL){
				newhead=temp1;
				newtail=temp1;
			}else{
				newtail->next=temp1;
				newtail=newtail->next;
			}
			temp1=temp1->next;
		}else{
				if(newhead==NULL){
				newhead=temp2;
				newtail=temp2;
			}else{
				newtail->next=temp2;
				newtail=newtail->next;
			}
			temp2=temp2->next;
		}
	}
	if(temp1!=NULL){
		newtail->next=temp1;
	}
	if(temp2!=NULL){
		newtail->next=temp2;
	}
	return newhead;
}
Node *mergesort(Node *head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node* midp=mid(head);
	Node* half1=head;
	Node* half2=midp->next;
	midp->next=NULL;
	half1=mergesort(half1);
	half2=mergesort(half2);
	Node *newhead=merge(half1,half2);
	return newhead;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    Node* head=takeinput(n);
	head=mergesort(head);
	print(head);
    return 0;
}
