
void head_er();
void welcome();
void admin();
void user();
void browse();



void head_er(){
    printf("\t\t\t\t=============Welcome to the Virtual Library=============\n");
    printf("\t\t\t\t\t-----------------------------------------\n");        
    printf("\t\t\t\t\tThis is Demo, Please consider any Bug :3\n");
    printf("\t\t\t\t\t-----------------------------------------\n");
    printf("\n\t\t\t\tChose One Option Below\n");
}


void welcome() {
    head_er();
    int n;
    printf("\n\t\t\t\t1.Admin\n\t\t\t\t2.User\n\t\t\t\t3.Browse\n");
    printf("\n\t\t\t\tNow Chose: "); 
    scanf("%d", &n);
    
    switch(n) {
        case 1: admin(); break;
        case 2: user(); break;
        case 3: browse(); break;
        default: welcome();
    }
    
}


void admin() {
    int n;
    printf("\n\t\t\t\t Welcome to the Admin Page\n");
    printf("\n\t\t\t\t1.Add Books\n\t\t\t\t2.View Books\n\t\t\t\t3.Search Book\n");
    printf("\n\t\t\t\tNow Chose: "); 
    scanf("%d", &n);
    switch(n) {
        case 1: add_books(); break;
        case 2: view_books(); break;
        case 3: search_books(); break;
        deafult: admin();
    }
}
void user() {
    printf("\n\t\t\t\tThis is User Page\n");
}
void browse() {
    printf("\n\t\t\t\tThis is Browser Page\n");
}

void add_books() {
    printf("\nAdd Books\n");
    printf("\nRemove Books\n");
    printf("\nYou are the admin, do whatever you can\n");
}

void view_books() {
    printf("\n\t\t\t\tWanna see all books? leter\n");
}

void search_books() {
    printf("\n\t\t\t\tthis is not a google company\n");
}
