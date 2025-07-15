# ESP-Firebase-Web-App - LÊ NGỌC TUẤN

# A. Công việc đã làm
## 1. Đọc giá trị cảm biến ánh sáng và điều khiển led
![alt](module_cam_bien_anh_sang.jpg)
###  Cách hoạt động của cảm biến ánh sáng?
- Cảm biến ánh sáng nhận tín hiệu ánh sáng làm điều kiện 
### Cảm biến ánh sáng có mấy kiểu trả về?
- Cảm biến ánh sáng có 2 kiểu trả về là digital(0 và 1) và analog( từ 0 -> 4095) 
## 2. Gửi giá trị cảm biến ánh sáng lên Firebase-Web-App
### a. Kết nối wifi
- Định dạng tên wifi, password?
- Cú pháp
	
		const char* ssid = "Nha Tro Vui Ve";
		const char* password = "66668888";
	
### b. Thiết lập Firebase
- Khai báo đối tượng toàn cục là gì?, Tìm hiểu 3 đối tượng dưới?
	
		FirebaseData fbData;
		FirebaseAuth auth;
		FirebaseConfig config;
	
- Định dạng host, auth?
- Cú pháp

		define Firebase_Host  "esp32-with-light-default-rtdb.firebaseio.com/" | -> lấy ở link địa chỉ Realtime Database
		define Firebase_Auth  "ex4GKoswbBLYjc0rtc4bWe5iZ5DZb9JBqkhI3F8Q" | -> project setting -> service accounts -> Database secrets
	
- Có thể sử dụng email thay cho auth?
	
		config.api_key = "YOUR_API_KEY";
		auth.user.email = "your@email.com";
		auth.user.password = "yourpassword";
		
## 3. Các lỗi có thể gặp phải khi thiết lập wifi và kết nối Firebase

### a. wifi
- Sai tên(ssid)
- Sai mật khẩu (password)
### b. Firebase
- Sai khi khai báo toàn cục
- Thư viện đổi mới, không cập nhập cú pháp liên kết 
- Tìm hiểu lỗi từ "FirebaseConfig" là gì?