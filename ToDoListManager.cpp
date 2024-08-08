#include <iostream>
#include <string>
#include "ToDoListManager.h"

using namespace std;

void ToDoListManager::loadTaskFromFile(const string& fileName)
{
	ifstream file(fileName);
	if (file.is_open())
	{
		tasks.clear();
		string line;
		while (getline(file, line))
		{
			size_t delimiterPos = line.find('|');
			string name = line.substr(0, delimiterPos);
			bool completed = (line.substr(delimiterPos + 1) == "1");
			tasks.push_back({ name, completed });

		}
		file.close();
	}
	else
	{
		cout << "Failed to open file!" << endl;
	}
}

void ToDoListManager::addTask(const string& taskName)
{
	tasks.push_back({ taskName, false });
}

void ToDoListManager::displayTasks()const
{
	if (tasks.empty())
	{
		cout << "No tasks found!" << endl;
	}
	else
	{
		for (size_t i = 0; i < tasks.size(); ++i)
		{
			cout << i + 1 << "." << tasks[i].name << "[" << (tasks[i].completed ? "Done" : "Not Done") << "]" << endl;
		}
	}
	cout << "Press to ENTER to continue..." << endl;
	cin.ignore();
	cin.get();
}

void ToDoListManager::removeTask(int taskNumber)
{
	if (taskNumber > 0 && taskNumber <= tasks.size())
	{
		tasks.erase(tasks.begin() + taskNumber - 1);
	}
	else
	{
		cout << "Invalid task number!" << endl;
	}
}

void ToDoListManager::markTaskAsCompleted(int taskNum)
{
	if (taskNum > 0 && taskNum <= tasks.size())
	{
		tasks[taskNum - 1].completed = true;
	}
	else 
	{
		cout << "Invalid task number!" << endl;
	}
}

void ToDoListManager::saveTaskToFile(const string& filename)const
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (const auto& task : tasks)
		{
			file << task.name << "|" << (task.completed ? "1" : "0") << endl;
		}
	}
	else
	{
		cout << "Failed to open file!" << endl;
	}
	
}
