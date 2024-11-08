#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H
#include<iostream>
#include "message_info.h"
inline EmployeeStruct fill_the_data()
{
    EmployeeStruct employee_struct;
    employee_struct.name = "vaishnavi";
    employee_struct.role = Role::ENGINEER;
    employee_struct.is_full_time = true;
    employee_struct.salary = 1234.12;
    employee_struct.years_of_experience = 2;
    employee_struct.address.city = "Pune";
    employee_struct.address.country = "INDIA";
    employee_struct.address.state = "Maharashtra";
    employee_struct.address.street = "Hinjewadi Phase 3";
    employee_struct.address.zip_code = "12345";
    employee_struct.skills.resize(3);
    employee_struct.skills[0] = "C++";
    employee_struct.skills[1] = "git";
    employee_struct.skills[2] = "bazel";

    return employee_struct;
}
#endif // EMPLOYEE_INFO_H