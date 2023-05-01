#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

enum GIOI_TINH {Nam, Nu};
int choice = 0;
ofstream fileOut;

class Con_Nguoi{
    private:
        string Name;
        int Sex;
        int Age;
    protected:
        char Chu_Cai_Cuoi(){
           return Name[Name.rfind(" ")+1];
        }
        virtual void NhapThongTin(){
            cout << "Nhap Ten: ";       getline(cin, Name);
            cout << "Nhap GT: "; cin >> Sex;
            cout << "Nhap Tuoi: ";      cin >> Age;
            cin.ignore();
        }
        virtual void XuatThongTin(){
            cout << left << setw(5) << "Ten: ";    cout << left << setw(20) << Name;
            cout << left << setw(3) << "GT: ";     cout << left << setw(7) << Sex;
            cout << left << setw(6) << "Tuoi: ";   cout << left << setw(7) << Age;
        }
        void Sao_Luu_Thong_Tin_Nguoi_Lon(){
            fileOut.open("DSNL.txt",ios_base::trunc);
            fileOut << Name << ", ";
            fileOut << Sex << ", ";
            fileOut << Age << ", ";
        }

       // FIXME: loi ko sync dc file
        void Sao_Luu_Thong_Tin_Tre_Em(){
            fileOut.open("DSTE.txt",ios_base::trunc);
            fileOut << Name << ", ";
            fileOut << Sex << ", ";
            fileOut << Age << ", ";
        }
        
};
class Nguoi_Lon : public Con_Nguoi{
    private:
        string CMND;
    public:
        char Chu_Cai_Cuoi(){
           return Con_Nguoi::Chu_Cai_Cuoi();
        }
        string So_CMND(){
            return CMND;
        }
        void NhapThongTin(){
            Con_Nguoi::NhapThongTin();
            cout << "Nhap CMND: ";       getline(cin, CMND);
        }
        void XuatThongTin(){
            Con_Nguoi::XuatThongTin();
            cout << left << setw(7) << "CMND: ";   cout <<left << setw(20) << CMND << endl;
        }
        // FIXME: loi ko sync dc file
        void Sao_Luu_Thong_Tin(){
            Sao_Luu_Thong_Tin_Nguoi_Lon();

            fileOut.open("DSNL.txt",ios_base::app);
            fileOut << CMND << endl << endl;

            fileOut.close();
        }
};
class Tre_Em : public Con_Nguoi{
    private:
        string MAHS;
    public:
        char Chu_Cai_Cuoi(){
           return Con_Nguoi::Chu_Cai_Cuoi();
        }
        string So_MAHS(){
            return MAHS;
        }
        void NhapThongTin(){
            Con_Nguoi::NhapThongTin();
            cout << "Nhap MAHS: ";       getline(cin, MAHS);
        }
        void XuatThongTin(){
            Con_Nguoi::XuatThongTin();
            cout << left << setw(7) << "MAHS: ";   cout <<left << setw(20) << MAHS << endl;
        }
        // FIXME: loi ko sync dc file
        void Sao_Luu_Thong_Tin(){
            Sao_Luu_Thong_Tin_Tre_Em();

            fileOut.open("DSTE.txt",ios_base::app);
            fileOut << MAHS << endl << endl;

            fileOut.close();
        }
};

struct List_Nguoi_Lon{
    Nguoi_Lon *Data;
    List_Nguoi_Lon* Next;
};
struct List_Tre_Em{
    Tre_Em *Data;
    List_Tre_Em* Next;
};

int Kich_Thuoc_Cua_List_Tre_Em(List_Tre_Em *mylist){
    int count = 0;
    for (List_Tre_Em *i = mylist->Next; i != nullptr; i = i->Next)
        count ++;
    return count;
}
int Kich_Thuoc_Cua_List_Nguoi_Lon(List_Nguoi_Lon *mylist){
    int count = 0;
    for (List_Nguoi_Lon *i = mylist->Next; i != nullptr; i = i->Next)
        count ++;
    return count;
}

void Khoi_Tao_Cau_Truc_Nguoi_Lon(List_Nguoi_Lon *&myList){
    myList = new List_Nguoi_Lon ();
    myList->Next = nullptr;
}
void Khoi_Tao_Cau_Truc_Tre_Em(List_Tre_Em *&myList){
    myList = new List_Tre_Em ();
    myList->Next = nullptr;
}

void Them_Doc_Gia_Nguoi_Lon(List_Nguoi_Lon *&mylist){
    List_Nguoi_Lon *tmp;
    
    Khoi_Tao_Cau_Truc_Nguoi_Lon(tmp);
    tmp->Data = new Nguoi_Lon ();
    tmp->Data->NhapThongTin();

    if (mylist == nullptr)
        mylist = tmp;
    else {
        List_Nguoi_Lon *index = mylist;

        for (int i=0; i<Kich_Thuoc_Cua_List_Nguoi_Lon(mylist); ++i)
            index = index->Next;
        index->Next = tmp;
    }
}
void Them_Doc_Gia_Tre_Em(List_Tre_Em *&mylist){
    List_Tre_Em *tmp;
    
    Khoi_Tao_Cau_Truc_Tre_Em(tmp);
    tmp->Data = new Tre_Em ();
    tmp->Data->NhapThongTin();

    if (mylist == nullptr)
        mylist = tmp;
    else {
        List_Tre_Em *index = mylist;
        
        for (int i=0; i<Kich_Thuoc_Cua_List_Tre_Em(mylist); ++i)
            index = index->Next;
        index->Next = tmp;
    }
}

void Xuat_Thong_Tin_Nguoi_Lon(List_Nguoi_Lon *mylist){
    for (List_Nguoi_Lon *i = mylist->Next; i != nullptr; i = i->Next)
        i->Data->XuatThongTin();
}
void Xuat_Thong_Tin_Tre_Em(List_Tre_Em *mylist){
    for (List_Tre_Em *i = mylist->Next; i != nullptr; i = i->Next)
        i->Data->XuatThongTin();
}

int Tim_Kiem_Thong_Tin_Nguoi_Lon(List_Nguoi_Lon *mylist){
    string CMND;
    cout<< "Nhap CMND Tim kiem: "; getline(cin, CMND);

    int count = 1;
    for (List_Nguoi_Lon *i = mylist->Next; i != nullptr; i = i->Next)
        if (i->Data->So_CMND() == CMND)
            return count;
        else count++;
}
int Tim_Kiem_Thong_Tin_Tre_Em(List_Tre_Em *mylist){
    string MAHS;
    cout<< "Nhap MAHS Tim kiem: "; getline(cin, MAHS);

    int count = 1;
    for (List_Tre_Em *i = mylist->Next; i != nullptr; i = i->Next)
        if (i->Data->So_MAHS() == MAHS)
            return count;
        else count++;
}

void Xuat_Tim_Kiem_Thong_Tin_Nguoi_Lon(List_Nguoi_Lon *mylist){
    int count = Tim_Kiem_Thong_Tin_Nguoi_Lon(mylist);

    List_Nguoi_Lon *tmp = mylist;
    for (int i=0; i < count; ++i)
        tmp = tmp->Next;
    tmp->Data->XuatThongTin();
}
void Xuat_Tim_Kiem_Thong_Tin_Tre_Em(List_Tre_Em *mylist){
    int count = Tim_Kiem_Thong_Tin_Tre_Em(mylist);

    List_Tre_Em *tmp = mylist;
    for (int i=0; i < count; ++i)
        tmp = tmp->Next;
    tmp->Data->XuatThongTin();

}

void Cap_Nhat_Thong_Tin_Nguoi_Lon(List_Nguoi_Lon *mylist){
    int count = Tim_Kiem_Thong_Tin_Nguoi_Lon(mylist);

    List_Nguoi_Lon *tmp = mylist;
    for (int i=0; i < count; ++i)
        tmp = tmp->Next;
    tmp->Data->NhapThongTin();
}
void Cap_Nhat_Thong_Tin_Tre_Em(List_Tre_Em *mylist){
    int count = Tim_Kiem_Thong_Tin_Tre_Em(mylist);

    List_Tre_Em *tmp = mylist;
    for (int i=0; i < count; ++i)
        tmp = tmp->Next;
    tmp->Data->NhapThongTin();
}

void Xoa_Thong_Tin_Nguoi_Lon(List_Nguoi_Lon *mylist){
    int count = Tim_Kiem_Thong_Tin_Nguoi_Lon(mylist);

    List_Nguoi_Lon *tmp = mylist;
    List_Nguoi_Lon *index = mylist;

    for (int i=0; i < count-1; ++i){
        tmp = tmp->Next;
        index = index->Next;
    }
    index = index->Next;
    tmp->Next = index->Next;
}
void Xoa_Thong_Tin_Tre_Em(List_Tre_Em *mylist){
    int count = Tim_Kiem_Thong_Tin_Tre_Em(mylist);

    List_Tre_Em *tmp = mylist;
    List_Tre_Em *index = mylist;

    for (int i=0; i < count-1; ++i){
        tmp = tmp->Next;
        index = index->Next;
    }
    index = index->Next;
    tmp->Next = index->Next;
}

class Doc_Gia{
    private:
        List_Nguoi_Lon *dsnl = new List_Nguoi_Lon ();
        List_Tre_Em *dste = new List_Tre_Em ();
    public:
        // CHUC NANG 1a
        void Nhap_Thong_Tin_Doc_Gia_Tre_Em(){
            Them_Doc_Gia_Tre_Em(dste);
        }
        void Nhap_Thong_Tin_Doc_Gia_Nguoi_Lon(){
            Them_Doc_Gia_Nguoi_Lon(dsnl);
        }
        // CHUC NANG 1b
        void Xoa_Thong_Tin_Cho_Nguoi_Lon(){
            Xoa_Thong_Tin_Nguoi_Lon(dsnl);
        }
        void Xoa_Thong_Tin_Cho_Tre_Em(){
            Xoa_Thong_Tin_Tre_Em(dste);
        }
        void Xoa_Toan_Bo_Thong_Tin_Nguoi_Lon(){
            dsnl->Next = nullptr;
        }
        void Xoa_Toan_Bo_Thong_Tin_Tre_Em(){
            dste->Next = nullptr;
        }
        // FIXME: CHUC NANG 2
        void Sap_Xep_Theo_Ten_Nguoi_Lon(){
            for (List_Nguoi_Lon *i = dsnl->Next; i != nullptr; i = i->Next)
                for (List_Nguoi_Lon *j=i->Next; j != nullptr; j = j->Next)
                    if (i->Data->Chu_Cai_Cuoi() > j->Data->Chu_Cai_Cuoi())
                        swap(i->Data, j->Data);
        }
        void Sap_Xep_Theo_Ten_Tre_Em(){
            for (List_Tre_Em *i = dste->Next; i != nullptr; i = i->Next)
                for (List_Tre_Em *j=i->Next; j != nullptr; j = j->Next)
                    if (i->Data->Chu_Cai_Cuoi() > j->Data->Chu_Cai_Cuoi())
                        swap(i->Data, j->Data);
        }
        
        // -----
        // CHUC NANG 3
        void Cap_Nhat_Thong_Tin_Cho_Nguoi_Lon(){
            Cap_Nhat_Thong_Tin_Nguoi_Lon(dsnl);
        }
        void Cap_Nhat_Thong_Tin_Cho_Tre_Em(){
            Cap_Nhat_Thong_Tin_Tre_Em(dste);
        }
        // CHUC NANG 4
        void Tim_Kiem_Thong_Tin_Nguoi_Lon(){
            Xuat_Tim_Kiem_Thong_Tin_Nguoi_Lon(dsnl);
        }
        void Tim_Kiem_Thong_Tin_Tre_Em(){
            Xuat_Tim_Kiem_Thong_Tin_Tre_Em(dste);
        }
        // FIXME: CHUC NANG 5
        void Sync_Thong_Tin_Nguoi_Lon(){
            dsnl->Data->Sao_Luu_Thong_Tin();
        }
        void Sync_Thong_Tin_Tre_Em(){
            dste->Data->Sao_Luu_Thong_Tin();
        }
        // --
        // CHUC NANG 6
        void Xuat_Thong_Tin_Doc_Gia_Tre_Em(){
            Xuat_Thong_Tin_Tre_Em(dste);
        }
        void Xuat_Thong_Tin_Doc_Gia_Nguoi_Lon(){
            Xuat_Thong_Tin_Nguoi_Lon(dsnl);
        }
        int So_Luong_Nguoi_Lon(){
            return Kich_Thuoc_Cua_List_Nguoi_Lon(dsnl);
        }
        int So_Luong_Tre_Em(){
            return Kich_Thuoc_Cua_List_Tre_Em(dste);
        }
        
};

void Menu_Chinh();
void Chuc_Nang_Chinh(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_1();
void Chuc_Nang_1(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_2_Basic();
void Menu_Chuc_Nang_2_Nguoi_Lon(Doc_Gia *mycustomer);
void Menu_Chuc_Nang_2_Tre_Em(Doc_Gia *mycustomer);
void Chuc_Nang_2(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_3();
void Chuc_Nang_3(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_4();
void Chuc_Nang_4(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_5();
void Chuc_Nang_5(Doc_Gia *mycustomer);

void Menu_Chuc_Nang_6();
void Chuc_Nang_6(Doc_Gia *mycustomer);


int main(){
    Doc_Gia *mycustomer = new Doc_Gia ();

    Chuc_Nang_Chinh(mycustomer);
    return 0;
}

void Menu_Chinh(){
    system("cls");
    cout << internal << setw(18)<< "----MENU DOC GIA-----" << endl;
    cout << "1. Them, xoa doc gia"  << endl;
    cout << "2. Sap xep thong tin"  << endl;
    cout << "3. Cap nhat thong tin" << endl;
    cout << "4. Tim kiem thong tin" << endl;
    cout << "5. Sao luu, khoi phuc" << endl;
    cout << "6. Xuat thong tin"     << endl;
    cout << "0. Exit"               << endl;   
    cout << "---------------------" << endl; 
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_Chinh(Doc_Gia *mycustomer){
    do{
        Menu_Chinh();
        // TODO: THIEU CHUC NANG sync (5), sort by sex, age (2)
        switch (choice){
        case 1:
            Chuc_Nang_1(mycustomer);
            break;
        case 2:
            Chuc_Nang_2(mycustomer);
            break;
        case 3:
            Chuc_Nang_3(mycustomer);
            break;
        case 4:
            Chuc_Nang_4(mycustomer);
            break;
        case 5:
            Chuc_Nang_5(mycustomer);
            break;
        case 6:
            Chuc_Nang_6(mycustomer);
            break;
        case 0:
            delete mycustomer;
            return;
        }
    } while (true);
}

void Menu_Chuc_Nang_1(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 1-----" << endl;
    cout << "1. Them doc gia nguoi lon" << endl;
    cout << "2. Them doc gia tre em"    << endl;
    cout << "3. Xoa doc gia nguoi lon"  << endl;
    cout << "4. Xoa doc gia tre em"     << endl;
    cout << "5. Xoa toan bo nguoi lon"  << endl;
    cout << "6. Xoa toan bo tre em"     << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_1(Doc_Gia *mycustomer){
    do{
        Menu_Chuc_Nang_1();
        
        switch (choice){
            case 1:
                mycustomer->Nhap_Thong_Tin_Doc_Gia_Nguoi_Lon();
                break;
            case 2:
                mycustomer->Nhap_Thong_Tin_Doc_Gia_Tre_Em();
                break;
            case 3:
                mycustomer->Xoa_Thong_Tin_Cho_Nguoi_Lon();
                break;
            case 4:
                mycustomer->Xoa_Thong_Tin_Cho_Tre_Em();
                break;
            case 5:
                mycustomer->Xoa_Thong_Tin_Cho_Nguoi_Lon();
                break;
            case 6:
                mycustomer->Xoa_Toan_Bo_Thong_Tin_Tre_Em();
                break;
            default:
                break;
        }
    } while (choice != 0);
}


void Menu_Chuc_Nang_2_Basic(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 2-----" << endl;
    cout << "1. Doi tuong nguoilon"<< endl;
    cout << "2. Doi tuong tre em"  << endl;
    // cout << "3. Doi tuong tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
// TODO: UP LAI CHUC NANG 2
void Menu_Chuc_Nang_2_Tre_Em(Doc_Gia *mycustomer){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 2-----" << endl;
    cout << "1. Sap xep theo ten"<< endl;
    cout << "2. Sap xep theo GT"  << endl;
    cout << "3. Sap xep theo Tuoi"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();

    switch (choice){
    case 1:
        mycustomer->Sap_Xep_Theo_Ten_Tre_Em();
        break;
    
    case 0:
        break;
    }
}
void Menu_Chuc_Nang_2_Nguoi_Lon(Doc_Gia *mycustomer){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 2-----" << endl;
    cout << "1. Sap xep theo ten"<< endl;
    cout << "2. Sap xep theo GT"  << endl;
    cout << "3. Sap xep theo Tuoi"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();

    switch (choice){
    case 1:
        mycustomer->Sap_Xep_Theo_Ten_Nguoi_Lon();
        break;
    // TODO: UPDATE THEM
    case 0:
        break;
    }
}
void Chuc_Nang_2(Doc_Gia *mycustomer){
    do{
        Menu_Chuc_Nang_2_Basic();

        switch (choice){
        case 1:
            Menu_Chuc_Nang_2_Nguoi_Lon(mycustomer);

            break;
        case 2:
            Menu_Chuc_Nang_2_Tre_Em(mycustomer);
            break;
        case 0:
            break;
        }
        
    } while (choice != 0);
    
}
// ----

void Menu_Chuc_Nang_3(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 3-----" << endl;
    cout << "1. Cap nhat nguoilon"<< endl;
    cout << "2. Cap nhat tre em"  << endl;
    // cout << "3. Cap nhat tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_3(Doc_Gia *mycustomer){
    do{
        Menu_Chuc_Nang_3();

        switch (choice){
        case 1:
            mycustomer->Cap_Nhat_Thong_Tin_Cho_Nguoi_Lon();
            break;
        
        case 2:
            mycustomer->Cap_Nhat_Thong_Tin_Cho_Tre_Em();
            break;
        case 0: 
            break;
        }
        if (choice !=0)
            system("pause");
        else
            break;
    } while (choice != 0);
}

void Menu_Chuc_Nang_4(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 4-----" << endl;
    cout << "1. Tim kiem nguoilon"<< endl;
    cout << "2. Tim kiem tre em"  << endl;
    // cout << "3. Tim kiem tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_4(Doc_Gia *mycustomer){
    do{
        Menu_Chuc_Nang_4();

        switch (choice){
        case 1:
            mycustomer->Tim_Kiem_Thong_Tin_Nguoi_Lon();
            break;
        
        case 2:
            mycustomer->Tim_Kiem_Thong_Tin_Tre_Em();
            break;
        case 0: 
            break;
        }
        if (choice !=0)
            system("pause");
        else
            break;
    } while (choice != 0);
}

void Menu_Chuc_Nang_5(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 5-----" << endl;
    cout << "1. Sao luu nguoilon"<< endl;
    cout << "2. Sao luu tre em"  << endl;
    cout << "3. Sao luu tat ca"  << endl;
    cout << "4. Khoi phuc nguoilon"<< endl;
    cout << "5. Khoi phuc tre em"  << endl;
    cout << "6. Khoi phuc tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_5(Doc_Gia *mycustomer){
    do{
    Menu_Chuc_Nang_5();

    switch (choice){
    case 1:
        mycustomer->Sync_Thong_Tin_Nguoi_Lon();
        break;
    case 2:
        mycustomer->Sync_Thong_Tin_Tre_Em();
        break;
    case 3:
        mycustomer->Sync_Thong_Tin_Nguoi_Lon();
        mycustomer->Sync_Thong_Tin_Tre_Em();
        break;
    case 0: 
        break;
    }
    if (choice !=0)
        system("pause");
    else
        break;
    } while (choice != 0);
}
// ---------------------

void Menu_Chuc_Nang_6(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 6-----" << endl;
    cout << "1. Xuat thong tin nguoilon"<< endl;
    cout << "2. Xuat thong tin tre em"  << endl;
    cout << "3. Xuat thong tin tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_6(Doc_Gia *mycustomer){
    do{
        Menu_Chuc_Nang_6();
        system("cls");

        switch (choice){
            case 1:{
                int count = 0;

                cout << right << setw(40)<< "----DS NGUOI LON-----" << endl;
                mycustomer->Xuat_Thong_Tin_Doc_Gia_Nguoi_Lon();
                cout << right << setw(33)<< "So luong " << (count = mycustomer->So_Luong_Nguoi_Lon()) << endl;
                break;
            }
            case 2:{
                int count = 0;

                cout << right << setw(40)<< "----DS TRE EM-----" << endl;
                mycustomer->Xuat_Thong_Tin_Doc_Gia_Tre_Em();
                cout << right << setw(35)<< "So luong " << (count = mycustomer->So_Luong_Tre_Em()) << endl;
                break;
            }
            case 3:{
                int count = 0;

                cout << right << setw(40)<< "----DS NGUOI LON-----" << endl;
                mycustomer->Xuat_Thong_Tin_Doc_Gia_Nguoi_Lon();
                
                cout << "\n";
                cout << right << setw(40)<< "------DS TRE EM------" << endl;
                mycustomer->Xuat_Thong_Tin_Doc_Gia_Tre_Em();

                cout << right << setw(35)<< "So luong " << (count = mycustomer->So_Luong_Nguoi_Lon() + mycustomer->So_Luong_Tre_Em());
                cout << endl;
            }
        }
        cout << endl;
        if (choice !=0)
            system("pause");
        else
            break;
    } while (choice != 0);
}
