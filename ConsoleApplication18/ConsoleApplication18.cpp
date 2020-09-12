#include<iostream>
#include<string>
#include<string.h>

class node {
public:
	int index;
	int i;
	double f;
	char c;
	std::string s;
	node* next;
	static int length;
	node(int i)			{ __init__(i);					}
	node(double f)		{ __init__(0, f);				}
	node(char c)		{ __init__(0, 0, c);			}
	node(std::string s) { __init__(0, 0, '\0', s);		}

	void __init__(int i = 0, double f = 0.0, char c = '\0', std::string s = "")
	{
		index = length;
		this->i = i;
		this->f = f;
		this->c = c;
		this->s = s;
		next = nullptr;
		length++;
	}

	int size()
	{
		return length;
	}
	void disp()
	{
		std::cout << "(";
		if (i != 0)			std::cout << i;
		else if (f != 0)	std::cout << f;
		else if (c != '\0')	std::cout << c;
		else				std::cout << s;
		std::cout << ")-->" ;
	}
	std::string toString()
	{
		std::string s1="";
		if (i != 0)			s1 += std::to_string(i);
		else if (f != 0)	s1 += std::to_string(f);
		else if (c != '\0')	s1 += std::to_string(c);
		else				s1 += s;
		return s1;
	}
	void reduceIndex()
	{
		index--;
	}
	~node() { length--; }
};

int node::length = 0;

class List {
public:
	node* head;
	List()
	{
		head = nullptr;
	}
	void append(int i)
	{
		node* n = new node(i);
		joinToNode(n);
	}
	void append(double f)
	{
		node* n = new node(f);
		joinToNode(n);
	}
	void append(char c)
	{
		node* n = new node(c);
		joinToNode(n);
	}
	void append(std::string s)
	{
		node* n = new node(s);
		joinToNode(n);
	}

	void joinToNode(node* n)
	{
		if (head == nullptr)
		{
			head = n;
		}
		else
		{
			node* ptr;
			for (ptr = head; ptr->next != nullptr; ptr = ptr->next);
			ptr->next = n;
		}
	}

	void del(int index)
	{
		node* temp = getNode(index);
		if (!(temp == nullptr))
		{
			node* ptr = head;
			for (; ptr->next != temp; ptr = ptr->next);
			if (temp == head)
			{
				head = head->next;
			}
			else
			{
				ptr->next = temp->next;
			}
			for (ptr=ptr->next; ptr != nullptr; ptr=ptr->next)
				ptr->reduceIndex();
			node::length--;
		}
	}
	node* getNode(int index)
	{
		node* ptr = head;
		node* temp = nullptr;
		for (; ptr != nullptr; ptr = ptr->next)
		{
			if (ptr->index == index)	temp = ptr;
		}
		return temp;
	}

	void disp()
	{
		if (head == nullptr)
		{
			std::cout << "list empty";
		}
		else 
		{
			std::cout << "\t";
			for (node* ptr = head; ptr != nullptr; ptr = ptr->next)
				ptr->disp();
			std::cout << "\n";
		}
	}
};

void main()
{
	List l;
	l.append(2);
	l.append("hello");
	l.append(3.0);
	l.append('c');
	l.disp();
	l.del(1);
	l.disp();
}

