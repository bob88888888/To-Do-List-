//1) create model of a task
//2) user input for inserting the task
//3) define functions: display, mark as done, set, edit task/task content
//4) Add interface/menu for the system
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

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

class Display{
protected:
    Task task;
    ifstream reader;
    string line;
public:
    void displayTasks(string Dir){
        ifstream reader(Dir);
        if(reader.is_open()){
            while (getline(reader, line)){
                stringstream sstream(line);
                string id, name, dueDate, dueTime, done;
                getline(sstream, id, ',');
                getline(sstream, name, ',');
                getline(sstream, dueDate, ',');
                getline(sstream, dueTime, ',');
                getline(sstream, done, ',');

                cout << id << "," << name << "," << dueDate << "," << dueTime << "," << done << endl;
            }
            reader.close();
        }
    }
};

class markAsDone{
protected:
    Task task;
    ofstream writer;
    string line;
    vector <Task> reUpload;
    bool found = false;
public:

    markAsDone(){}

    void markDone(string taskName, string dir){
        ifstream reader(dir);
        if(reader.is_open()){
            while (getline(reader, line)){
                stringstream sstream(line);
                string id, name, dueDate, dueTime, done;
                getline(sstream, id, ',');
                getline(sstream, name, ',');
                getline(sstream, dueDate, ',');
                getline(sstream, dueTime, ',');
                getline(sstream, done, ',');

                if (name == taskName){
                    done = stoi(done);
                    done = true;
                    cout << id << "," << name << "," << dueDate << "," << dueTime << "," << done << endl;
                    found = true;
                    continue;
                }
                else{
                    task.setID(stoi(id));
                    task.setName(name);
                    task.setDueDate(stoi(dueDate));
                    task.setDueTime(stoi(dueTime));
                    task.setDone(stoi(done));

                    reUpload.push_back(task);
                }
            }
            reader.close();
        }
        ofstream writer(dir);
        if (writer.is_open()){
            for (Task line : reUpload){
                writer << line.getID() << "," << line.getName() << "," << line.getDueDate() << "," << line.getDueTime() << "," << line.getDone() << endl;
            }
        }
    }
};
class editTask{
protected:
    Task task;
    ofstream writer;
    string line;
    vector <Task> reUpload;
    bool found = false;
public:

    editTask(){}

    void edit(string taskName, string dir){
        ifstream reader(dir);
        if(reader.is_open()){
            while (getline(reader, line)){
                stringstream sstream(line);
                string id, name, dueDate, dueTime, done;
                getline(sstream, id, ',');
                getline(sstream, name, ',');
                getline(sstream, dueDate, ',');
                getline(sstream, dueTime, ',');
                getline(sstream, done, ',');

                if (name == taskName){
                    done = stoi(done);
                    done = true;
                    cout << id << "," << name << "," << dueDate << "," << dueTime << "," << done << endl;
                    found = true;
                    string field;
                    cout << "Which field do you want to edit?(name/dueDate/dueTime): " << endl;
                    cin >> field;

                    if (field == "name"){
                        string newName;
                        cout << "Enter the task name you want it to be changed to: " << endl;
                        cin >> newName;
                        name = newName;
                    }
                    else if(field == "dueDate"){
                        int newDueDate;
                        cout << "Enter the new due date of the task: " << endl;
                        cin >> newDueDate;
                        dueDate = to_string(newDueDate);
                    }
                    else if(field == "dueTime"){
                        int newDueTime;
                        cout << "Enter the new due time of the task: " << endl;
                        cin >> newDueTime;
                        dueTime = to_string(newDueTime);

                    task.setID(id);
                    task.setName(name);
                    task.setDueDate(dueDate);
                    task.setDueTime(dueTime);
                    task.setDone(done);

                    cout << id << "," << name << "," << stoi(dueDate << "," << dueTime << "," << done << endl;
                    reUpload.push_back(task);
                }
                else{
                    task.setID(stoi(id));
                    task.setName(name);
                    task.setDueDate(stoi(dueDate));
                    task.setDueTime(stoi(dueTime));
                    task.setDone(stoi(done));

                    reUpload.push_back(task);
                }
            }
            reader.close();
        }
        ofstream writer(dir);
        if (writer.is_open()){
            for (Task line : reUpload){
                writer << line.getID() << "," << line.getName() << "," << line.getDueDate() << "," << line.getDueTime() << "," << line.getDone() << endl;
            }
        }
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

            case 2:{
                Display display;
                display.displayTasks(directory);
                break;

            }
            case 3:{
                markAsDone m1;
                string nameOfTask;
                cout << "Name the task needed to be marked as done: " << endl;
                cin >> nameOfTask;
                m1.markDone(nameOfTask, directory);
                break;
            }
            case 4:{
                editTask e1;
                string nameOfTask;
                cout << "Name the task needed to be edited: " << endl;
                cin >> nameOfTask;
                e1.edit(nameOfTask, directory);
                break;
            }
        }
    }
};

int main()
{
    const string dir = "C:/Users/FiercePC/Documents/Project/C++/toDoList/task.csv";
    int operation;
    cout << "What operation do you want to perform?(1. add/2. display/3. Mark as done/4. edit task): " << endl;
    cin >> operation;
    taskManager t1(operation, dir);
    t1.mainLoop();
}

