#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
/*node* Delete(node *head)
{
    node *temp=head;
    head=head->next;
    delete temp;
    return head;
}*/
/*node* Delete(node *head)
{
    node *temp=head,*temp2=temp;
    while(temp->next!=NULL)
    {
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    delete temp;
    return head;
}*/
node* Delete(node *head)
{
    node *temp1=head,*temp2=temp1->next;
    int c;
    cout<<"enter loc to del ";
    cin>>c;
    if(c==1)
    {
       head=temp1->next;
       delete temp1;
    }
    else
    {
    int Count=2;
    while(temp2!=NULL && Count!=c)
    {
        temp1=temp2;
        temp2=temp2->next;
        Count++;
    }
    if(Count==c)
    {
        temp1->next=temp2->next;
        delete temp2;
    }
    else
    {
        cout<<"node no. does not exist ";
    }
}
 return head;
}
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
        cout<<"node no. does not exist ";
    }
    }
    return head;
}
void print(node *head)
{
    node *stemp=head;
    while(stemp!=NULL)
    {
        cout<<stemp->data<<" ";
        stemp=stemp->next;
    }
    cout<<endl;
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
    head=Delete(head);
    print(head);
    return 0;
}


