cmake_minimum_required(VERSION 3.7)
project(Digital_Signal_Processing_II)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES dsp2-1/main.cpp dsp2-1/main.h dsp2-1/file.cpp dsp2-1/file.h dsp2-1/calc.cpp dsp2-1/calc.h)
add_executable(Digital_Signal_Processing_II ${SOURCE_FILES})