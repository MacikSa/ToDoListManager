#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class ToDoListManager
{
public:
	void loadTaskFromFile(const string& fileName);
	void addTask(const string& taskName);
	void displayTasks()const;
	void removeTask(int taskNumber);
	void markTaskAsCompleted(int taskNum);
	void saveTaskToFile(const string& filename)const;

private:
	struct Task
	{
		string name;
		bool completed;
	};
	vector <Task> tasks;
};

