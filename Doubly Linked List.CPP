#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
class node
{
	int data;
	node *prev;
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
};
node *start=NULL;
void node::create()
{
	int a;
	node *p,*temp;
	cout<<"\n Enter Data= ";
	cin>>a;
	if(start==NULL)
	{
		start=new node;
		start->prev=NULL;
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
		temp->prev=p;
		p->next=temp;
	}
}

void node::display()
{
	node *p;
	if(start==NULL)
	{
		cout<<" List is empty";
	}
	else
	{
		cout<<" List of elements = ";
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
	cout<<"\n Total number of Nodes = "<<m;
}
	
void node::insertbeg()
{
	int x;
	node *p;
	cout<<"\n Enter Data in Begining = ";
	cin>>x;
	p=new node;
	p->data =x;
	p->next=start;
	p->prev=NULL;
	start->prev=p;
	start=p;
}

void node::delbeg()
{
	node *p;
	p=start;
	start=start->next;
	delete p;
	start->prev=NULL;
}

void node::search()
{
	int y=1;
	node *p;
	int x;
	cout<<"\n Enter data you want to search = ";
	cin>>x;
	p=start;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			cout<<"\n Data found at Position = "<<y;
			break;
		}
		y=y+1;
		p=p->next;
	}
	if(p==NULL)
	cout<<"\n Data not found \n";
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
	cout<<"\n Enter position where you want to insert = ";
	cin>>x;
	cout<<"\n Enter data = ";
	cin>>y;
	p=start;
	for(w=0;w<x-1;w++)
	{
		p=p->next;
		if(p==NULL)
		{
			cout<<"\n There are less no of elements = ";
			return;
		}
	}
	temp=new node;
	temp->data=y;
	temp->next=p->next;
	p->next->prev=temp;
	temp->prev=p;
}

void node::delmid()
{
	int x;
	node *p,*temp;
	p=start;
	cout<<"\n Enter data want to delete = ";
	cin>>x;
	while(p->next->next!=NULL)
	{
		if(p->next->data==x)
		{
			temp=p->next;
			p->next=temp->next;
			temp->next->prev=p;
			delete temp;
		}
		p=p->next;
	}
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
		cout<<"\n 1. Create list";
		cout<<"\n 2. Display list";
		cout<<"\n 3. Count nodes";
		cout<<"\n 4. Insert node in begining";
		cout<<"\n 5. Delete node from begining";
		cout<<"\n 6. Delete last node";
		cout<<"\n 7. Search";
		cout<<"\n 8. Insert node in middle";
		cout<<"\n 9. Delete mid node";
		cout<<"\n 10. Exit";
		cout<<"\n---------------------------------";
		cout<<"\n \n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Number of nodes you want to create = ";
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
				p.count();
				break;
			case 4:
				p.insertbeg();
				break;
			case 5:
				p.delbeg();
				break;
			case 6:
				p.dellast();
				break;
			case 7:
				p.search();
				break;
			case 8:
				p.insertmid();
				break;
			case 9:
				p.delmid();
				break;
			case 10:
				exit(0);
				break;
		}
	}
}