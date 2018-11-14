#include<iostream>
using namespace std;
struct priority
{
	       string pr;
	       int at;
	       int bt,bt_1;
	       int ft;
	       int wt;
	       int ta;
	       bool id;
	       static int ct;
	       int prt;
	      
		   friend istream& operator>> (istream& in,priority &ob);
		   friend ostream& operator<< (istream& out,priority &ob);	       	       
	       void cal_ta()
		   {
		   	 ta=ft-at;
		   }
		   void cal_wt()
		   {
		   	wt=ta-bt;
		   }
	       
};
istream& operator>> (istream& in,priority &ob)
{
	cout<<"\nEnter process name: "; in>>ob.pr;
	cout<<"Enter arrival time: "; in>>ob.at;
	cout<<"Enter burst time: ";	in>>ob.bt;
	cout<<"Enter priority: ";	in>>ob.prt;
	ob.bt_1=ob.bt;
    return in; 
}

ostream& operator<< (ostream& out,priority &ob)
{
	cout<<ob.pr<<"\t"<<ob.at<<"\t"<<ob.ft<<"\n";
}
void Myswap(priority &ob,priority &ob1)
{
	priority temp;
	temp=ob;
	ob=ob1;
	ob1=temp;
}
int priority::ct=0;
int main()
{   
	int n;
	cout<<"Enter no of processes ";
	cin>>n;
	priority *ar=new priority[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	for(int i=0;i<n;i++)
	{ 
		for(int j=i+1;j<n;j++)
	    	if(ar[j].at<ar[i].at)
	     		Myswap(ar[j],ar[i]);
	    else if(ar[j].at==ar[i].at)
	     	if(ar[j].bt<ar[i].bt)
		 		Myswap(ar[j],ar[i]);
    }
    priority::ct=ar[0].at;
    int finished=1;
    while(finished<=n)
    {
    	for(int j=0;j<n;j++)
    	 	for(int i=j+1;i<n;i++)
    		{
    	 		if(ar[i].at<=priority::ct )
    	 		{
    	 			if(ar[i].prt<ar[j].prt)
    	 			{
    	 				Myswap(ar[i],ar[j]);
				 	}
			 	}
		 	}
		 	if(ar[0].bt>0 && ar[0].id!=1)
		 	{
		 		priority::ct++;
		 		ar[0].bt--;
		 	}
		 	if(ar[0].bt==0 && ar[0].id==0)
		 	{
		 		finished++;
		 		ar[0].id=1;
		 		ar[0].ft=priority::ct;
		 		ar[0].prt=1000;
		 	}
	}
	
	cout<<"\n\nPID\tAt\tFt\n";
	for(int i=0;i<n;i++)
    cout<<ar[i];
    return 0;
}
