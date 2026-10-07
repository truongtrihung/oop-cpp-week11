#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    int day, month, year;

    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Student {
// properties - những tính chất của đối tượng 
private:
    string name;
    string address;  
    Date birthdate; // yyyy/mm/dd hh:mm:ss
    string cccd; 

// methods
public: 
    // constructors: các hàm khởi tạo dữ liệu -> thông báo hđh cấp phát vùng nhớ để lưu trữ 
    Student() {
        name = ""; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }

    Student(string n) {
        name = n; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }  

    Student(Date d) {
        name = ""; 
        address = "";
        birthdate = d; 
        cccd = "";
    }

    Student(string n, string a) {
        name = n;
        address = a;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string a, Date d) {
        name = n;
        address = a;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string a, Date d, string c) {
        name = n;
        address = a;
        birthdate = d;
        cccd = c;
    }

    // Getter cơ bản
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getCccd() const { return cccd; }
    Date getBirthdate() const { return birthdate; }
    int getAge() const { return 2026 - birthdate.year; }

    // 1. Nhập thông tin sinh viên 
    void setStudentInfo() {
        cout << "Nhap ho ten: ";
        getline(cin, name);

        cout << "Nhap dia chi: ";
        getline(cin, address);

        cout << "Nhap ngay thang nam sinh (ngay thang nam): ";
        cin >> birthdate.day >> birthdate.month >> birthdate.year;
        cin.ignore(); 

        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    // Hàm xuất thông tin sinh viên
    void printStudentInfo() const {
        cout << "Ho ten: " << name << " | Dia chi: " << address << " | Ngay sinh: ";
        birthdate.printDate();
        cout << " | CCCD: " << cccd << endl;
    }

    // 2. Lấy thông tin 1 sinh viên theo CCCD từ danh sách
    static Student getStudentInfo(string searchCccd, const vector<Student>& list) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i].cccd == searchCccd) {
                return list[i];
            }
        }
        return Student(); // Trả về sinh viên rỗng nếu không tìm thấy
    }

    // 3. Lấy danh sách sinh viên theo tên
    static vector<Student> getStudents(string searchName, const vector<Student>& list) {
        vector<Student> result;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].name == searchName) {
                result.push_back(list[i]);
            }
        }
        return result;
    }

    // 4. Lấy danh sách sinh viên theo tuổi
    static vector<Student> getStudentsbyAge(int searchAge, const vector<Student>& list) {
        vector<Student> result;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getAge() == searchAge) {
                result.push_back(list[i]);
            }
        }
        return result;
    }
};

int main() {
    Student student1;
    Student student2("hung");
    Student student3("", "Nguyen Ai Quoc");

    return 0;
}