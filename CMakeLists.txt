cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(titration LANGUAGES CXX)

find_package(aws-lambda-runtime REQUIRED)
add_executable(${PROJECT_NAME} "main.cpp" src/sample.h src/parse.cpp src/parse.h src/controller.cpp src/controller.h)
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime)
aws_lambda_package_target(${PROJECT_NAME})
