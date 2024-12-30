#include <iostream>
using namespace std;

int AddEven()
{
    int sum = 0;
    for (int i = 2; i <= 100; i += 2)
    {
        sum += i;
    }

    return sum;
}

void PrintStar()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintReverse(const char* string, int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        std::cout << string[i];
    }
}

bool ToLower(char upperCase)
{
    if ((int)upperCase < 65 || (int)upperCase > 90)
    {
        std::cout << "�Է��Ͻ� ���ڴ� �빮�ڰ� �ƴմϴ�. �빮�ڸ� �ٽ� �Է��ϼ���." << '\n';
        return false;
    }
    else
    {
        cout << "�Է��Ͻ� ������ �빮�ڴ� " << (char)(upperCase + 32) << "�Դϴ�." << '\n';
    }

    return true;
}

bool ToUpper(char lowerCase)
{
    if ((int)lowerCase < 97 || (int)lowerCase > 122)
    {
        std::cout << "�Է��Ͻ� ���ڴ� �ҹ��ڰ� �ƴմϴ�. �ҹ��ڸ� �ٽ� �Է��ϼ���." << '\n';
        return false;
    }
    else
    {
        cout << "�Է��Ͻ� ������ �ҹ��ڴ� " << (char)(lowerCase - 32) << "�Դϴ�." << '\n';
    }

    return true;
}

bool HasSameCharacter(const char* testString, int stringLength)
{
    int count[26] = { 0, };

    for (int i = 0; i < stringLength; i++)
    {
        count[testString[i] - 'a']++;
    }

    for (int i = 0; i < 27; i++)
    {
        if (count[i] > 1)
        {
            return true;
        }
    }
    return false;
}

bool HasSameCharacter(const char* testString, int stringLength)
{
    bool arr[26] = { 0, };

    for (int i = 0; i < stringLength; i++)
    {
        if (arr[i - 'a'])
        {
            return true;
        }
        arr[i - 'a'] = true;
    }

    return false;
}

bool HasSameCharacter(const char* testString, int stringLength)
{
    int bitSet = 0;

    for (int i = 0; i < stringLength; i++)
    {
        int value = testString[i] - 'a';
        if ((bitSet & (1 << value)) > 0)
        {
            return true;
        }
        bitSet |= (1 << value);
    }

    return false;
}