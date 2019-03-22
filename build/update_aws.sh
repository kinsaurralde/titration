cmake .. -DCMAKE_BUILD_TYPE=Release
make aws-lambda-package-titration
aws lambda update-function-code --function-name titration --zip-file titration.zip
echo Done!
