#define _CRT_SECURE_NO_DEPRECATE    


/*          ���ֲ���--�Ǻ�����            */

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
//		if (arr[mid] > key) {			//���ڲ���Ԫ��
//			right = mid - 1;
//		}
//		else if (arr[mid] < key) {		//С�ڲ���Ԫ��
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


/*             ���ֲ���---������                */


#include <stdio.h>
int binary_search(int arr1[],int number, int size) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr1[mid] > number) {			//���ڲ���Ԫ��
			right = mid - 1;
		}
		else if (arr1[mid] < number) {		//С�ڲ���Ԫ��
			left = mid + 1;
		}
		else {								//�ҵ��ˣ����������±�
			return mid;
		}
	}
	return -1;								//û���ҵ�������-1
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);				//�����鳤��
	int key = 0;										
	int ret = 0;										//���ܺ������ر���
	int getnum = 1;										//ѭ���жϱ���
//	scanf("%d", &key);
again:													//goto���,������Ҫ�����жϵ�ʱ���������
	while (getnum) {									//whileѭ��
		printf("��������Ҫ�������в��ҵ�����:>");		//�����ʾ���
		scanf("%d", &key);								//������ҵ�����
		ret = binary_search(arr, key, sz);				//���ܷ���ֵ
//					����ȥ����   ���������   �������鳤��
		if (ret == -1) {								//û���ҵ�
			printf("error!\n");							//���error
		}												
		else {											//�ҵ��ˣ�����±�
			printf("�ҵ��ˣ������±�Ϊ%d\n", ret);
		}
		printf("����1���������ж�\n");					//��ʾ���
		scanf("%d", &getnum);							//��������1����������в���
		if (getnum == 1) {								//���������1����goto�����ҳ�ʼ����
			goto again;
		}
		else {}											//����ʲôҲ��ִ��
	}
	return 0;
}
