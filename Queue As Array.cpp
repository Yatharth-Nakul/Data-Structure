#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int front=-1,rear=-1,n=50;
int arr[50];
void insert()
{
	int val;
	cout<<" Enter the data to be entered : ";
	cin>>val;
	if(rear==n-1)
	{
		cout<<" Queue Overflow... ";
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		arr[rear]=val;
	}
}

void Delete()
{
	if((front==-1) || (front>rear))
	{
		cout<<" Queue is Empty.....";
	}
	else
	{
		cout<<"\n"<<" "<<arr[front]<<" Deleted..\n";
		front++;
	}
}
void display()
{
	if((front==-1) || (front>rear))
	{
		cout<<" Queue is Empty..";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<" "<<arr[i]<<endl;
		}
	}
}

int main()
{
	int choice;
	//clrscr();
	while(1)
	{
		cout<<"\n";
		cout<<"---------------------------------";
		cout<<"\n 1.Insert";
		cout<<"\n 2.Display";
		cout<<"\n 3.Delete";
		cout<<"\n 4.Exit";
		cout<<"\n---------------------------------";
		cout<<"\n \n Enter Your Choice(1/2/3/4): ";
		cin>>choice;
		switch(choice)
		{
			case 1:insert();break;
			case 2:display();break;
			case 3:Delete();break;
			case 4:exit(0);break;
		}
	}
	//getch();
}
