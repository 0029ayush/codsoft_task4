#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void printTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Task newTask;
            cout << "Enter the task description: ";
            cin.ignore(); // Clear newline character from buffer
            getline(cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            cout << "Task added successfully!" << endl;
        } else if (choice == 2) {
            printTasks(tasks);
        } else if (choice == 3) {
            printTasks(tasks);
            int taskIndex;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskIndex;
            if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                tasks[taskIndex - 1].completed = true;
                cout << "Task marked as completed!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        } else if (choice == 4) {
            printTasks(tasks);
            int taskIndex;
            cout << "Enter the task number to remove: ";
            cin >> taskIndex;
            if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                tasks.erase(tasks.begin() + taskIndex - 1);
                cout << "Task removed successfully!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        } else if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
