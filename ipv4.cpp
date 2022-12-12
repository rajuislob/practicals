#include<iostream>
using namespace std;

void output(string ip )
{
	string net="";
	string bd="";
	int w=0;
	int cn=0;
	int t1=0,t2=0,t3=0,t4=0;
	for(int i=0;i<ip.length();i++)
	{
		if(cn==0)
		{
			if(ip[i] !='.')
			{
				t1=t1*10+(ip[i]-'0');
			}
			else
			{
				cn++;
			}
		}
		else if(cn==1)
		{
			if(ip[i] !='.')
			{
				t2=t2*10+(ip[i]-'0');
			}
			else
			{
				cn++;
			}
		}
		else if(cn==2)
		{
			if(ip[i] !='.')
			{
				t3=t3*10+(ip[i]-'0');
			}
			else
			{
				cn++;
			}
		}
		else if(cn==3)
		{
			if(ip[i] !='.')
			{
				t4=t4*10+(ip[i]-'0');
			}
			else
			{
				cn++;
			}
		}
	}
	if(t1>=0 && t1<=127)
	{
		cout<<"class A \n";
		cout<<"network ip : "<<t1<<".0.0.0\n";
		cout<<"broadcast ip : "<<t1<<".255.255.255\n";
	}
	else if(t1>=128 && t1<=191)
	{
		cout<<"class B \n";
		cout<<"network ip : "<<t1<<"."<<t2<<".0.0\n";
		cout<<"broadcast ip : "<<t1<<"."<<t2<<".255.255\n";
	}
	else if(t1>=192 && t1<=223)
	{
		cout<<"class C \n";
		cout<<"network ip : "<<t1<<"."<<t2<<"."<<t3<<".0\n";
		cout<<"broadcast ip : "<<t1<<"."<<t2<<"."<<t3<<".255\n";
	}
	else if(t1>=224 && t1<=239)
	{
		cout<<"class D \n";
		cout<<"no network id and brodcast ip\n";
	}
	else if(t1>=240 && t1<=255)
	{
		cout<<"class E \n";
		cout<<"reerved for future use\n";
	}
	else
	{
		cout<<"invalid ip";
	}
	
}
int main()
{
	output("192.168.13.0");
}
