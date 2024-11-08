#include "client.h"
#include <iostream>
#include <string>
#include "employee.pb.h"

// Function to serialize an EmployeeID request
std::string serializeEmployeeRequest(const std::string& employee_id) {
    company::EmployeeID emp_id;
    emp_id.set_id(employee_id);
    
    std::string serialized_request;
    if (!emp_id.SerializeToString(&serialized_request)) {
        std::cerr << "Failed to serialize EmployeeID." << std::endl;
    }
    
    return serialized_request;
}

// Function to display Employee details
void displayEmployeeInfo(const std::string& serialized_response) {
    company::Employee emp;
    if (!emp.ParseFromString(serialized_response)) {
        std::cerr << "Failed to parse response." << std::endl;
        return;
    }

    std::cout << "Client received response: " << emp.message() << std::endl;
    std::cout << "Employee name: " << emp.name() << std::endl;
    std::cout << "Employee Role: " << emp.role() << std::endl;
    std::cout << "Employee salary: " << emp.salary() << std::endl;
    std::cout << "Is employee full time: " << emp.is_full_time() << std::endl;
    
    const auto& address = emp.address();
    std::cout << "Employee address:" << std::endl;
    std::cout << "  Country: " << address.country() << std::endl;
    std::cout << "  State: " << address.state() << std::endl;
    std::cout << "  City: " << address.city() << std::endl;
    std::cout << "  Street: " << address.street() << std::endl;
    std::cout << "  Zip code: " << address.zip_code() << std::endl;
    
    std::cout << "Skills: ";
    for (const auto& skill : emp.skills()) {
        std::cout << skill << ", ";
    }
    std::cout << std::endl;
}

// Main client function that uses the helper functions
void runClient() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Serialize the request
    std::string serialized_request = serializeEmployeeRequest("EMP103");

    // Send the request and receive the response
    std::string serialized_response = processRequest(serialized_request);

    // Deserialize and display the response
    displayEmployeeInfo(serialized_response);

    google::protobuf::ShutdownProtobufLibrary();
}
