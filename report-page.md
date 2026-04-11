# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu
Hiểu và cài đặt được các khái niệm nền tảng trong Lý thuyết thông tin và Mật mã học. Cụ thể:
- Nắm vững cách đo lường độ hỗn loạn (Entropy) và lượng thông tin dư thừa (Redundancy) của dữ liệu.
- Hiểu và lập trình được thuật toán Euclid mở rộng (Extended Euclidean Algorithm) để tìm nghịch đảo modulo (Modulo inverse).

## 2. Cách làm
- Đọc hiểu chương trình entropy mẫu: Phân tích cách chương trình C++ đọc đầu vào và tính toán xác suất xuất hiện của từng ký tự dựa trên tần suất.
- Bổ sung hàm tính redundancy: Cài đặt logic tính độ dư thừa thông tin dựa trên công thức `R = H_max - H(X)` (với giả định sử dụng bảng mã ASCII chuẩn, `H_max = log2(256) = 8`).
- Hoàn thiện hàm mod_inverse(): Cài đặt thuật toán Euclid mở rộng để tìm `x` sao cho `(a * x) mod m = 1`. Bổ sung bước kiểm tra điều kiện `gcd(a, m) == 1` và xử lý kết quả `x` âm bằng công thức `(x % m + m) % m` để đảm bảo kết quả luôn nằm trong khoảng `[0, m-1]`.
- Chạy thử trên nhiều test case: Biên dịch và đối chiếu kết quả output console của chương trình với kết quả tính toán thủ công trên giấy để xác minh tính chính xác của logic.

## 3. Kết quả chính
### 3.1 Entropy và redundancy
*(Lưu ý: Bảng dưới đây giả định tính Entropy theo đơn vị bits/symbol và H_max = 8 cho bảng mã ASCII)*

| Input | Entropy | Redundancy | Nhận xét |
|---|---:|---:|---|
| aaaa | 0 | 8 | Chỉ có 1 ký tự lặp lại hoàn toàn nên không có độ bất định (chắc chắn 100%), dữ liệu mang ít thông tin nhất. |
| abcd | 2 | 6 | 4 ký tự khác nhau với xác suất phân bố đều (0.25). Entropy đạt tối đa cho bộ 4 ký tự. |
| hello world | ~2.845 | ~5.155 | Phân bố tần suất không đều (chữ 'l' lặp 3 lần, 'o' lặp 2 lần, khoảng trắng 1 lần), độ hỗn loạn nằm ở mức trung bình. |

### 3.2 Modulo inverse
| a | m | Kết quả mong đợi | Kết quả chương trình |
|---:|---:|---|---|
| 3 | 7 | 5 | 5 |
| 10 | 17 | 12 | 12 |
| 6 | 9 | Không tồn tại | -1 (In ra thông báo không tồn tại do gcd != 1) |

## 4. Kết luận
- Bài lab giúp củng cố lại cách hoạt động của thuật toán Euclid mở rộng ở mức độ code thực tế thay vì chỉ tính toán trên giấy, đồng thời làm rõ rệt mối liên hệ giữa tần suất xuất hiện của ký tự và lượng thông tin (Entropy) mà thông điệp mang lại. 

- Khó khăn lớn nhất trong quá trình làm là việc xử lý các trường hợp ngoại lệ (edge cases) trong lập trình C++, đặc biệt là việc phải nhớ kiểm tra điều kiện `gcd(a, m) != 1` và mẹo xử lý lỗi phép toán `%` của C++ có thể trả về số âm để chương trình luôn xuất ra nghịch đảo modulo là số nguyên dương hợp lệ. Quá trình tự debug và đối chiếu kết quả từng bước của vòng lặp thực sự giúp nắm chắc bản chất toán học đằng sau hệ thống mật mã.