#include<iostream>
#include<fstream>
using namespace std;

int deluxe=5,super=5,suit=5;

bool login()
{
	string id,pass;

	cout<<"\n---Login Page---\n";
	cout<<"Enter ID       = ";
	cin>>id;
	cout<<"Enter Password = ";
	cin>>pass;

	if(id=="admin" && pass=="admin123")
	{
		cout<<"\nLogin Successful !!";
		return true;
	}
	else
	{
		cout<<"\nInvalid Credentials";
		return false;
	}
}

void show()
{
	cout<<"\n***HOTEL RESERVATION SYSTEM***\n";
	cout<<"\n~Room Availabily~\n";
	cout<<"1.Deluxe Room:"<<deluxe<<endl;
	cout<<"2.Super-Duluxe Room:"<<super<<endl;
	cout<<"3.Suit Room:"<<suit<<endl;
}

void booking()
{
	int day,choice;
	int bill=0;
	string name;

	cout<<"\nEnter Customer Name = ";
	cin>>name;

	cout<<"1.Deluxe.\n";
	cout<<"2.Super-Deluxe.\n";
	cout<<"3.Suit.\n";
	cout<<"Enter your choice:";
	cin>>choice;

	cout<<"Enter the day:";
	cin>>day;

	if(choice==1 && deluxe>0)
	{
		bill=5000*day;
		deluxe--;
	}
	else if(choice==2 && super>0)
	{
		bill=7000*day;
		super--;
	}
	else if(choice==3 && suit>0)
	{
		bill=10000*day;
		suit--;
	}
	else
	{
		cout<<"Not available !! ";
		return;
	}

	ofstream fout("room.dat");
	fout<<deluxe<<" "<<super<<" "<<suit;
	fout.close();

	ofstream book("booking.txt",ios::app);
	book<<name<<" "<<bill<<endl;
	book.close();

	cout<<"\nRoom booked successfully!";
	cout<<"\nTotal Bill: Rs"<<bill<<endl;
}

void display_book()
{
	int bill;
	string name;
	ifstream file("booking.txt");

	cout<<"\n--Record Booking--\n";

	while(file>>name>>bill)
	{
		cout<<"Customer Name : "<<name<<endl;
		cout<<"Bill          : "<<bill<<endl;
	}

	file.close();
}

int main()
{
	int choice;
	bool flag=false;

	do
	{
		cout<<"\n***** HOTEL MANAGEMENT SYSTEM *****\n";
		cout<<"1.Login Page.\n";
		cout<<"2.Show Room Availability.\n";
		cout<<"3.Book Room.\n";
		cout<<"4.Show Booking.\n";
		cout<<"5.Exit.\n";
		cout<<"Enter choice = ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				flag=login();
				break;

			case 2:
				if(flag) show();
				else cout<<"\nPlease login first";
				break;

			case 3:
				if(flag) booking();
				else cout<<"\nPlease login first";
				break;

			case 4:
				if(flag) display_book();
				else cout<<"\nPlease login first";
				break;

			case 5:
				cout<<"Exiting...\n";
				break;

			default:
				cout<<"Invalid choice!\n";
		}
	}
	while(choice!=5);

	return 0;
}
