#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
struct node
{
  int info;
  node *left;
  node *right;
 };
 node*  getnewnode(int data)
 {
     node* newnode=new node;
     newnode->info=data;
     newnode->left=NULL;
     newnode->right=NULL;
     return newnode;
 }
 node* Insert(node* temp,int data)
{
  if(temp==NULL)
  {
    temp=new node;
    temp->info=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    }
  if(data<=temp->info)
  {
    temp->left=Insert(temp->left,data);
    }
  else
  {
    temp->right=Insert(temp->right,data);
     }
   return temp;
 }
void display(node* root,int level)
{
    node* ptr=root;
    int i;
    if(root==NULL)
    {
      return;
    }
    if(ptr!=NULL)
    {
      display(ptr->right,level+1);
      cout<<endl;
      if(ptr==root)
      {
      cout<<" ";
	  }
      else
      {
       for(i=0;i<level;i++)
	   cout<<"  ";
	  }
	  cout<<ptr->info;
	  display(ptr->left,level+1);
     }
}
int findheight(node *root)
  {
    if(root==NULL)
    {
      return 0;
     }
    return max(findheight(root->left),findheight(root->right))+1;
   }
int findmin(node *root)
  {
    if(root==NULL)
    {
      cout<<"Tree Empty\n";
      return -1;
     }
    else if(root->left==NULL)
    {
       return root->info;
     }
      return findmin(root->left);
   }
int findmax(node *root)
   {
    if(root==NULL)
    {
      return -1;
     }
    else if(root->right==NULL)
    {
      return root->info;
     }
      return findmax(root->right);
    }
 void preorder(node *temp)
{
  if(temp==NULL)
  return;

   cout<<temp->info<<"  ";
   preorder(temp->left);
   preorder(temp->right);
 }
 void inorder(node *temp)
{
  if(temp==NULL)
   return;

    inorder(temp->left);
    cout<<temp->info<<"  ";
    inorder(temp->right);
 }
 void postorder(node *temp)
{
  if(temp==NULL)
   return;

   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->info<<"  ";
 }
 void levelorder(node *root)
 {
   if(root==NULL)
   return;
   queue<node*>Q;
   Q.push(root);
   while(!Q.empty())
   {
    node *current=Q.front();
    Q.pop();
    cout<<current->info<<"  ";
    if(current->left!=NULL)
    Q.push(current->left);
    if(current->right!=NULL)
    Q.push(current->right);
    }
  }
 void Search(node* current, int d)
{
    if(current==NULL)
        cout<<"not found"<<endl;
	if(current)
	{
		if(current->info==d)
			cout << "found " << current -> info << "\n";
		else if(current->info>d)
			Search(current->left,d);
		else if(current->info<d)
			Search(current->right,d);
	}
}
int main()
{
    int Max,Min,height;
    node* root=NULL;
    char ch;
    do{
    int n;
    cout<<"BINARY SEARCH TREE"<<endl;
    cout<<"1.insert"<<endl;
    cout<<"2.display"<<endl;
    cout<<"3.find min"<<endl;
    cout<<"4.find max"<<endl;
    cout<<"5.find height"<<endl;
    cout<<"6.traversal"<<endl;
    cout<<"7.search data"<<endl;
    cout<<"ENTER CHOICE"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        int d;
        cout<<"enter data : "<<endl;
        cin>>d;
        root=Insert(root,d);
        break;
    case 2:
        display(root,1);
        //1:level
        break;
    case 3:
        Min=findmin(root);
        if(Min==-1)
            cout<<"no tree found"<<endl;
        else
            cout<<"min element : "<<Min<<endl;
        break;
    case 4:
        Max=findmax(root);
        if(Max==-1)
            cout<<"no tree found"<<endl;
        else
            cout<<"max element : "<<Max<<endl;
        break;
    case 5:
        height=findheight(root);
        cout<<"height of tree : "<<height<<endl;
        break;
    case 6:
        int ch;
        cout<<"1.Level order\n2.Preorder\n3.Inorder\n4.Postorder"<<endl;
        cout<<"Enter choice\n";
        cin>>ch;
        if(ch==1)
            levelorder(root);
        else if(ch==2)
            preorder(root);
        else if(ch==3)
            inorder(root);
        else if(ch==4)
            postorder(root);
        else
            cout<<"Enter correct choice\n";
        break;
    case 7:
        int data;
        cout<<"enter data to be found : "<<endl;
        cin>>data;
        Search(root,data);
        break;
    }
    cout<<end<<"wanna continue?"<<endl;
    cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    return 0;
}
