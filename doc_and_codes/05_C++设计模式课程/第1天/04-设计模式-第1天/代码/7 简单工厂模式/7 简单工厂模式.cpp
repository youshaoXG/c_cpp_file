#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Fruit
{
public:
	Fruit(string kind)
	{
		this->kind = kind;
		if (kind == "apple") {
			//����ƻ��
			//ƻ���ĳ�ʼ����ʽ
		}
		else if (kind == "banana") {
			//�����㽶
			//�㽶�ĳ�ʼ����ʽ
		}
	}

	void getName() {
		if (this->kind == "apple") {
			cout << "����ƻ��" << endl;
		}
		else if (this->kind == "banana"){
			cout << "�����㽶" << endl;
		}
	}
private:
	string kind;//����ˮ��������
};

int main(void)
{
	//����һ��ƻ��
	Fruit *apple = new Fruit("apple");
	apple->getName();
	delete apple;

	//main������Fruit��Ĺ��캯����϶ȸߣ� ����ˮ����������� ���캯��Խ��Խ����
	
	return 0;
}