//2 way linked list
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* prev;
    node* next;
};
node *head=NULL;
node *create(node *);
node *display(node *);
node *reversedisplay(node *);
void Delete(node *);
node *Search(node *);
int main()
{
     int choice;
    do{
    cout<<"*****menu**********"<<endl;
    cout<<"1.create list: "<<endl;
    cout<<"2.display list: "<<endl;
    cout<<"3.delete list: "<<endl;
    cout<<"4.search list: "<<endl;
    cout<<"5.sort list: "<<endl;
    cout<<"6.exit: "<<endl;
    cout<<"enter choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        head=create(head);
        cout<<"created"<<endl;
        break;
    case 2:
        head=display(head);
        break;
    case 3:
        Delete(head);
        break;
   /* case 4:
        head=Search(head);
    /*case 5:
        head=Sort(head);*/
    }
    }
    while(choice!=6);
}

node *create(node *head)
{//insert at any position
    int data;
    node *ptr;
    cout<<"to exit: press -1 "<<endl;
    cout<<"enter data: "<<endl;
    cin>>data;
    while(data!=-1)
    {
    node *newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    node *temp=head;
    int c;
    cout<<"enter node no. :";
    cin>>c;
    if(c==1)
    {
       newnode->next=head;
       head=newnode;
    }
    else
    {
    int Count=2;
    while(temp!=NULL && Count!=c)
    {
        temp=temp->next;
        Count++;
    }
    if(Count==c)
    {
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        cout<<"node no. does not exist ";
    }
    }
    cout<<"enter data: "<<endl;
    cin>>data;
    }
    return head;
}
node* display(node *head)
{
    node *stemp=head;
    while(stemp!=NULL)
    {
        cout<<stemp->data<<" ";
        stemp=stemp->next;
    }
    cout<<endl;
    return head;
}
node* reversedisplay(node *head)
{
    node *stemp=head;
    while(stemp->next!=NULL)
    {
        stemp=stemp->next;
    }
    while(stemp->prev!=NULL)
    {
        cout<<stemp->data<<endl;
        stemp=stemp->prev;
    }
    cout<<endl;
    return head;
}
void Delete(node *head)
{
    int n,i=1;
    cout<<"enter loc: ";
    cin>>n;
    if(head==NULL || n<=0)
        return;
    node *cur=head;
    while(cur!=NULL && i<n)
    {
        cur=cur->next;
    }
    if(cur==NULL)
        return;
    if(head==cur)
        head=cur->next;
    if(cur->next!=NULL)
        cur->next->prev=cur->prev;
     if(cur->prev!=NULL)
        cur->prev->next=cur->next;
    delete cur;
}

