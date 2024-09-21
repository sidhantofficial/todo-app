#include <iostream>
#include <vector>
#include <algorithm> // for std::find

using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;

    // Constructor
Task(string desc) {
    description = desc;
    completed = false;
}
};

// Function to add a new task
void addTask(vector<Task> &tasks, const string &description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

// Function to remove a task by description
void removeTask(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&](const Task &task) {
        return task.description == description;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Task not found." << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&](const Task &task) {
        return task.description == description;
    });

    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Task not found." << endl;
    }
}

// Function to display all tasks
void displayTasks(const vector<Task> &tasks) {
    cout << "Tasks:" << endl;
    for (const auto &task : tasks) {
        cout << "- ";
        if (task.completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << task.description << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string description;

    cout << "Welcome to the To-Do List Application!" << endl;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Display all tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // clear the input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                cout << "Enter task description to remove: ";
                cin.ignore(); // clear the input buffer
                getline(cin, description);
                removeTask(tasks, description);
                break;
            case 3:
                cout << "Enter task description to mark as completed: ";
                cin.ignore(); // clear the input buffer
                getline(cin, description);
                markCompleted(tasks, description);
                break;
            case 4:
                displayTasks(tasks);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
