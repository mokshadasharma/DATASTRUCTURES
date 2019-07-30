#include<iostream>
using namespace std;
struct node
{
int data;
node* next;
};
node *head=NULL;
node *start;
node *create(node *);
node *display(node *);
node *Delete(node *);
node *Search(node *);
node *Sort(node *);
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
        head=Delete(head);
        break;
    case 4:
        head=Search(head);
    /*case 5:
        head=Sort(head);*/
    }
    }
    while(choice!=6);
    return 0;
}
node *create(node *head)
{//insert at end
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
        if(head==NULL)
        {
            head=new node;
            head->data=1;
            head->next=newnode;
            newnode->next=head->next;
        }
        else
        {
            ptr=head->next;
            while(ptr->next!=head->next)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=head->next;
            head->data+=1;
        }
        cout<<"enter data: "<<endl;
        cin>>data;
    }
    return head;
}
node* display(node *head)
{
    node* ptr=head;
    ptr=ptr->next;
    while(ptr->next!=head->next)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<" ";
    cout<<endl<<"node : "<<head->data<<endl;
    return head;
}
node* Delete(node *head)
{//at end
    node *prev,*ptr=head;
    ptr=ptr->next;
    while(ptr->next!=head->next)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=head->next;
    delete ptr;
    head->data-=1;
    return head;
}
node *Search(node *head)
{//for linked list of unique elements
  /*  int d,Count=1;
    node *ptr=head->next;
    cout<<"enter data to search:";
    cin>>d;
    while(ptr!=head->next&& ptr->data!=d)
    {
        ptr=ptr->next;
        Count++;
        if(ptr==head->next)
        {
            cout<<"not found"<<endl;
            return head;
        }
    }
    if(ptr->data==d)
    {
        cout<<"node position:"<<Count<<endl;
    }
    else
        {
        cout<<"not found"<<endl;
    }
    return head;*/

    //code for repeating data
    node* temp = head;
    int d,Count=0,flag=0;
    cout<<"enter data to search:";
    cin>>d;
        do
        {
            temp = temp->next;
            Count++;
            if(temp->data==d)
            {
                cout<<"node position:"<<Count<<endl;
                flag=1;
            }
        }
        while (temp->next != head->next);
        if(!flag)
            cout<<"NO such data "<<endl;
    return head;
}
