// CAN LAM CHINH LAI PHAN NHAP ID SINH VIEN
// CAP NHAT THEM TINH NANG SAP XEP THEO TEN A-Z
// quy ước chung các bảng, menu .... đc in ra dưới màu green
// các chức năng, thông tin sv đc in ra là màu 7 white
// các thư viện phục vụ công cuộc : lấy thông tin bàn phím vừa đc nhập, hàm liên quan tới dao diện terminal, hàm in chữ-công thức toán học
// hàm liên quan tới kiểu string
// hàm liên quan tới file

#include <windows.h>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

const int x =50;   //tọa độ CUA TABLE
const int y =4;   //tọa độ CUA TABLE
int z = y;

void GoTo(int posX, int posY);
void TextColor(int x);

struct sinhvien{
        string name;
        int id;
        float score;
        string subject;
        
        // constructor mặc định là :
        // sinhvien(){
        //     name ="Nguyen Van Minh Quan ";
        //     id = 2722225;
        //     score = 8.0;
        //     subject = "IT";
        // }
            void Nhap(){
                // không cần comment vì các dòng cout đã giải thích
                // cin.ignore() : xóa bộ nhớ đệm, cần đc dùng trc khi nhập string
                // getline(cin, biến) : nhập dữ liẹu vào biến để không bị mất dòng
                GoTo(x-3, y+19); cout <<"(!) Nhap ho ten sinh vien thu";
                cin.ignore();
                GoTo(x+30, y+19);
                getline(cin, name);
                do{
                    cin.ignore();
                    GoTo(x-3, y+20);
                    cout <<"(!) Nhap ma so sinh vien: ";
                    cin>>id;
                    cin.ignore();
                    GoTo(x-3, y+21);
                    cout<<"(!) Nhap diem so sinh vien: ";
                    cin>>score;
                    GoTo(x-3, y+22);
                    cout<<"(!) Nhap mon hoc: ";
                    cin.ignore();
                    getline(cin, subject);
                    
                    if(score<0 || score>10){
                        TextColor(4); GoTo(x+25, y+21); cout<<score;
                        TextColor(7);
                        GoTo(x+5, y+24);
                        cout <<"Diem khong hop le";
                        GoTo(x-5, y+25);
                        cout<<"Chuong trinh se chay toi khi diem hop le";
                        GoTo(x+5, y+26);
                        cout<<"Xin hay nhap lai\n";
                        Sleep(3000);
                        GoTo(x+5, y+24);
                        cout<<"                   ";
                        GoTo(x-5, y+25);
                        cout<<"                                        ";
                        GoTo(x+5, y+26);
                        cout<<"                 ";
                        do {
                            TextColor(7);
                            GoTo(x-3, y+21);
                            cout<<"(!) Nhap diem so sinh vien: ";
                            cout<<"        ";
                            GoTo(x-3, y+21);
                            cout<<"(!) Nhap diem so sinh vien: ";
                            cin>>score;
                            if(score<0 || score>10){
                            TextColor(4); GoTo(x+25, y+21); cout<<score;
                            Sleep(153);
                            }
                        } while (score <0 || score > 10);
                    }
                }while(score <0 || score > 10);

            }

};

// khai báo 2 biến minium và maxium dưới dạng toàn cục để phục vụ cho chức năng thống kê
sinhvien maxium;
sinhvien minium;

// khai báo các biến dưới hạng cục bộ hằng, để phục vụ cho dynamic sync
const int posX = 50;
const int posY = 2;
const int heith = 2;
const int weith =23;
const int num = 4;
const int b_color_sang = 4;


// dùng kĩ thuật overloading để khỏi gặp trường hợp hàm này gọi hàm kia nhưng hàm kia lại đc xác định ở dưới, gây ra lỗi
void thongkesv(sinhvien *person, int n);
void sortName(sinhvien *person, int n);
void restoredata(sinhvien *person, int &n);
void checkid(sinhvien *person, int n);
void loadingbarfile();
void box(int posX, int posY, int heith, int weith);
void n_box(int posX, int posY, int num, int heith, int weith, sinhvien* person, int n);
void hightlight(int posX, int PosY, int b_color_sang);
void dynamicsync(sinhvien* person, int n);
void filedeledata();
void fileOutds(sinhvien *person, int n);
void fileOuttk(sinhvien *person, int n);
void hocluc(sinhvien *person, int n);
void thongketable();
void thongke(sinhvien *person, int n);
void sort(sinhvien *person, int n);
void CapNhat(sinhvien *person, int n);
float Min(sinhvien *person, int n);
float Max(sinhvien *person, int n);
void drawTable();
void Press();
void Nhapperson(sinhvien *person, int &n);
void printtable(int n);
void printinfor(sinhvien *person, int n);
void Xoaperson(sinhvien *person, int &n);
void search(sinhvien *person, int n);
void swap(sinhvien &x, sinhvien &y);
void sort(sinhvien *person, int n);
void loadingbar(int &n);
void indexinfor(sinhvien *person, int n);
void indextable(int n);



int main(){
    system("cls");
    SetConsoleOutputCP(65001);
    SetConsoleTitle("NguyenVanMinhQuan-TH27.40-2722225231");
    sinhvien *person = new sinhvien[10];
    int count = 0, choice;

    do{

        TextColor(7);
        SetConsoleOutputCP(65001); // đặt các kí tự của console đc in ra là 65001 cho phép in cáckis tự đặc biệt, bao gồm tiếng việt
        system("cls");
        drawTable();
        GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: ";
        cin>>choice;
        switch (choice){
        case 0:
            printtable(count);
            printinfor(person, count);
            cout<<endl<<endl<<endl;
            Press();
            break;
        case 1:
            Nhapperson(person, count);
            count++;
            checkid(person, count);
            Press();
            break;
        case 2:
            printtable(count);
            printinfor(person, count);
            CapNhat(person, count);
            Press();
            break;  
        case 3:
            printtable(count);
            printinfor(person, count);
            Xoaperson(person, count);
            Sleep(2543);
            break;
        
        case 4:
            printtable(count);
            printinfor(person, count);
            search(person, count);
            Press();
            break;
        //////// ***
        case 5:
            sort(person, count);
            Press();
            break;
        case 6:
            thongke(person, count);
            hocluc(person, count);
            break;
        case 7:
            SetConsoleOutputCP(437);
            system("cls");
            dynamicsync(person, count);
            break;
        case 8:
            restoredata(person, count);

            break;
        case 9:
            system("cls");
            cout<<"\n\n\n\n\t\t\t\t    Đã kết thúc chương trình";
            Sleep(1298);
            cout<<"\n\t\t\tNó sẽ tự chuyển hướng đến creator trong 4s";
            ShowCursor(false);
            for(int i=4; i>0; --i){
                GoTo(64, 5); 
                TextColor(2);
                cout<<i;
                GoTo(66, 5); 
                Sleep(1000);
            }
            ShellExecute(0, 0, "https://linktr.ee/slso37", 0, 0 , SW_SHOW );
            return 0;
        default:
            system("cls");
            cout<<"\n\n\t\t\t Lua chon khong hop le !";\
            break;
        }
    } while (choice != 9);
    delete[] person;
    system("pause");
    return 0;
}       



// ham kiem tra id sinh vien
void checkid(sinhvien *person, int n){
    system("cls");
    for (int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if(person[j].id == person[i].id){
                system("cls");
                // GoTo(x+5, y+20);
                // cout<<"(!) Dang kiem tra lai thong tin lan cuoi ";
                // Sleep(2000);
                GoTo(x+5, y+4);
                cout<<"Ban da nhap trung ID ";
                TextColor(12); cout<<person[j].id;
                GoTo(x+5, y+5);
                TextColor(7);
                cout<<"Cho sinh vien: ";
                TextColor(12);
                cout<<person[j].name;
                GoTo(x+5, y+6);
                TextColor(7);
                cout<<"Vui long nhap lai!\n";
                Press();
                do{
                    system("cls");
                    GoTo(x+5, y+4);
                    cout<<"Ma sinh vien moi cho ";
                    TextColor(12);
                    cout<<person[j].name;
                    TextColor(7);
                    cout<<" la: ";
                    cin>>person[j].id;
                } 
                while (person[j].id == person[i].id);
            }
        }    
    }
}

// Hàm xóa sinh viên
void Xoaperson(sinhvien *person, int &n){
    int so, count =0;

    // khai báo biến "count" để in bảng phù hợp với số lượng sinh viên hiện tại
    for (int i=0; i<n; ++i){
        count++;
    }
    
    // in bảng và thông tin vào tọa độ người lập trình xác định trước
    bool loop = true;
    TextColor(2);
    GoTo(x+10, y+27+count); cout<<"+-------------------------------+";
    GoTo(x+10, y+28+count); cout<<"|";
    GoTo(x+42, y+28+count); cout<<"|";
    TextColor(12);
    GoTo(x+14, y+28+count); cout<<"(4)Xóa thông tin sinh viên";

    TextColor(2);
    GoTo(x+10, y+29+count); cout<<"+------";
    GoTo(x+10, y+30+count); cout<<"|";
    TextColor(7);
    GoTo(x+13, y+30+count); cout<<"ID";

    TextColor(2);
    GoTo(x+17, y+29+count); cout<<"+------------------------+";
    GoTo(x+17, y+30+count); cout<<"|";
    GoTo(x+42, y+30+count); cout<<"|";

    GoTo(x+10, y+31+count); cout<<"+------";
    GoTo(x+10, y+32+count); cout<<"|";
    TextColor(7);
    GoTo(x+11, y+32+count); cout<<"Status";
    TextColor(2);
    GoTo(x+10, y+33+count); cout<<"+------";

    TextColor(2);
    GoTo(x+17, y+31+count); cout<<"+------------------------+";
    GoTo(x+17, y+32+count); cout<<"|";	
    GoTo(x+42, y+32+count); cout<<"|";
    GoTo(x+17, y+33+count); cout<<"+------------------------+";

    // do {
        // GoTo(x+23, y+30+count); cout<<"              ";
        // GoTo(x+23,y+32+count); cout<<"              ";
label:
        GoTo(x+18,y+32+count); cout<<"                        ";
        GoTo(x+18,y+30+count); cout<<"                        ";
        GoTo(x+26, y+30+count);
        TextColor(7);
        cin >>so;

        // xóa = cách chèn dữ liệu của phần tử i+1 vào i

        for(int i=n; i>0; --i){
                if(person[i].id == so){
                    for(int j=i; j<n; j++){
                        person[j] = person[j+1];
                    }
                    loadingbar(n);
                    GoTo(x+24,y+35+count);
                    loop = false;
                }
            }

        //đặt ra trường hợp nếu user nhập sai thì sẽ cho phép user nhập lại

            GoTo(x+22,y+32+count);
            if (loop == true) {
                int choices;
                cout<<"KHONG TON TAI !";
                Sleep(1521);
                GoTo(x+22,y+32+count);
                cout<<"                 ";
                GoTo(x+21, y+30+count);
                cout<<"Nhap 0 de thoat";
                GoTo(x+21,y+32+count);
                cout<<"Nhap 1 de lam lai";
                GoTo(x+25,y+35+count); cin>>choices;
                switch (choices){
                case 0:
                    break;
                
                case 1:
                    GoTo(x+24,y+35+count); cout<<"   ";
                    goto label;
                    break;
                }
            } else n--;

    //     for(int i=0; i<n; i++){
    //         if(person[i].id == so){
    //             for(int j=i;j<n;j++)
    //                 person[j] = person[j+1];
    //                 loop = false;
    //                 loadingbar(n);
    //         }
    //     }
    // if(loop == true)
    //     cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
    // else n--;
}

// hàm chỉ in mỗi thông tin sinh viên
void printinfor(sinhvien *person, int n){
    TextColor(7);
    for (int i=0; i<n; ++i){
        GoTo(x+4, y+22+i); cout<<person[i].name;
        GoTo(x+28, y+22+i); cout<<person[i].id;       
        GoTo(x+40, y+22+i); cout<<person[i].score;
        GoTo(x+49, y+22+i); cout<<person[i].subject;
        GoTo(x+4, y+26+i);
    }
}

// hàm trả về giá trị điểm lớn nhất
float Max(sinhvien *person, int n){
    float max = person[0].score;

    // ép điểm lớn nhất là person[0]. cho vào vòng loop duyệt từ đầu mảng đến số lượng sinh viên hiện tại
    // nếu có giá trị nào lớn hơn thì ép max = giá trị đó
    // đồng thời đi tới tọa độ được xác định trước bởi người lập trình in ra tên
    string maxname = person[0].name;
    for(int i=1;i<n;i++){
        if(person[i].score >max){
            max = person[i].score;
            maxname = person[i].name;
            maxium = person[i];
        }
    }
    GoTo(x+16, y+22);cout<<maxname;
    GoTo(x+44, y+22);
    return max;
}

// hàm trả về giá trị nhỏ nhất
float Min(sinhvien *person, int n){
    float min = person[0].score;

    // ép điểm nhỏ nhất là person[0]. cho vào vòng loop duyệt từ đầu mảng đến số lượng sinh viên hiện tại
    // nếu có giá trị nào bé hơn thì ép min = giá trị đó
    // đồng thời đi tới tọa độ được xác định trước bởi người lập trình in ra tên
    string minname = person[0].name;
    for(int i=1;i<n;i++){
        if(person[i].score < min){
            min = person[i].score;
            minname = person[i].name;
            minium = person[i];
        }
    }
    GoTo(x+17, y+24);cout<<minname;
    GoTo(x+44, y+24);
    return min;
}

// hàm nhập thêm sinh viên
void Nhapperson(sinhvien *person, int &n){
    // khai báo biến "count" để in bảng phù hợp với số lượng sinh viên hiện tại
    bool loop = true;
    char choice;
    int count=0;

    //mỗi khi nhập 1 người thêm thì biến count sẽ + 1 đơn vị cho tới khi user muốn thoát ctrinh
    do {
        count++;
        TextColor(7);
        GoTo(x+27, y+19); cout<<count<<":";
        person[n].Nhap();
        GoTo(x-3, y+23);
        cout<<"(?) Ban co muon tiep tuc khong ? (y/n) ";
        cin>>choice;
        if (choice =='y' || choice =='Y'){
            loop = true;
            system("cls");
            drawTable();
            GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: 1";
            ++n;
        } else if (choice =='n' || choice =='N'){
            loop = false;
            system("cls");
            drawTable();
            GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: 1";
            GoTo(x+7, y+18);
            cout<<"(!) DA THEM ";

            // in ra số lượng sinh viên được thêm dưới màu "12" trong c++ lightgreen
            TextColor(12);
            cout<<count;
            TextColor(7);  // trả về màu 7 màu trắng 

            cout<<" SINH VIEN \n";
        }
    } while (loop == true);
}

//hàm in bảng cho chức năng in toàn bộ ds sinh viên
void printtable(int n){

    // đặt màu được in là 2 trong c++ ( màu green )
    // in bảng tới tọa độ đc xác định bởi người lập trình
    TextColor(2);
    GoTo(x-4, y+19); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+19); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+19); cout<<"+";

    GoTo(x-4, y+20); cout<<"|";
    GoTo(x+2, y+20); cout<<"|";
    GoTo(x+26, y+20); cout<<"|";
    GoTo(x+36, y+20); cout<<"|";
    GoTo(x+46, y+20); cout<<"|";
    GoTo(x+56, y+20); cout<<"|";

    GoTo(x-4, y+21); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+21); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+21); cout<<"+";
     
    TextColor(12);
    GoTo(x-2, y+20); cout<<"STT";
    GoTo(x+10, y+20); cout<<"Họ và Tên";
    GoTo(x+30, y+20); cout<<"ID";
    GoTo(x+38, y+20); cout<<"Điểm số";
    GoTo(x+48, y+20); cout<<"Môn học";
    GoTo(x+13, y+24);

    TextColor(2);
    int count =0;
    for (int i=0; i<n; ++i){
        GoTo(x-4, y+22+i); cout<<"|";
        TextColor(7);
        GoTo(x-1, y+22+i); cout<<i+1;
        TextColor(2);
        GoTo(x+2, y+22+i); cout<<"|";
        GoTo(x+26, y+22+i); cout<<"|";
        GoTo(x+36, y+22+i); cout<<"|";
        GoTo(x+46, y+22+i); cout<<"|";
        GoTo(x+56, y+22+i); cout<<"|";

        // khai báo biến "count" để in bảng phù hợp với số lượng sinh viên hiện tại
        count++;
    }
    GoTo(x-4, y+22+count); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+22+count); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+22+count); cout<<"+";
    cout<<endl;
}

// hàm di chuyển tới tọa độ x,y với x là ngang, y là dọc
void GoTo(int posX, int posY){
    //Hàm di chuyển con trỏ 
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    //đăt đối tượng con trỏ tới "position"
	SetConsoleCursorPosition(hStdout, Position);
}

// hàm in menu cho phần mở đầu chương trình
void drawTable(){
    TextColor(2);
    // KẺ ĐƯỜNG VIỀN CHO TABLE
    GoTo(x,y); cout<<"+"; cout<<"-----";
    GoTo(x+6,y); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33,y); cout<<"+"; cout<<"----------------";
    GoTo(x+50,y); cout<<"+"; 
    GoTo(x, y+1); cout<<"|"; GoTo(x+6, y+1); cout<<"|"; GoTo(x+33, y+1); cout<<"|"; GoTo(x+50, y+1); cout<<"|";
    GoTo(x, y+2); cout<<"+"; cout<<"-----";
    GoTo(x+6, y+2); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33, y+2); cout<<"+"; cout<<"----------------";
    GoTo(x+50, y+2); cout<<"+";

    GoTo(x+34, y+6); cout<<"----------------";
    GoTo(x+34, y+9); cout<<"----------------";

    GoTo(x, y+13); cout<<"+"; cout<<"-----";
    GoTo(x+6, y+13); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33, y+13); cout<<"+"; cout<<"----------------";
    GoTo(x+50, y+13); cout<<"+";

    TextColor(12);
    GoTo(x+2, y+1); cout<<"STT"; GoTo(x+12, y+1); cout<<"-> CHỨC NĂNG <-"; GoTo(x+37, y+1); cout<<"SỠ HỮU BỞI";

    //  KẺ "|"
    for (int i=y+3-z; i<y+13-z; ++i){
        TextColor(2);
        GoTo(x, y+i); cout<<"|";
        GoTo(x+6, y+i); cout<<"|"; 
        GoTo(x+33, y+i); cout<<"|"; 
        GoTo(x+50, y+i); cout<<"|";
    }
    //  VIẾT SỐ
    for (int i=0; i<10; ++i){
        TextColor(7);
        GoTo(x+3, y+3+i); cout<<i;
    }
    //  VIẾT CHỨC NĂNG
    for (int i=0; i<10; ++i){
        TextColor(7);
        switch (i){
        case 0:
            GoTo(x+8, y+3+i);
            cout<<"In danh sách sinh viên";
            GoTo(x+39, y+3+i);
            cout<<"Name: ";
            break;
        case 1:
            GoTo(x+8, y+3+i);
            cout<<"Thêm sinh viên";
            GoTo(x+37, y+3+i);
            cout<<"Nguyễn Văn";
            break;
        case 2:
            GoTo(x+8, y+3+i);
            cout<<"Sửa thông tin sinh viên";
            GoTo(x+37, y+3+i);
            cout<<"Minh Quân";
            break;
        case 3:
            GoTo(x+8, y+3+i);
            cout<<"Xóa thông tin sinh viên";
            break;
        case 4:
            GoTo(x+8, y+3+i);
            cout<<"Tìm kiếm thông tin (ID)";
            GoTo(x+39, y+3+i);
            cout<<"Class: ";
            break;
        case 5:
            GoTo(x+8, y+3+i);
            cout<<"Sắp xếp sinh viên";
            GoTo(x+38, y+3+i);
            cout<<"TH27.40";
            break;
        case 6:
            GoTo(x+8, y+3+i);
            cout<<"Thống kê sinh viên";
            break;
        case 7:
            GoTo(x+8, y+3+i);
            cout<<"Xử lý file";
            GoTo(x+37, y+3+i);
            cout<<"Quê quán: ";
            break;
        case 8:
            GoTo(x+8, y+3+i);
            cout<<"Khôi phục thông tin";
            GoTo(x+38, y+3+i);
            cout<<"Nghệ An";
            break;
        case 9: 
            GoTo(x+8, y+3+i);
            cout<<"Thoát chương trình";
            GoTo(x+37, y+3+i);
            cout<<"Hoàng Mai";
            break;
        }
    }
    TextColor(7);
}

// hàm tạm dừng, clr màn hình
void Press(){
    system("pause");
    system("cls");
}

// hàm ép màu chữ được in ra
void TextColor(int x){
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    // đặt đối tượng màu chữ đc in ra là "x"
    SetConsoleTextAttribute(h, x);
}

// hàm tìm kiếm thôg tin = id
void search(sinhvien *person, int n){
    bool loop = true;
    int choices;
    int ID =0;
    int count =0;
    //// khai báo biến "count" để in bảng phù hợp với số lượng sinh viên hiện tại

    do{
        label:  // đặt label ngay tại vị trí sau câu lệnh do while để phục vụ cho user nếu người nhập sai thông tin id sinh viên
        TextColor(12);
        GoTo(x-3, y+25+n);
        cout<<"(4) Tim kiem thong tin sinh vien";
        TextColor(7);
        GoTo(x-3, y+26+n);
        cout<<"(!) Nhap ID sinh vien: ";
        cin>>ID;
        for (int i=0; i<n; ++i){
            if (ID == person[i].id){ //**
                system("cls");
                drawTable();
                GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ:";
                count++;
                loop = false;
                printtable(count);
                TextColor(7);
                GoTo(x+4, y+21+count); cout<<person[i].name;
                GoTo(x+28, y+21+count); cout<<person[i].id;       
                GoTo(x+40, y+21+count); cout<<person[i].score;
                GoTo(x+49, y+21+count); cout<<person[i].subject;
                GoTo(x+4, y+26+count);
            } 
        }  
        if  (loop == true) {
            // nếu nhập sai thì sẽ in ra ⬇️
            GoTo(x-10, y+28+n);
            cout<<"BAN DA NHAP THONG TIN SINH VIEN SAI!\n"<<endl;
            GoTo(x-10, y+29+n);
            cout<<"(?) Ban co muon nhap lai thong tin khong ? (0/1) ";
            cin>>choices;
            switch (choices){
            case 0:
                // có nghĩa người dùng chọn thoát ctrinh
                // câu lệnh sẽ ép loop về false và thoát luôn vòng lặp switch
                // loop = false có nghĩa là kết thúc luôn ctrinh
                loop = false;
                break;
            
            case 1:
                // clr lại màn hình và in ra bảng phụ, thông tin phụ để user có thể nhìn thấy và nhập id muốn sửa
                system("cls");
                indexinfor(person, n);
                indextable(n);
                // nếu nhập sai thì sẽ return câu lệnh về if (loop == true)
                // nhập đúng thì sẽ quay lại phần label đc đặt bên trên bởi người lập trình
                goto label;
                break;
            }
        }
    } while (loop == true);
}

// hàm cập nhật thông tin sinh viên = void nhap trong kiểu struct
void CapNhat(sinhvien *person, int n){
    int so, count=0;
    // khai báo biến "count" để in bảng phù hợp với số lượng sinh viên hiện tại
    char choice;
    bool loop = false, loop1 = false;
label:    
    for (int i=0; i<n; ++i){
        TextColor(7);
        count++;
        GoTo(x+4, y+22+i); cout<<person[i].name;
        GoTo(x+28, y+22+i); cout<<person[i].id;       
        GoTo(x+40, y+22+i); cout<<person[i].score;
        GoTo(x+49, y+22+i); cout<<person[i].subject;
    }
    TextColor(12);
    GoTo(x+4, y+26+count);
    cout <<"(2) ID THONG TIN SINH VIEN CAN THAY DOI: ";
    TextColor(7);
    cin >>so;
    system("cls");
    GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: 2";
    GoTo(x, y+19); cout<<"                                                                             ";

    // cho vòng lặp chạy để check id vừa nhập có giống với id sinh viên đã có ko
    for(int i=0; i<n;i++){
        if (person[i].id == so){
            do {
                //nếu có thì in ra thông tin hiện tại với màu 12 (light red) để user dễ nhìn hơn
                system("cls");
                TextColor(12);
                GoTo(x-3, y+9); cout<<"(!) THONG TIN HIEN TAI";
                TextColor(7);
                GoTo(x-3, y+11); cout<<"Name: ";
                TextColor(2); cout<<" "<<person[i].name;
                TextColor(7);
                GoTo(x-3, y+12); cout<<"ID: ";
                TextColor(2); cout<<"   "<<person[i].id; 
                TextColor(7);      
                GoTo(x-3, y+13); cout<<"Diem: ";
                TextColor(2); cout<<" "<<person[i].score;
                TextColor(7);
                GoTo(x-3, y+14); cout<<"Nganh: ";
                TextColor(2); cout<<person[i].subject;
                TextColor(7);
                GoTo(x-3, y+17);
                TextColor(12);
                cout<<"(2) SUA THONG TIN SINH VIEN";
                TextColor(7);
                // gọi ra chức năng nhập thông tin được định nghĩa trong hàm struct void nhap();
                person[i].Nhap();
                GoTo(x-3, y+23);
                cout<<"(?) Ban co muon nhap lai thong tin khong ? (y/n) ";

                // ép loop = true nếu chọn đồng ý nhập lại thì loop = true và cho phép nhập lại thông tin, nếu ko thì loop = false
                loop1 = true;
                cin>>choice;
                system("cls");
                if (choice =='y' || choice =='Y'){
                    loop = true;
                    system("cls");
                    ++n;
                } else if (choice =='n' || choice =='N'){
                    loop = false;
                    system("cls");
                    break;
                }
                // loop = false thì thoát chương trình
            } while (loop == true);
        } 
    }
    // ép loop1 = false ngay từ đầu, nếu nhập sai thì giá trị loop1 ko ảnh hưởng và vẫn là false
    // nếu loop1= false thì có nghĩa ID đã sai
    if(loop1 == false){
        system("cls");
        GoTo(x-3, y+17);
        TextColor(12);
        cout <<"(!) Ban da nhap ma so sinh vien sai!";
        TextColor(7);
        GoTo(x-3, y+18); cout<<"(?) Ban co muon nhap khong (0/1) ";
        int choices;
        cin>>choices;
        printtable(count);
        switch (choices){

        case 0:
        system("cls");
            break;
        
        case 1:
            goto label;
            break;
        }

    }
} 

// hàm sắp xếp thông tin sinh viên
void sort(sinhvien *person, int n){
    bool loop = true;
    char choice;
    do{
        GoTo(x+8, y+18);
        TextColor(12);
        cout<<"(5) SAP XEP SINH VIEN";
        GoTo(x+8, y+19);
        TextColor(7);
        cout<<"(!) Theo diem so: ";
        GoTo(x+8, y+20);
        cout<<"(?) Theo ten sv:";
        GoTo(x+8, y+21);
        cout<<"==> Lua chon cua ban la: ";
        cin>>choice;
        system("cls");
        switch (choice){
            // hàm sắp xếp theo điểm 
        case '!':
            for (int i=0; i<n; ++i){
                for (int j=i+1; j<n; ++j){
                if (person[i].score < person[j].score) 
                    swap(person[i], person[j]);
                }
            }
            drawTable();
            GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: ";
            printtable(n);
            printinfor(person, n);
            loop = false;
            break;
            // ///////////// cần cập nhập thêm tên alphabet
        case '?':
            sortName(person, n);
            system("cls");
            drawTable();
            GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: ";
            printtable(n);
            printinfor(person, n);
            loop = false;
            break;
        default:
            system("cls");
            cout<<"\n\n\t\t\t Lua chon khong hop le !";
            break;
        }
    } while (loop == true);
}

// hàm loading 
void loadingbar(int &n){
    int count =0;
    for (int i=0; i<n; ++i){
        count++;
    }
    GoTo(x+18,y+32+count); cout<<"                        ";
    srand(time(NULL));
    GoTo(x+18, y+32+count);
    // đặt kí tự thành bảng ascii tại trang 437
    // phù hợp với thanh loading
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    // do tại sao lại bar1, bar2 lại đc gán cho số như vậy thì xem bảng ascii
    int bar1 = 177, bar2 = 219;
	int m;
    for(int i = 0; i < 24; i++){
		TextColor(13);
        cout << (char)bar1;
	}
    GoTo(x+18,y+32+count);
    for(int i = 0; i < 23; i++){
		TextColor(13);
        cout << (char)bar2;
		m = rand() % 500 +1;
        Sleep(m);
    }
    Sleep(645);
    GoTo(x+18,y+32+count); cout<<"                        ";
    GoTo(x+25,y+32+count); cout<<"COMPLETE!";
    GoTo(x+25,y+35+count);
}

// hàm thống kê điểm lớn, nhỏ nhất và in ra điểm lớp nhỏ nhất
void thongke(sinhvien *person, int n){
    thongketable();
    Max(person, n);
    cout<<fixed<<setprecision(1)<<Max(person, n);
    Min(person, n);
    cout<<fixed<<setprecision(1)<<Min(person, n);
    GoTo(x+41, y+27); cout<<n;
    hocluc(person, n);
    GoTo(x+10, y+40);
    Press();
    thongkesv(person, n);
    GoTo(x+10, y+20);
    Press();
}

// hàm ép hhọc lực
void hocluc(sinhvien *person, int n){
    float hocluctot = 0, hocluckha = 0, hoclucyeu = 0;

    // nếu >= 8 thì có nghĩa là số lượng học lực tốt ++;
    for (int i=0; i<n; ++i){
        if (person[i].score >= 8){
            hocluctot +=1.0;
        }
    }


    //nếu < 8 và >=6.5 thì số lượgn học lực khá ++
    for (int i=0; i<n; ++i){
        if (person[i].score < 8 && person[i].score >= 6.5){
            hocluckha+=1.0;
        }
    }

    // nếu bé hơn 6.5 và lớn hơn hoặc =0 thì học lực yếu ++;
    for (int i=0; i<n; ++i){
        if (person[i].score < 6.5 && person[i].score >= 0){
            hoclucyeu+=1.0;
        }
    }

    // in ra tỉ lệ học lực tại tọa độ đc xác định trc bởi dev
    GoTo(x+25, y+26); cout<<fixed<<setprecision(2)<<(float)((hocluctot)/n *100);
    GoTo(x+26, y+27); cout<<fixed<<setprecision(2)<<(float)((hocluckha)/n *100);
    GoTo(x+26, y+28); cout<<fixed<<setprecision(2)<<(float)((hoclucyeu)/n *100);

    GoTo(x+26, y+100);
}

// thong ke hs thi lai, dat
void thongkesv(sinhvien *person, int n){
    system("cls");
    TextColor(2);
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t(-) Các sinh viên đạt: \n";
    int numberous = 0;
    TextColor(7);
    for(int i=0; i<n; ++i){
        if(person[i].score >= 5){
            cout<<"\t\t\t\t\t\t\t+ "<<person[i].name<<": "<<person[i].score<<endl;
            numberous++;
        }
    }
    TextColor(4);
    cout<<"\n\t\t\t\t\t\tSố lượng sinh viên đạt: ";
    TextColor(7);
    cout<<numberous;

    TextColor(2);
    cout<<"\n\n\n\t\t\t\t\t\t(-) Các sinh viên thi lại: \n";
    TextColor(7);
    for(int i=0; i<n; ++i){
        if(person[i].score < 5){
            cout<<"\t\t\t\t\t\t\t+ "<<person[i].name<<": "<<person[i].score<<endl;
        }
    }
    TextColor(4);
    cout<<"\n\t\t\t\t\t\tSố lượng sinh viên trượt: ";
    TextColor(7);
    cout<<n-numberous;

}

// hàm in ra thông tin bảng thông kê  dưới màu là 10 (light green)
void thongketable(){
    TextColor(10); 
    GoTo(x+1, y+19); cout<<"+-----------------------------------------------+";
    GoTo(x+1, y+21); cout<<"+--------+--------------------------------------+";
    GoTo(x+10, y+23); cout<<"---------------------------------------+";
    GoTo(x+1, y+25); cout<<"+--------+-----------------------+--------------+";
    GoTo(x+1, y+29); cout<<"+--------+-----------------------+--------------+";

    for (int i=0; i<=2; ++i){
        GoTo(x+1, y+20); cout<<"|";
        GoTo(x+1, y+20); cout<<"|";
        GoTo(x+49, y+20); cout<<"|";
        GoTo(x+49, y+24); cout<<"|";
        GoTo(x+49, y+22); cout<<"|";
        GoTo(x+1, y+22+i); cout<<"|";
        GoTo(x+10, y+22+i); cout<<"|";
        GoTo(x+1, y+26+i); cout<<"|";
        GoTo(x+10, y+26+i); cout<<"|";
        GoTo(x+34, y+26+i); cout<<"|";
        GoTo(x+49, y+26+i); cout<<"|";
    }
    TextColor(12); 
    GoTo(x+14, y+20); cout<<"(6) THONG KE SINH VIEN";
    TextColor(7);
    GoTo(x+4, y+23); cout<<"DIEM";
    GoTo(x+5, y+26); cout<<"%";
    GoTo(x+3, y+27); cout<<"TY-LE";
    GoTo(x+2, y+28); cout<<"HOC-LUC";

    GoTo(x+12, y+22); cout<<"Max: ";
    GoTo(x+12, y+24); cout<<"Min:";
    GoTo(x+12, y+26); cout<<"Hoc luc tot: "; /* */ GoTo(x+32, y+26); cout<<"%"; GoTo(x+37, y+26); cout<<"Trong tong";
    GoTo(x+12, y+27); cout<<"Hoc luc kha: "; /* */ GoTo(x+32, y+27); cout<<"%";
    GoTo(x+12, y+28); cout<<"Hoc luc yeu: "; /* */ GoTo(x+32, y+28); cout<<"%"; GoTo(x+37, y+28); cout<<"sinh vien";
}

// hàm phụ in ra thông tin sinh vien với vị trí phù hợp với chức năng thêm sinh viên (vị trí đc xác định trước bởi dev)
void indexinfor(sinhvien *person, int n){
    TextColor(7);
    for (int i=0; i<n; ++i){
        GoTo(x+4, y+3+i); cout<<person[i].name;
        GoTo(x+28, y+3+i); cout<<person[i].id;       
        GoTo(x+40, y+3+i); cout<<fixed<<setprecision(2)<<person[i].score;
        GoTo(x+49, y+3+i); cout<<person[i].subject;
        GoTo(x+4, y+7+i);
    }
}

// hàm phụ in ra thông tin sinh vien với vị trí phù hợp với chức năng thêm sinh viên (vị trí đc xác định trước bởi dev)
void indextable(int n){
    TextColor(2);
    GoTo(x-4, y); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y); cout<<"+"; cout<<"---------";
    GoTo(x+36, y); cout<<"+"; cout<<"---------";
    GoTo(x+46, y); cout<<"+"; cout<<"---------";
    GoTo(x+56, y); cout<<"+";

    GoTo(x-4, y+1); cout<<"|";
    GoTo(x+2, y+1); cout<<"|";
    GoTo(x+26, y+1); cout<<"|";
    GoTo(x+36, y+1); cout<<"|";
    GoTo(x+46, y+1); cout<<"|";
    GoTo(x+56, y+1); cout<<"|";

    GoTo(x-4, y+2); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+2); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+2); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+2); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+2); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+2); cout<<"+";
     
    TextColor(12);
    GoTo(x-2, y+1); cout<<"STT";
    GoTo(x+10, y+1); cout<<"Họ và Tên";
    GoTo(x+30, y+1); cout<<"ID";
    GoTo(x+38, y+1); cout<<"Điểm số";
    GoTo(x+48, y+1); cout<<"Môn học";
    GoTo(x+13, y+5);

    TextColor(2);
    int count =0;
    for (int i=0; i<n; ++i){
        GoTo(x-4, y+3+i); cout<<"|";
        TextColor(7);
        GoTo(x-1, y+3+i); cout<<i+1;
        TextColor(2);
        GoTo(x+2, y+3+i); cout<<"|";
        GoTo(x+26, y+3+i); cout<<"|";
        GoTo(x+36, y+3+i); cout<<"|";
        GoTo(x+46, y+3+i); cout<<"|";
        GoTo(x+56, y+3+i); cout<<"|";

        count++;
    }
    GoTo(x-4, y+3+count); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+3+count); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+3+count); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+3+count); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+3+count); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+3+count); cout<<"+";
    cout<<endl;
}

// hàm trao đổi giá trị 2 biến có kiểu dữ liệu struct = cách truyền tham chiếu
void swap(sinhvien &x,sinhvien &y){
   sinhvien index=x;
   x=y;
   y=index;
}

// thanh loading của chức năng 7 
void loadingbarfile(){

    GoTo(posX+13,posY+8); cout<<"ON LOADING !!";

    GoTo(posX-5, posY+9);
    srand(time(NULL)); // hàm sử dụng thời gian ngẫu nhiên 
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    int bar1 = 177, bar2 = 219;
	int m;
    for(int i = 0; i < 50; i++){
        GoTo(posX-5+i,posY+10);
		TextColor(2);
        cout << (char)bar1;
	}
    SetConsoleOutputCP(65001);
    GoTo(posX-2,posY+14); cout<<"=> Bản quyền thuộc: Nguyễn Văn Minh Quân <=";
    GoTo(posX+9,posY+15); cout<<"=> ID: 2722225231 <=";
    GoTo(posX+13,posY+16); cout<<"=> TH27.40 <=";
    
    SetConsoleOutputCP(437);
    for(int i = 0; i < 50; i++){
        GoTo(posX-5+i,posY+10);
		TextColor(2);
        cout << (char)bar2;
		m = rand() % 500 +1; // m có giá trị ngẫu nhiên từ 1<= m <=500
        Sleep(m);
    }
    TextColor(7);
    GoTo(posX+13,posY+12); cout<<"COMPLETED";
    Sleep(2134);
}

// hàm in thông tin toàn bộ thông tin sinh viên hiện tại vào file
/**
 * The function writes the information of an array of students to two output files, one with a
 * formatted table and the other with a simplified format for restoring the data.
 * 
 * @param person a pointer to an array of objects of type "sinhvien", which represents a list of
 * students' information.
 * @param n The number of elements in the array of type "sinhvien" that is passed as the first
 * parameter.
 */
void fileOutds(sinhvien *person, int n){
    ofstream fileOut; // khai báo bbiến fileOut có kiểu dữ liệu là output file
    ofstream fileOutretore;
    fileOut.open("outputds.txt",ios_base::trunc);
    fileOutretore.open("restoreds.txt",ios_base::trunc);

    fileOutretore<<n;

    // mở fileOut với đường dẫn là  C:\\Users\\admin\\Desktop\\outputds.txt với chế độ mỗi khi mở là xóa toàn bộ thông tin hiện có
    fileOut<<"Thong tin: \n";
    fileOut<<"Name\t| ID\t|Diem\t|Monhoc \n";
    for (int i=0; i<n; ++i){
        fileOut<<person[i].name<<" | "<<person[i].id<<" | "<<person[i].score<<" | "<<person[i].subject<<endl;
        fileOutretore<<person[i].name<<","<<person[i].id<<" "<<person[i].score<<person[i].subject<<endl;
        // in thông tin vào fileOut
    }
    fileOut.close();
}

// hàm in thông tin toàn bộ thống kê thông tin sinh viên hiện tại vào file
void fileOuttk(sinhvien *person, int n){
    Max(person, n);
    Min(person, n);
    ofstream fileOut;// khai báo bbiến fileOut có kiểu dữ liệu là output file
    fileOut.open("outputtk.txt",ios_base::trunc);
    // mở fileOut với đường dẫn là  C:\\Users\\admin\\Desktop\\outputtk.txt với chế độ mỗi khi mở là xóa toàn bộ thông tin hiện có
    
    // in các thông tin thống kê, tới vị trí phù hợp đc xác định bởi dev
    fileOut<<"\t\t\tTong so sinh vien: "<<n;

    fileOut<<"\n\n\n\t\t\tHighest: \n";
    fileOut<<maxium.name<<" | "<<maxium.id<<" | "<<maxium.score<<" | "<<maxium.subject;
    fileOut<<"\n\n\n\t\t\tLowest: \n";
    fileOut<<minium.name<<" | "<<minium.id<<" | "<<minium.score<<" | "<<minium.subject<<endl;

    fileOut<<"\n\t\t\tHoc luc: ";
    float hocluctot = 0, hocluckha = 0, hoclucyeu = 0;
    for (int i=0; i<n; ++i){
        if (person[i].score >= 8){
            hocluctot +=1.0;
        }
    }

    for (int i=0; i<n; ++i){
        if (person[i].score < 8 && person[i].score >= 6.5){
            hocluckha+=1.0;
        }
    }

    for (int i=0; i<n; ++i){
        if (person[i].score < 6.5 && person[i].score >= 0){
            hoclucyeu+=1.0;
        }
    }
    // in tỷ lệ học lưc tới, vị trí phù hợp đc xác định bởi dev
    fileOut<<"\n+ Tot: "<<fixed<<setprecision(2)<<(float)((hocluctot)/n *100)<<" %";
    fileOut<<"\n+ Kha: "<<fixed<<setprecision(2)<<(float)((hocluckha)/n *100)<<" %";
    fileOut<<"\n+ Yeu: "<<fixed<<setprecision(2)<<(float)((hoclucyeu)/n *100)<<" %";
    fileOut.close();
}

// hàm xóa tòa bộ dữ liệu của file, với file đc chọn từ user
void filedeledata(){
    ofstream fileOut0;
    ofstream fileOut1;

    TextColor(2);
    GoTo(posX, posY); cout<<"+-----CHON FILE-----+";
    GoTo(posX, posY+1); cout<<"|                   |";
    GoTo(posX, posY+2); cout<<"|                   |";
    GoTo(posX, posY+3); cout<<"|                   |";
    GoTo(posX, posY+4); cout<<"+-------------------+";

    TextColor(7);
    GoTo(posX+2, posY+1); cout<<"1. outputds.txt";
    GoTo(posX+2, posY+2); cout<<"2. outputtk.txt";
    GoTo(posX+2, posY+3); cout<<"0. Thoat";

    GoTo(posX, posY+6); cout<<"Lua chon cua ban : ";

    int choice;
    cin>>choice;

    // mở file với đường dẫn cho trước với chế độ mỗi khi mở là xóa toàn bộ thông tin hiện có
    if (choice ==1) fileOut0.open("outputds.txt",ios_base::trunc);
    if (choice ==2) fileOut1.open("outputtk.txt",ios_base::trunc);

    fileOut1.close();
    fileOut0.close();

}

// hàm in sáng chữ phục vụ cho dynamic sync
// cần update
void hightlight(int posX, int posY, int b_color_sang){
    TextColor(b_color_sang);
    // GoTo(posX+1, posY+1); cout<<"1. SAO LUU DANH SACH";
    // GoTo(posX+1, posY+3); cout<<"2. SAO LUU THONG KE";
    // GoTo(posX+1, posY+5); cout<<"3. THOAT CHUONG TRINH";
    for (int xi=posX+1; xi<posX+weith; ++xi){
        for (int yi = posY+1; yi<posY+heith; ++yi){
            switch (yi){
            case 3:
                GoTo(posX+1,yi); cout<<"1. SAO LUU DANH SACH";
                break;
            case 5:
                GoTo(posX+1,yi); cout<<"2. SAO LUU THONG KE";
                break;
            case 7:
                GoTo(posX+1,yi); cout<<"3. XOA DU LIEU FILE";
                break;
            case 9:
                GoTo(posX+1,yi); cout<<"4. THOAT CHUONG TRINH";
                break;  
            }
        }
    }
}

// hàm in ra hộp (vị trí x, vị trí y, số lượng hộp đc in, chiều cao, chiều rộng, dữ liệu biến đc truyền vào, só lượng biến đc truyền vào )
void n_box(int posX, int posY, int num, int heith, int weith, sinhvien* person, int n){
    TextColor(2);
    // ép về màu green in thoong tin, bảng cho chức năng 7
    for(int i=0; i<num; ++i){
        box(posX, posY + 2*i, heith, weith);
    }
    for(int i=1; i<num; ++i){
        GoTo( posX, (posY+heith)+2*(i-1)); cout<<(char)195;
        GoTo( posX+weith, (posY+heith)+2*(i-1)); cout<<(char)180;
    }
    TextColor(7);
    GoTo(posX+1, posY+1); cout<<"1. SAO LUU DANH SACH";
    GoTo(posX+1, posY+3); cout<<"2. SAO LUU THONG KE";
    GoTo(posX+1, posY+5); cout<<"3. XOA DU LIEU FILE";
    GoTo(posX+1, posY+7); cout<<"4. THOAT CHUONG TRINH";
}

// hàm chọn file đc in dữ liệu, xóa dữ liệu = kĩ thuật dynamic 
void dynamicsync(sinhvien* person, int n){
    n_box(posX , posY, num, heith, weith, person, n);
    ShowCursor(false);  // ẩn con trỏ

    // đặt biến có giá trị = vị trí cũ của con trỏ
    int xp = posX ; 
    int yp = posY ;

    bool press = true;
    bool loop = true;

    while (loop == true){
        if (press ==true){
            
            // nếu ấn thì sẽ in ra bbảng box, tới vị trí posX, posY là  vị trí cũ
            n_box(posX , posY, num, heith, weith, person, n);
            GoTo(posX, posY);

            hightlight(posX, posY, 7);

            // nếu ấn thì sẽ in ra bbảng box, tới vị trí xp, yp là vị trí mới
            hightlight(xp, yp, b_color_sang);

            // không thể xóa dữ liệu, chỉ chèn dữ liệu, điều đó dẫn tới user nhìn sẽ nghĩ là đã xóa
            press = false;
        }

        if(kbhit()){
            // cú pháp lấy nút bấm đc ấn vào
            char c = getch();
            press = true;
            
            if(c==72){// nut len = 72
                if (yp!=3) yp -= 2; // nếu lên tọa độ y-=2
                else yp = posY+6;
            }
            if (c==80){// nut xuong = 80 
                if (yp!=7) yp+=2; // xuống tọa độ +=2
                else yp = posY;
            }  
            if (c==13){ //nut enter = 13
                press = false;
                loop = false;
                switch (yp){
                    // dùng switch ép ngay tại ví trí đó sẽ thực hiện cái gì
                case posY+6: // thoat ctrinh
                    break;
                case posY+4: // chọn xóa dữ liệu file
                    system("cls");
                    filedeledata();
                    system("cls");
                    loadingbarfile();
                    break;
                case posY+2: // chọn in dữ liệu vào file dưới thông tin đc thống kê
                    system("cls");
                    fileOuttk(person, n);
                    system("cls");
                    loadingbarfile();
                    break;
                case posY:
                // chọn in dữ liệu vào file dưới thông tin là toàn bộ sinh viên hiện có
                    system("cls");
                    fileOutds(person, n);
                    system("cls");
                    loadingbarfile();
                    break;
                }
            }
        }   
    }
}

// hàm in ra box
void box(int posX, int posY, int heith, int weith){
    // in giá trị int dưới kiểu char, 
    // lý do là bảng ascii để in ra kí tự đặc biệt, in bảng cho đẹp
    for (int yi = posY; yi<= posY+heith; yi++){
        GoTo(posX, yi); cout<<(char)179; 
        GoTo(posX+weith, yi); cout<<(char)179;
    }

    for (int xi = posX; xi <= posX+weith; xi++){
        GoTo(xi, posY); cout<<(char)196;
        GoTo(xi, posY+heith); cout<<(char)196;
    }

    GoTo(posX, posY); cout<<(char)218;
    GoTo(posX+weith, posY); cout<<(char)191;
    GoTo(posX, posY+heith); cout<<(char)192;
    GoTo(posX+weith, posY+heith); cout<<(char)217;
}

// hàm khôi phục lại dữ liệu
void restoredata(sinhvien *person, int &n){
    GoTo(posX+5,posY+5); cout<<"KHÔI PHỤC DỮ LIỆU";
    ifstream fileIn;
    int data;
    fileIn.open("restoreds.txt");
// ghi lại số lượng sinh viên
// phụ trợ cho chức năng in bảng thông tin sinh viên
    fileIn>>data;
    n = data;
  for(int i=0; i<n; ++i){
    // ghi dữ liệu vào person[i].name tới khi gặp dấu ","
    getline(fileIn,person[i].name,',');
    fileIn>>person[i].id;
    fileIn>>person[i].score;
    // ghi dữ liệu vào person[i].name tới khi gặp xuống dòng
    getline(fileIn,person[i].subject,'\n');
  }

    fileIn.close();
    system("cls");
    loadingbarfile();
    GoTo(posX+13,posY+30);
}

// hàm sắp xếp tên
void sortName(sinhvien *person, int n){
    string *index = new string [n];
    int *pos = new int [n];
    for (int i=0; i<n; ++i){
        // ghi lại vị trí dấu cách cuối cùng của tên
        // ví dụ : Nguyễn Minh Quân
        //                    ^~~~~~~ đây là vị trí 
        
        pos[i] = person[i].name.rfind(" ");


        // dùng 1 biến trung gian copy chuỗi từ (vị trí + 1) và chỉ lấy 1 kí tự sẽ đc "Q"
        index[i]=person[i].name.substr(pos[i] + 1, 1);
    }  
   
    // Hàm sắp xếp tên
    // chúng ta có thể ép kiểu dữ liệu về int
      for(int i=0; i<n-1; ++i){
         for(int j=i+1; j<n; ++j){
            if(index[i] > index[j]){
               swap(person[i], person[j]);
            }
         }
      }
    delete[] index;
    delete[] pos;
}