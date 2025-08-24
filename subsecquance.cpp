#include<iostream>
#include<string>
using namespace std;
int main(){
	string s="abc";
	string sub;
	for(int num=0;num<8;num++){
		sub="";
		for(int i=0;i<s.size();i++){
			if(num&(1<<i)){
				sub+=s[i];
			}
		}
		cout<<sub<<endl;
	}
}
