#pragma once

// 매크로로 자동화
#ifdef BUILD_DLL
#define MATH_DLL __declspec(dllexport)
#else
#define MATH_DLL __declspec(dllimport)
#endif

// DLL 라이브러리 용 클래스 제작.
// Dynamic Linking Library.
// Dynamic -> Runtime -> 실행 중에.
// SLL은 프로그램에 전부 다 공개한다.
// DLL은 메모리 공간에 잡히고 포인터를 두고 프로그램이 DLL의 주소를 찾는다. A, B 프로그램 모두 같은 주소의 dll을 쓴다.
// /*외부 공개용이다*/ __declspec(dllexport), mscompiler.
class MATH_DLL Math
{
public:
    static int Add(int a, int b);
    static int Substract(int a, int b);
    static int Multiply(int a, int b);
    static int Divide(int a, int b);
};

// lib 파일엔 dll 에 있는 함수등 파일의 정보등이 들어가있다. (지도 역할)