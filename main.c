#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void head_er();
void welcome();
void admin();
void user();
void browse();
void add_books();
void rmv_books();
void search_books();
void view_books();
void all_books();
void by_name();
void by_author();
void by_genre();
void by_id();
void borrow();
void deposit();
void admin_password();
void user_password();
void credit();

int t_b =0;
struct books {
        
        int id;
        char name[40];
        char author[40];
        char cat[20];
        int quantity;
    };
    
struct books b;

FILE *book_db, *temp;

int main() {    
	welcome();
    
    printf("\n\n\n\n\n");
	return 0;
}

void head_er() {
    printf("\t\t\t\t============Welcome to the Library Management System=============\n");
    printf("\t\t\t\t\t  --------------------------------------------\n");        
    printf("\t\t\t\t\t         This Project is Developed by\n");
    printf("--------\t\t\t\t\t         Group Seven");
    printf("\t\t\t\t\t\t--------\n\n");

}

void welcome() {
    system("cls");
    head_er();
    int n;
    printf("\n\t\t\t\t\t\t\t  1> Admin");
    printf("\n\t\t\t\t\t\t\t  2> User");
    printf("\n\t\t\t\t\t\t\t  3> Browse");
    printf("\n\t\t\t\t\t\t\t  4> Exit");
    printf("\n\n\t\t\t\t\t\t\t  Chose: "); 
    scanf("%d", &n);
    
    switch(n) {
        
        case 1: admin_password(); break;
        case 2: user_password(); break;
        case 3: browse(); break;
        case 4: credit(); break;
        default: welcome();
    }
    
}

void admin() {
    system("cls");
    head_er();
    int n;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  ADMIN PANEL  |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\t\t\t\t1. Add Books\n\t\t\t\t2. View Books\n\t\t\t\t3. Search Book\n\t\t\t\t4. Remove Books\n\t\t\t\t5. Log Out");
    printf("\n\n\t\t\t\tNow Chose: "); 
    scanf("%d", &n);
    switch(n) {
        case 1: add_books(); break;
        case 2: {
                view_books();
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\tTotal Books = %d", t_b);
                t_b = 0;
                printf("\n\n\t\t\tPress Any Key To Go Back...");
                getch();
                admin();
                break;
            }
        case 3: search_books(); break;
        case 4: rmv_books(); break;
        case 5: welcome(); break;
        deafult: fflush(stdin); getchar(); admin();
    }
}

void user() {
    system("cls");
    head_er();
    int n;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  USER   PANEL |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\t\t\t\t1. Search Book\n\t\t\t\t2. Book List\n\t\t\t\t3. Borrow Book\n\t\t\t\t4. Deposit Book\n\t\t\t\t5. Log Out");
    printf("\n\n\t\t\t\tChose: "); 
    scanf("%d", &n);
    switch(n) {
        case 1: {
                search_books();
                user();
                break;
        }
        case 2: {
                view_books(); 
                printf("\n\n\t\t\tPress any key to go back");
                getch();
                user();
                break;
        }
        case 3: borrow(); break;
        case 4: deposit(); break;
        case 5: welcome(); break;
        deafult: user();
    }
}
void browse() {
    system("cls");
    head_er();
    int n;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  BROWSE BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\t\t\t\t1.View Books\n\t\t\t\t2.Search Books\n\t\t\t\t3.Go Back\n\n\t\t\t\tChose: ");
    scanf("%d", &n);
    
        switch(n) {
        case 1: {
                view_books(); 
                printf("\n\n\n\t\t\t\tPress any key to go back");
                getch();
                browse();
                break;
            }
        case 2: {
                search_books(); 
                printf("\n\n\n\t\t\t\tPreess any key to go back");
                getch();
                browse();
                break;
            }
        case 3: welcome(); break;
        default: welcome();
        }
}

void add_books() {
    system("cls");
    head_er();
    int d, flag = 0;
    
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |   ADD  BOOKS  |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    
    book_db = fopen("list.txt", "a+");
    
    printf("\n\n\t\t\t\tEnter Book ID: ");
    scanf("%d", &d);
    
    rewind(book_db);
    while(fread(&b, sizeof(b), 1, book_db) == 1) {
        
        if(d == b.id) {
            printf("\n\n\t\t\t This Book is already on the Catalouge..");
            flag = 1;
        }
    }
    if(flag == 1) {
         fflush(stdin);
         getchar();
         admin();
    }
    
    b.id = d;
    printf("\t\t\t\tEnter Book Name: "); 
    fflush(stdin);
    gets(b.name);
    printf("\t\t\t\tEnter Book Author: "); 
    gets(b.author);
    printf("\t\t\t\tEnter Book Catagory: "); 
    gets(b.cat);
    printf("\t\t\t\tEnter Book Quantity: ");
    scanf("%d", &b.quantity);
    
    fseek(book_db, 0, SEEK_END);
    fwrite(&b, sizeof(b), 1, book_db);
    
    fclose(book_db);
    
    printf("\n\t\t\t\t %d Your entry has been saved ", flag);
    fflush(stdin);
    getch();
    admin();
}
void rmv_books() {
    system("cls");
    head_er();
    int b_id, flag =0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  DELETE BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    
    printf("\n\t\t\t\tEnter Book Id: ");
    scanf("%d", &b_id);
    
    book_db = fopen("list.txt", "r+");
    
    rewind(book_db);
    while(fread(&b, sizeof(b), 1, book_db) == 1) {
        if(b_id == b.id) {
            printf("\n\t\t\t\tBook Found! Here is the Information: \n");
            printf("\n\n\t\t\t\tBook ID: %d", b.id);
            printf("\n\t\t\t\tBook Name: %s", b.name);
            printf("\n\t\t\t\tBook Author: %s", b.author);
            printf("\n\t\t\t\tBook Genre: %s", b.cat);
            printf("\n\t\t\t\tBook Quantity: %d", b.quantity);
            
            printf("\n\n\t\t\t\t Press Y to confirm Delatation\n");
            fflush(stdin);
            if(getch()=='y' || getch()=='Y') {
                flag = 1;
            }
        }
    }
    
    if(flag == 0) {
        printf("\n\n\t\t\t\t\tBook Not found, plz check ID again\n");
        fflush(stdin);
        getchar();
        admin();
    }
    else {
        
        temp = fopen("temp_list.txt", "w+");
        
        rewind(book_db);
        while(fread(&b, sizeof(b), 1, book_db)==1){
            if(b.id != b_id ) {
                
                fseek(temp, 0, SEEK_CUR);
                fwrite(&b, sizeof(b), 1, temp);
            }
        }
        
        fclose(book_db);
        fclose(temp);
        
        remove("list.txt");
        rename("temp_list.txt", "list.txt");
        book_db = fopen("list.txt", "r");
        fclose(book_db);
        
        printf("\n\n\t\t\t\t\tBook has been deleted\n");
        printf("\n\n\t\t\t\t Press any key to Return\n");
                getch();
                admin();
            }
    }
    

void view_books() {
    
    system("cls");
    head_er();
    int n;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  VIEW  BOOKS  |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\t\t\t\t1. Book Author\n\t\t\t\t2. Book Genre\n\t\t\t\t3. All Books\n\t\t\t\tChose: ");
    scanf("%d", &n);
    
    switch(n) {
        case 1: by_author(); break;
        case 2: by_genre(); break;
        case 3: all_books(); break;
        default: all_books();
    }
}
void search_books() {
    system("cls");
    head_er();
    int n;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      | SEARCH  BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\t\t\t\t1. Book Name\n\t\t\t\t2. Book Author\n\t\t\t\t3. Book Genre\n\t\t\t\t4. Book ID\n\t\t\t\tChose: ");
    scanf("%d", &n);
    
    switch(n) {
        case 1: by_name(); break;
        case 2: by_author(); break;
        case 3: by_genre(); break;
        case 4: by_id(); break;
        default: search_books();
    }
}

void all_books() {
   
    system("cls");
    head_er();
     
      printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  BOOKS  LIST  |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
     printf("\t\tBook ID\t\tBook Name\t\tBook Author\t\tBook Genre\tQuantity");
     printf("\n\t\t---------------------------------");
     printf("---------------------------------------------------------------");
     book_db = fopen("list.txt", "r");
     
     while(fread(&b, sizeof(b), 1, book_db) == 1) {
         
         printf("\n\t\t%d", b.id);
         printf("\t\t%s", b.name);
         printf("\t\t%s", b.author);
         printf("\t\t%s", b.cat);
         printf("\t\t%d\n", b.quantity);
         t_b += b.quantity;

     }
     
     fclose(book_db);
     printf("\t\t---------------------------------");
     printf("---------------------------------------------------------------");
     printf("\n\t\t\t\t\t\t\t~~~END OF LIST~~~");
     printf("\n\t\t---------------------------------");
     printf("---------------------------------------------------------------");
}

void by_name() {
    system("cls");
    head_er();
    char b_name[16];
    int flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  SEARCH BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\tSearch Book By\n");
    printf("\t\t\t\tBook Name: "); fflush(stdin);
    gets(b_name);
    
    book_db = fopen("list.txt", "r");
    
    while(fread(&b, sizeof(b), 1, book_db)==1) {
        
        if(strcmp(b.name, (b_name))==0) {
            flag++;
            
            if (flag == 1) {
                    printf("\n\t\tBook ID\t\tBook Name\t\tBook Author\t\tBook Genre\tAvailable");
                    printf("\n\t\t---------------------------------");
                    printf("---------------------------------------------------------------");
            }
            
            printf("\n\t\t%d", b.id);
            printf("\t\t%s", b.name);
            printf("\t\t%s", b.author);
            printf("\t\t%s", b.cat);
            if(b.quantity != 0) {
                printf("\t\tYes");
            }
            else {
                printf("\t\tNo"); 
            }
        }
    }
    
    if(flag == 0) {
        printf("\n\t\t\tStatus:Not Found");
    }
    else {
        printf("\n\n\n\t\t\tStatus: Found %d times", flag);
    }

    printf("\n\t\t\tTry another search?(Y/N): ");
    if(getch()=='y' || getch()=='Y')
    by_name();
}
void by_author() {
    system("cls");
    head_er();
    char b_author[16];
    int flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  SEARCH BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\tSearch Book By\n");
    printf("\t\t\t\tBook Author: "); fflush(stdin);
    gets(b_author);
    
    book_db = fopen("list.txt", "r");
    
    while(fread(&b, sizeof(b), 1, book_db)==1) {
        
        if(strcmp(b.author, (b_author))==0) {
            flag++;
            
            if (flag == 1) {
                    printf("\n\t\tBook ID\t\tBook Name\t\tBook Author\t\tBook Genre\tAvailable");
                    printf("\n\t\t---------------------------------");
                    printf("---------------------------------------------------------------");
            }
            
            printf("\n\t\t%d", b.id);
            printf("\t\t%s", b.name);
            printf("\t\t%s", b.author);
            printf("\t\t%s", b.cat);
            if(b.quantity != 0) {
                printf("\t\tYes");
            }
            else {
                printf("\t\tNo"); 
            }
        }
    }
    
    if(flag == 0) {
        printf("\n\t\t\tStatus:Not Found");
    }
    else {
        printf("\n\n\n\t\t\tStatus: Found %d times", flag);
    }

    printf("\n\n\n\t\t\tTry another search?(Y/N): ");
    fflush(stdin);
    if(getch()=='y' || getch()=='Y')
    by_author();
}
void by_genre() {
    system("cls");
    head_er();
    char b_genre[16];
    int flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  SEARCH BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\tSearch Book By\n");
    printf("\t\t\t\tBook Genre: "); fflush(stdin);
    gets(b_genre);
    
    book_db = fopen("list.txt", "r");
    
    while(fread(&b, sizeof(b), 1, book_db)==1) {
        
        if(strcmp(b.cat, (b_genre))==0) {
            flag++;
            
            if (flag == 1) {
                    printf("\n\t\tBook ID\t\tBook Name\t\tBook Author\t\tBook Genre\tAvailable");
                    printf("\n\t\t---------------------------------");
                    printf("---------------------------------------------------------------");
            }
            
            printf("\n\t\t%d", b.id);
            printf("\t\t%s", b.name);
            printf("\t\t%s", b.author);
            printf("\t\t%s", b.cat);
            if(b.quantity != 0) {
                printf("\t\tYes");
            }
            else {
                printf("\t\tNo"); 
            }
        }
    }
    
    if(flag == 0) {
        printf("\n\t\t\tStatus:Not Found");
    }
    else {
        printf("\n\n\n\t\t\tStatus: Found %d times", flag);
    }
    
    
    printf("\n\n\n\t\t\tTry another search?(Y/N): ");
    if(getch()=='y' || getch()=='Y')
    by_genre();
}
void by_id() {
    system("cls");
    head_er();
    int b_id, flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  SEARCH BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\tSearch Book By\n");
    printf("\t\t\t\tBook Id: "); fflush(stdin);
    scanf("%d", &b_id);
    
    book_db = fopen("list.txt", "r");
    
    while(fread(&b, sizeof(b), 1, book_db)==1) {
        
        if(b.id == b_id) {
            
            flag = 1;
                printf("\n\t\tBook ID\t\tBook Name\t\tBook Author\t\tBook Genre\tAvailable");
                printf("\n\t\t---------------------------------");
                printf("---------------------------------------------------------------");
            printf("\n\t\t%d", b.id);
            printf("\t\t%s", b.name);
            printf("\t\t%s", b.author);
            printf("\t\t%s", b.cat);
            if(b.quantity != 0) {
                printf("\t\tYes");
            }
            else {
                printf("\t\tNo"); 
            }
        }
    }
    
    if(flag == 0) {
        printf("\n\t\t\tStatus: Not Found");
    }
    
    printf("\n\n\n\t\t\tTry another search?(Y/N): ");
    if(getch()=='y' || getch()=='Y')
    by_id();
}

void borrow(){
    system("cls");
    head_er();
    int d, flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      |  BORROW BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\tEnter Book Id: ");
    scanf("%d", &d);
    
    book_db = fopen("list.txt", "r+");
    
    rewind(book_db);
    while(fread(&b, sizeof(b), 1, book_db) == 1) {
        if(d == b.id) {

            printf("\n\t\t\t\t\t\t--Book__Info--");
            printf("\n\t\t\t\t\t\t~~~~~~~~~~~~~~\n");
            printf("\n\n\t\t\t\tBook ID   : %d", b.id);
            printf("\n\t\t\t\tBook Name   : %s", b.name);
            printf("\n\t\t\t\tBook Author : %s", b.author);
            printf("\n\t\t\t\tBook Genre  : %s", b.cat);
            if(b.quantity != 0) {
                printf("\n\t\t\t\tStatus      : Available");
                flag = 1;
            }
            else {
                printf("\n\t\t\t\tStatus      : Not Available");
            }
            
            break;
        }
    }
    
    if(flag == 0) {
    printf("\n\n\n\t\t\t\t\tSorry, Book Not Available. Please Cheack Id again. ");
    printf("\n\t\t\t\t\tOr someone else has already borrewed.");
    printf("\n\n\t\t\t\t\tPress any Key to return...");
    fflush(stdin);
    getch();
    user();
    }
    else {
    
        
        printf("\n\n\n\t\t\t\tPress Y to confirm, Any Other Key To Cancel");
            fflush(stdin);
            if(getch() == 'y' || getch() == "Y") {
                b.quantity = (b.quantity)-1;
                fseek(book_db, ftell(book_db)-sizeof(b), 0);
                fwrite(&b, sizeof(b), 1, book_db);
                fclose(book_db);
                printf("\n\n\t\t\t\tPlease Deposit the book in time...");
                printf("\n\t\t\t\tThank You,\n\t\t\t\tLibrary Authority");
                getch();
                user();
            }
            else {
                printf("\n\n\t\t\t\tCanceled");
                user();
            }
    printf("\n\t\t\t\t\tPlease return the book within time limit, Happy Reading");
    printf("\n\n\t\t\t\t\tPress any Key to return...");
    fflush(stdin);
    getch();
    user();
    }
}
void deposit() {
    
    system("cls");
    head_er();
    int d, flag = 0;
    printf("\t\t\t\t\t\t      |---------------|");
    printf("\n\t\t\t\t\t\t      | DEPOSIT BOOKS |");
    printf("\n\t\t\t\t\t\t      |---------------|\n");
    printf("\n\n\t\t\t\t\t\tEnter Book Id: ");
    scanf("%d", &d);
    
    book_db = fopen("list.txt", "r+");
    
    rewind(book_db);
    while(fread(&b, sizeof(b), 1, book_db) == 1) {
        if(d == b.id) {

            printf("\n\t\t\t\t\t\t--Book__Info--");
            printf("\n\t\t\t\t\t\t~~~~~~~~~~~~~~\n");
            printf("\n\n\t\t\t\tBook ID: %d", b.id);
            printf("\n\t\t\t\tBook Name: %s", b.name);
            printf("\n\t\t\t\tBook Author: %s", b.author);
            printf("\n\t\t\t\tBook Genre: %s", b.cat);
            printf("\n\t\t\t\tBook Quantity: %d", b.quantity);
            
            printf("\n\n\n\t\t\t\t\tPress y to confirm");
            
            fflush(stdin);
            if(getch() == 'y' || getch() == "Y") {
                
                b.quantity = (b.quantity)+1;
                fseek(book_db, ftell(book_db)-sizeof(b), 0);
                fwrite(&b, sizeof(b), 1, book_db);
                fclose(book_db);
                flag = 1;
                break;
            }
        }
    }
    
    if(flag == 0) {
    printf("\n\t\t\t\t\tBook Not Found. Please Cheack Id again ");
    printf("\n\t\t\t\t\t\t                            ~~ \n");
    printf("\n\n\t\t\t\t\tPress any Key to return...");
    fflush(stdin);
    getch();
    user();
    }
    else {
    printf("\n\t\t\t\t\tBook Has deposit seccessfully ");
    printf("\n\n\t\t\t\t\tPress any Key to return...");
    fflush(stdin);
    getch();
    user();
    }
    
}

void admin_password() {
   
    char username[15]; 
    char admin_pass[12]; 
 
 
    printf("\n\t\t\t\t\tEnter your username: "); 
    scanf("%s",&username); 
 
    printf("\n\t\t\t\t\tEnter your password: "); 
    scanf("%s",&admin_pass); 
 
    if(strcmp(username,"admin")==0) { 
        
        if(strcmp(admin_pass,"admin")==0) { 
 
        printf("\n\t\t\t\t\tPassword Matched! Press any key to continue.");
        getch();
        system("cls");
        admin();
        }
        
        else { 
        printf("\n\t\t\t\t\tWrong password. Try again\n");
        admin_password();
        } 
    }
    
    else { 
    printf("\nMake sure you are Admin\n");
    welcome();
    
}

void user_password() {
    
    char username[15]; 
    char admin_pass[12]; 
 
 
    printf("\n\t\t\t\t\tEnter your username: "); 
    scanf("%s",&username); 
 
    printf("\n\t\t\t\t\tEnter your password: "); 
    scanf("%s",&admin_pass); 
 
    if(strcmp(username,"user")==0) { 
        
        if(strcmp(admin_pass,"user")==0) { 
 
        printf("\n\t\t\t\t\tPassword Matched! Press any key to continue.");
        getch();
        system("cls");
        user();
        }
        
        else { 
        printf("\n\t\t\t\t\tWrong password. Try again\n");
        user_password();
        } 
    }
    
    else { 
    printf("\nUser Not found\n");
    welcome();
    } 
}

void credit() {
    system("cls");
    head_er();
    printf("\n\t\t\t\t\t\t\tOur Team Member");
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t  Abdul Fattah Mujtabir Samin \n\t\t\t\t\t\t        203-15-3878 PC-A");
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t     Afjal Hossain Shenam \n\t\t\t\t\t\t       203-15-3878 PC-A");
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t      Shayed Hasan Shakib \n\t\t\t\t\t\t        203-15-3878 PC-A");
    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t    Mostafizur Rahman Mohor \n\t\t\t\t\t\t       203-15-3878 PC-A");
    Sleep(1000);
    printf("\n\n\n\t\t\t\t\t\t\t    Thank You\n");
    
    getch();
    Sleep(2000);
    return 0;
}