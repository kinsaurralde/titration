#include <iostream>
#include <map>

#include "include/rapidjson/document.h"
#include "src/controller.h"
#include "src/parse.h"

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

void local_handler(int argc, char* argv[]) {
    std::cout << "Number of Command line arguments: " << argc << std::endl << std::endl;
    Parser json = Parser(argc, argv);
    run_titration(json.getData());
}


int main(int argc, char* argv[]) {
    if (RUN_TYPE) {
        std::cout << "Running AWS Version" << std::endl;
        run_handler(my_handler);
    } else {
        std::cout << "Running Local Testing Version" << std::endl;
        local_handler(argc, argv);
    }
    std::cout << std::endl;
    return 0;
}
