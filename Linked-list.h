#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list
{
private:
	node *head, *tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	void add_node(int n)
	{
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	int average()
	{
		node *tmp = head;
		int sum = 0, count = 0;
		while (tmp)
		{
			sum += tmp->data;
			count++;
			tmp = tmp->next;
		}
		delete tmp;
		return sum / count;
	}
	int variance()
	{
		float avg = average();
		node *tmp = head;
		int sum = 0, count = 0;
		while (tmp)
		{
			int temp = tmp->data;
			temp -= avg;
			temp *= temp;
			sum += temp;
			count++;
			tmp = tmp->next;
		}
		delete tmp;
		return sum / count;
	}
	void traverse()
	{
		node *tmp = head;
		while (tmp)
		{
			cout << tmp->data << "   ";
			tmp = tmp->next;
		}
		delete tmp;
		cout << "\n";
	}
	int find(int x)
	{
		node *tmp = head;
		int count = 0;
		while (tmp)
		{
			count++;
			if (tmp->data == x)
				return count - 1;
			tmp = tmp->next;
		}
		delete tmp;
		return -1;
	}
	bool delete_node(int x)
	{
		node *tmp = head;
		if (head->data == x)
		{
			head = head->next;
			delete tmp;
			cout << "Item " << x << " is deleted.\n";
			return true;
		}
		node *tmp2 = head->next;
		while (tmp2)
		{
			if (tmp2->data == x)
			{
				tmp->next = tmp2->next;
				delete tmp2;
				cout << "Item " << x << " is deleted.\n";
				return true;
			}
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		cout << x << " NOT FOUND!\n";
		return false;
	}
	void delete_all_nodes()
	{
		while (head)
		{
			node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};