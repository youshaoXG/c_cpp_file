#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;


class Animal
{
public:
	Animal();
	virtual ~Animal();

	//���麯��
	virtual void voice() = 0;
};

//�˺����Ǹ��� �����������з�װ�ġ� ���ֺ��� �ͽмܹ�������
void AnimalVoice(Animal *ap);

