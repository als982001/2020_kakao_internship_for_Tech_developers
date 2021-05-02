#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    // 답안 작성 시작

    int Lr = 3, Lc = 0;
    int Rr = 3, Rc = 2;

    for (int num = 0; num < numbers.size(); ++num)
    {
        if (numbers[num] % 3 == 2 || numbers[num] == 0)
        {
            int target = numbers[num];
            int target_r, target_c;

            if (target != 0)
            {

                target_r = (target - 1) / 3;
                target_c = (target - 1) % 3;
            }
            else
                target_r = 3, target_c = 1;

            int left_distance = abs(target_r - Lr) + (target_c - Lc);
            int right_distance = abs(target_r - Rr) + (Rc - target_c);

            if (left_distance == right_distance)
            {
                if (hand == "right")
                {
                    answer.push_back('R');
                    Rr = target_r;
                    Rc = target_c;

                }
                else
                {
                    answer.push_back('L');
                    Lr = target_r;
                    Lc = target_c;
                }
            }
            else if (left_distance < right_distance)
            {
                answer.push_back('L');
                Lr = target_r;
                Lc = target_c;
            }
            else
            {
                answer.push_back('R');
                Rr = target_r;
                Rc = target_c;
            }
        }
        else if (numbers[num] % 3 == 1)
        {
            // 1일 때
            answer.push_back('L');
            Lr = (numbers[num] - 1) / 3;  // Lr = 0
            Lc = (numbers[num] - 1) % 3;  // Lc = 0
        }
        else if (numbers[num] % 3 == 0)
        {
            // 3일 때
            answer.push_back('R');
            Rr = (numbers[num] - 1) / 3;  // Rr = 0
            Rc = (numbers[num] - 1) % 3;  // Rc = 2
        }
    }

    // 답안 작성 끝
    return answer;
}

/*
    검사용

int main()
{
    vector<int> numbers;

    numbers.push_back(7);
    numbers.push_back(0);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);

    string hand = "left";

    string result = solution(numbers, hand);

    cout << result << endl;

    return 0;
}

*/