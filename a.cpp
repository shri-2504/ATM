#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/* Mini project - ATM
  ->check balance
  ->cash withdraw
  ->user details
  ->update mobile number
*/
class atm {                        //class atm
    private:                          //private member variables
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;


    public:                            //public member function
    // setdata function is setting the data into private member variables
    void setdata(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a){
        account_No=account_No_a;       //assigning the formal arguments to the private member var's
        name=name_a;
        PIN=PIN_a;
        balance=balance_a;
        mobile_No=mobile_No_a;
    }
    //getAccountNo function is returning the user's account no.
    long int getAccountNo(){
        return account_No;
    }
    //getName function is returning the user's Name
    string getName(){
        return name;
    }
    //getPIN funtion is returning the user's PIN
    int getPIN(){
        return PIN;
    }
    //getBalance is returning the user's Bank balance
    double getBalance(){
        return balance;
    }
    //getMobileNo is returning the user's Mobile No.
    string getMobileNo(){
        return mobile_No;
    }
    //setmobile function is updating the useer mobile no.
    void setMobile(string mob_prev,string mob_new){
        if(mob_prev==mobile_No){      //it will check old mobile no
            mobile_No=mob_new;        //and update with new,if old matches
            cout<<endl<<"Successfully Updated Mobile no.";
            _getch();    //getch is to hold the screen user press any key
        }
        else{
            cout<<endl<<"Incorrect  !!! Old Mobile no";
            _getch();   //getch is to hold the screen untill user press any key
        }
    } 
    //cashWithDraw function is used to withdraw money from ATM
    void cashWithDraw(int amount_a){
        if((amount_a >0) && (amount_a <balance))      //check entered amount validity
        {
            balance-=amount_a;     
            cout<<endl<<"Please Collect Your Cash";
            cout<< endl<< "Available Balance :"<<balance;
            _getch();
        }
        else{
            cout<<endl<<"Invalid Input Or Insufficient Balance";
            _getch();
        }
    }
};

int main(){
    int choice=0,enterPIN;     //enterPIN and enterAccountNo. --->user authentication
    long int enterAccountNo;
    system("cls");      //used to clean the sccreen
    //created user(object)
    atm user1;
    //set user details (into object)    (setting default data)
    user1.setdata(1234567,"shubham",1111,50000.00,"9525580908");

    do {
        system("cls");
        cout<<endl<<"****Welcome to ATM"<<endl;
        cout<<"Enter Your Account No.";                 //Asking user to enter account no.
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN";      //asking user to enter PIN
        cin>>enterPIN;
        //check whether enter values matches with usser details 
        if((enterAccountNo==user1.getAccountNo()) && (enterPIN==user1.getPIN())){
            do {
                int amount=0;
                string oldMobileNO,newMobileNo;
                system("cls");
                //user inteface
                cout<<endl<<"****welcome to ATM"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User  Details";
                cout<<endl<<"4. Update Mobile No.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;         //taking user choice
                    switch(choice)
                        {
                                case 1:                      //if user presses 1
                                cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                                                                    // getBalance is....printing the users bank balance


                                 _getch();
                                    break;


                                case 2:                          //if user presses 2
                                    cout<<endl<<"Enter the amount :";
                                    cin>>amount;
                                    user1.cashWithDraw(amount);    //calling cashwithdrw function
                                    _getch();                         //passing the withdraw amount
                                break;

                                case 3:                     //if userpresses 3
                                    cout<<endl<<"*** User Details are:-";
                                    cout<<endl<<"-> Account no"<<user1.getAccountNo();
                                    cout<<endl<<"-> Name" <<user1.getName();
                                    cout<<endl<<"-> Balance "<<user1.getBalance();
                                    cout<<endl<<"->Mobile No."<<user1.getMobileNo();
                                                                                    //getting and printing user details
                                    _getch();
                                break;

                                case 4:
                                    cout<<endl<<"Enter Old Mobile No.";
                                    cin>>oldMobileNO;
                                    cout<<endl<<"Enter New Mobile No.";
                                    cin>>newMobileNo;

                                    user1.setMobile(oldMobileNO,newMobileNo);     //now set new mobile no.
                                    _getch();
                                break;

                                case 5:               //if user presses 5
                                    exit(0);
                                break;         //exit application

                                default: cout<<endl<<"Enter valid Data !!!"; break;
                        }
            } while(1);    //MENU //condition will always TRUE and lopp is capable of ruuning Infinite times.   
        
        }

        else {
            cout<<endl<<"User details are Invalid!";
            _getch();
        }
        
    } while(1);

    return 0;
}