#include <gtest/gtest.h>
#include "utility/message_info.h"
#include "employee.pb.h"
#include "utility/employee_info.h"
#include "../client.h"


TEST(ClientServerAppTest, FillTheDataInitialization) 
{
     EmployeeStruct data = fill_the_data();
    
    EXPECT_EQ(data.name, "vaishnavi");
    EXPECT_EQ(data.role, Role::ENGINEER);
    EXPECT_EQ(data.is_full_time, true);
    EXPECT_EQ(data.salary, 1234.12f);
    EXPECT_EQ(data.years_of_experience, 2);
    EXPECT_EQ(data.address.city, "Pune");
    EXPECT_EQ(data.skills.size(), 3);
    EXPECT_EQ(data.skills[0], "C++");
    EXPECT_EQ(data.skills[1], "git");
    EXPECT_EQ(data.skills[2], "bazel");

}
TEST(ClientServerAppTest, CheckClientSerializedRequest) 
{
   std::string serialized_request = serializeEmployeeRequest("EMP103");
   company::EmployeeID emp_id;
   emp_id.ParseFromString(serialized_request);
   EXPECT_EQ("EMP103",emp_id.id());
}
TEST(ClientServerAppTest, CheckProcessServer) 
{
   std::string serialized_request = serializeEmployeeRequest("EMP103");
   std::string server_response = processRequest(serialized_request);
    company::Employee emp;
    emp.ParseFromString(server_response);
    EXPECT_EQ(emp.name(), "vaishnavi");
    EXPECT_EQ(emp.role(), Role::ENGINEER);
    EXPECT_EQ(emp.is_full_time(), true);
    EXPECT_EQ(emp.salary(), 1234.12f);
    EXPECT_EQ(emp.years_of_experience(), 2);
    EXPECT_EQ(emp.address().city(), "Pune");
    EXPECT_EQ(emp.skills().size(), 3);
    EXPECT_EQ(emp.skills(0), "C++");
    EXPECT_EQ(emp.skills(1), "git");
    EXPECT_EQ(emp.skills(2), "bazel");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
