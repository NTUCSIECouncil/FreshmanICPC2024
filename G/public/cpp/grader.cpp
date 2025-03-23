#include "group.h"
#include <iostream>
#include <string>
#include <vector>

namespace
{
    static const int maxQ = 60;
    int totalQ = 0;
    int N;
    std::vector<std::vector<int>> computation;

    enum wrong_reason
    {
        TOO_MANY_QUERIES,
        INVALID_ARGUMENT,
        WRONG_ANSWER
    };

    void exit_WA(wrong_reason reason)
    {
        std::string output;
        if (reason == TOO_MANY_QUERIES)
            output = "too many queries";
        else if (reason == INVALID_ARGUMENT)
            output = "invalid arguments";
        else if (reason == WRONG_ANSWER)
            output = "answer is not correct";

        std::cout << "Wrong Answer: " << output << std::endl;
        exit(0);
    }

    void exit_AC()
    {
        std::cout << "Accepted" << std::endl;
        exit(0);
    }

}


int compute(int a, int b)
{
    ::totalQ++;
    if (::totalQ > ::maxQ)
        exit_WA(TOO_MANY_QUERIES);
    if (!(0 <= a && a < N && 0 <= b && b < N))
        exit_WA(INVALID_ARGUMENT);

    return computation[a][b];
}

int main()
{
    bool answer;
    std::cin >> N;
    computation.resize(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> computation[i][j];
    bool result = is_abelian(N);

    if (result != answer)
        exit_WA(WRONG_ANSWER);

    exit_AC();

    return 0;
}
