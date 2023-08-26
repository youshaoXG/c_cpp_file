#include <stdio.h>
#include <stdlib.h>

//��������
void quickSort(int s[], int l, int r)
{
	// �ݹ����������
	if (l >= r)
	{
		return;
	}
	int i = l;	// ��ʼλ��
	int j = r;	// ���һ��Ԫ�ص�λ��
	// ��׼��
	int tmp = s[l];	// ȡ��һ��Ԫ����Ϊ��׼�� -- i��λ���ǿ�

	// ѭ���ж�
	while (i < j)
	{
		// jλ�õ�Ԫ��, ���ڵ��ڻ�׼��
		while (i<j && s[j] >= tmp)
		{
			// ǰ��
			j--;
		}
		// �ҵ�����ӵ���
		if (i < j)
		{
			// ���
			s[i] = s[j];	// j��ɿ�
			// i����
			i++;
		}
		// �ƶ�i, �Ӳ��ƶ�
		// iλ�õ�Ԫ�� С�ڻ�׼��
		while (i < j && s[i] < tmp)
		{
			i++;
		}
		// �ҵ��˴��ڵ��ڻ�׼����Ԫ��
		if (i < j)
		{
			// ���ߵĿ�
			s[j] = s[i];
			// jǰ��
			j--;
		}
	}
	// i j ���� i==j
	// ���
	s[i] = tmp;
	// �����벿��
	quickSort(s, l, i - 1);
	// ��
	quickSort(s, i + 1, r);
}

#if 0
void main()
{
	int i;
	//������������
	int array[] = { 12, 5, 33, 6, 10 };
	//�������鳤��
	int len = sizeof(array) / sizeof(int);
	//��������
	printf("��������������: ");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	//����
	quickSort(array, 0, len-1);

	//����
	printf("��������֮�������:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif


#if 0

#define SWAP(x,y){int z;z=x;x=y;y=z;}
//��������
#pragma region �����ֿ���
int partition(int number[], int left, int right)
{
	int i, j, s;
	s = number[right];
	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (number[j] <= s)
		{
			i++;
			SWAP(number[i], number[j]);
		}
	}
	SWAP(number[i + 1], number[right]);
	return i + 1;
}

void quickSort(int s[], int left, int right)
{
	int q;
	if (left < right)
	{
		q = partition(s, left, right);
		quickSort(s, left, q - 1);
		quickSort(s, q + 1, right);
	}
}
#endif