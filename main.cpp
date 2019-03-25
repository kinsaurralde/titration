#include <iostream>
#include <map>

#include "include/rapidjson/document.h"
#include "src/controller.h"
#include "src/parse.h"
#include "src/sample.h"

#define RUN_TYPE 0  // Set to 1 for aws lambda version

void run_titration(std::map<std::string, std::string> data) {
    Controller control = Controller(std::move(data));
    control.setupReaction();
    control.run();
}

#if RUN_TYPE    // Dont include aws lambda files and handler if testing locally
#include <aws/lambda-runtime/runtime.h>
using namespace aws::lambda_runtime;

invocation_response my_handler(invocation_request const& request) {
    Parser json = Parser(request.payload.c_str());
    run_titration(json.getData());
    return invocation_response::success(request.payload, "application/json");
}
#else
#define my_handler 0
void run_handler(int a) {}
#endif

void local_handler(int num) {
    const char* input = sample[num];
    Parser json = Parser(input);
    run_titration(json.getData());
}

void local_handler() {
    local_handler(0);
}

int main() {
    if (RUN_TYPE) {
        std::cout << "Running AWS Version" << std::endl;
        run_handler(my_handler);
    } else {
        std::cout << "Running Local Testing Version" << std::endl;
        local_handler();
    }
    return 0;
}
