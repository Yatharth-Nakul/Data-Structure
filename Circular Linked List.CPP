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
	void insertbeg();
	void insertmid();
	void delbeg();
	void dellast();
	void delmid();
	void count();
	void search();
};

node *start = NULL;

void node:: create()
{
	int x;
	cout<<" Enter the data : ";
	cin>>x;
	node *p, *temp;
	if (start == NULL)
	{
		start = new node;
		start->data = x;
		start->next = start;
	}
	else
	{
		p = start;
		while(p->next != start)
		{
			p = p->next;
		}

		temp = new node;
		temp->data = x;
		temp->next = start;
		p->next = temp;
	}
}

void node:: insertbeg()
{
	node *temp, *p;
	int x;
	cout<<" Enter the data : ";
	cin>>x;
	p = start;
	while(p->next != start)
	{
		p=p->next;
	}
	temp = new node;
	temp->data = x;
	temp->next = start;
	p->next = temp;
	start = temp;

}

void node:: insertmid()
{
	node *p, *temp;
	int x,pos;
	cout<<" Enter the Data : ";
	cin>>x;
	cout<<" Enter the position : ";
	cin>>pos;
	p = start;
	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
	}
	temp = new node;
	temp->data = x;
	temp->next =  p->next;
	p->next = temp;

}

void node:: delbeg()
{
	node *p, *temp;
	p = start;
	while(p->next != start)
	{
		p=p->next;
	}
	p->next = start->next;
	temp = start;
	start = start->next;
	delete temp;

}

void node:: delmid()
{
	int x,flag=0;
	cout<<" Enter the data to be deleted : ";
	cin>>x;
	node *p,*temp;
	p=start;
	while(p->next->next!=start)
	{
		if(p->next->data==x)
		{
			temp=p->next;
			p->next=temp->next;
			delete temp;
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==0)
	{
		cout<<" Element not found ";
	}
}
void node::dellast()
{
	node *p, *temp;
	p = start;
	while(p->next->next != start)
	{
		p=p->next;
	}
	temp=p->next;
	p->next = temp->next;
	delete temp;

}
void node::display()
{
	node *p;
	if(start == NULL)
	{
		cout<<" No Element Found ";	
	}
	else
	{
		p=start;
		while(p->next != start)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<" "<<p->data;	
	}
	
}
void node:: count()
{
	int c=1;
	node *p;
	p=start;
	while(p->next!=start)
	{
		p=p->next;
		c++;
	}
	cout<<" No of Nodes : "<<c<<endl;
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



























