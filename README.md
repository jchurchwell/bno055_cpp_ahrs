# bno055_cpp_ahrs
A C++ API for the Bosch Sensortec BNO055 AHRS

How to build sample program (main.cpp)

1) Ensure that the port specified in main is the correct one for your BNO device.

2) Compile that shit.

g++ bno055.cpp Interface.cpp main.cpp -I /Wherever/The/Interface_UART/Library/Is/ -L /Wherever/The/Interface_UART/Library/Is/ -lInterface_UART -o BNOTest

3) Run

BNOTest

4) ???

5) Profit.
