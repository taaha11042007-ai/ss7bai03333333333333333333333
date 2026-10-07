# SMART HOME IOT SESSION 10

## 1. Mục tiêu

Bài tập phân tích Trade-off giữa việc sử dụng struct chưa tối ưu và struct đã được tái cấu trúc.

Chương trình thực hiện:

- Phân tích Memory Alignment và Padding.
- So sánh kích thước bằng `sizeof`.
- Tối ưu thứ tự các thành phần trong struct.
- Xây dựng struct lồng nhau.
- Kiểm tra dữ liệu cảm biến.
- Tính công suất thực tế.
- Phát hiện sai lệch cảm biến.
- Phát hiện quá tải.
- Phát hiện rò rỉ điện hoặc tải ẩn.
- Tính điện năng tiêu thụ theo kWh.

## 2. Phân tích Input

Các dữ liệu nhập vào gồm:

- Mã thiết bị.
- Tên thiết bị.
- Trạng thái thiết bị.
- Điện áp U.
- Dòng điện I.
- Công suất đo được P.
- Thời gian hoạt động t.

## 3. Phân tích Output

Chương trình xuất:

- Kích thước struct chưa tối ưu.
- Kích thước struct đã tối ưu.
- Kích thước struct lồng nhau.
- Công suất tính toán.
- Phần trăm sai lệch công suất.
- Cảnh báo cảm biến sai lệch nếu vượt 5%.
- Cảnh báo quá tải nếu I > 30A hoặc P > 6600W.
- Cảnh báo rò rỉ nếu thiết bị tắt nhưng I > 0.05A.
- Điện năng tiêu thụ theo kWh.

## 4. Giải pháp 1: Flat Struct Optimization

Struct chưa tối ưu:

```c
struct DeviceUnoptimized {
    char deviceName[20];
    double measuredPower;
    int deviceID;
    float voltage;
    int status;
    float current;
    int operatingMinutes;
};
