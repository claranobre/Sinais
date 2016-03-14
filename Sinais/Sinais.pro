QT += core
QT -= gui

CONFIG += c++11

TARGET = Sinais
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../../Dev/BlackLib/v1_0/BlackLib.cpp \
    ../../Dev/BlackLib/v1_0/example.cpp \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/Timing.cpp \
    ../../Dev/BlackLib/v2_0/BlackADC.cpp \
    ../../Dev/BlackLib/v2_0/BlackCore.cpp \
    ../../Dev/BlackLib/v2_0/BlackGPIO.cpp \
    ../../Dev/BlackLib/v2_0/BlackI2C.cpp \
    ../../Dev/BlackLib/v2_0/BlackPWM.cpp \
    ../../Dev/BlackLib/v2_0/BlackSPI.cpp \
    ../../Dev/BlackLib/v2_0/BlackUART.cpp \
    ../../Dev/BlackLib/v2_0/exampleAndTiming.cpp \
    ../../Dev/BlackLib/v3_0/BlackADC/BlackADC.cpp \
    ../../Dev/BlackLib/v3_0/BlackDirectory/BlackDirectory.cpp \
    ../../Dev/BlackLib/v3_0/BlackGPIO/BlackGPIO.cpp \
    ../../Dev/BlackLib/v3_0/BlackI2C/BlackI2C.cpp \
    ../../Dev/BlackLib/v3_0/BlackMutex/BlackMutex.cpp \
    ../../Dev/BlackLib/v3_0/BlackPWM/BlackPWM.cpp \
    ../../Dev/BlackLib/v3_0/BlackSPI/BlackSPI.cpp \
    ../../Dev/BlackLib/v3_0/BlackThread/BlackThread.cpp \
    ../../Dev/BlackLib/v3_0/BlackTime/BlackTime.cpp \
    ../../Dev/BlackLib/v3_0/BlackUART/BlackUART.cpp \
    ../../Dev/BlackLib/v3_0/BlackCore.cpp \
    ../../Dev/BlackLib/v3_0/examples.cpp

HEADERS += \
    ../../Dev/BlackLib/v1_0/BlackDef.h \
    ../../Dev/BlackLib/v1_0/BlackErr.h \
    ../../Dev/BlackLib/v1_0/BlackLib.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_ADC.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_GPIO.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_I2C.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_PWM.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_SPI.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/exampleAndTiming_UART.h \
    ../../Dev/BlackLib/v2_0/exampleAndTiming/Timing.h \
    ../../Dev/BlackLib/v2_0/BlackADC.h \
    ../../Dev/BlackLib/v2_0/BlackCore.h \
    ../../Dev/BlackLib/v2_0/BlackDef.h \
    ../../Dev/BlackLib/v2_0/BlackErr.h \
    ../../Dev/BlackLib/v2_0/BlackGPIO.h \
    ../../Dev/BlackLib/v2_0/BlackI2C.h \
    ../../Dev/BlackLib/v2_0/BlackLib.h \
    ../../Dev/BlackLib/v2_0/BlackPWM.h \
    ../../Dev/BlackLib/v2_0/BlackSPI.h \
    ../../Dev/BlackLib/v2_0/BlackUART.h \
    ../../Dev/BlackLib/v3_0/BlackADC/BlackADC.h \
    ../../Dev/BlackLib/v3_0/BlackDirectory/BlackDirectory.h \
    ../../Dev/BlackLib/v3_0/BlackGPIO/BlackGPIO.h \
    ../../Dev/BlackLib/v3_0/BlackI2C/BlackI2C.h \
    ../../Dev/BlackLib/v3_0/BlackMutex/BlackMutex.h \
    ../../Dev/BlackLib/v3_0/BlackPWM/BlackPWM.h \
    ../../Dev/BlackLib/v3_0/BlackSPI/BlackSPI.h \
    ../../Dev/BlackLib/v3_0/BlackThread/BlackThread.h \
    ../../Dev/BlackLib/v3_0/BlackTime/BlackTime.h \
    ../../Dev/BlackLib/v3_0/BlackUART/BlackUART.h \
    ../../Dev/BlackLib/v3_0/examples/example_ADC.h \
    ../../Dev/BlackLib/v3_0/examples/example_directory.h \
    ../../Dev/BlackLib/v3_0/examples/example_GPIO.h \
    ../../Dev/BlackLib/v3_0/examples/example_I2C.h \
    ../../Dev/BlackLib/v3_0/examples/example_PWM.h \
    ../../Dev/BlackLib/v3_0/examples/example_SPI.h \
    ../../Dev/BlackLib/v3_0/examples/example_threadAndMutex.h \
    ../../Dev/BlackLib/v3_0/examples/example_time.h \
    ../../Dev/BlackLib/v3_0/examples/example_UART.h \
    ../../Dev/BlackLib/v3_0/BlackCore.h \
    ../../Dev/BlackLib/v3_0/BlackDef.h \
    ../../Dev/BlackLib/v3_0/BlackErr.h \
    ../../Dev/BlackLib/v3_0/BlackLib.h
