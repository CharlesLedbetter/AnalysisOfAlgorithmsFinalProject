#Project
#Author: Ann Kostecki, Charles Ledbetter, Matthew Northey
#Date: 3/9/18
#Description: makefile for CS325 Project

CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC = TSP.cpp
SRC += solveTSP.cpp

ZF = TSP.zip

HZ = solveTSP.hpp

XTR = makefile
XTR += tsp_example_1.txt.tour
XTR += tsp_example_2.txt.tour
XTR += tsp_example_3.txt.tour
XTR += test-input-1.txt.tour
XTR += test-input-2.txt.tour
XTR += test-input-3.txt.tour
XTR += test-input-4.txt.tour
XTR += test-input-5.txt.tour
XTR += test-input-6.txt.tour
XTR += test-input-7.txt.tour
XTR += group40FinalProject.pdf
XTR += readme.txt

#compile all program
sortMains: ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o TSP

#clean up extra files
clean:
	rm TSP

#zip all files
zip:
	zip -D ${ZF} ${HZ} ${SRC} ${XTR}
