CXX = g++
CPPFLAGS = -std=c++11
RM = rm -f

SRCS=imx6.cpp main.cpp

default: all

all: imx6-demo
imx6-demo: main.cpp
	$(CXX) $(CPPFLAGS) -o imx6-demo $(SRCS)

clean:
	$(RM) imx6-demo
