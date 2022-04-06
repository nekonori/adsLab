#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int salary, empId;
    double tax;

public:
    Employee() {}
    Employee(int salary, int empId)
    {
        this->salary = salary;
        this->empId = empId;
    }
    void calcTax()
    {
        tax = 0.05 * salary;
    }
    double getTax()
    {
        return tax;
    }
    int getId()
    {
        return empId;
    }
    int getSalary()
    {
        return salary;
    }
};

int main()
{
    int n = 3;
    vector<Employee> emps;
    for (int i = 0; i < n; i++)
    {
        int tempId, tempSalary;
        printf("Enter employee id, salary: ");
        cin >> tempId >> tempSalary;
        Employee newEmp = Employee(tempSalary, tempId);
        emps.push_back(newEmp);
    }
    for (int i = 0; i < n; i++)
    {
        emps[i].calcTax();
    }
    for (auto x : emps)
    {
        cout << "Employee id: " << x.getId() << "\n";
        cout << "salary: " << x.getSalary() << "\n";
        cout << "tax: " << x.getTax() << "\n\n";
    }
}