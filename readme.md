# C++ Implementation of GoogleMock
[![Build Status](https://travis-ci.org/vijay4313/Week4_TDD_4B.svg?branch=master)](https://travis-ci.org/vijay4313/Week4_TDD_4B)
[![Coverage Status](https://coveralls.io/repos/github/vijay4313/Week4_TDD_4B/badge.svg?branch=master)](https://coveralls.io/github/vijay4313/Week4_TDD_4B?branch=master)

## Overview
A simple implementation of googlemock framework to incorporate mock classes in google tests.
* cmake
* googletest
* googlemock
* Travis CI
* Coveralls

## Review of the changes made
Following changes were made to original project:
* A new virtual class Tuner is implemented. Tuner has a job of returning random values for PID constants.
* To get random value of Kp, Kd and Ki, PID class calls these methods of Tuner class through methods:
adjustTunedKp(), adjustTunedKd() and adjustTunedKi(). 
* Since we are interested in testing PID class and it uses Tuner class for implementation of its methods, 
Googlemock is used to mock the object of the Tuner class.
* Four additional tests are included that use GoogleMock:
  1. callTunerMethodsTest - tests whether PID methods are calling methods of mocked Tuner object. 
  2. adjustTunedKpTest - Test whether Kp is adjusted properly. If Kp value returned by tuner is less than 0 or more than
     100 then pid should set kp equal to 50. Else pid should set kp value to value returned by tuner as it is. 
  3. adjustTunedKdTest - Test whether Kd is adjusted properly. If Kd value returned by tuner is less than 0 or more than
     100 then pid should set kd equal to 50. Else pid should set kd value to value returned by tuner as it is. 
  4. adjustTunedKiTest - Test whether Kp is adjusted properly. If Kp value returned by tuner is less than 0 or more than
     100 then pid should set ki equal to 50. Else pid should set ki value to value returned by tuner as it is.  

## Standard install via command-line
To install this branch run following command:
```
$ git clone -b GMock_Extra_Credit_Siddhesh https://github.com/vijay4313/Week4_TDD_4B
```

## Run the test
```
$ cd <path to repository>
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./test/cpp-test
```

## Run the program
Go to the build directory and run the following command:		
```
$ ./app/pid-controller
```

## Run cpplint
Go to main workspace and run following command:
```
$ cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## Run cppcheck
```
$ cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```

