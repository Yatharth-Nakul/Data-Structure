#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
class node
{
	int data;
	node *next;
	public:
	void insert();
	void display();
	void Delete();
};
node *start=NULL;
void node::insert()
{
	node *p,*temp;
	int num;
	cout<<" Enter the data to insert : ";
	cin>>num;
	if(start==NULL)
	{
		start=new node;
		start->data=num;
		start->next=NULL;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		temp=new node;
		temp->data=num;
		temp->next=NULL;
		p->next=temp;
	}
}
void node::display()
{
	node *p;
	if(start==NULL)
	{
		cout<<" No elements in the queue...";
	}
	else
	{
		p=start;
		while(p!=NULL)
		{
			cout<<" "<<p->data<<endl;
			p=p->next;
		}
	}
}
void node:: Delete()
{
	node *p;
	if(start==NULL)
	{
		cout<<" No elements found......";
	}
	else
	{
		p=start;
		start=start->next;
		cout<<endl<<" "<<p->data<<" Deleted \n";
		delete p;
	}
}

int main()
{
	int choice;
	node n;
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
		cout<<"\n \n Enter Your Choice(1/2/3/4) : ";
		cin>>choice;
		switch(choice)
		{
			case 1: n.insert();break;
			case 2: n.display();break;
			case 3: n.Delete();break;
			case 4: exit(0);break;
		}
	}

	//getch();
}
