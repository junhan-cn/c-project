//快速排序
//基本思想：随变选择一个基准值，一般选择第一个数据，分别从左右两边开始，找到一边比基准大，一边比基准值小，交换
//直到左右相逢，再将基准值放到对应位置。这样就形成了以基准值为界的左边都比基准值小，右边比基准值大的，再通过递归完成排序。
#include <stdio.h>

int testData[10] = {11,234,24,112,4,335,23,99,54,66};


void exchange(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int quickSort(int left,int right) {

	if(left > right) {
		return 0;
	}

	int basedata = testData[left];

	int i,j;//i 从头部计数，j从尾部计数

	i = left; 
	j = right; 
	while(i<j) {
		while(i<j&&testData[j]>=basedata) j--;
		while(i<j&& testData[i]<=basedata) i++;

		if(i<j) {
			exchange(&testData[i],&testData[j]);
		}
	}
	exchange(&testData[i],&testData[left]);
	quickSort(left,i-1);
	quickSort(i+1,right);
	return 0;
}

int main(){
	quickSort(0,9);

	for(int i = 0;i<10;i++) {
		printf("%d\n",testData[i]);
	}
	return 0;
}
