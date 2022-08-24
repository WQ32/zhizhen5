#include <stdio.h>
//// ��ϰ��
//
//int Add(int x,int y)
//{
//	return x + y;
//}
//int main()
//{
//	//ָ������
//	int* arr[10];
//	//����ָ��
//	int* (*pa)[10] = &arr;
//	// ����ָ��
//	int (*pAdd)(int, int) = &Add;
//	//���ú���  (*pAdd)(1,2)   pAdd(1,2)   Add(1,2)
//	
//	// ����ָ�������
//	int(*pArr[5])(int, int);
//	//ָ������ָ���ָ��
//	int(*(*ppArr)[5])(int, int) = &pArr;
//	return 0;
//}

//�ص�����

//// ��һ��ð�����򣨽��������ң�����Ԫ�ؽ��бȽϣ�
//bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 5,2,11,9,3,1,6,4,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz); 
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

// ������

// qsort - �⺯�� - ������������
// quick sort  ��������
// void qsort(void *base,        ���������ݵ���ʼλ��
//                 size_t num,	 �����Ԫ�ظ���
//                 size_t width, һ��Ԫ�ص��ֽڴ�С
//                 int(*cmp)(const void *e1,const void *e2) 
//				   cmp��һ������ָ�룬ָ��һ���ȽϺ���
//						
//            );
// ��д qsort����
#include <stdlib.h>
// ����ͷ�ļ�

int cmp_int(const void* e1, const void* e2)
{
	// �Ƚ���������ֵ��
	return *(int*)e1 - *(int*)e2;//��Ϊvoid*����ֱ�ӽ����ã�����Ҫǿ�Ƹı���������

}
void test1()
{
	int arr[10] = { 0,5,1,3,4,7,6,9,8,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2)
{
	//return *(float*)e1 - *(float*)e2;
	//�����ǿ��ԣ����ǻ�����棬���ص�float���뺯�����ص�int�Ͳ�����
	// ��ȷ��
	//��һ��return ((int)(*(float*)e1 - *(float*)e2));
	//������
	if ((*(float*)e1 - *(float*)e2) == 0)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void test2()
{
	float f[5] = { 1.0,5.0,4.0,9.0,7.0 };
	int sz1 = sizeof(f) / sizeof(f[0]);
	qsort(f, sz1, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz1; j++)
	{
		printf("%f ", f[j]);
	}
}
#include <string.h>
// ����ṹ��
struct Stu
{
	char name[10];
	int age;
};
// ��һ��
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
// ������  
int cmp_stu_by_name(const void* e1, const void* e2)
{
//�Ƚ����־��ǱȽ��ַ���
//�ַ����Ƚϲ���ֱ����><=���Ƚϣ�Ӧ����strcmp����������Ҫ����<string.h>ͷ������
//strcmp�������صĽ��Ҳ��-1,0,1
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3()
{
	struct Stu s[3] = { {"Zhangsan",20},{"Lisi",30},{"Wangwu",10} };
	int sz2 = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz2, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz2, sizeof(s[0]), cmp_stu_by_name);
	int k = 0;
	for (k = 0; k < sz2; k++)
	{
		printf("%s ", s[k]);
	}
}

void test4()
{
	struct Stu s[3] = { {"Zhangsan",20},{"Lisi",30},{"Wangwu",10} };
	int sz2 = sizeof(s) / sizeof(s[0]);
	qsort(s, sz2, sizeof(s[0]), cmp_stu_by_age);
	//qsort(s, sz2, sizeof(s[0]), cmp_stu_by_name);
	int k = 0;
	for (k = 0; k < sz2; k++)
	{
		printf("%s ", s[k]);
	}
}
int main() 
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	printf("\n");
	test4();
	return 0;
}




//// ����ָ������ - void*
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pb = &a;   // ���ַ�ʽҲ���ԣ�����Ҫ������
//	void* p = &a;    // ���ַ�ʽ����
//	char ch = 'w';
//	void* pd = &ch;   //Ҳ����
//	p = &ch;
//	// *p = 0;    // error
//	// p++;       // error
//	// void* ���͵�ָ�� ���Խ����������͵ĵ�ַ
//	// void* ���͵�ָ�� ���ܽ��н����ò�������û�о������ͣ�������ʱ��ȷ��
//	// void* ���͵�ָ�� ���ܽ��� + -�����Ĳ���
//	return 0;
//}