#include "linked-list.h"
int main()
{
    linked_list list;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, value;
        cin >> type >> value;
        switch (type) {
        case 1:
            if (list.find(value) != -1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            break;
        case 2:
            list.add_node(value);
            break;
        case 3:
            list.delete_node(value);
            break;
        default:
            break;
        }
    }
}
