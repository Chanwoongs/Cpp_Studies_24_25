#pragma once

// dllimport
class __declspec(dllimport) Math
{
public:
    static int Add(int a, int b);
    static int Substract(int a, int b);
    static int Multiply(int a, int b);
    static int Divide(int a, int b);
};
