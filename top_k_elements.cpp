#include<iostream>
#include<vector>
#include <queue> 
#include <functional>
using namespace std;
int main(){
	vector<int>v;
	int n;
	priority_queue< int, vector<int>, greater<int> > pq;
	cout<<"enter the size";
	cin>>n;
	for(int i=0;i<n;i++){
		int ele;
		cout<<"enter the element";
		cin>>ele;
		v.push_back(ele);
	}
	int k;
	cin>>k;
	cout<<"enter the value of k"<<endl;
	for(int i=0;i<k;i++){
		pq.push(v[i]);
	}
	for(int i=k;i<n;i++){
		pq.push(v[i]);
		pq.pop();
	}
	cout<<"the top"<<" "<<k<<" "<<"elements"<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
