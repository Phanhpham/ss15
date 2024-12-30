#include<stdio.h>
#define MAX 100
//Khai bao danh sach ke
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;

//Ham them vao hang doi
void enqueue(int value){
	if(rear == MAX - 1){
		return;
	}
	if(front == -1){
		front = 0;
	}
	queue[++rear] = value;
}

//Lay phan tu khoi hnag doi
int dequeue(){
	if(front == -1 || front > rear){
		return -1;
	}
	return queue[front++];
}

//Thuat toan tim kiem theo chieu rong
void BFSFunction(int start, int n){
	for(int i = 0; i<n;i++){
		visited[i] = 0;
	}
	enqueue(start);
	visited[start] = 1;
	while(front <= rear){
		int current = dequeue();
		printf("%d", current);
		for(int i = 0; i<n; i++){
			if(graph[current][i] == 1 && !visited[i]){
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int n, u, v, start, edges;
	printf("Nhap vao so dinh : ");
	scanf("%d",&n);
	
	printf("Nhap vao so canh : ");
	scanf("%d",&edges);
	
	printf("Nhap cac canh (dinh v) : ");
	for(int i = 0; i < edges; i++){
		scanf("%d %d",&u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printf("Nhap vao dinh bat dau duyet : ");
	scanf("%d",&start);
	BFSFunction(start, n);
	return 0;
}
