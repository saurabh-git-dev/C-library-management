#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "help.h"
#include <dos.h>

FILE *fp_add, *ftemp, *fp_issue, *fp_bill;

void blinkp();
int password();
void exiting();
char *date_time(void);
void border();
void border2();
void main_menu();
void add_book();
void add_details();
int view_books();
int search_books();
int edit_books();
int edit_details();
int delete_books();
int issue_portal();
int issuing_books(); //(char *isb->id,char*isb->quantity);
int issued_books();
void return_portal();
int returning_books();
void bill_generate();
int issued_history();
void exiting();

/************************************STRUCTRE OF BOOK DETAILS*************************/
char categories[][15] = {"Engineer", "Medical", "Art Scie", "Finance", "Comics", "Sports", "Others"};
typedef struct
{
    char id[5], name[25], author[20], price[6], quantity[2], rack[5], cat[15];
} book;
book *bk = NULL, *bked = NULL;
;
/************************************END STRUCTRE OF BOOK DETAILS*************************/

/************************************STRUCTRE OF ISSUE BOOK****************************/
typedef struct
{
    char id[5], std_name[15], std_id[8], quantity[2], price[6], bill_id, iss_time[5], ret_time[5];
} issue;
issue *isb = NULL, *ised=NULL;
/************************************END STRUCTRE OF ISSUE BOOK****************************/

/***********************************MAIN FUNCTION**************************************/
main()
{
    system("cls");
    password();
    main_menu();
    return 0;
}
//***********************************END MAIN FUNCTION**************************************/

//*****************************************Password**********************************/

int password()
{
password_:
    int i = 0, option;
    char pass[20], ch, user[10], passwd[] = "code", user_name[] = "saurabh", invalid[] = "Invalid Login Credentials.";
    system("cls");
    border();

    gotoxy(34, 7);
    printf("\x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104");
    gotoxy(34, 8);
    printf("%c     STUDENTS    %c", 260, 260);
    gotoxy(34, 9);
    printf("%c   SEARCH BOOKS  %c", 260, 260);
    gotoxy(34, 10);
    printf("\x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104");

    gotoxy(34, 14);
    printf("\x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104");
    gotoxy(34, 15);
    printf("%c  ADMINISTRATOR  %c", 260, 260);
    gotoxy(34, 16);
    printf("%c      LOGIN      %c", 260, 260);
    gotoxy(34, 17);
    printf("\x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104 \x104");
    //getch();
    gotoxy(30, 20);
    printf("Press STUDENTS-S / ADMIN-A ");
    blinkp();
    option = getch();
    if (option == 65 || option == 97)
    {
    label_login:
        system("cls");
        border();
        gotoxy(42, 6);
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("LOGIN\n");
        gotoxy(38, 10);
        printf("  User   :");
        gotoxy(38, 12);
        printf("Password : ");
        gotoxy(30, 20);

        /*gotoxy(52, 10);
        do
        {
        ch = getch();
        if (i > 0 && ch == 8)
        {
            pass[--i] = '\0';
            printf("\b \b");
        }
        if (ch != 8 && ch != 13)
        {
            printf("%c", ch);
            user[i] = ch;
            i++;
        }
        } while (ch != 13);
        user[i] = '\0';
        i = 0;
        fflush(stdin);
        gotoxy(52, 12);
        do
        {
        ch = getch();
        if (i > 0 && ch == 8)
        {
            pass[--i] = '\0';
            printf("\b \b");
        }
        if (ch != 8 && ch != 13)
        {
            printf("*");
            pass[i] = ch;
            i++;
        }
        } while (ch != 13);
        pass[i] = '\0';*/
        //if ((!strcmp(pass, passwd)) && (!strcmp(user, user_name)))

        gotoxy(36, 16);
        //system("color B");

        printf("loging in");
        blinkp();
        return 0;
        //else
        printf("\a");
        blink(invalid, 40, 14, 5);
        gotoxy(40, 15);
        printf("Press Enter to continue");
        gotoxy(40, 16);
        printf("Else press other keys to exit the application.");
        if ((option = getch()) == 13)
            goto label_login;
        else if (option == 27)
            goto password_;
        else
        {
            system("cls");
            border();
            gotoxy(40, 14);
            printf("Sure to close(Y/N) ");
            blinkp();
            if ((option = getch()) == 89 || option == 121)
                exiting();
            else
                goto password_;
        }
    }
    else if (option == 83 || option == 115)
    {
        view_books();
        goto password_;
    }
    else if (option = 27)
    {
        system("cls");
        border();
        gotoxy(40, 14);
        printf("Sure to close(Y/N) ");
        blinkp();
        if ((option = getch()) == 89 || option == 121)
            exiting();
        else
            goto password_;
    }
    return 0;
}
/*****************************************END_PASSWORD**********************************************/

/****************************************** MAIN_MENU **********************************************/
void main_menu()
{
    int i, option;
    system("cls");
    border();
    gotoxy(62, 2);
    printf("Logout-ESC");
    gotoxy(25, 4);
    printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
    printf(" MAIN MENU ");
    printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
    gotoxy(25, 7);
    printf("1 \xAF SEARCH BOOKS");
    gotoxy(25, 9);
    printf("2 \xAF BOOK ISSUE PORTAL ");
    gotoxy(25, 11);
    printf("3 \xAF BOOK RETURN PORTAL");
    gotoxy(25, 13);
    printf("4 \xAF ISSUED BOOK DETAILS");
    gotoxy(25, 15);
    printf("5 \xAF ADD BOOK DETAILS");
    gotoxy(25, 17);
    printf("6 \xAF EDIT BOOK DETAILS");
    gotoxy(25, 19);
    printf("Choose valid option ");
label_1:
    blinkp();
    option = getch();
    switch (option)
    {
    case 49:
        view_books();
        break;
    case 50:
        issue_portal();
        break;
    case 51:
        return_portal();
        break;
    case 52:
        issued_books();
        break;
    case 53:
        add_book();
        break;
    case 54:
        edit_books();
        break;
    case 55:
        issued_history();
        break;
    case 27:
        password();
        break;
    default:
    {
        gotoxy(45, 19);
        printf("   ");
        gotoxy(25, 20);
        printf("Invalid");
        blinkp();
        printf("Try Again");
        delay(500);
        gotoxy(25, 20);
        printf("                   ");
        gotoxy(45, 19);
        goto label_1;
    }
    }
    main_menu();
}
/*******************************************END Main_menu *****************************************/

/****************************************ADD BOOK DETAILS******************************************/
void add_book()
{
    int i, option;
    system("cls");
    border();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(25, 4);
    printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
    printf(" CATEGORIES ");
    printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
    gotoxy(25, 7);
    printf("1 \xAF Engineering");
    gotoxy(25, 9);
    printf("2 \xAF Medical");
    gotoxy(25, 11);
    printf("3 \xAF Art Science");
    gotoxy(25, 13);
    printf("4 \xAF Finance");
    gotoxy(25, 15);
    printf("5 \xAF Comics");
    gotoxy(25, 17);
    printf("6 \xAF Sports");
    gotoxy(25, 19);
    printf("7 \xAF Others");
    gotoxy(25, 21);
    printf("Choose valid option ");
label_1:
    blinkp();

    option = getch();
    if (option > 48 && option < 56)
    {
    add_detail_label:
        add_details();
        fp_add = fopen("Libraraymanage.txt", "ab+");
        strcpy(bk->cat, categories[option - 49]);
        fwrite(bk, sizeof(book), 1, fp_add);
        // fwrite(cat,sizeof(categories[option-1]),1,fp_add);
        fclose(fp_add);
        free(bk);
        gotoxy(29, 19);
        printf("Data Saved");
        gotoxy(26, 20);
        printf("Want to add more(Y/N) ");
        //printf("%s",bk->cat);
    lable2:
        blinkp();
        option = getch();
        if (option == 89 || option == 120)
        {
            system("cls");
            goto add_detail_label;
        }
        else if (option == 78 || option == 110)
        {
            add_book();
        }
        else
        {
            gotoxy(48, 20);
            printf("   ");
            gotoxy(25, 22);
            printf("Invalid");
            blinkp();
            printf("Try Again");
            delay(500);
            gotoxy(25, 22);
            printf("                   ");
            gotoxy(48, 20);
            goto lable2;
        }
    }
    else if (option == 27)
        main_menu();
    // else if(option == _DEL)
    //system("exit");
    else
    {
        gotoxy(45, 21);
        printf("   ");
        gotoxy(25, 22);
        printf("Invalid");
        blinkp();
        printf("Try Again");
        delay(500);
        gotoxy(25, 22);
        printf("                   ");
        gotoxy(46, 21);
        goto label_1;
    }
}
/****************************************END ADD BOOK DETAILS***********************************/

/***************************************ADD BOOK DETAILS****************************************/
void add_details()
{
    char integer[5];

    bk = (book *)malloc(sizeof(book));
    fflush(stdin);
    system("cls");
    border();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(27, 4);
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    printf(" ADD BOOK DETAILS ");
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    gotoxy(25, 7);
    printf("1 \xAF Book id  : ");

    gotoxy(25, 9);
    printf("2 \xAF  Name    : ");
    gotoxy(25, 11);
    printf("3 \xAF  Author  : ");
    gotoxy(25, 13);
    printf("4 \xAF  Price   : ");
    gotoxy(25, 15);
    printf("5 \xAF Quantity : ");
    gotoxy(25, 17);
    printf("6 \xAF Rack NO. : ");
    fflush(stdin);
label5:
    gotoxy(42, 7);
    gets(bk->id);
    fp_add = fopen("Libraraymanage.txt", "rb+");
    bked = (book *)malloc(sizeof(book));
    while (fread(bked, sizeof(book), 1, fp_add) == 1)
    {
        if (!strcmp(bked->id, bk->id))
        {
            blink("Already Exist", 49, 7, 3);
            gotoxy(49, 7);
            printf("             ");
            gotoxy(42, 7);
            printf("      ");
            goto label5;
        }
    }
    fclose(fp_add);
    free(bked);
    //getinput();
    gotoxy(42, 9);
    gets(bk->name);
    gotoxy(42, 11);
    gets(bk->author);
    gotoxy(42, 13);
    gets(bk->price);
    gotoxy(42, 15);
    gets(bk->quantity);
    gotoxy(42, 17);
    gets(bk->rack);
}
/**************************************END ADD BOOK DETAILS********************************/

/************************************** VIEW BOOKS ****************************************/

int view_books()
{
view_books_lable:
    int j, SNo = 0, option;
    system("cls");
    border2();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(34, 4);
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    printf("  VIEW BOOKS  ");
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    gotoxy(19, 7);
    printf("SN.  Id        Title        Author    Price  Quantity  Category  Rack");
    j = 9;
    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        gotoxy(19, j);
        printf("%d.", ++SNo);
        gotoxy(24, j);
        printf("%s", bk->id);
        gotoxy(33, j);
        printf("%s", bk->name);
        gotoxy(47, j);
        printf("%s", bk->author);
        gotoxy(58, j);
        printf("%s", bk->price);
        gotoxy(65, j);
        printf("%s", bk->quantity);
        gotoxy(74, j);
        printf("%s", bk->cat);
        gotoxy(85, j);
        printf("%s", bk->rack);
        j++;
    }
    fclose(fp_add);
    free(bk);
    gotoxy(38, 26);
    printf("Press BACK-ESC / SEARCH-F ");

search_books_label:
    blinkp();
    option = getch();
    if (option == 27)
        return 0;
    if (option == 70 || option == 102)
    {
        gotoxy(38, 26);
        printf("                                ");
        search_books();
    }
    goto view_books_lable;
    gotoxy(70, 26);
    printf("   ");
    gotoxy(40, 27);
    printf("Invalid");
    blinkp();
    printf("Try Again");
    blinkp();
    gotoxy(40, 27);
    printf("                       ");
    gotoxy(70, 26);
    goto search_books_label;
}
/**************************************END VIEW BOOKS ****************************************/

/*********************************** SEARCHING DETAILS   *********************************/
int search_books()
{
    char idk[10], option;
    int SNo = 0, j, x, y;
lable8:
    gotoxy(30, 26);
    printf("Enter book id/name/author/category ");
    blinkp();
    gets(idk);
    gotoxy(30, 26);
    printf("                                                      ");
    //system("cls");
    //gotoxy(19, 7);
    //printf("SN.  Id        Title        Author    Price  Quantity  Category  Rack");
    j = 9;
    for (x = 9; x < 19; x++)
    {
        gotoxy(19, x);
        for (y = 19; y < 88; y++)
        {
            printf(" ");
        }
        //printf("\n");
    }

    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        if (strstr(bk->id, idk) || strstr(bk->name, idk) || strstr(bk->author, idk) || strstr(bk->cat, idk))
        {

            gotoxy(19, j);
            printf("%d.", ++SNo);
            gotoxy(24, j);
            printf("%s", bk->id);
            gotoxy(33, j);
            printf("%s", bk->name);
            gotoxy(47, j);
            printf("%s", bk->author);
            gotoxy(58, j);
            printf("%s", bk->price);
            gotoxy(65, j);
            printf("%s", bk->quantity);
            gotoxy(74, j);
            printf("%s", bk->cat);
            gotoxy(85, j);
            printf("%s", bk->rack);
            j++;
        }
    }
    if (SNo == 0)
    {
        blink("Books Not Found", 44, 20, 3);
    }
    fclose(fp_add);
    free(bk);
    gotoxy(44, 26);

    printf("Press ESC/Enter ");
search_books_label:
    blinkp();
    option = getch();
    gotoxy(44, 20);
    printf("                ");
    if (option == 27)
        return 0;
    if (option == 13)
        printf("                    ");
    goto lable8;
    gotoxy(60, 26);
    printf("   ");
    gotoxy(40, 27);
    printf("Invalid");
    blinkp();
    printf("Try Again");
    blinkp();
    gotoxy(40, 27);
    printf("                       ");
    gotoxy(60, 26);
    goto search_books_label;
}
/***********************************END SEARCHING DETAILS   *********************************/

/************************************** EDIT BOOKS ****************************************/
int edit_books()
{
    int j, SNo = 0, option;
lable4:
    system("cls");
    border2();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(34, 4);
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    printf("  EDIT BOOKS  ");
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    gotoxy(19, 7);
    printf("SN.  Id        Title        Author    Price  Quantity  Category  Rack");
    j = 9;

    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    //printf("%d",fread(bk, sizeof(book), 1, fp_add));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        gotoxy(19, j);
        printf("%d.", ++SNo);
        gotoxy(24, j);
        printf("%s", bk->id);
        gotoxy(33, j);
        printf("%s", bk->name);
        gotoxy(47, j);
        printf("%s", bk->author);
        gotoxy(58, j);
        printf("%s", bk->price);
        gotoxy(65, j);
        printf("%s", bk->quantity);
        gotoxy(74, j);
        printf("%s", bk->cat);
        gotoxy(85, j);
        printf("%s", bk->rack);
        j++;
    }
    fclose(fp_add);
    free(bk);

    gotoxy(35, 25);
    printf("Press E to Edit / del to delete");
    blinkp();
    fflush(stdin);
    option = getch();
    fflush(stdin);
    if (option == 224)
    {
        gotoxy(35, 25);
        printf("                                        ");
        delete_books();
        goto lable4;
    }
    else if (option == 69 || option == 101)
    {
        edit_details();
        goto lable4;
    }
    else if (option == 27)
        return 0;
    else
    {
        gotoxy(67, 25);
        printf("   ");
        gotoxy(36, 26);
        printf("Invalid");
        blinkp();
        printf("Try Again");
        blinkp();
        gotoxy(36, 26);
        printf("                      ");
        goto lable4;
    }
    system("cls");
    border();
    gotoxy(25, 21);
    printf("Something Error");
    blinkp();
    printf("Press any Key");
    getch();
    system("cls");
    password();
    return 0;
}
/**************************************END EDIT BOOKS ****************************************/

/************************************** DELETE BOOKS ****************************************/
int delete_books()
{
    char idk[5];
    int option;
    gotoxy(40, 25);
    printf("Enter book id: ");
    gets(idk);
    fflush(stdin);
    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        if (!strcmp(bk->id, idk))
        {
            free(bk);
            gotoxy(40, 26);
            printf("Are you sure to delete(Y/N)");
        label3:
            gotoxy(69, 26);
            blinkp();
            fflush(stdin);
            fflush(fp_add);
            option = getch();

            if (option == 89 || option == 121)
            {
                gotoxy(40, 26);
                printf("                                ");
                bk = (book *)malloc(sizeof(book));
                rewind(fp_add);
                gotoxy(48, 26);
                printf("Deleting");
                while (fread(bk, sizeof(book), 1, fp_add) == 1)
                {
                    if (strcmp(bk->id, idk))
                    {
                        printf(".");
                        delay(300);
                        printf(".");
                        delay(300);
                        printf(".");
                        delay(300);
                        ftemp = fopen("temp.txt", "ab+");
                        fwrite(bk, sizeof(book), 1, ftemp);
                        fclose(ftemp);
                        printf("\b\b\b     \b\b\b");
                    }
                }
                fclose(ftemp);
                fclose(fp_add);
                free(bk);
                remove("Libraraymanage.txt");
                rename("temp.txt", "Libraraymanage.txt");
                gotoxy(48, 26);
                printf("        ");
                blink("Deleted", 48, 26, 3);
                gotoxy(48, 26);
                printf("       ");
                return 0;
            }
            else if (option == 78 || option == 110)
            {
                edit_books();
            }
            else
            {
                gotoxy(69, 26);
                printf("   ");
                gotoxy(40, 27);
                printf("Invalid");
                blinkp();
                printf("Try Again");
                blinkp();
                gotoxy(40, 27);
                printf("                      ");
                gotoxy(69, 26);
                goto label3;
            }
        }
    }
    fclose(fp_add);
    blink("Not found", 40, 26, 3);
    gotoxy(40, 26);
    printf("         ");
    //system("cls");
    return 0;

    // main_menu();
    //delete_books();
    //fclose(fp_add);
}
/**************************************END DELETE BOOKS ****************************************/

/*********************************** EDIT BOOK DETAILS *******************************/
int edit_details()
{
    char idk[5];
    int option, j;
    gotoxy(32, 25);
    printf("                                           ");
    gotoxy(37, 25);
    printf("Enter Book id to EDIT : ");
    gets(idk);
    fflush(stdin);
    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        if (!strcmp(bk->id, idk))
        {
            system("cls");
            border2();
            gotoxy(29, 29);
            printf("BACK-ESC");
            gotoxy(34, 4);
            printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
            printf("  EDIT BOOKS  ");
            printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
            gotoxy(19, 7);
            printf("SN.  Id        Title        Author    Price  Quantity  Category  Rack");
            j = 9;
            gotoxy(19, j);
            printf("Old");
            gotoxy(24, j);
            printf("%s", bk->id);
            gotoxy(33, j);
            printf("%s", bk->name);
            gotoxy(47, j);
            printf("%s", bk->author);
            gotoxy(58, j);
            printf("%s", bk->price);
            gotoxy(65, j);
            printf("%s", bk->quantity);
            gotoxy(74, j);
            printf("%s", bk->cat);
            gotoxy(85, j);
            printf("%s", bk->rack);
            free(bk);
            fclose(fp_add);
            // to edit
            j += 4;
            bked = (book *)malloc(sizeof(book));
            gotoxy(24, (j - 2));
            printf("You must have to Enter all details again.");
            blinkp();
            gotoxy(19, j);
            printf("New");
            gotoxy(24, j);
            gets(bked->id);
            gotoxy(33, j);
            gets(bked->name);
            gotoxy(47, j);
            gets(bked->author);
            gotoxy(58, j);
            gets(bked->price);
            gotoxy(65, j);
            gets(bked->quantity);
            gotoxy(74, j);
            gets(bked->cat);
            gotoxy(85, j);
            gets(bked->rack);

            //fp_add = fopen("Libraraymanage.txt", "rb+");
            //bk = (book *)malloc(sizeof(book));
            fp_add = fopen("Libraraymanage.txt", "rb+");
            if (fp_add == NULL)
            {
                printf("Data File Not Found");
                blinkp();
                printf("Error");
                blinkp();
                return 0;
            }
            bk = (book *)malloc(sizeof(book));
            //printf("%d",fread(bk, sizeof(book), 1, fp_add));
            while (fread(bk, sizeof(book), 1, fp_add) == 1)
            {
                if (!strcmp(bk->id, idk))
                {
                    //blink("issuing1", 21, 23, 2);
                    //  itoa((atoi(bk->quantity) - atoi(isb->quantity)), bk->quantity, 10);
                    ftemp = fopen("temp1.txt", "ab+");
                    fwrite(bked->id, sizeof(bked->id), 1, ftemp);
                    fwrite(bked->name, sizeof(bked->name), 1, ftemp);
                    fwrite(bked->author, sizeof(bked->author), 1, ftemp);
                    fwrite(bked->price, sizeof(bked->price), 1, ftemp);
                    fwrite(bked->quantity, sizeof(bked->quantity), 1, ftemp);
                    //printf("%s",bk->cat);
                    fwrite(bked->rack, sizeof(bked->rack), 1, ftemp);
                    fwrite(bked->cat, sizeof(bked->cat), 1, ftemp);
                    //printf("%s",bk->rack);
                    fclose(ftemp);
                    continue;
                }
                ftemp = fopen("temp1.txt", "ab+");
                //blink("issuing2", 21, 24, 2);
                //printf("\b\b\b\b\b\b\b       \b\b\b\b\b\b\b");
                fwrite(bk, sizeof(book), 1, ftemp);
                fclose(ftemp);
            }
            fflush(fp_add);
            fclose(fp_add);
            free(bk);
            free(bked);
            gotoxy(38, 18);
            printf("Save Changes(Y/N) ");
            blinkp();
        back:
            if ((option = getch()) == 78 || option == 110)
            {
                remove("temp1.txt");
            }
            if (option == 89 || option == 121)
            {
                remove("Libraraymanage.txt");
                rename("temp1.txt", "Libraraymanage.txt");
            }
            else
            {
                goto back;
            }
            return 0;
        }
    }
    //gotoxy(68,25);
    blink("Not Found", 68, 25, 3);
    return 0;
}
/***********************************END EDIT BOOK DETAILS *******************************/
//i have to add the check book id funct code in add

/**************************************** BORDER2 *************************************/
void border2()
{
    int i;
    gotoxy(70, 29);
    printf("Copyright %c SAURABH", 260); // for making symbol 260
    gotoxy(19, 2);
    printf("%s", date_time());
    gotoxy(19, 29);
    printf("EXIT-ESC");
    gotoxy(16, 1);
    printf("%c", 201);
    gotoxy(16, 30);
    printf("%c", 200);

    gotoxy(90, 30);
    printf("%c", 188);
    for (i = 17; i < 90; i += 1)
    {
        gotoxy(i, 1);
        printf("%c ", 205);
    }
    gotoxy(90, 1);
    printf("%c", 187);
    for (i = 17; i < 90; i += 1)
    {
        gotoxy(i, 30);
        printf("%c", 205);
    }
    for (i = 2; i < 30; i++)
    {
        gotoxy(16, i);
        printf("%c", 186);
    }
    for (i = 2; i < 30; i++)
    {
        gotoxy(90, i);
        printf("%c", 186);
    }
}
/****************************************END BORDER2 *************************************/

/*********************************** ISSUE PORTAL   *********************************/
int issue_portal()
{
    char integer[5];
    int option;
    system("cls");
    border();
    gotoxy(34, 4);
    printf("\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04");
    gotoxy(34, 5);
    printf("\x04 LIBRARY  PORTAL \x04");
    gotoxy(34, 6);
    printf("\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04");
    gotoxy(25, 10);
    printf("\xAF Book id  : ");
    gotoxy(25, 12);
    printf("\xAF Std Name : ");
    gotoxy(25, 14);
    printf("\xAF  Std Id  : ");
    gotoxy(25, 16);
    printf("\xAF Quantity : ");
    gotoxy(25, 18);
    printf("\xAF  Price   : ");
    //gotoxy(25, 19);
    //printf("6 \xAF Rack NO. : ");
    isb = (issue *)malloc(sizeof(issue));
    fflush(stdin);
label6:
    gotoxy(42, 10);
    fflush(stdin);
    gets(isb->id);
    fp_add = fopen("Libraraymanage.txt", "rb+");
    bk = (book *)malloc(sizeof(book));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        if (!strcmp(isb->id, bk->id))
        {
            if (atoi(bk->quantity) > 0)
            {
                blink("Avail ", 49, 10, 3);
                printf("(%d)", atoi(bk->quantity));

                gotoxy(42, 12);
                fflush(stdin);
                gets(isb->std_name);
                gotoxy(42, 14);
                fflush(stdin);
                gets(isb->std_id);
            label7:
                gotoxy(42, 16);
                fflush(stdin);
                gets(isb->quantity);
                if (!(atoi(isb->quantity) > 0 && atoi(isb->quantity) <= 3 && atoi(isb->quantity) <= atoi(bk->quantity)))
                {

                    blink("Invalid", 49, 16, 2);
                    gotoxy(42, 16);
                    printf("   ");
                    gotoxy(49, 17);
                    printf("Press (Enter/ESC)..");
                    if ((option = getch()) == 27)
                    {
                        fclose(fp_add);
                        free(bk);
                        return 0;
                    }
                    gotoxy(49, 16);
                    printf("        ");
                    gotoxy(49, 17);
                    printf("                    ");
                    goto label7;
                }
                gotoxy(42, 18);
                gets(isb->price);
                //gotoxy(42, 19);
                //gets(bk->rack);
                //isb->
                //isb->iss_time = "1223";
                fp_issue = fopen("libraryissue.txt", "ab+");
                fwrite(isb, sizeof(issue), 1, fp_issue);
                fclose(fp_issue);
                fclose(fp_add);
                free(bk);
                issuing_books(); //(isb->id,isb->quantity);
                free(isb);
                system("cls");
                border();
                //gotoxy(33, 17);
                //blinkp();
                blink("BOOK ISSUED", 36, 20, 2);
                blinkp();
                return 0;
            }
            blink("All Issued", 49, 10, 3);
            gotoxy(42, 10);
            printf("     ");
            gotoxy(49, 11);
            printf("Press (Enter/ESC)..");
            if ((option = getch()) == 27)
            {
                fclose(fp_add);
                free(bk);
                return 0;
            }

            gotoxy(49, 10);
            printf("          ");
            gotoxy(49, 11);
            printf("                   ");
            fclose(fp_add);
            goto label6;
        }
    }
    fclose(fp_add);
    free(bk);
    blink("Not Exist", 49, 10, 3);
    gotoxy(42, 10);
    printf("     ");
    gotoxy(49, 11);
    printf("Press (Enter/ESC)..");
    if ((option = getch()) == 27)
    {
        fclose(fp_add);
        free(bk);
        return 0;
    }

    gotoxy(49, 9);
    printf("         ");
    gotoxy(49, 10);
    printf("                   ");
    goto label6;
}
/***********************************END ISSUE PORTAL   *********************************/

/*********************************** ISSUING PORTAL   *********************************/
int issuing_books()
{
    int j, option;
    fp_add = fopen("Libraraymanage.txt", "rb+");
    if (fp_add == NULL)
    {
        printf("Data File Not Found");
        blinkp();
        printf("Error");
        blinkp();
        return 0;
    }
    bk = (book *)malloc(sizeof(book));
    //printf("%d",fread(bk, sizeof(book), 1, fp_add));
    while (fread(bk, sizeof(book), 1, fp_add) == 1)
    {
        if (!strcmp(bk->id, isb->id))
        {
            //blink("issuing1", 21, 23, 2);
            itoa((atoi(bk->quantity) - atoi(isb->quantity)), bk->quantity, 10);
            ftemp = fopen("temp.txt", "ab+");
            fwrite(bk->id, sizeof(bk->id), 1, ftemp);
            fwrite(bk->name, sizeof(bk->name), 1, ftemp);
            fwrite(bk->author, sizeof(bk->author), 1, ftemp);
            fwrite(bk->price, sizeof(bk->price), 1, ftemp);
            fwrite(bk->quantity, sizeof(bk->quantity), 1, ftemp);
            //printf("%s",bk->cat);
            fwrite(bk->rack, sizeof(bk->rack), 1, ftemp);
            fwrite(bk->cat, sizeof(bk->cat), 1, ftemp);
            //printf("%s",bk->rack);
            fclose(ftemp);
            continue;
        }
        ftemp = fopen("temp.txt", "ab+");
        //blink("issuing2", 21, 24, 2);
        printf("\b\b\b\b\b\b\b       \b\b\b\b\b\b\b");
        fwrite(bk, sizeof(book), 1, ftemp);
        fclose(ftemp);
    }
    fflush(fp_add);
    fclose(fp_add);
    free(bk);
    remove("Libraraymanage.txt");
    //fp_add=fopen("Libraraymanage.txt","rb");
    if (fp_add == NULL)
    {
        printf("Data File Not Found");
        blinkp();
        printf("Error");
        blinkp();
        main_menu();
    }
    else
    {
        //printf("Error");
        fclose(fp_add);
        remove("Libraraymanage.txt");
    }
    rename("temp.txt", "Libraraymanage.txt");
    // gotoxy(29, 21);
    //blinkp();
    return 0;
}
/***********************************END ISSUING PORTAL   *********************************/

/*********************************** BILL GENERATE   *********************************/
void bill_generate()
{
    fp_bill = fopen("libraryissuebill.text", "a+");
    //fread(isbk);
    fclose(fp_bill);
}
/***********************************END BILL GENERATE   *********************************/

/*********************************** RETURN PORTAL   *********************************/
void return_portal()
{
    char bookid[5]; //bookamt[5];
    int option = 0;
    system("cls");
    border();
    gotoxy(34, 4);
    printf("\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04");
    gotoxy(34, 5);
    printf("\x04 LIBRARY  PORTAL \x04");
    gotoxy(34, 6);
    printf("\x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04 \x04");
    gotoxy(25, 10);
    printf("\xAF Book id  : ");
    gotoxy(43, 10);
    fflush(stdin);
    gets(bookid);
    isb = (issue *)malloc(sizeof(issue));
    ftemp = fopen("libraryissue.txt", "rb+");
    while (fread(isb, sizeof(issue), 1, ftemp) == 1)
    {
        if (!strcmp(isb->id, bookid))
        {
            gotoxy(25, 11);
            printf("\xAF Bill amt. : ");
            gotoxy(43, 11);
            fflush(stdin);
            gets(isb->price);
            gotoxy(25, 16);
            printf("Do you want to return(Y/N) ");
            blinkp();
            if ((option = getch()) == 89 || option == 121)
            {
                itoa((-atoi(isb->quantity)), isb->quantity, 10);
                issuing_books();
                returning_books(); // it used for changing the quantity in main file after return
                blink("Returned", 28, 18, 3);
                blinkp();
            }
        }
    }
    if (!option)
    {
        blink("Not Issued", 25, 16, 3);
        blinkp();
    }
    fclose(ftemp);
    free(isb);
}
/***************************************** END RETURN PORTAL   *****************************************/

/***************************************** ISSUED DETAILS   ********************************************/
int issued_books()
{

    int j, SNo = 0, option;
    system("cls");
    border2();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(32, 4);
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    printf("  ISSUED BOOKS  ");
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    gotoxy(19, 7);
    printf("SN. Book_Id    Std_Name      Std_Id Quantity IssueDate Bill ReturnDate");
    j = 9;
    fp_add = fopen("libraryissue.txt", "rb+");
    if (fp_add == NULL)
    {
        printf("Saurabh");
        main_menu();
    }
    isb = (issue *)malloc(sizeof(issue));
    //printf("%d",fread(isb, sizeof(issue), 1, fp_add));
    while (fread(isb, sizeof(issue), 1, fp_add) == 1)
    {
        gotoxy(19, j);
        printf("%d.", ++SNo);
        gotoxy(24, j);
        printf("%s", isb->id);
        gotoxy(33, j);
        printf("%s", isb->std_name);
        gotoxy(47, j);
        printf("%s", isb->std_id);
        gotoxy(58, j);
        printf("%s", isb->quantity);
        gotoxy(65, j);
        // printf("%s", isb->iss_time);
        gotoxy(74, j);
        printf("%s", isb->price);
        gotoxy(85, j);
        // printf("%s", isb->ret_time);
        j++;
    }
    fclose(fp_add);
    free(bk);
    gotoxy(44, 26);
    printf("Press ESC ");
search_books_label:
    blinkp();
    option = getch();
    if (option == 27)
        return 0;

    gotoxy(54, 26);
    printf("   ");
    gotoxy(40, 27);
    printf("Invalid");
    blinkp();
    printf("Try Again");
    blinkp();
    gotoxy(40, 27);
    printf("                       ");
    gotoxy(54, 26);
    goto search_books_label;
}
/***********************************END ISSUED DETAILS   *********************************/

/************************************** Blinking***************************************/
void blinkp()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        delay(300);
        printf(".");
    }
}
/**************************************END Blinking***************************************/

/*************************************** EXIT APP ***********************************/
void exiting()
{
    system("cls");
    //system("color B");
    gotoxy(40, 14);
    printf("Closing");
    blinkp();
    system("cls");
    exit(1);
}
/***************************************END EXIT APP ***********************************/

/**************************************TIME****************************************/
char *date_time(void)
{
    time_t t;
    time(&t);
    //printf("Date and time:%s\n",ctime(&t));
    return (ctime(&t));
}
/**************************************END TIME****************************************/

/**************************************BORDER****************************************/
void border()
{
    int i;

    gotoxy(54, 29);
    printf("Copyright %c SAURABH", 260); // for symbol 260
    gotoxy(19, 2);
    printf("%s", date_time());
    gotoxy(19, 29);
    printf("BACK-ESC");
    gotoxy(16, 1);
    printf("%c", 201);
    gotoxy(16, 30);
    printf("%c", 200);

    gotoxy(74, 30);
    printf("%c", 188);
    for (i = 17; i < 74; i += 1)
    {
        gotoxy(i, 1);
        printf("%c ", 205);
    }
    gotoxy(74, 1);
    printf("%c", 187);
    for (i = 17; i < 74; i += 1)
    {
        gotoxy(i, 30);
        printf("%c", 205);
    }
    for (i = 2; i < 30; i++)
    {
        gotoxy(16, i);
        printf("%c", 186);
    }
    for (i = 2; i < 30; i++)
    {
        gotoxy(74, i);
        printf("%c", 186);
    }
}
/**************************************END BORDER**************************************/

/*********************************** RETURNING PORTAL   *********************************/
int returning_books()
{
    int j, option;
    fp_issue = fopen("libraryissue.txt", "rb+");
    if (fp_issue == NULL)
    {
        printf("Data File Not Found");
        blinkp();
        printf("Error");
        blinkp();
        return 0;
    }
    ised = (issue *)malloc(sizeof(issue));
    //printf("%d",fread(bk, sizeof(book), 1, fp_add));
    fp_add = fopen("temp.txt", "ab+");
    while (fread(ised, sizeof(issue), 1, fp_issue) == 1)
    {
        if (!strcmp(ised->id, isb->id))
        {
          fp_bill=fopen("libraryissuehistory.txt","ab+");
          fwrite(ised,sizeof(issue),1,fp_bill);
          fclose(fp_bill);
          continue;
        }
        fwrite(ised, sizeof(issue), 1, fp_add);
    }
    fflush(fp_add);
    fclose(fp_add);
    fflush(fp_issue);  
    fclose(fp_issue);
    free(ised);  
    fflush(fp_add);
    fclose(fp_add);

    remove("libraryissue.txt");
    rename("temp.txt", "libraryissue1.txt");
    return 0;
}








int issued_history()
{

    int j, SNo = 0, option;
    system("cls");
    border2();
    gotoxy(29, 29);
    printf("BACK-ESC");
    gotoxy(32, 4);
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    printf("  ISSUED BOOKS  ");
    printf("\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7\xF7");
    gotoxy(19, 7);
    printf("SN. Book_Id    Std_Name      Std_Id Quantity IssueDate Bill ReturnDate");
    j = 9;
    fp_add = fopen("libraryissuehistory.txt", "rb+");
    if (fp_add == NULL)
    {
        printf("Saurabh");
        main_menu();
    }
    isb = (issue *)malloc(sizeof(issue));
    //printf("%d",fread(isb, sizeof(issue), 1, fp_add));
    while (fread(isb, sizeof(issue), 1, fp_add) == 1)
    {
        gotoxy(19, j);
        printf("%d.", ++SNo);
        gotoxy(24, j);
        printf("%s", isb->id);
        gotoxy(33, j);
        printf("%s", isb->std_name);
        gotoxy(47, j);
        printf("%s", isb->std_id);
        gotoxy(58, j);
        printf("%s", isb->quantity);
        gotoxy(65, j);
        // printf("%s", isb->iss_time);
        gotoxy(74, j);
        printf("%s", isb->price);
        gotoxy(85, j);
        // printf("%s", isb->ret_time);
        j++;
    }
    fclose(fp_add);
    free(bk);
    gotoxy(44, 26);
    printf("Press ESC ");
search_books_label:
    blinkp();
    option = getch();
    if (option == 27)
        return 0;

    gotoxy(54, 26);
    printf("   ");
    gotoxy(40, 27);
    printf("Invalid");
    blinkp();
    printf("Try Again");
    blinkp();
    gotoxy(40, 27);
    printf("                       ");
    gotoxy(54, 26);
    goto search_books_label;
}