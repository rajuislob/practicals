#include <bits/stdc++.h>
using namespace std;
  
// This function adds two binary strings and return
// result as a third string
string addBinary(string A, string B)
{
    // If the length of string A is greater than the length
    // of B then just swap the string by calling the
    // same function and make sure to return the function
    // otherwise recursion will occur which leads to
    // calling the same function twice
    if (A.length() > B.length())
        return addBinary(B, A);
  
    // Calculating the difference between the length of the
    // two strings.
    int diff = B.length() - A.length();
  
    // Initialise the padding string which is used to store
    // zeroes that should be added as prefix to the string
    // which has length smaller than the other string.
    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
  
    A = padding + A;
    string res;
    char carry = '0';
  
    for (int i = A.length() - 1; i >= 0; i--) {
        // This if condition solves 110 111 possible cases
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        // This if condition solves 000 001 possible cases
        else if (A[i] == '0' && B[i] == '0') {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        // This if condition solves 100 101 010 011 possible
        // cases
        else if (A[i] != B[i]) {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
  
    // If at the end there is carry then just add it to the
    // result
    if (carry == '1')
        res.push_back(carry);
    // reverse the result
    reverse(res.begin(), res.end());
  
    // To remove leading zeroes
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}
int main()
{
	int dl;
	int Cl;
	string dataword="";
	
	cout<<"enter dataword\n";
	cin>>dataword;
	cout<<"length of cheksum \n";
	cin>>Cl;
	string *temp,t1="";
	dl=dataword.length();
	if(dl%Cl==0)
	{
		t1=dataword;
		temp=new string[dl/Cl];
	}
	else
	{	
		for(int i=0;i<Cl-(dl%Cl);i++)
		{
			t1+="0";
		}
		t1+=dataword;
		temp=new string[dl/Cl+1];
	}
	for(int i=0;i<t1.length()/Cl;i++)
	{
		temp[i]="";
	}
	int nt =0;
	while(nt<t1.length()/Cl)
	{
		for(int i=nt*Cl;i<(nt+1)*Cl;i++)
		{
			temp[i]+=t1[i];
		}
		nt++;
	}
	nt=1;
	string t2="";
	t2=temp[0];
	while(nt<t1.length()/Cl)
	{
		t2=addBinary(t2,temp[nt]);
		nt++;
	}
}
