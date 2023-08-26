#include <stdio.h>
#include <stdlib.h>

//��������������a[first...mid]��a[mid+1...last]�ϲ���
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int leftStart = first;	//�������������
	int leftEnd = mid;	//�����������յ�
	int rightStart = mid + 1;	//�������������
	int rightEnd = last;	//�����������յ�
	int length = 0;	//�����������кϲ�֮����������г���
	int i = leftStart, j = rightStart;
	
	//���������������е�Ԫ�غϲ�������������������(a����벿�ֺ��Ұ벿�ֺϲ���temp��)
	while (i <= leftEnd && j <= rightEnd)
	{
		//���մ�С�����˳����뵽temp��
		if (a[i] <= a[j])
		{
			temp[length++] = a[i++];
		}
		else
		{
			temp[length++] = a[j++];
		}
	}
	//�����벿�ֻ���Ԫ��, ֱ�ӷŵ�temp��
	while (i <= leftEnd)
	{
		temp[length++] = a[i++];
	}
	//����Ұ벿�ֻ���Ԫ��, ֱ�ӷŵ�temp��
	while (j <= rightEnd)
	{
		temp[length++] = a[j++];
	}
	//��temp���źõ����п�����a������
	for (i = 0; i < length; i++)
	{
		//ֻ�滻���ź������һ����
		a[leftStart + i] = temp[i];
	}
}

//�鲢����
void mergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		//�ҵ�������м�λ��
		int mid = (first + last) / 2;
		//�������
		mergeSort(a, first, mid, temp);  
		//�ұ�����
		mergeSort(a, mid + 1, last, temp); 
		//�ٽ������������кϲ�
		mergeArray(a, first, mid, last, temp); 
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