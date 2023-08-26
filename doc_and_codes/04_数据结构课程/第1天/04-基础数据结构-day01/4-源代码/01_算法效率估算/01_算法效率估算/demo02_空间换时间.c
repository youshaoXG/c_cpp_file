#include <stdio.h>
#include <stdlib.h>

/***************************** ��ϰ *****************************

	��һ������Ȼ��1-1000��ĳЩ��������ɵ������У�ÿ�����ֿ��ܳ�����λ��߶�Ρ�
	���һ���㷨���ҳ����ִ����������֡�

	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };

	���ִ�����������: 6

***************************************************************/

//����
//ʱ�临�Ӷ�: O(n)
void search(int a[], int len)
{
	int sp[1000] = { 0 };	
	int i = 0;
	int max = 0;

	// ���������и�Ԫ��ֵ���ֵĴ���
	for (i = 0; i<len; i++)	//n
	{
		// ��ȡ������ i λ��Ԫ�ص�ֵ
		int index = a[i];
		// ������index���ֵĴ���
		// ����һ�ξ����µ������� index ��λ�ü�1
		sp[index]++;
	}

	//Ѱ��sp�����е������
	for (i = 0; i<1000; i++)	//n
	{
		if (max < sp[i])
		{
			//�������ֵ
			max = sp[i];
		}
	}

	//����λ��Ѱ�����ֵ��Ӧ��Ԫ��
	for (i = 0; i<1000; i++)	//n
	{
		if (max == sp[i])
		{
			printf("���ִ�����������: %d\n", i);
		}
	}
}

#if 1
int main()
{
	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };

	search(array, sizeof(array) / sizeof(*array));

	system("pause");
	return 0;
}
#endif


#if 0
#include <map>
#include <iostream>
using namespace std;

//STL ʵ��
void search(int* array, int len)
{
	map<int, int> M;
	for (int i = 0; i < len; i++)
	{
		//�������е�Ԫ��
		pair<map<int, int>::iterator, bool> pairIt = M.insert(pair<int, int>(array[i], 1));
		if (pairIt.second != true)
		{
			//�������ʧ��,��˵����������Ѵ���,����value����1����,������ֵĴ���
			M[array[i]]++;
		}
	}

	int max = 0;//�洢Ƶ��
	int data = 0;//a[i]
	for (int i = 0; i < len; i++)
	{
		if (M[array[i]] > max)
		{
			n = i;
			// �洢���ִ�������Ԫ��
			data = array[i];
			// �洢�������Ĵ���
			max = M[array[i]];
		}
	}
	cout<< "���ִ�������Ԫ��Ϊ:" << data << endl;
	cout<< "���ֵĴ���Ϊ: " << max <<endl;
}
#endif
