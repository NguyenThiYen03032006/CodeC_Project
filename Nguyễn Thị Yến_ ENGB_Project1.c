#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
/*
 char admin[50]="nguyenvana";
 char password1[50]="nva@gmail.com";
 char student[50]="nguyenvanb";
 char password2[50]="nvb@gmail.com";
 char teacher[50]="nguyenvanc";
 char password3[50]="nvc@gmail.com";
 */
struct Date{
    int month, day, year;
};

struct Student{
    char studentId[10];
    char studentName[50];
    char classroomId[10];
    struct Date dateOfBirth;
    bool gender;
    char email[30];
    char phone[15];
    char password[20];
};

struct Classroom{
    char classroomId[10];
    char teacherId[10];
    char classroomName[10];
    struct Student students[];
};

struct Teacher{
    char teacherId[10];
    char Name[20];
    struct Date dateOfBirth;
    bool gender;
    char Email[30];
    char Phone[20];
    char password[20];
    struct Classroom classrooms[];
};

void startTheProgram(int *choiceSystem);

void endTheProgram(int *flag);

int startAdminMenu(int *choiceMenu);

void studentMenu(int *choiceStudentMenu, int *numberStudent, struct Student *sv, struct Student *sv1, char *choose, struct Student *sv6,struct Student *sv3, struct Student *sv0, int *flag);
void startStudentMenu(int *choiceStudentMenu);
void getStudentByFile(int *numberStudent, struct Student *sv);
void saveStudent(struct Student *sv);
char addANewStudent(int *numberStudent, struct Student *sv, struct Student *sv1, char *choose, struct Student *sv0);
char showAllStudent(int *numberStudent, struct Student *sv, char *choose);
char searchStudent(int *numberStudent, struct Student *sv, char *choose, struct Student *sv3);
char fixStudent(int *numberStudent, struct Student *sv, char *choose);
char deleteStudent(int *numberStudent, struct Student *sv, char *choose);
char arrangeStudent(int *numberStudent, struct Student *sv, char *choose, struct Student *sv6);
bool checkStudent(struct Student *sv0, int*numberStudent,struct Student *sv);
void loadStudent(int *numberStudent,struct Student *sv);


void teacherMenu(int *choiceTeacherMenu, int *numberTeacher, struct Teacher *tc, struct Teacher *tc1, char *choose, struct Teacher *tc3, struct Teacher *tc0, int *flag);
void startTeacherMenu(int *choiceTeacherMenu);
void getTeacherByFile(int *numberTeacher, struct Teacher *tc);
void saveTeacher(struct Teacher *tc);
char addANewTeacher(int *numberTeacher, struct Teacher *tc, struct Teacher *tc1, char *choose, struct Teacher *tc0);
bool checkTeacher(struct Teacher *tc0, int*numberTeacher,struct Teacher *tc);
char showAllTeacher(int *numberTeacher, struct Teacher *tc, char *choose);
char searchTeacher(int *numberTeacher, struct Teacher *tc, char *choose, struct Teacher *tc3);
char fixTeacher(int *numberTeacher, struct Teacher *tc, char *choose);
char deleteTeacher(int *numberTeacher, struct Teacher *tc, char *choose);
void loadTeacher(int *numberTeacher,struct Teacher *tc);

void classroomMenu(int *choiceClassMenu, int *numberClass, struct Classroom *c, struct Classroom *c1, char *choose, struct Classroom *c6,struct Classroom *c3, struct Classroom *c0, int *flag, int *memberStudent, struct Student *sv);
void startClassMenu(int *choiceClassMenu);
char addANewClass(int *numberClass, struct Classroom *c, struct Classroom *c1, char *choose, struct Classroom *c0);
char showAllClass(int *numberClass, struct Classroom *c, char *choose, int *memberStudent);

void addStudentToClass(struct Student *sv,struct Classroom *c, int *numberStudent, int *memberStudent, int *count);
char fixClass(int *numberClass, struct Classroom *c, char *choose, int *memberStudent, int *numberStudent, struct Student *sv);

int main(void) {
    int choiceSystem=-1, choiceStudentMenu=-1, choiceMenu=-1, flag=-1, numberStudent=0;
    int choiceTeacherMenu=-1, numberTeacher=0;
    int choiceClassMenu=-1, numberClass=0, member=0;
    int memberStudent[member];
    char choose='a';

    struct Student sv[100];
    struct Student sv0;
    struct Student sv1;
    struct Student sv3;
    struct Student sv6;
    
    struct Teacher tc[100];
    struct Teacher tc0;
    struct Teacher tc1;
    struct Teacher tc3;
    
    struct Classroom c[100];
    struct Classroom c0;
    struct Classroom c1;
    struct Classroom c3;
    struct Classroom c6;
    
    char adminEmail[50];
    char adminPassword[20];
    char studentEmail[50];
    char studentPassword[20];
    char teacherEmail[50];
    char teacherPassword[20];
    
    loadStudent(&numberStudent, sv);
    loadTeacher(&numberTeacher, tc);
    getStudentByFile(&numberStudent, sv);
    getTeacherByFile(&numberTeacher, tc);
    do{
        startTheProgram(&choiceSystem);
        switch(choiceSystem){
            case 1: // cong viec của admin
                flag=1;
                printf("***Admin Management System Using C*** \n \n");
                printf("          LOGIN \n");
                printf("------------------------------ \n");
                printf("------------------------------ \n");
                printf("EMAIL :");
                fgets(adminEmail,50,stdin);
                adminEmail[strcspn(adminEmail, "\n")] = '\0';
                printf("Password :");
                fgets(adminPassword,50,stdin);
                adminPassword[strcspn(adminPassword, "\n")] = '\0';
                char admin[50]="nguyenvana";
                char password1[50]="nva@gmail.com";
                if(strcmp(admin,adminEmail)!=0 || strcmp(password1,adminPassword)!=0){
                    printf("Wrong login name or password admin !\n \n \n");
                    endTheProgram(&flag);
                    return 0;
                }
                do{
                    startAdminMenu(&choiceMenu);
                    switch(choiceMenu){ // quan ly
                        case 1: // sinh vien
                            studentMenu(&choiceStudentMenu, &numberStudent, sv, &sv1, &choose, &sv6,&sv3, &sv0, &flag);
                            break;
                        case 2: // lop hoc
                            classroomMenu(&choiceClassMenu, &numberClass, c, &c1, &choose, &c6,&c3, &c0, &flag, memberStudent, sv);
                            break;
                        case 3: //giao vien
                            
                            teacherMenu(&choiceTeacherMenu, &numberTeacher, tc, &tc1, &choose,&tc3, &tc0, &flag);
                            break;
                        case 4: // user guideline
                            break;
                        case 5:// about us
                            break;
                        case 0:// exit
                            //flag=0;
                            //endTheProgram(&flag);
                            break;
                        default:
                            printf("Lua chon cua ban khong cho trong MENU \n");
                    }
                }while(choiceMenu!=0);
                break;
            case 2:
                flag=2;
                printf("***Studnet Management System Using C*** \n \n");
                printf("          LOGIN \n");
                printf("------------------------------ \n");
                printf("------------------------------ \n");
                printf("EMAIL :");
                fgets(studentEmail,50,stdin);
                studentEmail[strcspn(studentEmail, "\n")] = '\0';
                printf("Password :");
                fgets(studentPassword,50,stdin);
                studentPassword[strcspn(studentPassword, "\n")] = '\0';
                char student[50]="nguyenvanb";
                char password2[50]="nvb@gmail.com";
                if(strcmp(student,studentEmail)!=0 || strcmp(password2, studentPassword)!=0){
                    printf("Wrong login name or password student !\n \n \n");
                    endTheProgram(&flag);
                    return 0;
                }
                
                break;
            case 3:
                flag=3;
                printf("***Teacher Management System Using C*** \n \n");
                printf("          LOGIN \n");
                printf("------------------------------ \n");
                printf("------------------------------ \n");
                printf("EMAIL :");
                fgets(teacherEmail,50,stdin);
                teacherEmail[strcspn(teacherEmail, "\n")] = '\0';
                printf("Password :");
                fgets(teacherPassword,50,stdin);
                teacherPassword[strcspn(teacherPassword, "\n")] = '\0';
                char teacher[50]="nguyenvanc";
                char password3[50]="nvc@gmail.com";
                if(strcmp(teacher,teacherEmail)!=0 || strcmp(password3,teacherPassword)!=0){
                    printf("Wrong login name or password teacher !\n \n \n");
                    endTheProgram(&flag);
                    return 0;
                }
                break;
            case 0:
                flag=0;
                endTheProgram(&flag);
                return 1;
                break;
            default:
                printf("Your choose is invalid \n");
        }
    }while(flag!=0);
    return 0;
}

void getStudentByFile(int *numberStudent, struct Student *sv){
    FILE *fileSV;
    fileSV= fopen("student.bin","wb");
    if(fileSV == NULL){
        printf("Error opening file \n");
        return;
    }
    *numberStudent=(int)fread(&sv,sizeof(struct Student),1,fileSV);
    fclose(fileSV);
}

void saveStudent(struct Student *sv){
    FILE *fileSV;
    fileSV = fopen("student.bin", "wb");
    fwrite(sv, sizeof(struct Student), 1, fileSV);
    fclose(fileSV);
}

void startTheProgram(int *choiceSystem){
    printf("***Student Management System Using C***\n\n");
    printf("\t\t\tCHOOSE YOUR ROLE \n");
    printf("\t\t========================\n");
    printf("\t\t[1] Admin.\n");
    printf("\t\t[2] Student.\n");
    printf("\t\t[3] Teacher.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t========================\n");
    printf("\t\tEnter The Choice: ");
    scanf("%d", choiceSystem);
    getchar();
}

void endTheProgram(int *flag){
    printf("\t\t ========= Thank You =========\n");
    printf("\t\t ========= See You Soon ======\n\n");
    printf("\t\t-------------------------------\n");
    
}

int startAdminMenu(int *choiceMenu){
    printf("***Student Management System Using C***");
    printf("\n\n");
    printf("\t\t\t\tMENU \n");
    printf("\t\t===========================\n");
    printf("\t\t[1] Student management.\n");
    printf("\t\t[2] Classrooms management.\n");
    printf("\t\t[3] Teacher management.\n");
    printf("\t\t[4] User Guideline.\n");
    printf("\t\t[5] About Us\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t============================\n");
    printf("\t\tEnter The Choice: ");
    scanf("%d", choiceMenu);
    return *choiceMenu;
}

void studentMenu(int *choiceStudentMenu, int *numberStudent, struct Student *sv, struct Student *sv1, char *choose, struct Student *sv6, struct Student *sv3, struct Student *sv0, int *flag){
    do{
        startStudentMenu(choiceStudentMenu);
        switch(*choiceStudentMenu){
            case 1:
                
                addANewStudent(numberStudent, sv, sv1, choose, sv0);
                break;
            case 2:
                showAllStudent(numberStudent, sv, choose);
                break;
            case 3:
                searchStudent(numberStudent, sv, choose, sv3);
                break;
            case 4:
                fixStudent(numberStudent,sv, choose);
                break;
            case 5:
                deleteStudent(numberStudent,sv, choose);
                break;
            case 6:
                arrangeStudent(numberStudent,sv, choose, sv6);
                break;
            case 0:
                
                break;
            default:
                printf("Your choose is invalid \n");
                
        }
    }while(*choiceStudentMenu!=0);
   // }while(*choose!='0');
}
void startStudentMenu(int *choiceStudentMenu){
    printf("***Student Management System Using C***");
    printf("\n\n");
    printf("\t\t\t  STUDENT MENU \n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New Student.\n");
    printf("\t\t[2] Show All Student.\n");
    printf("\t\t[3] Search A Student.\n");
    printf("\t\t[4] Edit A Student.\n");
    printf("\t\t[5] Delete A Student\n");
    printf("\t\t[6] Arrange A Student\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t========================\n");
    printf("\t\tEnter The Choice: ");
    scanf("%d", choiceStudentMenu);
    system("clearn");
}
char showAllStudent(int *numberStudent, struct Student *sv, char *choose){
    printf("\t\t\t**** All Student **** \n\n");
    printf("|==========|====================|=========================|===============|===============|\n");   //10,20,25,15,11,15
    printf("|    ID    |        Name        |          Email          |     Phone     | Date Of Birth |\n");
    printf("|==========|====================|=========================|===============|===============|\n");
    if(*numberStudent >0){
        
        for(int i=0; i< *numberStudent; i++){
            printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv[i].studentId, sv[i].studentName,sv[i].email, sv[i].phone,sv[i].dateOfBirth.day,sv[i].dateOfBirth.month,sv[i].dateOfBirth.year);
            printf("|----------|--------------------|-------------------------|---------------|---------------|\n");
        }
    }
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
    
char addANewStudent(int *numberStudent, struct Student *sv, struct Student *sv1, char *choose, struct Student *sv0){
    printf("\t\t**** Add A New Student ****\n\n");
    // ktra id ton tai chua
    getchar();
    while(1){
        int flag=-1;
        printf("Enter The ID: ");
        fgets(sv1->studentId, 10, stdin);
        sv1->studentId[strcspn(sv1->studentId, "\n")] = '\0';
        for(int i=0; i< *numberStudent; i++){
            if(strcmp(sv1->studentId,sv[i].studentId)==0){
                printf("ID already exists. \n");
                flag=1;
                break;
            }
        }
        if(flag==-1){
            break;
        }
    }
    printf("Enter The Name: ");
    fgets(sv1->studentName, sizeof(sv1->studentName), stdin);
    sv1->studentName[strcspn(sv1->studentName,"\n")]='\0';
    
    printf("Enter The Email: ");
    fgets(sv1->email, sizeof(sv1->email), stdin);
    sv1->email[strcspn(sv1->email,"\n")]='\0';
    
    printf("Enter The Phone: ");
    fgets(sv1->phone, sizeof(sv1->phone), stdin);
    sv1->phone[strcspn(sv1->phone,"\n")]='\0';
    
    printf("Enter The Date of Birth(day/month/year)\n");
    printf("Day: ");
    scanf("%d", &sv1->dateOfBirth.day);
    getchar();
    printf("Month: ");
    scanf("%d", &sv1->dateOfBirth.month);
    getchar();
    printf("Year: ");
    scanf("%d", &sv1->dateOfBirth.year);
    getchar();
    
    // check thong tin
    if(!checkStudent(sv1, numberStudent, sv)){
        printf("Invalid information \n");
        return 'c';
    }
    
    
    printf("Student Added Successfully\n");
    
    sv[*numberStudent]=*sv1;
    *numberStudent= *numberStudent+1;
    // luu file
    saveStudent(sv);
    *choose='a';
    do{
        printf("Go back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}

char searchStudent(int *numberStudent, struct Student *sv, char *choose, struct Student *sv3){
    int temp=-1;
    
    printf("Enter The Name: ");
    getchar();
    fgets(sv3->studentName, sizeof(sv3->studentName), stdin);
    sv3->studentName[strcspn(sv3->studentName, "\n")] = '\0';
    
    for(int i=0; i<*numberStudent; i++){
        if(strstr(sv[i].studentName,sv3->studentName)!=NULL){
            temp=i;
            printf("The student has been found \n");
            break;
        }
    }
    if(temp==-1){
        printf("Student not found \n");
    }else{
        printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv[temp].studentId, sv[temp].studentName,sv[temp].email, sv[temp].phone,sv[temp].dateOfBirth.day,sv[temp].dateOfBirth.month,sv[temp].dateOfBirth.year);
    }
    saveStudent(sv);
    *choose='a';
    do{
        printf("Go back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}

char fixStudent(int *numberStudent, struct Student *sv, char *choose){
    int temp=-1;
    char id[10];
    getchar();
    printf("Enter The ID: ");
    fgets(id, 10, stdin);
    id[strcspn(id,"\n")]='\0';
    
    // ktra id
    for(int i=0; i<*numberStudent; i++){
        if(strcmp(id,sv[i].studentId)==0){
            temp=i;
            break;
        }
    }
    if(temp==-1){
        printf("Student not found  \n");
        return 'c';
    }
    // in thong tin sv tim duoc
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv[temp].studentId, sv[temp].studentName,sv[temp].email, sv[temp].phone,sv[temp].dateOfBirth.day,sv[temp].dateOfBirth.month,sv[temp].dateOfBirth.year);
    // sua thong tin
    printf("Enter The New Name: ");
    fgets(sv[temp].studentName, 50, stdin);
    sv[temp].studentName[strcspn(sv[temp].studentName,"\n")]='\0';
    printf("Enter The New Email: ");
    fgets(sv[temp].email, 30, stdin);
    sv[temp].email[strcspn(sv[temp].email,"\n")]='\0';
    printf("Enter The New Phone: ");
    fgets(sv[temp].phone, 15, stdin);
    sv[temp].phone[strcspn(sv[temp].phone,"\n")]='\0';
    printf("Enter The Date of Birth(day/month/year)\n");
    printf("Day: ");
    scanf("%d", &sv[temp].dateOfBirth.day);
    getchar();
    printf("Month: ");
    scanf("%d", &sv[temp].dateOfBirth.month);
    getchar();
    printf("Year: ");
    scanf("%d", &sv[temp].dateOfBirth.year);
    getchar();
    // check thong tin sua
    if(!checkStudent(&sv[temp], numberStudent, sv)){
        printf("Invalid information \n");
        return 'c';
    }
    // luu file
    saveStudent(sv);
    *choose='a';
    do{
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%s", choose);
    }while(*choose != '0' && *choose != 'b');

    return *choose;
}

char deleteStudent(int *numberStudent, struct Student *sv, char *choose){
    int temp=-1;
    char confirm = 'c';
    char id[10];
    getchar();
    printf("Enter the student Id you want to delete: ");
    fgets(id, 10, stdin);
    id[strcspn(id,"\n")]='\0';
    
    // ktra id
    for(int i=0; i<*numberStudent; i++){
        if(strcmp(id,sv[i].studentId)==0){
            temp=i;
            break;
        }
    }
    if(temp==-1){
        printf("\nStudent not found \n\n");
        return 'c';
    }
    
    printf("The student Id %s has been found \n", id);
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv[temp].studentId, sv[temp].studentName,sv[temp].email, sv[temp].phone,sv[temp].dateOfBirth.day,sv[temp].dateOfBirth.month,sv[temp].dateOfBirth.year);
    
    // xac nhan xoa sv
    do{
        printf("Are you sure %s (Yes (y)? or No(n): ", id);
        scanf("%c", &confirm);
    }while(confirm !='y' && confirm != 'n');
    
    // xoa sv
    if(confirm == 'y'){
        for(int i=temp; i< *numberStudent -1; i++){
            sv[i]=sv[i+1];
        }
        *numberStudent= *numberStudent -1;
        printf("Delete successfully \n");
        
    }
    saveStudent(sv);
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%s", choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
char arrangeStudent(int *numberStudent, struct Student *sv, char *choose, struct Student *sv6){
    int temp=0;
    char letter[*numberStudent-1];
    printf("Howw do you want to arrange? \n");
    do{
        printf("A->Z(1) or Z->A(2): ");
        scanf("%d", &temp);
        
    }while(temp!=1 && temp!=2);
   
   
    for(int k=0; k<*numberStudent; k++){// do tung ten
        if(sv[k].studentName[0]!=' '){
            letter[k]=sv[k].studentName[0];
        }
        for(int j=0; j<strlen(sv[k].studentName); j++){//do tung chu trong ten
            if(sv[k].studentName[j]==' '){
                if(sv[k].studentName[j+1] !=' '){
                    letter[k]=sv[k].studentName[j+1];

                }
            }
        }
    }
    if(temp==2){ // z->a
        for(int i=0; i<*numberStudent-1; i++){
            for(int n=i+1; n<*numberStudent; n++){
                if(letter[i]< letter[n]){
                    *sv6=sv[i];
                    sv[i]=sv[n];
                    sv[n]=*sv6;
                }
            }
        }
    }
    if(temp==1){// a-> z
        for(int i=0; i<*numberStudent-1; i++){
            for(int n=i+1; n<*numberStudent; n++){
                if(letter[i]> letter[n]){
                    *sv6=sv[i];
                    sv[i]=sv[n];
                    sv[n]=*sv6;
                }
            }
        }
    }
    printf("Successful arrangement \n");
    saveStudent(sv);
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%s", choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
bool checkStudent(struct Student *sv0,int *numberStudent,struct Student *sv){
    // xac nhan ko bo sot thong tin
    int temp=0;
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv0->studentId, sv0->studentName,sv0->email, sv0->phone,sv0->dateOfBirth.day,sv0->dateOfBirth.month,sv0->dateOfBirth.year);
    if(strlen(sv0->studentName)==0 || strlen(sv0->studentId)==0 || strlen(sv0->email)==0 || strlen(sv0->phone)==0){
        printf("Information is missing \n");
        temp++;
    }
    // xac nhan email co @ vs .
    if (strchr(sv0->email, '@') == NULL || strchr(sv0->email, '.') == NULL) {
            printf("wrong email \n");
        temp++;
        }
    // xac nhan sdt chi chua so
    for (int i = 0; i < strlen(sv0->phone); i++) {
            if (!isdigit(sv0->phone[i])) {
                printf("Invalid phone number \n");
                temp++;
            }
        }
    // ktra do dai sdt
    if (strlen(sv0->phone) < 10 || strlen(sv0->phone) > 15) {
            printf("Phone number includes 10 to 15 numbers \n");
        temp++;
        }
    // ktra thong in sv
    for(int i=0; i< *numberStudent; i++){
        if(strcmp(sv0->studentName,sv[i].studentName)==0){
            printf("Name already exists \n");
            temp++;
        }
        if(strcmp(sv0->email,sv[i].email)==0){
            printf("Email already exists \n");
            temp++;
        }
        if(strcmp(sv0->phone,sv[i].phone)==0){
            printf("Phone number already exists \n");
            temp++;
        }
    }
    if(temp!=0){
        return false;
    }
    if(sv0->dateOfBirth.month<=12 && sv0->dateOfBirth.month>0){
        if(sv0->dateOfBirth.month==1|| sv0->dateOfBirth.month==3 || sv0->dateOfBirth.month==5 || sv0->dateOfBirth.month==7 || sv0->dateOfBirth.month==8 || sv0->dateOfBirth.month==9 || sv0->dateOfBirth.month==12){
            if(sv0->dateOfBirth.day>32 || sv0->dateOfBirth.day<1){
                printf("Invalid information \n");
                return false;
            }
        }
        if(sv0->dateOfBirth.month==4 || sv0->dateOfBirth.month==6 || sv0->dateOfBirth.month==9 || sv0->dateOfBirth.month== 11){
            if(sv0->dateOfBirth.day>31 || sv0->dateOfBirth.day<1){
                printf("Invalid information \n");
                return false;
            }
        }
        if(sv0->dateOfBirth.month==2){
            if(sv0->dateOfBirth.year % 400 ==0 || (sv0->dateOfBirth.year % 4 ==0 && sv0->dateOfBirth.year % 100 !=0)){
                if(sv0->dateOfBirth.day>30 || sv0->dateOfBirth.day<1){
                    printf("Invalid information \n");
                    return false;
                }
            }else{
                if(sv0->dateOfBirth.day>29 || sv0->dateOfBirth.day<1){
                    printf("Invalid information \n");
                    return false;
                }
            }
        }
    }else{
        printf("Invalid information \n");
        return false;
    }
        
    return true;
}
void loadStudent(int *numberStudent,struct Student *sv) {
    FILE *file = fopen("student.bin", "rb");
    if (file != NULL) {
        fread(numberStudent, sizeof(int), 1, file);
        fread(sv, sizeof(struct Student), *numberStudent, file);
        fclose(file);
    }
}


void startTeacherMenu(int *choiceTeacherMenu){
    printf("***Teacher Management System Using C***");
    printf("\n\n");
    printf("\t\t\t  TEACHER MENU \n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New Teacher.\n");
    printf("\t\t[2] Show All Teacher.\n");
    printf("\t\t[3] Search A Teacher.\n");
    printf("\t\t[4] Edit A Teacher.\n");
    printf("\t\t[5] Delete A Teacher.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t========================\n");
    printf("\t\tEnter The Choice: ");
    scanf("%d", choiceTeacherMenu);
}

void teacherMenu(int *choiceTeacherMenu, int *numberTeacher, struct Teacher *tc, struct Teacher *tc1, char *choose, struct Teacher *tc3, struct Teacher *tc0, int *flag){
    
    do{
        startTeacherMenu(choiceTeacherMenu);
        switch(*choiceTeacherMenu){
            case 1:
                addANewTeacher(numberTeacher, tc, tc1, choose, tc0);
                break;
            case 2:
                showAllTeacher(numberTeacher, tc, choose);
                break;
            case 3:
                searchTeacher(numberTeacher, tc, choose, tc3);
                break;
            case 4:
                fixTeacher(numberTeacher,tc, choose);
                break;
            case 5:
                deleteTeacher(numberTeacher,tc, choose);
                break;
            case 0:
               
                break;
            default:
                printf("Your choose is invalid \n");
        }
    }while(*choose!=0);
}

void getTeacherByFile(int *numberTeacher, struct Teacher *tc){
    FILE *fileTC;
    fileTC= fopen("teacher.bin","wb");
    if(fileTC == NULL){
        printf("Error opening file \n");
        return;
    }
    *numberTeacher=(int)fread(&tc,sizeof(struct Teacher),1,fileTC);
    fclose(fileTC);
}
void saveTeacher(struct Teacher *tc){
    FILE *fileTC;
    fileTC = fopen("teacher.bin", "wb");
    fwrite(tc, sizeof(struct Teacher), 1, fileTC);
    fclose(fileTC);
}

char addANewTeacher(int *numberTeacher, struct Teacher *tc, struct Teacher *tc1, char *choose, struct Teacher *tc0){
    printf("\t\t**** Add A New Teacher ****\n\n");
    // ktra id ton tai chua
    getchar();
    while(1){
        int flag=-1;
        printf("Enter The ID: ");
        fgets(tc1->teacherId, 10, stdin);
        tc1->teacherId[strcspn(tc1->teacherId, "\n")] = '\0';
        for(int i=0; i< *numberTeacher; i++){
            if(strcmp(tc1->teacherId,tc[i].teacherId)==0){
                printf("ID already exists. \n");
                flag=1;
                break;
            }
        }
        if(flag==-1){
            break;
        }
    }
    printf("Enter The Name: ");
    fgets(tc1->Name, sizeof(tc1->Name), stdin);
    tc1->Name[strcspn(tc1->Name,"\n")]='\0';
    
    printf("Enter The Email: ");
    fgets(tc1->Email, sizeof(tc1->Email), stdin);
    tc1->Email[strcspn(tc1->Email,"\n")]='\0';
    
    printf("Enter The Phone: ");
    fgets(tc1->Phone, sizeof(tc1->Phone), stdin);
    tc1->Phone[strcspn(tc1->Phone,"\n")]='\0';
    
    printf("Enter The Date of Birth(day/month/year)\n");
    printf("Day: ");
    scanf("%d", &tc1->dateOfBirth.day);
    getchar();
    printf("Month: ");
    scanf("%d", &tc1->dateOfBirth.month);
    getchar();
    printf("Year: ");
    scanf("%d", &tc1->dateOfBirth.year);
    getchar();
    
    // check thong tin
    if(!checkTeacher(tc1, numberTeacher, tc)){
        printf("Invalid information \n");
        return 'c';
    }
    
    
    printf("Teacher Added Successfully\n");
    
    tc[*numberTeacher]=*tc1;
    *numberTeacher= *numberTeacher+1;
    
    saveTeacher(tc);
    *choose='a';
    do{
        printf("Go back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}

bool checkTeacher(struct Teacher *tc0, int*numberTeacher,struct Teacher *tc){
    // xac nhan ko bo sot thong tin
    int temp=0;
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",tc0->teacherId, tc0->Name,tc0->Email, tc0->Phone,tc0->dateOfBirth.day,tc0->dateOfBirth.month,tc0->dateOfBirth.year);
    if(strlen(tc0->Name)==0 || strlen(tc0->teacherId)==0 || strlen(tc0->Email)==0 || strlen(tc0->Phone)==0){
        printf("Information is missing \n");
        temp++;
    }
    // xac nhan email co @ vs .
    if (strchr(tc0->Email, '@') == NULL || strchr(tc0->Email, '.') == NULL) {
            printf("wrong email \n");
        temp++;
        }
    // xac nhan sdt chi chua so
    for (int i = 0; i < strlen(tc0->Phone); i++) {
            if (!isdigit(tc0->Phone[i])) {
                printf("Invalid phone number \n");
                temp++;
            }
        }
    // ktra do dai sdt
    if (strlen(tc0->Phone) < 10 || strlen(tc0->Phone) > 15) {
            printf("Phone number includes 10 to 15 numbers \n");
        temp++;
        }
    // ktra thong in sv
    for(int i=0; i< *numberTeacher; i++){
        if(strcmp(tc0->Name,tc[i].Name)==0){
            printf("Name already exists. \n");
            temp++;
        }
        if(strcmp(tc0->Email,tc[i].Email)==0){
            printf("Email already exists. \n");
            temp++;
        }
        if(strcmp(tc0->Phone,tc[i].Phone)==0){
            printf("Phone number already exists. \n");
            temp++;
        }
    }
    if(temp!=0){
        return false;
    }
    if(tc0->dateOfBirth.month<=12 && tc0->dateOfBirth.month>0){
        if(tc0->dateOfBirth.month==1|| tc0->dateOfBirth.month==3 || tc0->dateOfBirth.month==5 || tc0->dateOfBirth.month==7 || tc0->dateOfBirth.month==8 || tc0->dateOfBirth.month==9 || tc0->dateOfBirth.month==12){
            if(tc0->dateOfBirth.day>32 || tc0->dateOfBirth.day<1){
                printf("Invalid information  \n");
                return false;
            }
        }
        if(tc0->dateOfBirth.month==4 || tc0->dateOfBirth.month==6 || tc0->dateOfBirth.month==9 || tc0->dateOfBirth.month== 11){
            if(tc0->dateOfBirth.day>31 || tc0->dateOfBirth.day<1){
                printf("Invalid information  \n");
                return false;
            }
        }
        if(tc0->dateOfBirth.month==2){
            if(tc0->dateOfBirth.year % 400 ==0 || (tc0->dateOfBirth.year % 4 ==0 && tc0->dateOfBirth.year % 100 !=0)){
                if(tc0->dateOfBirth.day>30 || tc0->dateOfBirth.day<1){
                    printf("Invalid information  \n");
                    return false;
                }
            }else{
                if(tc0->dateOfBirth.day>29 || tc0->dateOfBirth.day<1){
                    printf("Invalid information  \n");
                    return false;
                }
            }
        }
    
        if(tc0->dateOfBirth.year>=1000 && tc0->dateOfBirth.year<=9999){
            printf("Invalid information  \n");
            return false;
        }
    }else{
        printf("Invalid information \n");
        return false;
    }
        
    return true;
}

char showAllTeacher(int *numberTeacher, struct Teacher *tc, char *choose){
    printf("\t\t\t**** All Teacher **** \n\n");
    printf("|==========|====================|=========================|===============|===============|\n");   //10,20,25,15,11,15
    printf("|    ID    |        Name        |          Email          |     Phone     | Date Of Birth |\n");
    printf("|==========|====================|=========================|===============|===============|\n");
    if(*numberTeacher >0){
        
        for(int i=0; i< *numberTeacher; i++){
            printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",tc[i].teacherId, tc[i].Name,tc[i].Email, tc[i].Phone,tc[i].dateOfBirth.day,tc[i].dateOfBirth.month,tc[i].dateOfBirth.year);
            printf("|----------|--------------------|-------------------------|---------------|---------------|\n");
        }
    }
    
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}

char searchTeacher(int *numberTeacher, struct Teacher *tc, char *choose, struct Teacher *tc3){
    int temp=-1;
    
    printf("Enter The Name: ");
    getchar();
    fgets(tc3->Name, sizeof(tc3->Name), stdin);
    tc3->Name[strcspn(tc3->Name, "\n")] = '\0';
    
    for(int i=0; i<*numberTeacher; i++){
        if(strstr(tc[i].Name,tc3->Name)!=NULL){
            temp=i;
            printf("The teacher has been found \n");
            break;
        }
    }

    if(temp==-1){
        printf("Teacher not found \n");
    }else{
        printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",tc[temp].teacherId, tc[temp].Name,tc[temp].Email, tc[temp].Phone,tc[temp].dateOfBirth.day,tc[temp].dateOfBirth.month,tc[temp].dateOfBirth.year);
    }
    
    *choose='a';
    do{
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;

}
char fixTeacher(int *numberTeacher, struct Teacher *tc, char *choose){
    
    int temp=-1;
    char id[10];
    getchar();
    printf("Enter The ID: ");
    fgets(id, 10, stdin);
    id[strcspn(id,"\n")]='\0';
    
    // ktra id
    for(int i=0; i<*numberTeacher; i++){
        if(strcmp(id,tc[i].teacherId)==0){
            temp=i;
            break;
        }
    }
    if(temp==-1){
        printf("Teacher not found \n");
        return 'c';
    }
    // in thong tin sv tim duoc
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",tc[temp].teacherId, tc[temp].Name,tc[temp].Email, tc[temp].Phone,tc[temp].dateOfBirth.day,tc[temp].dateOfBirth.month,tc[temp].dateOfBirth.year);
    // sua thong tin
    printf("Enter The New Name: ");
    fgets(tc[temp].Name, 50, stdin);
    tc[temp].Name[strcspn(tc[temp].Name,"\n")]='\0';
    printf("Enter The New Email: ");
    fgets(tc[temp].Email, 30, stdin);
    tc[temp].Email[strcspn(tc[temp].Email,"\n")]='\0';
    printf("Enter The New Phone Number: ");
    fgets(tc[temp].Phone, 15, stdin);
    tc[temp].Phone[strcspn(tc[temp].Phone,"\n")]='\0';
    printf("Enter The Date of Birth(day/month/year)\n");
    printf("Day: ");
    scanf("%d", &tc[temp].dateOfBirth.day);
    getchar();
    printf("Month: ");
    scanf("%d", &tc[temp].dateOfBirth.month);
    getchar();
    printf("Year: ");
    scanf("%d", &tc[temp].dateOfBirth.year);
    getchar();
    // check thong tin sua
    if(!checkTeacher(&tc[temp], numberTeacher, tc)){
        printf("Invalid information \n");
        return 'c';
    }
    // luu file
    saveTeacher(tc);
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
char deleteTeacher(int *numberTeacher, struct Teacher *tc, char *choose){
    int temp=-1;
    char confirm = 'c';
    char id[10];
    getchar();
    printf("Enter the teacher Id you want to delete:  ");
    fgets(id, 10, stdin);
    id[strcspn(id,"\n")]='\0';
    
    // ktra id
    for(int i=0; i<*numberTeacher; i++){
        if(strcmp(id,tc[i].teacherId)==0){
            temp=i;
            break;
        }
    }
    if(temp==-1){
        printf("\nTeacher not found \n\n");
        return 'c';
    }
    
    printf("The teacher Id %s has been found \n", id);
    printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",tc[temp].teacherId, tc[temp].Name,tc[temp].Email, tc[temp].Phone,tc[temp].dateOfBirth.day,tc[temp].dateOfBirth.month,tc[temp].dateOfBirth.year);
    
    // xac nhan xoa gv
    do{
        printf("Are you sure %s (Yes (y)? or No(n): ", id);
        scanf("%c", &confirm);
    }while(confirm !='y' && confirm != 'n');
    
    // xoa gv
    if(confirm == 'y'){
        for(int i=temp; i< *numberTeacher -1; i++){
            tc[i]=tc[i+1];
        }
        *numberTeacher= *numberTeacher -1;
        printf("Delete successfully \n");
        
    }
    
    saveTeacher(tc);
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
void loadTeacher(int *numberTeacher,struct Teacher *tc) {
    FILE *file = fopen("teacher.bin", "rb");
    if (file != NULL) {
        fread(numberTeacher, sizeof(int), 1, file);
        fread(tc, sizeof(struct Teacher), *numberTeacher, file);
        fclose(file);
    }
}

void classroomMenu(int *choiceClassMenu, int *numberClass, struct Classroom *c, struct Classroom *c1, char *choose, struct Classroom *c6,struct Classroom *c3, struct Classroom *c0, int *flag, int *memberStudent, struct Student *sv){
    do{
        startClassMenu(choiceClassMenu);
        switch(*choiceClassMenu){
            case 1:
                addANewClass(numberClass,c,c1, choose, c0);
                break;
            case 2:
                showAllClass(numberClass, c, choose, memberStudent);
                break;
            case 3:
                fixClass(numberClass, c, choose, memberStudent, numberClass, sv);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                *flag=0;
                endTheProgram(flag);
                return;
                break;
            default:
                printf("Lua chon cua ban khong hop le \n");
        }
    }while(*choose!='0');
    
}
void startClassMenu(int *choiceClassMenu){
    printf("***Class Management System Using C***");
    printf("\n\n");
    printf("\t\t\t  CLASS MENU \n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New Class.\n");
    printf("\t\t[2] Show All Class.\n");
    printf("\t\t[3] Fix A Class.\n");
    printf("\t\t[4] Search A CLass.\n");
    printf("\t\t[5] Arrange A CLass\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t========================\n");
    printf("\t\tEnter The Choice: ");
    scanf("%d", choiceClassMenu);
}

char showAllClass(int *numberClass, struct Classroom *c, char *choose, int *memberStudent){
    printf("\t\t\t**** All CLass **** \n\n");
    printf("|==========|===============|==========|==============================|\n");//10,15,10,30
    printf("|  ClassId |   ClassName   |TeacherId |           Student            |\n");
    printf("|==========|===============|==========|==============================|\n");
    if(*numberClass>0){
        for(int i=0; i< *numberClass; i++){
            printf("|%-10s|%-15s|%-10s|%-10s%-20s|\n", c[i].classroomId, c[i].classroomName, c[i].teacherId,c[i].students[0].studentId,c[i].students[0].studentName);
            if( memberStudent[i]>0){
                for(int k=1; k<= memberStudent[i]; k++){
                    printf("|          |               |          |%-10s%-20s|\n",c[i].students[k].studentId,c[i].students[k].studentName);
                }
            }
        }
        printf("|----------|---------------|----------|------------------------------|\n");
    }
    
    
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}

char addANewClass(int *numberClass, struct Classroom *c, struct Classroom *c1, char *choose, struct Classroom *c0){
    printf("\t\t**** Add A New Class ****\n\n");
    getchar();
    while(1){
        int flag=-1;
        printf("Enter The ID: ");
        fgets(c1->classroomId, 10, stdin);
        c1->classroomId[strcspn(c1->classroomId, "\n")] = '\0';
        for(int i=0; i< *numberClass; i++){
            if(strcmp(c1->classroomId,c[i].classroomId)==0){
                printf("ID already exists. \n");
                flag=1;
                break;
            }
        }
        if(flag==-1){
            break;
        }
    }
    printf("Enter The Name: ");
    fgets(c1->classroomName, sizeof(c1->classroomName), stdin);
    c1->classroomName[strcspn(c1->classroomName,"\n")]='\0';
    
    c[*numberClass]= *c1;
    *numberClass= *numberClass+1;
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
char fixClass(int *numberClass, struct Classroom *c, char *choose, int *memberStudent, int *numberStudent, struct Student *sv){
    int count=-1;
    char id[10];
    getchar();
    printf("Enter The ID: ");
    fgets(id, 10, stdin);
    id[strcspn(id,"\n")]='\0';
    
    // ktra id
    for(int i=0; i<*numberClass; i++){
        if(strcmp(id,c[i].classroomId)==0){
            count=i;
            break;
        }
    }
    if(count==-1){
        printf("Class not found \n");
        return 'c';
    }
    // in thong tin lop tim duoc

        printf("|%-10s|%-15s|%-10s|%-10s%-20s|\n", c[count].classroomId, c[count].classroomName, c[count].teacherId,c[count].students[0].studentId,c[count].students[0].studentName);
    if( memberStudent[count]>0){
        for(int k=1; k< memberStudent[count]; k++){
            printf("|          |               |          |%-10s%-20s|\n",c[count].students[k].studentId,c[count].students[k].studentName);
        }
    }
    int select=0;
    printf("\t\t[0] Not edit the student in class.\n");
    printf("\t\t[1] Add Student to Class.\n");
    printf("\t\t[2] Delete Student from Class.\n");
    printf("Your choice: ");
    do{
        scanf("%d", &select);
    } while(select!=1 && select!=2 && select !=0);
    if(select ==1){
       
        addStudentToClass(sv,c,numberStudent, memberStudent, &count);
    }
    if(select ==2){
        
    }
    *choose='a';
    do{
        getchar();
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf("%c", choose);
        printf("%c", *choose);
    }while(*choose != '0' && *choose != 'b');
    return *choose;
}
void addStudentToClass(struct Student *sv,struct Classroom *c, int *numberStudent, int *memberStudent, int *count){
    int temp=-1;
    char id[10];
    printf("Choose the student Id you want to add to the class: ");

    fgets(id,10,stdin);
    id[strcspn(id,"\n")]='\0';
    
    for(int i=0; i< *numberStudent; i++){
        if(strcmp(id, sv[i].studentId)==0){
            temp=i;
            printf("|%-10s|%-20s|%-25s|%-15s|%d/%d/%d     |\n",sv[i].studentId, sv[i].studentName,sv[i].email, sv[i].phone,sv[i].dateOfBirth.day,sv[i].dateOfBirth.month,sv[i].dateOfBirth.year);
            break;
        }
        
    }
    if(temp==-1){
        printf("Student not found \n");
        return ;
    }
    char confirm = 'c';
    do{
        printf("Are you sure (Yes(y)? or No(n): ");
        scanf("%c", &confirm);
    }while(confirm !='y' && confirm != 'n');
    strcpy(c[*count].students[*numberStudent-1].studentId, sv[temp].studentId);
    strcpy(c[*count].students[*numberStudent-1].studentName, sv[temp].studentName);
    memberStudent[temp]= memberStudent[temp]+1;
    
}
