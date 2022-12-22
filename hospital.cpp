#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class patient
{
	public:int age;
	public: string name,disease,doctor;
	public:
		void get_info()
		{
			cout<<"Enter Age: ";
			cin>>age;
			cout<<"Enter Name of Patient: ";
			cin>>name;
			cout<<"Enter Disease: ";
			cin>>disease;
			cout<<"Enter Name of Doctor: ";
			cin>>doctor;		
		}
		void show_info()
		{
			cout<<"Age: "<<age<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Disease: "<<disease<<endl;
			cout<<"Doctor: "<<doctor<<endl;
		}
		
};

class department:public patient
{
	public:
		int choice;
		void get_department()
		{
			cout<<"\n1. Neuro";
			cout<<"\n2. Cardio";
			cout<<"\n3. Ortho";
			cout<<"\nEnter Department Choice: ";
			cin>>choice;
		}
		void show_department()
		{
			switch(choice)
			{
				case 1:
					cout<<"Deparment: Neuro"<<endl;
					break;
				case 2:
					cout<<"Deparment: Cardio"<<endl;
					break;
				case 3:
					cout<<"Deparment: Ortho"<<endl;
					break;
			}
		}
};

class bill:public department
{
	public:
		int r_rent,d_charge,m_cost,b_charge,t_charge,m_charge;
		void get_bill()
		{
			cout<<"Enter Room Rent: ";
			cin>>r_rent;
			cout<<"Enter Doctor Charge: ";
			cin>>d_charge;
			cout<<"Enter Medicine Cost: ";
			cin>>m_cost;
			cout<<"Enter Blood Charge: ";
			cin>>b_charge;
			cout<<"Enter Test Charge: ";
			cin>>t_charge;
			cout<<"Enter Miscellenous Charge: ";
			cin>>m_charge;
		}
		void show_bill()
		{
			cout<<"Room Rent: "<<r_rent<<endl;
			cout<<"Doctor Charge: "<<d_charge<<endl;
			cout<<"Medicine Cost: "<<m_cost<<endl;
			cout<<"Blood Charge: "<<b_charge<<endl;
			cout<<"Test Charge: "<<t_charge<<endl;
			cout<<"Miscellenous Charge: "<<m_charge<<endl;
		}
		int total_bill(int r_rent,int d_charge,int m_cost,int b_charge,int t_charge,int m_charge)
		{
			int total;
			total=r_rent+d_charge+m_cost+b_charge+t_charge+m_charge;
			return total;
		}
		int GST(int total)
		{
			int GST=total*0.18;
			return GST;
		}
		friend void total_bill(bill p);
		
		void insurance(int total)
		{
			int insurance;
			cout<<"Enter Insurance: ";
			cin>>insurance;
			int total_insurance=total-insurance;
			if(insurance<0)
			{
				throw insurance;
			}
			else
			{
				cout<<"Total Bill: "<<total_insurance<<endl;
			}
		}
		
};

void total_bill(bill p)
{
	int total;
	total=p.total_bill(p.r_rent,p.d_charge,p.m_cost,p.b_charge,p.t_charge,p.m_charge);
	cout<<"Total : "<<total<<endl;
	int GST=p.GST(total);
	cout<<"GST: "<<GST<<endl;
	int total_gst=total+GST;
	cout<<"Total after GST: "<<total_gst<<endl;
}


int main()
{
	int n,i;
	cout<<"Enter Number Of Patients: ";
	cin>>n;
	bill p[n];
	ofstream fout;
	fout.open("file.txt");
	for(i=0;i<n;i++)
	{
		p[i].get_department();
		p[i].get_info();
		p[i].get_bill();
		total_bill(p[i]);
		try
		{
			p[i].insurance(p[i].total_bill(p[i].r_rent,p[i].d_charge,p[i].m_cost,p[i].b_charge,p[i].t_charge,p[i].m_charge));
		}
		catch(int insurance)
		{
			cout<<"Negative Amount: "<<insurance<<endl;
		}
		fout<<p[i].age<<endl;
		fout<<p[i].name<<endl;
		fout<<p[i].disease<<endl;
		fout<<p[i].doctor<<endl;
		fout<<p[i].choice<<endl;
		fout<<p[i].r_rent<<endl;
		fout<<p[i].d_charge<<endl;
		fout<<p[i].m_cost<<endl;
		fout<<p[i].b_charge<<endl;
		fout<<p[i].t_charge<<endl;
		fout<<p[i].m_charge<<endl;
		
	}
	fout.close();
	ifstream fin;
	fin.open("file.txt");
	for(i=0;i<n;i++)
	{
		fin>>p[i].age;
		fin>>p[i].name;
		fin>>p[i].disease;
		fin>>p[i].doctor;
		fin>>p[i].choice;
		fin>>p[i].r_rent;
		fin>>p[i].d_charge;
		fin>>p[i].m_cost;
		fin>>p[i].b_charge;
		fin>>p[i].t_charge;
		fin>>p[i].m_charge;
		
		p[i].show_info();
		p[i].show_department();
		p[i].show_bill();
		total_bill(p[i]);
		try
		{
			p[i].insurance(p[i].total_bill(p[i].r_rent,p[i].d_charge,p[i].m_cost,p[i].b_charge,p[i].t_charge,p[i].m_charge));
		}
		catch(int insurance)
		{
			cout<<"Negative Amount: "<<insurance<<endl;
		}
		
	}
	return 0;
}

