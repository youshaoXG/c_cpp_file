#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//�����ˮ����
class Fruit
{
public:
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	virtual void getName() {
		cout << "����ƻ��" << endl;
	}
};

class Banana :public Fruit {
public:
	virtual void getName() {
		cout << "�����㽶 " << endl;
	}
};

//���һ�����Ʒ
class Pear : public Fruit
{
public:
	virtual void getName() {
		cout << "����Ѽ�� " << endl;
	}
};

//����Ĺ�����
class AbstractFactory
{
public:
	virtual Fruit * createFruit() = 0;//�����ˮ��������
};

//ƻ���Ĺ���
class AppleFactory :public AbstractFactory
{
public:
	virtual Fruit * createFruit() {
		return new Apple;
	}
};

//�㽶���� 
class BananaFactory : public AbstractFactory {
public:
	virtual Fruit *createFruit() {
		return new Banana;
	}
};

//�����Ĺ���
class PearFactory :public AbstractFactory
{
public:
	virtual Fruit *createFruit() {
		//....
		return  new Pear;
	}
};

int main(void)
{
	//1 ������һ���㽶�Ĺ���
	AbstractFactory * bananaFactory = new BananaFactory;
	//2 ������һ��ˮ��
	Fruit * banana = bananaFactory->createFruit(); //ֻ�ܹ������㽶 //��̬
	//Fruit *banana = new Banana;
	banana->getName(); //��̬

	delete bananaFactory;
	delete banana;

	AbstractFactory *appleFactory = new AppleFactory;
	Fruit *apple = appleFactory->createFruit();
	apple->getName();

	AbstractFactory *pearFactory = new PearFactory;
	Fruit *pear = pearFactory->createFruit();
	//Fruit *pear = new Pear;
	pear->getName(); //��̬
	
	return 0;
}