#include <iostream>
#include <string>
#include <limits>

using namespace std;

template<typename T>
class ArrayQueue
{
private:
    int size;
    int head;
    int tail;
    int count;
    T* arr;
public:
    ArrayQueue(int size_);
    bool enQueue(T value);
    T deQueue();
    void display();
    bool isEmpty()
    {
        return count == 0;
    }
};

template<typename T>
ArrayQueue<T>::ArrayQueue(int size_)
{
    size = size_;
    head = tail = -1;
    count = 0;
    arr = new T[size_];
}

template<typename T>
bool ArrayQueue<T>::enQueue(T value)
{
    try {
        if ((head == 0 && tail == size - 1) || head == tail + 1)
        {
            throw -1;
        }
        else if (head == -1)
        {
            head = 0;
            tail = 0;
            arr[tail] = value;
            count++;
        }
        else if (tail == size - 1 && head != 0)
        {
            tail = 0;
            arr[tail] = value;
            count++;
        }
        else
        {
            tail++;
            arr[tail] = value;
            count++;
        }
        return 1;
    }
    catch (...)
    {
        return 0;
    }

}

template<typename T>
T ArrayQueue<T>::deQueue()
{
    T val = arr[head];
    if (head == tail)
    {
        head = -1;
        tail = -1;
    }
    else if (head == size - 1)
        head = 0;
    else
        head++;
    count--;

    return val;
}

template<typename T>
void ArrayQueue<T>::display()
{
    if (head == -1)
    {
        cout << "[ERROR] Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    if (tail >= head)
    {
        for (int i = head; i <= tail; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i = head; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= tail; i++)
            cout << arr[i] << " ";
    }


}

template<typename T>
void choice(ArrayQueue<T>* arrQ)
{
    int a = NULL;
    while (a != 4)
    {
        system("cls");
        cout << "---- Lab4 ----\n\nChoose operation: \n| 1. EnQueue\n| 2. DeQueue\n| 3. Display\n| 4. Exit\n\nlab4@asd:~$ ";
        cin >> a;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[ERROR] Incorrect input! Try again...\n\nlab4@asd:~$ ";
            cin >> a;
        }

        switch (a)
        {
        case 1:
        {
            cout << "\nEnter value: ";
            T b;
            cin >> b;
            arrQ->enQueue(b) ? cout << "Value '" << b << "' successfully added!\n" : cout << "Failed!\n";
            system("pause");
        } break;
        case 2:
        {
            if (arrQ->isEmpty())
            {
                cout << "[ERROR] Queue is empty!\n";
            }
            else {
                T temp = arrQ->deQueue();
                cout << "Value '" << temp << "' successfully deleted!\n";
            }
            system("pause");
        }break;
        case 3:
            arrQ->display();
            system("pause");
            break;
        case 4:
            break;
        default:
            cout << "[ERROR] Incorrect operation! Try again...\n";
            system("pause");
            break;
        }


    }

}

int main()
{
    ArrayQueue<int> aq(5);
    choice(&aq);

    return 0;
}
