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

class addTask{
protected:
    Task task;
    ofstream addRow;

public:
    void add(string Dir){
        addRow.open(Dir, ios::app);
        if (addRow.is_open()){
            addRow << task.getID() << task.getName() << task.getDueDate() << task.getDueTime() << task.getDone() << endl;
        }
        addRow.close();
        return;
    }
};

int main()
{
    const string dir = "C:/Users/FiercePC/DocumentsProject/C++/toDoList/task.csv";
    Task newTask;
    addTask.addNewTask;

    ID = 1;
    newTask.setID(ID);
    string setName;
    cout << "Enter the task name: " << endl;
    cin >> newtask.setName(newName);

    int newDueDate;
    cout << "Enter the task's due date(DD/MM/YY): " << endl;
    cin >> newTask.setDueDate(newDueDate);

    int newDueTime;
    cout << "Enter the task's due time(HH/MM): " << endl;
    cin >> newTask.setDueTime(newDueTime);

    addNewTask.add(dir);
    return 0;
}
