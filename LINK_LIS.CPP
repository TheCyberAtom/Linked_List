#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<dos.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *ins_after(struct node*);
struct node *insert_bfr(struct node*);
struct node *del_beg(struct node*);
struct node *del_end(struct node*);
struct node *del_after(struct node*);
int main()
{
int count=1;
clrscr();
gotoxy(1,8);
cout<<"\n    W       W   E E E E   L         C C C C   O O O O   M       M   E E E E  ";
cout<<"\n    W       W   E         L         C     C   O     O   M M   M M   E        ";
cout<<"\n    W       W   E         L         C         O     O   M  M M  M   E        ";
cout<<"\n    W       W   E E E     L         C         O     O   M   M   M   E E E    ";
cout<<"\n    W   W   W   E E E     L         C         O     O   M       M   E E E    ";
cout<<"\n    W  W W  W   E         L         C         O     O   M       M   E        ";
cout<<"\n    W W   W W   E         L         C     C   O     O   M       M   E        ";
cout<<"\n    W       W   E E E E   L L L L   C C C C   O O O O   M       M   E E E E  ";
delay(600);
cout<<"\n\n\t\t\t Press any key to continue  ";
getch();
clrscr();
char pass[10];
again:
clrscr();
gotoxy(20,10);
cout<<"    Enter Password : ";
for(int i=0;i<6;i++)
{
pass[i]=getch();
cout<<"*";
}
if(pass[0]=='m'&&pass[1]=='i'&&pass[2]=='s'&&pass[3]=='h'&&pass[4]=='r'&&pass[5]=='a')
{
clrscr();
goto letsgo;
}
else
{   cout<<"\n\n\n\t\t    You have entered wrong password "<<count<<" times";
	delay(500);
	if(count==3)
	{
	cout<<"\n Program is Shutting Down.....";
	delay(200);
	exit(1);
	}
count++;
delay(200);
goto again;
}
letsgo:
clrscr();
gotoxy(1,11);
cout<<"\t\t\t\t LOADING.....\n";
int j=5;
for(i=0;i<20;i++)
{
delay(100);
cout<<j<<"% ";
j=j+5;
}
oncemore :
clrscr();
int choice;
do
{
cout<<"\n  1 : Create a list ";
cout<<"\n  2 : Display the list";
cout<<"\n  3 : Add a node at the beginning ";
cout<<"\n  4 : Add a node at the end ";
cout<<"\n  5 : Add a node after given node ";
cout<<"\n  6 : Add a node before given node ";
cout<<"\n  7 : Deleting node at beginning ";
cout<<"\n  8 : Deleting node at end ";
cout<<"\n  9 : Deleting node afer a given node ";
cout<<"\n 10 : Exit the PROGRAM ";
cout<<"\n\n Enter The option to perform the following operation : ";
cin>>choice;
clrscr();
switch(choice)
{
case 1: start =create(start);
	gotoxy(1,20);
	cout<<"\n\t\t\t Linked list created ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 2: clrscr();
	start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	gotoxy(1,20);
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 3: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start =insert_beg(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element is inserted at the begining of the List ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 4: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start =insert_end(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element is inserted at the end of the List ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 5: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start=ins_after(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element is inserted after the given node ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 6: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start=insert_bfr(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element is inserted before the given node ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 7: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start=del_beg(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element deleted from the begining of the List ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 8: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start=del_end(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element deleted from the end of the List ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 9: start =display(start);
	cout<<"   <--Current LINKED LIST \n ";
	start=del_after(start);
	gotoxy(1,20);
	cout<<"\n\t\t Element deleted after the given node ";
	cout<<"\n\n\t\t\tPress any key to continue ";
	getch();
	clrscr();
	break;
case 10 : exit(1);

default :clrscr();
	 gotoxy(5,12);
	 cout<<"\n You have Entered Wrong Option Press Any Key to Choose Again ";
	 getch();
	 goto oncemore;
	 break;
}
}while(choice>0&&choice<10);
getch();
return 0;
}

struct node *create(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	cout<<"\n Enter -1 to end the list: \n";
	cout<<"\n Enter the data :";
	cin>>num;
		while(num!=-1)
		{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
			if(start==NULL)
			{
			new_node->next=NULL;
			start = new_node;
			}
			else
			{
			ptr=start;
				while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
			}
		cout<<"\n enter the data :";
		cin>>num;
		}
		 return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	cout<<"\n\n=====>>  ";
	while(ptr!=NULL)
	{	cout<<"  "<<ptr->data;
		ptr=ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	cout<<"\n enter the values : ";
	cin>>num;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	cout<<"\n enter the values : ";
	cin>>num;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
	return start;
}
struct node *ins_after(struct node *start)
{
	struct node *preptr,*ptr,*new_node;
	int num,val;
	cout<<"\n enter the values : ";
	cin>>num;
	cout<<"\n enter the node value after which you want to insert :";
	cin>>val;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *insert_bfr(struct node *start)
{
	struct node *preptr,*ptr,*new_node;
	int num,val;
	cout<<"\n enter the values : ";
	cin>>num;
	cout<<"\n enter the node value after which you want to insert :";
	cin>>val;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}
struct node *del_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
struct node *del_after(struct node *start)
{
	struct node *preptr,*ptr;
	int val;
	cout<<"\n enter the node value after which you want to delete :";
	cin>>val;
	ptr=start;
	preptr=ptr;
	if(ptr->data==val)
	{
	ptr=ptr->next;
	preptr->next=ptr->next;
	free(ptr);
	}
	else
	{
		while(preptr->data!=val)
		{
		preptr=ptr;
		ptr=ptr->next;
		}
	preptr->next=ptr->next;
	free(ptr);
	}
	return start;
}