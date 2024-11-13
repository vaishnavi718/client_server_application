proto_library(
    name = "employee_proto",
    srcs = ["employee.proto"],
)

cc_proto_library(
    name = "employee_cc_proto",
    deps = [":employee_proto"],
)
cc_library(
    name = "utility_headers",
    hdrs = [
        "utility/message_info.h",
        "utility/employee_info.h",
    ],
    visibility = ["//visibility:public"],
)
cc_library(
    name = "server_lib",
    srcs = ["server.cpp"],
    hdrs = ["server.h"],
    deps = [
        ":employee_cc_proto",
        ":utility_headers",
    ],
    visibility = ["//visibility:public"],
)
cc_library(
    name = "client_lib",
    srcs = ["client.cpp"],
    hdrs = ["client.h"],
    deps = [
        ":employee_cc_proto",
        ":server_lib",
    ],
    visibility = ["//visibility:public"],
)



cc_binary(
    name = "client_server_app",
    srcs = ["main.cpp"],
    deps = [
        ":client_lib",
        ":server_lib",
        ":employee_cc_proto",
    ],
)
cc_test(
    name = "client_server_test",
    srcs = ["test/client_server_test.cpp"],
    deps = [
        ":employee_cc_proto",
        "@com_google_googletest//:gtest_main",
        ":client_server_app",
        ":utility_headers",
        ":client_lib",
    ],
)