#include<iostream>
using namespace std;

string zor(string s1,string s2)
{
	string s3="";
	for(int i=1;i<s1.length();i++)
	{
		if(s1[i]==s2[i])
		{
			s3+="0";
		}
		else
		{
			s3+="1";
		}
	}
	return s3;
}
string div(string dataword,string polynomial)
{
	int dsize=polynomial.length();
	string step=dataword.substr(0,dsize);
	int size=polynomial.length();
	while(dsize<size)
	{
		if(step[0]=='1')
		{
			step=zor(polynomial,step)+dataword[dsize];
		}
		else
		{
			step=zor(string(dsize,'0'),step)+dataword[dsize];
		}
		dsize++;
	}
	if(step[0]=='1')  
	{
		step=zor(polynomial,step);
	}
	else
	{
		step=zor(string(dsize,'0'),step);
	}
	cout<<"\ncrc is :"<<step<<"\n";
	return step; 
}
void encodedata(string data,string key)
{
	string data1=data+string(key.length()-1,'0');
	string crc=div(data1,key);
	string encodeddata=data+crc;
	cout<<"encoded data "<<encodeddata;
}
int main()
{
	encodedata("1101","1001");
}
