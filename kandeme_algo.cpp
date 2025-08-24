//kandeme's algorithum use to find the maximum sum of subarray.
#include<iostream>
using namespace std;
int posialgo(int a[],int n){
	int max=INT_MIN,sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>max)max=sum;
		if(sum<0)sum=0;
	}
	return max;
}
int main(){
	int a[10];
	int n;
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=posialgo(a,n);
	cout<<sum;
}

