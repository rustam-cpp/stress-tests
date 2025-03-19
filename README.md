# STRESS TESTS FOR LINUX, FOR C++

- Write your wrong solution in `nok.cpp`

- Write your correct solution in `ok.cpp`

- Write test generator in `testgen.cpp`

- Write your own checker in `checker.cpp` if it's many correct answers, or use default checker that compares answers from correct and wrong solution

Then compile stress.cpp:

`g++ stress.cpp -o stress`

Run stress and wait until the test is found:

`./stress`

Good luck with finding bugs! I wish you to open this folder less! :)