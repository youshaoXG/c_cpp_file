#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//������ֻ���
class Phone
{
public:
	virtual void show() = 0;
};

class iPhone :public Phone
{
public:
	virtual void show() {
		cout << "�����iphone" << endl;
	}
};

class Mi :public Phone
{
	virtual void show() {
		cout << "�����С���ֻ�" << endl;
	}
};

//дһ�������װ����
class Decorator :public Phone
{
public:
	Decorator(Phone *phone) {
		this->phone = phone;
	}

	virtual void show() = 0;
protected:
	Phone * phone; //ӵ��һ�� �����ֻ��ĸ���ָ��
};

//������ֻ���Ĥװ����
class MoDecorator :public Decorator
{
public:
	MoDecorator(Phone *phone) : Decorator(phone) {}
	virtual void show() {
		this->phone->show();  //����ԭ�е�show

		this->mo(); //�������һ�� mo�ķ���
	}

	//Ĥװ����������������ӵķ���
	void mo() {
		cout << "�ֻ�������Ĥ" << endl;
	}
};

//Ƥ�׵�װ������
class TaoDecorator :public Decorator
{
public:
	TaoDecorator(Phone *phone) : Decorator(phone) {}
	virtual void show() {
		this->phone->show();
		tao();
	}

	void tao() {
		cout << "�ֻ�����Ƥ��" << endl;
	}
};



int main(void)
{
	Phone *phone = new iPhone;
	phone->show();
	cout << " -----  " << endl;
	Phone * moPhone = new MoDecorator(phone);
	moPhone->show();
	cout << " -----  " << endl;
	Phone * taoPhone = new TaoDecorator(phone);
	taoPhone->show(); 

	cout << " ------  " << endl;
	Phone *moTaoPhone = new TaoDecorator(moPhone);
	moTaoPhone->show(); //moPhone.show() + tao() ==  phone.show() + mo() + tao();

	
	return 0;
}