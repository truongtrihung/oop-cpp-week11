#include <iostream>
#include <string>
#include <vector>

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

    string getBD() const {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
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
    Student (string n) : name (""), address (""), birthday(), cccd (n) {}

    Student (string name) {}
    Student (string name, string address) {}
    Student (string name, string address, Date birthday) {}
    Student (string name, string address, Date birthday, string cccd) {}

    void setStudentInfo() { // Hàm nhập thông tin sinh viên
        cin.ignore();
        cout << "Enter student name: "; getline (cin, name);

        cout << "Enter student address: "; getline (cin, address);

        cout << "Enter birthday (day/month/year): ";
        int day, month, year;
        char separator;
        cin >> day >> separator >> month >> separator >> year;
        birthday = Date(day, month, year);

        cout << "Enter cccd: "; getline (cin, cccd);
    }

    void getStudentInfo() const {  // Lấy thông tin sinh viên
        cout << name << "\t\t" << address << "\t\t" << birthday.getBD() << "\t\t" << cccd << endl;
    }

    Student getStudents (string name);

    Student getStudentbyAge (int age);

};

void main(){
    Student student1();
}