#pragma once

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>

using namespace std;


class Employee
{
public:
	Employee();


	 virtual ~Employee();

	//�õ�Ա����нˮ�ķ���
	virtual void getPay() = 0;

	//Ա������������
	virtual void uplevel(int addLevel ) = 0;

	//��ʾԱ������Ϣ�Ľӿ�
	void displayStatus();

	//�ṩһ����ʾ�ĳ�ʼ���ӿ�
	virtual void init() = 0;

protected:
	string name;//Ա��������
	int id; //Ա���ı��
	double salary;// Ա����нˮ
	int level; //Ա���ĵȼ�

	static int startnum; //��̬�ı�ż���
};

