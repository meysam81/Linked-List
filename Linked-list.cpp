#include "Linked-List.h"
int main()
{
	linked_list list;
	do
	{
		system("cls");
		cout << "============================== Linked-List ==============================\n";
		cout << "Choose from the list below:\n\n" <<
			"1. Initialize the list randomly\n" <<
			"2. Initialize the list from input\n" <<
			"3. Traverse and show the list elements\n" <<
			"4. Find an element\n" <<
			"5. Delete an element\n" <<
			"6. Variance of all elements\n" <<
			"7. Average of the elements\n" <<
			"\nYour choice: ";
		int input;
		cin >> input;
		int upper;
		int num;
		int temp = 20;
		switch (input)
		{
		case 1:
			list.delete_all_nodes();
			cout << "Enter number of list elements: ";
			num = 50;
			cin >> num;
			cout << "Enter upper boundry of list: ";
			upper = 50;
			cin >> upper;
			srand(time(0));
			for (unsigned short i = 0; i < num; i++)
				list.add_node(rand() % upper + 1);
			break;
		case 2:
			list.delete_all_nodes();
			cout << "Enter number of list elements: ";
			num = 50;
			cin >> num;
			cout << "Enter list of elements seperated by a space: ";
			for (int i = 0; i < num; i++)
			{
				int temp;
				cin >> temp;
				list.add_node(temp);
			}
			break;
		case 3:
			list.traverse();
			break;
		case 4:
			cout << "List of elements:\n";
			list.traverse();
			cout << "Enter the value of the element to be found: ";
			cin >> temp;
			cout << "Your element can be found at element " << list.find(temp) << "\n";
			break;
		case 5:
			cout << "List of elements:\n";
			list.traverse();
			cout << "Enter the value of the element to be deleted: ";
			int temp;
			cin >> temp;
			if (list.delete_node(temp))
				cout << "Your element has been succesfully deleted.\n";
			else
				cout << "Sorry, no can do!";
			cout << "List of elements after deletion:\n";
			list.traverse();
			break;
		case 6:
			cout << "Variance of all elements is " << list.variance() << "\n";
			break;
		case 7:
			cout << "Average of all elements is " << list.average() << "\n";
			break;
		default:
			break;
		}
		cout << "\n\nDone.\n\nPress any key to continue...\n";
		getch();
	} while (true);
	return 0;
}