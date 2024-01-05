// https://practice.geeksforgeeks.org/problems/run-length-encoding/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends

/*You are required to complete this function */
// TC : O(N)
// SC : O(1)
string encode(string s) {    
    int n = s.length();
    int cnt = 1;
    string result;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        }
        else {
            result += s[i-1] + to_string(cnt);
            cnt = 1;
        }
    }
    return result;
}     
 
