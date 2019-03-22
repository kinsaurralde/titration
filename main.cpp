// main.cpp
#include <aws/lambda-runtime/runtime.h>
#include <iostream>

using namespace aws::lambda_runtime;

invocation_response my_handler(invocation_request const& request)
{
    std::cout << "test" << std::endl;
    return invocation_response::success(request.payload, "application/json");

    // return invocation_response::success("Hello,,,,,, World!!!!!", "application/json");
}

int main()
{
    run_handler(my_handler);
    return 0;
}
