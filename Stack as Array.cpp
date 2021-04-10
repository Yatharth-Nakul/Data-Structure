#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int top=-1,n=50;
int arr[50];
void push()
{
	int num;
	cout<<"\n Enter the element to push : ";
	cin>>num;
	if(top>=n-1)
	{
		cout<<" Stack is Full......";
	}
	else
	{
		top++;
		arr[top]=num;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<" Stack is Empty";
	}
	else
	{
		cout<<endl<<" "<<arr[top]<<" Deleted..";
		top--;
	}
}
void display()
{
	if (top==-1)
	{
		cout<<" Stack is empty....";
	}
	else
	{
		for(int i=top;i>=0;i--)
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
		cout<<"\n 1.Push";
		cout<<"\n 2.Display";
		cout<<"\n 3.Pop";
		cout<<"\n 4.Exit";
		cout<<"\n---------------------------------";
		cout<<"\n \n Enter Your Choice(1/2/3/4) : ";
		cin>>choice;
		switch(choice)
		{
			case 1:push();break;
			case 2:display();break;
			case 3:pop();break;
			case 4:exit(0);break;
		}
	}
	//getch();
}
