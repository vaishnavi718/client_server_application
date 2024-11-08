#include <gtest/gtest.h>
#include "utility/message_info.h"
#include "employee.pb.h"
#include "utility/employee_info.h"


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



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
