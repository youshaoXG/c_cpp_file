#include <stdio.h>
#include <stdlib.h>

//��������
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r;
		// �ó���һ��Ԫ��, ���浽x��,��һ��λ�ó�Ϊһ����
		int x = s[l];
		while (i < j)
		{
			// ����������С��x����
			while (i < j && s[j] >= x)
			{
				//����, ֱ������С�ڵ���x����
				j--;
			}
			if (i < j)
			{
				//���Ҳ��ҵ���С��x��Ԫ�ط���������, �Ҳ����һ����
				//���Ԫ����������
				s[i++] = s[j];
			}

			// ���������Ҵ��ڵ���x����
			while (i < j && s[i] < x)
			{
				//����, ֱ����������x����
				i++;
			}
			if (i < j)
			{
				//������ҵ���Ԫ�ط����Ҳ����, ������һ����
				//�Ҳ�Ԫ��������ǰ�ƶ�
				s[j--] = s[i];
			}
		}
		//��ʱ i=j,��������x�е����������
		s[i] = x;
		quickSort(s, l, i - 1); // �ݹ���� 
		quickSort(s, i + 1, r);
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