#include<bits/stdc++.h>
using namespace std;
class segmentTree{
	private:
		vector<int>segtree;
	public:
		segmentTree(int n){
				segtree.resize(4*n);
	}
	//adding the element in a tree from
	void add(int index,int start,int end,vector<int>&arr)
	{
		//adding the number into segtree tree by base 
		if(start==end){
			segtree[index]=arr[end];
		}
		int mid=(start+end)/2;
		add(2*index+1,start,mid,arr);
		add(2*index+2,mid+1,end,arr);
		segtree[index]=segtree[2*index+1]+segtree[2*index+2];
		
	}
	//rangsum return the sum
	int rangesum(int ql,int qr,int start,int end,int index)
	{
		//there is no overlap in the arry
		if(ql>end||qr<start)
		{
			return -1;          
		}
	}
	
};
int main()
{
	segmentTree s(5);
	vector<int>arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	add(0,0,n-1,arr);
	int l,r;
	cin>>l>>r;
	rangesum(l,r,0,n-1,0);
}
