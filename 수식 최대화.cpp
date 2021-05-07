#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    // 시작

    vector<char> opcodes;
    vector<long long> operands;


    // 숫자랑 연산자랑 분리해서 숫자 배열, 연산자 배열에 저장한다
    string temp_opnd;

    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            opcodes.push_back(expression[i]);
            operands.push_back(stoi(temp_opnd));
            temp_opnd.clear();
        }
        else
            temp_opnd.push_back(expression[i]);
    }
    operands.push_back(stoi(temp_opnd));

    // 6가지 케이스 직접 그냥 다 적자
    char ops[6][3] =
    {
        {'+', '-', '*'},
        {'+', '*', '-'},
        {'-', '+', '*'},
        {'-', '*', '+'},
        {'*', '+', '-'},
        {'*', '-', '+'}
    };

    for (int times = 0; times < 6; ++times)
    {
        vector<long long> temp(operands);
        for (int op = 0; op < 3; ++op)
        {
            for (int i = 0; i < opcodes.size(); ++i)
            {
                if (opcodes[i] == ops[times][op])
                {
                    if (ops[times][op] == '+')
                    {
                        int front = i, back = i + 1;
                        while (temp[front] == LLONG_MAX)
                            --front;
                        while (temp[back] == LLONG_MAX)
                            ++back;
                        temp[i] = temp[front] + temp[back];
                        if (front != i)
                            temp[front] = LLONG_MAX;
                        if (back != i)
                            temp[back] = LLONG_MAX;
                    }
                    else if (ops[times][op] == '-')
                    {
                        int front = i, back = i + 1;
                        while (temp[front] == LLONG_MAX)
                            --front;
                        while (temp[back] == LLONG_MAX)
                            ++back;
                        temp[i] = temp[front] - temp[back];
                        if (front != i)
                            temp[front] = LLONG_MAX;
                        if (back != i)
                            temp[back] = LLONG_MAX;
                    }
                    else if (ops[times][op] == '*')
                    {
                        int front = i, back = i + 1;
                        while (temp[front] == LLONG_MAX)
                            --front;
                        while (temp[back] == LLONG_MAX)
                            ++back;
                        temp[i] = temp[front] * temp[back];
                        if (front != i)
                            temp[front] = LLONG_MAX;
                        if (back != i)
                            temp[back] = LLONG_MAX;
                    }
                }
            }
        }

        for (int i = 0; i < temp.size(); ++i)
        {
            //printf("temp[%d] = %d \n", i, temp[i]);
            if (temp[i] != LLONG_MAX)
            {
                temp[i] = (temp[i] < 0 ? temp[i] * (-1) : temp[i]);
                if (answer < temp[i])
                    answer = temp[i];

            }
        }
    }
    // 끝
    return answer;
}

/*
int main()
{
    string expression[2] = {
        "100-200*300-500+20",
        "50*6-3*2"
    };

    for (int i = 0; i < 2; ++i)
    {
        cout << i + 1 << "번째 거 결과 = " << solution(expression[i]) << endl;

    }

    return 0;
}
*/