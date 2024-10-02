#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho danh sách liên kết đơn
struct Node {
    int data;       // Lưu trữ giá trị dữ liệu (kiểu số nguyên)
    Node* next;     // Con trỏ trỏ đến node tiếp theo
};

// Lớp Stack sử dụng danh sách liên kết đơn
class Stack {
private:
    Node* top;      // Con trỏ trỏ đến đỉnh của stack
    int size;       // Kích thước hiện tại của stack
    const int maxSize;  // Kích thước tối đa của stack

public:
    // Hàm khởi tạo stack với giới hạn kích thước
    Stack(int max) : maxSize(max) {
        top = nullptr;  // Khởi tạo đỉnh của stack là nullptr (ngăn xếp rỗng)
        size = 0;       // Khởi tạo kích thước của stack là 0
    }

    // Hàm kiểm tra stack có rỗng hay không
    bool isEmpty() {
        return top == nullptr;  // Nếu top là nullptr, trả về true (stack rỗng)
    }

    // Hàm kiểm tra stack có đầy hay không
    bool isFull() {
        return size == maxSize;  // Nếu kích thước hiện tại bằng kích thước tối đa, trả về true (stack đầy)
    }

    // Hàm đẩy (push) một phần tử vào stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push more elements." << endl;
            return;
        }
        Node* newNode = new Node();  // Tạo một node mới
        newNode->data = value;       // Gán giá trị cho node mới
        newNode->next = top;         // Liên kết node mới với node hiện tại ở đỉnh stack
        top = newNode;               // Cập nhật đỉnh stack thành node mới
        size++;                      // Tăng kích thước của stack
        cout << value << " has been pushed onto the stack." << endl;
    }

    // Hàm lấy (pop) một phần tử từ stack
    int pop() {
        if (isEmpty()) {  // Kiểm tra stack có rỗng không
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;  // Trả về -1 để báo lỗi
        }
        int poppedValue = top->data;  // Lấy giá trị của phần tử ở đỉnh stack
        Node* temp = top;             // Lưu node hiện tại vào biến tạm
        top = top->next;              // Cập nhật đỉnh stack thành node tiếp theo
        delete temp;                  // Giải phóng bộ nhớ của node vừa lấy ra
        size--;                       // Giảm kích thước của stack
        return poppedValue;           // Trả về giá trị của phần tử vừa lấy ra
    }

    // Hàm in phần tử ở đỉnh của stack
    void printTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "The top element is: " << top->data << endl;
        }
    }

    // Hàm huỷ để giải phóng bộ nhớ
    ~Stack() {
        while (!isEmpty()) {  // Xoá tất cả các phần tử còn lại trong stack
            pop();
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    Stack stack(maxSize);  // Tạo một đối tượng stack với kích thước tối đa
    int choice, value;

    // Menu
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Push an element onto the stack\n";
        cout << "2. Pop an element from the stack\n";
        cout << "3. Check if the stack is empty\n";
        cout << "4. Check if the stack is full\n";
        cout << "5. Print the top element of the stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
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
                cout << "Enter the value to push onto the stack: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                cout << "The popped element is: " << stack.pop() << endl;
                break;
            case 3:
                if (stack.isEmpty()) {
                    cout << "The stack is empty." << endl;
                } else {
                    cout << "The stack is not empty." << endl;
                }
                break;
            case 4:
                if (stack.isFull()) {
                    cout << "The stack is full." << endl;
                } else {
                    cout << "The stack is not full." << endl;
                }
                break;
            case 5:
                stack.printTop();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
