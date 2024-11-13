// server.cpp
#include "server.h"
std::string processRequest(const std::string &serialized_request)
{
    company::EmployeeID employee_id;
    if (!employee_id.ParseFromString(serialized_request))
    {
        std::cerr << "Failed to parse request." << std::endl;
        return "";
    }
    EmployeeStruct filled_data = fill_the_data();
    std::cout << "Server received request: " << employee_id.id() << std::endl;

    company::Employee employee;
    employee.set_message("Information for Employee id:-" + employee_id.id() + " is !");
    employee.set_name(filled_data.name);
    employee.set_role(static_cast<company::Role>(filled_data.role));
    employee.set_salary(filled_data.salary);
    employee.set_is_full_time(filled_data.is_full_time);
    employee.set_years_of_experience(filled_data.years_of_experience);
    employee.mutable_address()->set_city(filled_data.address.city);
    employee.mutable_address()->set_country(filled_data.address.country);
    employee.mutable_address()->set_state(filled_data.address.state);
    employee.mutable_address()->set_street(filled_data.address.street);
    employee.mutable_address()->set_zip_code(filled_data.address.zip_code);
    

    for (const auto &skill : filled_data.skills)
    {
        employee.add_skills(skill);
    }

    std::string serialized_response;

    employee.SerializeToString(&serialized_response);

    return serialized_response;
}


