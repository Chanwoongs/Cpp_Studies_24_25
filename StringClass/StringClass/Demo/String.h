#pragma once

#include <iostream>

// ���� �����غ��� ���ڿ� Ŭ����
class String
{
public:
	// �Ϲ� ������
	String(const char* string = nullptr);
	// ���� ������
	String(const String& other);
	// �Ҹ���
	~String();

	// Getter.
	const int Length() const;
	const char* Data() const;

	// ������ �����ε�
	friend std::ostream& operator<<(std::ostream& os, const String& string);
	String& operator=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);

private:
	int length; // ���ڿ� ����
	char* data; // ���ڿ� �����ϴ� ���� (�����, �����̳�)
};

