#include <iostream>
#include <string>

using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(string n, int a) : name(n), age(a) {}

    void personinfo() {
        cout << "Name of employee: " << name << endl;
        cout << "Age of employee: " << age << endl;
    }
};

class employee : public person {
protected:
    int employee_id;
public:
    employee(string n, int a, int id) : person(n, a), employee_id(id) {}

    void employeeinfo() {
        personinfo();
        cout << "ID of employee: " << employee_id << endl;
    }

    int getEmployeeID() { return employee_id; } // Getter for employee ID
};

class manager : public employee {
private:
    string dept;
public:
    manager(string n, int a, int id, string d) : employee(n, a, id), dept(d) {}

    void managerinfo() {
        employeeinfo();
        cout << "Department: " << dept << endl;
    }
};

int main() {
    const int MAX_MANAGERS = 3;
    manager managers[MAX_MANAGERS] = {
        manager("Prince", 40, 101, "HR"),
        manager("Tarang", 45, 102, "Finance"),
        manager("Pratham", 38, 103, "IT")
    };

    cout << "\n---- Displaying All Managers ----\n";
    for (int i = 0; i < MAX_MANAGERS; i++) {
        cout << "Manager ID: " << managers[i].getEmployeeID() << endl;
        managers[i].managerinfo();
        cout << "----------------------\n";
    }

    int search_id;
    cout << "\nEnter Manager ID to search: ";
    cin >> search_id;

    bool found = false;
    for (int i = 0; i < MAX_MANAGERS; i++) {
        if (managers[i].getEmployeeID() == search_id) {
            cout << "\nManager found:\n";
            managers[i].managerinfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nManager not found!\n";
    }

    return 0;
}