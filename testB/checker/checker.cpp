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

void check(bool res) {
    if (!res)
        exit_WA();
}

const int MAXC = 1000000000;
std::set<int> vis;
int N, M;

int readAns(InStream &stream) {
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (stream.seekEof()) break;
        int A = stream.readInt(0, MAXC, "A_" + std::to_string(cnt));
        int B = stream.readInt(0, MAXC, "B_" + std::to_string(cnt));
        if (A + B == N && vis.find(A) == vis.end())
            vis.insert(A), ++cnt;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    N = inf.readInt();
    M = inf.readInt();
    int cnt = readAns(ouf);
    if (cnt > M || cnt == 0)
        exit_WA();
    else if (cnt == M)
        exit_AC();
    else
        exit_WA();
}
