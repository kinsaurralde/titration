# Titration Calculator

This project calculates strong acid/base titrations. It can be run as an aws lambda function or locally in the terminal.

A version can be run from the website: https://chemistry.kinsaurralde.com/

### Features:
- Strong Acid / Base Titration types
- Change number of cycles used in calculations
- Set molarity and volume of acid and base used
- Display calculation results to screen and file
- Write data to csv file
- Display runtime
- Switch between local and aws run type
- Command line arguments for extra options
    - -n [integer] : change number of calculation cycles
    - -t [type name] : change type (must be "SASB" or "SBSA")
    - -f [path to file] : read configuration from given file (check samples in configuration folder for correct format)
    - -s [integer] : change preset sample (0, 1, or 2)
    - -b [optional] : run faster by not printing to screen (type any character after -b if used as last argument) 
    - -ttc [number] : change concentration of titrant
    - -ttv [number] : change volume of titrant
    - -tdc [number] : change concentration of titrand
    - -tdv [number] : change volume of titrand
