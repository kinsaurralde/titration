cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(titration LANGUAGES CXX)

#find_package(aws-lambda-runtime REQUIRED)
add_executable(${PROJECT_NAME} "main.cpp" src/sample.h src/parse.cpp src/parse.h src/controller.cpp src/controller.h src/reaction.cpp src/reaction.h src/StrongAcidBase.cpp src/StrongAcidBase.h src/component.cpp src/component.h src/acid.cpp src/acid.h src/base.cpp src/base.h src/view.cpp src/view.h src/StandardView.cpp src/StandardView.h)
#target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime)
#aws_lambda_package_target(${PROJECT_NAME})
