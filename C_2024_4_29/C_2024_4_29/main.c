#define _CRT_SECURE_NO_DEPRECATE    


/*          二分查找--非函数版            */

//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int key = 0;
//	scanf("%d", &key);
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (arr[mid] > key) {			//大于查找元素
//			right = mid - 1;
//		}
//		else if (arr[mid] < key) {		//小于查找元素
//			left = mid + 1;
//		}
//		else {
//			printf("%d\n", mid);
//			break;
//		}
//	}
//	if (left > right) {
//		printf("error!\n");
//	}
//	return 0;
//}


/*             二分查找---函数版                */


#include <stdio.h>
int binary_search(int arr1[],int number, int size) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr1[mid] > number) {			//大于查找元素
			right = mid - 1;
		}
		else if (arr1[mid] < number) {		//小于查找元素
			left = mid + 1;
		}
		else {								//找到了，返回数组下标
			return mid;
		}
	}
	return -1;								//没有找到，返回-1
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);				//求数组长度
	int key = 0;										
	int ret = 0;										//接受函数返回变量
	int getnum = 1;										//循环判断变量
//	scanf("%d", &key);
again:													//goto语句,方便想要接着判断的时候更加容易
	while (getnum) {									//while循环
		printf("请输入你要在数组中查找的数字:>");		//输出提示语句
		scanf("%d", &key);								//输入查找的数字
		ret = binary_search(arr, key, sz);				//接受返回值
//					传过去数组   输入的数字   还有数组长度
		if (ret == -1) {								//没有找到
			printf("error!\n");							//输出error
		}												
		else {											//找到了，输出下标
			printf("找到了，数组下标为%d\n", ret);
		}
		printf("输入1继续进行判断\n");					//提示语句
		scanf("%d", &getnum);							//若是输入1，则继续进行查找
		if (getnum == 1) {								//若是输入的1，则goto到查找初始部分
			goto again;
		}
		else {}											//否则什么也不执行
	}
	return 0;
}
