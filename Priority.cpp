#include<iostream>
using namespace std;
struct Priority
{
	char PId[20];
	int bt;
	int pt;
	int ta;
	int wt;
	static int ct;

    friend istream & operator>>(istream & in,Priority &ob);
	friend ostream & operator<<(ostream & out,Priority &ob);

	void calc_ct()
	{
		ct+=bt;
	}

	void calc_ta()
	{
		ta=ct;
	}
	void calc_wt()
	{
		wt=ta-bt;
	}
};

int Priority::ct=0;

void Myswap(Priority &ob1,Priority &ob2)
{
	Priority temp;
	temp =ob1;
	ob1=ob2;
	ob2=temp;
}

istream &operator>>(istream &in,Priority &ob)
{
	cout<<"Enter PId: ";in>>ob.PId;
	cout<<"Enter Priority: ";in>>ob.pt;
	cout<<"Enter BT: ";in>>ob.bt;
	cout<<endl;
	return in;
}

ostream &operator<<(ostream &out,Priority &ob)
{
	out<<"PId: "<<ob.PId<<endl;
	return out;
}

int main()
{
	int n;
	int avgta=0;
	int avgwt=0;
	cout<<"Enter number process:";cin>>n;
	Priority*ob=new Priority[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>ob[i];
	}

	for(int i=0;i<n;i++)
 	{
		for(int j=i;j<n;j++)
  		{
   			if(ob[i].pt<ob[j].pt)
   			{
				Myswap(ob[i],ob[j]);
   			}
   			if(ob[i].pt==ob[j].pt&&ob[i].bt>ob[j].bt)
   			{
			    Myswap(ob[i],ob[j]);		
   			}	
  		}
 	}


	for(int i=0;i<n;i++)
	{
		ob[i].calc_ct();
		ob[i].calc_ta();
		ob[i].calc_wt();
		avgta+=ob[i].ta;
		avgwt+=ob[i].wt;
	}

	for(int i=0;i<n;i++)
	{	
		cout<<ob[i];
 		cout<<"ta: "<<ob[i].ta<<endl;
 		cout<<"wt: "<<ob[i].wt<<endl;
		cout<<endl;
	}

	cout<<"Avg wating time: "<<(avgwt/n)<<endl;
	cout<<"Avg turn around time: "<<(avgta/n)<<endl;

	delete []ob;
	return 0;
}
