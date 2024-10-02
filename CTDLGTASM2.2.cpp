#include <iostream>
using namespace std;

// Định nghĩa một nút trong danh sách liên kết
struct Node {
    int data; // Dữ liệu trong nút (có thể thay bằng char nếu muốn lưu ký tự)
    Node* next; // Con trỏ trỏ đến nút tiếp theo
};

// Khởi tạo một hàng đợi với danh sách liên kết đơn
struct Queue {
    Node* front; // Phần tử đầu hàng đợi
    Node* rear;  // Phần tử cuối hàng đợi
    int maxSize; // Kích thước tối đa của hàng đợi
    int currentSize; // Số lượng phần tử hiện tại trong hàng đợi
};

// 1. Hàm khởi tạo hàng đợi với giới hạn kích thước
void initializeQueue(Queue &q, int size) {
    q.front = q.rear = nullptr;
    q.maxSize = size; // Đặt kích thước tối đa
    q.currentSize = 0; // Số lượng phần tử ban đầu là 0
}

// 2. Hàm kiểm tra hàng đợi rỗng
bool isEmpty(Queue q) {
    return (q.front == nullptr);
}

// 3. Hàm kiểm tra hàng đợi đầy
bool isFull(Queue q) {
    return (q.currentSize >= q.maxSize);
}

// 4. Hàm thêm một phần tử vào hàng đợi
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "The queue is full, cannot enqueue.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.currentSize++; // Tăng số lượng phần tử sau khi thêm
    cout << "Enqueued " << value << " into the queue.\n";
}

// 5. Hàm lấy một phần tử ra khỏi hàng đợi
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "The queue is empty, cannot dequeue.\n";
        return;
    }
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    cout << "Dequeued " << temp->data << " from the queue.\n";
    delete temp;
    q.currentSize--; // Giảm số lượng phần tử sau khi lấy ra
}

// 6. Hàm in phần tử đầu và cuối của hàng đợi
void printFrontRear(Queue q) {
    if (isEmpty(q)) {
        cout << "The queue is empty.\n";
    } else {
        cout << "Front element of the queue: " << q.front->data << "\n";
        cout << "Rear element of the queue: " << q.rear->data << "\n";
    }
}

int main() {
    Queue q;
    int maxSize;
    cout << "Enter the maximum size of the queue: ";
    cin >> maxSize;
    initializeQueue(q, maxSize);
    
    int choice, value;

    // 7. Menu thực hiện các chức năng
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue an element\n";
        cout << "2. Dequeue an element\n";
        cout << "3. Check if the queue is empty\n";
        cout << "4. Check if the queue is full\n";
        cout << "5. Print front and rear elements of the queue\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        // Kiểm tra lỗi nhập liệu
        if (cin.fail()) {
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(10000, '\n'); // Bỏ qua các ký tự còn lại trong bộ đệm
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                if (isEmpty(q)) {
                    cout << "The queue is empty.\n";
                } else {
                    cout << "The queue is not empty.\n";
                }
                break;
            case 4:
                if (isFull(q)) {
                    cout << "The queue is full.\n";
                } else {
                    cout << "The queue is not full.\n";
                }
                break;
            case 5:
                printFrontRear(q);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
