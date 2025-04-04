#include <set>
#include <string>
#include <vector>

#include "testlib.h"

void exit_WA(std::string message = "") {
    std::string output = "Wrong Answer";
    if (!message.empty()) output += ": " + message;
    quitf(_wa, "%s", output.c_str());
}

void exit_AC(std::string message = "") {
    std::string output = "Accepted";
    if (!message.empty()) output += ": " + message;
    quitf(_ok, "%s", output.c_str());
}

const std::string FLAGS[] = {
    "CSIE{DeCyPh3r_Th3_C0nUnDrUm}",
    "CSIE{P3rp3Tu4l_T3mp0r4l_Fr33z3}",
    "CSIE{C0sm1c_3ch0}",
    "CSIE{V4p0r1z3d_Inf0rm4t1c_M4tr1x}",
    "CSIE{C4us4l_T3mp0r4l_D1st0rt1on_V01d}"};

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    std::set<std::string> userFlags;

    while (!ouf.seekEof()) {
        std::string userFlag = ouf.readLine();

        if (userFlags.find(userFlag) != userFlags.end()) {
            exit_WA("Duplicate flag found: " + userFlag);
        }

        userFlags.insert(userFlag);
    }

    if (userFlags.size() > 5) {
        exit_WA("Too many flags submitted.");
    }

    if (userFlags.size() < 5) {
        exit_WA("Not all flags submitted.");
    }

    for (int i = 0; i < 5; ++i) {
        if (userFlags.find(FLAGS[i]) == userFlags.end()) {
            exit_WA("Missing flag: " + FLAGS[i]);
        }
    }

    exit_AC("All flags are correct.");
}
