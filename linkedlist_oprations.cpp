#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* update(node *head,int data)
{
    //updation by providing data
    node *temp=head;
    int d,flag=0;
    cout<<"enter data to be updated:";
    cin>>d;
    while(temp!=NULL)
    {
    if(temp->data==data)
    {
        temp->data=d;
        flag=1;
    }
    temp=temp->next;
    }
    if(!flag)
    cout<<"node no. does not exist ";
    return head;
}
/*node* update(node *head)
{
    node *temp=head;
    int c,d;
    cout<<"enter count:";
    cin>>c;
    cout<<"enter data to be updated:";
    cin>>d;
    if(c==1)
    {
       temp->data=d;
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
        temp=temp->next;
        temp->data=d;
    }
    else
    {
        cout<<"node no. does not exist ";
    }
    }
    return head;
}*/
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
    node *head=NULL;
            int n;
            cout<<"enter no. of nodes";
            cin>>n;
            while(n--)
            {
                int d;
                cout<<"enter data : ";
                cin>>d;
                head=Insert(head,d);
            }
    print(head);
    //head=update(head);
    cout<<"enter data to be changed:";
    int data;
    cin>>data;
    head=update(head,data);
    print(head);
    return 0;
}


