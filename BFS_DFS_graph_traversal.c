#define MAX_SIZE 100
int queue[MAX_SIZE];
int start, end, nElems;
int isEmpty() {
	return (nElems <= 0);
}
void initQueue() {
	start = 0;
	end = 0;
	nElems = 0;
}
void enQueue(int i) {
	if (nElems == MAX_SIZE) {
		printf("queue full\n");
		return;
	}
	queue[end] = i;
	end = (end + 1) % MAX_SIZE;
	nElems++;
}
int deQueue() {
	int ret;
	if (nElems == 0) {
		printf("queue empty\n");
		return -1;
	}
	ret = queue[start];
	start = (start + 1) % MAX_SIZE;
	nElems--;
	return ret;
}
#define N_VERTICES 4
int adj[N_VERTICES][N_VERTICES] = {	{0,1,1,0},
									{1,0,0,1},
									{1,0,0,1},
									{0,1,1,0}};
void DFS_recur(int v, int visited[]) {
	visited[v] = 1;
	printf("Visited %d\n", v);
	for (int i = 0; i < N_VERTICES; i++) {
		if (adj[v][i] == 1 && !visited[i]) {
			DFS_recur(i,visited);
		}
	}
}
void DFS(int v) {
	int visited[N_VERTICES];
	for (int i = 0; i < N_VERTICES; i++)
		visited[i] = 0;
	DFS_recur(v, visited);
}
int isBipartite() {
	int n, i;
	int color[N_VERTICES];
	for (i = 0; i < N_VERTICES; i++)
		color[i] = -1;
	color[0] = 0;
	enQueue(0);
	while (!isEmpty()) {
		n = deQueue();
		for (i = 0; i < N_VERTICES; i++) {
			if (adj[n][i] == 1){
				if (color[i] == -1) {
					color[i] = 1 - color[n];
					enQueue(i);
				}
				else if (color[i] == color[n])
					return 0;
			}
		}
	}
	return 1;
}
void BFS(int v) {
	int n, i;
	int visited[N_VERTICES];
	for (i = 0; i < N_VERTICES; i++)
		visited[i] = 0;
	visited[v] = 1;
	enQueue(v);
	while (!isEmpty()) {
		n = deQueue();
		printf("Visited %d\n",n);
		for (i = 0; i < N_VERTICES; i++) {
			if (adj[n][i] == 1 && !visited[i]){
				visited[i] = 1;
				enQueue(i);
			}
		}
	}
}