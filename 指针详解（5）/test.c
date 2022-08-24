#include <stdio.h>
//// 复习：
//
//int Add(int x,int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int* (*pa)[10] = &arr;
//	// 函数指针
//	int (*pAdd)(int, int) = &Add;
//	//调用函数  (*pAdd)(1,2)   pAdd(1,2)   Add(1,2)
//	
//	// 函数指针的数组
//	int(*pArr[5])(int, int);
//	//指向数组指针的指针
//	int(*(*ppArr)[5])(int, int) = &pArr;
//	return 0;
//}

//回调函数

//// 例一：冒泡排序（将数从左到右，相邻元素进行比较）
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

// 例二：

// qsort - 库函数 - 排序任意类型
// quick sort  快速排序
// void qsort(void *base,        待排序数据的起始位置
//                 size_t num,	 数组的元素个数
//                 size_t width, 一个元素的字节大小
//                 int(*cmp)(const void *e1,const void *e2) 
//				   cmp是一个函数指针，指向一个比较函数
//						
//            );
// 自写 qsort函数
#include <stdlib.h>
// 引入头文件

int cmp_int(const void* e1, const void* e2)
{
	// 比较两个整形值的
	return *(int*)e1 - *(int*)e2;//因为void*不能直接解引用，所以要强制改变他的类型

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
	//可以是可以，但是会出警告，返回的float型与函数返回的int型不符合
	// 正确：
	//法一：return ((int)(*(float*)e1 - *(float*)e2));
	//法二：
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
// 定义结构体
struct Stu
{
	char name[10];
	int age;
};
// 法一：
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
// 法二：  
int cmp_stu_by_name(const void* e1, const void* e2)
{
//比较名字就是比较字符串
//字符串比较不能直接用><=来比较，应该用strcmp函数（并且要引入<string.h>头函数）
//strcmp函数返回的结果也是-1,0,1
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




//// 任意指针类型 - void*
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pb = &a;   // 这种方式也可以，但是要报错误
//	void* p = &a;    // 这种方式可以
//	char ch = 'w';
//	void* pd = &ch;   //也可以
//	p = &ch;
//	// *p = 0;    // error
//	// p++;       // error
//	// void* 类型的指针 可以接受任意类型的地址
//	// void* 类型的指针 不能进行解引用操作符，没有具体类型，解引用时不确定
//	// void* 类型的指针 不能进行 + -整数的操作
//	return 0;
//}