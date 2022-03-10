#include<stdio.h>
#include <stdlib.h>

void myMemCpy2(void* dest, void* src, size_t n, size_t s)
{
	
	if (s == 1) {
		char* csrc = (char*)src;
		char* cdest = (char*)dest;
		for (int i = 0; i < n; i++)
			*(cdest + i) = *(csrc + i);
		printf("%zu byte is detected!", sizeof(cdest[0]));
		printf("\n");
	}
	else if (s == 2) {
		short int* csrc = (short int*)src;
		short int* cdest = (short int*)dest;
		for (int i = 0; i < n; i++)
			*(cdest + i) = *(csrc + i);
		printf("%zu byte is detected!", sizeof(cdest[0]));
		printf("\n");
	}
	else if (s == 4) {
		int* csrc = (int*)src;
		int* cdest = (int*)dest;
		for (int i = 0; i < n; i++)
			*(cdest + i) = *(csrc + i);
		printf("%zu byte is detected!", sizeof(cdest[0]));
		printf("\n");
	}
	else if (s == 8) {
		double* csrc = (double*)src;
		double* cdest = (double*)dest;
		for (int i = 0; i < n; i++)
			*(cdest + i) = *(csrc + i);
		printf("%zu byte is detected!", sizeof(cdest[0]));
		printf("\n");
	}
	else {
		char* csrc = (char*)src;
		char* cdest = (char*)dest;
		for (int i = 0; i < n; i++)
			*(cdest + i) = *(csrc + i);
		printf("%zu byte is detected!", sizeof(cdest[0]));
		printf("\n");
	}
}


void myMemCpy(void* dest, void* src, size_t n)//if we cast every data type into char*, why do we determine function member as void* ?
{
	// Typecast src and dest addresses to (char *)
	char* csrc = (char*)src;
	char* cdest = (char*)dest;

	// Copy contents of src[] to dest[]
	for (int i = 0; i < n; i++)
		cdest[i] = csrc[i];
}

#define length 4
int main(void) {
	short int src_2[] = { 1,4,5,7 };
	short int dest_2[20];
	short int dest_2_0[20];

	int src_4[] = { 1,4,5,7 };
	int dest_4[20];
	int dest_4_0[20];

	char src_1[] = { '1','4','5','7' };
	char dest_1[20];
	char dest_1_0[20];

	double src_8[] = { 1.2f,2,3,4 };
	double dest_8[20];
	double dest_8_0[20];

	myMemCpy(dest_1_0, src_1, length);
	myMemCpy2(dest_1, src_1, length, sizeof(src_1[0]));
	printf("Actual data for 1 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%c ", src_1[i]);
	}
	printf("\n");
	printf("New memory copy for 1 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%c ", dest_1[i]);
	}
	printf("\n");
	printf("Classic memory copy for 1 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%c ", dest_1_0[i]);
	}
	printf("\n");
	printf("\n");

	myMemCpy(dest_2_0, src_2, length);
	myMemCpy2(dest_2, src_2, length, sizeof(src_2[0]));
	printf("Actual data for 2 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", src_2[i]);
	}
	printf("\n");
	printf("New memory copy for 2 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", dest_2[i]);
	}
	printf("\n");
	printf("Classic memory copy for 2 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", dest_2_0[i]);
	}
	printf("\n");
	printf("\n");

	myMemCpy(dest_4_0, src_4, length);
	myMemCpy2(dest_4, src_4, length, sizeof(src_4[0]));
	printf("Actual data for 4 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", src_4[i]);
	}
	printf("\n");
	printf("New memory copy for 4 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", dest_4[i]);
	}
	printf("\n");
	printf("Classic memory copy for 4 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", dest_4_0[i]);
	}
	printf("\n");
	printf("\n");

	myMemCpy(dest_8_0, src_8, length);
	myMemCpy2(dest_8, src_8, length, sizeof(src_8[0]));
	printf("Actual data 8 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", src_8[i]);
	}
	printf("\n");
	printf("New memory copy for 8 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", dest_8[i]);
	}
	printf("\n");
	printf("Classic memory copy for 8 byte\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", dest_8_0[i]);
	}
	printf("\n");
	printf("\n");

	float src_f[] = { 1.2f,2.1f,3,4 };
	float dest_f[20];
	float dest_f_0[20];

	myMemCpy(dest_f_0, src_f, length);
	myMemCpy2(dest_f, src_f, length, sizeof(src_f[0]));
	printf("Actual data for float\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", src_f[i]);
	}
	printf("\n");
	printf("New memory copy for float\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", dest_f[i]);
	}
	printf("\n");
	printf("Classic memory copy for float\n");
	for (int i = 0; i < length; i++) {
		printf("%0.1f ", dest_f_0[i]);
	}
	printf("\n");
}
//OUTPUT
/*
1 byte is detected!
Actual data for 1 byte
1 4 5 7
New memory copy for 1 byte
1 4 5 7
Classic memory copy for 1 byte
1 4 5 7

2 byte is detected!
Actual data for 2 byte
1 4 5 7
New memory copy for 2 byte
1 4 5 7
Classic memory copy for 2 byte
1 4 -13108 -13108

4 byte is detected!
Actual data for 4 byte
1 4 5 7
New memory copy for 4 byte
1 4 5 7
Classic memory copy for 4 byte
1 -858993460 -858993460 -858993460

8 byte is detected!
Actual data 8 byte
1.2 2.0 3.0 4.0
New memory copy for 8 byte
1.2 2.0 3.0 4.0
Classic memory copy for 8 byte
-92559604377396320631573109411943288059837260752080316881960960.0 -92559631349317830736831783200707727132248687965119994463780864.0 -92559631349317830736831783200707727132248687965119994463780864.0 -92559631349317830736831783200707727132248687965119994463780864.0

4 byte is detected!
Actual data for float
1.2 2.1 3.0 4.0
New memory copy for float
1.2 2.1 3.0 4.0
Classic memory copy for float
1.2 -107374176.0 -107374176.0 -107374176.0

*/