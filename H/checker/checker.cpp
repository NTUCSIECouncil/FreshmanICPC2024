#include "testlib.h"
#include <set>
#include <string>

void exit_WA(std::string message = "") {
    std::string output = "Wrong Answer";
    if (!message.empty()) output += ": " + message;
    quitf(_wa, output.c_str());
}

void exit_AC(std::string message = "") {
    std::string output = "Accepted";
    if (!message.empty()) output += ": " + message;
    quitf(_ok, output.c_str());
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int N = ouf.readInt();
    int M = ans.readInt();
    if (N == M && ouf.seekEof() && ans.seekEof())
        exit_AC();
    else
        exit_WA();
}
