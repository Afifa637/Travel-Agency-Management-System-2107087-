//Roll: 2107087
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int age;
    int customerID;
    string email;
    bool givenFlight;
    int flightNum;
public:
    Customer()
    {
        age=0;
        customerID=0;
        givenFlight = false;
    }
    Customer(string name, int age,int custID,string email)
    {
        this->name= name;
        this->age=age;
        customerID= custID;
        this->email= email;
    }
    int getid()
    {
        return customerID;
    }
    string getname()
    {
        return name;
    }
    void displayInfo()
    {
        cout << "   Customer Name: " << name << endl;
        cout << "   Customer Age: " << age << endl;
        cout << "   Customer ID: " << customerID<<endl;
        cout << "   Email: " << email << endl;
    }
    friend class TravelAgency;
};

class Flight
{
private:
    string origin;
    string destination;
    bool Available;
    int seats,cost;

public:
    Flight()
    {
        Available = false;
        seats=0;
        cost = 0;
    }
    Flight(string origin, string destination, int seats, int cost)
    {
        this->origin=origin;
        this->destination=destination;
        Available=true;
        this -> cost = cost;
        this -> Available = true;
    }

    void displayInfo()
    {
        cout << "Origin: " << origin << endl;
        cout << "Destination: " << destination << endl;
        cout << "cost " << cost << "\n";
    }
    bool checkAvailability()
    {
        return Available;
    }
    int getcost()
    {
        return cost;
    }
    friend class TravelAgency;
};

class Uber
{
private:
    int UberType;
    double Kilometers, Ubercost;
    bool Available;

public:
    Uber()
    {
        Available = false;
        Ubercost = 0.0;
    }
    Uber(int ub, int kl, int ubc)
    {
        UberType = ub;
        Kilometers = kl;
        Ubercost = ubc;
        Available = true;
    }
    float getubercost()
    {
        return Ubercost;
    }
    bool checkAvailability()
    {
        return Available;
    }
};

class Bookings
{
private:
    int choiceHotel;
    int package;
    int hotelcost;
    bool Available;
public:
    Bookings()
    {
        Available = false;
        hotelcost = 0;
    }
    Bookings(int ch, int p, int cs)
    {
        choiceHotel = ch;
        package = p;
        hotelcost = cs;
        Available = true;
    }
    void Hotels()
    {
        string hotelNo[]= {"The Grand Palace", "The Royal Hotel", "Sky City Hotel"};
        for(int i=0; i<3; i++)
        {
            cout<<"   "<<i+1<<". "<<hotelNo[i]<<endl;
        }
    }
    int gethotelcost()
    {
        return hotelcost;
    }
    bool checkAvailability()
    {
        return Available;
    }
};

class TravelAgency
{
    Customer customers[100];
    Flight flights[100];
    Uber ubers[100];
    Bookings hotels[100];
    int numCustomers;
    int numFlights;

public:
    TravelAgency() {
        numCustomers = 0;
        numFlights = 0;
    }
    void addCustomer()
    {
        if (numCustomers >= 100)
        {
            cout<<"Sorry! No services available right now.\n";
            return;
        }
        string name, email;
        int id,age;
        cout<<"\n   Enter name: ";
        cin >> customers[numCustomers].name;
        cout<<"\n   Enter customer age: ";
        cin >> customers[numCustomers].age;
        cout<<"\n   Enter customer ID: ";
        cin >> customers[numCustomers].customerID;
        cout<<"\n   Enter email: ";
        cin >> customers[numCustomers].email;
        numCustomers++;
    }

    void addFlight()
    {
        int id,choice;
        double flightcost=0.00;
        cout<<"\n   Enter your ID: ";
        cin >> id;
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "User not found\n";
            return;
        }
        cout<<"\n   Enter Origin Airport: ";
        cin >> flights[numFlights].origin;
        cout<<"\n   Enter Destination Airport: ";
        cin>> flights[numFlights].destination;
        cout << "\n   Available flights : \n";
        cout << "   1. BD-456 08-08-2023 12:30PM \n";
        cout << "   2. BD-756 14-08-2023 09:30AM \n";
        cout << "   3. BD-586 09-08-2023 00:30AM \n";
        cout << "Enter which ticket you want to book: ";
        cin >> choice;
        if(choice==1)
        {
            cout<<"Your ticket BD-456 08-08-2023 12:30PM has been successfully booked\n";
        }
        else if (choice == 2)
        {
            cout << "Your ticket BD-756 14-08-2023 09:30AM has been successfully booked.\n";
        }
        else
        {
            cout << "Your ticket BD-586 09-08-2023 00:30AM has been successfully booked.\n";
        }
        cout<<"\n   Enter Number of seats you want to book: ";
        cin>>flights[numFlights].seats;
        flightcost= 20000.00*flights[numFlights].seats;
        flights[numFlights].cost = flightcost;
        cout<<"  Flight cost is: BDT."<<flightcost<<"\n";
        customers[pos].givenFlight = true;
        customers[pos].flightNum = numFlights;
        numFlights++;
    }

    void addUber()
    {
        int UberType, id;
        cout<<"   Enter your ID: ";
        cin >> id;
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "User not found\n";
            return;
        }
        double Kilometers, Ubercost;
        cout<<"We collaborated with fastest and safest Uber throughout the country!"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"  1. Rent a standard uber- 1 KM at BDT.200tk"<<endl;
        cout<<"  2. Rent a luxury uber- 1 KM at BDT.350tk"<<endl;
        cout<<"  Enter your Uber type to calculate the total cost: "<<endl;
        cin>>UberType;
        cout<<"  Enter how many kilometers you want to travel: "<<endl;
        cin>>Kilometers;
        if(UberType==1)
        {
            Ubercost= Kilometers*200;
            cout<<"  Uber cost is: BDT."<<Ubercost<<" tk"<<endl;
            cout<<"  You have successfully hired an Uber!"<<endl;
            cout<<"  Take receipt from main menu.\n";
        }
        else if(UberType==2)
        {
            Ubercost= Kilometers*350;
            cout<<"  Uber cost is: BDT."<<Ubercost<<" tk"<<endl;
            cout<<"  You have successfully hired an Uber!"<<endl;
            cout<<"  Take receipt from main menu.\n";
        }

        else cout<<"  Invalid Uber Type!"<<endl;
        Uber ub(UberType, Kilometers, Ubercost);
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                ubers[i]=ub;
            }
        }
    }
    void addHotel()
    {
        int id;
        cout<<"   Enter your ID: ";
        cin >> id;
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "User not found\n";
            return;
        }
        cout<<"\nOur available Hotels are:\n";
        string hotelNo[]= {"The Grand Palace", "The Royal Hotel", "Sky City Hotel"};
        for(int i=0; i<3; i++)
        {
            cout<<"   "<<i+1<<". "<<hotelNo[i]<<endl;
        }
        int ret, choiceHotel, package, hotelcost;
        cout<<"   Enter which number of the hotel you want to book: ";
        cin>>choiceHotel;
        if( choiceHotel==1)
        {
            cout<<"\n---------------Welcome to THE GRAND PALACE!--------------"<<endl;
            cout<<"   Packages offered by The Grand Palace: "<<endl;
            cout<<" \n   1. Standard pack: \n  All basic facilities you need just for BDT.5000.00tk"<<endl;
            cout<<"   2. Premium pack: \n Enjoy the premium facilities just for BDT.10000.00tk"<<endl;
            cout<<"--------------------------------------------------------------------\n";
            cout<<"   Enter package number you want to book: \n";
            cin>>package;
            if (package==1)
            {
                hotelcost= 5000;
                cout<<"  \nYou have successfully booked standard pack!\n";
            }
            else if ( package==2)
            {
                hotelcost=10000;
                cout<<"  \nYou have successfully booked premium pack!\n";
            }
        }
        else if( choiceHotel==2)
        {
            cout<<"\n-------------------Welcome to THE ROYAL HOTEL!---------------------"<<endl;
            cout<<"   Packages offered by The Royal Hotel: "<<endl;
            cout<<" \n   1. Standard pack: \n  All basic facilities you need just for BDT.5000.00tk"<<endl;
            cout<<"   2. Premium pack: \n Enjoy the premium facilities just for BDT.10000.00tk"<<endl;
            cout<<"--------------------------------------------------------------------\n";
            cout<<"   Enter package number you want to book: ";
            cin>>package;
            if (package==1)
            {
                hotelcost= 5000;
                cout<<"   \nYou have successfully booked standard pack!\n";
            }
            else if ( package==2)
            {
                hotelcost=10000;
                cout<<"   \nYou have successfully booked premium pack!\n";
            }
        }
        else if( choiceHotel==3)
        {
            cout<<"\n----------------------Welcome to SKY CITY HOTEL!--------------------"<<endl;
            cout<<"   Packages offered by Sky City Hotel: "<<endl;
            cout<<" \n   1. Standard pack: \n  All basic facilities you need just for BDT.5000.00tk"<<endl;
            cout<<"   2. Premium pack: \n Enjoy the premium facilities just for BDT.10000.00tk"<<endl;
            cout<<"--------------------------------------------------------------------\n";
            cout<<"   Enter package number you want to book: ";
            cin>>package;
            if (package==1)
            {
                hotelcost= 5000;
                cout<<"  \nYou have successfully booked standard pack!\n";
            }
            else if ( package==2)
            {
                hotelcost=10000;
                cout<<"  \nYou have successfully booked premium pack!\n";
            }
        }
        else cout<<"Invalid input!"<<endl;
        Bookings hotel(choiceHotel, package, hotelcost);
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                hotels[i]=hotel;
            }
        }
    }

    string getcustomername(int pos)
    {
        return customers[pos].getname();
    }
    int getcustomerid(int pos)
    {
        return customers[pos].getid();
    }
    void showFlightInformation(int id)
    {
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "User not found\n";
            return;
        }
        if(customers[pos].givenFlight)
        {
            cout << "Customer ID: " << id << "\n";
            flights[customers[pos].flightNum].displayInfo();
        }
        else
        {
            cout << "   You haven't booked any flight till now.\n";
        }
    }
    int getnumCustomers()
    {
        return numCustomers;
    }
    void cutomerinfo(int id)
    {
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "User not found\n ";
            return;
        }
        customers[pos].displayInfo();
    }

    void showTotalCost(int id)
    {
        int pos = -1;
        for(int i = 0; i < numCustomers; i++)
        {
            if(customers[i].getid() == id)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
        {
            cout << "Invalid ID \n";
            return;
        }
        cout<<"\n";
        cout << "--------------------RECEIPT-------------------- \n";
        int sum = 0;
         if(customers[pos].givenFlight)
        {
            cout << "   *Flight Cost =             " << flights[customers[pos].flightNum].getcost() << "\n";
            sum += flights[customers[pos].flightNum].getcost();
        }
        if(ubers[pos].checkAvailability())
        {
            cout << "   *Uber Cost =               " << ubers[pos].getubercost() << "\n";
            sum += ubers[pos].getubercost();
        }
        if(hotels[pos].checkAvailability())
        {
            cout << "   *Hotel Cost =              " << hotels[pos].gethotelcost() << "\n";
        }
        cout<<"------------------------------------------------------\n";
        cout << "   *Your Total Cost is =      " << flights[pos].getcost() + ubers[pos].getubercost() + hotels[pos].gethotelcost() << "\n";
    }

    friend void update(int id, TravelAgency &);
    ~TravelAgency() {};
};

void update(int id, TravelAgency &obj)
{
    int pos = -1;
    for(int i = 0; i < obj.numCustomers; i++)
    {
        if(obj.customers[i].getid() == id)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        cout << "User not found\n";
        return;
    }
    string name, email;
    int age;
    cout<<"\n   Enter Updated name: ";
    cin>>name;
    cout<<"\n   Enter Updated age: ";
    cin>>age;
    cout<<"\n   Enter Updated email: ";
    cin>>email;
    Customer cus(name, age, id, email);
    obj.customers[pos] = cus;
}

int main()
{
    TravelAgency travelAgency;
    cout << "              \"Welcome to XYZ Travel Agency!\"" << endl;
    cout << "=======================================================" << endl;
    int n;
    cout<<"-----------------Customer Registration-----------------\n";
    cout<<"   Enter number of customers: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"   Please enter the following informations of customer "<<i+1<<": \n";
        travelAgency.addCustomer();
        cout<<"  User "<<travelAgency.getcustomername(i)<< " has registered successfully.\n";
    }
    cout<<"   \nDo you want to book a flight?(y/n) ";
    char ch;
    cin>>ch;
    if(ch=='Y'||ch=='y')
    {
        for(int i=0; i<n; i++)
        {
            cout<<"-----------------FLIGHT RESERVATION-----------------\n";
            cout<<"\n";
            travelAgency.addFlight();
        }
    }
    cout<<"   \nDo you want to book a hotel?(y/n) ";
    ch;
    cin>>ch;
    if(ch=='Y'||ch=='y')
    {
        cout << "-------------------HOTEL RESERVATION------------------\n";
        travelAgency.addHotel();
    }
    cout<<"   \nDo you want to book an Uber to your hotel?(y/n) ";
    cin>>ch;
    if(ch=='Y'||ch=='y')
    {
        cout << "-------------------UBER RESERVATION--------------------\n";
        travelAgency.addUber();
    }
    int id;
    cout<<"\n";
    cout << "-----------------TRAVEL AGENCY----------------- \n";
    cout << "---------------------MENU----------------------\n";
    cout << "Enter your ID: ";
    cin >> id;
    travelAgency.showTotalCost(id);

    int choice;
    do
    {
        cout<<"   \nChoose an option\n";
        cout << "  1. Display Flight Informations\n  2. Display Customer Information\n";
        cout<<"  3. update your personal Information\n  4. Exit\n";
        cout << "   Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int id;
            cout << "   Enter your ID: \n";
            cin >> id;
            travelAgency.showFlightInformation(id);
            break;
        case 2:
            id;
            cout << "   Enter your ID: \n";
            cin >> id;
            travelAgency.cutomerinfo(id);
            break;
        case 3:
            cout << "Enter Your ID: \n";
            cin >> id;
            update(id, travelAgency);
            break;
        case 4:
            cout << "\n   Thank you for using XYZ Travel Agency! Goodbye." << endl;
            exit(0);
        default:
            cout << "   Invalid choice. Please try again." << endl;
        }
    }
    while(choice != 4);
    return 0;
}
