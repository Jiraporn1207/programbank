#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
char menu();
void Member_Register(int ID[], string name[]);
void Oral_Treatment(int ID[],string treatment[][5], string name[], float pay[][5]);
void Report(int ID[], string treatment[][5], string name[], float pay[][5]);
int main()
{
	int ID[100]={1000,1001,1002,1003,1004};
	char c;
	string name[100]= {"somchai", "ithikorn", "chawanwit", "knyanut","athiphong"}; 
	string treatment[100][5]={{"Tooth Pulling out" , "Tooth Cleaning" , "Fluoride treament" , "Teeth whitening laser" , ""},
	{"Tooth Cleaning"},{"Tooth Pulling out"} , {"Fluoride treament","Tooth Cleaning" },{"Tooth Pulling out","Tooth Cleaning" } };
	float pay[100][5]={	{500,200,2000,1000},
	{200},{500},{2000,200},{500,200}};
	do{
		c= menu();
		if(c == '1')
		{
			Member_Register(ID,name);
		}
		if( c == '2')
		{
			Oral_Treatment(ID,treatment,name,pay);
		}
		if(c == '3')
		{
			Report(ID,treatment,name,pay);
		}
    }while(c != '4');
}
char menu()
{
	char choose;
	cout << "-------------------------- \n";
	cout << "| Welcome to Dental Case | \n";
	cout << "-------------------------- \n";
	cout << " 1. Member Register \n";
	cout << " 2. Oral Treatment \n";
	cout << " 3. Report \n";
	cout << " 4. Exit \n";
	cout << endl;
	cout << "Enter Menu : ";
	cin >> choose;
	system("cls");
	return(choose);
}
void Member_Register(int ID[], string name[])
{
	cout << "==>  -Member Register-  <== " << endl;
	int a;
	bool ko = true;
	cout << "Enter ID : ";
	cin >> a;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(a == ID[i]) // check ID
		{
			cout << "!!! You have already applied !!!" << endl; 
			ko = false;
			cout << endl;
		}
		if(i == 99 && ko == true)
		{
			for(int j = 0 ; j < 100 ; j++)
			{
				if(ID[j] == 0)
				{
					ID[j]=a;
					cout << "Enter name : ";
					cin >> name[j];
					cout << endl;
					break;
				}
			}
		}
	}
}
void Oral_Treatment(int ID[], string treatment[][5],string name[], float pay[][5])
{
	cout << "==>  -Oral Treatment-  <==" << endl;
	int a;
	bool ko = true ;
	char c;
	cout << "Input ID : "; 
	cin >> a;
	cout << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "ID" << setw(20) << "Name" << setw(30) << "Treatment" << setw(20) << "Pay" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	for(int i = 0 ; i < 100 ; i++)
	{
		  if(a == ID[i])
		  {
			cout << setw (4) << ID[i] << setw(20) << name[i] ;
			for(int j = 0 ; j < 5 ; j++)
			{
				if (treatment[i][j] == "") break;
				 cout << setw(30)<< treatment[i][j] << setw(18) << fixed << setprecision(2) << pay[i][j] << endl << setw(24) << " ";
			}
			cout << endl;
			cout << endl;
			cout << " What have you been Oral treatment " << endl;
			cout << " 1. [500$] Tooth Pulling out " << endl;
			cout << " 2. [200$] Tooth Cleaning " << endl;
			cout << " 3. [1000$] Teeth whitening laser" << endl;
			cout << " 4. [2000$] Fluoride treament" << endl;
			cout << endl;
			cout << " Please Enter choose : ";
			cin >> c;
			cout << endl;
			for(int r = 0 ; r < 5 ; r++)
			{
				ko = false;
				if(c=='1')
				{
					if(treatment[i][r] == "")
					{
						treatment[i][r] += "Tooth Pulling out";
						pay[i][r]=500;
						break;
					}
				}
				if(c=='2')
				{
					if(treatment[i][r] == "")
					{
						treatment[i][r] += "Tooth Cleaning";
						pay[i][r]=200;
						break;
					}
				}
				if(c=='3')
				{
					if(treatment[i][r] == "")
					{
						treatment[i][r] += "Teeth whitening laser";
						pay[i][r]=1000;
						break;
					}
				}
				if(c=='4')
				{
					if(treatment[i][r] == "")
					{
						treatment[i][r] += "Fluoride treament";
						pay[i][r]=2000;
						break;
					}
				}
				ko = false;
			}
		}	
	}
	for (int i = 0 ; i < 100 ; i++)
		{
			if (i == 99 && ko == true)
			{
				cout << endl;
				cout << "#### You never have id ####"  << endl;
				cout << endl;
				Member_Register(ID , name);
				break;
			}
		}
}

void Report(int ID[], string treatment[][5], string name[], float pay[][5])
{
	char R;
	int a;
	float total = 0;
	cout << "==>  -REPORT-  <==  " << endl;
	cout << "1. Medical information history report " << endl;
	cout << "2. Report the total amount of money received from the treatment " << endl;
	cout << "3. All patient history and treatment reports " << endl;
	cout << endl;
	cout << "Enter Report : ";
	cin >> R;
	cout << endl;
	if(R == '1')
	{
		cout << "Input ID : ";
		cin >> a;
		for(int i = 0 ; i < 100 ; i++)
		{
			if(a == ID[i])
			{	
				cout << "ID" << setw(20) <<  "Name"  << setw(40) << "Treatment" << endl;
				cout << "-----------------------------------------------------------------" << endl;
				for(int r = 0 ; r < 100 ; r++)
				{
					for(int c = 0 ; c < 5 ; c++)
					{
						if (treatment[i][c] == "")break;
						cout << ID[i] << setw(20) << name[i] << setw(40) << treatment[i][c] << endl;
					}  
					break;
				}
			}
		}
	}
	if(R == '2')
	{
		cout << "Input ID : ";
		cin >> a;
		for(int i = 0 ; i < 100 ; i++)
		{
			if(a == ID[i])
			{
				cout << "--------------------------------------------------------------------------------------" << endl;
				cout << "ID" << setw(22) <<  "Name"  << setw(40) << "Treatment" << setw(20) << "pay" <<  endl;
				cout << "--------------------------------------------------------------------------------------" << endl;
				for(int r = 0 ; r < 100 ; r++)
				{
					for(int c = 0 ; c < 5 ; c++)
					{
						if (treatment[i][c] == "")break;
						cout << ID[i] << setw(20) << name[i] << setw(40) << treatment[i][c] << setw(20) << fixed << setprecision(2)<< pay[i][c] <<endl;
						total += pay[i][c];
					}
					
	
				cout << "--------------------------------------------------------------------------------------" << endl;
				cout << setw(64) <<"total"<< setw(20) << total << endl;
				break;
				}
			}
		}
	}
	if(R=='3')
	{
		float total2 = 0; 
		cout << "ID" << setw(20) <<  "Name"  << setw(32) << "Treatment" << setw(18) << "Pay" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		for(int i = 0 ; i < 100 ; i++)
		{
			if(ID == 0)break;
			if(name[i] == "")break;
			cout << setw (4) << ID[i] << setw(20) << name[i] ;
			for(int j = 0 ; j < 5 ; j++)
			{
				if (treatment[i][j] == "") break;
				cout << setw(30)<< treatment[i][j] << setw(18) << fixed << setprecision(2) << pay[i][j] << endl << setw(24) << " ";
				total2 += pay[i][j];
			} 
		cout << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		}	
		cout << setw(65) << "Total = " << total2 << endl;
	}
	cout << endl;
}