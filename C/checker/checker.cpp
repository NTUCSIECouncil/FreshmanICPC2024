#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("courses_scheduling", argc, argv);
	compareRemainingLines();
}
