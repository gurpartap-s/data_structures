int main() {
	int i, j, key;
	int arr[] = {5,8,2,6,7,1,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < n; i++) {
		j = i - 1;
		key = arr[i];
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	for (i = 0; i < n; i++)
		printf("%d\n",arr[i]);
}