#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor không có tham số
    Date() : day(0), month(0), year(0) {}

    // Constructor có tham số 
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
};

class Student{
// Properties - những tính chất của đối tượng 
private:
    string name;
    string address;
    Date birthday; 
    string cccd;

// Methods
public:
    // Constructors: các hàm khởi tạo dữ liệu --> thông báo hđh cấp phát vùng nhớ để lưu trữ 
    Student() : name(""), address(""), birthday (), cccd ("") {}

    // Constructor chỉ lấy name
    Student (string n) : name (n), address(""), birthday(), cccd ("") {}

    // Constructor chỉ lấy địa chỉ 
    Student (string n) : name(""), address (n), birthday(), cccd ("") {}

    // Constructor chỉ lấy birthday
    Student (Date d) : name (""), address (""), birthday (d), cccd ("") {}

    // Constructor chỉ lấy cccd
    Student (string n) : name (""), address (""), birthday(), cccd ("") {}
};

int main(){

    return 0;
}