// main.cpp
#include <aws/lambda-runtime/runtime.h>
#include <iostream>

#define RUN_TYPE "LOCAL"  // AWS or LOCAL

using namespace aws::lambda_runtime;

void run_titration(std::string data) {
    std::cout << "Data: " << data << std::endl;
}

invocation_response my_handler(invocation_request const& request) {
    run_titration("aws");
    return invocation_response::success(request.payload, "application/json");
}

void local_handler() { run_titration("testing"); }

int main() {
    if (RUN_TYPE == "AWS") {
        std::cout << "Running AWS Version" << std::endl;
        run_handler(my_handler);
    } else {
        std::cout << "Running Local Testing Version" << std::endl;
        local_handler();
    }
    return 0;
}
