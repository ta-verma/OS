#include<iostream>
using namespace std;
class Memory
{
	int *arr;
	int n;
	public:
		Memory(int t)
		{
			n=t;
			arr= new int[n];
		}
		
		~Memory()
		{
			delete []arr;
		}
		void set()
		{
			cout<<"Enter size of Segments of Memory :";
			for(int i=0;i<n;++i)
			{
				cin>>arr[i];
			}
		}
		void a_order()
		{   int temp;
			for(int i=0;i<n;i++)
 			{
				 for(int j=i+1;j<n;j++)
				 {
 					if(arr[i]>arr[j])
 					{
 						temp=arr[i];
 						arr[i]=arr[j];
 						arr[j]=temp;
 					}
 				}
 			}
		}
		void d_order()
		{   int temp;
		for(int i=0;i<n;i++)
 			{
				 for(int j=i+1;j<n;j++)
				 {
 					if(arr[i]<arr[j])
 					{
 						temp=arr[i];
 						arr[i]=arr[j];
 						arr[j]=temp;
 					}
 				}
 			}
		}
		void F_fit()
		{
			char ch1; int temp,t=1,flag=0,sum=0; 
			char ch='y';
			while(ch=='y'||ch=='Y')
			{
				cout<<"\nEnter Process "<<t<<" :";
				cin>>ch1;
				cout<<"\nEnter its size :";
				cin>>temp;
				for(int i=0;i<n;++i)
				{
					if(temp<=arr[i])
					{
						arr[i]=arr[i]-temp;
						cout<<"\nMemory is allocated sucessfully!!";
						flag=1;
						break;
					}
				}
				if(flag==0)
				cout<<"\n Process "<<ch1<<" is waiting....";
				flag=0;
				cout<<"\nDo you want to enter more process (y/n) :";
				cin>>ch;
				++t;
			}
			for(int i=0;i<n;++i) sum=sum+arr[i];
			cout<<"\n Remaing memeory :"<<sum;
			
		}
		
		void B_fit()
		{
			char ch1; int temp,t=1,flag=0,sum=0; 
			char ch='y';
			a_order();
			while(ch=='y'||ch=='Y')
			{
				cout<<"\nEnter Process "<<t<<" :";
				cin>>ch1;
				cout<<"\nEnter its size :";
				cin>>temp;
				for(int i=0;i<n;++i)
				{
					if(temp<=arr[i])
					{
						arr[i]=arr[i]-temp;
						cout<<"\nMemory is allocated sucessfully!!";
						flag=1;
						a_order();
						break;
					}
				}
				if(flag==0)
				cout<<"\n Process "<<ch1<<" is waiting....";
				flag=0;
				cout<<"\nDo you want to enter more process (y/n) :";
				cin>>ch;
				++t;
			}
			for(int i=0;i<n;++i) sum=sum+arr[i];
			cout<<"\n Remaing memeory :"<<sum;
			
		}
		void W_fit()
		{
			char ch1; int temp,t=1,flag=0,sum=0; 
			char ch='y';
			d_order();
			while(ch=='y'||ch=='Y')
			{
				cout<<"\nEnter Process "<<t<<" :";
				cin>>ch1;
				cout<<"\nEnter its size :";
				cin>>temp;
				for(int i=0;i<n;++i)
				{
					if(temp<=arr[i])
					{
						arr[i]=arr[i]-temp;
						cout<<"\nMemory is allocated sucessfully!!";
						flag=1;
						d_order();
						break;
					}
				}
				if(flag==0)
				cout<<"\n Process "<<ch1<<" is waiting....";
				flag=0;
				cout<<"\nDo you want to enter more process (y/n) :";
				cin>>ch;
				++t;
			}
			for(int i=0;i<n;++i) sum=sum+arr[i];
			cout<<"\n Remaing memeory :"<<sum;
			
		}
};

int main()
{   int n;
    cout<<"\nEnter number of memory segment :";
    cin>>n;
	Memory M(n);
	M.set(); int i;
	cout<<"\nMain Menu \n1.First Fit \n2.Best Fit \n3.Worst Fit \n4.Exit \nEnter your choice :";
	cin>>i;
	switch(i)
	{
		case 1: M.F_fit(); break;
		case 2: M.B_fit(); break;
		case 3: M.W_fit(); break;
		default : break;
	}
	
	return 0;
}
