# Mini Google Maps (C++ CLI)

## Tên ứng dụng

**Mini Google Maps** là chương trình mô phỏng hệ thống tìm đường trên bản đồ bằng giao diện dòng lệnh (CLI). Chương trình cho phép tạo các địa điểm, kết nối chúng bằng các tuyến đường và tìm đường đi ngắn nhất giữa hai địa điểm bằng thuật toán Dijkstra.

---

## Mô tả ngắn gọn

Dự án được xây dựng nhằm mô phỏng nguyên lý hoạt động cơ bản của Google Maps. Mỗi địa điểm được biểu diễn bằng một đỉnh (Vertex), mỗi con đường được biểu diễn bằng một cạnh (Edge) có trọng số là khoảng cách. Thuật toán Dijkstra kết hợp với Min-Heap (Priority Queue) được sử dụng để tìm đường đi ngắn nhất.

---

## Cấu trúc dữ liệu sử dụng

### Graph (Adjacency List)

* **Dùng để:** Lưu trữ toàn bộ bản đồ.
* **Vì:** Tiết kiệm bộ nhớ và duyệt các cạnh nhanh hơn so với ma trận kề khi đồ thị thưa.

### Struct City

* **Dùng để:** Lưu thông tin của một địa điểm (ID, tên địa điểm).

### Struct Edge

* **Dùng để:** Lưu thông tin của một con đường gồm đỉnh đích và khoảng cách.

### Vector

* **Dùng để:** Lưu danh sách địa điểm, danh sách các cạnh và các mảng hỗ trợ thuật toán.
* **Vì:** Có thể thay đổi kích thước linh hoạt và truy cập nhanh theo chỉ số.

### Priority Queue (Min-Heap)

* **Dùng để:** Luôn lấy ra đỉnh có khoảng cách nhỏ nhất trong thuật toán Dijkstra.
* **Vì:** Giúp giảm độ phức tạp từ **O(V²)** xuống **O((V + E) log V)**.

### Parent Array

* **Dùng để:** Lưu đỉnh trước của mỗi đỉnh.
* **Vì:** Giúp truy vết và in lại đường đi ngắn nhất sau khi chạy Dijkstra.

### Distance Array

* **Dùng để:** Lưu khoảng cách ngắn nhất từ điểm xuất phát đến từng đỉnh.

---

## Compile và chạy

```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app
./app
```

Hoặc nếu toàn bộ chương trình nằm trong một file:

```bash
g++ -std=c++17 main.cpp -o app
./app
```

---

## Chức năng

1. Thêm địa điểm mới.
2. Thêm đường nối giữa hai địa điểm.
3. Hiển thị toàn bộ bản đồ.
4. Hiển thị danh sách các địa điểm.
5. Tìm đường đi ngắn nhất bằng thuật toán Dijkstra.
6. Hiển thị tổng quãng đường của đường đi ngắn nhất.
7. Thoát chương trình.

---

## Test Cases

### Test Case 1: Thêm địa điểm

* Thêm 5 địa điểm.
* Kiểm tra danh sách địa điểm được lưu đúng.

### Test Case 2: Thêm đường

* Thêm nhiều tuyến đường giữa các địa điểm.
* Kiểm tra bản đồ hiển thị đúng các kết nối.

### Test Case 3: Tìm đường ngắn nhất

* Chọn điểm bắt đầu và điểm kết thúc.
* Kết quả phải hiển thị đúng đường đi và tổng khoảng cách.

### Test Case 4: Không tồn tại đường đi

* Hai địa điểm không được kết nối.
* Chương trình thông báo không tìm thấy đường đi.

### Test Case 5: Điểm bắt đầu trùng điểm kết thúc

* Chọn cùng một địa điểm.
* Kết quả trả về khoảng cách bằng 0 và đường đi chỉ gồm một địa điểm.

---

## Cấu trúc file

```text
src/
│
├── main.cpp
│   └── Menu và điều khiển chương trình
│
├── structures.h
│   └── Khai báo struct City, Edge, Graph và nguyên mẫu các hàm
│
├── functions.cpp
│   └── Cài đặt các hàm xử lý Graph và thuật toán Dijkstra
│
└── data.txt
    └── Dữ liệu mẫu (nếu sử dụng)
```

---

## Thuật toán chính

* Xây dựng đồ thị bằng **Adjacency List**.
* Mỗi cạnh có trọng số là khoảng cách giữa hai địa điểm.
* Sử dụng **Dijkstra + Min-Heap (Priority Queue)** để tìm đường đi ngắn nhất.
* Sử dụng mảng **Parent** để khôi phục và hiển thị đường đi.

---

## Độ phức tạp

| Chức năng       | Độ phức tạp      |
| --------------- | ---------------- |
| Thêm địa điểm   | O(1)             |
| Thêm đường      | O(1)             |
| Hiển thị bản đồ | O(V + E)         |
| Dijkstra        | O((V + E) log V) |

Trong đó:

* **V**: số lượng địa điểm (Vertices).
* **E**: số lượng tuyến đường (Edges).
