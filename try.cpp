#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string.h>
#include<sstream>
using namespace std;
class account
{
	int acno ;
	char name[50];
	int deposit;
	char type[1];
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
};         

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
	}cout<<acno;
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
	cout<<"\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
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
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
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
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account

int main()
{
	char ch;
	int num;
	
	cout<<"BANK MANAGEMENT SYSTEM";
	cin.get();

	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
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
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n)
{
	cout<<n;
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
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
			
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void modify_account(int n)
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
		if(ac.retacno()==n)
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
void delete_account(int n)
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

void deposit_withdraw(int n, int option)
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
		if(ac.retacno()==n)
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

