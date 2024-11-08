#include <iostream>
#include <string>
#include "employee.pb.h"
#include "server.h"
void runClient();
std::string serializeEmployeeRequest(const std::string& employee_id);
void displayEmployeeInfo(const std::string& serialized_response);