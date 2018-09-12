//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//                   STUDENT REPORT CARD GENERATION
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


//#################################################################
//                    HEADER FILES USED
//#################################################################


#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//                      CLASS: REPORT CARD
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


class reportcard
{
	int rno;
	char name[40];
	float sub1, sub2, sub3, sub4, sub5;
	char grade;
	float per;
	void calculate();	//FUNCTION TO CALCULATE GRADE

public:
	void getdata();		//FUNCTION TO ACCEPT DATA FROM USER
	void showdata();	//FUNCTION TO SHOW ALL THE DATA
	void show_result(int);
	int retrno();
};
//CLASS FINISHES


void reportcard::getdata()
{       cout<<"###################################";
	cout<<"Enter student Details as follows:";
	cout<<"\nEnter the roll number of student:";
	cin>>rno;
	cout<<"\n\nEnter the Name of student:";
	gets(name);
	cout<<"\nEnter the marks in physics (max 100):";
	cin>>sub1;
	cout<<"\nEnter the marks in chemistry (max 100):";
	cin>>sub2;
	cout<<"\nEnter the marks in maths (max 100): ";
	cin>>sub3;
	cout<<"\nEnter the marks in english (max 100): ";
	cin>>sub4;
	cout<<"\nEnter the marks in computer science (max 100): ";
	cin>>sub5;
	calculate();
}


void reportcard::showdata()
{
	cout<<"\n\n******************************REPORT CARD********************************";
	cout<<endl<<setw(20)<<"Roll number: "<<rno<<endl;
	cout<<setw(20)<<"Name: "<<name<<endl;
	cout<<"\n###########################################################################";
	cout<<"\nSubject                   Maximum Marks           Marks Obatined";
	cout<<"\n###########################################################################";
	cout<<"\nPhysics                       100                  "<<sub1;
	cout<<"\nChemistry                     100                  "<<sub2;
	cout<<"\nMaths                         100                  "<<sub3;
	cout<<"\nEnglish                       100                  "<<sub4;
	cout<<"\nComputer Science              100                  "<<sub5;
	cout<<"\n#############################################################################"<<endl;
	cout<<setw(20)<<"Percentage: "<<per<<"%"<<endl;
	cout<<setw(20)<<"Grade: "<<grade;
}


void reportcard::calculate()
{
	per=(sub1+sub2+sub3+sub4+sub5)/5.0;
	if(per>=90)
		grade='A';
	else if(per>= 80)
		grade= 'B';
	else if(per>=70)
		grade = 'C';
	else if(per>=60)
		grade='D';
	else if(per>=50)
		grade='E';
	else
		grade='F';
}


void reportcard::show_result(int s)
{
	cout<<rno;
	gotoxy(14,7+s);
	cout<<name;
	gotoxy(24,7+s);
	cout<<sub1;
	gotoxy(29,7+s);
	cout<<sub2;
	gotoxy(33,7+s);
	cout<<sub3;
	gotoxy(36,7+s);
	cout<<sub4;
	gotoxy(40,7+s);
	cout<<sub5;
	gotoxy(47,7+s);
	cout<<per;
	gotoxy(60,7+s);
	cout<<grade<<endl;
}


int  reportcard::retrno()
{
	return rno;
}

//#################################################################
//    	               FUNCTION DECLARATION
//#################################################################


void inputstud();	//write the record in binary file
void dispstud();	//read all records from binary file
void disp_spstud(int);	//accept rno and read record from binary file
void modstud(int);	//accept rno and update record of binary file
void delstud(int);	//accept rno and delete selected records from binary file
void result();	//display all records in tabular format from binary file
void resultmenu();		//display result menu
void intro();		//display welcome screen
void entry_menu();	//display main menu on screen


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    	          MAIN FUNCTION OF THE PROGRAME
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


void main()
{
	int ch;
	clrscr();
	intro();
	clrscr();
	gotoxy(10,18);
	char *p;
	p=getpass("Enter Password : ");
	if(strcmp(p,"SVSS")==0)
	{
		gotoxy(10,18);
		clreol();
		cout<<"\t\t\tWelcome to my program ";
		for(int i=0;i<=75;i++)
		{
			gotoxy(2+i,20);
			cout<<char(236);
			delay(120);
			gotoxy(40,21);
			cout<<4*i/3<<"%";
		}
		getch();
		do
		{
			clrscr();
			cout<<endl;
			cout<<setw(20)<<" MAIN MENU"<<endl;
			cout<<setw(20)<<" 1. STUDENT DATABASE"<<endl;
			cout<<setw(20)<<" 2. REPORT CARD"<<endl;
			cout<<setw(20)<<" 3. EXIT"<<endl;
			cout<<setw(25)<<"Please Select Your Option (1-3) ";
			cin>>ch;
			clrscr();
			switch(ch)
			{
				case 1 : entry_menu();
					 break;

				case 2 : resultmenu();
					 break;

				case 3 :
					 break;
				default :
					 cout<<"\n Wrong command...";
			}
		}while(ch!='3');
	}


	else
	{
		clrscr();
		gotoxy(10,22);
		cout<<"\n PASSWORD INCORRECT ...";
		delay(800);
	}
}
//#################################################################
//                  FUNCTION TO WRITE IN A FILE
//#################################################################


void inputstud()
{
	reportcard r1;
	ofstream dFile;
	dFile.open("student.dat",ios::binary|ios::app);
	r1.getdata();
	dFile.write((char *) &r1, sizeof(reportcard));
	dFile.close();
	cout<<"\n\nStudent record Has Been Created ";
	getch();
}


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    	     FUNCTION TO READ ALL RECORDS FROM THE FILE
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#

void dispstud()
{
	reportcard r2;
	ifstream sFile;
	sFile.open("student.dat",ios::binary);

	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(sFile.read((char *) &r2, sizeof(reportcard)))
	{
		r2.showdata();
	}
	sFile.close();
	getch();
}


//#################################################################
//           FUNCTION TO READ SPECIFIC RECORD IN A FILE
//#################################################################


void disp_spstud(int n)
{
	reportcard r3;
	ifstream aFile;
	aFile.open("student.dat",ios::binary);

	int c=0;
	while(aFile.read((char *) &r3, sizeof(reportcard)))
	{
		if(r3.retrno()==n)
		{
			 r3.showdata();
			 c=1;
		}
	}
	aFile.close();
	if(c==0)
		cout<<"\n\n Record does not exist";
	getch();
}


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    	      FUNCTION TO MODIFY A RECORD IN A FILE
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


void modstud(int n)
{
	int x=1;
	reportcard r4;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);

	while(File.read((char *) &r4, sizeof(reportcard)))
	{
		if(r4.retrno()==n)
		{
			r4.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			r4.getdata();
			int pos=(-1)*sizeof(r4);
			File.seekp(pos,ios::cur);
			File.write((char *) &r4, sizeof(reportcard));
			cout<<"\n\n\t Record Updated";
			x=0;
		}
	}
	File.close();
	if(x==1)
		cout<<"\n\n Record Not Found ";
	getch();
}


//################################################################
//           FUNCTION TO DELETE A RECORD IN THE FILE
//################################################################


void delstud(int n)
{
	reportcard r5;
	ifstream iFile;
	int s=0;
	iFile.open("student.dat",ios::binary);
	ofstream oFile;
	oFile.open("Temp.dat",ios::out);
	iFile.seekg(0,ios::beg);
	while(iFile.read((char *) &r5, sizeof(reportcard)))
	{
		if(r5.retrno()!=n)
		{
			oFile.write((char *) &r5, sizeof(reportcard));
		}
		else
			s=1;
	}
	oFile.close();
	iFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(s==1)
	{
		cout<<"\n\n\tRecord Deleted ..";
	}
	else
	{
		cout<<"\n Record does not exist.. ";
	}
	getch();
}


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    	FUNCTION TO DISPLAY ALL STUDENT GRADE REPORT CARD
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


void result()
{
	reportcard r6;
	ifstream iFile;
	int s=0;
	iFile.open("student.dat",ios::binary);
	cout<<"\n\n\t\tCLASS WISE RESULT \n\n";
	cout<<"====================================================================\n";
	cout<<"R.No       Name        P     C     M     E     CS     %age     Grade"<<endl;
	cout<<"====================================================================\n";
	while(iFile.read((char *) &r6, sizeof(reportcard)))
	{
		s++;
		r6.show_result(s);
	}
	getch();
	iFile.close();
}


//#################################################################
//       	 FUNCTION TO DISPLAY RESULT MENU
//#################################################################


void resultmenu()
{
	int  ch;
	int rn;
	cout<<endl;
	cout<<setw(40)<<"Result MENU"<<endl;
	cout<<setw(20)<<" 1. Class Wise Result"<<endl;
	cout<<setw(20)<<" 2. Student Report Card"<<endl;
	cout<<setw(20)<<" 3. Back to Main Menu"<<endl;
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
		case 1 : result();
			 break;

		case 2 : cout<<"\n\n\tEnter Roll Number of Student : ";
			 cin>>rn;
			 disp_spstud(rn);
			 break;

		case 3 : break;

		default : cout<<"\n Wrong Command..";
	}
}


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    	                INTRODUCTION FUNCTION
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#


void intro()
{       delay(1000);
	cout<<"\n ############################## ";
	delay(1000);
	cout<<"SS MOTA SINGH MODEL SCHOOL”;
	delay(1000);
	cout<<"#############################";
	delay(1000);
	gotoxy(20,20);
	cout<<" REPORT CARD GENERATION";
	delay(1500);
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tPress any key to Contine..........";
	delay(700);
	cout<<"\n\n\n#########################################################################";
	delay(1500);
	cout<<"\n Made By : JASMEEN KAUR";
	cout<<"\n Class: 12-A";
	cout<<"\n School : SS MOTA SINGH MODEL SCHOOL";
	getch();
}


//################################################################
//    	             CHOICE MENU FUNCTION
//################################################################


void entry_menu()
{
	int ch;
	int num;
	clrscr();
	cout<<endl;
	cout<<setw(40)<<" ENTRY MENU"<<endl;
	cout<<setw(20)<<" 1.CREATE STUDENT RECORD"<<endl;
	cout<<setw(20)<<" 2.DISPLAY ALL STUDENTS RECORDS"<<endl;
	cout<<setw(20)<<" 3.SEARCH STUDENT RECORD "<<endl;
	cout<<setw(20)<<" 4.MODIFY STUDENT RECORD"<<endl;
	cout<<setw(20)<<" 5.DELETE STUDENT RECORD"<<endl;
	cout<<setw(20)<<" 6.BACK TO MAIN MENU"<<endl;
	cout<<"\n\n\t\t  Please Enter Your Choice (1-6) ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
		case 1 : inputstud();
			 break;

		case 2 : dispstud();
			 break;

		case 3 : cout<<"\n\n\tPlease Enter The roll number ";
			 cin>>num;
			 disp_spstud(num);
			 break;

		case 4 : cout<<"\n\n\tPlease Enter The roll number ";
			 cin>>num;
			 modstud(num);
			 break;

		case 5 : cout<<"\n\n\tPlease Enter The roll number ";
			 cin>>num;
			 delstud(num);
			 break;

		case 6 :
			 break;
		default :
			 cout<<"\n Wrong Command..";
	}
}


//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
//    			END OF PROJECT
//#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
