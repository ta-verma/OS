#include<iostream>
using namespace std;
class sched
{
public:
	char PID[20];
    int n,bt[10],tat[10],wt[10],rt[10],finish[10],twt,ttat,total;
    void readData();
    void Init();
    void dispTime();
    void computeRR();
};

void sched::readData()
{
    cout<<"Enter no. of processes\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cout<<"\nEnter PID:"; cin>>PID;
    	cout<<"Enter Bt:";	cin>>bt[i];
	}
    
}

void sched::Init()
{
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<n; i++)
 		{
        	rt[i]=bt[i];
        	finish[i]=0;
        	wt[i]=0;
        	tat[i]=0;
        	total+=bt[i];
        }
}

void sched::dispTime()
{
    for(int i=0;i<n;i++)
    {

        twt+=wt[i];
        tat[i]=wt[i]+bt[i];
        ttat+=tat[i];
        cout<<PID<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";

    }

    cout<<"\nAvg Waiting time = "<<(double)twt/n<<"\nAvg Turnaround time = "<<(double)ttat/n<<endl;
}

void sched::computeRR()
{

    readData();
    Init();
    int time=0,j,q,i,dec=0;
    cout<<"Enter the time Quantum:";
    cin>>q;
	while(time!=total)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {

                if(rt[i]<q)  
				{
                    dec=rt[i];
                }
                else {dec=q;}

                rt[i]=rt[i]-dec;
                if(rt[i]==0) 
    			finish[i]=1;
    			
                for(j=0;j<n;j++)
                {
                	if(j!=i && finish[j]==0)
                        wt[j]+=dec;
				}
                    
                time=time+dec;

            }

        }

    }   
	cout<<"\nPID\tBt\t\Tt\tWt\n";                                               
    dispTime();
}
int main()
{
    sched s;
    int ch;
    s.computeRR(); 
}
