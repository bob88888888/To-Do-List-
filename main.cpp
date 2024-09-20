//1) create model of a task
//2) user input for inserting the task
//3) define functions: display, mark as done, set, delete, edit task/task content
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Task{
private:
    int id;
    string name;
    int dueDate;
    int dueTime;
    bool done;

public:
    Task(){
        done = false;
    }

    void setID(int ID){
        id = ID;
    }

    void setName(string Name){
        name = Name;
    }

    void setDueDate(int DueDate){
        dueDate = DueDate;
    }

    void setDueTime(int DueTime){
        dueTime = DueTime;
    }

    void setDone(bool Done){
        done = Done;
    }

    int getID(){
        return id;
    }

    string getName(){
        return name;
    }

    int getDueDate(){
        return dueDate;
    }

    int getDueTime(){
        return dueTime;
    }

    bool getDone(){
        return done;
    }
};

class AddTask{
public:
    void add(Task task, string Dir){
        ofstream addRow (Dir, ios::app);
        if (addRow.is_open()){
            addRow << task.getID() << "," << task.getName() << "," << task.getDueDate() << "," << task.getDueTime() << "," << task.getDone() << endl;
        }
        addRow.close();
    }
};

class taskManager{
protected:
    int operation;
    string directory;

public:
    taskManager(int o, string dir){
        operation = o;
        directory = dir;
    }

    void mainLoop(){
        switch (operation){
            case 1:{
                Task newTask;
                AddTask addNewTask;

                int ID = 1;
                newTask.setID(ID);

                string newName;
                cout << "Enter the task name: " << endl;
                cin >> newName;
                newTask.setName(newName);

                int newDueDate;
                cout << "Enter the task's due date(DD/MM/YY): " << endl;
                cin >> newDueDate;
                newTask.setDueDate(newDueDate);


                int newDueTime;
                cout << "Enter the task's due time(HH/MM): " << endl;
                cin >> newDueTime;
                newTask.setDueTime(newDueTime);

                addNewTask.add(newTask, directory);
                break;
            }
        }
    }
};


int main()
{
    const string dir = "C:/Users/FiercePC/Documents/Project/C++/toDoList/task.csv";
    int operation;
    cout << "What operation do you want to perform?(1. add/2. display): " << endl;
    cin >> operation;
    taskManager t1(operation, dir);
    t1.mainLoop();
}
