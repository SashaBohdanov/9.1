#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

// Структура, що представляє інформацію про студента
struct Student {
    string lastName;                // Прізвище
    int course;                     // Курс
    string specialty;               // Спеціальність
    int physicsGrade;               // Оцінка з фізики
    int mathGrade;                  // Оцінка з математики
    int computerScienceGrade;       // Оцінка з інформатики
};

// Функція для введення даних студента
void inputData(Student*& students, int& size) {
    cout << "Enter the number of students: ";
    cin >> size;

    students = new Student[size];

    for (int i = 0; i < size; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialty: ";
        cin >> students[i].specialty;
        cout << "Physics Grade: ";
        cin >> students[i].physicsGrade;
        cout << "Math Grade: ";
        cin >> students[i].mathGrade;
        cout << "Computer Science Grade: ";
        cin >> students[i].computerScienceGrade;
    }
}

// Функція для виведення таблиці студентів
void displayTable(const Student* students, int size) {
    cout << setw(15) << "Last Name" << setw(8) << "Course" << setw(20) << "Specialty"
        << setw(15) << "Physics" << setw(15) << "Math" << setw(20) << "Computer Science" << endl;

    for (int i = 0; i < size; ++i) {
        cout << setw(15) << students[i].lastName << setw(8) << students[i].course
            << setw(20) << students[i].specialty << setw(15) << students[i].physicsGrade
            << setw(15) << students[i].mathGrade << setw(20) << students[i].computerScienceGrade << endl;
    }
}

// Функція для виведення студентів без оцінок нижче 4
void studentsWithoutThrees(const Student* students, int size) {
    cout << "Students without grades below 4:\n";
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade >= 4 && students[i].mathGrade >= 4 && students[i].computerScienceGrade >= 4) {
            cout << students[i].lastName << endl;
        }
    }
}

// Функція для підрахунку кількості студентів із оцінкою з фізики '5'
int studentsWithPhysics5(const Student* students, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i].physicsGrade == 5) {
            count++;
        }
    }
    return count;
}

int main() {
    Student* students = nullptr;
    int size;

    inputData(students, size);
    displayTable(students, size);
    studentsWithoutThrees(students, size);

    int physics5Count = studentsWithPhysics5(students, size);
    cout << "Number of students with a physics grade of '5': " << physics5Count << endl;

    delete[] students; // Free the memory allocated for the dynamic array

    return 0;
}


