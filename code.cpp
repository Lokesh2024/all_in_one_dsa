/*
    PROJECT NAME : ALL IN ONE DATA STRUCTURE
THIS PROJECT IS ABOUT ALL THE DATA STRUCTURE IMPLEMENTATION
THE FOLLOWING DATA STRUCTURE ARE COVERED :
    :- ARRAY
    :- STACK
    :- QUEUE
    :- CIRCULAR QUEUE
    :- DEQUE
    :- LINKED LIST
    :- CIRCULAR LINKED LIST
    :- DOUBLY LINKED LIST
    :- CIRCULAR DOUBLY LINKED LIST
    :- BINARY SEARCH TREE
    :- BINARY TREE
    :- AVL TREE
*/

#include<bits/stdc++.h>
using namespace std;

class cir_queue
{
        int *q,front_q,rear,c,n;

public :
        cir_queue(){cout<<"\n\n\t\t\t\t\tENTER THE SIZE OF QUEUE : ";
                    cin>>n;
                while(n==0)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tTHE SIZE OF QUEUE CANNOT BE ZERO"<<endl;
                    cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
                    getchar();
                    getchar();
                    system("cls");
                    cout<<endl<<"\n\n\t\t\t\t\tENTER THE SIZE OF QUEUE : ";cin>>n;
                }
                    q = new int[n];
            front_q=0;rear=0;c=0;}

        void enqueue();
        void dequeue();
        void display();
        void search_ele();
        void sort_q();
};

void cir_queue::sort_q()
{
    if(c==0)
    {
        cout<<endl<<endl<<"\t\t\t\t\tQueue is empty"<<endl;
        return;
    }
    int temp,i;
	int d = c-1;
	d = d*d;
	int temp_1;

	while(d--)
	{
        i = front_q;
        temp_1 = c-1;
        while(temp_1--)
        {
            if(q[i%n] > q[(i+1)%n])
            {
                temp = q[i%n];
                q[i%n] = q[(i+1)%n];
                q[(i+1)%n] = temp;
            }
            i = (i+1)%n;
        }
	}
	cout<<endl<<"\t\t\t\t\tQUEUE SORTED"<<endl;
}

void cir_queue::search_ele()
{
    if(c==0)
    {
        cout<<endl<<"\t\t\t\t\tQueue is empty"<<endl;
        return;
    }
    cout<<endl<<"\t\t\t\t\tEnter the element to search for : ";
    int x;
    cin>>x;
    int i = front_q;
    int temp = c;
    while(temp--)
    {
        if(q[i] == x)
        {
            cout<<endl<<"\t\t\t\t\t!!!! Given element is present in the queue"<<endl;
            return;
        }
        i = (i+1)%n;
    }

    cout<<endl<<"\t\t\t\t\t!!! Given element is not present in the queue"<<endl;
}

void cir_queue :: enqueue()
{
        int a;
        if(rear == n+1 || (rear == front_q && rear != 0))
        {
                cout<<"\t\t\t\t\tQueue is full no more elements can be added "<<endl<<endl;
        }
        else
        {
                cout<<endl<<"\t\t\t\t\tEnter the element to add to queue : ";
                cin>>a;
                q[rear] = a;
		c++;
                rear++;
		if(rear == n && front_q == 0)
			rear++;
		else
		{
			rear  = (rear%n);
		}
		cout<<endl<<"\t\t\t\t\tElement added "<<endl;
        }
}

void cir_queue :: dequeue()
{
	if(c == 0)
        {
                cout<<"\t\t\t\t\tQueue is empty You cannot delete element from queue "<<endl<<endl;
                front_q = rear = 0;
        }
        else
        {
                cout<<"\t\t\t\t\tElement "<<q[front_q]<<" is deleted "<<endl<<endl;
		c--;
		if(rear == n+1)
		rear = (rear-1)%n;
                front_q = (front_q + 1)%n;
        }
}

void cir_queue :: display()
{
        cout<<endl<<endl<<"\t\t\t\t\tElements of queue are as follows : "<<endl<<endl;
	int i = front_q;
	int j = c;
	cout<<"\t\t\t\t\t";

	while(j--)
        cout<<"---";
    j = c;
    cout<<endl<<"\t\t\t\t\t";
	while(j--)
	{
		cout<<"|"<<q[i];
		i = (i+1)%n;
	}
	cout<<endl<<"\t\t\t\t\t";
	j = c;

	while(j--)
        cout<<"---";
    cout<<endl;
}

class my_queue
{
	int *q,front_q,rear,c,n;

public :
	my_queue(){cout<<endl<<"\n\n\t\t\t\t\tENTER THE SIZE OF QUEUE : ";cin>>n;

                while(n==0)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tTHE SIZE OF QUEUE CANNOT BE ZERO"<<endl;
                    cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
                    getchar();
                    getchar();
                    system("cls");
                    cout<<endl<<"\n\n\t\t\t\t\tENTER THE SIZE OF QUEUE : ";cin>>n;
                }
            q = new int[n];
	    front_q=0;rear=0;c=0;}

	void enqueue();
	void dequeue();
	void display();
	void search_q();
	void sort_q();
};

void my_queue :: enqueue()
{
	int a;
	if(rear == n)
	{
		cout<<"\t\t\t\t\tQueue is full no more elements can be added "<<endl<<endl;
	}
	else
	{
		cout<<endl<<"\t\t\t\t\tEnter the element to add to queue : ";
		cin>>a;
		q[rear] = a;
		rear++;
		c++;
		cout<<endl<<"\t\t\t\t\tELEMENT ADDED SUCCESSFULLY";
	}
}

void my_queue :: dequeue()
{
	if(front_q == rear)
	{
                cout<<"\t\t\t\t\tQueue is empty You cannot delete element from queue "<<endl<<endl;
		front_q = rear = 0;
	}
	else
	{
		cout<<"\t\t\t\t\tElement "<<q[front_q]<<" is deleted "<<endl<<endl;
		front_q++;
		c--;
	}
}

void my_queue :: display()
{
	cout<<endl<<endl<<"\t\t\t\t\tElements of queue are as follows : "<<endl<<endl;

    cout<<"\t\t\t\t\t";
	for(int i=front_q;i<rear;i++)
		cout<<"----";
    cout<<endl<<"\t\t\t\t\t";
    for(int i=front_q;i<rear;i++)
    cout<<"|"<<q[i]<<"|";
    cout<<endl<<"\t\t\t\t\t";

    for(int i=front_q;i<rear;i++)
		cout<<"----";
}

void my_queue :: search_q()
{
	cout<<"\t\t\t\t\tEnter the element to search for : ";
	int b,ch = 0;
	int coun = 0;
	cin>>b;
	cout<<"\t\t\t\t\tElement "<<b<<" found at index : ";

	for(int i=front_q;i<rear;i++)
	{
		if(q[i] == b)
		{
			coun++;
			cout<<i<<" ";
			ch=1;
		}
	}
	if(ch == 0)
		cout<<endl<<"\t\t\t\t\tELEMENT NOT FOUND "<<endl;
	else
	{
		cout<<endl<<"\t\t\t\t\t NUMBER OF TIMES : "<<coun<<endl<<endl;
	}
}

void my_queue :: sort_q()
{
    if(c==0)
    {
        cout<<endl<<endl<<"\t\t\t\t\tQueue is empty"<<endl;
        return;
    }
	int temp;
	int d = c-1;
	d = d*d;
	while(d--)
	{
	for(int i=front_q;i<rear-1;i++)
	{
		if(q[i] > q[i+1])
		{
			temp = q[i];
			q[i] = q[i+1];
			q[i+1] = temp;
		}
	}
	}
	cout<<endl<<"\t\t\t\t\tQUEUE SORTED SUCCESSFULLY"<<endl;
}

void simple_queue()
{
    system("cls");
    my_queue my_q;
	int ch=1;

	while(ch != 6)
	{
	    system("cls");
	    cout<<"\n\n\t\t\t\t****** WELCOME TO QUEUE DATA STRUCTURE(INT TYPE) *********"<<endl;
		cout<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO WITH QUEUE?"<<endl;
		cout<<"\n\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.deletion\n\t\t\t\t\t3.show\n\t\t\t\t\t4.search\n\t\t\t\t\t5.sort\n\t\t\t\t\t6.exit"<<endl<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1 : my_q.enqueue();
				 break;

			case 2 : my_q.dequeue();
				break;

			case 3 : my_q.display();
				 break;
			case 4 : my_q.search_q();break;
			case 5 : my_q.sort_q();break;
			case 6 : cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING QUEUE "<<endl;break;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;

		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY TO CONTINUE"<<endl;char ch;

		 getchar();
	}
}

void cir_queue_1()
{
    system("cls");
        cir_queue my_q;
        int ch=1;

        while(ch != 6)
        {
            system("cls");
                cout<<endl<<"\n\t\t\t\t***** WELCOME TO CIRCULAR QUEUE DATA STRUCTURE(INT TYPE) ******";
                cout<<endl<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO WITH CIRCULAR QUEUE?"<<endl;
                cout<<"\n\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.deletion\n\t\t\t\t\t3.show\n\t\t\t\t\t4.search\n\t\t\t\t\t5.sort\n\t\t\t\t\t6.exit"<<endl<<endl;
                cout<<"\t\t\t\t\tEnter your choice : ";
                cin>>ch;

                switch(ch)
                {
                        case 1 : my_q.enqueue();
                                 break;

                        case 2 : my_q.dequeue();
                                break;

                        case 3 : my_q.display();
                                 break;
                        case 4: my_q.search_ele();
                                break;
                        case 5:my_q.sort_q();break;
                        case 6:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING CIRCULAR QUEUE "<<endl;break;break;
                        default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENETERED"<<endl;
                }
		getchar();
        cout<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
        getchar();
        }
}

class my_stack
{
	int *s,si;

public:
    int top;
	my_stack()
	{
	    cout<<endl<<"\t\t\t\t\tENTER THE SIZE OF STACK : ";
	    int siz;
	    cin>>siz;

	    while(siz==0)
        {
                    cout<<endl<<endl<<"\t\t\t\t\tTHE SIZE OF STACK CANNOT BE ZERO"<<endl;
                    cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
                    getchar();
                    getchar();
                    system("cls");
                    cout<<endl<<"\n\n\t\t\t\t\tENTER THE SIZE OF STACK : ";cin>>siz;
        }
		top = -1;
		s = new int[siz];
		si = siz;
	}
	void push();
	void pop();
	void show();
};

void my_stack :: push()
{
	if(top == si-1)
		cout<<"\t\t\t\t\tStack is full"<<endl;
	else
	{
	int ch;
	cout<<"\t\t\t\t\tEnter the element to push to stack : ";
	cin>>ch;
	s[++top] = ch;
	cout<<"\t\t\t\t\tElement pushed successfully"<<endl;
	}
}

void my_stack :: pop()
{
	if(top == -1)
		cout<<"\t\t\t\t\tStack is empty"<<endl;
	else
		cout<<"\t\t\t\t\tElement "<<s[top--]<<" is popped out "<<endl;
}

void my_stack :: show()
{
	int b = top;
	cout<<"\t\t\t\t\tStack is : ";
	cout<<endl<<endl<<"\t\t\t\t\t";
	while(1)
	{
		if(b == -1)
			break;
		else
			cout<<"|"<<s[b]<<"|"<<endl;
            cout<<"\t\t\t\t\t"<<"|--|"<<endl;
            cout<<"\t\t\t\t\t";
		b--;
	}
}

void eva_stack()
{
    system("cls");
    stack<int>s1;
	int i=0,temp,a,b,d;
	string c;
	cout<<endl<<"\n\n\t\t\t\tEnter the expression : ";
	cin>>c;

	while(c[i] != '\0')
	{
		if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/' || c[i] == '^')
		{
		    if(s1.empty() == false)
            {
                a = s1.top();
                s1.pop();
            }
            else
            {
                cout<<"\n\t\t\t\t\t!!!! THE EXPRESSION ENTERED IS WRONG !!!"<<endl;
                return ;
            }
            if(s1.empty() == false)
            {
                b = s1.top();
                s1.pop();
            }
            else
            {
                cout<<"\n\t\t\t\t\t!!!! THE EXPRESSION ENTERED IS WRONG !!!"<<endl;
                return ;
            }
            switch(c[i])
			{
				case '+' : temp = b+a;
                            s1.push(temp);break;
				case '-' : temp = b-a;
                            s1.push(temp);break;
				case '*' : temp = b*a;
                            s1.push(temp);break;
				case '/' : temp = b/a;
                            s1.push(temp);break;
				case '^' : temp = pow(b,a);
                            s1.push(temp);break;
			}
		}
		else if(c[i] > 47 && c[i] < 59)
		{
			d = c[i]-48;
			s1.push(d);
		}
		i++;
	}
        if(s1.empty() == false)
        {
            int temp = s1.top();
            s1.pop();
            if(s1.empty() == true)
            cout<<endl<<"\t\t\t\tThe resultant is : "<<temp<<endl;
            else
                cout<<"\n\t\t\t\t\t!!!! THE EXPRESSION ENTERED IS WRONG !!!"<<endl;
        }
        else
            cout<<"\n\t\t\t\t\t!!!! THE EXPRESSION ENTERED IS WRONG !!!"<<endl;
}

int prec(char b)         //returns the respective precedence of operators
{
	switch(b)
	{
		case '+' :
		case '-' : return(1);
		case '*' :
		case '/' : return(2);
		case '^' : return(3);
		case '(' :
		case '{' :
        case '[' : return(4);
        case ']' :
        case '}' :
		case ')' : return(5);
		default :  return(0);
	}
}

void postfix()
{
    system("cls");
	int i = 0;
    string a;

	cout<<endl<<endl<<endl<<"\t\t\t\tEnter the expression : ";
    cin>>a;

	char pp;
	stack<char>s1;
	s1.push('(');
    cout<<endl<<"\n\t\t\t\tThe postfix of given expression is : ";
	while(a[i] != '\0')
	{
		switch(prec(a[i]))
		{
			case 4 : s1.push(a[i]);
				 break;

			case 1 :
			case 2 :
			case 3 :
                pp = s1.top();
                s1.pop();

				 while((prec(pp) >= prec(a[i])) && pp != '(')
                 {
					cout<<pp;
                    pp = s1.top();
                    s1.pop();
				 }
				 s1.push(pp);
				 s1.push(a[i]);
				 break;

			case 5 :
				pp = s1.top();
				s1.pop();
				while(pp != '(')
				{
					cout<<pp;
					pp = s1.top();
					s1.pop();
				}
				break;

			case 0 : cout<<a[i];
				 break;
		}
		i++;
	}

	pp = s1.top();
	s1.pop();

	while(pp != '(')
	{
		cout<<pp;
		pp = s1.top();
		s1.pop();
	}
    cout<<endl;
}

int prec_p(char b)         //returns the respective precedence of operators
{
	switch(b)
	{
		case '+' :
		case '-' : return(1);
		case '*' :
		case '/' : return(2);
		case '^' : return(3);
		case '(' :
		case '{' :
        case '[' : return(5);
        case ']' :
        case '}' :
		case ')' : return(4);
		default :  return(0);
	}
}

void prefix()
{
    system("cls");
    string exp;
    string infix;
    cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter the infix expression : ";
    cin>>infix;

    int i = infix.size()-1;
    stack<char>s1;
    s1.push(')');
    int j=0;
    char pp;

    while(i>=0)
    {
        switch(prec_p(infix[i]))
        {
            case 0 : exp[j] = infix[i];
                     j++;break;

             case 4 :
                    s1.push(infix[i]);
                      break;

            case 1 :
            case 2:
            case 3:
                    pp = s1.top();
                s1.pop();

				 while((prec_p(pp) > prec_p(infix[i])) && pp != ')')
                 {
					exp[j] = pp;
					j++;
                    pp = s1.top();
                    s1.pop();
				 }
				 s1.push(pp);
				 s1.push(infix[i]);
				 break;
            case 5 :
				pp = s1.top();
				s1.pop();
				while(pp != ')')
				{
					exp[j] = pp;
					j++;
					pp = s1.top();
					s1.pop();
				}
				break;
        }
        i--;
    }
    pp = s1.top();
	s1.pop();

	while(pp != ')')
	{
		exp[j] = pp;
		j++;
		pp = s1.top();
		s1.pop();
	}

	j--;
    cout<<endl<<endl<<"\t\t\t\t\tThe required prefix is : ";

    try
    {
    while(j>=0)
    {
        if(j==-1)
        throw j;
        cout<<exp[j];
        j--;
    }
    }
    catch(int x)
    {
        cout<<"ERROR "<<x<<endl;
    }
    cout<<endl;
    //cout<<exp[0]<<endl;
}

void my_stack_1()
{
    int ch=1;
	system("cls");

	my_stack st;

	while(ch != 8)
	{
	    system("cls");
	    cout<<endl<<"\t\t\t\t\t******* WELCOME TO STACK DATA STRUCTURE ********** "<<endl<<endl;
	    cout<<"\t\t\t\t\t*** WHAT DO YOU WANT TO DO? ****";
	cout<<endl<<endl<<"\t\t\t\t\t1.Push\n\t\t\t\t\t2.Pop\n\t\t\t\t\t3.Show\n\t\t\t\t\t4.Find size of stack\n\t\t\t\t\t";
	cout<<"5.Evaluate expression\n\t\t\t\t\t6.Infix to Postfix conversion\n\t\t\t\t\t7.Infix to Prefix\n\t\t\t\t\t8.exit"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter the choice : ";
	cin>>ch;

	switch(ch)
	{
		case 1 : st.push();break;
		case 2: st.pop();break;
		case 3: st.show();break;
		case 8: cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING STACK "<<endl;break;break;
		case 4 : cout<<endl<<"\t\t\t\t\tThe current size of stack is : "<<st.top+1<<endl;break;
		case 5 : eva_stack();break;
		case 6 : postfix();break;
		case 7 : prefix();break;
		default : cout<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
	}
	getchar();
	cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
	getchar();
	}
}

struct node
{
	int data;
	struct node *next;
};

int i=0;

void traverse(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\t\t\t\t\tList is empty"<<endl;
		return;
	}

	if(head->next == NULL)
	{
		cout<<"\t\t\t\t\tAddress of last node : "<<&head;
		cout<<endl<<"\t\t\t\t\tlast second node does not exist"<<endl;
		return;
	}
	struct node *p;
	//p = new node();
	p = head;
	while(p->next->next!=NULL)
	{
		p = p->next;
	}
	struct node *q = p;
	cout<<"\t\t\t\t\tAddress of last node : "<<p->next;
	cout<<endl<<"\t\t\t\t\tAddress of last second node : "<<&p;
	//delete p;
	//cout<<endl<<p->data<<endl<<p->next<<endl;
	//cout<<endl<<q->data<<endl<<q->next<<endl;
}

void insert_at_end(struct node **head)
{
	struct node *p;
	p = new node();

	cout<<endl<<"\t\t\t\t\tEnter the element : ";
	int x;
	cin>>x;
	p->data = x;
	//p->next = NULL;

	if(*head == NULL)
	{
		*head = p;cout<<"\t\t\t\t\telement added successfully"<<endl;
		i++;
		return;
	}

	struct node *q;
	q = *head;

	while(q->next != NULL)
		q = q->next;

	q->next = p;
	i++;
	cout<<"\t\t\t\t\tElement added successfully"<<endl;

}

void insert_at_front(struct node **head)
{
	struct node *p = new node();
	cout<<endl<<"\t\t\t\t\tEnter the element : ";
	int x;
	cin>>x;
	p->data = x;
	p->next = NULL;

	if(*head == NULL)
	{
		*head = p;cout<<"\t\t\t\t\tElement added successfully"<<endl;
		i++;
		return;
	}

	p->next = *head;
	*head = p;i++;

	cout<<"\t\t\t\t\tElement added successfully"<<endl;
}

void insert_at_pos(struct node **head,int x)
{
	int k=1,d;
    if(*head == NULL)
    {
            cout<<endl<<"\n\t\t\t\t\tPosition does not exist "<<endl;
                return;
    }
	struct node *p = new node();
	cout<<"\t\t\t\t\tEnter the Element : ";
	cin>>d;
	p->next = NULL;
	p->data = d;

	struct node *q = *head;
	struct node *a = q;

	while(q->next!=NULL && k<x)
	{
		a = q;
		q = q->next;
		k++;
	}
	if(k<x)
	{
		cout<<endl<<"\t\t\t\t\tPosition does not exist "<<endl;
		return;
	}

	//a->next = p;
	p->next = q;
	a->next = p;
	i++;
	cout<<endl<<"\t\t\t\t\tElement added successfully"<<endl;
}

void delete_at_end(struct node **head)
{
	struct node *p;
	//p = new node();

	if(*head == NULL)
	{
		cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
		return;
	}

	if((*head)->next == NULL)
	{
		p = *head;
		delete p;
		p = NULL;
		*head = NULL;
		i--;
		cout<<"\t\t\t\t\tElement deleted successfully"<<endl;
		return;
	}
	p  = *head;

	while(p->next->next != NULL)
	{
		p = p->next;
	}

	delete p->next;
	p->next = NULL;
	i--;
	cout<<"\t\t\t\t\tElement deleted successfully"<<endl;

}

void delete_at_front(struct node **head)
{
	struct node *p;

	if(*head == NULL)
	{
	 	cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

	if((*head)->next == NULL)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                cout<<"\t\t\t\t\tElement deleted successfully"<<endl;
		i--;
                return;
        }

	p = *head;
	*head = (*head)->next;
	delete p;
	p = NULL;
	i--;
	cout<<"\t\t\t\t\tElement deleted successfully"<<endl;

}

void display(struct node *head)
{
	struct node *p = head;
	cout<<endl<<"\t\t\t\t\tThe list is as follows : "<<endl<<endl<<"\t\t\t\t\t";
	while(p != NULL)
	{
	cout<<"|"<<p->data<<"|"<<" -> ";
	p = p->next;
	}
	cout<<"NULL"<<endl<<endl;
}

void delete_at_pos(struct node **head,int x)
{
	int k=1;
	struct node *p;
	if(*head == NULL)
	{
	cout<<endl<<"\t\t\t\t\tList is empty "<<endl;
		return;
	}
	p = *head;
	struct node *q = p;
	while(p->next!=NULL && k<x)
	{
		q = p;
		p = p->next;
		k++;
	}

	if(k<x)
	{
		cout<<endl<<"\t\t\t\t\tPosition does not exist in list"<<endl;
		return;
	}

	q->next = p->next;
	delete p;
	p = NULL;
	i--;
	cout<<endl<<"\t\t\t\t\tNode delete successfully"<<endl;
}

void reverse_1(struct node **head)
{
	if(*head == NULL)
	{
		cout<<endl<<"\t\t\t\t\tList is empty "<<endl;
		return;
	}

	struct node *p,*q,*r;

	r = *head;
	p = *head;
	q = NULL;
	while(r!=NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	*head = q;
	cout<<"\t\t\t\t\tLIST REVERSED"<<endl;
}

void singly_list()
{
    struct node *head = new node();
	head = NULL;
	int x = 1;
	i=0;
	while(x!=10)
	{
	    system("cls");
    cout<<endl<<"\t\t\t\t****** WELCOME TO LINKED LIST ********"<<endl<<endl;
	cout<<endl<<"\t\t\t\t\t**** WHAT DO YOU WANT TO DO? *******"<<endl<<endl;
	cout<<"\t\t\t\t\t1.Traverse\n\t\t\t\t\t2.Insert_at_end\n\t\t\t\t\t3.Insert_at_front\n\t\t\t\t\t4.Delete_at_end\n\t\t\t\t\t5.Delete_at_front\n\t\t\t\t\t6.Display\n";
	cout<<"\t\t\t\t\t7.delete_from_specified\n\t\t\t\t\t8.insert_at_position\n\t\t\t\t\t9.reverse\n\t\t\t\t\t10.exit\n\n";
	cout<<"\t\t\t\t\tEnter the choice : ";
	cin>>x;

	switch(x)
	{
		case 1:	traverse(head);break;
		case 2 : insert_at_end(&head);break;
		case 3 : insert_at_front(&head);break;
		case 4 : delete_at_end(&head);break;
		case 5 : delete_at_front(&head);break;
		case 6 : display(head);break;
		case 7 : int a;cout<<"\t\t\t\t\tEnter the position : ";cin>>a;
			if(a==1)
			delete_at_front(&head);
			else
			delete_at_pos(&head,a);break;
		case 8 : int x;cout<<"\t\t\t\t\tEnter the position : ";cin>>a;
                        if(a==1)
                        insert_at_front(&head);
			else if(i == (a-1))
			insert_at_end(&head);
                        else
                        insert_at_pos(&head,a);break;
		case 9 :reverse_1(&head);break;
		case 10:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING LINKED LIST "<<endl;break;break;
		default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENETERED"<<endl;
	}
	getchar();
	cout<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
	getchar();
	}

}

int i_1=0;

void cir_traverse(struct node *head)
{
        if(head==NULL)
        {
                cout<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if(head->next == head)
        {
                cout<<"\t\t\t\t\tAddress of last node : "<<&head;
                cout<<endl<<"\t\t\t\t\tlast second node does not exist"<<endl;
                return;
        }
        struct node *p;
        p = head;
        while(p->next->next!=head)
        {
                p = p->next;
        }
        struct node *q = p;
        cout<<"\t\t\t\t\tAddress of last node : "<<p->next;
        cout<<endl<<"\t\t\t\t\tAddress of last second node : "<<&p;
}

void cir_insert_at_end(struct node **head)
{
        struct node *p;
        p = new node();

        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
	p->next = *head;
        if(*head == NULL)
        {
		*head = p;
		(*head)->next = *head;
		cout<<"\t\t\t\t\tnode added successfully"<<endl;
                i_1++;
                return;
        }

        struct node *q;
        q = *head;

        while(q->next != *head)
                q = q->next;

        q->next = p;
        i_1++;
        cout<<"\t\t\t\t\tnode added successfully"<<endl;

}

void cir_insert_at_front(struct node **head)
{
        struct node *p = new node();
        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = *head;

        if(*head == NULL)
        {
		p->next = p;
                *head = p;cout<<"\t\t\t\t\tNode added successfully"<<endl;
                i_1++;
                return;
        }

	struct node *q;
	q = *head;

	while(q->next != *head)
		q = q->next;

        p->next = *head;
        *head = p;
	q->next = *head;
        cout<<"\t\t\t\t\tNode added successfully"<<endl;
        i_1++;

}

void cir_insert_at_pos(struct node **head,int x)
{
        int k=1,d;
        if(*head == NULL)
        {
            cout<<endl<<"\n\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }
        struct node *p = new node();
        cout<<"\n\t\t\t\t\tEnter the data of the node : ";
        cin>>d;
        p->next = NULL;
        p->data = d;

        struct node *q = *head;
        struct node *a = q;

        while(q->next!= *head && k<x)
        {
                a = q;
                q = q->next;
                k++;
        }
        if(k<x)
        {
                cout<<endl<<"\n\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }

        p->next = q;
        a->next = p;
        i_1++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void cir_delete_at_end(struct node **head)
{
        struct node *p;

        if(*head == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                i_1--;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                return;
        }
        p  = *head;

        while(p->next->next != *head)
        {
                p = p->next;
        }

        delete p->next;
        p->next = *head;
        i_1--;
        cout<<"\t\t\t\t\tNode deleted successfully"<<endl;

}

void cir_delete_at_front(struct node **head)
{
        struct node *p;

        if(*head == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                i_1--;
                return;
        }

        p = *head;

	struct node *q = *head;

	while(q->next != *head)
		q = q->next;

        *head = (*head)->next;
        delete p;
        p = NULL;
        i_1--;
	q->next = *head;
        cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
}

void cir_display(struct node *head)
{
        struct node *p = head;
        int a =0;
        cout<<endl<<"\t\t\t\t\tThe list is as follows : "<<endl<<endl;
        if(head == NULL)
            return;
	if(head->next == head)
	{
		cout<<"\t\t\t\t\t"<<"->|"<<p->data<<"|->";
		return;
	}
	cout<<"\t\t\t\t\t->";
        while(p->next != head)
        {
        cout<<"|"<<p->data<<"|->";
        p = p->next;
        a++;
        }
	 cout<<"|"<<p->data<<"|->";

        p = p->next;
        cout<<endl<<endl;
}

void cir_delete_at_pos(struct node **head,int x)
{
        int k=1;
        struct node *p;
        if(*head == NULL)
        {
        cout<<endl<<"\t\t\t\t\tList is empty "<<endl;
                return;
        }
        p = *head;
        struct node *q = p;
        while(p->next!= *head && k<x)
        {
                q = p;
                p = p->next;
                k++;
        }

        if(k<x)
        {
                cout<<endl<<"\t\t\t\t\tPosition does not exist in list"<<endl;
                return;
        }

        q->next = p->next;
        delete p;
        p = NULL;
        i_1--;
        cout<<endl<<"\t\t\t\t\tNode delete successfully"<<endl;
}

void cir_list()
{
        i_1 = 0;
        struct node *head = new node();
        head = NULL;
        int x = 1;
        while(x!=9)
        {
            system("cls");
            cout<<endl<<"\t\t\t\t***** WELCOME TO CIRCULAR LINKED LIST ******"<<endl<<endl;
        cout<<endl<<"\t\t\t\t\t *** WHAT DO YOU WANT TO DO? ****"<<endl<<endl;
        cout<<"\t\t\t\t\t1.Traverse\n\t\t\t\t\t2.Insert_at_end\n\t\t\t\t\t3.Insert_at_front\n\t\t\t\t\t4.Delete_at_end\n\t\t\t\t\t5.Delete_at_front\n\t\t\t\t\t6.Display\n";
        cout<<"\t\t\t\t\t7.delete_from_specified\n\t\t\t\t\t8.insert_at_position\n\t\t\t\t\t9.exit\n\n";
        cout<<"\t\t\t\t\tEnter the choice : ";
        cin>>x;

        switch(x)
        {
                case 1: cir_traverse(head);break;
                case 2 : cir_insert_at_end(&head);break;
                case 3 : cir_insert_at_front(&head);break;
                case 4 : cir_delete_at_end(&head);break;
                case 5 : cir_delete_at_front(&head);break;
                case 6 : cir_display(head);break;
                case 7 : int a;cout<<"\t\t\t\t\tEnter the position : ";cin>>a;
                        if(a==1)
                        cir_delete_at_front(&head);
                        else
                        cir_delete_at_pos(&head,a);break;
                case 8 : int x;cout<<"\t\t\t\t\tEnter the position : ";cin>>x;
                        if(x==1)
                        cir_insert_at_front(&head);
                        else if(i_1 == (x-1))
                        cir_insert_at_end(&head);
                        else
                        insert_at_pos(&head,x);break;
                case 9 :cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING CIRCULAR LINKED LIST "<<endl;break;break;
                default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
        }
        getchar();
        cout<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
        getchar();
        }

}

struct dll_node
{
        int data;
        struct dll_node *next;
        struct dll_node *prev;
};

int i_2=0;

void dll_insert_at_end(struct dll_node **head)
{
        struct dll_node *p;
        p = new dll_node();

        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;
                (*head)->next = NULL;
                cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
                i_2++;
                return;
        }

        struct dll_node *q;
        q = *head;

        while(q->next != NULL)
                q = q->next;

        q->next = p;
	p->prev = q;
        i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;

}

void dll_insert_at_front(struct dll_node **head)
{
        struct dll_node *p = new dll_node();
        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
                i_2++;
                return;
        }

	p->next = *head;
	(*head)->prev = p;
	*head = p;
	i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void dll_insert_at_pos(struct dll_node **head,int x)
{
        int k=1,d;
         if(*head == NULL)
        {
            cout<<endl<<"\n\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }
        struct dll_node *p = new dll_node();
        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        cin>>d;
        p->next = NULL;
	    p->prev = NULL;
        p->data = d;

        struct dll_node *q = *head;
        struct dll_node *a = q;

        while(q->next!= NULL && k<x)
        {
                a = q;
                q = q->next;
                k++;
        }
        if(k<x)
        {
                cout<<endl<<"\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }

        a->next = p;
	p->prev = a;
	q->prev = p;
	p->next = q;

        i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void dll_delete_at_front(struct dll_node **head)
{
        struct dll_node *p;

        if((*head) == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == NULL)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                i_2--;
                return;
        }

        p = *head;

        *head = (*head)->next;
        delete p;
        p = NULL;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode deleted successfully"<<endl;

}

void dll_display(struct dll_node *head)
{
        struct dll_node *p = head;
        cout<<endl<<"\t\t\t\t\tThe list is as follows : "<<endl;
        if(head == NULL)
        {
		cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
		return;
        }
        cout<<"\t\t\t\t\t";
        while(p != NULL)
        {
        cout<<p->data<<" <-> ";
        p = p->next;
        }
        cout<<"NULL";
        cout<<endl<<endl;
}

void dll_delete_at_pos(struct dll_node **head,int x)
{
        int k=1;
        struct dll_node *p;
        if(*head == NULL)
        {
        cout<<endl<<"\t\t\t\t\tList is empty "<<endl;
                return;
        }
        p = *head;
        struct dll_node *q = p;

        while(p->next!= NULL && k<x)
        {
                q = p;
                p = p->next;
                k++;
        }

        if(k<x)
        {
                cout<<endl<<"\t\t\t\t\tPosition does not exist in list"<<endl;
                return;
        }

        q->next = p->next;
	//p->next->prev = q;
        delete p;
        p = NULL;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode delete successfully"<<endl;
}

void dll_delete_at_end(struct dll_node **head)
{
        struct dll_node *p;

        if(*head == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == NULL)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                i_2--;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                return;
        }
        p  = *head;

        while(p->next != NULL)
        {
                p = p->next;
        }

        p->prev->next = NULL;
        delete p;
	    p = NULL;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode deleted successfully"<<endl;
}

void doubly_list()
{
        struct dll_node *head = new struct dll_node();
        head = NULL;
        int x = 1;
        i_2=0;
        while(x!=8)
        {
            system("cls");
            cout<<endl<<"\t\t\t\t******* WELCOME TO DOUBLY LINKED LIST ********"<<endl<<endl;
        cout<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO?"<<endl<<endl;
        cout<<"\t\t\t\t\t1.Insert_at_end\n\t\t\t\t\t2.Insert_at_front\n\t\t\t\t\t3.Delete_at_end\n\t\t\t\t\t4.Delete_at_front\n\t\t\t\t\t5.Display\n\t\t\t\t\t";
        cout<<"6.delete_from_specified\n\t\t\t\t\t7.insert_at_position\n\t\t\t\t\t8.exit\n\n";
        cout<<"\t\t\t\t\tEnter the choice : ";
        cin>>x;

        switch(x)
        {
                case 1 : dll_insert_at_end(&head);break;
                case 2 : dll_insert_at_front(&head);break;
                case 3 : dll_delete_at_end(&head);break;
                case 4 : dll_delete_at_front(&head);break;
                case 5 : dll_display(head);break;
                case 6 : int a;cout<<endl<<"\t\t\t\t\tEnter the position : ";cin>>a;
                        if(a==1)
                        dll_delete_at_front(&head);
                        else if(i_2 == (a-1))
                            dll_delete_at_end(&head);
                        else
                        dll_delete_at_pos(&head,a);break;
                case 7 : int x;cout<<endl<<"\t\t\t\t\tEnter the position : ";cin>>x;
                        if(x==1)
                        dll_insert_at_front(&head);
                        else if(i_2 == (x-1))
                        dll_insert_at_end(&head);
                        else
                        dll_insert_at_pos(&head,x);break;
                case 8:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING DOUBLY LINKED LIST "<<endl;break;break;
                default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;

          }
          getchar();
          cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE"<<endl;
          getchar();
	}
}

void cdll_insert_at_end(struct dll_node **head)
{
        struct dll_node *p;
        p = new dll_node();

        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;
                (*head)->next = *head;
                (*head)->prev = *head;
                cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
                i_2++;
                return;
        }

        struct dll_node *q;
        q = *head;

        while(q->next != *head)
                q = q->next;

        q->next = p;
	p->prev = q;
	p->next = *head;
	(*head)->prev = p;
        i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void cdll_insert_at_front(struct dll_node **head)
{
        struct dll_node *p = new dll_node();
        cout<<endl<<"\t\t\t\t\tEnter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
                (*head)->next = (*head)->prev = *head;
                i_2++;
                return;
        }

        struct dll_node *q = *head;
        while(q->next != *head)
            q = q->next;

    p->next = (*head);
    (*head)->prev = p;
    (*head) = p;
    q->next = (*head);
    (*head)->prev = q;
	i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void cdll_insert_at_pos(struct dll_node **head,int x)
{
        int k=1,d;
         if(head == NULL)
        {
            cout<<endl<<"\n\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }
        struct dll_node *p = new dll_node();
        cout<<endl<<"\n\t\t\t\t\tEnter the data of the node : ";
        cin>>d;
        p->next = NULL;
	    p->prev = NULL;
        p->data = d;

        struct dll_node *q = *head;
        struct dll_node *a = q;

        while(q->next!= *head && k<x)
        {
                a = q;
                q = q->next;
                k++;
        }
        if(k<x)
        {
                cout<<endl<<"\t\t\t\t\tPosition does not exist "<<endl;
                return;
        }

        a->next = p;
	p->prev = a;
	q->prev = p;
	p->next = q;

        i_2++;
        cout<<endl<<"\t\t\t\t\tNode added successfully"<<endl;
}

void cdll_delete_at_front(struct dll_node **head)
{
        struct dll_node *p;

        if((*head) == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                i_2--;
                return;
        }

        p = *head;
        struct dll_node *q = *head;

        while(q->next != *head)
            q = q->next;
        *head = (*head)->next;
        q->next = *head;
        (*head)->prev = q;
        delete p;
        p = NULL;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode deleted successfully"<<endl;

}

void cdll_display(struct dll_node *head)
{
        struct dll_node *p = head;
        cout<<endl<<"\t\t\t\t\tThe list is as follows : "<<endl;
        if(head == NULL)
        {
		cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
		return;
        }
        cout<<"\t\t\t\t\t <-> ";

        while(p->next != head)
        {
        cout<<p->data<<" <-> ";
        p = p->next;
        }

        cout<<p->data<<" <-> ";
        cout<<endl<<endl;
}

void cdll_delete_at_pos(struct dll_node **head,int x)
{
        int k=1;
        struct dll_node *p;
        if(*head == NULL)
        {
        cout<<endl<<"\t\t\t\t\tList is empty "<<endl;
                return;
        }
        p = *head;
        struct dll_node *q = p;
        while(p->next!= *head && k<x)
        {
                q = p;
                p = p->next;
                k++;
        }

        if(k<x)
        {
                cout<<endl<<"\t\t\t\t\tPosition does not exist in list"<<endl;
                return;
        }

        q->next = p->next;
	//p->next->prev = q;
        delete p;
        p = NULL;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode delete successfully"<<endl;
}

void cdll_delete_at_end(struct dll_node **head)
{
        struct dll_node *p;

        if(*head == NULL)
        {
                cout<<endl<<"\t\t\t\t\tList is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                i_2--;
                cout<<"\t\t\t\t\tNode deleted successfully"<<endl;
                return;
        }

        p = (*head)->prev;
        p->prev->next = *head;
        (*head)->prev = p->prev;
        delete p;
        i_2--;
        cout<<endl<<"\t\t\t\t\tNode deleted successfully"<<endl;
}

void cir_doubly_list()
{
    struct dll_node *head = new struct dll_node();
        head = NULL;
        int x = 1;
        i_2=0;
        while(x!=8)
        {
            system("cls");
            cout<<endl<<"\t\t\t\t******* WELCOME TO CIRCULAR DOUBLY LINKED LIST ********"<<endl<<endl;
        cout<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO?"<<endl<<endl;
        cout<<"\t\t\t\t\t1.Insert_at_end\n\t\t\t\t\t2.Insert_at_front\n\t\t\t\t\t3.Delete_at_end\n\t\t\t\t\t4.Delete_at_front\n\t\t\t\t\t5.Display\n\t\t\t\t\t";
        cout<<"6.delete_from_specified\n\t\t\t\t\t7.insert_at_position\n\t\t\t\t\t8.exit\n\n";
        cout<<"\t\t\t\t\tEnter the choice : ";
        cin>>x;

        switch(x)
        {
                case 1 : cdll_insert_at_end(&head);break;
                case 2 : cdll_insert_at_front(&head);break;
                case 3 : cdll_delete_at_end(&head);break;
                case 4 : cdll_delete_at_front(&head);break;
                case 5 : cdll_display(head);break;
                case 6 : int a;cout<<endl<<"\t\t\t\t\tEnter the position : ";cin>>a;
                        if(a==1)
                        cdll_delete_at_front(&head);
                        else
                        cdll_delete_at_pos(&head,a);break;
                case 7 : int x;cout<<endl<<"\t\t\t\t\tEnter the position : ";cin>>x;
                        if(x==1)
                        cdll_insert_at_front(&head);
                        else if(i_2 == (x-1))
                        cdll_insert_at_end(&head);
                        else
                        cdll_insert_at_pos(&head,x);break;
                default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
                case 8:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING CIRCULAR DOUBLY LINKED LIST "<<endl;break;break;

          }
          getchar();
          cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE"<<endl;
          getchar();
	}
}

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

void bst_insert(struct tree **root)
{
	int x;
	struct tree *temp;
	struct tree *p = new struct tree();
	cout<<"\t\t\t\t\tEnter the element : ";
	cin>>x;
	p->data = x;

	p->left = p->right = NULL;

	if(*root == NULL)
	{
		*root = p;
		cout<<"\t\t\t\t\tElement inserted successfully";
		return;
	}
	struct tree *q;
	temp = *root;

	while(temp!=NULL)
	{

		q = temp;

		if(x > temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if(x > q->data)
		q->right = p;
	else
		q->left = p;
	cout<<"\t\t\t\t\tElement inserted successfully"<<endl;
}


void preorder(struct tree *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct tree *root)
{
        if(root == NULL)
                return;
        inorder(root->left);
	cout<<root->data<<" ";
        inorder(root->right);
}

void postorder(struct tree *root)
{
        if(root == NULL)
                return;
        postorder(root->left);
        postorder(root->right);
	cout<<root->data<<" ";
}

void bst_max(struct tree *root)
{
	struct tree *q;
	q = root;
	if(root == NULL)
    {
		cout<<endl<<"\t\t\t\t\tTree is empty"<<endl;
		return;
    }

	while(q->right!=NULL)
		q = q->right;

	cout<<endl<<"\t\t\t\t\tThe max element is : "<<q->data<<endl;
}

void bst_min(struct tree *root)
{
        struct tree *q;
        q = root;
	 if(root == NULL)
     {
            cout<<endl<<"\t\t\t\t\tTree is empty"<<endl;
            return;
     }

        while(q->left!=NULL)
                q = q->left;

        cout<<endl<<"\t\t\t\t\tThe min element is : "<<q->data<<endl;
}

void delete_node(struct tree *root)
{
	struct tree *temp,*q;
	if(root == NULL)
	{
		cout<<"\t\t\t\t\tTree is empty"<<endl;
		return ;
	}

	cout<<"\t\t\t\t\tEnter the element : ";
	int x;
	cin>>x;

	temp= root;

	while(temp!=NULL)
	{
		 if(x == temp->data)
                        break;

		q = temp;

		if(x>temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if(temp->right == NULL && temp->left == NULL)
	{
		//if(q == temp)
		//{
		//	temp = NULL;
		//}

		if(q->left == temp)
		{
			delete temp;
			q->left = NULL;
			temp = NULL;
		}
		else
		{
			delete temp;
			q->right = NULL;
			temp = NULL;
		}
	}
	else if(temp->left != NULL && temp->right!= NULL)
	{
		q = temp;
		q = q->left;
		struct tree *p;

		if(q->right == NULL)
		{
			temp->data = q->data;
			temp->left = q->left;
			delete q;
			q = NULL;
		}
		else
		{
			while(q->right != NULL)
			{
			p = q;
			 q = q->right;
			}

			temp->data = q->data;
			delete q;
			q = NULL;
			p->right = NULL;
		}
	}
	else
	{
		if(temp->right!=NULL)
		{
			if(temp == q->left)
			{
				q->left = temp->right;
				delete temp;
				temp = NULL;
			}
			else
			{
				q->right = temp->right;
				delete temp;
				temp = NULL;
			}
		}
		else
		{
			if(temp == q->left)
                        {
                                q->left = temp->left;
                                delete temp;
                                temp = NULL;
                        }
                        else
                        {
                                q->right = temp->left;
                                delete temp;
                                temp = NULL;
                        }
		}
	}
	cout<<"\t\t\t\t\tElement deleted successfully"<<endl;
}

void bst()
{
    struct tree *root = new struct tree();
	root = NULL;

	int ch=1;

	while(ch!=8)
	{
	    system("cls");
		cout<<endl<<endl<<"\t\t\t\t******* WELCOME TO BINARY SEARCH TREE ******** "<<endl<<endl;
		cout<<"\t\t\t\t\tWHAT DO YOU WANT TO DO?"<<endl<<endl;

		cout<<"\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.Preorder traversal\n\t\t\t\t\t3.Inorder traversal\n\t\t\t\t\t4.Postorder traversal\n\t\t\t\t\t5.Max element\n\t\t\t\t\t6.Min element\n\t\t\t\t\t7.Deletion\n\t\t\t\t\t8.Exit\n\n";
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:bst_insert(&root);break;
			case 2:cout<<"\t\t\t\t\tPreorder is : "<<endl<<"\t\t\t\t\t";preorder(root);cout<<endl;break;
			case 3:cout<<"\t\t\t\t\tInorder is : "<<endl<<"\t\t\t\t\t";inorder(root);cout<<endl;break;
			case 4:cout<<"\t\t\t\t\tPostorder is : "<<endl<<"\t\t\t\t\t";postorder(root);cout<<endl;break;
			case 5:bst_max(root);break;
			case 6:bst_min(root);break;
			case 7:delete_node(root);break;
			case 8:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING BINARY SEARCH TREE "<<endl;break;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
		getchar();
	}
}

void bt_insert(struct tree **root)
{
    struct tree *node = new struct tree();

    cout<<"\t\t\t\t\tENTER THE ELEMENT : ";
    cin>>node->data;
    node->right = node->left = NULL;

    if(*root == NULL)
    {
        *root = node;
        cout<<"\t\t\t\t\tElement added successfully"<<endl;
        return;
    }

        queue<struct tree*>q;
        q.push(*root);
        struct tree *temp;

        while(q.empty() == false)
        {
            temp = q.front();
            q.pop();

            if(temp->left == NULL)
            {
                temp->left = node;
                break;
            }

            if(temp->right == NULL)
            {
                temp->right = node;
                break;
            }

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
        cout<<endl<<"\t\t\t\t\tElement added successfully"<<endl;
}

void no_of_nodes(struct tree *root)
{
    if(root == NULL)
    {
        cout<<endl<<"\t\t\t\t\tThe number of node in tree are : 0"<<endl;
        return;
    }

        queue<struct tree*>q;
        q.push(root);
        struct tree *temp;
        int no_nodes = 0;

        while(q.empty() == false)
        {
            temp = q.front();
            q.pop();
            no_nodes++;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
         cout<<endl<<"\t\t\t\t\tThe number of nodes in tree are : "<<no_nodes<<endl;
}

void leaf_node(struct tree *root)
{
    if(root == NULL)
        return;
    if(!root->left && !root->right)
    {
        cout<<root->data<<" ";
        return;
    }
    leaf_node(root->left);
    leaf_node(root->right);
}

void internal_nodes(struct tree *root)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    else
        cout<<root->data<<" ";
    internal_nodes(root->left);
    internal_nodes(root->right);
}

void find_height(struct tree *root)
{
    queue<struct tree*>q;
    q.push(root);
    q.push(NULL);

    if(root == NULL)
    {
        cout<<endl<<"\t\t\t\t\tThe tree is empty"<<endl;
        return;
    }

    long int height = 0;

    while(q.empty() == false)
    {
        struct tree *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            if(q.empty() == false)
                q.push(NULL);
                height++;
        }
        else
        {
        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
        }
    }
    cout<<endl<<"\t\t\t\t\tThe height of the tree is : "<<height<<endl;
}

void mirror(struct tree *root,struct tree **m)
{
    if(root == NULL)
    {
        m = NULL;
        return;
    }
    *m = new struct tree();
    (*m)->data = root->data;
    mirror(root->left,&((*m)->right));
    mirror(root->right,&((*m)->left));
}

void binary_tree()
{
    struct tree *root = new struct tree();
	root = NULL;
	struct tree *m;

	int ch=1;

	while(ch!=10)
	{
	    system("cls");
		cout<<endl<<endl<<"\t\t\t\t******* WELCOME TO BINARY TREE ******** "<<endl<<endl;
		cout<<"\t\t\t\t\t*NOTE : THE HEIGHT OF ROOT IS 1"<<endl<<endl;
		cout<<"\t\t\t\t\tWHAT DO YOU WANT TO DO?"<<endl<<endl;

		cout<<"\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.Preorder traversal\n\t\t\t\t\t3.Inorder traversal\n\t\t\t\t\t4.Postorder traversal\n\t\t\t\t\t5.Find number of nodes\n\t\t\t\t\t6.Find leaf nodes\n\t\t\t\t\t";
        cout<<"7.Find Internal nodes\n\t\t\t\t\t8.Find Height\n\t\t\t\t\t9.Find mirror image\n\t\t\t\t\t10.exit\n\n";
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:bt_insert(&root);break;
			case 2:cout<<"\t\t\t\t\tPreorder is : "<<endl<<"\t\t\t\t\t";preorder(root);cout<<endl;break;
			case 3:cout<<"\t\t\t\t\tInorder is : "<<endl<<"\t\t\t\t\t";inorder(root);cout<<endl;break;
			case 4:cout<<"\t\t\t\t\tPostorder is : "<<endl<<"\t\t\t\t\t";postorder(root);cout<<endl;break;
			case 6:if(root == NULL)
                    cout<<endl<<"\t\t\t\t\tThe tree is empty"<<endl;
                    else
                    {
                        cout<<endl<<"\t\t\t\t\tThe leaf nodes are : ";
                        leaf_node(root);cout<<endl;
                    }break;
			case 5:no_of_nodes(root);break;
			case 7 :if(root == NULL)
                    cout<<endl<<"\t\t\t\t\tThe tree is empty"<<endl;
                    else
                    {
                        cout<<endl<<"\t\t\t\t\tThe Internal nodes are : ";
                        internal_nodes(root);cout<<endl;
                    }break;
            case 8:find_height(root);break;
            case 9:if(root == NULL)
                    cout<<endl<<"\t\t\t\t\tThe tree is empty"<<endl;
                    else
                    {
                        mirror(root,&m);
                        cout<<"\t\t\t\tPreorder traversal of original tree : ";preorder(root);
                        cout<<endl<<"\t\t\t\tPreorder traversal of mirror tree : ";preorder(m);
                        cout<<endl;
                        delete m;
                        m = NULL;
                    }break;
            case 10:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING BINARY TREE "<<endl;break;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
		getchar();
	}
}

void queue_using_stack()
{
    system("cls");
    stack<int> s1;
    stack<int>s2;
    int x;
	int ch=1;

	while(ch != 4)
	{
	    system("cls");
	    cout<<"\n\t\t\t\t****** WELCOME TO QUEUE DATA STRUCTURE USING STACK(INT TYPE) *********"<<endl;
		cout<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO WITH QUEUE?"<<endl;
		cout<<"\n\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.deletion\n\t\t\t\t\t3.show\n\t\t\t\t\t4.exit"<<endl<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1 : cout<<endl<<"\t\t\t\t\tEnter the element : ";
                     cin>>x;
                     s1.push(x);
                     cout<<"\t\t\t\t\tElement added successfully"<<endl;
                     break;
			case 2 : if(s1.empty() == true)
                            cout<<endl<<"\t\t\t\t\t!!! QUEUE IS EMPTY !!!!"<<endl;
                    else
                    {
                        while(s1.empty() == false)
                        {
                            s2.push(s1.top());
                            s1.pop();
                        }
                        cout<<endl<<"\t\t\t\t\tElement "<<s2.top()<<" is deleted "<<endl;
                        s2.pop();

                        while(s2.empty() == false)
                        {
                            s1.push(s2.top());
                            s2.pop();
                        }
                    }
                    break;

			case 3 :    cout<<"\n\t\t\t\t\tThe element of queue are as follows : "<<endl;
                        while(s1.empty() == false)
                        {
                            s2.push(s1.top());
                            s1.pop();
                        }
                        cout<<"\t\t\t\t\t";
                        while(s2.empty() == false)
                        {
                            s1.push(s2.top());
                            cout<<s2.top()<<" ";
                            s2.pop();
                        }

                        cout<<endl;
                        break;
			case 4 : cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING QUEUE USING STACK "<<endl;break;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY TO CONTINUE"<<endl;char ch;

		 getchar();
	}
}

void stack_using_queue()
{
    system("cls");
    queue<int>q1;
    queue<int>q2;
    int x;
	int ch=1;

	while(ch != 4)
	{
	    system("cls");
	    cout<<"\n\t\t\t\t****** WELCOME TO STACK DATA STRUCTURE USING QUEUE(INT TYPE) *********"<<endl;
		cout<<endl<<"\t\t\t\t\tWHAT DO YOU WANT TO DO WITH STACK?"<<endl;
		cout<<"\n\t\t\t\t\t1.Push\n\t\t\t\t\t2.Pop\n\t\t\t\t\t3.show\n\t\t\t\t\t4.exit"<<endl<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1 : cout<<endl<<"\t\t\t\t\tEnter the element : ";
                     cin>>x;
                     while(q1.empty() == false)
                     {
                         q2.push(q1.front());
                         q1.pop();
                     }
                     q1.push(x);

                     while(q2.empty() == false)
                     {
                         q1.push(q2.front());
                         q2.pop();
                     }
                     cout<<"\t\t\t\t\tElement added successfully"<<endl;
                     break;
			case 2 : if(q1.empty() == true)
                            cout<<endl<<"\t\t\t\t\t!!! STACK IS EMPTY !!!"<<endl;
                      else
                      {
                          cout<<endl<<"\t\t\t\t\tElement : "<<q1.front()<<" is deleted "<<endl;
                          q1.pop();
                      }break;

			case 3 :    cout<<endl<<"\t\t\t\t\tThe element of stack are as follows : "<<endl;
                        cout<<"\t\t\t\t\t";
                        while(q1.empty() == false)
                        {
                            cout<<q1.front()<<endl;
                            q2.push(q1.front());
                            q1.pop();
                            cout<<"\t\t\t\t\t";
                        }

                        while(q2.empty() == false)
                        {
                            q1.push(q2.front());
                            q2.pop();
                        }
                        cout<<endl;
                        break;
			case 4 : cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING STACK USING QUEUE "<<endl;break;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY TO CONTINUE"<<endl;char ch;

		 getchar();
	}
}

void show_queue(struct node *head)
{
    struct node *temp = head;
        if(head == NULL)
        {
            cout<<endl<<"\t\t\t\t\t!!! QUEUE IS EMPTY !!!"<<endl;
            return;
        }
        cout<<endl<<"\t\t\t\t\tTHE DEQUE IS AS FOLLOWS : "<<endl<<"\t\t\t\t\t";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
}

void my_deque()
{
    int ch=1;
    struct node *head = new node();
    head = NULL;

    while(ch!=6)
    {
        system("cls");
        cout<<endl<<"\t\t\t\t******* WELCOME TO DEQUE *********"<<endl<<endl;
        cout<<"\t\t\t\t\t WHAT DO YOU WANT TO DO? "<<endl<<endl;

        cout<<"\t\t\t\t\t1.insert_at_front\n\t\t\t\t\t2.insert_at_end\n\t\t\t\t\t3.delete_at_front\n\t\t\t\t\t4.delete_from_end\n";
        cout<<"\t\t\t\t\t5.show\n\t\t\t\t\t6.exit"<<endl<<endl;
        cout<<"\t\t\t\t\tEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
        case 2 : insert_at_end(&head);break;
		case 1 : insert_at_front(&head);break;
		case 4 : delete_at_end(&head);break;
		case 3 : delete_at_front(&head);break;
		case 5 : show_queue(head);break;
		case 6:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING DEQUE "<<endl;break;break;
		default: cout<<endl<<"\t\t\t\t\t!!! WRONG CHOICE ENTERED !!!"<<endl;
        }
        getchar();
        cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
        getchar();
    }
}

void Bubble_sort(int arr[],int n)
{
    int temp = n-1;
    temp = temp*temp;

    while(temp--)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                int a = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = a;
            }
        }
    }
}

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_ele=arr[i+1];
        int index = i+1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < min_ele)
            {
                min_ele = arr[j];
                index = j;
            }
        }
        if(arr[i] > min_ele)
        {
        arr[index] = arr[i];
        arr[i] = min_ele;
        }
    }
}

void insertion_sort(int arr[],int n)
{
    int i,j;
    for(i=1;i<=n-1;i++)
    {
        int temp = arr[i];
        j=i;

        while(arr[j-1]>temp && j>=1)
        {
            arr[j]= arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
         j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sorting(int arr[],int n)
{
	int ch1=1;
	while(ch1!=6)
    {
        system("cls");
	cout<<endl<<endl<<endl<<"\t\t\t\t\t**** WHAT TYPE OF SORTING DO YOU WANT TO DO? ****"<<endl;
	cout<<endl<<"\t\t\t\t\t1.Selection_sort\n\t\t\t\t\t2.Bubble_sort\n\t\t\t\t\t3.Insertion_sort\n\t\t\t\t\t4.Merge_sort\n\t\t\t\t\t5.Quick_sort\n\t\t\t\t\t6.Exit\n\n";
	cout<<"\t\t\t\t\tEnter Your Choice : ";
	cin>>ch1;

	switch(ch1)
	{
		case 2:  Bubble_sort(arr,n);cout<<endl<<"\t\t\t\t\tSORTED SUCCESSFULLY"<<endl;break;
		case 1:	 selection_sort(arr,n);cout<<endl<<"\t\t\t\t\tSORTED SUCCESSFULLY"<<endl;break;
		case 3: insertion_sort(arr,n);cout<<endl<<"\t\t\t\t\tSORTED SUCCESSFULLY"<<endl;break;
		case 4:  mergeSort(arr,0,n-1);cout<<endl<<"\t\t\t\t\tSORTED SUCCESSFULLY"<<endl;break;
		case 5: quickSort(arr,0,n-1);cout<<endl<<"\t\t\t\t\tSORTED SUCCESSFULLY"<<endl;break;
		case 6: break;
	}
	getchar();
	cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
	getchar();
    }
}

int insertion(int arr[],int n,int cap)
{
	if(n == cap)
	{
		cout<<endl<<endl<<"\t\t\t\t!!!! SORRY THE ARRAY IS FULL"<<endl;
		return n;
	}
	cout<<endl<<endl<<"\t\t\t\t\tEnter The element : ";
	int ele;
	cin>>ele;
	arr[n] = ele;
	cout<<endl<<endl<<"\t\t\t\t\tELEMENT ADDED SUCCESSFULLY";
	return ++n;
}

int deletion(int arr[],int n)
{
	if(n == 0)
	{
		cout<<endl<<endl<<"\t\t\t\t\t!!! OOPS! ARRAY IS EMPTY";
		return n;
	}

	cout<<endl<<endl<<"\t\t\t\t\tEnter the element to delete : ";
	int ele;
	cin>>ele;
	bool found = false;
	int i,j;

	for(i=0;i<n;i++)
	{
		if(arr[i] == ele)
		{
			found = true;
			break;
		}
	}

	if(found == false)
	{
		cout<<endl<<endl<<"\t\t\t\t!!! SORRY GIVEN ELEMENT IS NOT PRESENT IN ARRAY"<<endl;
		return n;
	}
	else
	{
		for(j=i;j<n-1;j++)
			arr[j] = arr[j+1];
        cout<<endl<<endl<<"\t\t\t\t!!! ELEMENT DELETED SUCCESSFULLY"<<endl;
		return --n;
	}
}

void linear_search(int arr[],int n)
{
    if(n == 0)
    {
        cout<<endl<<endl<<"\t\t\t\t\t!!! OOPS THE ARRAY IS EMPTY"<<endl;
        return;
    }

    cout<<endl<<endl<<"\t\t\t\t\tEnter the element to search for : ";
    int ele;
    cin>>ele;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == ele)
        {
            cout<<endl<<endl<<"\t\t\t\t\t!!! HURRAH !!! THE GIVEN ELEMENT IS PRESENT IN ARRAY AT POSITION : "<<i+1<<endl;
            return;
        }
    }
    cout<<endl<<endl<<"\t\t\t\t\t!!!! OOPS THE GIVEN ELEMENT IS NOT PRESENT IN ARRAY"<<endl;
}

void binary_search(int arr[],int n)
{
    if(n == 0)
    {
        cout<<endl<<endl<<"\t\t\t\t\t!!! OOPS THE ARRAY IS EMPTY"<<endl;
        return;
    }

    cout<<endl<<endl<<"\t\t\t\t\tEnter the element to search for : ";
    int ele;
    cin>>ele;

    int temp[n];

    for(int i=0;i<n;i++)
        temp[i] = arr[i];

    Bubble_sort(temp,n);
    int l = 0;
    int r = n-1;

    while(l <= r)
    {
            int mid = (l+r)/2;
            if(temp[mid] == ele)
            {
                cout<<endl<<endl<<"\t\t\t\t\t!!! HURRAH !!! THE GIVEN ELEMENT IS PRESENT IN ARRAY "<<endl;
                return;
            }
            if(ele<temp[mid])
                r = mid-1;
            else
                l = mid+1;
    }
        cout<<endl<<endl<<"\t\t\t\t\t!!!! OOPS THE GIVEN ELEMENT IS NOT PRESENT IN ARRAY"<<endl;
}

void searching(int arr[],int n)
{
	int ch1=1;

	while(ch1!=3)
	{
	    system("cls");
	cout<<endl<<endl<<"\t\t\t\t\t***** WELCOME TO SEARCHING *****"<<endl<<endl;
	cout<<"\t\t\t\t*** WHAT DO YOU WANT TO DO? ****"<<endl<<endl;

	cout<<"\t\t\t\t\t1.Linear Search\n\t\t\t\t\t2.Binary Search\n\t\t\t\t\t3.Exit\n\n\t\t\t\t";
	cout<<"Enter your choice : ";
	cin>>ch1;

	switch(ch1)
	{
		case 1:linear_search(arr,n);break;
		case 2:binary_search(arr,n);break;
		case 3:break;
	}
	getchar();
	cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
	getchar();
	}
}

void arr()
{
	int ch=1;
	system("cls");
	cout<<endl<<endl<<"\t\t\t\t\tENTER THE CAPACITY OF ARRAY : ";
	int size=0;
	int cap;
	cin>>cap;

	while(cap == 0)
    {
        cout<<endl<<endl<<"\t\t\t\t\tTHE CAPACITY OF ARRAY CANNOT BE 0";
        cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
        getchar();
        getchar();
        system("cls");
        cout<<endl<<endl<<"\t\t\t\t\tENTER THE CAPACITY OF ARRAY : ";
        cin>>cap;
    }

	int arr[cap];

	while(ch!=6)
	{
		system("cls");
		cout<<endl<<"\t\t\t\t**** WELCOME TO ARRAY DATA STRUCTURE *******"<<endl<<endl;
		cout<<"\t\t\t\t\t**** WHAT DO YOU WANT TO DO? *******"<<endl<<endl;
		cout<<"\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.Deletion\n\t\t\t\t\t3.Sorting\n\t\t\t\t\t4.Searching\n\t\t\t\t\t5.Show\n\t\t\t\t\t6.Exit"<<endl<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1: size = insertion(arr,size,cap);break;
			case 2: size = deletion(arr,size);break;
			case 3: sorting(arr,size);break;
			case 4: searching(arr,size);break;
			case 5 :
			    cout<<endl<<endl<<"\t\t\t\t\tThe Array is as follows : "<<endl<<endl<<"\t\t\t\t\t";
			    for(int i=0;i<size;i++)
                    cout<<arr[i]<<" ";
                    break;
            case 6:cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING ARRAY "<<endl;break;break;
			default : cout<<endl<<endl<<"\t\t\t\t\t!!!! WRONG CHOICE ENTERED !!!!";
		}

		getchar();
		cout<<endl<<endl<<"\t\t\t\t\tPRESS ANY TO CONTINUE ";
		getchar();
	}
}


struct avl
{
    int data;
    struct avl *left;
    struct avl *right;
    int height;
};

int height(struct avl *temp)
{
    if(temp == NULL)
        return 0;

    return temp->height;
}

avl* right_rotate(struct avl *node)
{
    struct avl *x = node->left;
    struct avl *y = x->right;

    x->right = node;
    node->left = y;

    node->height = 1+max(height(node->left),height(node->right));
    x->height = 1 + max(height(x->left),height(x->right));
    return x;
}

avl* left_rotate(struct avl *node)
{
    struct avl *x = node->right;
    struct avl *y = x->left;

    x->left = node;
    node->right = y;

    node->height = 1+max(height(node->left),height(node->right));
    x->height = 1 + max(height(x->left),height(x->right));
    return x;
}

int balance_factor(struct avl*temp)
{
    if(temp == NULL)
        return 0;
    return height(temp->left) - height(temp->right);

}

avl* insertion_avl(struct avl *node,int x)
{
    if(node == NULL)
    {
        struct avl *newnode = new avl();
        newnode->data = x;
        newnode->height = 1;
        newnode->left = newnode->right = NULL;
        node = newnode;
        return node;
    }

    if(x < node->data)
        node->left = insertion_avl(node->left,x);
    else
        node->right = insertion_avl(node->right,x);

    node->height = 1+max(height(node->left),height(node->right));

    int bal = balance_factor(node);

    if(bal > 1 && x < node->left->data)
        return right_rotate(node);
    else if(bal < -1 && x> node->right->data)
        return(left_rotate(node));
    else if(bal > 1 && x > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    else if(bal < -1 && x<node->left->data)
    {
        node->right = right_rotate(node->left);
        return left_rotate(node);
    }
    return node;
}

avl* inorder_prede(struct avl* temp)
{
    while(temp->right!=NULL)
        temp = temp->right;
    return temp;
}

avl* delete_avl(struct avl* root,int val)
{
    if(root == NULL)
        return root;

    if(val<root->data)
        root->left = delete_avl(root->left,val);
    else if(val>root->data)
        root->right = delete_avl(root->right,val);
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            struct avl *temp = root->left?root->left:root->right;

            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
            temp = NULL;
        }
        else
        {
            struct avl *temp;
            temp = inorder_prede(root->left);
            root->data = temp->data;

            root->left = delete_avl(root->left,temp->data);
        }
    }
    if(root == NULL)
        return root;

    root->height = 1+max(height(root->left),height(root->right));

    int bal = balance_factor(root);

    if(bal > 1 && balance_factor(root->left)<0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if(bal > 1 && balance_factor(root->left)>=0)
        return right_rotate(root);
    else if(bal < -1 && balance_factor(root->right) >= 0)
    {
        root->right = left_rotate(root->right);
        return left_rotate(root);
    }
    else if(bal < -1 && balance_factor(root->right) < 0)
        return left_rotate(root);

    return root;
}

bool avl_search(struct avl* root,int x)
{
    if(root == NULL)
        return false;
    else
    {
        struct avl* temp = root;
        while(temp!=NULL)
        {
            if(x < temp->data)
                temp = temp->left;
            else if(x>temp->data)
                temp = temp->right;
            else
            {
                return true;
            }
        }
    }
    return false;
}

void preorder(struct avl *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct avl *root)
{
        if(root == NULL)
                return;
        inorder(root->left);
	cout<<root->data<<" ";
        inorder(root->right);
}

void postorder(struct avl *root)
{
        if(root == NULL)
                return;
        postorder(root->left);
        postorder(root->right);
	cout<<root->data<<" ";
}

void avl_tree()
{
    struct avl *root = new avl();
    root = NULL;

    int ch=1;

	while(ch!=6)
	{
	    system("cls");
		cout<<endl<<endl<<"\t\t\t\t\t******* WELCOME TO AVL TREE ******** "<<endl<<endl;
		cout<<"\t\t\t\t\t*** WHAT DO YOU WANT TO DO? ****"<<endl<<endl;

		cout<<"\t\t\t\t\t1.Insertion\n\t\t\t\t\t2.Preorder traversal\n\t\t\t\t\t3.Inorder traversal\n\t\t\t\t\t4.Postorder traversal\n\t\t\t\t\t5.deletion\n\t\t\t\t\t6.Exit\n\n";
		cout<<"\t\t\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:cout<<endl<<endl<<"\t\t\t\t\tEnter the element : ";
                  int x;
                  cin>>x;
			    root = insertion_avl(root,x);
			    cout<<endl<<"\t\t\t\t\tELEMENT ADDED SUCCESSFULLY "<<endl;
			    break;
			case 2:cout<<endl<<"\t\t\t\t\tPreorder is : "<<endl<<"\t\t\t\t\t";preorder(root);cout<<endl;break;
			case 3:cout<<endl<<"\t\t\t\t\tInorder is : "<<endl<<"\t\t\t\t\t";inorder(root);cout<<endl;break;
			case 4:cout<<endl<<"\t\t\t\t\tPostorder is : "<<endl<<"\t\t\t\t\t";postorder(root);cout<<endl;break;
			case 5:cout<<endl<<endl<<"\t\t\t\t\tEnter the element to delete : ";
			{

                  int x;
                  cin>>x;
                 if(!avl_search(root,x))
                     cout<<endl<<endl<<"\t\t\t\t\t!!! OOPS EITHER THE GIVEN ELEMENT IS NOT PRESENT IN TREE OR TREE IS EMPTY "<<endl;
                 else
                 {
                    root = delete_avl(root,x);
                    cout<<endl<<"\t\t\t\t\tELEMENT DELETED SUCCESSFULLY "<<endl;
                    break;
                 }
			}
			break;
			case 6: cout<<endl<<endl<<"\t\t\t\t\t!!! THANK YOU FOR VISITING AVL TREE "<<endl;break;
			default : cout<<endl<<"\t\t\t\t\tWRONG CHOICE ENTERED"<<endl;
		}
		getchar();
		cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE ";
		getchar();
	}
}


int main()
{
    int ch = 1;
    system("cls");
    while(ch!=15)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t******** WELCOME TO ALL IN ONE DATA STRUCTURE ********"<<endl;
        cout<<"\t\t\t\t\t***** WHAT DO YOU WANT TO DO ? ********"<<endl<<endl;
        cout<<"\t\t\t\t\t1.ARRAY"<<endl;
        cout<<"\t\t\t\t\t2.SIMPLE QUEUE"<<endl;
        cout<<"\t\t\t\t\t3.CIRCULAR QUEUE"<<endl;
        cout<<"\t\t\t\t\t4.DEQUE"<<endl;
        cout<<"\t\t\t\t\t5.STACK"<<endl;
        cout<<"\t\t\t\t\t6.SINGLY LINKED LIST"<<endl;
        cout<<"\t\t\t\t\t7.CIRCULAR LINKED LIST"<<endl;
        cout<<"\t\t\t\t\t8.DOUBLY LIST"<<endl;
        cout<<"\t\t\t\t\t9.CIRCULAR DOUBLY LIST"<<endl;
        cout<<"\t\t\t\t\t10.BINARY SEARCH TREE"<<endl;
        cout<<"\t\t\t\t\t11.BINARY TREE"<<endl;
        cout<<"\t\t\t\t\t12.AVL TREE"<<endl;
        cout<<"\t\t\t\t\t13.QUEUE USING STACK"<<endl;
        cout<<"\t\t\t\t\t14.STACK USING QUEUE"<<endl;
        cout<<"\t\t\t\t\t15.EXIT"<<endl;
        cout<<endl<<"\t\t\t\tENTER YOUR CHOICE : ";
        cin>>ch;

        switch(ch)
        {
            case 1 : arr();break;
            case 2 : simple_queue();break;
            case 3 : cir_queue_1();break;
            case 5 : my_stack_1();break;
            case 6 : singly_list();break;
            case 7 : cir_list();break;
            case 8 : doubly_list();break;
            case 9 : cir_doubly_list();break;
            case 10 : bst();break;
            case 11 :binary_tree();break;
            case 15: cout<<endl<<endl<<"\t\t\t\t!!!!!! THANK YOU FOR USING ALL IN ONE DATA STRUCTURE !!!!!!!";
                getchar();
        cout<<endl<<endl<<"\t\t\t\tPRESS ANY KEY TO CONTINUE";
        getchar();
            break;
            case 12 : avl_tree();break;
            case 13 : queue_using_stack();break;
            case 14 : stack_using_queue();break;
            case 4 : my_deque();break;
            default : cout<<endl<<"\t\t\t\t!!!! WRONG CHOICE ENTERERD"<<endl;
        }
        //getchar();
        //cout<<endl<<endl<<"\t\t\t\tPRESS ANY KEY TO CONTINUE";
        //getchar();
        system("cls");
    }
	system("cls");
    return 0;
}
