#include<iostream>
using namespace std;
struct sjf
{
	char PId[20];
	int bt;
	int at;
	int ta;
	int wt;
	int ft;
	static int ct;

	friend istream & operator>>(istream & in,sjf &ob);
	friend ostream & operator<<(ostream & out,sjf &ob);

	void calc_ta()
	{
		ta=ft-at;
	}

	void calc_wt()
	{
		wt=ta-bt;
	}
};
int sjf::ct=0;

void Myswap(int ar[],int i,int j,sjf &ob1,sjf &ob2)
{
	sjf temp;
	temp =ob1;
	ob1=ob2;
	ob2=temp;
	int temp1;
	temp1=ar[i];
	ar[i]=ar[j];
	ar[j]=temp1;
}

istream &operator>>(istream &in,sjf &ob)
{
	cout<<"Enter PId: ";in>>ob.PId;
	cout<<"Enter Arrival Time: ";in>>ob.at;
	cout<<"Enter Burst Time: ";in>>ob.bt;
	cout<<endl;
	return in;
}

ostream &operator<<(ostream &out,sjf &ob)
{
	
	out<<ob.PId<<"\t"<<ob.at<<"\t"<<ob.bt<<"\t"<<ob.ta<<"\t"<<ob.wt<<endl;
	return out;
}
int main()
{
	int n;
	int sum=0;
	int avgta=0;
	int avgwt=0;
	cout<<"Enter number process:";cin>>n;
	sjf*ob=new sjf[n];
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{	cin>>ob[i];
 		sum+=ob[i].bt;
 		arr[i]=ob[i].bt;
	}

	for(int i=0;i<n;i++)
	{
 		for(int j=i+1;j<n;j++)
		 {
  			if(ob[i].at>ob[j].at)
   				{ 
				   Myswap(arr,i,j,ob[i],ob[j]);
  	 			}
   			else if((ob[i].at==ob[j].at) && (ob[i].bt>ob[j].bt))
			   {
					Myswap(arr,i,j,ob[i],ob[j]);		
   				}		
  
 		}
	}

 for(int i=0;i<n;)
 {
 	if(arr[i]>1)
	{
   		sjf::ct+=1;
   		arr[i]-=1;
  	}
    else if(arr[i]==1)
	{
   		arr[i]=0;
   		sjf::ct+=1;
   		ob[i].ft=sjf::ct;
   		
   		ob[i].calc_ta();
		ob[i].calc_wt();
		
		avgwt+=ob[i].wt;
		avgta+=ob[i].ta;
		i++; 
    }
	for(int j=i+1;j<n;j++)
	{
 		if((sjf::ct>=ob[j].at)&&(arr[i]>arr[j]))
		{
  			Myswap(arr,i,j,ob[i],ob[j]);  
  
  	 	}
    }
 }

	cout<<"\n\nPID\tAt\tBt\tTt\tWt\n";
	for(int i=0;i<n;++i)
	{
       
       cout<<ob[i];
	}
cout<<"\nAvg wating time: "<<(avgwt/n)<<endl;
cout<<"Avg turn around time: "<<(avgta/n)<<endl;
return 0;
}
