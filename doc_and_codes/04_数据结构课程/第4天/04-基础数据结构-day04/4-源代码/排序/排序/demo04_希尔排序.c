#include <stdio.h>
#include <stdlib.h>

/**************************** ������� ****************************

	ϣ�������ǰѼ�¼���±��һ���������飬��ÿ��ʹ��ֱ�Ӳ��������㷨����
	���������𽥼��٣�ÿ������Ĺؼ���Խ��Խ�࣬����������1ʱ�������ļ�ǡ
	���ֳ�һ�飬�㷨����ֹ��

	�ȶ���: ϣ�������Ƿ��ȶ������㷨��

*****************************************************************/
//ϣ������
void shellSort(int *array, int len)
{
	// ����
	int gap = len;
	while (gap > 1)
	{
		// �����ݼ���ʽ
		gap = gap / 3 + 1;
		// ����, ��ÿһ��, ���в�������
		for (int i = 0; i < gap; ++i)
		{
			int tmp;	// ��׼��
			int index;	// �ӵ�λ��
			// ��������
			// ��������
			for (int j = i + gap; j < len; j += gap)
			{
				tmp = array[j];
				index = j;
				// ��������(�Ӻ���ǰ����)
				for (int k = j - gap; k >= 0; k -= gap)
				{
					if (tmp < array[k])
					{
						// ����
						array[k + gap] = array[k];
						// λ��
						index = k;
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
	}
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
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	//����
	shellSort(array, len);

	//����
	printf("ϣ������֮�������:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif