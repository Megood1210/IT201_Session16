#include <stdio.h>
#include <stdlib.h>

// Khởi tạo cấu trúc danh sách liên kết
typedef struct  Node{
    int data;
    struct Node *next;
}Node;
// Khợi tạo cấu trúc của một Queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Khởi tạo Queue
Queue* initialQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL){
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}
// Hàm tạo Node mới
Node* createNode(){
    // Nhập số nguyên bất kỳ
    int value;
    printf("Nhap so muon them vao hang doi: ");
    scanf("%d", &value);
    // Cấp phát
    Node* newNode = (Node *)malloc(sizeof(Node));
    // Kiểm tra cấp phát
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode; // trả về  phần tử được tạo
}
// Hàm thêm phần tử vào hàng đợi
void enqueue(Queue *q){
    // Tạo node mới
    Node* newNode = createNode();
    // Kiểm tra cấp phát
    if(newNode == NULL){
        printf("Khong tao duoc hang doi");
        return; // Dừng chương trình
    }
    // Kiểm tra hàng đợi rỗng
    if (q->rear == NULL){
        // Cập nhật phần tử đầu tiên và cuối vào node mới
        q->front = q->rear = newNode;
    // Kiểm tra hàng đợi không rỗng
    }else{
        q->rear->next = newNode; // Cập nhật phần tử cuối vào sau node hiện tại cuối hàng đợi
        q->rear = newNode; // Cập nhật phần tử cuối vào node mới
    }
}
// In ra hàng đợi
void displayQueue(Queue *q){
    Node * temp = q->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Hàm xem phần tử đầu hàng đợi
void peek(Queue* q){
    // Kiểm tra hàng đợi rỗng
    if(q->front == NULL){
        printf("queue is empty");
        return;
    }
    // Hiển thị phần tử đầu hàng đợi
    printf("%d ", q->front->data);
}
int main(){
    Queue* queue = initialQueue(); // Khợi tạo hàng đợi
    // Nhập 3 phần tử

    // Xem phần tử đầu hàng đợi
    peek(queue);

    // Giải phóng
    while (queue->front != NULL){
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
    return 0;
}


