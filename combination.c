#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int *bits;
void combination(int n, int r, int index, int data[], int i, int *ret) {
	if (index == r) {
		if((bits[data[0]] | bits[data[1]]) == 1023)
			(*ret)++;
		printf("%d %d %d\n",data[0], data[1], *ret);
		return;
	}
	if (i >= n)
		return;
	data[index] = i;
	combination(n, r, index+1, data, i+1, ret);
	combination(n, r, index, data, i+1, ret);
}
int winningLotteryTicket(int tickets_size) {
	int data[2];
	int ret = 0;
	int len;
	combination(tickets_size, 2, 0, data, 0, &ret);
	return ret;
}

int main() {
	int n, len;
	char inp[1000000];
	freopen("input.txt", "r", stdin);
	scanf("%i", &n);
	bits = calloc(n, sizeof(int));
	for (int tickets_i = 0; tickets_i < n; tickets_i++) {
		//scanf("%s", inp);
		gets(inp, 1000000, stdin);
		len = strlen(inp);
		if (len == 0) {
			tickets_i--;
		}
		for (int i = 0; i < len; i++) {
			bits[tickets_i] |= (1 << (inp[i] - 48));
			if (bits[tickets_i] == 1023)
				break;
		}
	}
	int result = winningLotteryTicket(n);
	printf("%d\n", result);
	return 0;
}