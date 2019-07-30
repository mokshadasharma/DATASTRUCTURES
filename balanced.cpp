#include<iostream>
#include<string.h>
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

void pop(int Stack[])
{
    if(top==-1)
    {
        cout<<"underflow"<<endl;;
    }
    else
    {
       // Stack[top]=0;
        top=top-1;
    }
}
bool isEmpty()
{
    if(top==-1)
    {
        //cout<<"empty"<<endl;
        return true;
    }
    else
    {
        //cout<<"not empty"<<endl;
        return false;
    }
}
bool check(string s)
{
    int n=s.size();
    cout<<n<<endl;
    int Stack[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                push(Stack,s[i],n);
            }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(isEmpty())
                {
                    return false;
                }
            else
            {
                pop(Stack);
            }
        }
    }
    if(isEmpty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<s<<endl;
    if(check(s))
        cout<<"balanced"<<endl;
    else
        cout<<"unbalanced"<<endl;
    return 0;
}
