#include<iostream>
#include<fstream>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
class HOTEL
{
	public:
		void screen()
	{	int i;
		gotoxy(20,8);

		for(i=1;i<=40;i++)
		{
			cout<<"*";
		}
		for(i=8;i<=23;i++)
		{
			gotoxy(60,i);
			cout<<"*";
		}
		for(i=9;i<=23;i++)
		{
			gotoxy(20,i);
			cout<<"*";
		}
		for(i=1;i<=40;i++)
		{
			cout<<"*";
		}
	}
	void welcome()
	{
		gotoxy(36,10);
		cout<<"C++ PROJECT";
		gotoxy(40,11);
		cout<<"ON";
		gotoxy(33,12);
		cout<<"HOTEL MANAGEMENT";
		gotoxy(25,15);
		cout<<"Made by:-";
		gotoxy(25,16);
		cout<<"ASTHA and DIKSHA BHASIN";
		gotoxy(25,18);
		cout<<"Submitted to:-";
		gotoxy(25,19);
		cout<<"Mrs. VENUKA";
		gotoxy(25,21);
		cout<<"Press ENTER to continue....";
		getch();

	}
	void login()
	{       int ch;
		gotoxy(35,10);
		cout<<"Login Screen";
		gotoxy(30,12);
		gotoxy(25,12);
		cout<<"1. Administrator Login";
		gotoxy(25,13);
		cout<<"2. Customer Login";
		gotoxy(25,14);
		cout<<"3. Exit";
		gotoxy(25,16);
		cout<<"Enter Choice    ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		   case 1: admin();
			   getch();
			   break;
		   case 2: customerlog();
			   getch();
			   break;
		   case 3: exit(0);
		}
	}
	void admin()
	{
		clrscr();
		screen();
		char login[30];
		char password[30];
		gotoxy(33,10);
		cout<<"Login Id:  ";
		gets(login);
		gotoxy(33,12);
		cout<<"Password:  ";
		int i=0;
		while(1)
		{
		    char ch=getch();
		    if(ch==8)
		    {
			 if(i!=0)
			 {
			    cout<<"\b";
			    cout<<" ";
			    cout<<"\b";
			    i--;

			 }
		    }
		    else if(ch==13)
		    {
			 break;
		    }
		    else
		    {
			password[i]=ch;
			cout<<"*";
			i++;
		    }
		}
		password[i]='\0';
		int m=strcmp(login,"astha");
		int n=strcmp(password,"diksha");
		if(m==0 && n==0)
		{
			clrscr();
			screen1();
		}
		else
		{
			gotoxy(25,15);
			cout<<"Incorrect Login Id or Password";
			gotoxy(25,17);
			char max;
			cout<<"Do you want  to continue y/n.... ";
			cin>>max;
			if(max=='y'||max=='Y')
			{
			     clrscr();
			     screen();
			     admin();
			}
			else
			{
			    exit(0);
			}
		}
	}
	void customerlog()
	{
		clrscr();
		screen();
		int logid;
		char y,max;
		char logname[30];
		gotoxy(33,10);
		cout<<"Login   Id:  ";
		cin>>logid;
		gotoxy(33,12);
		cout<<"Login Name:  ";
		gets(logname);

		Customer k1;

		fstream file;
		file.open("xyz.cpp",ios::in|ios::binary);
		file.seekg(0,ios::end);
		int f=file.tellg()/sizeof(Customer);
		file.seekg(0,ios::beg);

		for(int i=1;i<=f;i++)
		{
			file.read((char*)&k1,sizeof(Customer));
			if(k1.custsearch(logid,logname))
			{
				clrscr();
				screen2();
				k1.show(9);
				gotoxy(7,12);
				cout<<"Do you want to see your bill y/n....";
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen2();
					k1.bill();
					break;

				}
				else
				{
					exit(0);
				}
			}
			else
			{
				gotoxy(25,15);
				cout<<"There is no such Record";
			}
		}
			gotoxy(33,23);
			cout<<"Do you want  to continue y/n.... ";
			file.close();
			cin>>max;
			if(max=='y'||max=='Y')
			{
			     clrscr();
			     screen();
			     login();
			}
			else
			{
			    exit(0);
			}
	}

	void screen1()
	{
		int i;
		gotoxy(35,4);
		cout<<"Welcome To";
		gotoxy(33,5);
		cout<<"PARADISE HOTEL";
		gotoxy(10,6);
		for(i=1;i<=60;i++)
		{
			cout<<"*";
		}
		for(i=6;i<=25;i++)
		{
			gotoxy(70,i);
			cout<<"*";
		}
		for(i=6;i<=25;i++)
		{
			gotoxy(10,i);
			cout<<"*";
		}
		for(i=1;i<=60;i++)
		{
			cout<<"*";
		}
		menu1();
	}
	void screen2()
	{
		int i;
		gotoxy(5,5);
		for(i=1;i<=70;i++)
		{
			cout<<"*";
		}
		for(i=6;i<=20;i++)
		{
			gotoxy(75,i);
			cout<<"*";
		}
		for(i=6;i<=20;i++)
		{
			gotoxy(5,i);
			cout<<"*";
		}
		for(i=1;i<=70;i++)
		{
			cout<<"*";
		}
	}
	 public:void menu1()
	{
		int ch;
		gotoxy(15,10);
		cout<<"1. Add Customer";
		gotoxy(15,11);
		cout<<"2. Display Customer";
		gotoxy(15,12);
		cout<<"3. Search Customer";
		gotoxy(15,13);
		cout<<"4. Update Customer";
		gotoxy(15,14);
		cout<<"5. Delete Customer";
		gotoxy(15,15);
		cout<<"6. Checkout Customer";
		gotoxy(15,16);
		cout<<"7. Enter Room Details";
		gotoxy(15,17);
		cout<<"8. Show Room Details";
		gotoxy(15,18);
		cout<<"9. EXIT";
		gotoxy(15,19);
		cout<<"Enter your Choice..";
		cin>>ch;
		Customer k;
		char y;
		fstream file;
		char text[]="xyz.cpp";
		fstream str;
		char text12[]="FileInput.cpp";
		switch(ch)
		{
			case 1: clrscr();
			       screen();
			       gotoxy(33,7);
				cout<<"Add Customer                  ";
				file.open(text,ios::out|ios::app|ios::binary);
				if(file!=NULL)
				{
					k.add();
					file.write((char*)&k,sizeof(Customer));
					gotoxy(33,23);
					cout<<"Record is Added"<<endl;
					gotoxy(33,25);
					 cout<<"Do you want to continue y/n....";
					file.close();
					cin>>y;
					if(y=='Y' || y=='y')
					{
					    clrscr();
					    screen1();
					}
					else
					{
					   exit(0);
					}
				}
				else
				{
					cout<<"File not formed";
				}
				file.close();
				break;
			case 2: clrscr();
				screen2();
				int num4=7;
				gotoxy(33,7);
				file.open(text,ios::in|ios::binary);
				file.seekg(0,ios::end);
				int m1=file.tellg()/sizeof(Customer);
				file.seekg(0,ios::beg);
				for(int i=1;i<=m1;i++)
				{
					file.read((char*)&k,sizeof(Customer));
					 num4=num4+2;
					k.show(num4);
				}
				gotoxy(33,25);
				cout<<"Do you want to continue y/n....";
				file.close();
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					   exit(0);
				}
				getch();
				break;
			case 3: clrscr();
				screen2();
				gotoxy(33,7);
				int num,p=0;
				cout<<"Search Customer      ";
				gotoxy(33,9);
				cout<<"Enter Customer ID:  ";
				cin>>num;
				file.open(text,ios::in|ios::binary);
				file.seekg(0,ios::end);
				int m2=file.tellg()/sizeof(Customer);
				file.seekg(0,ios::beg);
				for(i=1;i<=m2;i++)
				{
					file.read((char*)&k,sizeof(Customer));
					p=k.search(num);
					if(p==1)
					{
						k.show(9);
						break;
					}
				}
				if(p==0)
				{
					gotoxy(33,11);
					cout<<"No  Record Found"<<endl;
				}
				gotoxy(7,12);
				cout<<"Do you want to continue y/n....";
				file.close();
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					exit(0);
				}
				break;
			case 4:	clrscr();
				screen2();
				gotoxy(33,7);
				cout<<"Modify Customer";
				int num2,p2=0;
				gotoxy(33,9);
				cout<<"Enter Customer ID:  ";
				cin>>num2;
				file.open(text,ios::in|ios::binary);
				file.seekg(0,ios::end);
				int m4=file.tellg()/sizeof(Customer);
				file.seekg(0,ios::beg);
				fstream cpy1;
				char text2[]="Copy.cpp";
				cpy1.open(text2,ios::out|ios::binary);
				int x1=0;
				for(i=1;i<=m4;i++)
				{
					file.read((char*)&k,sizeof(Customer));
					p2=k.search(num2);
					if(p2==1)
					{
						x1=1;
						k.modify();
						gotoxy(10,22);
						cpy1.write((char*)&k,sizeof(Customer));
						cout<<"Record is Updated"<<endl;
					}
					else
					{
						cpy1.write((char*)&k,sizeof(Customer));
					}
				}
				if(x1==0)
				{
					gotoxy(33,11);
					cout<<"No  Record Found"<<endl;
				}
				else
				{
					cpy1.close();
					file.close();
					file.open(text,ios::out|ios::binary);
					cpy1.open(text2,ios::in|ios::binary);
					cpy1.seekg(0,ios::end);
					int max1=cpy1.tellg()/sizeof(Customer);
					cpy1.seekg(0,ios::beg);
					for(i=1;i<=max1;i++)
					{
						cpy1.read((char*)&k,sizeof(Customer));
						file.write((char*)&k,sizeof(Customer));
					}
				}
				gotoxy(10,24);
				cout<<"Do you want to continue y/n....";
				file.close();
				cpy1.close();
				remove(text2);
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					exit(0);
				}
				break;
			case 5: clrscr();
				screen2();
				gotoxy(33,7);
				cout<<"Delete Customer";
				int num1,p1=0;
				gotoxy(33,9);
				cout<<"Enter Customer ID:  ";
				cin>>num1;
				file.open(text,ios::in|ios::binary);
				file.seekg(0,ios::end);
				int m3=file.tellg()/sizeof(Customer);
				file.seekg(0,ios::beg);
				fstream cpy;
				char text1[]="Copy.cpp";
				cpy.open(text1,ios::out|ios::binary);
				int x=0;
				for(i=1;i<=m3;i++)
				{
					file.read((char*)&k,sizeof(Customer));
					p1=k.search(num1);
					if(p1==1)
					{
						x=1;
						gotoxy(7,10);
						cout<<"Record is Deleted"<<endl;
					}
					else
					{
						cpy.write((char*)&k,sizeof(Customer));
					}
				}
				if(x==0)
				{
					gotoxy(33,11);
					cout<<"No  Record Found"<<endl;
				}
				else
				{
					cpy.close();
					file.close();
					file.open(text,ios::out|ios::binary);
					cpy.open(text1,ios::in|ios::binary);
					cpy.seekg(0,ios::end);
					int max=cpy.tellg()/sizeof(Customer);
					cpy.seekg(0,ios::beg);
					for(i=1;i<=max;i++)
					{
						cpy.read((char*)&k,sizeof(Customer));
						file.write((char*)&k,sizeof(Customer));
					}
				}
				gotoxy(7,15);
				cout<<"Do you want to continue y/n....";
				file.close();
				cpy.close();
				remove(text1);
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					exit(0);
				}
				break;
			case 6: clrscr();
				screen2();
				gotoxy(33,7);
				int num6,p6=0;
				char name[30];
				cout<<"Search Customer      ";
				gotoxy(33,9);
				cout<<"Enter Customer ID:  ";
				cin>>num6;
				file.open(text,ios::in|ios::binary);
				file.seekg(0,ios::end);
				int m6=file.tellg()/sizeof(Customer);
				file.seekg(0,ios::beg);
				for(i=1;i<=m6;i++)
				{
					file.read((char*)&k,sizeof(Customer));
					p6=k.search(num6);
					if(p6==1)
					{
						k.show1(9);
						gotoxy(7,12);
						cout<<"Do you want to generate bill y/n....";
						cin>>y;
						if(y=='Y' || y=='y')
						{
							clrscr();
							screen2();
							k.bill();
							break;
						}
						else
						{
							exit(0);
						}
					}
				}
				if(p6==0)
				{
					gotoxy(33,11);
					cout<<"No  Record Found"<<endl;
				}
				gotoxy(33,23);
				cout<<"Do you want to continue y/n....";
				file.close();
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					exit(0);
				}
				break;
			case 7: clrscr();
				screen2();
				str.open(text12,ios::out|ios::app|ios::binary);
				if(str!=NULL)
				{
					k.add1();
					str.write((char*)&k,sizeof(Customer));
					gotoxy(33,23);
					cout<<"Record is Added"<<endl;
					gotoxy(33,25);
					cout<<"Do you want to continue y/n....";
					str.close();
					cin>>y;
					if(y=='Y' || y=='y')
					{
					    clrscr();
					    screen1();
					}
					else
					{
					   exit(0);
					}
				}
				else
				{
					cout<<"File not formed";
				}
				break;
			case 8:	 clrscr();
				screen2();
				int num12=7;
				gotoxy(33,7);
				str.open(text12,ios::in|ios::binary);
				str.seekg(0,ios::end);
				int m12=str.tellg()/sizeof(Customer);
				str.seekg(0,ios::beg);
				for(i=1;i<=m12;i++)
				{
					str.read((char*)&k,sizeof(Customer));
					 num12=num12+2;
					k.room(num12);
				}
				gotoxy(33,25);
				cout<<"Do you want to continue y/n....";
				str.close();
				cin>>y;
				if(y=='Y' || y=='y')
				{
					clrscr();
					screen1();
				}
				else
				{
					   exit(0);
				}
				getch();
				break;
		case 9: exit(0);
		}
  }
};

class Customer
{
    int cust_id;
    char cust_name[30];
    int cust_age;
    char cust_occupation[50];
    int inYear;
    int inMonth;
    int inDate;
    int otYear;
    int otMonth;
    int otDate;
    int rtype;
    long int charge;
    char choice;
    char rname[30];
    int days;
    long int total_charge;

    public:
    void show(int num)
    {   gotoxy(20,3);
	cout<<"Customer Information";
	gotoxy(7,7);
	int max=9;
	cout<<"Id"<<setw(max)<<"Name"<<setw(max)<<"Age"<<setw(max)<<"OCP"<<setw(max)<<"Year"<<setw(max)<<"Month"<<setw(max)<<"Date";
	gotoxy(7,num);
	cout<<cust_id<<setw(max)<<cust_name<<setw(max)<<cust_age<<setw(max)<<cust_occupation<<setw(max)<<inYear<<setw(max)<<inMonth<<setw(max)<<inDate<<endl;
    }
    void show1(int num)
    {
	 gotoxy(20,3);
	cout<<"Check Out Customer";
	gotoxy(7,7);
	int max=12;
	cout<<"Id"<<setw(max)<<"Name"<<setw(max+3)<<" CheckInDate "<<setw(max+4)<<" CheckOutDate ";
	gotoxy(7,num);
	cout<<cust_id<<setw(max)<<cust_name<<setw(max)<<inYear<<"/"<<inMonth<<"/"<<inDate<<setw(max+2)<<otYear<<"/"<<otMonth<<"/"<<otDate<<endl;
    }

    void bill()
    {
	days=(otDate-inDate);
	if(rtype==1)
	{
	      charge=9000;
	}
	else  if(rtype==2)
	{
		charge=8000;
	}
	else if(rtype==3)
	{
		charge==7000;
	}
	else
	{
		charge==4000;
	}
	total_charge=(days*charge);
	show1(9);
	gotoxy(7,13);
	cout<<"Number of days stayed:  "<<days;
	gotoxy(7,14);
	cout<<"Charges per day:  "<<charge;
	gotoxy(7,15);
	cout<<"Service Charger:  500";
	gotoxy(7,16);
	cout<<"Hotel Charge:   "<<total_charge;
	gotoxy(7,17);
	cout<<"Total Charge:   "<<total_charge+500;

    }

    void add()
    {
       gotoxy(25,10);
       cout<<"Enter customer Id: ";
       cin>>cust_id;
       gotoxy(25,11);
       cout<<"Enter customer Name: ";
       cin>>cust_name;
       gotoxy(25,12);
       cout<<"Enter customer Age: ";
       cin>>cust_age;
       gotoxy(25,13);
       cout<<"Enter customer Occupation: ";
       cin>>cust_occupation;
       gotoxy(25,14);
       cout<<"Enter customer Check In Date: ";
       gotoxy(25,15);
       cout<<"Year : ";
       cin>>inYear;
       gotoxy(25,16);
       cout<<"Month : ";
       cin>>inMonth;
       gotoxy(25,17);
       cout<<"Date : ";
       cin>>inDate;
       gotoxy(25,18);
       cout<<"Enter Room Type : ";
       cin>>rtype;
       gotoxy(25,19);
       cout<<"Enter customer Check Out Date:  ";
       gotoxy(25,20);
       cout<<"Year: ";
       cin>>otYear;
       gotoxy(25,21);
       cout<<"Month: ";
       cin>>otMonth;
       gotoxy(25,22);
       cout<<"Date: ";
       cin>>otDate;
    }

    void add1()
    {
       gotoxy(25,10);
       cout<<"Enter Room Type: ";
       cin>>rtype;
       gotoxy(25,11);
       cout<<"Enter Room Name: ";
       cin>>rname;
       gotoxy(25,12);
       cout<<"Enter Room Charge: ";
       cin>>charge;



    }

    void room(int num)
    {
	gotoxy(25,3);
	cout<<"Room Details";
	gotoxy(15,7);
	int max=15;
	cout<<"Type"<<setw(max)<<"Name"<<setw(max)<<"Charge";
	gotoxy(15,num);
	cout<<rtype<<setw(max)<<rname<<setw(max)<<charge<<endl;

    }

    void modify()
    {

       gotoxy(25,11);
       cout<<"Enter customer Name: ";
       cin>>cust_name;
       gotoxy(25,12);
       cout<<"Enter customer Age: ";
       cin>>cust_age;
       gotoxy(25,13);
       cout<<"Enter customer Occupation: ";
       cin>>cust_occupation;
       gotoxy(25,14);
       cout<<"Enter customer Check In Date: ";
       gotoxy(25,15);
       cout<<"Year : ";
       cin>>inYear;
       gotoxy(25,16);
       cout<<"Month : ";
       cin>>inMonth;
       gotoxy(25,17);
       cout<<"Date : ";
       cin>>inDate;
       gotoxy(25,18);
       cout<<"Enter Room Type :- ";
       cin>>rtype;
       gotoxy(25,19);
       cout<<"Enter Room Charges :- ";
       cin>>charge;
       gotoxy(25,20);


    }
    int search(int num)
    {
	if(num==cust_id)
	{
		return 1;
	}
	else
	{
		return 0;
	}

    }

    int custsearch(int num,char name[])
    {
	if(num==cust_id && strcpy(name,cust_name))
	{
		return 1;
	}
	else
	{
		return 0;
	}

    }

    void checkout()
    {
	gotoxy(25,10);
	cout<<"Enter Customer Id    ";
	cin>>cust_id;
	gotoxy(27,12);
	cout<<"Customer Checkout SUCCESSFULL ";
    }

};

void main()
{
	clrscr();
	HOTEL k;
	k.screen();
	k.welcome();
	clrscr();
	k.screen();
	k.login();
	getch();
}