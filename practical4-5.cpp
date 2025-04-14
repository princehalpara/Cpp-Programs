/* Programmer : Prince Halpara
   Date : 11 April, 2025
   
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
protected:
    float marks;
public:
    void setMarks(float m) { // corrected name and parameter spacing
        marks = m;
    }
    virtual string computeGrade() = 0; // pure virtual function
};

class underGraduate : public Student { // corrected casing
public:
    string computeGrade() override { // added parentheses, fixed override syntax
        if (marks >= 85) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 65) return "C";
        else return "F";
    }
};

class postGraduate : public Student { // fixed class name casing
public:
    string computeGrade() override { // corrected override syntax
        if (marks >= 90) return "A";
        else if (marks >= 80) return "B";
        else if (marks >= 70) return "C";
        else return "F";
    }
};

int main() {
    vector<Student*> students;
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        float m;

        cout << "Enter the student type (1 for UG, 2 for PG): ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> m;

        Student* s = nullptr;

        if (type == 1) {
            s = new underGraduate();
        } else if (type == 2) {
            s = new postGraduate();
        } else {
            cout << "Invalid student type\n";
            continue;
        }

        s->setMarks(m);
        students.push_back(s);
    }

    cout << "\nStudent Grades:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i + 1 << " Grade: " << students[i]->computeGrade() << endl;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        delete students[i];
    }

    return 0;
}