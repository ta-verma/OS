#include<iostream>

using namespace std;
class FCFS
{
	public:
		char PID[20];
		int At,Bt;
		int Ft,Tt,Wt;
		static int Ct;
		
		void clac_Ct()
		{
			if(Ct<At)
			{
				cout<<"\tIdeal\n";
				Ct=At;
			}
			Ct+=Bt;
			Ft=Ct;
		}
		
		void calc_Tt()
		{
			Tt=Ft-At;
		}
		
		void clac_Wt()
		{
			Wt=Tt-Bt;
		}
		
		friend ostream & operator<<(ostream &O,FCFS &F);
		friend istream & operator>>(istream &I,FCFS &F);
};
double avg_Tt=0,avg_Wt=0;

istream & operator>>(istream &I,FCFS &F)
{
	cout<<"\nEnter Process ID:"; I>>F.PID;
	cout<<"Enter Arrival Time:"; I>>F.At;
	cout<<"Enter Burst Time:"; I>>F.Bt;
	return I;
}

ostream & operator<<(ostream &O,FCFS &F)
{
	O<<F.PID<<"\t"<<F.At<<"\t"<<F.Bt<<"\t"<<F.Tt<<"\t"<<F.Wt<<"\n";
	avg_Tt+=F.Tt;
	avg_Wt+=F.Wt;
	return O;
}

void FCFS_swap(FCFS &A,FCFS &B)
{
	FCFS T;
	T=A;
	A=B;
	B=T;
}

int FCFS :: Ct=0;

int main()
{	int no_p;
	cout<<"Enter number of processes:";
	cin>>no_p;
	
	FCFS *F=new FCFS[no_p];
	
	for(int i=0;i<no_p;++i)
	{
		cin>>F[i];
	}
	
	for(int i=0;i<no_p;++i)
	{ 
		for(int j=i+1;j<no_p;++j)
		if(F[i].At>F[j].At)
		FCFS_swap(F[i],F[j]);
	}
	cout<<"\nPID\tAt\tBt\tTt\tWt\n";
	cout<<"...................................\n";
	for(int i=0;i<no_p;++i)
	{ 
		F[i].clac_Ct();
		F[i].calc_Tt();
		F[i].clac_Wt();
	}
	
	
	for(int i=0;i<no_p;++i)
	cout<<F[i];
	cout<<"\n\nAverage Turn-around Time:"<<avg_Tt/no_p;
	cout<<"\nAverage Waiting Time:"<<avg_Wt/no_p;
	
	return 0;
}
