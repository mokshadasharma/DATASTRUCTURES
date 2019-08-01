//STACK
#include<iostream>
using namespace std;
int top=-1;
void push(int Stack[],int x,int n)
{
    if(top==n-1)
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        top=top+1;
        Stack[top]=x;
    }
}
int topElement (int Stack[])
    {
        return Stack[top];
    }
void pop(int Stack[])
{
    if(top==-1)
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
    int Stack[n]={0};
    char ch;
    do
    {
        int c;
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.isEmpty"<<endl;
        cout<<"4.size"<<endl;
        cout<<"5.display"<<endl;
        cout<<"6.top element"<<endl;
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

