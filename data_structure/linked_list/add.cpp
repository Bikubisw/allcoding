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
Node* reverse(Node* head){
	Node* next=NULL;
	Node* prev=NULL;
	Node* curr=head;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
int main()
{
    IOS;
    int n,m;cin>>n;
    Node* head1=takeinput(n);
    cin>>m;
    Node*head2=takeinput(m);
    Node *newhead1=reverse(head1);
    Node* newhead2=reverse(head2);
    Node* temp1=newhead1;
    Node* temp2=newhead2;
    
    Node* newhead=NULL;
    Node* newtail=NULL;
    int carry=0;
    while(newhead1!=NULL||newhead2!=NULL){
		int ans=0;
		if(newhead1!=NULL){
			ans+=newhead1->data;
		}
		if(newhead2!=NULL){
			ans+=newhead2->data;
		}
		ans+=carry;
		carry=ans/10;
		ans=ans%10;
		Node* newnode=new Node(ans);
		if(newhead==NULL){
		newhead=newnode;
		newtail=newnode;	
		}else{
		newtail->next=newnode;
		newtail=newnode;
		}
		newhead1==NULL?newhead1:newhead1=newhead1->next;
		newhead2==NULL?newhead2:newhead2=newhead2->next;
	}
	if(carry){
		Node* newnode=new Node(carry);
		newtail->next=newnode;
}
Node*head=reverse(newhead);
    print(head);
    delete head;
    delete temp1;
    delete temp2;
    return 0;
}
