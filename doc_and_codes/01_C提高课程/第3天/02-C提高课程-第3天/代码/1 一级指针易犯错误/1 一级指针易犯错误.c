#include	<stdio.h>

void	copy_str(char	*from, char	*to)
{
	//if (*from == '\0' || *to == '\0')
	if (from == NULL|| to == NULL) //�ж�һ��ָ���Ƿ�Ϸ� ��Ϊ���ж����Ƿ���Ұָ�룬 �����ǹ������������
	{
		printf("func	copy_str()	err\n");
		return;
	}
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';
}

char	*my_stract(char	*x, char*	y) //x = "123456\0",  y  ="abcd"
{
	char	str[80]; //"123456abcd\0 "
	                     //           ��
	char	*z = str;											/*ָ��zָ������str*/
	while (*z++ = *x++);
	z--;																				/*ȥ����β������־*/
	
	while (*z++ = *y++);
	z = str;		  /*��str��ַ����ָ�����z*/


	return(z);
}

int	main()
{
	char	*p = "aabbccdd";
	char	to[100] = { 0 } ;
	copy_str(p, to);
	printf("to	:	%s\n", to);
	return 0;
}