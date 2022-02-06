#include <stdio.h>

int main(void) {
	int _sum = 0;

	for (int x = 0; x <1000;x+=8) {
		_sum += x;
	}

	printf("%d\n",_sum);
	return 0;
}
