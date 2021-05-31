#include <iostream>
using namespace std;

int main() {
	int n,a,b;
	cin>>n>>a>>b;
	int round=1;
	while((a+1)/2!=(b+1)/2){	//a,b가 붙을때까지
		a=(a+1)/2;
		b=(b+1)/2;
		round++;
	}
	
	cout<<round;
	
	return 0;
}