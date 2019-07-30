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



