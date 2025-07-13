#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// Khởi tạo cấu trúc danh sách liên kết
typedef struct  Node{
    int data[MAX];
    struct Node *next;
}Node;
// Khợi tạo cấu trúc của một Queue
typedef struct Queue {
    int data[MAX];
    int front, rear;
} Queue;

// Khởi tạo Queue
void initialQueue(Queue *q){
    q->front = q->rear = -1; // Đă cả phần front và rear về -1 để biểu thị hàng đợi rỗng
}

int main(){

    return 0;
}


