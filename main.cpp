#include <iostream>
#include <string>
using namespace std;

// Base Employee Class
class employee {
public:
    string name;
    int id;

    // Default constructor
    employee() {
        name = "Unknown";
        id = 0;
    }

    // Virtual function for salary
    virtual double calculate_Salary() {
        return 0.0;
    }

    // Virtual destructor
    virtual ~employee() {}
};

// Hourly Employee Class
class hourly_employee : public employee {
public:
    double rate;
    double hours;

    hourly_employee(string n, int i, double r, double h) {
        name = n;
        id = i;
        rate = r;
        hours = h;
    }

    double calculate_Salary() override {
        return rate * hours;
    }
};

// Salaried Employee Class
class salaried_employee : public employee {
public:
    double monthly_salary;

    salaried_employee(string n, int i, double s) {
        name = n;
        id = i;
        monthly_salary = s;
    }

    double calculate_Salary() override {
        return monthly_salary;
    }
};

// Main Function
int main() {
    employee* staff[10]; 
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
            staff[count] = new hourly_employee(n, i, r, h);
            count = count + 1;
        } 
        else if (choice == 2) {
            string n; int i; double s;
            cout << "Enter Name, ID, Monthly Salary: ";
            cin >> n >> i >> s;
            staff[count] = new salaried_employee(n, i, s);
            count = count + 1;
        }
    }

    cout << "\nID\tName\tSalary" << endl;
    for (int i = 0; i < count; i++) {
        cout << staff[i]->id << "\t" << staff[i]->name << "\t" << staff[i]->calculate_Salary() << endl;
    }

    for (int i = 0; i < count; i++) {
        delete staff[i];
    }

    return 0;
}

