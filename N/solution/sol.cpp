#include <bits/stdc++.h>
using namespace std;
#define N 500000

struct card
{
    int suit;
    int number;
};

int combination[10][3] = {{0,1,2}, {0,1,3}, {0,1,4}, {0,2,3}, {0,2,4}, {0,3,4}, {1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}};
vector<card> init(4);

bool flush(vector<card> arr)
{
    for(int i=1; i<5; i++)
    {
        if (arr[i].suit != arr[0].suit)
            return false;
    }
    return true;
}

bool highest_straight(vector<int> numbers)
{
    return (numbers[0] == 1  && numbers[1] == 10  && numbers[2] == 11 && 
            numbers[3] == 12 && numbers[4] == 13);
}

bool straight(vector<int> numbers)
{
    if (highest_straight(numbers))
        return true;
    for(int i=1; i<5; i++)
    {
        if (numbers[i] != numbers[i-1] + 1)
            return false;
    }
    return true;
}

bool four(vector<int> numbers)
{
    return (numbers[1] == numbers[0]  && numbers[2] == numbers[0] && numbers[3] == numbers[0])
     || (numbers[1] == numbers[4] && numbers[2] == numbers[4] && numbers[3] == numbers[4]);
}

bool three_of_a_kind(vector<int> numbers)
{
    return (numbers[1] == numbers[0] && numbers[2] == numbers[0])
        || (numbers[2] == numbers[1] && numbers[3] == numbers[1])
        || (numbers[3] == numbers[2] && numbers[4] == numbers[2]);
}

bool full_house(vector<int> numbers)
{
    return (numbers[1] == numbers[0] && numbers[2] == numbers[0] && numbers[3] == numbers[4])
     || (numbers[1] == numbers[0]  && numbers[2] == numbers[4] && numbers[3] == numbers[4]);
}

int num_pairs(vector<card> arr)
{
    int nums[13] = {0};
    int cnt = 0;
    for (int i=0; i<5; i++)
        nums[arr[i].number-1] ++;
    for (int i=0; i<13; i++)
    {
        if(nums[i] >= 2)
            cnt++;
    }
    return cnt;
}

int which_hand_rankings(vector<card> arr)
{
    vector<int> numbers;
    for (const auto& c: arr)
        numbers.push_back(c.number);
    sort(numbers.begin(),numbers.end());
    if (highest_straight(numbers) && flush(arr))
        return 1;
    else if (straight(numbers) && flush(arr))
        return 2;
    else if (four(numbers))
        return 3;
    else if (full_house(numbers))
        return 4;
    else if (flush(arr))
        return 5;
    else if (straight(numbers))
        return 6;
    else if (three_of_a_kind(numbers))
        return 7;
    else if (num_pairs(arr) == 2)
        return 8;
    else if (num_pairs(arr) == 1)
        return 9;
    else
        return 10;
}

int game()
{
    vector<card> sent = init;
    vector<card> community(5);
    for(int i=0; i<5; i++)
    {
        while(true)
        {
            int send = rand() % 52;
            int suit = send / 13;
            int number = send % 13 + 1;
            bool repeated = false;
            for (const auto& c: sent)
            {
                if (suit == c.suit && number == c.number)
                {
                    repeated = true;
                    break;
                }
            }
            if (!repeated)
            {
                community[i].suit = suit;
                community[i].number = number;
                sent.push_back(community[i]);
                break;
            }
        }
    }
    int min_rank_you = 100, min_rank_opponent = 100;
    for (int i=0; i<10; i++)
    {
        vector<card> yours = {init[0], init[1], community[combination[i][0]], community[combination[i][1]], community[combination[i][2]]};
        vector<card> opponents = {init[2], init[3], community[combination[i][0]], community[combination[i][1]], community[combination[i][2]]};
        min_rank_you = min(min_rank_you, which_hand_rankings(yours));
        min_rank_opponent = min(min_rank_opponent, which_hand_rankings(opponents));
    }
    if (min_rank_you < min_rank_opponent)
        return 1;
    else
        return 0;
}

void read_input()
{
    map<char, int> suits = {{'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}};
    map<char, int> numbers = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
        {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'1', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};
    for(int i=0; i<4; i++)
    {
        string tmp;
        cin >> tmp;
        init[i].suit = suits[tmp[0]];
        init[i].number = numbers[tmp[1]];
    }
    return;
}

int main() 
{
    int cnt = 0;
    srand(time(NULL));
    read_input();
    for(int i=0; i<N; i++)
        cnt += game();
    cout << (double)cnt / N << '\n';
}
