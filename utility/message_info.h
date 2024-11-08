#ifndef MESSAGE_INFO_H
#define MESSAGE_INFO_H
#include<iostream>
#include<vector>

// Structure to represent the unique employee ID
struct EmployeeIDStruct {
    std::string id;  // Unique employee ID
};
// Enum to represent different employee roles
enum Role {
    UNKNOWN = 0,
    INTERN = 1,
    ENGINEER = 2,
    MANAGER = 3,
    DIRECTOR = 4,
    EXECUTIVE = 5
};
struct AddressStruct {
    std::string street;
    std::string city;
    std::string state;
    std::string zip_code;
    std::string country;
};
// Structure to represent the main employee information
struct EmployeeStruct {
   // EmployeeIDStruct employee_id;        // Employee's ID
    std::string name;                    // Employee's full name
    Role role;                  // Employee role as an enum
    float salary;                        // Employee's salary
    std::vector<std::string> skills;     // List of skills (vector)
    AddressStruct address;               // Nested structure for address
    uint32_t years_of_experience;        // Years of experience (primitive data type)
    bool is_full_time;                   // Boolean indicating if full-time
};
#endif // MESSAGE_INFO_H