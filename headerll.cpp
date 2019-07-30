//header linked list : it contain a special node(header node) at beg containing no. of nodes : 1. grounded 2. circular ....first:=
#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
};
node *head=NULL;
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
   /* case 3:
        head=Delete(head);
        break;
    case 4:
        head=Search(head);
    case 5:
        head=Sort(head);
    */
    }
    }
    while(choice!=6);

    return 0;
}
node *create(node *head)
{//at end
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
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            head->data+=1;
        }
        cout<<"enter data: "<<endl;
        cin>>data;
    }
    return head;
}
node *Delete(node *head)
{//at end
    node *ptr,*prev;;
    ptr=head->next;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    delete ptr;
    head->data-=1;
    return head;
}
node *Search(node *head)
{
    int d,Count=1;
    node *ptr=head->next;
    cout<<"enter data to search:";
    cin>>d;
    while(ptr!=NULL && ptr->data!=d)
    {
        ptr=ptr->next;
        Count++;
        if(ptr==NULL)
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
    return head;
}
node* display(node *head)
{
    node* ptr=head;
    ptr=ptr->next;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl<<"node : "<<head->data<<endl;
    return head;
}
node* Sort(node *head)
{
    return head;

}
/*node* Insert(node *head,int data)
{
    node *newnode=new node;

    newnode->data=data;
    newnode->next=head;
            if(head==NULL)
                head=newnode;
            newnode->next=head;
            head=newnode;

    return head;
}
void printList(node *head)
{
    node *temp = head->next;
    if (temp!= NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != head && temp!=NULL);
    }
    else{
        cout<<endl<<"no linked list"<<endl;
    }
}
int countNodes(node* head)
{
    node* temp = head;
    int result = 0;
    if (head != NULL)
    {
        do
        {
            temp = temp->next;
            result++;
        }
        while (temp != head);
    }
    return result;
}
int main()
{
    node *head=NULL;
    int d;
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
    //cout<<"total: "<<countNodes(head);
    printList(head);
    cout<<"enter element to search: ";
    cin>>d;
    cout<<Search(head,d)<<endl;
    return 0;
}
*/
