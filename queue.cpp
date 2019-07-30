//CIRCULAR QUEUE
#include<iostream>
#include<limits.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int fr=-1,rr=-1;
void enqueue(int Q[],int x,int n)
{
    if((rr+1)%n==fr)
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        if(fr==-1)
            fr++;
        rr=(rr+1)%n;
        Q[rr]=x;
    }
}

void dequeue(int Q[],int n)
{
    if(fr==-1 && rr==-1)
    {
        cout<<"underflow"<<endl;;
    }
    else if(fr==rr)
    {
        rr=-1;
        fr=-1;
    }
    else
    {
        Q[fr]=0;
        fr=(fr+1)%n;
    }
}
bool isEmpty()
{
    if(fr==-1)
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}
int Size(int Q[],int n)
{
    return (abs(rr-fr)%n)+1;
}
int Front(int Q[])
    {
        return Q[fr];
    }
int Rear(int Q[])
    {
        return Q[rr];
    }

int main()
{
    int n;
    cout<<"enter size:"<<endl;
    cin>>n;
    int Q[n]={0};
    char ch;
    do
    {
        int c;
        cout<<"1.enqueue"<<endl;
        cout<<"2.dequeue"<<endl;
        cout<<"3.isEmpty"<<endl;
        cout<<"4.size"<<endl;
        cout<<"5.display"<<endl;
        cout<<"6.front element"<<endl;
        cout<<"7.rear element"<<endl;
        cin>>c;
        switch(c)
        {
        case 1:
            int d;
            cout<<"enter data: ";
            cin>>d;
            enqueue(Q,d,n);
            break;
        case 2:
            dequeue(Q,n);
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            cout<<Size(Q,n);
            break;
        case 5:
            for(int i=0;i<n;i++)
                cout<<Q[i]<<endl;
            break;
        case 6:
            cout<<Front(Q)<<endl;
            break;
        case 7:
            cout<<Rear(Q)<<endl;
        }
       cout<<endl<<"want to continue ?(Y/N)";
       cin>>ch;
    }
    while(ch=='y' | ch=='Y');
    return 0;
}



/*STACK
#include<iostream>
using namespace std;
int fr=-1,rr=-1;
void push(int Queue[],int x,int n)
{
    if(fr==(rr+1)%n)
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        rr=rr+1;
        Queue[rr]=x;
    }
}
int topElement (int Queue[])
    {
        return Queue[rr];
    }
void pop(int Queue[])
{
    if(fr==rr)
    {
        cout<<"underflow"<<endl;;
    }
    else
    {
        Stack[top]=0;
        top=top-1;
    }
}
bool isEmpty()
{
    if(top==-1)
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}
int Size()
{
    return top+1;
}
int main()
{
    int n;
    cout<<"Enter size of Queue : "<<endl;
    cin>>n;
    int Queue[n]={0 };
    char ch;
    do
    {
        int c;
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.isEmpty"<<endl;
        cout<<"4.size"<<endl;
        cout<<"5.display"<<endl;
        cout<<"6.front element"<<endl;
        cout<<"7.rear element"<<endl;
        cin>>c;
        switch(c)
        {
        case 1:
            int d;
            cout<<"enter data: ";
            cin>>d;
            push(Stack,d,n);
            break;
        case 2:
            pop(Stack);
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            cout<<Size();
            break;
        case 5:
            for(int i=0;i<n;i++)
                cout<<Stack[i]<<endl;
            break;
        case 6:
            cout<<topElement(Stack);
            break;
        case 7:
            break;
        }

       cout<<endl<<"want to continue ?(Y/N)";
       cin>>ch;
    }
    while(ch=='y' | ch=='Y');
    return 0;
}
*/
