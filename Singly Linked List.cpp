#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


class node
{
	int data;
	node *next;
	public:
	void create();
	void display();
	void count();
	void insertbeg();
	void delbeg();
	void search();
	void dellast();
	void insertmid();
	void delmid();
	void swap();
};

node *start=NULL;


void node::create()
{
	int a;
	node *p,*temp;
	cout<<" Enter data = ";
	cin>>a;
	if(start==NULL)
	{
		start=new node;
		start->data=a;
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
		temp->data= a;
		temp->next=NULL;
		p->next=temp;
	}
}


void node::display()
{
	node *p;
	if(start==NULL)
	{
		cout<<" List is empty ";
	}
	else
	{
		cout<<" List of Elements = ";
		p=start;
		while(p!=NULL)
		{
			cout<<endl<<" "<<p->data;
			p=p->next;
		}
	}
}


void node::count()
{
	int m=0;
	node *p;
	p=start;
	while(p!=NULL)
	{
		m=m+1;
		p=p->next;
	}
	cout<<" Total number of nodes = "<<m;
}


void node::insertbeg()
{
	int x;
	node *p;
	cout<<" Enter data for begining = ";
	cin>>x;
	p=new node;
	p->data =x;
	p->next=start;
	start=p;
}


void node::delbeg()
{
	node *p;
	p=start;
	start=start->next;
	delete p;
}


void node::search()
{
	int y=1;
	node *p;
	int x;
	cout<<" Enter data want to search = ";
	cin>>x;
	p=start;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			cout<<" Data found at position = "<<y;
			break;
		}
		y=y+1;
		p=p->next;
	}
	if(p==NULL)
	cout<<" Data not found ";
}


void node::dellast()
{
	node *p,*temp;
	p=start;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	temp=p->next;
	delete temp;
	p->next= NULL;
}


void node::insertmid()
{
	int x,y,w;
	node *p,*temp;
	cout<<" Enter position where you want to insert = ";
	cin>>x;
	cout<<" Enter data = ";
	cin>>y;
	p=start;
	for(w=0;w<x-1;w++)
	{
		p=p->next;
		if(p==NULL)
		{
			cout<<" There are less no of elements = ";
			return;
		}
	}
	temp=new node;
	temp->data=y;
	temp->next=p->next;
	p->next=temp;
}


void node::delmid()
{
	int x;
	node *p,*temp;
	p=start;
	cout<<" Enter data want to delete = ";
	cin>>x;
	while(p->next->next!=NULL)
	{
		if(p->next->data==x)
		{
			temp=p->next;
			p->next=temp->next;
			delete temp;
		}
		p=p->next;
	}
}


void node::swap()
{
	node *p,*temp;
	p=start;
	temp= p->next;
	p->next=temp->next;
	temp->next=p;
	start=temp;
}



int main()
{
	//clrscr();
	node p;
	int ch,w,x,y,z;
	while(1)
	{
		cout<<"\n";
		cout<<"---------------------------------";
		cout<<"\n 1.  Create list";
		cout<<"\n 2.  Display list";
		cout<<"\n 3.  Exit function";
		cout<<"\n 4.  Count nodes";
		cout<<"\n 5.  Insert node at begining";
		cout<<"\n 6.  Delete node from begining";
		cout<<"\n 7.  Delete last node";
		cout<<"\n 8.  Search";
		cout<<"\n 9.  Insert node in middle";
		cout<<"\n 10. Swap for first node";
		cout<<"\n 11. Delete mid node";
		cout<<"\n---------------------------------";
		cout<<"\n \n Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<" How many nodes you want to create = ";
			cin>>w;
			for(int i=1;i<=w;i++)
			{
				p.create();
			}
			break;
			
			case 2:
			p.display();
			break;
			
			case 3:
			exit(0);
			break;
			
			case 4:
			p.count();
			break;
			
			case 5:
			p.insertbeg();
			break;
			
			case 6:
			p.delbeg();
			break;
			
			case 7:
			p.dellast();
			break;
			
			case 8:
			p.search();
			break;
			
			case 9:
			p.insertmid();
			break;
			
			case 10:
			p.swap();
			break;
			
			case 11:
			p.delmid();
			break;
		}
	}
}
