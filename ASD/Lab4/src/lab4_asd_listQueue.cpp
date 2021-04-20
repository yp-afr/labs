#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;    
};

class ListQueue
{
private:
    int size;
    Node* head;
    Node* tail;
    
public:
    ListQueue();
    bool isEmpty()
    {
        return size == 0;
    }
    void enQueue(int data_);
    int deQueue();
    void display();
};

ListQueue::ListQueue()
{
    size = 0;
    head = tail = NULL;
}

void ListQueue::enQueue(int data_)
{
    Node* tempNode = new Node;
    tempNode->next = NULL;
    tempNode->data = data_;
    if(head != NULL)
    {
        tempNode->prev = tail;
        tail->next = tempNode;
        tail = tempNode;
        size++;
    }else
    {
        tempNode->prev = NULL;
        head = tail = tempNode;
        size++;
    }
}

int ListQueue::deQueue()
{
    int value = 0;
    value = head->data;
    if(size > 0)
    {
        if(size == 1)
        {
            delete head;
            head = NULL;
            size--;
        }else
        {
            Node* tempNode = head;
            tempNode = head->next;
            head->next->prev = NULL;
            delete head;
            head = tempNode;
            size--;
        }
    }
    return value; 
}

void ListQueue::display()
{
    Node* tempNode = head;
    while(tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << "\n";
}


void choice(ListQueue* listQ)
{
    int a = 0;
    while(a != 4)
    {
        system("clear");
        cout << "---- Lab4 ----\n\nChoose operation: \n| 1. EnQueue\n| 2. DeQueue\n| 3. Display\n| 4. Exit\n\nlab4@asd:~$ ";
        cin >> a;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[ERROR] Incorrect input! Try again...\n\nlab4@asd:~$ ";
            cin >> a;
        }

        switch(a)
        {
        case 1:
            cout << "\nEnter value: ";
            int val;
            cin >> val;
            listQ->enQueue(val);
            cin.get();
            break;
        case 2:
            if(listQ->isEmpty())
            {
                cout << "[ERROR] Queue is empty!\n";
            }else
            {
                int temp = listQ->deQueue();
            }
            cin.get();
            break;
        case 3:
            listQ->display();
            cin.get();
            break;
        case 4:
            break;
        default:
            cout << "[ERROR] Incorrect operation! Try again...\n";
            cin.get();
            break;
        }
        cout << "Press any key...\n";
        cin.get();
    
    }
}

int main()
{
    ListQueue lq;
    
    choice(&lq);

	return 0;
}
