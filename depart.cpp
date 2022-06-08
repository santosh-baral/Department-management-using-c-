#include<iostream>
#include<conio.h>
#include<string.h>
#include<sstream>
#include<limits>
#include<fstream>
using namespace std;
class product
{
private:
char name[20],id[20];
char code[10],code1[10],code2[10];
int rate,quantity,yearm,monm,daym,yeare,mone,daye;
public:
void input()
	{
	cout<<"Enter the name of product::";
	cin>>name;
	cout<<"Enter the date of manufracture(year/month/day)::"<<endl;
	bool x=true;
	while(x)
    {
    	cout<<"year=";
		cin>>yearm;
		    if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
			else if((yearm<=2085) && (yearm>2060))
			{
				x=false;
			}
			else
			{
				cout<<"wrong input"<<endl;
			}
		}
 bool y=true;
 while(y)
    {
    	cout<<"month=";
		cin>>monm;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
        	else if(monm>12)
        	{
        		cout<<"invalid input"<<endl;
			}
			else
			{
				y=false;
			}
		}
 	bool z=true;
 	while(z)
    {
    	cout<<"day=";
		cin>>daym;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
         else if(daym>30)
		{
		 cout<<"invalid input"<<endl;
		}
		else
			{
                z=false;
            }
}

	cout<<"Enter the expiry date(year/month/day)::";
	while(true)
    {
    	cout<<"year=";
		cin>>yeare;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
        else if(yeare<yearm)
        {
        	cout<<"invalid input"<<endl;
		}
            else
		{
                break;
        }
 	}
 	while(true)
    {
    	cout<<"month=";
		cin>>mone;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
            else if(yearm==yeare)
            {
			if(mone<monm)
            {
            	cout<<"month of expire should be greater than month of manufracture"<<endl;
			}
			else
			{
				break;
			}
			}
			else if(mone>12||mone<1)
			{
			cout<<"invalid input";
			}
            else
			{
                break;
            }
 	}
 	while(true)
    {
    	cout<<"day=";
		cin>>daye;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
            else if(daye>30)
            {
            	cout<<"invalid input";
			}
            else if(yearm==yeare && mone==monm)
            {
            	if(daye<daym)
            	{
            		cout<<"date of expire should be greater than date of manufracture";
				}
				else
				{
					break;
				}
			}
            else
			{
                break;
            }
 	}
	while(true)
    {
    	cout<<"Enter the rate of product::Rs";
		cin>>rate;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input " << endl;
            }
            else
			{
                break;
            }
 	}
 /*	bool b=true;
 	while(b)
 	{
 		cout<<"Enter the code of product:";
		cin>>code2;
        fstream code1;
        code1.open("data.txt",ios::in);
	    while(code1>>name>>yearm>>monm>>daym>>yeare>>mone>>daye>>rate>>code>>quantity) 	
		{
		if(code2==code)
		{
			cout<<"this code is already in database:: "<<endl;
		}
		else
		{
		b=false;
		break;
		}	
 		}
 		code1.close();
	 }*/
	cout<<"Enter the code of product:";
	cin>>code;
	cout<<"Enter the quantity:";
	cin>>quantity;
}
void fwrite()
{
		fstream out;
		out.open("data.txt",ios::app);
		out<<name<<" "<<yearm<<" "<<monm<<" "<<daym<<" "<<yeare<<" "<<mone<<" "<<daye<<" "<<rate<<" "<<code<<" "<<quantity<<endl;
		out.close();
}

void remove()
{
	cout<<"enter the code of product you want to removde::";
	cin>>code1;
    fstream out,temp;
	out.open("data.txt", ios::in);
	temp.open("temp.txt",ios::out);
	while(out>>name>>yearm>>monm>>daym>>yeare>>mone>>daye>>rate>>code>>quantity)
	{
		if(strcmp(code1,code)==0)
		{
			cout<<"you have successfully remove: "<<name;
			getch();
			continue;
		}
		else
		{
			temp<<name<<" "<<yearm<<" "<<monm<<" "<<daym<<" "<<yeare<<" "<<mone<<" "<<daye<<" "<<rate<<" "<<code<<" "<<quantity<<endl;
		}
		}
	temp.close();
	out.close();
	out.open("data.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(temp>>name>>yearm>>monm>>daym>>yeare>>mone>>daye>>rate>>code>>quantity)
	{
		out<<name<<" "<<yearm<<" "<<monm<<" "<<daym<<" "<<yeare<<" "<<mone<<" "<<daye<<" "<<rate<<" "<<code<<" "<<quantity<<endl;
	}
	temp.close();
	out.close();
}

void detail()
{
	cout<<endl<<endl<<"                                *************DETAIL OF PRODUCT *************"<<endl;
	int i;
		for(i=0;i<=117;i++)
		{
			cout<<"-";
		}
		cout<<endl;
	cout<<"| NAME"<<"            |"<<" DATE OF MANUFRACTURE"<<"|"<<" DATE OF EXPIRE"<<" |"<<" RATE"<<"        |"<<" QUANTITY       |"<<" CODE          |"<<" TOTAL COST    |"<<endl;
		for(i=0;i<=117;i++)
		{
			cout<<"-";
		}
		cout<<endl;
		fstream out;
		string text;
		out.open("data.txt",ios::in);
		while(out>>name>>yearm>>monm>>daym>>yeare>>mone>>daye>>rate>>code>>quantity)
		{
		cout<<"| "<<name;
		for(i=0;i<=15-strlen(name);i++)
		{
			cout<<" ";
		}
		cout<<"| ";
		cout<<yearm<<"/"<<monm<<"/"<<daym;
		int n1=yearm,n2=monm,n3=daym;
		int m,m1=0,m2=0,m3=0;
		while(n1>0)
		{
			n1=n1/10;
			m1++;
		}
			while(n2>0)
		{
			n2=n2/10;
			m2++;
		}
			while(n3>0)
		{
			n3=n3/10;
			m3++;
		}
		m=m1+m2+m3;
		for(i=0;i<=17-m;i++)
		{
			cout<<" ";
		}
		cout<<"| ";
		cout<<yeare<<"/"<<mone<<"/"<<daye;
		int a1=yeare,a2=mone,a3=daye;
		int count4,count5=0,count6=0,count7=0;
		while(a1>0)
		{
			a1=a1/10;
			count5++;
		}
			while(a2>0)
		{
			a2=a2/10;
			count6++;
		}
			while(a3>0)
		{
			a3=a3/10;
			count7++;
		}
		count4=count5+count6+count7;
		for(i=0;i<=12-count4;i++)
		{
			cout<<" ";
		}
		cout<<"| ";
		cout<<"Rs"<<rate;
		int r=rate,r1=0;
		while(r>0)
		{
			r=r/10;
			r1++;
		}
		for(i=0;i<=9-r1;i++)
		{
			cout<<" ";
		}
		cout<<"| ";
		cout<<quantity;
		int q=quantity,q1=0;
		while(q>0)
		{
			q=q/10;
			q1++;
		}
		for(i=0;i<=14-q1;i++)
		{
			cout<<" ";
		}
		cout<<"| ";
		cout<<code;
		for(i=0;i<=13-strlen(code);i++)
		{
			cout<<" ";
		}
		cout<<"|";
		int total,t,t1;
		total=rate*quantity;
		cout<<"Rs"<<total;
		t=total,t1=0;
		while(t>0)
		{
			t=t/10;
			t1++;
		}
		for(i=0;i<=12-t1;i++)
		{
			cout<<" ";
		}
		cout<<"|"<<endl;
		}
		out.close();
getch();
}
};
void password()
{
	int i;
	char password[10];
	string passwor;
	fstream pass;
	bool a=true;
	while(a)
	{
	cout<<endl<<endl<<endl<<" *****************WELCOME TO DEPARTMENT MANAGEMENT SYSTEM****************"<<endl<<endl;
	cout<<"*******TO LOGIN IN THIS SYSTEM PLEASE ENTER 5 CHARACTER PASSSWORD***********";
	cout<<endl<<endl<<endl<<"                     Enter the password letter by letter=";
		for(int z=0;z<5;z++)
	{
		password[z]=getch();
		//system("cls");
		//cout<<"
		cout<<"*";
	}
	password[5]='\0';
	pass.open("pass.txt",ios::in);
	while(pass>>passwor)
	{
	if(password==passwor)
	{
		cout<<endl<<endl<<endl<<endl<<"                                  ****WELCOME LOGIN IS SUCCESSFULL**********";
	//goto mainmenu();
	a=false;
	}
	else
	{
		cout<<endl<<"******access denied!!!!!!...*********"<<endl;
		system("cls");
	}
	}
	pass.close();
}
}
void changepass()
	{
		int i;
		fstream pass,newpass;
		string password;
    	char password1[10],password2[10];
    	pass.open("pass.txt", ios::in);
    	newpass.open("newpass.txt", ios::out);
    	cout<<"Enter old password name: ";
    	for(int z=0;z<5;z++)
		{
		password1[z]=getch();
			for(i=z;i<=z;i++)
			{
			cout<<"*";
			}
		}cout<<endl;
		password1[5]='\0';
    cout<<"\nEnter new password: ";
   	for(int z=0;z<5;z++)
	{
		password2[z]=getch();
		for(i=z;i<=z;i++)
		{
			cout<<"*";
		}
	}cout<<endl;
	password2[5]='\0';
    while(pass>>password)
    {
        if(password1==password)
        {
            password=password2;
            cout<<"**********password is change**********";
			newpass<<password<<endl;
			getch();
		}
		else
		{
			cout<<"password isnot change";
			getch();
		}
    }
    pass.close();
    newpass.close();
    pass.open("pass.txt", ios::out);
    newpass.open("newpass.txt", ios::in);
    while(newpass>>password)
    {
        pass<<password<<endl;
    }
    pass.close();
    newpass.close();
}
void mainmenu()
{

	cout<<"                            WELCOME IN TAPLEJUNG STORE	"<<endl<<endl;
	cout<<"|*****************************************************************************|"<<endl;
	cout<<"|******                                                                   ****|"<<endl;
	cout<<"|********             press the following number to perform task        ******|"<<endl;
	cout<<"|**********                                                           ********|"<<endl;
	cout<<"|************            1 to add the item                          **********|"<<endl;
	cout<<"|**************          2 to remove sells item                   ************|"<<endl;
	cout<<"|****************        3 to get detail of product             **************|"<<endl;
	cout<<"|******************      4 to change the password or logout   ****************|"<<endl;
	cout<<"|********************    5 to exit                          ******************|"<<endl;
	cout<<"|**********************                                   ********************|"<<endl;
	cout<<"press any number above=";
	//cout<<"taplejung";
}
int main()

{
	password();
	product p;
	char a;
	bool x=true;
	while(x)
	{
		system("CLS");
		mainmenu();
		cin>>a;
		switch (a)
		{

		case '1':
			{
				system("CLS");
				p.input();
				p.fwrite();
				system("CLS");
				cout<<"you have enter the data successfully"<<endl<<endl<<"press any key to continue";
				getch();
				break;
			}
		case '2':
			{
				system("CLS");
				p.remove();
				break;
			}
		case '3':
			{
				system("CLS");
				p.detail();
				break;
			}
		case '4':
		{
			bool y=true;
			while(y)
			{
			system("CLS");
			cout<<"press 1 to change password"<<endl;
			cout<<"press 2 to logout"<<endl;
			cout<<"enter choice:";
			int x;
			cin>>x;
			if(x==1)
			{
			system("CLS");
			changepass();
			password();
			y=false;
			}
			else if(x==2)
			{
				system("CLS");
				password();
				y=false;
			}
			else
			{
			 cout<<"wrong input";
			}
			}
			break;
		}

		case '5':
		{
			system("CLS");
			x=false;
			break;
		}
		default:
			{
				cout<<"wrong input";
			}
		}
	}
	 
    return 0;
 

}
