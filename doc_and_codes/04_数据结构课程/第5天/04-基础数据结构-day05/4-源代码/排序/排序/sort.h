#ifndef SORT_H_
#define SORT_H_



//ѡ������(��������)
void selectionSort(int *array, int len);

//���������㷨(��������)
void insertionSort(int *array, int len);

//ð������
void bubbleSort(int *array, int len);

//ϣ������
void shellSort(int *array, int len);

//��������
void quickSort(int s[], int l, int r);

//�鲢����
void mergeSort(int a[], int first, int last, int temp[]);

#endif //SORT_H_