#include <bits/stdc++.h>
using namespace std;
#define N 5000000

struct card
{
    int suit;
    int number;
};
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

bool highest_straight(vector<card> arr)
{
    return (arr[0].number == 1  && arr[1].number == 10 
         && arr[2].number == 11 && arr[3].number == 12 && arr[4].number == 13);
}

bool straight(vector<card> arr)
{
    if (highest_straight(arr))
        return true;
    for(int i=1; i<5; i++)
    {
        if (arr[i].number != arr[i-1].number + 1)
            return false;
    }
    return true;
}

bool four(vector<card> arr)
{
    return (arr[1].number == arr[0].number  && arr[2].number == arr[0].number && arr[3].number == arr[0].number)
     || (arr[1].number == arr[4].number  && arr[2].number == arr[4].number && arr[3].number == arr[4].number);
}

bool three_of_a_kind(vector<card> arr)
{
    return (arr[1].number == arr[0].number  && arr[2].number == arr[0].number)
        || (arr[2].number == arr[1].number  && arr[3].number == arr[1].number)
        || (arr[3].number == arr[2].number  && arr[4].number == arr[2].number);
}

bool full_house(vector<card> arr)
{
    return (arr[1].number == arr[0].number && arr[2].number == arr[0].number && arr[3].number == arr[4].number)
     || (arr[1].number == arr[0].number  && arr[2].number == arr[4].number && arr[3].number == arr[4].number);
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
    if (highest_straight(arr) && flush(arr))
        return 1;
    else if (straight(arr) && flush(arr))
        return 2;
    else if (four(arr))
        return 3;
    else if (full_house(arr))
        return 4;
    else if (flush(arr))
        return 5;
    else if (straight(arr))
        return 6;
    else if (three_of_a_kind(arr))
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
    vector<card> sent(3);
    for(int i=0; i<3; i++)
    {
        int send = rand() % 52;
        int suit = send / 13;
        int number = send % 13 + 1;
        bool out = false;
        while(out)
        {
            for (int j=0; j<4; j++)
            {
                if (suit == init[j].suit && number == init[j].number)
                    break;
                if (j == 3)
                    out = true;
            }
        }
        sent[i].suit = suit;
        sent[i].number = number;
    }
    vector<card> yours(5), opponents(5);
    yours[0] = init[0];
    yours[1] = init[1];
    yours[2] = sent[0];
    yours[3] = sent[1];
    yours[4] = sent[2];
    opponents[0] = init[2];
    opponents[1] = init[3];
    opponents[2] = sent[0];
    opponents[3] = sent[1];
    opponents[4] = sent[2];
    sort(yours.begin(),yours.end(),[](card e1,card e2){return e1.number<e2.number;});
    sort(yours.begin(),yours.end(),[](card e1,card e2){return e1.suit<e2.suit;});
    sort(opponents.begin(),opponents.end(),[](card e1,card e2){return e1.number<e2.number;});
    sort(opponents.begin(),opponents.end(),[](card e1,card e2){return e1.suit<e2.suit;});
    int your_rank = which_hand_rankings(yours);
    int opponents_rank = which_hand_rankings(opponents);
    if (your_rank >= opponents_rank)
        return 1;
    else
        return 0;
}

void read_input()
{
    for(int i=0; i<4; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp[0] == 'S')
            init[i].suit = 0;
        else if (tmp[0] == 'H')
            init[i].suit = 1;
        else if (tmp[0] == 'D')
            init[i].suit = 2;
        else
            init[i].suit = 3;

        if (tmp[1] == 'J')
            init[i].number = 11;
        else if (tmp[1] == 'Q')
            init[i].number = 12;
        else if (tmp[1] == 'K')
            init[i].number = 13;
        else if (tmp[1] == 'A')
            init[i].number = 1;
        else if (tmp[1] == '1')
            init[i].number = 10;
        else 
            init[i].number = tmp[1] - '0';
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
