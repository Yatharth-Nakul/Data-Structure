#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

class node
{
	int data;
	node *next,*prev;
	public:
		void create();
		void display();
		void count();
		void insert_beg();
		void del_beg();
		void search();
		void insert_mid();
		void del_mid();
		void del_last();
};
node *start=NULL;
void node::create()
{
	int a;
	cout<<" Enter the Data for the node : ";
	cin>>a;
	node *temp,*p;
	p=new node;
	p->data=a;

	if(start==NULL)
	{
		start=p;
		start->next=p;
		start->prev=p;
	}
	else
	{
		p->next=start;
		p->prev=start->prev;
		p->prev->next=p;
		start->prev=p;
	}

}

void node:: display()
{
	node *p;
	if(start==NULL)
	{
		cout<<" List is Empty ";
	}
	else
	{
		p=start;
		cout<<" "<<p->data<<"->";
		p=p->next;
		while(p!=start)
		{
			cout<<p->data;
			p=p->next;
			cout<<"->";
		}
		cout<<endl;
	      /*	while(p->next!=start)
		{
			cout<<"  "<<p->data;
			p=p->next;
		}
		cout<<" "<<start->prev->data; */
	}
}

void node:: insert_beg()
{
	node *ptr,*p;
	int a;
	cout<<" Enter the element for the list : ";
	cin>>a;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	p=new node;
	p->data=a;
	ptr->next=p;
	p->prev=ptr;
	start->prev=p;
	p->next=start;
	start=p;
}
void node::del_beg()
{
	node *p,*temp;
	p=start;
	while(p->next!=start)
	{
		p=p->next;
	}
	p->next=start->next;
	start->next->prev=p;
	delete start;
	start=p->next;
}
void node:: del_last()
{
	node *p;
	p=start;
	while(p->next!=start)
	{
		p=p->next;
	}
	p->prev->next=start;
	start->prev=p->prev;
	delete p;

}
void node:: insert_mid()
{
	int x,y,w;
	node *p,*temp;
	cout<<" Enter position where you want to insert = ";
	cin>>x;
	cout<<" Enter data = ";
	cin>>y;
	p=start;
	for(w=1;w<x-1;w++)
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
	temp->prev=p;
	p->next=temp;
	p->next->prev=temp;
}

void node:: del_mid()
{
	if(start == NULL)
	{
		cout << " List is Empty ";
		goto el;
	}
	else
	{
		int x;
		cout<<" Enter the data to be deleted : ";
		cin>>x;
		node *p,*temp;
	
		p=start;
		int flag =0;
		while(p->next->next!=start)
		{
			if(p->next->data==x)
			{
				temp=p->next;
				p->next=temp->next;
				temp->next->prev=p;
				delete temp;
				flag = 1;
			}
			p=p->next;
	
		}
		if(flag==0){
			cout << " Element Not Found ";
		}
		else{
			cout<<" Successfully Deleted ";
		}
	}
	el:{}
	
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

void node :: search()
{
	int x,pos=2,flag=0;
	cout<<" Enter the Element to search : ";
	cin>>x;
	node *p;
	if(start->data==x)
	{
		cout<<" Value Found at : 1"<<endl;
		goto lb;
	}
	p=start->next;
	while(p!=start)
	{
		if(p->data==x)
		{
			flag=1;
			break;
		}
		p=p->next;
		pos++;
	}
	if(flag==0)
	{
		cout<<endl<<" Element Not Found"<<endl;
	}
	else
	{
		cout<<endl<<" Value Found at : "<<pos<<endl;
	}
	lb:{}
		
}

int main()
{
	//clrscr();
	node N;
	int choice,w;
	while(1)
	{
		cout<<"\n\t\t Menu \t\t";
		cout<<"\n 1.Create";
		cout<<"\n 2.Display";
		cout<<"\n 3.Count";
		cout<<"\n 4.Insert in Beginning";
		cout<<"\n 5.Insert in Middle";
		cout<<"\n 6.Delete in Beginning";
		cout<<"\n 7.Delete in Middle";
		cout<<"\n 8.Delete in End";
		cout<<"\n 9.Search";
		cout<<"\n 10.Exit";
		cout<<endl;
		cout<<"\n Enter Your Choice : " ;
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
			case 1:
				cout<<" Number of nodes you want to create = ";
				cin>>w;
				for(int i=1;i<=w;i++)
				{
					N.create();
				}				
			case 2:N.display();break;
			case 3:N.count();break;
			case 4:N.insert_beg();break;
			case 5:N.insert_mid();break;
			case 6:N.del_beg();break;
			case 7:N.del_mid();break;
			case 8:N.del_last();break;
			case 9:N.search();break;
			case 10:exit(0);break;
			default:
				cout<<" Wrong Choice Enter Again..\n";
		}
	}
	getch();
}
