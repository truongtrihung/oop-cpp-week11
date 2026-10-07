#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

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
};

class Student {
//properties - những tính chat của đối tượng 
private:
    string name;
    string address;  
    Date birthdate; //yyyy/mm/dd hh:mm:ss
    string cccd; 

//methods
public: 
    //constructors: các hàm khởi tạo dữ lieu -> thông báo hđh cap phát vùng nhớ để lưu trữ 
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

    // Các hàm lấy thông tin cơ bản
    string getName() { return name; }
    string getAddress() { return address; }
    string getCccd() { return cccd; }
    int getBirthYear() { return birthdate.year; }

    void setStudentInfo() { //nhập thông tin sinh viên 
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap ngay thang nam sinh (ngay thang nam): ";
        cin >> birthdate.day >> birthdate.month >> birthdate.year;
        cin.ignore(); // Tránh trôi lệnh
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    void inThongTin() {
        cout << "Ten: " << name << " | Dia chi: " << address 
             << " | Nam sinh: " << birthdate.year << " | CCCD: " << cccd << endl;
    }
};

// ================= HÀM XỬ LÝ DANH SÁCH (TẤT CẢ HÀM GET ĐỀU TRẢ VỀ VECTOR) =================

// Lấy thông tin sinh viên theo CCCD (trả về vector chứa sinh viên tìm thấy)
vector<Student> getStudentInfo(string cccd, vector<Student> ds) {
    vector<Student> kq;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getCccd() == cccd) {
            kq.push_back(ds[i]);
        }
    }
    return kq;
}

// Lấy danh sách sinh viên theo tên
vector<Student> getStudents(string name, vector<Student> ds) {
    vector<Student> kq;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getName() == name) {
            kq.push_back(ds[i]);
        }
    }
    return kq;
}

// Update:
// 1. Thống kê và liệt kê danh sách sinh viên theo năm sinh (2000, 2001,...)
vector<Student> getStudentsByNamSinh(int nam, vector<Student> ds) {
    vector<Student> kq;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getBirthYear() == nam) {
            kq.push_back(ds[i]);
        }
    }
    return kq;
}

// 2. Thống kê và liệt kê danh sách sinh viên theo tỉnh
vector<Student> getStudentsByTinh(string tinh, vector<Student> ds) {
    vector<Student> kq;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getAddress().find(tinh) != string::npos) {
            kq.push_back(ds[i]);
        }
    }
    return kq;
}

// private/public: OOP = Data hiding -> Encapsulation 

int main() {
    Student student1;
    Student student2("huong");
    Student student3("", "vo van ngan");

    // Dữ liệu mẫu
    vector<Student> dsSinhVien;
    dsSinhVien.push_back(Student("An", "TPHCM", Date(1, 1, 2001), "001"));
    dsSinhVien.push_back(Student("Binh", "Dong Nai", Date(5, 5, 2001), "002"));
    dsSinhVien.push_back(Student("Cuong", "TPHCM", Date(10, 10, 2000), "003"));

    // 1. Liệt kê sinh viên sinh năm 2001
    cout << "=== DANH SACH SINH VIEN SINH NAM 2001 ===" << endl;
    vector<Student> ds2001 = getStudentsByNamSinh(2001, dsSinhVien);
    for (int i = 0; i < ds2001.size(); i++) {
        ds2001[i].inThongTin();
    }

    // 2. Liệt kê sinh viên theo tỉnh (TPHCM)
    cout << "\n=== DANH SACH SINH VIEN O TPHCM ===" << endl;
    vector<Student> dsTPHCM = getStudentsByTinh("TPHCM", dsSinhVien);
    for (int i = 0; i < dsTPHCM.size(); i++) {
        dsTPHCM[i].inThongTin();
    }

    return 0;
}