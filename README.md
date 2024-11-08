# Client-Server Application with Protocol Buffers

This project implements a client-server application using Protocol Buffers for serializing structured employee data. The application uses Bazel as its build system to manage dependencies and build configurations.

## Features
- **Protocol Buffers**: Defines employee data with nested structures, enums, and lists.
- **Bazel Build System**: Handles build configurations and dependency management.
- **Client-Server Simulation**: Simulates client requests and server responses containing employee details.

## Prerequisites

- **Bazel**: Install Bazel (version bazel 7.4.0).
- **Protocol Buffers**: Install Protocol Buffers (version libprotoc 3.6.1).

## Build Instructions

 - **Build the Application: Run the following command to build the application**: :
 bazel build //:client_server_app

 - **After building, run the application using**:
 ./bazel-bin/client_server_app
