//1) create model of a task
//2) user input for inserting the task
//3) define functions: display, mark as done, set, delete, edit task/task content
#include <iostream>
#include <string>

using namespace std;

class Task{
protected:
    int id;
    string name;
    int dueDate;
    int dueTime;
    bool done;

public:

    //for appending task into the to-do list
    Task(int ID, string n, int date, int time){
        id = ID;
        name = n;
        dueDate = date;
        dueTime = time;
        done = false;
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

int main()
{
    string setName;
    cout << "Enter the task name: " << endl;
    cin >> setName;

    int setDueDate;
    cout << "Enter the task's due date(DD//MM//YY): " << endl;
    cin >> setDueDate;

    int setDueTime;
    cout << "Enter the task's due time(HH/MM): " << endl;
    cin >> setDueTime;

    Task t1(1, setName, setDueDate, setDueTime);
    cout << t1.getID() << "," << t1.getName() << "," << t1.getDueDate() << "," << t1.getDueTime() << "," << t1.getDone() << endl;
}
