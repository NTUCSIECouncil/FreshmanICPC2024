SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:%.cpp=%.exe)

.PHONY: all clean

all: $(EXECUTABLES)

clean:
	rm -f *.exe

%.exe: %.cpp
	$(CXX) -DEVAL -std=gnu++17 -O2 -pipe $< -o $@

compile_outputs_list:
	@echo $(COMPILE_OUTPUTS)
