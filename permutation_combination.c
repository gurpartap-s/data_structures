int count;
void printPermutation(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d",arr[i]);
	printf("\n");
	count++;
}
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void permute(int arr[], int l, int r, int n) {
	if (l == r) {
		printPermutation(arr, n);
		return;
	}
	for (int i = l; i <= r; i++) {
		swap(arr, l, i);
		permute(arr,l+1,r,n);
		swap(arr,l,i);
	}
}
void combinationUtil(int arr[], int n, int r, int outi, int data[], int inpi) {
	if (outi == r) {
		/*for (int i = 0; i < r ; i++)
			printf("%d", data[i]);
		printf("\n");*/
		permute(data, 0, r - 1, r);	//permutations of combinations
		return;
	}
	if (inpi >= n)
		return;
	data[outi] = arr[inpi];
	combinationUtil(arr, n, r, outi + 1, data, inpi + 1);	//include
	combinationUtil(arr, n, r, outi, data, inpi + 1);		//exclude
}
void combination(int arr[], int n, int r) {
	int data[4];
	combinationUtil(arr, n, r, 0, data, 0);
}
int main() {
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	combination(arr, n, 4);
	printf("%d\n",count);
	return 0;
}