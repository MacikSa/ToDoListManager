#include <iostream>
#include <string>
#include "ToDoListManager.h"

using namespace std;

int main()
{
    ToDoListManager manager;

    do
    {
        int choice;

        cout << "1. Add a task" << endl;
        cout << "2. Viev task" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Mark the task as completed" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string taskName;
            cout << "Enter the name of the task: " << endl;
            cin.ignore();
            getline(cin, taskName);
            manager.addTask(taskName);
        }
        break;
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            cout << "Invalid choice. Try again" << endl;
        }
        }

    } while (true);
}
