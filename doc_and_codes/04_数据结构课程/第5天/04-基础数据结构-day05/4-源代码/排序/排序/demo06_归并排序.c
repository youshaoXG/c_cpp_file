#include <stdio.h>
#include <stdlib.h>

//��������������a[first...mid]��a[mid+1...last]�ϲ���
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;	// ��һ���������еĿ�ʼ�±�
	int j = mid + 1;	// ��2���������еĿ�ʼ�±�

	int length = 0;
	// �ϲ�������������
	while (i<=mid && j<=last)
	{
		// �Ҷ����бȽ�С����
		if (a[i] < a[j])
		{
			temp[length] = a[i];
			i++;
		}
		else
		{
			temp[length] = a[j];
			j++;
		}
		length++;
	}
	// ��ʣ��һ������������������
	while (i <= mid)
	{
		temp[length] = a[i];
		i++;
		length++;
	}
	while (j <= last)
	{
		temp[length++] = a[j++];
	}

	// ����ԭ��λ�õ���������
	for (int i = 0; i < length; ++i)
	{
		// �ҵ�ԭ�� �ĵ�һ���������еĿ�ʼλ�� - ��ʼ����
		a[first + i] = temp[i];
	}
}

//�鲢����
void mergeSort(int a[], int first, int last, int temp[])
{
	// �ݹ����������
	if (first == last)
	{
		return;
	}
	// ���м�λ�ò��
	int mid = (first + last) / 2;
	// ���
	// ����
	mergeSort(a, first, mid, temp);
	// �Ұ��
	mergeSort(a, mid + 1, last, temp);
	// �ϲ�������������
	mergeArray(a, first, mid, last, temp);
}


#if 1
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

	//�������ʴ�С����ʱ����
	int *p = (int*)malloc(sizeof(int) * len);
	if (p == NULL)
	{
		return;
	}
	mergeSort(array, 0, len - 1, p);
	free(p);

	//����
	printf("�鲢����֮�������:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif