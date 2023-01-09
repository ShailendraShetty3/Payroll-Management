#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Employer{
    private:
	string name;
	string locations[100];
	string bands[10];
	string dept[10];
    //Employee emp;

	public:
    Employer(){
        int no_loc,no_band,no_dept;
		cout<<"enter the name of the company\n";
        cin>>name;
        cout<<"enter the number of locations the company has\n";
        cin>>no_loc;
        for(int i=0;i<no_loc;i++)
        {
			cout<<"enter the "<<i+1<<" location\n";
            cin>>locations[i];
        }
        cout<<"enter the number of bands the company has\n";
        cin>>no_band;
        for(int i=0;i<no_loc;i++)
        {
			cout<<"enter the "<<i+1<<" band\n";
            cin>>bands[i];
        }
        cout<<"enter the number of departments the company has\n";
        cin>>no_dept;
        for(int i=0;i<no_loc;i++)
        {
			cout<<"enter the "<<i+1<<" department\n";
            cin>>dept[i];
        }
		cout<<"you have successfully entered the company details\n";

    }
};
vector<Employer>employer;

struct Address{
        string door_no;
        string street;
        string area;
        string city;
        int pin;
};

class Employee{
    private:
	string name;
	string gender;
	Address address;
	string location;
	static int counter; 
	int emp_id;
	string dept;
	string emp_type;
	string band;
	string pf_no;
	string acc_no;
	double ctc;
	
	public:
	Employee(string e_name,string e_gender,string e_door_no,string e_street,string e_area,string e_city,int e_pin,string e_loc,string e_dept,string e_emp_type,string e_band,string e_pf_no,string e_acc_no,double e_ctc):name(e_name),gender(e_gender),location(e_loc),dept(e_dept),emp_type(e_emp_type),pf_no(e_pf_no),acc_no(e_acc_no),ctc(e_ctc)
	{
		address.door_no=e_door_no;
		address.street=e_street;
		address.area=e_area;
		address.city=e_city;
		address.pin=e_pin;
		counter++;
		emp_id=counter;
	}
	int get_emp_id()
	{
		return emp_id;
	}
    double get_emp_ctc()
    {
        return ctc;
    }
	void set_emp_name(string name)
	{
		name=name;
	}
	void set_emp_location(string location)
	{
		location=location;
	}
	void set_emp_dept(string dept)
	{
		dept=dept;
	}
	void set_emp_type(string type)
	{
		emp_type=type;
	}
	void set_emp_band(string band)
	{
		band=band;
	}
	void set_emp_account(string acc)
	{
		acc_no=acc;
	}
	void set_emp_ctc(double ctc)
	{
		ctc=ctc;
	}
	
	
	void print_emp_details()
	{
		cout<<"employee id "<<emp_id<<endl;
		cout<<"employee name "<<name<<endl;
		cout<<"gender "<<gender<<endl;
		cout<<"door number "<<address.door_no<<endl;
		cout<<"street "<<address.street<<endl;
		cout<<"area "<<address.area<<endl;
		cout<<"city "<<address.city<<endl;
		cout<<"pin code "<<address.pin<<endl;
		cout<<"location "<<location<<endl;
		cout<<"department "<<dept<<endl;
		cout<<"employment type "<<emp_type<<endl;
		cout<<"Eemployee band "<<band<<endl;
		cout<<"pf number "<<pf_no<<endl;
		cout<<"account number "<<acc_no<<endl;
		cout<<"ctc "<<ctc<<endl;
	}
    //friend class Employer;
};
int Employee::counter=0;


int main()
{
	Employer er;
    string mon,trans_date;
    int eid,mess_bill;  //generate payslip

	vector<Employee> emp;
	string name;
	string gender;
	string doorno;
    string street;
    string area;
    string city;
    int pin;
	string location;
	string dept;
	string emp_type;
	string band;
	string pf_no;
	string acc_no;
	double ctc;
	int opt;
	do
	{
		cout<<"1. add the employee details"<<endl;
		cout<<"2. modify the employee details"<<endl;
		cout<<"3. remove employee details"<<endl;
		cout<<"4. search employee details"<<endl;
		cout<<"5. print all employee's details"<<endl;
		cout<<"6. generate pay slip"<<endl;
		cout<<"7. exit"<<endl;
		cout<<"enter the choice"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				cout<<"enter the name of the employee\n";
				cin>>name;
				cout<<"enter the gender\n";
				cin>>gender;
				cout<<"enter the door no\n";
				cin>>doorno;
				cout<<"enter the street\n";
				cin>>street;
				cout<<"enter the area\n";
				cin>>area;
				cout<<"enter the  city\n";
				cin>>city;
				cout<<"enter the pincode\n";
				cin>>pin;
				cout<<"enter the base location of the employee\n";
				cin>>location;
				cout<<"enter the department of the employee\n";
				cin>>dept;
				cout<<"enter the type of the employee\n";
				cin>>emp_type;
				cout<<"enter the  band of the employee\n";
				cin>>band;
				cout<<"enter the Employee PF no\n";
				cin>>pf_no;
				cout<<"enter the account number of the employee\n";
				cin>>acc_no;
				cout<<"enter the ctc of the employee\n";
				cin>>ctc;
				emp.push_back(Employee(name,gender,doorno,street,area,city,pin,location,dept,emp_type,band,pf_no,acc_no,ctc));
				for(unsigned int i=0;i<emp.size();i++)
				{
					cout<<endl;
					cout<<"employee "<<i+1<<" details\n";
					cout<<endl;
					emp[i].print_emp_details();
					cout<<endl;
				}		
			}
			break;
			case 2:
			{
				int id,flag=0,ch;
				for(unsigned int i=0;i<emp.size();i++)
				{
					cout<<"employee "<<i+1<<" details\n";
					cout<<endl;
					emp[i].print_emp_details();
					cout<<endl;
				}
				cout<<"enter the employee id to modify\n";
				cin>>id;
				unsigned int i;
				for(i=0;i<emp.size();i++)
			    {
					if(emp[i].get_emp_id()==id)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					cout<<"Employee not found\n";
					break;
				}
				else
				{
					string n;
					while(flag==1)
					{
						cout<<"1. modify name"<<endl;
						cout<<"2. modify location"<<endl;
						cout<<"3. modify department"<<endl;
						cout<<"4. modify employee type"<<endl;
						cout<<"5. modify band"<<endl;
						cout<<"6. modify account no"<<endl;
						cout<<"7. modify ctc"<<endl;
						cout<<"8. main menu"<<endl;
						cout<<"enter the choice"<<endl;
						cin>>ch;
						switch (ch)
						{
							case 1:
							{
								cout<<"enter the new name"<<endl;
								cin>>n;
								emp[i].set_emp_name(n);
								
							}
							break;
							case 2:
							{
								cout<<"enter the new location"<<endl;
								cin>>location;
								emp[i].set_emp_location(location);
								
							}
							break;
							case 3:
							{
								cout<<"enter the new department"<<endl;
								cin>>dept;
								emp[i].set_emp_dept(dept);
								
							}
							break;
							case 4:
							{
								cout<<"enter the new employment type"<<endl;
								cin>>emp_type;
								emp[i].set_emp_type(emp_type);
								
							}
							break;
							case 5:
							{
								cout<<"enter the new employee band"<<endl;
								cin>>band;
								emp[i].set_emp_band(band);
								
							}
							break;
							case 6:
							{
								cout<<"enter the new account number"<<endl;
								cin>>acc_no;
								emp[i].set_emp_account(acc_no);
								
							}
							break;
							case 7:
							{
								cout<<"enter the new ctc"<<endl;
								cin>>ctc;
								emp[i].set_emp_ctc(ctc);
								
							}
							break;
							case 8:
							{
								flag=0;
								break;
							}
						}
					}
				}
				for(unsigned int i=0;i<emp.size();i++)
				{
					cout<<endl;
					cout<<"employee "<<i+1<<" details:"<<endl;
					cout<<endl;
					emp[i].print_emp_details();
					cout<<endl;
				}		
			}
			break;
			case 3:
			{
				int id,flag=0;
				cout<<"enter the employee id to be removed"<<endl;
				cin>>id;
				unsigned int i;
				for(i=0;i<emp.size();i++)
			    {
					if(emp[i].get_emp_id()==id)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					cout<<"employee not found."<<endl;
					break;
				}
				else
				{
					cout<<"employee removed is:"<<endl;
					emp[i].print_emp_details();
					emp.erase(emp.begin()+i);
					cout<<"employee removed successfully"<<endl;
					
				}
				
			}
			break;
		    case 4:
			{
				int id,flag=0;
				cout<<"enter the employee id to be searched."<<endl;
				cin>>id;
				unsigned int i;
				for(i=0;i<emp.size();i++)
			    {
					if(emp[i].get_emp_id()==id)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					cout<<"employee not found.\n";
					break;
				}
				else
				{
					cout<<"employee details\n";
					emp[i].print_emp_details();
				}
				
			}
			break;
			case 5:
			{
				cout<<"employee details of all the employees are\n";
				for(unsigned int i=0;i<emp.size();i++)
				{
					cout<<endl;
					cout<<"employee "<<i+1<<" details:"<<endl;
					cout<<endl;
					emp[i].print_emp_details();
					cout<<endl;
				}
				
			}
			break;
            case 6: cout<<"enter the month\n";
                    cin>>mon;
                    cout<<"enter the employee id\n";
                    cin>>eid;
                    cout<<"enter the mess bill\n";
                    cin>>mess_bill;
                    cout<<"enter the transfer date\n";
                    cin>>trans_date;
                    bool flag;
                    int i;
                    double ctc_sal,basic_sal,vpp,pf_sal,oa_sal,income_tax,gross_pay,net_pay;
                    for(i=0;i<emp.size();i++)
                    {
                        if(eid==emp[i].get_emp_id())
                        {
                            flag=true;
                            break;
                        }
                        else{
                            flag=false;
                        }
                    }
                    if(flag==true)
                    {
                        ctc_sal=emp[i].get_emp_ctc();
						//cout<<"ctc here is "<<emp[i].get_emp_ctc()<<endl;
                        basic_sal=emp[i].get_emp_ctc()*(60/100);
                        vpp=emp[i].get_emp_ctc()*(30/100);
                        pf_sal=emp[i].get_emp_ctc()*(5/100);
                        oa_sal=emp[i].get_emp_ctc()*(5/100);
                        if(emp[i].get_emp_ctc()<=5)
                        {
                            income_tax=0;
                        }
                        else if(emp[i].get_emp_ctc()<5 && ctc_sal<=10)
                        {
                            income_tax=emp[i].get_emp_ctc()*(5/100);
                        }
                        else if(emp[i].get_emp_ctc()<10 && emp[i].get_emp_ctc()<=15)
                        {
                            income_tax=emp[i].get_emp_ctc()*(10/100);
                        }
                        else if(emp[i].get_emp_ctc()<15 && emp[i].get_emp_ctc()<=20)
                        {
                            income_tax=emp[i].get_emp_ctc()*(15/100);
                        }
                        else if(ctc_sal<20)
                        {
                            income_tax=emp[i].get_emp_ctc()*(20/100);
                        }
						gross_pay=basic_sal+vpp+pf_sal+pf_sal+oa_sal;
                    	net_pay=basic_sal-income_tax-mess_bill;
						cout<<"the generated payslip is\n";
						cout<<"ctc is "<<emp[i].get_emp_ctc()<<endl;
						cout<<"basic salary is "<<basic_sal<<endl;
						cout<<"variable pay is "<<vpp<<endl;
						cout<<"pf amount is "<<pf_sal<<endl;
						cout<<"other allowance is "<<oa_sal<<endl;
						cout<<"gross pay is "<<gross_pay<<endl;
						cout<<"net pay is "<<net_pay<<endl;
                    }
                    
					else{
						cout<<"employee details are not found\n";
					}
            break;
            case 7: cout<<"exit\n";
                    exit(0);
            default: cout<<"invalid input\n";
            break;
			
		}	
	}while(opt!=7);
    return 0;
}
