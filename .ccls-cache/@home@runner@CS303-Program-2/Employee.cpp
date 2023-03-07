

#include "Employee.hpp"
#include <string>

Professional::Professional(){
  monthlySalary = 0;
  ID = 0;
}

Professional::Professional(std::string name, int ID, double monthlySalary, int vacation){
  this->name = name;
  this->ID = ID;
  this->monthlySalary = monthlySalary;
  this->vacation = vacation;
}

double Professional::weeklySalary(double hoursWorked){
  double weeklysal = monthlySalary / 4;
  return weeklysal;
}

double Professional::healthCareContribution(){
  return (monthlySalary/4) * 0.1;
}

int Professional::vacationDays(){
  return (vacation / 12)/4; //fixed number of vacation days divided by weeks to get vaction days earned per week
}

Nonprofessional::Nonprofessional(){
  payRate = 0.0;
  vacayHours = 0.0;
}

Nonprofessional::Nonprofessional(std::string name, int ID, double payRate, int vacayHours){
  this->name = name;
  this->ID = ID;
  this->payRate = payRate;
  this->vacayHours = vacayHours;
}

double Nonprofessional::weeklySalary(double hoursWorked){
  return payRate * hoursWorked;
}

double Nonprofessional::healthCareContribution(double hoursWorked){
  return (weeklySalary(hoursWorked) * 0.09); //healthcare contribution is weekly earnings multiplied by 9%
}

int Nonprofessional::vacationDays(double hoursWorked){
  this->vacayHours = (hoursWorked * 0.02); //set vacation hours based on hours worked per week
  return vacayHours / 8; //divide amount of hours earned by 8 to get total vaction days (in integer form)
}

