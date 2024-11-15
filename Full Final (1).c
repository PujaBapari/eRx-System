#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct meroDate
{
    int mm,dd,yy;
};

int t(void)
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));
    return 0 ;
}

int main()
{
    system("color F9");
    gotoxy(40,5);
    printf("Software Development Capstone Project");
    gotoxy(36,6);
    printf("Electronic prescription(eRx) Management System");
    gotoxy(40,8);
    printf("Developed by: Puja Bapari(222-35-1174)");
     gotoxy(57,9);
    printf("&");
    gotoxy(42,10);
    printf("Mehedi Hasan Rupom(0242220005341142)");
    gotoxy(47,12);
    printf("Press ANY to Continue");
    getch();
    homepage();
    getch();
    return 0;
}

void homepage();
void homepage(void)
{
    system("cls");
    system("color F1");
    gotoxy(38,2);
    printf("Do you want to use this application?");
    gotoxy(50,5);
    printf("1. As a Doctor.");
    gotoxy(50,7);
    printf("2. As a Patient.");
    gotoxy(38,10);
    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        Password();
        break;
    case '2':
        searchinfo();
        break;
    case '0':
        stop();
        break;
    }
}

char password[10]= {"admin"};

void Password();
void Password(void)
{
    system("cls");
    gotoxy(52,3);
    printf(" LOG IN PANEL ");
     gotoxy(34,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    char d[25]=" Password Protected";
    char ch,pass[10];
    int i=0,j;

    gotoxy(32,6);
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("*");
    }
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("%c",d[j]);
    }
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("*");
    }
    gotoxy(50,10);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        gotoxy(50,12);
        printf("Password match");
        gotoxy(45,13);
        printf("Press any key to countinue.....");
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(45,12);
        printf("\aWarning!! Incorrect Password");
        getch();
        Password();
    }
}

void mainmenu(void);
void mainmenu()
{

    system("cls");
    system("color F3");
    int i;
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Patient Disease");
    gotoxy(40,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Patient ID");
    gotoxy(40,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Patient Info");
    gotoxy(40,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View all Prescription");
    gotoxy(40,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Patient Medicine");
    gotoxy(40,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Back to Homepage");
    gotoxy(40,19);
    printf("------------------------------------------");
    gotoxy(20,20);
    t();
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        addptdi();
        break;
    case '2':
        deleteptdi();
        break;
    case '3':
        searchinfo();
        break;
    case '4':
        viewpres();
        break;
    case '5':
        editmedi();
        break;
    case '6':
        homepage();
        break;
    default:
    {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
            mainmenu();
    }
    }
}
FILE *fp,*ft,*fs;
int s;

char catagories[][25]= {"Fever & Cold","Cancer","Allergies","Migration","Gastric","Fungal"};

struct patient
{
    int id;
    char patname[20];
    char mediname[20];
    char takentime[20];
    int dosages;
    int count;
    int duration;
    char *cat;
    int age;
};
struct patient a;
void addptdi(void);
void addptdi(void)
{
    system("cls");
    int i;
    gotoxy(40,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Fever & Cold");
    gotoxy(40,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Cancer");
    gotoxy(40,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Allergies");
    gotoxy(40,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Migration");
    gotoxy(40,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Gastric");
    gotoxy(40,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Fungal");
    gotoxy(40,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
    gotoxy(40,21);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)
        mainmenu() ;
    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(41,14);
        printf("The record is sucessfully saved");
        gotoxy(41,15);
        printf("Save any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else
        system("cls");
        addptdi();
        }
}
int getdata();
int getdata()
{
    int t;
       gotoxy(44,3);
    printf(" Enter the Information Below" );
    gotoxy(42,4);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(42,6);
    printf(" Category:");
    printf("%s",catagories[s-1]);
    gotoxy(43,7);
    printf("Patient ID:");
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe patient id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(43,8);
    printf("Patient Name:");
    scanf("%s",&a.patname);
    gotoxy(43,9);
    printf("Patient Age:");
    scanf("%d",&a.age);
    gotoxy(43,10);
    printf("Medicine Name:");
    scanf("%s",&a.mediname);
    gotoxy(43,11);
    printf("Dosages a day:");
    scanf("%d",&a.dosages);
    gotoxy(43,12);
    printf("Duration:");
    scanf("%d",&a.duration);
    return 1;
}

int checkid(int);
int checkid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}

char findptdi;

void deleteptdi(void);
void deleteptdi(void)
{
    system("cls");
    system("color F4");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(40,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE PATIENTS INFO");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(44,5);
        printf("Enter patient ID to  delete:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                gotoxy(44,7);
                printf("The patient record is available");
                gotoxy(44,8);
                printf("Patient name is: %s",a.patname);
                gotoxy(44,9);
                printf("Patient age is: %d",a.age);
                findptdi='t';
            }
        }
         if(findptdi!='t')
        {
            gotoxy(44,10);
            printf("No record is found modify the search");
            if(getch())
                mainmenu();
        }
        if(findptdi=='t' )
        {
            gotoxy(44,11);
            printf("Do you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("Bibek.dat");
                rename("test.dat","Bibek.dat");
                fp=fopen("Bibek.dat","rb+");
                if(findptdi=='t')
                {
                    gotoxy(30,13);
                    printf("The record is sucessfully deleted");
                    gotoxy(30,14);
                    printf("Delete another record?(Y/N)");
                }
            }
            else
                mainmenu();
            fflush(stdin);
            another=getch();
        }
    }
    gotoxy(10,15);
    mainmenu();
}

void editmedi(void);
void editmedi(void)
{
    system("cls");
    int c=0;
    int d,e;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(0,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 EDIT PATIENTS INFO");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(10,6);
        printf("Enter Patient Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
if(checkid(d)==0)
            {
                gotoxy(10,7);
                printf("The patent is availble");
                gotoxy(10,8);
                printf("The patient ID:%d",a.id);
                gotoxy(10,9);
                printf("Enter new patient name:");
                scanf("%s",&a.patname);
                gotoxy(10,10);
                printf("Enter new Medicine:");
                scanf("%s",&a.mediname);
                gotoxy(10,11);
                printf("Enter new dosages:");
                scanf("%d",&a.dosages);
                gotoxy(10,12);
                printf("Enter new Duration:");
                scanf("%d",&a.duration);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(10,9);
                printf("No record found");
            }
        }
        gotoxy(10,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    returnfunc();
}

void searchinfo(void);
void searchinfo(void)
{
    system("cls");
    int d;
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH PATIENT INFO");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("Enter Patient's ID:");
    scanf("%d",&d);
    gotoxy(40,7);
    printf("Searching........");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {
            delay(2);
            system("cls");
            gotoxy(30,3);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PATIENT PRESCRIPTION");
            printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22,4);
            printf("CATEGORY:");
            gotoxy(22,5);
            printf("PATIENT NAME:");
            gotoxy(22,6);
            printf("AGE:");
            gotoxy(22,7);
            printf("PATIENT ID:");
            gotoxy(22,8);
            printf("MEDICINE NAME:");
            gotoxy(22,9);
            printf("DOSAGES:");
            gotoxy(22,10);
            printf("DURATION:");
            gotoxy(40,4);
            printf("%s",a.cat);
            gotoxy(40,5);
            printf("%s",a.patname);
            gotoxy(40,6);
            printf("%d",a.age);
            gotoxy(40,7);
            printf("%d",a.id);
            gotoxy(40,8);
            printf("%s",a.mediname);
            gotoxy(40,9);
            printf("%d",a.dosages);
            gotoxy(40,10);
            printf("%d",a.duration);
            findptdi='t';
        }
        fclose(fp);
    }
    if(findptdi!='t')
    {

        gotoxy(40,9);
        printf("\xB2");
        gotoxy(58,9);
        printf("\xB2");
        gotoxy(42,9);
        printf("\aNo Record Found");
    }
    gotoxy(40,17);
    printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchinfo();
    else
        homepage();
    fclose(fp);
}

void viewpres(void);
void viewpres(void)
{
    int i=0,j;
    system("cls");
    gotoxy(20,1);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENT PRESCRIPTION INFO");
            printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(2,2);
    printf("CATEGORY      PATIENT NAME     ID      AGE      MEDICINE      DOSAGES  DURATION ");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(18,j);
        printf("%s",a.patname);
        gotoxy(33,j);
        printf("%d",a.id);
        gotoxy(41,j);
        printf("%d",a.age);
        gotoxy(50,j);
        printf("%s",a.mediname);
        gotoxy(66,j);
        printf("%d",a.dosages);
        gotoxy(75,j);
        printf("%d",a.duration);
        printf("\n\n");

        j++;
    }
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}

void returnfunc(void);
void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if(getch()==13) //allow only use of enter
        mainmenu();
    else
        goto a;
}

void stop();
void stop(void)
{
    system("cls");
    gotoxy(36,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLOSE APPLICATION");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,6);
    printf("eRX Management System");
    gotoxy(36,8);
    printf("******************************************");
    gotoxy(36,10);
    printf("******************************************");
    gotoxy(36,11);
    printf("******************************************");
    gotoxy(36,13);
    printf("******************************************");
    gotoxy(30,17);
    printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
}

