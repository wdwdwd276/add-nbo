#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
	if(argc < 3)
		return -1;
	
	FILE *fp1, *fp2;
	
	uint32_t num1, num2;

	fp1 = fopen(argv[1], "rb");
	if(fp1 == NULL)
		printf("fp1 notfound");

	fp2 = fopen(argv[2], "rb");
	if(fp2 == NULL)
		printf("fp2 notfound");

	fread(&num1, sizeof(uint32_t), 1, fp1);
	fread(&num2, sizeof(uint32_t), 1, fp2);

	uint32_t n1 = ntohl(num1);
	uint32_t n2 = ntohl(num2);
	uint32_t sum = n1 + n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

