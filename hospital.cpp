#include<iostream>
#include<string.h>

using namespace std;

class person
{
    private:
        char name[30], gender[7], city[20], state[20], bgroup[4];
        int age, phone, id;
    public:
        void pinfo()
        {
            cout<<"\tEnter Name :";
            cin>>name;
            cout<<"\tEnter Gender :";
            cin>>gender;
            cout<<"\tEnter Age :";
            cin>>age;
            cout<<"\tEnter Address (city and state):";
            cin>>city>>state;
            cout<<"\tEnter Blood group:";
            cin>>bgroup;
        }
        void displayinfo()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Gender: "<<gender<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Address: "<<city<<", "<<state<<endl;
            cout<<"Blood Group:"<<bgroup<<endl;
        }
};

class patient : public person
{
    private:
        int regno, bill, total;
        char occ[30], date_admit[20], date_discharge[20], medicine[20];
    public:
        void getdata(); //function to accept data from user
        void showdata(); //function to show data on screen
        void pbill();
        int pmenu();
};

void patient :: pbill() //using scope resolution operator to define function outside class
{
    cout << "\n********************************************************************************";
    cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
    cout << "*******************************************************************************";
    cout << "\nHospital Room Charges                      :\t  1000";
    cout << "\nHospital Care Charges                      :\t  50";
    cout << "\nHospital Maintaince Charges                :\t  50";
    cout << "\nPatient Individual  Charges                :\t " << bill;
    total = 1000 + 50 + 50 + bill;
    cout << "\nTotal Fee Charge                           :\t"  << total<<"\n";
    cout << "********************************************************************************"<<endl;
}

void patient::getdata()
{
    cout<<"---------------------------------------------------------------------------------"<<endl;
    pinfo();
    cout<<"\nEnter The registration number of the patient: ";
    cin>>regno;
    cout<<"\nEnter The occupation of the patient: ";
    cin>>occ;
    cout<<"\nEnter The bill of the patient:";
    cin>>bill;
    cout<<"\nEnter The date admitted(dd/mm/yyyy):";
    cin>>date_admit;
    cout<<"\nEnter The date discharged(dd/mm/yyyy):";
    cin>>date_discharge;
    cout<<"Enter prescribed medicine:";
    cin>>medicine;
    pbill();
}

void patient::showdata()
{
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"\nRegistration number of patient: "<<regno<<"\n";
    displayinfo();
    cout<<"\nOccupation : "<<occ;
    cout<<"\nAdmit date : "<<date_admit;
    cout<<"\nDischarhge date :"<<date_discharge;
    cout<<"\nBill :"<<total;
    cout<<"\nPrescribed Medicine: "<<medicine<<endl;
}

int patient::pmenu()
{
    char b;
    do
    {
        cout<<"********************************************************************************"<<endl;
        cout<<"\n--------------------------------------------------------------------------------"<<endl;
        cout<<"                                     PATIENT MENU                                "<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"\t1. Insert Patient Details"<<endl;
        cout<<"\t2. Show Patient Details"<<endl;
        cout<<"\t3. Exit Patient Menu"<<endl;
        cout<<"\n\n\tPlease Select Your Option (1-3): ";
        cin>>b;
        cout<< "********************************************************************************"<<endl;
        switch(b)
        {
            case '1': 
                getdata();
                break;
            case '2':
                showdata();
                break;
            case '3':
                return 0;
                break;
            default:
                cout<<"\b";
        }
     } 
    while (b!='4');
}

class Staff:public person
{
        
    private:
        int salary;
        char time_from[30],time_to[30];

    public:
        void staff_info()
        {
            pinfo();
            cout<<"Enter salary:";
            cin>>salary;
            cout<<"Enter Duty time:"<<endl; 
            cout<<"From:";
            cin>>time_from;
            cout<<"To:";
            cin>>time_to;
        }

        void show_staff()
        {
            cout<<"\nSalary: "<<salary;
            cout<<"\nDuty Time: "<<time_from<<"--"<<time_to<<endl;
            displayinfo();
        }
};

class doctor : public Staff
{
    private:
        int docid;
        char special[30];
    public:
        void docdata()
        {
            cout<<"---------------------------------------------------------------------------------"<<endl;
            staff_info();
            cout<<"Enter Doctor ID:";
            cin>>docid;
            cout<<"Enter Speciality :";
            cin>>special;
        }
         void displaydocinfo()
        {
            cout<<"---------------------------------------------------------------------------------"<<endl;
            cout<<"Doctor ID :"<<docid;
            show_staff();
            cout<<"\n"<<"Doctor Speciality :"<<special;
            cout<<endl;
        }
        int docmenu()
        {
            char a;
            do
            {
                cout<< "********************************************************************************"<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"                                     DOCTOR MENU                                 "<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Insert Doctor Details"<<endl;
                cout<<"\t2. Show Doctor Details"<<endl;
                cout<<"\t3. Exit Doctor Menu"<<endl;
                cout<<"\n\n\tPlease Select Your Option (1-3): ";
                cin>>a;
                cout<< "********************************************************************************"<<endl;
                switch(a)
                {
                    case '1': 
                        docdata();
                        break;
                    case '2':
                        displaydocinfo();
                        break;
                    case '3':
                        return 0;
                        break;
                    default:
                        cout<<"\b";
                }
            } 
            while (a!='4');
        }
};

class nurse : public Staff
{
    private:
        int nid;
        int room;
    public:
        void ndata()
        {
            cout<<"---------------------------------------------------------------------------------"<<endl;
            staff_info();
            cout<<"Enter Nurse ID:";
            cin>>nid;
            cout<<"Enter the room number incharged :";
            cin>>room;
        }
         void displayninfo()
        {
            cout<<"---------------------------------------------------------------------------------"<<endl;
            cout<<"Nurse ID :"<<nid;
            show_staff();
            cout<<"\n"<<"The Room incharged to nurse :"<<room;
            cout<<endl;
        }
        int nmenu()
        {
            char nu;
            do
            {
                cout<< "********************************************************************************"<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"                                     NURSE MENU                                  "<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Insert Nurse Details"<<endl;
                cout<<"\t2. Show Nurse Details"<<endl;
                cout<<"\t3. Exit Nurse Menu"<<endl;
                cout<<"\n\n\tPlease Select Your Option (1-3): ";
                cin>>nu;
                cout<< "********************************************************************************"<<endl;
                switch(nu)
                {
                    case '1': 
                        ndata();
                        break;
                    case '2':
                        displayninfo();
                        break;
                    case '3':
                        return 0;
                        break;
                    default:
                        cout<<"\b";
                }
            } 
            while (nu!='4');
        }
};

class admin
{
    private:
        doctor d;
        patient p;
        nurse n;
    public:
        int staffmenu()
        {
            char ch;
            do
            {
                cout<< "********************************************************************************"<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"                                 STAFF MENU                                      "<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Doctor"<<endl;
                cout<<"\t2. Nurse"<<endl;
                cout<<"\t3. Patient"<<endl;
                cout<<"\t4. Exit"<<endl;
                cout<<"\n\n\tPlease Select Your Option (1-3): ";
                cin>>ch;
                cout<< "********************************************************************************"<<endl;
                switch(ch)
                {
                    case '1': 
                        d.docmenu();
                        break;
                    case '2':
                        n.nmenu();
                        break;
                    case '3':
                        p.pmenu();
                        break;
                    case '4':
                        cout<<"Thank You!!"<<endl;
                        break;
                        return 0;
                    default:
                        cout<<"\b";
                }
            } 
            while (ch!='5');
        }
};

int main()
{
    admin ad;
    char pass[15];
    cout<<"********************************************************************************"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"|                       HOSPITAL MANAGEMENT SYSTEM                              |"<<endl;
    cout<<"|                         MADE BY - DHRUVI SUTHAR                               |"<<endl;
    cout<<"|                                21162101005                                    |"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"\t\tTo enter ADMIN please enter password:";
    cin>>pass;
    cout<< "********************************************************************************"<<endl;
    if(strcmp(pass,"admin")==0)
    {
        ad.staffmenu();
    }
    else
    {
        cout<<"WRONG PASSWORD!!"<<endl;
    }
    return 0;
}