#pragma once


#include "Employee.h"
//������Ա
class Technician : public Employee
{
public:
	Technician();
	~Technician();

	//�õ�Ա����нˮ�ķ���
	virtual void getPay();

	//Ա������������
	virtual void uplevel(int addLevel);

	virtual void init();

private:
	double perHourMoney; //ÿСʱ׬��Ǯ
	int workHour; // һ���¹����˶���Сʱ
};

