#include<iostream>
using namespace std;

class Stack
{
	char data;
	Stack *next;
	Stack *top;
	public:
	
		Stack()
		{
			top=NULL;
		}
		void push(char x);
		void pop();
		void infixtopostfix(char [],char []);
};

void Stack :: push(char x)
{
	Stack *newnode=new Stack();
	newnode->data=x;
	newnode->next=NULL;
	
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}

void Stack :: pop()
{
	if(top==NULL)
	{
		cout<<"Empty Stack.";
		return;
	}
	else
	{
		top=top->next;
	}
}

int priority(char x)
{
	if(x=='^')
	{
		return 3;
	}
	else if(x=='*' || x=='/')
	{
		return 2;
	}
	else if(x=='+' || x=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Stack::infixtopostfix(char infix[10],char postfix[10])
{   
	int i=0,j=0;
	while(infix[i]!='\0')
	{
		if(!(isalnum(infix[i])))
		{
			if(top==NULL)
			push(infix[i]);
			else if(infix[i]=='(')
			{
				push(infix[i]);  
			}
			else if(infix[i]==')')
			{
				while(top->data!='(')
				{
					postfix[j]=top->data;
					j++;
					pop();
				}
				pop();
			}
			else
			{
				while(priority(infix[i])<=priority(top->data))
				{
					postfix[j]=top->data;
					j++;
					pop();
					if(top==NULL)
						break;
				}
				push(infix[i]);
			}
		}  
			else
			{
				postfix[j]=infix[i];
				j++;
			}
				i++;
	}
	while(top!=NULL)
	{
		postfix[j]=top->data;
		j++;
		pop();
	}
	postfix[j]='\0';
}

int main()
{
	Stack s;
	char infix[10];
	char postfix[10];
	cout<<"Enter Expression: "<<endl;
	cin>>infix;
	s.infixtopostfix(infix,postfix);
	cout<<postfix<<endl;

}
