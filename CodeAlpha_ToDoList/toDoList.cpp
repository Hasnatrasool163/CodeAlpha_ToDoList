/*
TASK 1
TO-DO LIST APPLICATION
Build a console-based to-do list application.
Users should be able to add tasks, mark them as
completed, and view their current tasks.
@author MuhammadHasnatRasool
        25/9/2024
*/

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;

class ToDoList{

    private:
    vector<string>tasks;
    vector<bool>completed;


    public:
    ToDoList(){}

    void addTask(string task){

        tasks.push_back(task);
        completed.push_back(false);
        return;
    } 

    void markCompletion(int id){
        if(id>0 && id <tasks.size() ){
            completed[--id]=true;
        }
        else{
            cout<< "Invalid ID" << "\n";
        }
    }

    void displayTask(){
        if(isEmpty()){
            cout << "Task List is Empty! \n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i+1 <<") " << tasks[i] << " -> " << (completed[i]? "Completed" : "Not Completed") << "\n";
        }
        
    }

    bool isEmpty(){
        return tasks.size()<1;
    }

    int getSize(){
        return tasks.size();
    }

    string getTask(int id){
        if(id>0 && id < tasks.size()){
            return tasks[--id];
        }
        else{
            return  "Invalid ID";
        }
    }

    void printMenu(){
        cout<< "---------To-Do-List-------- " << "\n";
        cout<< "Press  1) To See ALl Tasks \n";
        cout<< "Press  2) To Add a Task \n";
        cout<< "Press  3) To Mark a Task Completed \n";
        cout<< "Press -1) To Exit the program! \n";
        cout<< "--------------------------- \n";
    }

    int handleUserChoice(){
        int choice;
        cin>> choice;
        return choice;
    }

    void clear(){
        tasks ={};
    }

    void handleOperations(int choice){
        switch (choice)
        {
        case 1:
        displayTask();
        break;
        case 2:
        handleTaskAddition();
        break;
        case 3:
        handleTaskCompletion();
        break;
        default:
            break;
        }
    }

    void handleTaskAddition(){
        cout << "Enter Task Name: " << "\n";
        string name ;
        cin.ignore();
        getline(cin, name);
        addTask(name);
        return;
    }

     void handleTaskCompletion(){
        int id ;
        cout << "Enter Task Number: " << "\n";
        cin >> id;
        markCompletion(id);
        return;
    }

};

int main(){
    ToDoList list;

    // sample add tasks

    // list.addTask("Cpp Task");
    // list.addTask("Task upload");
    // list.addTask("Task share");

    // display tasks

    // cout << "To-Do-List " << "\n";
    // list.displayTask();

    // mark as complete 

    // list.markCompletion(1);

    // display again
    // list.displayTask();

    // list.clear();
    // cout<< "\n\n\n";

    list.printMenu();
    int choice;
    choice = list.handleUserChoice();
    while(choice!=-1){
        list.handleOperations(choice);
        list.printMenu();
        choice = list.handleUserChoice();
    }
    cout << "Exiting program...\n";
    return 0;

}
