#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string.h>
#include<sstream>
#include<conio.h>
using namespace std;
class account
{
	int acno ;
	char name[50];
	int deposit;
	char type[1];
	char pass[10];
public:
	account()
	{
		acno =0;
	}
	void create_account();	
	void show_account() const ;	
	void modify();
	void dep(int);	
	void draw(int);	
	void report() const;	
	int retacno() ;	
	int retdeposit() const;	
	char rettype() const;
	string retpass();	
};         
string account :: retpass()
{
	int i;
	string pwd;
	for(i=0;i<10;i++)
	{
		pwd[i]= pass[i];
	}
	pwd[i]='\0';
	return pwd;
}
void account::create_account()
{
	string acn,nam;
	string typ;
	int i,c=0;
	while(1)
	{
		cout<<"\nEnter The account No. :";
		cin>>acn;
		for ( i= 0;i<acn.length();i++)
		{
			if(!isdigit(acn[i]))
			{
				cout<<"Please Enter only digits"<<endl;
				c=1;
				break;
			}
		}
		if(c==0)
		{
		for(i=0;i<acn.length();i++)
		{
			int v1=acn[i];
			acno=acno*10+(v1-48);
		}
		break;
		}
		c=0;
	}
	
	account ac1;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac1), sizeof(account)))
	{
		if(ac1.retacno()==acno)
		{
			cout<<"Account number already exists"<<endl;
			acno = -1;
			return ;
		}
	}
	inFile.close();
	char ch,pwd[11];
	i=0;
	cout<<"\nCreate Password: ";
	while(i<10) {
        ch = getch();
        if(ch==13) { break; }
        else if(ch=='\b'&&i>0) {
            cout<<"\b \b";
            i--;
        } else {
            pwd[i]=ch;
            cout<<"*";
            i++;
        }
    }
	pwd[i]='\0';
	for (i =0 ; i< 10;i++)
	{
		pass[i] =pwd[i];
	}
		
	while(1)
	{
		cout<<"\n\nEnter The Name of The account Holder : ";
		cin.ignore();
		cin>>nam;
		for (i=0;i<nam.length();i++)
		{
			if(isdigit(nam[i]))
			{
				cout<<"Please Do Not Enter digits"<<endl;
				c=1;
				break;
			}
		}
		if(c==0)
			break;
		
		c=0;
	}
	for(i=0;i<nam.length();i++)
	{
		name[i]=nam[i];
	}
	name[i]='\0';
	 c=0;
	while(1)
	{
			cout<<"\nEnter Type of The account c or C or S or s : ";
			cin>>typ;
			if(typ.length()>1)
			{
				cout<<"Please Enter only one character c or C or S or s character length is exceeding 1"<<endl;
				continue;
			}
			else
			{
			int v2=(int)typ[0];
			if(v2==67||v2==99||v2==83||v2==115)
			{
				type[0]=typ[0];
				break;
			}
			else
			{
				cout<<"Please Enter c or C or S or s ";
				continue;
			}
		    }
	}
	type[0]=toupper(type[0]);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current) : ";
	cin>>deposit;
	system("cls");
	cout<<"\n\n\nAccount Created..";
}
string password()
{
	string pass2;
	char ch;
	int i=0;
	cout<<"\n\tEnter Password: ";
	while(i<10) {
        ch = getch();
        if(ch==13) { break; }
        else if(ch=='\b'&&i>0) {
            cout<<"\b \b";
            i--;
        } else {
            pass2[i]=ch;
            cout<<"*";
            i++;
        }
    }
	pass2[i]='\0';
	return pass2;
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : "<<name;	
	cout<<"\nType of Account : "<<type[0];
	cout<<"\nBalance amount : "<<deposit;
}
void account::modify() 
{
	string nam;
	cout<<"\nAccount No. : "<<acno;
	int c=0,i;
	while(1)
	{
		cout<<"\n\nEnter Modified Name of The account Holder : ";
		cin.ignore();
		cin>>nam;
		for (int i=0;i<nam.length();i++)
		{
			if(isdigit(nam[i]))
			{
				cout<<"Please Do Not Enter digits"<<endl;
				c=1;
				break;
			}
		}
		if(c==0)
		break;
	}
	for(i=0;i<nam.length();i++)
	{
		name[i]=nam[i];
	}
	name[i]='\0';
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type[0]=toupper(type[0]);
	//cout<<"\nModify Balance amount : ";
	//cin>>deposit;
}
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type[0]<<setw(6)<<deposit<<endl;
}	
int account::retacno()
{
	return acno;
}
int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type[0];
}
void write_account();	//function to write record in binary file
void display_sp(int,string);	//function to display account details given by user
void modify_account(int,string);	//function to modify record of file
void delete_account(int,string);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int,string); // function to desposit/withdraw amount for given account

int main()
{
	char ch;
	int num;
	string pass1;
	
	abc: cout<<"\n\n\t\t\t\t\tBANK MANAGEMENT SYSTEM\n\n";

	do
	{
		system("cls");
		cout<<"\n\n\n\t\t\t\tMAIN MENU";
		cout<<"\n\n\t\t\t\t01. NEW ACCOUNT";
		cout<<"\n\n\t\t\t\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t\t\t\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t\t\t\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t\t\t\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t\t\t\t08. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8) >> ";
		ch = getchar();
		if (!isdigit(ch))
		{
			system("cls");
			cout<<"\n\t\t\t\t\tPlease enter number input";
			goto abc;	
		}
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			pass1 = password();
			deposit_withdraw(num, 1, pass1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			pass1 = password();
			deposit_withdraw(num, 2,pass1);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			pass1 = password();
			display_sp(num,pass1);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			pass1 =password();
			delete_account(num,pass1);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			pass1 =password();
			modify_account(num,pass1);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"Please enter valid input";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}
void write_account()
{
	
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	if (ac.retacno() != -1)
	{
		outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	}	
	outFile.close();
}
void display_sp(int n,string pass3)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(ac)))
	{
		if(ac.retacno()==n && ac.retpass() == pass3)
		{
			ac.show_account();
			flag=true;
			
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void modify_account(int n,string pass3)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpass() == pass3)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void delete_account(int n,string pass3)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}
void display_all()
{
	string id,pa;
	cout<<"\n\tEnter technician id: ";
	cin>>id;
	if (id =="66.69")
	{
		account ac;
		ifstream inFile;
		inFile.open("account.dat",ios::binary);
		if(!inFile)
		{
			cout<<"File could not be open !! Press any Key...";
			return;
		}
		cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout<<"A/c no.      NAME           Type  Balance\n";
		while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
		{
			ac.report();
		}
		inFile.close();
	}
	else
	{
		cout<<"Entered id or password is wrong";
		return;
	}
}

void deposit_withdraw(int n, int option, string pass3)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && pass3 == ac.retpass())
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

