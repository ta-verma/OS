#include<bits/stdc++.h>
using namespace std;

void allocateMemory(int &memorySize, int &pageSize, int &numFrames, int * &memory, int &freeFrames)
{
	cout<<"\nEnter memory size:";
	cin>>memorySize;
	cout<<"Enter Page size:";
	cin >> pageSize;
	numFrames=(memorySize/pageSize);
	freeFrames=numFrames;
	memory=new int[numFrames*2];
	for(int i=0;i<numFrames;i++)
	 {
		memory[2*i]=memory[2*i+1]=-1;
	}
}
void enterProcess(int & pid,int &pSize,int &pPages,const int &pageSize) {
	cout<<"\nEnter Process ID :";
	cin>>pid;
	cout<<"Enter Process size :";
	cin>>pSize;
	
	pPages=pSize/pageSize;
	if(pSize%pageSize!= 0)
	 {
		pPages++;
	}
}

void allocateProcess(const int &pageSize,const int &numFrames,int *&memory, int &freeFrames)
 {
	int pid,pSize,pPages;
	enterProcess(pid,pSize,pPages,pageSize);
	
	if (freeFrames==0||pPages>freeFrames)
	 {
		cout<<"\nFrames cannot be allocated to this Process";
	}
	else{
		srand(time(NULL));
		int randomFrame;
		for(int i = 0;i<pPages;i++)
		 {
			do
			{
				randomFrame=(rand()%numFrames)*2; 
			} 	while(memory[randomFrame]!=-1);
			memory[randomFrame]=pid;
			memory[randomFrame+1]=i;
		}
		freeFrames-=pPages;
	}
}

void deallocate(const int &numFrames,int *&memory, const int &pid) 
{
	bool flag=true;
	for (int i=0;i<numFrames;i++)
	 {
		if(memory[2*i]==pid)
		 {
			memory[2*i]=memory[2*i+1]=-1;
			flag=false;
		}
	}
	if(flag){
		cout<<"Invalid process ID";
	}
}

void disp(const int & numFrames,int * & memory,const int & pid,const int & page)
 {
	
	cout<<"\n\tProcess ID\t\tPage\t\t\tFrame"<<endl;
	bool flag=true;
	for(int i = 0;i<numFrames;i++) {
		if (flag && (memory[2*i]==pid) && (memory[2*i+1]==page))
		 {
			cout<<"  \t  "<< memory[2*i]<<"\t\t\t "<<memory[2*i+1]<<"\t\t\t "<<i<<endl;
			flag=false;
		}
	}
	if (flag)
	{
		cout<<"Invalid input";
	}
}

void display(const int & numFrames, int * & memory) {
	cout << "\n\tProcess ID\t\tPage\t\t\tFrame" << endl;
	for (int i = 0; i < numFrames; i++) {
		if (memory[2 * i] != -1) {
			cout << "  \t  " << memory[2 * i] << " \t\t\t " << memory[2 * i + 1] << " \t\t\t " << i << endl;
			
		}
	}
}

int main() {
	bool flag1 = true;
	int option;
	while (flag1) {
		cout <<  "\n\n1.Paging";
		cout << "\n0.Exit";
		cout << "\nEnter option...";
		cin >> option;
		switch (option) {
			case 1: {
				int memorySize, pageSize, numFrames, * memory, freeFrames;
				allocateMemory(memorySize, pageSize, numFrames, memory, freeFrames);
				
				bool flag2 = true;
				while (flag2) {
					cout << "\n\n1.Allocate Process";
					cout << "\n2.Deallocate Process";
					cout << "\n3.Display frame no. for the corresponding pid and its page";
					cout << "\n4.Display Page Table";
					cout << "\n5.Previous menu";
					cout << "\n0.Exit";
					cout << "\nEnter option...";
					cin >> option;
					switch (option) {
						case 1: {
							allocateProcess(pageSize, numFrames, memory, freeFrames);
							break;
						}
						
						case 2: {
							cout << "Enter process id : ";
							int pid;
							cin >> pid;
							deallocate(numFrames, memory, pid);
							break;
						}
						
						case 3: {
							cout << "Enter process id : ";
							int pid;
							cin >> pid;
							cout << "Enter Page no. : ";
							int page;
							cin >> page;
							disp(numFrames, memory, pid, page);
							break;
						}
						case 4: {
							display(numFrames, memory);
							break;
						}
						
						case 0: {
							flag1 = false;
						}
						
						case 5: {
							flag2 = false;
							delete []memory;
							break;
						}
					}
				}
				break;
			}
			
			case 0: {
				flag1 = false;
				break;
			}
		}
	}
	return 0;
}
