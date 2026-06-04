#include <iostream>
#include <string>
using namespace std;

// Base Employee Class
class Employee {
public:
    string name;
    int id;

    // Default constructor
    Employee() {
        name = "Unknown";
        id = 0;
    }

    // Virtual function for salary
    virtual double calculateSalary() {
        return 0.0;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Hourly Employee Class
class HourlyEmployee : public Employee {
public:
    double rate;
    double hours;

    HourlyEmployee(string n, int i, double r, double h) {
        name = n;
        id = i;
        rate = r;
        hours = h;
    }

    double calculateSalary() override {
        return rate * hours;
    }
};

// Salaried Employee Class
class SalariedEmployee : public Employee {
public:
    double monthlySalary;

    SalariedEmployee(string n, int i, double s) {
        name = n;
        id = i;
        monthlySalary = s;
    }

    double calculateSalary() override {
        return monthlySalary;
    }
};

// Main Function
int main() {
    Employee* staff[10]; 
    int count = 0;
    int choice = 0;

    while (choice != 3) {
        cout << "\n--- Payroll Management System ---" << endl;
        cout << "1. Add Hourly Employee" << endl;
        cout << "2. Add Salaried Employee" << endl;
        cout << "3. Display Report and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (count >= 10) {
            cout << "Error: System full! Cannot add more employees." << endl;
            continue; // Go back to the top of the menu
        }
        if (choice == 1) {
            string n; int i; double r, h;
            cout << "Enter Name, ID, Hourly Rate, Hours Worked: ";
            cin >> n >> i >> r >> h;
            staff[count] = new HourlyEmployee(n, i, r, h);
            count = count + 1;
        } 
        else if (choice == 2) {
            string n; int i; double s;
            cout << "Enter Name, ID, Monthly Salary: ";
            cin >> n >> i >> s;
            staff[count] = new SalariedEmployee(n, i, s);
            count = count + 1;
        }
    }

    cout << "\nID\tName\tSalary" << endl;
    for (int i = 0; i < count; i++) {
        cout << staff[i]->id << "\t" << staff[i]->name << "\t" << staff[i]->calculateSalary() << endl;
    }

    for (int i = 0; i < count; i++) {
        delete staff[i];
    }

    return 0;
}
