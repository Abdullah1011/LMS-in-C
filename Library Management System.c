
//This are the header file
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

//list of global variable
char choice;
FILE *login;
char findBook;
char password[10];
int x = 15;

//-----------------------------Main Interface functions-----------------------------------------------------
int main(){
    SetConsoleTitle("Library Management System by winners");
    system("cls");window();
    gotoxy(34,4);printf("Login Area");
    gotoxy(20,10);printf("1. Admin");
    gotoxy(45,10);printf("2. User");
    gotoxy(20,12);printf("3. Developer Info");
    gotoxy(45,12);printf("9. Exit");
    gotoxy(15,23);printf("Enter your choice: ");
    choice  = getche(); // input from keyboard
    system("cls");      //use to clear windows
    window();           // for title message
    switch(choice)
    {
    case '1':
    pass(); adminMain();
    break;

    case '2':
    u_pass();
    break;

    case '3':
    developer();
    break;

    case '9':
    finish();
    break;

    default :
    gotoxy(20,17);printf("wrong! input --- Press Again");
    main();
    };
    return 0;
}

int adminMain(void){
    system("cls"); window();
    gotoxy(32,4);printf("Admin Workspace");
    gotoxy(15,10);printf("1. Book Info");
    gotoxy(35,10);printf("2. User Info");
    gotoxy(15,12);printf("3. Change User Password");
    gotoxy(55,10);printf("8. Back");
    gotoxy(55,12);printf("9. Exit");
    gotoxy(15,23);printf("Enter your choice: ");
    choice  = getche();

    switch(choice)
    {
    case '1':
    adminMain_book();
    break;

    case '2':
    adminMain_user();
    break;

    case '3':
    change_A_pass();
    break;

    case '8':
    main();
    break;

    case '9':
    finish();
    break;

    default :
    adminMain();
    };
}

int adminMain_book(void){
    while(1){
        system("cls"); window();
        gotoxy(35,4);printf("Admin Area");
        gotoxy(x,6);printf("1. Add Book");
        gotoxy(x,8);printf("2. Search Book");
        gotoxy(x,10);printf("3. Modify Book Record");
        gotoxy(x,12);printf("4. Delete Book Record");
        gotoxy(x,14);printf("5. View book list");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();

        switch(choice){
            case '1':
                add_books();
                break;
            case '2':
                search_books();
                break;
            case '3':
                edit_books();
                break;
            case '4':
                delete_books();
                break;
            case '5':
                view_books();
                break;
            case '8':
                system("cls"); adminMain();
                break;
            case '9':
                finish();
                break;
            default:
                break;
        };
    };

}

int adminMain_user(void){
    while(1){
	system("cls"); window();
        gotoxy(35,4);printf("Admin Area");
        gotoxy(x,6);printf("1. Add User");
        gotoxy(x,8);printf("2. Search User");
        gotoxy(x,10);printf("3. Modify User Record");
        gotoxy(x,12);printf("4. Delete User Record");
        gotoxy(x,14);printf("5. View All User");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();
        switch(choice){
            case '1':
                add_user();
                break;
            case '2':
                search_user();
                break;
            case '3':
                edit_user();
                break;
            case '4':
                delete_user();
                break;
            case '5':
                view_user();
                break;
            case '8':
                adminMain();
                break;
            case '9':
                finish();
                break;
            default:
                break;
        };
    };
}


int userMain(void){
    while(1){
        system("cls"); window();
        gotoxy(35,4);printf("User Area");
        gotoxy(x,6);printf("1. View Book List");
        gotoxy(x,8);printf("2. Search Book");
        gotoxy(x,10);printf("3. View All User info");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();

        switch(choice){
            case '1':
                view_books();
                break;
            case '2':
                search_books();
                break;
            case '3':
                view_user();
                break;
            case '8':
                system("cls");
                main();
                break;
            case '9':
                finish();
                break;
            default:
                main();
                break;
        };
    };
}

//-----------------------------------------------------------------------------------------------



//-----------------------------General Function-----------------------------------------------------
COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
int gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int developer(){       // function for show Developer Info
    system("cls"); window();
    gotoxy(20,6);printf("Design and Developed by....");
    gotoxy(25,8);printf("\xB2\xB2\xB2\xB2\xB2   Abdullah Al Mizan");
    gotoxy(25,10);printf("\xB2\xB2\xB2\xB2\xB2   Tahsir Ahmed Munna");
    gotoxy(25,12);printf("\xB2\xB2\xB2\xB2\xB2   Sadia Islam Soma");
    gotoxy(20,15);printf("Supervised by....");
    gotoxy(25,17);printf("\xB2\xB2\xB2\xB2\xB2   Md. Mijanur Rahman");
    gotoxy(20,20);printf("Software Engineering Dept. DIU)");
    getch(); main();
}

int window(){          // function for show software info altime
    gotoxy(15,1); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(35,2);printf("SWE, DIU");
    gotoxy(5,3);printf("______________________________________________________________________");
 }

int change_A_pass(){    // function for Admin Password change
    system("cls"); window();
    FILE *login;
    char old_pass[10], new_pass[10];
    gotoxy(15,10);printf("Enter Old password: ");
    get_password(old_pass);
    gotoxy(15,12);printf("Enter New password: ");
    get_password(new_pass);
    login = fopen("password.dat","rb+");
    while(fread(&password,sizeof(password),1,login)==1){
        if(strcmp(old_pass,password)==0){
            strcpy(password,new_pass);
            fseek(login,-sizeof(password),SEEK_CUR);
            fwrite(&password,sizeof(password),1,login);
            fclose(login);
            gotoxy(15,15);printf("Password sucessfully changed! ");
        }else{
            gotoxy(15,15);printf("Password changing process failed!");
        }
    }
    gotoxy(15,23);printf("press any key to go back..");
    getch(); system("cls"); window(); adminMain();
}

int finish(){          // function to Exit Message
    system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    system("cls");window(); main();
    }
    else{
    system("cls"); window();
    gotoxy(15,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(21,12);printf("Department of Software Enginnering");
    gotoxy(x,21);printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
    }
}

int pass(){            // function for Admin Password
    login = fopen("password.dat","rb");
    if(login == NULL){
        gotoxy(10,9);printf("Database Do not exits. Be an adminstrator. Sign Up");
        adminsignup();
    }else{
        adminsignin();
    }
}

int u_pass(){          // function for User Password
    system("cls"); window();
    gotoxy(15,7);printf("To Enter User Area need your Library ID");
    gotoxy(15,9);printf("Do you have Library ID(Y/N): ");
    if(getch()=='n'){
    gotoxy(15,10);printf("please contact with Library Administrator for your Library ID");
    getch(); system("cls"); window(); main();
    }
    else
    {
    user_pass();
    }
}

int adminsignup(){     // function for save admin Pass
    char temp[10];
    login = fopen("password.dat","wb");
    gotoxy(10,10);printf("Enter password: ");
    get_password(password);
    gotoxy(10,11);printf("Re Enter Password: ");
    get_password(temp);
    while(strcmp(password,temp)!=0){
        gotoxy(10,10);printf("Password did not matched! Enter again");
        gotoxy(10,11);printf("Enter password: ");
        get_password(password);
        gotoxy(10,12);printf("Re Enter Password: ");
        get_password(temp);
        system("cls");
    }
    fwrite(&password,sizeof(password),1,login);
    fclose(login);
    system("cls"); window();
}


int adminsignin(){     // function for Admin Login part
    char temp[10];
    login = fopen("password.dat","rb");
    gotoxy(15,10);printf("Enter password: ");
    get_password(temp);
    while(fread(&password, sizeof(password),1,login)==1){
        while(strcmp(temp,password)!=0){
            system("cls"); window();
            gotoxy(15,10); printf("Password did not match!---Enter Again: ");
            get_password(temp);
        }
        gotoxy(15,12);printf("Password Match");
        break;
    }
    fclose(login);
    Sleep(1000);
    system("cls");window();
}

int get_password(char* pass){  // function for Password
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}
//--------------------------------------------------------------------------------------------

//--------------------------Book Releted Function-------------------------------------------------
struct BOOK             //Structure variable for BOOK
{
    int id;
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int rackno;
    char *cat;
};
struct BOOK book;

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};

int add_books(void){    //funtion for adding books
	system("cls");window();
	FILE *fp;
	int i, choice;
	system("cls"); window(); add_window();
	gotoxy(x,19); printf("Enter your choice:");
	scanf("%d", &choice);
	if(choice==7)
        adminMain_book() ;
	system("cls"); window();
	fp = fopen("Record.dat","ab+");
	if(getdata(choice) == 1){
        book.cat=catagories[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&book,sizeof(book),1,fp);
        fclose(fp);
        gotoxy(x,17);printf("The record is sucessfully saved");
        gotoxy(x,19);printf("Save any more?(Y / N):");
        if(getch()=='n'){
            system("cls"); adminMain_book();
        }else{
            add_books();
        }
    }
    fclose(fp);
}

int add_window(){      //Function for Books Catagory Interface
    system("cls"); window();
    gotoxy(25,6);printf("******SELECT CATEGOIES******");
	gotoxy(x,9);printf("1. Computer");
	gotoxy(x,10);printf("2. Electronics");
	gotoxy(x,11);printf("3. Electrical");
	gotoxy(x,12);printf("4. Civil");
	gotoxy(x,13);printf("5. Mechanical");
	gotoxy(x,14);printf("6. Architecture");
	gotoxy(x,16);printf("7. Back");
}

int getdata(int choice){
    int x1 = 30; int bookID;
	gotoxy(x,7);printf("Enter the Information Bellow");
	gotoxy(x,9);printf("Category:");  gotoxy(x1,9);printf("%s",catagories[choice-1]);
	gotoxy(x,10);printf("Book ID:");  gotoxy(x1,10);scanf("%d",&bookID);

	 if(book.id==bookID){
                gotoxy(x,11);printf("Id is already Exits");
                getch(); add_books();
                }

	book.id=bookID;
	gotoxy(x,11);printf("Book Name:"); gotoxy(x1,11);scanf("%s",book.name);
	gotoxy(x,12);printf("Author:");    gotoxy(x1,12);scanf("%s",book.Author);
	gotoxy(x,13);printf("Quantity:");  gotoxy(x1,13);scanf("%d",&book.quantity);
	gotoxy(x,14);printf("Price:");     gotoxy(x1,14);scanf("%f",&book.Price);
	gotoxy(x,15);printf("Rack No:");   gotoxy(x1,15);scanf("%d",&book.rackno);
	return 1;
}

int checkid(int t)      //Function to check ID is exist or not
{
    FILE *temp;
	temp = fopen("Record.dat","rb+");
	while(fread(&book,sizeof(book),1,temp)==1)
        if(book.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;

}


int edit_books()       //Function to Edit Books info
{
    system("cls");window();
	FILE *fp;
	int c=0,d;
	gotoxy(27,6);printf("****Edit Book Section****");
	while(1)
	{
		gotoxy(x,8);printf("Enter Book Id to edit:");scanf("%d",&d);
		fp=fopen("uRecord.dat","rb+");
		while(fread(&book,sizeof(book),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(x,9);printf("The book is availble");
				gotoxy(x,10);printf("The Book ID:%d",book.id);
				gotoxy(x,11);printf("New name:");scanf("%s",book.name);
				gotoxy(x,12);printf("New Author:");scanf("%s",book.Author);
				gotoxy(x,13);printf("New quantity:");scanf("%d",&book.quantity);
				gotoxy(x,14);printf("New price:");scanf("%f",&book.Price);
				gotoxy(x,15);printf("New rackno:");scanf("%d",&book.rackno);
				gotoxy(x,16);printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(book),0);
				fwrite(&book,sizeof(book),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(x,11);printf("No record found");
			}
		}

    gotoxy(x,18);printf("Modify another Record?(Y/N)");
    if(getch()=='y'){
        edit_books();
    }
    else
        adminMain_user();
	}
}



int search_books(){    //Function to search books
    system("cls"); window();
    gotoxy(25,7);printf("********Search Books********");
    gotoxy(x,10);printf("1. Search By ID");
    gotoxy(x,12);printf("2. Search By Name");
    gotoxy(x,16);printf("Enter Your Choice: ");
    switch(getch())
    {
        case '1':
            searchByID();
            break;
        case '2':
            searchByName();
            break;
        default :
            getch();search_books();
    }
}

int searchByID(){      //Function to search books by given ID
    system("cls"); window();
    int id; FILE *fp;
    gotoxy(25,7);printf("*****Search Books By Id*****");
    gotoxy(x,9);printf("Enter the book id:");scanf("%d",&id);
    int findBook = 0;
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==id){
            Sleep(2);
            gotoxy(x,11);printf("The Book is available");
            gotoxy(x,13);printf("\xB2 ID:%d",book.id);
            gotoxy(x,14);printf("\xB2 Name:%s",book.name);
            gotoxy(x,15);printf("\xB2 Author:%s ",book.Author);
            gotoxy(x,16);printf("\xB2 Qantity:%d ",book.quantity);
            gotoxy(x,17);printf("\xB2 Price:%.2f",book.Price);
            gotoxy(x,18);printf("\xB2 Rack No:%d ",book.rackno);
            findBook = 1;
        }
    }
    if(findBook == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchByID();
    else
    system("cls");window();
}

int searchByName(){    //Function to search books by using Books name
    system("cls");window();
    char s[15];
    int d=0;
    FILE *fp;
    gotoxy(25,7);printf("****Search Books By Name****");
    gotoxy(x,9);printf("Enter Book Name:");scanf("%s",s);
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(strcmp(book.name,(s))==0){ //checks whether book.name is equal to s or not
            gotoxy(x,11);printf("The Book is available");
            gotoxy(x,13);printf("\xB2 ID:%d",book.id);
            gotoxy(x,14);printf("\xB2 Name:%s",book.name);
            gotoxy(x,15);printf("\xB2 Author:%s",book.Author);
            gotoxy(x,16);printf("\xB2 Qantity:%d",book.quantity);
            gotoxy(x,17);printf("\xB2 Price:Rs.%.2f",book.Price);
            gotoxy(x,18);printf("\xB2 Rack No:%d ",book.rackno);
            d++;
        }
    }
    if(d==0){
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
    searchByName();
    else
    system("cls");window();
}

int delete_books(){    //function that delete  record form Database
    system("cls"); window();
    FILE *ft,*fp;
    char another;
    int d,findBook = 0;
    while(another = 'y'){  //infinite loop
        gotoxy(25,7);printf("********BOOK DELETE********");
        gotoxy(x,9);printf("Enter the Book ID to  delete:"); scanf("%d",&d);
        fp = fopen("Record.dat","rb+");
        while(fread(&book,sizeof(book),1,fp)==1){
            if(book.id==d){
                gotoxy(x,11);printf("The book record is available");
                gotoxy(x,13);printf("Book name is %s",book.name);
                gotoxy(x,14);printf("Rack No. is %d",book.rackno);
                findBook = 1;
                gotoxy(x,16);printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'){
                    ft=fopen("test.dat","wb");  //temporary file for delete
                    rewind(fp);
                    while(fread(&book,sizeof(book),1,fp)==1){
                        if(book.id!=d){
                            fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Record.dat");
                    rename("test.dat","Record.dat"); //copy all item from temporary file to fp except that
                                        //we want to delete
                    gotoxy(x,17);printf("The record is sucessfully deleted");
                }
            }
        }
        if(findBook == 0){
            gotoxy(x,11);printf("No record is found");
        }

        gotoxy(x,18);printf("Delete another record?(Y/N)");
        if(getch()=='y'){
            delete_books();
        }
        else
            adminMain_book();
    }
}

int view_books()   //I use this function to view all books info
{
    int j;
    system("cls");window();
    FILE *fp;
    gotoxy(5,5);printf("*********************************Book List****************************");
    gotoxy(5,6);printf(" CATEGORY      ID      BOOK NAME       AUTHOR     QTY   PRICE   RackNo");
    j=8;
    fp=fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        gotoxy(5,j);printf("%s",book.cat);
        gotoxy(19,j);printf("%d",book.id);
        gotoxy(27,j);printf("%s",book.name);
        gotoxy(44,j);printf("%s",book.Author);
        gotoxy(56,j);printf("%d",book.quantity);
        gotoxy(61,j);printf("%.2f",book.Price);
        gotoxy(71,j);printf("%d",book.rackno);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    getch(); system("cls"); window();
}
//--------------------------------------------------------------------------------------------

//------------------------------User Releted Function for Admin-----------------------------------------------------
struct USER             //Structure variable for User
{
    int id;
    char name[20];
    char pass[20];
    int mobile;
    float fee;
    int age;
    char *cat;
};
struct USER user;

char catagories_u[][15]={"Student","Teacher","Others"};

int add_window_u(){      //Function for user Catagory Interface
    system("cls"); window();
    gotoxy(25,6);printf("******SELECT CATEGOIES******");
	gotoxy(x,9);printf("1. Student");
	gotoxy(x,11);printf("2. Teacher");
	gotoxy(x,13);printf("3. Others");
	gotoxy(x,15);printf("7. Back");
}


int add_user(void){    //funtion for adding User
	FILE *fp;
	int i, choice;
	system("cls");window();
	add_window_u();
	gotoxy(x,19);printf("Enter your choice:");scanf("%d", &choice);
	if(choice==7)
        adminMain_user() ;
	system("cls");window();
	fp = fopen("uRecord.dat","ab+");
	if(getdata_user(choice) == 1){
        user.cat=catagories_u[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&user,sizeof(user),1,fp);
        fclose(fp);
        gotoxy(x,17);printf("The record is sucessfully saved");
        gotoxy(x,19);printf("Save any more?(Y / N):");
        if(getch()=='n'){
            system("cls"); window(); adminMain_user();
        }else{
            add_user();
        }
    }
    fclose(fp);
}




int getdata_user(int choice)
{
    int x1 = 30;
	int userID;
	gotoxy(x,7);printf("Enter the Information Bellow");
	gotoxy(x,9);printf("Category:");  gotoxy(x1,9);printf("%s",catagories_u[choice-1]);
	gotoxy(x,10);printf("User ID:");  gotoxy(x1,10);scanf("%d",&userID);

            if(user.id==userID){
                gotoxy(x,11);printf("Id is already Exits");
                getch(); add_user;
                }

	user.id=userID;
	gotoxy(x,11);printf("User Name:");  gotoxy(x1,11);scanf("%s",user.name);
	gotoxy(x,12);printf("Password:");gotoxy(x1,12);scanf("%s",user.pass);
	gotoxy(x,13);printf("Mobile:");     gotoxy(x1,13);scanf("%d",&user.mobile);
	gotoxy(x,14);printf("Fee:");        gotoxy(x1,14);scanf("%f",&user.fee);
	gotoxy(x,15);printf("Age:");        gotoxy(x1,15);scanf("%d",&user.age);
	return 1;
}









int checkid_user(int t)      //Function to check ID is exist or not
{
    FILE *temp;
	temp = fopen("uRecord.dat","rb+");
	while(fread(&user,sizeof(user),1,temp)==1)
        if(user.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;

}

int edit_user()       //Function to Edit User info
{
    system("cls");window();
	FILE *fp;
	int c=0,d;
	gotoxy(27,6);printf("****Edit User Section****");
	while(1)
	{
		gotoxy(x,8);printf("Enter User Id to edit:");scanf("%d",&d);
		fp=fopen("uRecord.dat","rb+");
		while(fread(&user,sizeof(user),1,fp)==1)
		{
			if(checkid_user(d)==0)
			{
				gotoxy(x,9);printf("The User is availble");
				gotoxy(x,10);printf("The User ID:%d",user.id);
				gotoxy(x,11);printf("New Name:");scanf("%s",user.name);
				gotoxy(x,12);printf("Password:");scanf("%s",user.pass);
				gotoxy(x,13);printf("New Mobile:");scanf("%d",&user.mobile);
				gotoxy(x,14);printf("New Fee:");scanf("%f",&user.fee);
				gotoxy(x,15);printf("New Age:");scanf("%d",&user.age);
				gotoxy(x,16);printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(user),0);
				fwrite(&user,sizeof(user),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(x,11);printf("No record found");
			}
		}

    gotoxy(x,18);printf("Modify another Record?(Y/N)");
    if(getch()=='y'){
        edit_user();
    }
    else
        adminMain_user();
	}
}

int search_user(){    //Function to search user
    system("cls");window();
    gotoxy(27,7);printf("******Search User******");
    gotoxy(x,10);printf("1. Search By ID");
    gotoxy(x,12);printf("2. Search By Name");
    gotoxy(x,14);printf("Enter Your Choice: ");
    switch(getch())
    {
        case '1':
            searchBy_user_ID();
            break;
        case '2':
            searchBy_user_Name();
            break;
        default :
            getch(); search_user();
    }
}

int searchBy_user_ID(){      //Function to search user by given ID
    system("cls");window();
    int id; FILE *fp;
    gotoxy(27,7);printf("****Search User By Id****");
    gotoxy(x,9);printf("Enter the User id:");scanf("%d",&id);
    int findUser = 0;
    fp = fopen("uRecord.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1){
        if(user.id==id){
            Sleep(2);
            gotoxy(x,11);printf("The user is available");
            gotoxy(x,13);printf("\xB2 ID:%d",user.id);
            gotoxy(x,14);printf("\xB2 Name:%s",user.name);
            gotoxy(x,15);printf("\xB2 Password:%s ",user.pass);
            gotoxy(x,16);printf("\xB2 Mobile:%d ",user.mobile);
            gotoxy(x,17);printf("\xB2 Fee:%.2f",user.fee);
            gotoxy(x,18);printf("\xB2 Age:%d ",user.age);

            findUser = 1;
        }
    }
    if(findUser == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchBy_user_ID();
    else
        adminMain_user();
}


int searchBy_user_Name(){    //Function to search user by using Books name
    system("cls");window();
    char s[15];
    int d=0;
    FILE *fp;
    gotoxy(27,7);printf("****Search User By Name****");
    gotoxy(x,9);printf("Enter User Name:");scanf("%s",s);
    fp = fopen("uRecord.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1){
        if(strcmp(user.name,(s))==0){ //checks whether user.name is equal to s or not
            gotoxy(x,11);printf("The User is available");
            gotoxy(x,13);printf("\xB2 ID:%d",user.id);
            gotoxy(x,14);printf("\xB2 Name:%s",user.name);
            gotoxy(x,15);printf("\xB2 Password:%s",user.pass);
            gotoxy(x,16);printf("\xB2 Mobile:%d",user.mobile);
            gotoxy(x,17);printf("\xB2 Fee:%.2f",user.fee);
            gotoxy(x,18);printf("\xB2 Age:%d ",user.age);

            d++;
        }
    }
    if(d==0){

        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchBy_user_Name();
    else
        adminMain_user();
}


int delete_user(){    //function that delete  record form Database
    system("cls");window();
    FILE *ft,*fp;
    char another;
    int d,findUser = 0;
    while(another = 'y'){  //infinite loop
        gotoxy(25,7);printf("********USER DELETE********");
        gotoxy(x,9);printf("Enter the User ID to  delete:");
        scanf("%d",&d);
        fp = fopen("uRecord.dat","rb+");
        while(fread(&user,sizeof(user),1,fp)==1){
            if(user.id==d){
                gotoxy(x,11);printf("The user record is available");
                gotoxy(x,13);printf("User name is %s",user.name);
                gotoxy(x,14);printf("AGE. is %d",user.age);
                findUser = 1;
                gotoxy(x,16);printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'){
                    ft=fopen("utest.dat","wb");  //temporary file for delete
                    rewind(fp);
                    while(fread(&user,sizeof(user),1,fp)==1){
                        if(user.id!=d){
                            fwrite(&user,sizeof(user),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("uRecord.dat");
                    rename("utest.dat","uRecord.dat"); //copy all item from temporary file to fp except that
                                        //we want to delete
                    gotoxy(x,17);printf("The record is sucessfully deleted");
                }
            }
        }
        if(findUser == 0){
            gotoxy(x,11);printf("No record is found");
        }

        gotoxy(x,18);printf("Delete another record?(Y/N)");
        if(getch()=='y'){
            delete_user();
        }
        else
            adminMain_user();
    }
}

int view_user()   //I use this function to view all user info
{
    int j;
    system("cls");window();
    FILE *fp;
    gotoxy(5,5);printf("*********************************User List****************************");
    gotoxy(5,6);printf(" CATEGORY    ID   USER NAME    Password     MOBILE       Age       Fee");
    j=8;
    fp=fopen("uRecord.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1){
        gotoxy(5,j);printf("%s",user.cat);
        gotoxy(17,j);printf("%d",user.id);
        gotoxy(24,j);printf("%s",user.name);
        gotoxy(38,j);printf("%s",user.pass);
        gotoxy(45,j);printf("%d",user.mobile);
        gotoxy(61,j);printf("%d",user.age);
        gotoxy(71,j);printf("%.2f",user.fee);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    getch();system("cls");window();
}
//--------------------------------------------------------------------------------------------


//--------------------------------------User Interface Functon---------------------------------------
int user_pass(){    //function that delete  record form Database
    system("cls"); window();
    FILE *ft,*fp;
    int d,findUser = 0;
    while(1){  //infinite loop
        gotoxy(25,7);printf("********USER Login********");
        gotoxy(x,9);printf("Enter the User ID:");
        scanf("%d",&d);
        fp = fopen("uRecord.dat","rb+");
        while(fread(&user,sizeof(user),1,fp)==1){
            if(user.id==d){
                gotoxy(x,11);printf("The user record is available");
                gotoxy(x,13);printf("User name is %s",user.name);
                gotoxy(x,14);printf("AGE. is %d",user.age);

                char p[20];
                gotoxy(x,16);printf("Enter Your Password:");scanf("%s",p);
                if(strcmp(user.pass,(p))==0){
                gotoxy(x,18); printf("Thank You");
                getch(); userMain();

                }
                else{
                gotoxy(x,18); printf("wrong Password");
                getch();
                main();
                }
            }
        }
        if(findUser == 0){
            gotoxy(x,11);printf("No user is found");
            getch(); system("cls"); window(); main();
        }
    }
}
