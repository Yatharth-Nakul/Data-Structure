#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

class node
{
	int data;
	node *next;
	public:
	void push();
	void display();
	void pop();
};
node *top=NULL;

void node:: push()
{
	int num;
	cout<<" Enter the data you want to push : ";
	cin>>num;
	node *temp,*p;
	if(top==NULL)
	{
		 top=new node;
		 top->data=num;
		 top->next=NULL;
	}
	else
	{
		p=top;
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

void node::pop()
{
		node *p,*temp;
		if(top==NULL)
		{
			cout<<" Stack Underflow..";
		}

		p=top;
		if(p->next==NULL)
		{
			delete p;
			top=NULL;
			cout<<" Element Deleted";
		}
		else
		{
			while(p->next->next!=NULL)
			{
				p=p->next;
			}
			temp=p->next;
			delete temp;
			p->next=NULL;
		}
}
void node::display()
{
	node *p;
	if(top==NULL)
	{
		cout<<" Stack Underflow....";
	}
	else
	{
		p=top;
		while(p!=NULL)
		{
			cout<<endl<<" "<<p->data<<endl;
			p=p->next;
		}
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
		cout<<"\n 1.PUSH";
		cout<<"\n 2.Display";
		cout<<"\n 3.POP";
		cout<<"\n 4.Exit";
		cout<<"\n---------------------------------";
		cout<<"\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:n.push();break;
			case 2:n.display();break;
			case 3:n.pop();break;
			case 4:exit(0);break;
		}
	}
	//getch();
}
