#include <stdio.h>
#include <stdlib.h>

/*-------------------- ������� --------------------

		���Ĺ���ԭ����ÿһ�δӴ����������Ԫ����ѡ��
		��С������󣩵�һ��Ԫ�أ���������е���ʼλ
		�ã�ֱ��ȫ�������������Ԫ�����ꡣ

		�ȶ���:ѡ�������ǲ��ȶ������򷽷� ��:[5,5,3]

-------------------------------------------------*/

//ѡ������(��������)
void selectionSort(int *array, int len)
{
	int min = 0;	// ָ����С��Ԫ�ص�λ��
	// ���ѭ��
	for (int i = 0; i < len - 1; ++i)
	{
		min = i;
		// �ڴ�ѭ��
		for (int j = i + 1; j < len; ++j)
		{
			// �ж�
			if (array[min] > array[j])
			{
				// ������С��Ԫ�ص�λ��
				min = j;
			}
		}
		// �ж��Ƿ���Ҫ����
		if (min != i)
		{
			// �ҵ����µ���Сֵ
			// ����
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}
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
	selectionSort(array, len);

	//����
	printf("ѡ������֮�������:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif
