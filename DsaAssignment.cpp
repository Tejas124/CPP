#include<iostream>
using namespace std;

struct data
{
    string name;
    int rollno;
    float sgpa;
}A[15];

void getdata(int a)
{
   cout<<"Enter name: ";
   cin>>A[a].name;
   cout<<"Enter Roll no.: ";
   cin>>A[a].rollno;
   cout<<"Enter SGPA: ";
   cin>>A[a].sgpa;
}

void display(int b)
{
    cout<<A[b].name<<"\t"<<A[b].rollno<<"\t\t"<<A[b].sgpa<<endl;
}

void BubbleSort(int a)
{
    struct data temp;
    int i,j;
	for(i=0; i<(a-1); i++)
    {
        for(j=0; j<(a-i-1);j++)
        {
            if(A[j].rollno>A[j+1].rollno)
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    for(int i=0;i<a;i++)
    {
        cout<<A[i].name<<"\t"<<A[i].rollno<<"\t\t"<<A[i].sgpa<<endl;
    }
}


void LinearSearch(int a)
{
    float j;
    cout<<"\n\nEnter SGPA of data you want to search:";
    cin>>j;
    int f=0;
    cout<<"\nNAME\tROLL NO.\n";

    for(int i=0;i<a;i++){
        
        if(A[i].sgpa==j){
            cout<<A[i].name<<"\t"<<A[i].rollno<<endl;
            f=1;
        }
    }

    if(f==0){
        cout<<"Record not found"<<endl;

    }
}

void InsertionSort(int a)
{
    int i,j;
	for(i=1;i<a-1;i++)
    {
		string temp =A[i].name;
		j=i-1;
		while(j>=0 && temp<A[j].name)
		{
            A[j+1].name=A[j].name;
            j--;
		}
		A[j+1].name=temp;
		
	}
	for(i=0;i<a;i++)
    {
        cout<<A[i].name<<"\t"<<A[i].rollno<<"\t\t"<<A[i].sgpa<<endl;
    }   
}


void binary(int a)
{
    string SearchName;
    cout<<"\nEnter the name: ";
    cin>>SearchName;
    int low=0;
    int high=a-1;
    
    int start=-1;
    int end=-1;
   
    
    while(low<=high){
        
        int mid=(low+high)/2;

        if(A[mid].name==SearchName){
            start=mid;
            high=mid-1;
        }

        else if(A[mid].name>SearchName){
            high=mid-1;
        }

        else{
            low=mid+1;
        }

        
    }

    low=0;
    high=a-1;
        

    while(low<=high){
        
        int mid=(low+high)/2;

        if(A[mid].name==SearchName){
            end=mid;
            low=mid+1;
        }

        else if(A[mid].name>SearchName){
            high=mid-1;
        }

        else{
           low=mid+1; 
          }
    } 
        if(start!=-1 && end!=-1)
        {
            for(int j=start; j<=end; j++)
            {
                cout<<A[j].name<<"\t"<<A[j].rollno<<"\t\t"<<A[j].sgpa;
            }
        }
    }


int partition(struct data A[15],int left,int right)
{
    int pivot=A[left].sgpa;
    int i = left+1;
    int j = right;
    do{
        while (A[i].sgpa<=pivot && i<=right)
        {
            i++;
        }
        while (A[j].sgpa>pivot)
        {
            j--;
        }
        if(i<j)
        {
            struct data o=A[i];
            A[i]=A[j];
            A[j]=o;
        }
    }while(i<j);
    
    struct data temp=A[left];
    A[left]=A[j];
    A[j]=temp;
    return j;
}

void QuickSort(struct data A[15],int left,int right)
{
    if(left<right)
    {
        int partitionIndex=partition(A,left,right);
        QuickSort(A,left,partitionIndex-1);
        QuickSort(A,partitionIndex+1,right);
    }
}

int main()
{
    string SearchName;
    int a;
    cout<<"Enter the no. of records: "<<endl;
    cin>>a;

    while(true)
    {
        cout<<"\n1.Enter Records \n2.Display Records\n3.Search Records by SGPA\n4.Bubble Sort(roll no)\n5.Insertion Sort(Through Names)\n6.Binary Search\n7.Quick Sort\n8.Exit"<<endl;
        int ch;
        cout<<"Enter ur Choice: ";
        cin>>ch;
        struct data A[a];

        switch(ch)
        {
            case 1:
                 
                for(int i=0;i<a;i++){
                getdata(i);
                }
                break;

            case 2:
                cout<<"\nNAME\tROLL NO.\tSGPA\n";
               	for(int i=0;i<a;i++){
                    display(i);
                }
                break;   

            case 3:
                LinearSearch(a);
                break;
                 
            case 4:
                cout<<"\nNAME\tROLL NO.\tSGPA\n";
                BubbleSort(a);
               	break; 

            case 5:
                cout<<"\nNAME\tROLL NO.\tSGPA\n";
                InsertionSort(a);
               	break;

            case 6:
                cout<<"\nNAME\tROLL NO.\tSGPA\n";
                binary(a);
                break;

            case 7:
                QuickSort(A,0,a-1);
                for(int i=a-1;i>=0;i--){
                    display(i);
                }
                
                break;
       

            case 8: exit(0);

            
            default:
            cout<<"INVALID INPUT"<<endl;

        }
    }
    return 0;
}