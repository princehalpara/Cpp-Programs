/* Programmer :Prince Halpara
   Date : 05 May, 2025
   Aim : To read and display student performance data from a file, with sorting options
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Structure to store student data
struct Student
{
    string name;
    int marks;
    char grade;
};

// Method 1: Direct processing without storing in memory
void directProcessing(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    cout << "\n=== Student Report (Direct Processing) ===\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Marks"
         << setw(20) << "Grade" << endl;
    cout << string(60, '-') << endl;

    string name;
    int marks;
    char grade;

    while (file >> ws && getline(file, name, ' '))
    {
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> marks >> grade;
        cout << left << setw(20) << name
             << setw(20) << marks
             << setw(20) << grade << endl;
    }

    file.close();
}

// Method 2: Store data for advanced processing
void storeAndProcess(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    vector<Student> students;
    string name;
    int marks;
    char grade;

    while (file >> ws && getline(file, name, ' '))
    {
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> marks >> grade;
        students.push_back({name, marks, grade});
    }

    file.close();

    // Manual selection sort by marks descending
    for (size_t i = 0; i < students.size(); ++i)
    {
        for (size_t j = i + 1; j < students.size(); ++j)
        {
            if (students[j].marks > students[i].marks)
            {
                swap(students[i], students[j]);
            }
        }
    }

    cout << "\n=== Student Report (Stored & Sorted by Marks) ===\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Marks"
         << setw(20) << "Grade" << endl;
    cout << string(60, '-') << endl;

    for (const auto& s : students)
    {
        cout << left << setw(20) << s.name
             << setw(20) << s.marks
             << setw(20) << s.grade << endl;
    }
}

int main()
{
    string filename = "students.txt";

    directProcessing(filename);
    storeAndProcess(filename);

    cout<<endl;
    cout<<"Prince Halpara:: 24CE038"<<endl;

    return 0;
}
