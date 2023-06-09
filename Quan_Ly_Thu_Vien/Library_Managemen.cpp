//            string gender = (sex % 2 == 0) ? "Male" : "Female";

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

int choice = 0;
ofstream fileOut;

class Human{
    private:
        string name;
        int sex;
        int age;
        
    protected:
        char getLastInitial(){
           return name[name.rfind(" ")+1];
        }
        
        int getAge(){
            return age;
        }
        
        int getGender(){
            return sex % 2;
        }
        
        string getName(){
            return name;
        }
        
        virtual void inputInformation(){
            cout << "Enter name: ";       getline(cin, name);
            cout << "Enter gender: ";        cin >> sex;
            cout << "Enter age: ";      cin >> age;
            cin.ignore();
        }
        
        virtual void displayInformation(){
            string gender = (sex % 2 == 0) ? "Male" : "Female";

            cout << left << setw(6) << "Name: ";    cout << left << setw(20) << name;
            cout << left << setw(6) << "Gender: ";  cout << left << setw(12) << gender;
            cout << left << setw(4) << "Age: ";     cout << left << setw(8) << age;
        }   
};

class Adult : public Human {
    private:
        string nationalID;
        
    public:
        char getLastInitial(){
           return Human::getLastInitial();
        }
        
        int getAge(){
            return Human::getAge();
        }
        
        int getGender(){
            return Human::getGender();
        }
        
        string getNationalID(){
            return nationalID;
        }
        
        string getName(){
            return Human::getName();
        }
        
        virtual void inputInformation(){
            Human::inputInformation();
            cout << "Enter national ID: ";       getline(cin, nationalID);
        }
        
        virtual void displayInformation(){
            Human::displayInformation();
            cout << left << setw(6) << "National ID: ";   cout <<left << setw(20) << nationalID << endl;
        }
};

class Child : public Human {
    private:
        string studentId;
    public:
        char getLastInitial(){
            return Human::getLastInitial();
        }
        int getAge(){
            return Human::getAge();
        }
        int getGender(){
            return Human::getGender();
        }
        string GetStudentId(){
            return studentId;
        }
        string getName(){
            return Human::getName();
        }
        void InputInformation(){
            Human::inputInformation();
            cout << "Input student ID: ";
            getline(cin, studentId);
        }
        void displayInformation(){
            Human::displayInformation();
            cout << left << setw(6) << "Student ID: ";
            cout << left << setw(20) << studentId << endl;
        }
};


struct Adult_List {
    Adult* data;
    Adult_List* next;
};

struct Child_List {
    Child* data;
    Child_List* next;
};

int Size_Of_Child_List(Child_List *mylist){
    int count = 0;
    for (Child_List *current = mylist->next; current != nullptr; current = current->next)
        count ++;
    return count;
}

int Size_Of_Adult_List(Adult_List *mylist){
    int count = 0;
    for (Adult_List *current = mylist->next; current != nullptr; current = current->next)
        count ++;
    return count;
}

void Initialize_Adult_List_Structure(Adult_List *&myList){
    myList = new Adult_List();
    myList->next = nullptr;
}

void Initialize_Child_List_Structure(Child_List *&myList){
    myList = new Child_List();
    myList->next = nullptr;
}

void Add_Adult_Member(Adult_List *&mylist){
    Adult_List *tmp;
    
    Initialize_Adult_List_Structure(tmp);
    tmp->data = new Adult ();
    tmp->data->inputInformation();

    if (mylist == nullptr)
        mylist = tmp;
    else {
        Adult_List *index = mylist;

        for (int i=0; i<Size_Of_Adult_List(mylist); ++i)
            index = index->next;
        index->next = tmp;
    }
}

void Add_Child_Member(Child_List *&mylist){
    Child_List *tmp;
    
    Initialize_Child_List_Structure(tmp);
    tmp->data = new Child ();
    tmp->data->InputInformation();

    if (mylist == nullptr)
        mylist = tmp;
    else {
        Child_List *index = mylist;
        
        for (int i=0; i<Size_Of_Child_List(mylist); ++i)
            index = index->next;
        index->next = tmp;
    }
}


void Display_Adult_List(Adult_List *mylist){
    for (Adult_List *i = mylist->next; i != nullptr; i = i->next)
        i->data->displayInformation();
}
void Display_Child_List(Child_List *mylist){
    for (Child_List *i = mylist->next; i != nullptr; i = i->next)
        i->data->displayInformation();
}


int searchAdultBygetNationalID(Adult_List *adultList) {
    string inputgetNationalID;
    cout << "Enter getNationalID: "; getline(cin, inputgetNationalID);

    int count = 1;
    for (Adult_List *currentAdult = adultList->next; currentAdult != nullptr; currentAdult = currentAdult->next) {
        if (currentAdult->data->getNationalID() == inputgetNationalID) {
            return count;
        }
        else ++count;
    }
}

int searchChildByGetStudentId(Child_List *childList) {
    string inputGetStudentId;
    cout << "Enter GetStudentId: "; getline(cin, inputGetStudentId);

    int count = 1;
    for (Child_List *currentChild = childList->next; currentChild != nullptr; currentChild = currentChild->next) {
        if (currentChild->data->GetStudentId() == inputGetStudentId) {
            return count;
        }
        else ++count;
    }
}


void displayAdultInfoByNationalID(Adult_List* myList) {
    int count = searchAdultBygetNationalID(myList);
    Adult_List* tmp = myList;
    for (int i=0; i < count; ++i) 
        tmp = tmp->next;
    
    tmp->data->displayInformation();
}

void displayChildInfoByStudentID(Child_List* myList) {
    int count = searchChildByGetStudentId(myList);
    Child_List* tmp = myList;
    for (int i=0; i < count; ++i) 
        tmp = tmp->next;
    
    tmp->data->displayInformation();
}

void updateAdultInfo(Adult_List* myList) {
    int count = searchAdultBygetNationalID(myList);
    Adult_List* tmp = myList;
    for (int i=0; i < count; ++i) {
        tmp = tmp->next;
    }
    tmp->data->inputInformation();
}

void updateChildInfo(Child_List* myList) {
    int count = searchChildByGetStudentId(myList);
    Child_List* tmp = myList;
    for (int i=0; i < count; ++i) {
        tmp = tmp->next;
    }
    tmp->data->InputInformation();
}


void deleteAdultInfoByNationalID(Adult_List *mylist){
    int count = searchAdultBygetNationalID(mylist);

    Adult_List *prev = mylist;
    Adult_List *curr = mylist->next;

    for (int i=1; i < count; ++i){
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = curr->next;
}

void deleteChildInfoByStudentID(Child_List *mylist){
    int count = searchChildByGetStudentId(mylist);

    Child_List *prev = mylist;
    Child_List *curr = mylist->next;

    for (int i=1; i < count; ++i){
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = curr->next;
}


class Member{
    private:
        Adult_List *adult_members_list  = new Adult_List ();
        Child_List *child_members_list  = new Child_List ();
    public:
        // Function to add child member information
        void Add_Child_Member_Info(){
            Add_Child_Member(child_members_list);
        }
        // Function to add adult member information
        void Add_Adult_Member_Info(){
            Add_Adult_Member(adult_members_list);
        }
        // Function to delete adult member information
        void Delete_Adult_Member_Info(){
            deleteAdultInfoByNationalID(adult_members_list);
        }
        // Function to delete child member information
        void Delete_Child_Member_Info(){
            deleteChildInfoByStudentID(child_members_list);
        }
        // Function to delete all adult member information
        void Delete_All_Adult_Member_Info(){
            adult_members_list->next = nullptr;
        }

        // Function to delete all child member information
        void Delete_All_Child_Member_Info(){
            child_members_list->next = nullptr;
        }
        // TODO: In such cases, more efficient sorting algorithms 
        // like merge sort and quick sort should be used.
        void Sort_Adult_Members_By_Last_Name(){
            for (Adult_List *i = adult_members_list->next; i != nullptr; i = i->next){
                int min = i->data->getLastInitial();
                
                for (Adult_List *j= i->next; j != nullptr; j = j->next)
                    if (min > j->data->getLastInitial())
                        swap(i->data, j->data);
            }
        }
        void Sort_Child_Members_By_Last_Name(){
            for (Child_List *i = child_members_list->next; i != nullptr; i = i->next){
                int min = i->data->getLastInitial();
                
                for (Child_List *j= i->next; j != nullptr; j = j->next)
                    if (min > j->data->getLastInitial())
                        swap(i->data, j->data);
            }
        }
        void Sort_Adults_By_Gender() {
            for (Adult_List* i = adult_members_list->next; i != nullptr; i = i->next) {
                int min = i->data->getGender();
                for (Adult_List* j = i->next; j != nullptr; j = j->next) {
                    if (min < j->data->getGender())
                        swap(i->data, j->data);
                }
            }
        }

        void Sort_Children_By_Gender() {
            for (Child_List* i = child_members_list->next; i != nullptr; i = i->next) {
                int min = i->data->getGender();
                for (Child_List* j = i->next; j != nullptr; j = j->next) {
                    if (min < j->data->getGender())
                        swap(i->data, j->data);
                }
            }
        }

        void Sort_Adults_By_Age() {
            for (Adult_List* i = adult_members_list->next; i != nullptr; i = i->next) {
                int min = i->data->getAge();
                for (Adult_List* j = i->next; j != nullptr; j = j->next) {
                    if (min > j->data->getAge())
                        swap(i->data, j->data);
                }
            }
        }

        void Sort_Children_By_Age() {
            for (Child_List* i = child_members_list->next; i != nullptr; i = i->next) {
                int min = i->data->getAge();
                for (Child_List* j = i->next; j != nullptr; j = j->next) {
                    if (min > j->data->getAge())
                        swap(i->data, j->data);
                }
            }
        }

        // ----

        // CHUC NANG 3
        void Update_Adult_Information() { 
            updateAdultInfo(adult_members_list); 
        }
        void Update_Child_Information() {
            updateChildInfo(child_members_list);
        }
        // CHUC NANG 4
        void Search_Adult_Information_By_NationalID() {
            displayAdultInfoByNationalID(adult_members_list);
        }
        void Search_Child_Information_By_StudentCode(){
            displayChildInfoByStudentID(child_members_list);
        }
        void SearchAdultByGender() {
            int gender;
            cout << "Enter gender: ";
            cin >> gender;

            for(Adult_List *i = adult_members_list->next; i != nullptr; i = i->next) {
                if(i->data->getGender() == gender % 2) {
                    i->data->displayInformation();
                }
            }
        }

        void SearchChildByGender() {
            int gender;
            cout << "Enter gender: ";
            cin >> gender;

            for(Child_List *i = child_members_list->next; i != nullptr; i = i->next) {
                if(i->data->getGender() == gender % 2) {
                    i->data->displayInformation();
                }
            }
        }

        void SearchAdultByName() {
            string name;
            cout << "Enter name: ";
            getline(cin, name);

            for(Adult_List *i = adult_members_list->next; i != nullptr; i = i->next) {
                if(i->data->getName() == name) {
                    i->data->displayInformation();
                }
            }
        }

        void SearchChildByName() {
            string name;
            cout << "Enter name: ";
            getline(cin, name);

            for(Child_List *i = child_members_list->next; i != nullptr; i = i->next) {
                if(i->data->getName() == name) {
                    i->data->displayInformation();
                }
            }
        }

        // CHUC NANG 5
        void Back_Up_Thong_Tin_Nguoi_Lon(){
            ofstream fileOut;
            fileOut.open("adult_memberslist.txt", ios_base::trunc);

            for (Adult_List *i = adult_members_list->next; i != nullptr; i = i->next){
                fileOut << i->data->getName()   << ", ";
                fileOut << i->data->getGender()    << ", ";
                fileOut << i->data->getAge()  << ", ";
                fileOut << i->data->getNationalID()  << ", " << endl;
            }
            fileOut.close();
        }
        void Back_Up_Thong_Tin_Tre_Em(){
            ofstream fileOut;
            fileOut.open("child_memberslist.txt", ios_base::trunc);

            for (Child_List *i = child_members_list->next; i != nullptr; i = i->next){
                fileOut << left << setw(25) << i->data->getName()   << ",";
                fileOut << left << setw(3)  << i->data->getGender()    << ", ";
                fileOut << left << setw(5)  << i->data->getAge()  << ", ";
                fileOut << left << setw(20) << i->data->GetStudentId()  << ", " << endl;
            }
            fileOut.close();
        }

        // CHUC NANG 6
        void PrintChildMemberInfo(){
            Display_Child_List(child_members_list);
        }

        void PrintAdultMemberInfo(){
            Display_Adult_List(adult_members_list);
        }

        int NumberOfAdults(){
            return Size_Of_Adult_List(adult_members_list);
        }

        int NumberOfChildren(){
            return Size_Of_Child_List(child_members_list);
        }

        
};

void Menu_Chinh();
void Chuc_Nang_Chinh(Member *mycustomer);

void Menu_Chuc_Nang_1();
void Chuc_Nang_1(Member *mycustomer);

void Menu_Chuc_Nang_2_Basic();
void Menu_Chuc_Nang_2_Nguoi_Lon(Member *mycustomer);
void Menu_Chuc_Nang_2_Tre_Em(Member *mycustomer);
void Chuc_Nang_2(Member *mycustomer);

void Menu_Chuc_Nang_3();
void Chuc_Nang_3(Member *mycustomer);

void Menu_Chuc_Nang_4();
void Chuc_Nang_4(Member *mycustomer);

void Menu_Chuc_Nang_5_Basic();
void Chuc_Nang_5_Khoi_Phuc(Member *mycustomer);
void Chuc_Nang_5_Sao_Luu(Member *mycustomer);
void Chuc_Nang_5(Member *mycustomer);

void Menu_Chuc_Nang_6();
void Chuc_Nang_6(Member *mycustomer);


int main(){
    Member *mycustomer = new Member ();

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
void Chuc_Nang_Chinh(Member *mycustomer){
    do{
        Menu_Chinh();
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
void Chuc_Nang_1(Member *mycustomer){
    do{
        Menu_Chuc_Nang_1();
        
        switch (choice){
            case 1:
                mycustomer->Add_Adult_Member_Info();
                break;
            case 2:
                mycustomer->Add_Child_Member_Info();
                break;
            case 3:
                mycustomer->Delete_Adult_Member_Info();
                break;
            case 4:
                mycustomer->Delete_Child_Member_Info();
                break;
            case 5:
                mycustomer->Delete_All_Adult_Member_Info();
                break;
            case 6:
                mycustomer->Delete_All_Child_Member_Info();
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
void Menu_Chuc_Nang_2_Tre_Em(Member *mycustomer){
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
        mycustomer->Sort_Child_Members_By_Last_Name();
        break;
    case 2:
        mycustomer->Sort_Children_By_Gender();
        break;
    case 3:
        mycustomer->Sort_Adults_By_Age();
        break;
    case 0:
        break;
    }
}
void Menu_Chuc_Nang_2_Nguoi_Lon(Member *mycustomer){
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
        mycustomer->Sort_Adult_Members_By_Last_Name();
        break;
    case 2:
        mycustomer->Sort_Adults_By_Gender();
        break;
    case 3:
        mycustomer->Sort_Adults_By_Age();
        break;
    case 0:
        break;
    }
}
void Chuc_Nang_2(Member *mycustomer){
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
void Chuc_Nang_3(Member *mycustomer){
    do{
        Menu_Chuc_Nang_3();

        switch (choice){
        case 1:
            mycustomer->Update_Adult_Information();
            break;
        
        case 2:
            mycustomer->Update_Child_Information();
            break;
        case 0: 
            break;
        }
    } while (choice != 0);
}

void Menu_Chuc_Nang_4(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 4-----" << endl;
    cout << "1. Tim kiem nguoilon   (ID)"<< endl;
    cout << "2. Tim kiem nguoilon   (GT)"  << endl;
    cout << "3. Tim kiem nguoilon   (Ten)" << endl;
    cout << "4. Tim kiem tre em     (ID)"<< endl;
    cout << "5. Tim kiem tre em     (GT)"  << endl;
    cout << "6. Tim kiem tre em     (Ten)" << endl;
    // cout << "3. Tim kiem tat ca"  << endl;
    cout << "0. Exit"                      << endl;   
    cout << "---------------------"        << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_4(Member *mycustomer){
    do{
        Menu_Chuc_Nang_4();

        switch (choice){
        case 1:
            mycustomer->Search_Adult_Information_By_NationalID();
            break;
        case 2:
            mycustomer->SearchAdultByGender();
            break;
        case 3:
            mycustomer->SearchAdultByName();
            break;
        case 4:
            mycustomer->Search_Child_Information_By_StudentCode();
            break;
        case 5:
            mycustomer->SearchChildByGender();
            break;
        case 6:
            mycustomer->SearchChildByName();
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


void Menu_Chuc_Nang_5_Basic(){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 5-----" << endl;
    cout << "1. Sao luu thong tin"      << endl;
    cout << "2. Khoi phuc thong tin (DAG)"  << endl;
    // cout << "3. Doi tuong tat ca"  << endl;
    cout << "0. Exit"                   << endl;   
    cout << "---------------------"     << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
}
void Chuc_Nang_5_Sao_Luu(Member *mycustomer){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 5-----" << endl;
    cout << "1. Sao luu nguoilon"   << endl;
    cout << "2. Sao luu tre em"     << endl;
    cout << "3. Sao luu tat ca"     << endl;
    cout << "0. Exit"               << endl;   
    cout << "------BAO TRI-------"  << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
    
    switch (choice){
    case 1:
        mycustomer->Back_Up_Thong_Tin_Nguoi_Lon();
        break;
    case 2:
        mycustomer->Back_Up_Thong_Tin_Tre_Em();
        break;
    case 3:
        mycustomer->Back_Up_Thong_Tin_Nguoi_Lon();
        mycustomer->Back_Up_Thong_Tin_Tre_Em();
        break;
    case 0:
        break;
    }
}
void Chuc_Nang_5_Khoi_Phuc(Member *mycustomer){
    system("cls");
    cout << internal << setw(18)<< "----CHUC NANG 5-----" << endl;
    cout << "1. Khoi phuc nguoilon"<< endl;
    cout << "2. Khoi phuc tre em"  << endl;
    cout << "3. Khoi phuc tat ca"  << endl;
    cout << "0. Exit"              << endl;   
    cout << "------BAO TRI-------" << endl;
    cout << "Lua chon: "; cin>> choice;
    cin.ignore();
    // TODO: UPDATE Chuc nang backup & sync
}
void Chuc_Nang_5(Member *mycustomer){
    do{
    Menu_Chuc_Nang_5_Basic();

        switch (choice){
        case 1:
            Chuc_Nang_5_Sao_Luu(mycustomer);
            break;
        case 2:
            Chuc_Nang_5_Khoi_Phuc(mycustomer);
            break;
        case 0: 
            break;
        }
    } while (choice != 0);
}


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
void Chuc_Nang_6(Member *mycustomer){
    do{
        Menu_Chuc_Nang_6();
        system("cls");

        switch (choice){
            case 1:{
                int count = 0;

                cout << right << setw(40)<< "----DS NGUOI LON-----" << endl;
                mycustomer->PrintAdultMemberInfo();
                cout << right << setw(33)<< "So luong " << (count = mycustomer->NumberOfAdults()) << endl;
                break;
            }
            case 2:{
                int count = 0;

                cout << right << setw(40)<< "----DS TRE EM-----" << endl;
                mycustomer->PrintChildMemberInfo();
                cout << right << setw(35)<< "So luong " << (count = mycustomer->NumberOfChildren()) << endl;
                break;
            }
            case 3:{
                int count = 0;

                cout << right << setw(40)<< "----DS NGUOI LON-----" << endl;
                mycustomer->PrintAdultMemberInfo();
                
                cout << "\n";
                cout << right << setw(40)<< "------DS TRE EM------" << endl;
                mycustomer->PrintChildMemberInfo();

                cout << endl;
                cout << right << setw(34)<< "So luong ";
                cout << (count = mycustomer->NumberOfAdults() + mycustomer->NumberOfChildren());
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
