#include <iostream>
#include <string>
#include "ToDoListManager.h"
#include <cstdlib>

using namespace std;

int main()
{
    ToDoListManager manager;
    manager.loadTaskFromFile("tasks.txt");
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
            system("cls");
        }
        break;
        case 2:
        {
            system("cls");
            manager.displayTasks();
            system("cls");

        }
        break;
        case 3:
        {
            int taskNumber;
            cout << "Enter the number of the task to be deleted:" << endl;
            cin >> taskNumber;
            
            manager.removeTask(taskNumber);
            system("cls");
        }
        break;
        case 4:
        {
            int taskNum;
            cout << "Enter the task number to mark as completed:" << endl;
            cin >> taskNum;
            manager.markTaskAsCompleted(taskNum);
            system("cls");
        }
        break;
        case 5:
        {
            manager.saveTaskToFile("tasks.txt");
            system("cls");
            cout << "The task list has been saved. Exit the program." << endl;
            return 0;
        }
        break;
        default:
        {
            cout << "Invalid choice. Try again" << endl;
        }
        }

    } while (true);
}
