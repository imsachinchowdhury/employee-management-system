//Employee Management System
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
using namespace std;
class employee
{
private:
    int employee_id,sal,group_id;
    string name,address;
public:
    void menu();
    void insert_record();
    void display_record();
    void search_record();
    void modify_record();
    void delete_record();
    void group_record();
    void search_group();
};z
void login()
{
    p:
    system("cls");
    char ch,i;
    string username,password;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t================================";
    cout<<"\n\n\t\t\t\tLogin Process";
    cout<<"\n\n\t\t\t================================";
    cout<<"\n\n\n Enter User Name : ";
    cin>>username;
    cout<<"\n\n Enter Password : ";
    for(i=1;i<=6;i++)
    {
        ch = getch();
        password += ch;
        cout<<"*";
    }
    if(username == "chowdhurysachin4@gmail.com" && password=="sachin")
    {
        cout<<"\n\n\n\t\t\t Congratulation Login successfully....";
        cout<<"\n\n\n\n\t\t\t\t\t Loading";
        for(i=1;i<6;i++)
        {
            Sleep(500);
            cout<<".";
        }
    }
    else if(username != "chowdhurysachin4@gmail.com" && password=="sachin")
    {
        cout<<"\n\n\nYour User Name is Wrong....";
        getch();
        goto p;
    }
    else if(username == "chowdhurysachin4@gmail.com"&& password !="sachin")
    {
        cout<<"\n\n\nYour Password is Wrong....";
        getch();
        goto p;
    }
    else
    {
       cout<<"\n\n\nYour User Name and Password Both are Wrong....";
       getch();
       exit(0);
    }
}
void intro()
{
    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t\tMy Best Friend";
    cout<<"\n\n\t\t\t\t 1.Subhajit Bhattacharya";
    cout<<"\n\n\t\t\t\t 2.Atanu Chokrabarty";
    cout<<"\n\n\t\t\t\t 3.subrata Mandal";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    getch();
    system("cls");
     cout<<"\n\n\n\n\n";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t\t  Employee Management System";
    cout<<"\n\n\t\t\t\t\tVersion : 1.1";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    getch();
    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t\t\tIntroduction";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\t\t\tName    : Sachin Chowdhury";
    cout<<"\n\t\t\tCourse  : Btech";
    cout<<"\n\t\t\tSection : CSE-1";
    cout<<"\n\t\t\tCollege : Dr B C Roy Engineering College";
    cout<<"\n\t\t\tRoll    : 12000119065";
    cout<<"\n\t\t\tStream  : Computer Science and Engineering";
    cout<<"\n\n\t\t\t=========================================";
    cout<<"\n\n\t\t\t=========================================";
    getch();

}
void employee::menu()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t\t\t\t Control Panel";
    cout<<"\n\n\n 1. Insert Record";
    cout<<"\n 2. Display Record";
    cout<<"\n 3. Search Record";
    cout<<"\n 4. Modify Record";
    cout<<"\n 5.  Delete Record";
    cout<<"\n 6. Group Record";
    cout<<"\n 7. Search Group";
    cout<<"\n 8.  Exit";
    cout<<"\n  Your Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        insert_record();
        break;
    case 2:
        display_record();
        break;
    case 3:
        search_record();
        break;
    case 4:
        modify_record();
        break;
    case 5:
        delete_record();
        break;
    case 6:
        group_record();
        break;
    case 7:
        search_group();
        break;
    case 8:
        exit(0);
    default:
        cout<<" Your Choose  is Invalid Please try Again...";

    }
    getch();
    goto p;
}
void employee::insert_record()
{
    system("cls");
    fstream file,file1;
    cout<<"\n\n\n\t\t\t\t Insert Record";
    cout<<"\n\n\n Employee ID : ";
    cin>>employee_id;
    cout<<"\n\n\t\t\t  Employee Name : ";
    cin>>name;
    cout<<"\n\n Employee Sallary : ";
    cin>>sal;
    cout<<"\n\n\t\t\t Employee Address : ";
    cin>>address;
    cout<<"\n\n Employee Group ID: ";
    cin>>group_id;
    file.open("employee.txt",ios::out|ios::app);
    file<<" "<<employee_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<endl;
    file.close();
    file1.open("group.txt",ios::out|ios::app);
    file1<<" "<<group_id<<" "<<employee_id<<" "<<sal<<endl;
    file1.close();
    cout<<"\n\n\n\t\t\t\t New record Insert Successfully";
}
void employee::display_record()
{
    system("cls");
    //here we display employee record;
    fstream file;
    cout<<"\n\n\t\t\t\t Display Record";
    //here we open file for read operation
    file.open("employee.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n File Opening Error...";
        getch();
        menu();
    }

    file>>employee_id>>name>>sal>>address>>group_id;
    while(!file.eof())//eof->end of file
    {
        cout<<"\n\n\n\n Employee ID :"<<employee_id;
        cout<<"\n\n\t\t Employee Name :"<<name;
        cout<<"\n\n\t\t Employee Salary :"<<sal;
        cout<<"\n\n\t\t Employee Address :"<<address;
        cout<<"\n\n\t\t Group_ID :"<<group_id;
        file>>employee_id>>name>>sal>>address>>group_id;
    }
    file.close();
}
void employee::search_record()
{
    system("cls");
    fstream file;
    int emp_id,flag=0;
    cout<<"\n\n\t\t\t\tSearch Record ";
    file.open("employee.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n File opening Error";
        getch();
        menu();
    }
    cout<<"\n\n Employee ID for Search : ";
    cin>>emp_id;//take an input which employee i found
    file>>employee_id>>name>>sal>>address>>group_id;
    while(!file.eof())//eof->end of file
    {
        if(emp_id==employee_id)
        {
            system("cls");
            cout<<"\n\n\t\t\t\t\t Search Record : ";
            cout<<"\n\n Employee ID :"<<employee_id;
            cout<<"\n Employee Name :"<<name;
            cout<<"\n Employee Salary :"<<sal;
            cout<<"\n Employee Address :"<<address;
            cout<<"\n Group_ID :"<<group_id;
            flag++;
        }
        file>>employee_id>>name>>sal>>address>>group_id;
    }
    file.close();
    if(flag==0)
    {
        cout<<"\n\nEmployee ID Can't Found ";
    }
}
void employee::modify_record()
{
        system("cls");
        int test_id,update_sal,flag=0;
        string update_name,update_address;
        fstream file,file1,file2,file3;
        cout<<"\n\n\t\t\t\Modify Record";
        file.open("employee.txt",ios::in);
        file1.open("group.txt",ios::in);
        if(!file)
        {
            cout<<"\n\nFile opening Error";
            getch();
            menu();
        }
        cout<<"\n\nEmployee ID for modify : ";
        cin>>test_id;
        file2.open("employee1.txt",ios::out|ios::app);
        file>>employee_id>>name>>sal>>address>>group_id;
        while(!file.eof())
        {
            if(test_id == employee_id)
            {
                system("cls");
                cout<<"\n\n\t\t\t\t Modify Record";
                cout<<"\n\n\n Employee Name : ";
                cin>>update_name;
                cout<<"\n\n\t\t\t  Employee Sallary : ";
                cin>>update_sal;
                cout<<"\n\n Employee Address : ";
                cin>>update_address;
                //here we send the data into new file ;
                file2<<" "<<employee_id<<" "<<update_name<<" "<<update_sal<<" "<<update_address<<" "<<group_id<<endl;
                flag=1;
            }
            else
            {

                 file2<<" "<<employee_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<endl;

            }
              file>>employee_id>>name>>sal>>address>>group_id;
        }
        file.close();
        file2.close();
        remove("employee.txt");
        rename("employee1.txt","employee.txt");

        //here we Update group file
        file3.open("group1.txt",ios::out|ios::app);
        file1>>group_id>>employee_id>>sal;
        while(!file1.eof())
        {
            if(test_id == employee_id)
            {
                file3<<" "<<group_id<<" "<<employee_id<<" "<<update_sal<<endl;
            }
            else
            {
               file3<<" "<<group_id<<" "<<employee_id<<" "<<sal<<endl;
            }
            file1>>group_id>>employee_id>>sal;
        }
        file1.close();
        file3.close();
        remove("group.txt");
        rename("group1.txt","group.txt");
        if(flag==0)
        {
            cout<<"\n\n\t\t\t\tEmployee ID can't found.... ";
        }
        else
        {
            cout<<"\n\n\t\t\t\t\tRecord Modifyed Successfully...";
        }

}
void employee::delete_record()
{
    system("cls");
    int test_id,flag=0;
    fstream file,file1,file2,file3;
    cout<<"\n\n\t\t\t\t Delete Record ";
    file.open("employee.txt",ios::in);
    file1.open("group.txt",ios::in);
    if(!file || !file1)
    {
        cout<<"File opening Error...";
        getch();
        menu();
    }
    cout<<"\n\n Employee Id For Delete : ";
    cin>>test_id;
    file2.open("employee1.txt",ios::out|ios::app);
    file>>employee_id>>name>>sal>>address>>group_id;//fetch the data
    while(!file.eof())
    {
        if(employee_id==test_id)
        {
            cout<<"\n\n Record Delete Sucessfully....";
            flag++;
        }
        else
        {

            file2<<" "<<employee_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<endl;

        }
            file>>employee_id>>name>>sal>>address>>group_id;
    }
    file.close();
    file2.close();
    remove("employee.txt");
    rename("employee1.txt","employee.txt");
    file3.open("group.txt",ios::out|ios::app);
     file1>>group_id>>employee_id>>sal;
    while(!file.eof())
    {
        if(test_id != employee_id)
        {
            file3<<" "<<group_id<<" "<<employee_id<<" "<<sal<<endl;

        }
         file1>>group_id>>employee_id>>sal;
    }
    file1.close();
    file3.close();
        remove("group.txt");
        rename("group1.txt","group.txt");
        if(flag==0)
        {
            cout<<"\n\n\t\t\t\tEmployee ID can't found.... ";
        }
        else
        {
            cout<<"\n\n\t\t\t\t\tRecord Modifyed Successfully...";
        }

}
void employee:: group_record()
{
    system("cls");
    fstream file;
    cout<<"\n\n\t\t\t\tGroup Record";
    file.open("group.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile Opening Error....";
        getch();
        menu();
    }
    file>>group_id>>employee_id>>sal;//here we fatch data
    while(!file.eof())
    {
        cout<<"\n\n\n\n Group ID : "<<group_id;
        cout<<"\nEmployee ID : "<<employee_id;
        cout<<"\nEmployee Sallary : "<<sal;
        file>>group_id>>employee_id>>sal;
    }
    file.close();
}
//bassically here we check how many employee are there in that  group which you want
void employee::search_group()
{
   system("cls");
   int test_id,flag=0,total_employee=0,sal_count=0;
   fstream file;
   cout<<"\n\n\t\t\t\t\t Search Group Record ";
   file.open("group.txt",ios::in);
   if(!file)
   {
       cout<<"\n\n File opening Error....";
       getch();
       menu();
   }
   cout<<"\n\n Group ID For Search : ";
   cin>>test_id;
   system("cls");
   cout<<"\n\n\t\t\t\t\t\t Search Group Record";
   file>>group_id>>employee_id>>sal;
   while(!file.eof())
   {
       if(test_id==group_id)
       {
           cout<<"\n\n\n\n Group ID : "<<group_id;
           cout<<"\n Employee ID : "<<employee_id;
           cout<<"\n Employee Salary : "<<sal;
           flag++;
           total_employee++;
           sal_count += sal;
       }
        file>>group_id>>employee_id>>sal;
   }
   file.close();
   if(flag!=0)
   {
       cout<<"\n\n\n Group ID : "<<test_id;
       cout<<"\nTotal Employees : "<<total_employee;
       cout<<"\nTotal sallary : "<<sal_count;
   }
   else
   {
       cout<<"\n\n Group ID can't Found : ";
   }

}
int main()
{
    employee e;
    login();
    intro();
    e.menu();
}
