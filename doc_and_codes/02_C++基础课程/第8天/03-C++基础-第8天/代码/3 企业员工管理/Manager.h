#pragma once
#include "Employee.h"
class Manager : virtual public Employee
{
public:
	Manager();
	~Manager();

	//�õ�Ա����нˮ�ķ���
	virtual void getPay();

	//Ա������������
	virtual void uplevel(int addLevel) ;

	virtual void init();


protected:
	double fixSalary; //�̶�нˮ
};

