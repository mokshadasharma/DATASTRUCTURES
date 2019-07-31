#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char * PreClassName;
	node * next;
};
struct vertex
{
	char * ClassName;
	node * nodehead;
	vertex * next;
};

class Graph
{
	public:
		Graph()
		{
		    head = 0;
	        tail = 0;
		}
		int AddVert(char * sendclass);
		int AddEdge(char * sendclass, char * preclass);
		int RemoveVert(char * sendclass);
		int RemoveEdge(char * sendclass, char * preclass);
		void Display();
		~Graph();

	private:
		vertex * head;
		vertex * tail;
};

int main()
{
	Graph g;
	char tempname[256];
	char * sendclass;
	char * preclass;
	bool quit = false;
	int answer = 0;
	while(quit != true)
	{
		cout << "1) Adding class\n"
		<< "2) Adding prerequisite class\n"
		<< "3) Removing class\n"
		<< "4) Removing prerequisite class\n"
		<< "5) Display Graph\n"
		<< "6) Quit\n";
		cin >> answer;
		cin.ignore();
		switch(answer)
		{
			case 1:
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.AddVert(sendclass) == 1)
					cout << "You have successfully added that class\n";
				else
					cout << "We were unable to add that class\n";
				break;
			case 2:
				cout << "What is the prerequisite class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				preclass = new char[strlen(tempname) + 1];
				strcpy(preclass,tempname);
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.AddEdge(sendclass,preclass) == 1)
					cout << "You have successfully added that prerequisite class\n";
				else
					cout << "We were unable to add that prerequisite class\n";
				break;
			case 3:
				cout << "What class you would like to remove?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.RemoveVert(sendclass) == 1)
					cout << "You have successfully removed that class\n";
				else
					cout << "We were unable to remove that class\n";
				break;
			case 4:
				cout << "What prerequisite class you would like to remove?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				preclass = new char[strlen(tempname) + 1];
				strcpy(preclass,tempname);
				cout << "What is the class?\n";
				cin.get(tempname,256,'\n');
				cin.ignore();
				sendclass = new char[strlen(tempname) + 1];
				strcpy(sendclass,tempname);
				if(g.RemoveEdge(sendclass,preclass) == 1)
					cout << "You have successfully removed that prerequisite class\n";
				else
					cout << "We were unable to remove that prerequisite class\n";
				break;
			case 5:
				g.Display();
				break;
			case 6:
				quit = true;
				break;
			default:
				cout << "please enter in a valid option\n";
				break;
		}
	}
	return 0;
}
int Graph::AddVert(char * sendclass)
{
	if(!head)
	{
		head = new vertex;
		head->ClassName = new char[strlen(sendclass)+1];
		strcpy(head->ClassName,sendclass);
		head->nodehead = 0;
		head->next=0;
		tail = head;
		return 1;
	}
	else
	{
		tail->next = new vertex;
		tail = tail->next;
		tail->ClassName = new char[strlen(sendclass)+1];
		strcpy(tail->ClassName,sendclass);
		tail->nodehead =0;
		tail->next = 0;
		return 1;
	}
	return 0;
}

int Graph::AddEdge(char * sendclass, char * preclass)
{
	vertex * temp;
	node * tempnode;
	temp = head;
	while(temp)
	{
		if(strcmp(temp->ClassName, sendclass) == 0)
		{
			tempnode = new node;
			tempnode-> PreClassName = new char[strlen(preclass)+1];
			strcpy(tempnode->PreClassName,preclass);
			tempnode ->next = temp->nodehead;
			temp->nodehead = tempnode;
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

int Graph::RemoveVert(char * sendclass)
{
	vertex * currentvert;
	vertex * previousvert;
	node * tempnode;
	node * temp;
	currentvert = head;
	if(currentvert)
	{
		if(strcmp(currentvert->ClassName,sendclass) == 0)
		{
			cout << "found it at head\n";
			head = head->next;
			tempnode = currentvert->nodehead;
			while(tempnode)
			{
				temp = tempnode;
				tempnode = tempnode->next;
				delete [] temp->PreClassName;
				delete temp;
			}
			delete [] currentvert->ClassName;
			delete currentvert;
			return 1;
		}
		else
		{
			previousvert = currentvert;
			currentvert = currentvert->next;
			while((currentvert)&&(strcmp(currentvert->ClassName,sendclass) != 0))
			{
				previousvert = currentvert;
				currentvert = currentvert->next;
			}
			if(currentvert)
			{
				if(strcmp(currentvert->ClassName,tail->ClassName) == 0)
					tail = previousvert;
				previousvert->next = currentvert->next;
				tempnode = currentvert->nodehead;
				while(tempnode)
				{
					temp = tempnode;
					tempnode = tempnode->next;
					delete [] temp->PreClassName;
					delete temp;
				}
				delete [] currentvert->ClassName;
				delete currentvert;
				return 1;
			}
		}
	}
}
int Graph::RemoveEdge(char * sendclass, char * preclass)
{
	vertex * temp;
	node * currentnode;
	node * previousnode;
	node * tempnode;
	temp = head;
	while((temp)&&(strcmp(temp->ClassName,sendclass) != 0))
		temp = temp -> next;
	if(temp)
	{
		currentnode = temp->nodehead;
		previousnode = currentnode;
		while((currentnode)&&(strcmp(currentnode->PreClassName, preclass) != 0))
			{
				previousnode = currentnode;
				currentnode = currentnode -> next;
			}
			if(currentnode)
			{
				previousnode->next = currentnode->next;
				delete [] currentnode->PreClassName;
				delete currentnode;
				return 1;
			}

	}
}

void Graph::Display()
{
	vertex * temp = 0;
	node * tempnode = 0;
	temp = head;
	while(temp)
	{
		cout << temp->ClassName << ":\n";
		tempnode = temp->nodehead;
		while(tempnode)
		{
			cout << tempnode->PreClassName << "\n";
			tempnode = tempnode->next;
		}
		cout << "\n";
		temp = temp->next;
	}
}
Graph::~Graph()
{
	vertex * tempvert;
	node * tempnode;
	node * temp;
	while(head)
	{
		tempvert = head;
		head = head->next;
		tempnode = tempvert->nodehead;
		while(tempnode)
		{
			temp = tempnode;
			tempnode = tempnode->next;
			delete [] temp->PreClassName;
			delete temp;
		}
		delete [] tempvert->ClassName;
		delete tempvert;
	}
}

