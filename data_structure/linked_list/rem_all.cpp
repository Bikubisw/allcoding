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
		this->data=d;
		this->next=NULL;
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
Node*temp=head;
while(temp!=NULL){cout<<temp->data<<" ";temp=temp->next;}
cout<<endl;
}
int main()
{
    //IOS;
    int n;
    cin>>n;
    Node* head=takeinput(n);
    Node *curr=head;
    Node *newhead=NULL,*newtail=NULL;
    while(curr!=NULL){
		if(curr->next!=NULL&&curr->data==curr->next->data){
			Node* tempy=curr;
			while(curr->next!=NULL&&curr->data==curr->next->data){
				curr=curr->next;
			}
			Node* nextv=curr->next;
			while(tempy!=nextv){
				Node*temp=tempy;
				tempy=tempy->next;
				temp->next=NULL;
				delete temp;
			}
			curr=nextv;
		}
		else{
			if(newhead==NULL){
				newhead=curr;
				newtail=curr;
			}else{
				newtail->next=curr;              
				newtail=curr;
			}
			curr=curr->next;
		}
		
	}
	if(newtail!=NULL){
		newtail->next=NULL;
	}
    print(newhead);
    if(newhead!=NULL){
		delete newhead;
	}
    return 0;
}
