#include <iostream>

#include "MyMath.h"

// Main.cpp 컴파일 -> Main.obj 파일 생성됨 -> 링커 (obj끼리 연결이 필요한지 보고, 추가 라이브러리 있으면 연결).
// -> obj와 lib를 한데 묶어서 exe 파일을 생성.

//////////////////////////// 1차.
// 라이브러리용 클래스 제작.
//class Math
//{
//public:
//    static int Add(int a, int b);
//    static int Substract(int a, int b);
//    static int Multiply(int a, int b);
//    static int Divide(int a, int b);
//};

////////////////////////////// 2차.
// 헤더 파일을 똑같이 생성.
// 헤더를 main에 include.
// 문제 : Math.h를 볼 때 이게 현재 프로그램에 속해있는 헤더인지, 라이브러리에서 가져오는 헤더인지 알 수 없다.
// 해결 : 관습적으로 이런 파일은 약속된 경로에 넣어 사용한다.

////////////////////////////// 3차.
// Lib 폴더에 라이브러리 파일
// Includes 폴더에 헤더 파일을 배치한다.


int main()
{
    std::cout << "Hello\n";

    // 컴파일러는 함수의 틀을 찾을 수 있으면 넘어간다.
    // obj 파일이 만들어지고 링커는 함수의 실제 구현된 곳을 찾는다.
    // 만약 obj 파일에 없다면 라이브러리에서 찾는다. 다 없으면 링커 오류.
    std::cout << "10 + 20 = " << Math::Add(10, 20) << '\n';
    std::cin.get();
}