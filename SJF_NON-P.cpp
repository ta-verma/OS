#include<iostream>

using namespace std;
class SJF
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
		
		friend ostream & operator<<(ostream &O,SJF &F);
		friend istream & operator>>(istream &I,SJF &F);
};
double avg_Tt=0,avg_Wt=0;

istream & operator>>(istream &I,SJF &F)
{
	cout<<"\nEnter Process ID:"; I>>F.PID;
	cout<<"Enter Arrival Time:"; I>>F.At;
	cout<<"Enter Burst Time:"; I>>F.Bt;
	return I;
}

ostream & operator<<(ostream &O,SJF &F)
{
	O<<F.PID<<"\t"<<F.At<<"\t"<<F.Bt<<"\t"<<F.Tt<<"\t"<<F.Wt<<"\n";
	avg_Tt+=F.Tt;
	avg_Wt+=F.Wt;
	return O;
}

void SJF_swap(SJF &A,SJF &B)
{
	SJF T;
	T=A;
	A=B;
	B=T;
}

int SJF :: Ct=0;

int main()
{	int no_p;
	cout<<"Enter number of processes:";
	cin>>no_p;
	
	SJF *S=new SJF[no_p];
	
	for(int i=0;i<no_p;++i)
	{
		cin>>S[i];
	}
	
	for(int i=0;i<no_p;++i)
	{ 
		for(int j=i;j<no_p;++j)
		{
			if(S[i].At>S[j].At)
			SJF_swap(S[i],S[j]);
			else if(S[i].At==S[j].At && S[i].Bt>S[j].Bt)
			SJF_swap(S[i],S[j]);
		}
		
	}
	cout<<"\nPID\tAt\tBt\tTt\tWt\n";
	cout<<"...................................\n";
	for(int i=0;i<no_p;++i)
	{ 
		S[i].clac_Ct();
		S[i].calc_Tt();
		S[i].clac_Wt();
		for(int j=i+1;j<no_p-1;++j)
		{
			if(SJF::Ct>S[j].At && SJF::Ct>S[j+1].At && S[j].Bt>S[j+1].Bt)
			SJF_swap(S[j],S[j+1]);
		}
	}
	
	
	for(int i=0;i<no_p;++i)
	cout<<S[i];
	cout<<"\n\nAverage Turn-around Time:"<<avg_Tt/no_p;
	cout<<"\nAverage Waiting Time:"<<avg_Wt/no_p;
	
	return 0;
}
