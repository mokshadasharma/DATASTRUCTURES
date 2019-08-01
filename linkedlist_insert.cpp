#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* Insert(node *head,int data)
{
    node *newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    node *temp=head;
    int c;
    cout<<"enter count";
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
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        cout<<"node no. doesnot exist ";
    }
    }
    return head;
}
/*node* Insert(node *head,int data)
{
    node *newnode=new node;
    node *temp;
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}*/
/*node* Insert(node *head,int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
    temp->next=head;
    head=temp;
    }
    return head;
}*/
void print(node *head)
{
    node *stemp=head;
    while(stemp!=NULL)
    {
        cout<<stemp->data<<" ";
        stemp=stemp->next;
    }
}
int main()
{
    int n;
    node *head=NULL;

    cout<<"enter node:";
    cin>>n;
    while(n--)
    {
        int d;
        cout<<"enter data : ";
        cin>>d;
        head=Insert(head,d);
    }
    print(head);
    return 0;
}
