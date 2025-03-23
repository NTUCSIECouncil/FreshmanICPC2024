#include "group.h"
#include <iostream>
#include <string>
#include <vector>
// BEGIN SECRET
#include <algorithm>
#include <cassert>
#include <numeric>
#include <random>
#include <sstream>
// END SECRET

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

// BEGIN SECRET
namespace
{
    static const int secret[8] = {0x1a, 0x0f, 0x1c, 0x1e, 0x10, 0x0d, 0x05, 0x1f};
    static const int secret2[8] = {1, 3, 4, 2, 7, 0, 6, 5};
    static const std::string token = "fff2bc4eea31886d937c535d7021ae050c7c49d593d84f3e25f9f186c512a905";
    static const unsigned base = 23;
    std::string encode(std::string s)
    {
        int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};
        while ((int)s.size() % 8 != 0)
            s.push_back(' ');

        std::string t(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i += 8)
        {
            for (int j = 0; j < 8; j++)
                perm[j] = secret2[perm[j]];
            for (int j = 0; j < 8; j++)
            {
                t[i + j] = s[i + perm[j]] ^ secret[j];
                assert(32 <= t[i + j] && t[i + j] < 127);
            }
        }
        return t;
    }

    std::string decode(const std::string &s)
    {
        int perm[] = {0, 1, 2, 3, 4, 5, 6, 7};

        std::string t(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i += 8)
        {
            for (int j = 0; j < 8; j++)
                perm[j] = secret2[perm[j]];
            for (int j = 0; j < 8; j++)
                t[i + perm[j]] = s[i + j] ^ secret[j];
        }
        return t;
    }

    unsigned compute_seed(const std::string &s)
    {
        unsigned seed = 0;
        for (auto &c : s)
            seed = seed * base + c;
        return seed;
    }

    void __exit_security_violation(bool condition)
    {
        if (condition)
        {
            std::cerr << "Security Violation" << std::endl;
            exit(0);
        }
    }

    void __exit_wrong_answer(wrong_reason reason)
    {
        std::string output;
        if (reason == TOO_MANY_QUERIES)
            output = "too many queries";
        else if (reason == INVALID_ARGUMENT)
            output = "invalid arguments";
        else if (reason == WRONG_ANSWER)
            output = "answer is not correct";

        std::cerr << "Wrong Answer: " << output << std::endl;
        exit(0);
    }

    void __exit_accpeted()
    {
        std::cout << token << std::endl;
        std::cerr << "Accepted" << std::endl;
        exit(0);
    }

    int fast_mod_pow(int b, int p, int m)
    {
        long long a = 1;
        long long pw_b = b;
        while (p)
        {
            if (p & 1)
                a = a * pw_b % m;
            pw_b = pw_b * pw_b % m;
            p >>= 1;
        }
        return (int)a;
    }

    std::vector<int> perm;
    std::vector<int> inv_perm;
    std::vector<int> groups;
    std::vector<int> semi_direct;

}
// END SECRET

int fuse_ball(int a, int b)
{
    // BEGIN SECRET
    // ================================== Actual Grader Start ==================================
    ::totalQ++;
    if (::totalQ > ::maxQ)
        __exit_wrong_answer(TOO_MANY_QUERIES);
    if (!(0 <= a && a < N && 0 <= b && b < N))
        __exit_wrong_answer(INVALID_ARGUMENT);

    a = perm[a];
    b = perm[b];
    std::vector<int> A, B;
    for (auto G : groups)
    {
        A.emplace_back(a % G);
        a /= G;
        B.emplace_back(b % G);
        b /= G;
    }

    // will be twisted by semi-direct product
    std::vector<int> C(groups.size());
    for (int i = 0; i + 1 < (int)groups.size(); i++)
        C[i] = (A[i] + (long long)B[i] * fast_mod_pow(semi_direct[i], A.back(), groups[i])) % groups[i];
    C.back() = (A.back() + B.back()) % groups.back();

    int c = 0;
    for (int i = (int)groups.size() - 1; i >= 0; i--)
    {
        c *= groups[i];
        c += C[i];
    }

    return inv_perm[c];
    // ================================== Actual Grader End   ==================================
    // END SECRET
    ::totalQ++;
    if (::totalQ > ::maxQ)
        exit_WA(TOO_MANY_QUERIES);
    if (!(0 <= a && a < N && 0 <= b && b < N))
        exit_WA(INVALID_ARGUMENT);

    return computation[a][b];
}

int main()
{
    // BEGIN SECRET
    // ================================== Actual Grader Start ==================================

    std::string input;
    std::getline(std::cin, input);
    __exit_security_violation(input.size() % 8 != 0 || input.size() == 0);
    input = ::decode(input);

    __exit_security_violation(input.find("#") == std::string::npos);
    std::string groups_str = input.substr(0, input.find("#"));
    std::string product_str = input.substr(input.find("#") + 1);

    {
        std::stringstream ss;
        ss << groups_str;
        int current;
        while (ss >> current)
            groups.emplace_back(current);
    }

    {
        std::stringstream ss;
        ss << product_str;
        int current;
        while (ss >> current)
            semi_direct.emplace_back(current);
    }
    semi_direct.resize((int)groups.size(), 1);

    N = 1;
    for (auto g : groups)
        N *= g;
    __exit_security_violation(N > 1'000'000);

    unsigned seed = compute_seed(input);
    std::mt19937 rd(seed);
    perm.resize(N);
    inv_perm.resize(N);
    std::iota(perm.begin(), perm.end(), 0);
    std::shuffle(perm.begin(), perm.end(), rd);
    for (int i = 0; i < N; i++)
        inv_perm[perm[i]] = i;

    // if (N <= 500)
    // {
    //     int count = 0;
    //     for (int i = 0; i < N; i++)
    //     {
    //         bool abelian = true;
    //         for (int j = 0; j < N; j++)
    //         {
    //             abelian &= (compute(i, j) == compute(j, i));
    //             totalQ -= 2;
    //         }
    //         count += abelian;
    //     }
    //     std::cerr << "Center size: " << count << '\n';
    // }

    bool __result = is_abelian(N);
    bool __answer = *std::max_element(semi_direct.begin(), semi_direct.end()) == 1;

    if (__result != __answer)
        __exit_wrong_answer(WRONG_ANSWER);

    __exit_accpeted();

    return 0;
    // ================================== Actual Grader End   ==================================
    // ================================== Sample Grader Start ==================================
    // END SECRET
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
    // BEGIN SECRET
    // ================================== Sample Grader End   ==================================
    // END SECRET
}
