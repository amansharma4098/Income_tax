#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class taxpayers
   {
   	 public:
         char name[100],adress[100];
         int AdharNo;
         
        
     	int age;
       void getdetails()
       {
        cout<<"\n Enter taxpayers age     :";
        cin>>age;
        cout<<"\n Enter taxpayers name   : ";
        cin>>name;
        cout<<"\n Enter taxpayers AdharNo     : ";
        cin>>AdharNo;
        cout<<"\ntaxpayers address in details  : ";
        cin>>adress;
       }

    void showdetail()
       {
        cout<<"\nName       : "<<name;
        cout<<"\nAdharNo    : "<<AdharNo;
        cout<<"\nAddress    : "<<adress;
        cout<<"\nAge        : "<<age;
       }
     };

class taxrules:public taxpayers
{	
    public:
	float sal,incometax;
    
    void inform()
    {cout<<"\nenter anual salary in indian rupees      :";
    cin>>sal;
    }
    void checktax()
    {
    if(age<18)
	{
		    cout<<"\ncitizen category    :      minor";
	    	cout<<"\nminor have no tax charges"<<endl;
	}
	if(age>60)
	{
		cout<<"citizen category    :      senior";
	if(sal<300000)
	{
	 	cout<<"NO INCOME TAX payment"<<endl;
	}
	if(sal>=300000&&sal<500000)
	{
	incometax=((sal-300000)/10);
	cout<<"tax to pay   : "<<incometax;
	}
	if(sal>=500000&&sal<1000000)
	{
	incometax=((sal-300000)/5)+50000;
	cout<<"tax to pay   : "<<incometax;
	}
	if(sal>=1000000)
	{
	incometax=((sal-300000)*(4/10))+30000;
	cout<<"tax to pay   : "<<incometax;
	}
    }
if((age>=18)&&(age<=60))
	{ 
	cout<<"\ncitizen category    :      working";
    if(sal<300000)
	{
	cout<<"\nNO INCOME TAX "<<endl;
	}
	if(sal>=300000&&sal<500000)
	{
	incometax=((sal-300000)/10);
	cout<<"\ntax to pay   : "<<incometax;
	}
	if(sal>=500000&&sal<1000000)
	{
	incometax=((sal-300000)/5)+75000;
	cout<<"\ntax to pay   : "<<incometax;
	}
	if(sal>=1000000)
	{
    incometax=((sal-300000)*(4/10))+30000;
	cout<<"\ntax to pay   : "<<incometax;
	}
	}
}
};

class taxcatgary:public taxrules
{
     int memberId;
     public:
     	void payercategary()
     	{
     	cout<<"enter member id      :";
     	cin>>memberId;
     	if(incometax<=30000)
     	{
     		cout<<"taxpayer is from low class \n";
		}
		if((incometax>30000)&&(incometax<=50000))
     	{
     		cout<<"taxpayer is from middle class \n";
		}
		if((incometax>50000)&&(incometax<=100000))
     	{
     		cout<<"taxpayer is from upper class \n";
		}
		if(incometax>100000)
     	{
     		cout<<"taxpayer is from high class \n";
		}
	}
};

main()
{
taxpayers M;
taxrules R;
taxcatgary C;
system("cls");
cout<<"                 ACCORDING TO DIGITAL INDIA SCHEME YOUR MEMBER ID IS ONLY ADHAR NO   "<<endl;
int opt,i,j,n,Id;
char occupation[50];
do
{
cout<<"enter occupation of taxpayer      :";
cin>>occupation;

cout<<"                                   INCOME TAX CALCULATION                "
<<"\n1.Asking for IncomeTax view\n2.Search details of taxpayer\n3.Exit.\n"
<<"\n4.Make your choice   :";
cin>>opt;
switch(opt)
{   
 case 1:
 	cout<<"enter total no of members for calculating tax     :";
 	cin>>j;
        for(i=1;i<=j;i++)
		{
	    cout<<"\n give serial     :";
	    cin>>n;
		cout<<"\n occupation       : "<<occupation<<endl;
		cout<<"\n serial no        :"<<n<<endl;
		if(strcmp(occupation,"farmer")==0)
            {
            M.getdetails();
            M.showdetail();
            R.inform();
            R.checktax();
            cout<<"\n farmers   are under tax free category    :";
            R.incometax=0;
            cout<<"\ntax     :"<<R.incometax;
            C.payercategary();
            }
        else if(strcmp(occupation,"businessman")==0)
            {
            M.getdetails();
            M.showdetail();
            R.inform();
            R.checktax();
            cout<<"\nbusinessman are under taxrule 1     :\n extra  4%  surcharge tax applies";
            R.incometax=R.incometax+(R.incometax/25);
            cout<<"\nfinal tax payment     :"<<R.incometax;
            C.payercategary();
            }
        else if(strcmp(occupation,"doctor")==0)
            {
            M.getdetails();
            M.showdetail();
            R.inform();
            R.checktax();
            cout<<"\ndoctors are under taxrule 2     :\n extra  2.5%  surcharge tax applies";
            R.incometax=R.incometax+(R.incometax/40);
            cout<<"\nfinal tax payment     :"<<R.incometax;
            C.payercategary();
			}
        if(strcmp(occupation,"engineer")==0)
            {
            M.getdetails();
            M.showdetail();
            R.inform();
            R.checktax();
            cout<<"\nbusinessman are under taxrule 3    :\n extra  2%  surcharge tax applies";
            R.incometax=R.incometax+(R.incometax/50);
            cout<<"\nfinal tax payment     :"<<R.incometax;
            C.payercategary();
			}
        if(stricmp(occupation,"burocrate")==0)
        {
        	M.getdetails();
            M.showdetail();
            R.inform();
            R.checktax();
            cout<<"\nbusinessman are under taxrule 3    :\n extra  2%  surcharge tax applies";
            R.incometax=R.incometax+(R.incometax/30);
            cout<<"\nfinal tax payment     :"<<R.incometax;
		    C.payercategary();
		}
	}
		break;
		case 2:
			 cout<<"\n enter id of members regest in incometax  department ";
			 Id=M.AdharNo;
	    break;
	    case 3:
	    break;
	    default:
        cout<<"\n       Wrong choice Try again      :";
        cout<<"\nPress any key to return to main menu...";
        getch();
        break;
			
}

}while(opt<=3);
}


