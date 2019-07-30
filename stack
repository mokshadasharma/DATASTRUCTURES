//STACK
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

