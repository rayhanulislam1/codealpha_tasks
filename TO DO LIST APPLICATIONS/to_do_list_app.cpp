#include <bits/stdc++.h>
#include <chrono>
using namespace std;

struct Task{
    bool completed;
    string taskDescription;
};
class to_do_list{
    vector <Task> tasks;
    public:
    void addTask(string& taskDesc){
        Task newTask;
        newTask.completed = true;
        newTask.taskDescription = taskDesc;
        tasks.push_back(newTask);
        cout << "Task added: " << taskDesc << "\n";
        cout << "\n";
        cout << "\n";

    }
    void markCompleted(int taskNumber){
        if(taskNumber < 1 || taskNumber > tasks.size()){
            cout << "Invalid Enter Task Number!\n";
            for(int i = 0; i < tasks.size(); i++){
                cout << i + 1 << ". " << tasks[i].taskDescription << (tasks[i].completed ? "[Pending]" : "[Completed]") << endl;
            }
            return;
        }
        tasks[taskNumber - 1].completed = false;
        cout << "Task " << taskNumber << " number marked as Completed.\n";
        cout << "\n";
        cout << "\n";
    }
    void viewTask(){
        if(tasks.empty()){
            cout << "No Tasks Available.\n";
            return;
        }
        for(int i = 0; i < tasks.size(); i++){
            cout << i + 1 << ". " << tasks[i].taskDescription << (tasks[i].completed ? "[Pending]" : "[Completed]") << endl;
        }
        cout << "\n";
        cout << "\n";
    }
};
void displayMenu(){
    cout << "---------------------------------\n";
    cout << "|          Welcome              |\n";
    cout << "|   To-Do List Application      |\n";
    cout << "|                               |\n";
    cout << "---------------------------------\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Completed\n";
    cout << "3. View Task\n";
    cout << "4. Exit\n";
    cout << "Enter your Choice: ";
}
int main(){
    to_do_list todolist;
    string taskDescription;
    int taskNumber;
    string choice;
    do{
        displayMenu();
        getline(cin, choice);
        // cin.ignore();
        if(choice == "1"){
            cout << "Enter Task Description: ";
            getline(cin, taskDescription);
            todolist.addTask(taskDescription);
        }
        else if(choice == "2"){
            cout << "Enter Number Mark Task as Completed: ";
            cin >> taskNumber;
            todolist.markCompleted(taskNumber);
        }
        else if(choice == "3"){
            cout << "Current Task: \n";
            todolist.viewTask();
        }
        else if(choice == "4"){
            cout << "Exiting the applications.\n";
        }
        else{
            cout << "Invalid choice! Please try again. \n";
        }
        cout << "\n";
        cout << "\n";
    }while(choice != "4");

    return 0;
}