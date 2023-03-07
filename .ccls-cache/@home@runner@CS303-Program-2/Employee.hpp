#pragma once
#include <string>

class Employee {
public:
    virtual double weeklySalary(double hoursWorked) = 0;
    virtual double healthCareContribution() = 0;
    virtual int vacationDays() = 0;

protected:
    std::string name;
    int ID;
};

class Professional : public Employee {
  private:
    double monthlySalary;
    int vacation;
  public:
    Professional();
    Professional(std::string name, int ID, double monthlySalary, int vacation);
    double weeklySalary(double hoursWorked);
    double healthCareContribution();
    int vacationDays();

};

class Nonprofessional : public Employee {
  private:
    double payRate;
    double vacayHours;
  public:
    Nonprofessional();
    Nonprofessional(std::string name, int ID, double payRate, int vacayHours);
    double weeklySalary(double hoursWorked);
    double healthCareContribution(double hoursWorked);
    int vacationDays(double hoursWorked);
};




