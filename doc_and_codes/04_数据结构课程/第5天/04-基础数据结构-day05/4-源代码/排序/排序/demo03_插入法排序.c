#include <stdio.h>
#include <stdlib.h>

/******************* ������� *******************

	ÿ�δ�����ǽ��������еĵ�һ��Ԫ������������
	��Ԫ�شӺ���ǰ������бȽϣ��ҳ�����λ�ã���
	��Ԫ�ز��뵽�������еĺ���λ���С�

	�ȶ���:�����������ȶ���

***********************************************/

//���������㷨(��������)
void insertionSort(int *array, int len)
{
	int tmp = 0;	// �洢��׼��
	int index = 0;	// �ӵ�λ��
	// ������������
	for (int i = 1; i < len; ++i)
	{
		index = i;
		tmp = array[i];
		// ������������(�Ӻ���ǰ)
		for (int j = i - 1; j >= 0; --j)
		{
			// ��׼�������������е�Ԫ�رȽ�
			if (tmp < array[j])
			{
				// ��������Ԫ�غ���
				array[j + 1] = array[j];
				// �ӵ�λ��
				index = j;
			}
			else
			{
				break;
			}
		}
		// ���
		array[index] = tmp;
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
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	//����
	insertionSort(array, len);

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