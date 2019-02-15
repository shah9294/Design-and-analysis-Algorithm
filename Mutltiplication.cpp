#include <iostream>
#include<cmath>
using namespace std;

int lgth(int n)
{
	return to_string(n).length();
}

long int shifting(long int num,int shft)
{
	string n=to_string(num);
	for(int i=0;i<shft;i++)
		n+="0";
	return stoi(n);
}

void func(long int &tem,long int &tem2, float  &k,float &lengh, bool &chek,bool kk=true,bool tt=false)
{
	if(chek)
	{
		chek=!chek;
		tem+=tem2;
	}

	if(tt)
		tem2=0;

	if(kk)
	if(lgth(tem)>lengh)
	{
		tem2=tem/k;
		tem=fmod(tem,k);
		chek=!chek;
	}
}

long int mull(long int x,long int y)
{
	if(lgth(x)<=1 && lgth(y)<=1)
	{
		int result=0;
		for (int i=0;i<abs(y);i++)
		{
			result+=abs(x);
		}
		if((x>0 && y<0) || (x<0 && y>0))
		result=result-result-result;   // for changing it into negative number
		return result;
	}

	float length,length1=ceil(lgth(x)/2),length2=ceil(lgth(y)/2),p=1;
	long  int sum=0;
	length=(length1<=length2)?length2:length1;
	p=shifting(p,length);

	long int right1=fmod(x,p), right2=fmod(y,p); 		// fmod to find mod of float number
	long int left1=int(x/p) , left2=int(y/p);
	long int temp=0,temp2=0,temp3=0;
	bool check=false;
	temp=mull(right2,right1);

	if(lgth(temp)>length)
	{
		temp2=temp/p;
		temp=fmod(temp,p);
		check=!check;
	}
	sum+=temp;

	temp=mull(right1,left2);
	func(temp,temp2,p,length,check,false);

	sum+=shifting(temp,length);
	temp=mull(left1,right2);
	func(temp,temp2,p,length,check);
	sum+=shifting(temp,length);

	temp=mull(left1,left2);
	func(temp,temp2,p,length,check,true,true);

	sum+=shifting(temp,length+length);
	if(temp!=0)
	{
		sum+=shifting(temp2,length+length+length);
	}
	return sum;
}

int main()
{
	long int x,y;
	cout<<"enter 1st value :  ";
	cin>>x;
	cout<<"\nenter 2nd value : ";
	cin>>y;
	cout<<"\nresult is :	" <<mull(x,y)<<endl;
}
