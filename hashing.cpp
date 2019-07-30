#include<iostream>
#include<vector>
using namespace std;
int freq[26];
/*//without hashing
void frequency(string s)
    {
        for(char c='a'; c<='z';c++)
        {
            int co=0;
            for(int i=0;i<=s.length()-1;i++)
            {
             if(s[i]==c)
                    co++;
            }
            cout<<c<<":"<<co<<endl;
        }
    }*/
//hashing
int hashfunc(char c)
{
    return (c-'a');
}
void frequency(string s)
{
   for(int i=0;i<s.length();i++)
   {
       int index=hashfunc(s[i]);
       freq[index]++;
   }
}
/*vector<string> hashtable[20];
int hashsize=20;

void Insert(string s)
{
    int index=hashfunc(s);
    hashtable[index].push_back(s);
}
void Search(string s)
{
    index=hashfunc(s);
    for(int i=0;i<hashtable[index].size();i++)
    {
        if(hashtable[index][i]==s)
        {
            cout<<s<<" found "<<endl;
            return;
        }
    }
    cout<<s<<" not found "<<endl;
}*/
int main()
{
    string s;
    cin>>s;
    frequency(s);
    //Search(string s)
    //Insert(s)
    for(int i=0;i<26;i++)
    {
    cout<<(char)(i+'a')<<" : "<<freq[i]<<endl;
    }
    return 0;
}
