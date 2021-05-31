#include <iostream>
#include <string>

using namespace std;
 
int alp[26];
int main() {
	int n;
	cin >> n;
	string str;
	int count = 0;
	while (n--) {
		for (int i = 0; i < 26; i++)  //초기화 
			alp[i] = 0;
		cin >> str;
		int ans = 1;	
		//if(90< str[0] && str[0]>113)
		//	alp[(int)str[0] - 97] = 1;
		for(int i=0; i<str.length();i++){
			int k = str[i] - 97;
			if (alp[k] == 0)
				alp[k] = 1;
			else {
				if(i>0)
					if (str[i-1]!=str[i]) {
					ans = 0;
					break;
				}
			}
		}
		count += ans;
	}
	cout << count;
}
