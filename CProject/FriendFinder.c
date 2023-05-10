#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>



void gotoxy(int x, int y)
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Creating a structure to store
// data of the user
struct pass {
char name[50];
char username[50];
char field[50];
int age;
char book[10];
char game[15];
char food[20];
char pet[20];
char color[20];
char place[20];
char film[50];
char persona[20];
};
void create_account(void);
void accountcreated(void);
void login(void);
void loginsu(void);
void display(char username1[]);
void logout(void);
void user_list();
void my_friend();
//this function is to create an account
//you can create an account by entering your taste
void create_account(void)
{
char password[20];
int passwordlength, i, seek = 0;
char ch;
FILE *fp;
struct pass u1;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
// Opening file to
// write data of a user
fp = fopen("ffuserinfo.txt", "ab");

// Inputs
system("cls");
printf("\n\n\t\t\t!!!!!CREATE ACCOUNT!!!!!");

printf("\n\n ENTER YOUR REAL NAME....");
scanf("%s",u1.name);

printf("\n\n NAME and AS YOUR USER_NAME TO LOGIN..");
scanf("%s", u1.username);

printf("\n\n\nENTER YOUR AGE...");
scanf("%d", &u1.age);

printf("\n\nENTER YOUR FAVORATE COLOR....");
scanf("%s", u1.color);

printf("\n\nENTER FOOD YOU LIKE\'S THE MOST.....");
scanf("%s", u1.food);

printf("\n\nENTER WHAT TYPE OF PET DO YOU WISH FOR EXAMPLE:DOG,CAT:....");
scanf("%s", u1.pet);

printf("\n\nDREAM PLACE TO TRAVEL:");
scanf("%s", u1.place);

printf("\n\nENTER YOUR FAVOURATE GENRE OF FILM EXAMPLE:COMEDY,HORROR:....");
scanf("%s", u1.film);
printf("\n\nDO YOU PREFER READING BOOKS (YES OR NO):...");
scanf("%s", u1.book);
printf("\n\nENTER YOUR FAVORATE GAME:...");
scanf("%s", u1.game);

printf("\n\nWHAT TYPE OF PERSONALITY ARE YOU ? (EXAMPLE:CALM,INTROVERT,FEROCIOUS):...");
scanf("%s", u1.persona);

printf("\n\nWHICH FIELD ARE YOU INTERSTED IN ? EXAMPLE :ENGINEERING ,MEDICAL ,LAW :...");
scanf("%s", u1.field);

printf("\n\nCREATE YOUR OWN PASSWORD TO LOGIN TO THE TOOL....");
// Taking password in the form of
// stars
for (i = 0; i < 50; i++) {
ch = getch();
if (ch != 13) {
password[i] = ch;
ch = '*';
printf("%c", ch);
}
else
break;
}

// Writing to the file
fwrite(&u1, sizeof(u1),1, fp);

// Closing file
fclose(fp);

// Calling another function
// after successful creation
// of account
accountcreated();
}
//after the details are entered succesfully for loading the page
void accountcreated(void)
{
int i;
char ch;
system("cls");
printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
for(i=10;i>=0;i--){
system("cls");
printf("\n\n\n\n\t\t LOADING...\n\t\t\t\t%d",i);
sleep(1);
}
gotoxy(30, 10);

printf("ACCOUNT CREATED SUCCESSFULLY....");
gotoxy(0, 20);

printf("Press enter to login");
login();
getch();
}
// Login function to check
// the username of the user
void login(void)
{
system("cls");

char username[50];
char password[50];

int i, j, k;
char ch;
FILE *fp;
struct pass u1;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
// Opening file of
// user data
fp = fopen("ffuserinfo.txt","rb");

if (fp == NULL) {
printf("ERROR IN OPENING FILE");
}
gotoxy(34, 2);
printf(" ACCOUNT LOGIN ");
gotoxy(7, 5);
printf("***********************************************"
"********************************");

gotoxy(35, 10);
printf("==== LOG IN ====");

// Take input
gotoxy(35, 12);
printf("USERNAME.. ");
scanf("%s", &username);

gotoxy(35, 14);
printf("PASSWORD..");

// Input the password
for (i = 0; i < 50; i++) {
ch = getch();
if (ch != 13) {
password[i] = ch;
ch = '*';
printf("%c", ch);
}

else
break;
}

// Checking if username
// exists in the file or not
while (fread(&u1, sizeof(u1), 1, fp)) {
if (strcmp(username, u1.username)== 0) {

display(username);

loginsu();
}
}

// Closing the file
fclose(fp);
}
void loginsu(void)
{
int k;
FILE* fp;
struct pass u1;
system("cls");
printf("Fetching account details.....\n");
for(k=10;k>=0;k--){
system("cls");
printf("\n\n\n\n\t\t\tPLEASE WAIT A MINUTE...\n\t\t\t\t%d",k);
sleep(1);
}



gotoxy(30, 10);
printf("LOGIN SUCCESSFUL....");
gotoxy(0, 20);
printf("Press enter to continue");
getch();
}
// Display function to show the
// data of the user on screen
void display(char username1[])
{
system("cls");
FILE* fp;
int choice, i;
fp = fopen("ffuserinfo.txt", "rb");
struct pass u1;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
if (fp == NULL) {
printf("error in opening file");
}

while (fread(&u1, sizeof(u1), 1, fp))
{

if (strcmp(username1,u1.username)== 0) {
gotoxy(30, 1);
printf("WELCOME, %s ",u1.username);
gotoxy(28, 2);
printf("..........................");
gotoxy(55, 6);
printf("==== YOUR DETAILS INFO ====");
gotoxy(55, 8);
printf("***************************");
gotoxy(55, 9);
printf("NAME..%s ", u1.name);

gotoxy(55, 11);
printf("YOUR AGE IS ...%d ",u1.age);

gotoxy(55, 13);
printf("YOUR FAVORATE COLOR IS ...%s",u1.color);

gotoxy(55, 14);
printf("FOOD YOU LIKE THE MOST IS ...%s",u1.food);

gotoxy(55, 15);
printf("YOU LIKE THE PET AS ......%s",u1.pet);

gotoxy(55, 16);
printf("YOUR DREAM PLACE IS .....%s",u1.place);

gotoxy(55, 17);
printf("YOUR FAVOURATE GENRE OF FILM IS....%s", u1.film);

gotoxy(55, 18);
printf("YOU PREFER %s FOR READING BOOKS",u1.book);

gotoxy(55, 19);
printf("YOUR FAVORATE GAME:...%s",u1.game);
gotoxy(55, 20);
printf("YOUR PERSONALITY IS A .....%s",u1.persona);
gotoxy(55, 21);
printf("FIELD YOU INTRESTED IN IS.....%s",u1.field);
}

}
fclose(fp);

gotoxy(0, 6);

// Menu to perform different
// actions by user
printf(" HOME ");
gotoxy(0, 7);
printf("******");
gotoxy(0, 9);
printf(" 1....CHECK WITH YOUR FRIEND...");
gotoxy(0, 11);
printf(" 2....CHECK WITH USER THAT WE HAVE IN THIS TOOL...");
gotoxy(0, 13);
printf(" 3....LOG OUT AND LOG IN OTHER ACCOUNT...\n\n");
gotoxy(0, 15);
printf(" 4....EXIT\n\n");

printf(" ENTER YOUR CHOICES..");
scanf("%d", &choice);

switch (choice) {
case 1:
{
my_friend();
break;
}
case 2:
{
user_list();
break;
}
case 3:
logout();
login();
break;
case 4:
exit(0);
break;
}
}
//FOR CHECKING WITH YOUR OWN FRIEND
//AND FIND THE MATCHES BETWEEN THEM
void my_friend()
{
system("cls");
FILE* fp;
struct pass u1;
fp = fopen("ffuserinfo.txt","rb");
//INPUT YOUR FRIEND'S DETAILS HERE TO CHECK THE MATCHES BETWEEN EACH OTHER...
char colour[50],food[50],pet[50],travel[50],book[50],film[50],games[50],per[50],field[50];
int age,u,count,n,flag;// n is for number of friends you have to check with your character...
int toco[100];
// n is the number of users you wanted to choose friend from
printf("\n\tENTER THE NUMBER OF USERS U WANTED TO CHECK WITH ....");
scanf("%d" , &n);
for(u=0;u<n;u++){
count = 0;
printf("\n\tENTER THE INPUTS ACCORDING TO YOUR TASTE:...");
printf("\n\t\t\tPERSON %d" ,u+1);
//age
printf("\n\tENTER YOUR AGE:...");
scanf("%d" , &age);
if(age==u1.age)
{
count = count +1;
}
//color
printf("\n\tWHAT IS YOUR FAVOURITE COLOUR:..");
scanf("%s" , colour);
if(*colour==*u1.color)
{
count = count +1;
}
//food
printf("\n\tENTER FOOD YOU LIKE:...");
scanf("%s" , food);
if(*food==*u1.food){
count = count +1;
}
//pet
printf("\n\tWHAT type of pet do u like:..");
scanf("%s" , pet);
if(*pet==*u1.pet)
{
count = count +1;
}
//travel place
printf("\n\tDREAM PLACE TO TRAVEL:..");
scanf("%s" , travel);
if(*travel==*u1.place)
{
count = count +1;
}
//film
printf("\n\tWHAT GENRE OF FILM DO YOU LIKE ? : ...");
scanf("%s" , film);
if(*film==*u1.film)
{
count = count +1;
}
//books
printf("\n\tDO YOU PREFER READING BOOKS YES OR NO :..");
scanf("%s" , book);
if(*book==*u1.book)
{
count = count +1;
}
//game like indoor or outdoor
printf("\n\tWHAT GAME DO YOU LIKE:...");
scanf("%s" , games);
if(*games==*u1.game)
{
count = count +1;
}
//personality
printf("\n\tWHAT TYPE OF PERSONALITY ARE YOU?:...");
scanf("%s" , per);
if(*per==*u1.persona)
{
count = count +1;
}
printf("\n\tENTER IN WHICH FIELD ARE YOU INTERESTED:...");
scanf("%s" , field);
if(*field==*u1.field)
{
count = count +1;
}
//each persons data will be calculated after completion of one loop
printf("\n\tTHE NUMBER OF MATCHES MATCHED WITH PERSON %d are %d" , u+1,count);
flag = 1;
while(flag == 1)
{
toco[u] = count;
flag = 0;
}
printf("\n\tTHE PERCENTAGE THAT YOUR FRIENDSHIP CAN BE WORKED SUCCESSFULLY WITH PERSON %d is %d &" ,u+1,percent(count,u));

}
fclose(fp);
}
//for the percentage calculation this function is used
int percent(int count,int u){
int p;
if(count<=3){
p=30;
}
else if(count>3 && count<=5){
p=50;
}
else if(count>5 && count<=8){
p=75;
}
else{
p=95;
}
return p;
}
//OR HECK WITH OUR ACTIVE USERS IN THIS TOOL...
//THEN CHECK THE MATCHES BETWEEN EACH OTHER...
void user_list()
{

}
//logout function
//for loging out out and loging in with other account....
void logout(void)
{
int i, j;
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
printf("please wait, logging out");

for(i=5;i>=0;i--){
system("cls");
printf("\n\n\n\n\t\t LOGGING OUT ...\n\t\t\t\t%d",i);
sleep(1);
}
gotoxy(30, 10);
printf("Sign out successfully..\n");

gotoxy(0, 20);
printf("press any key to continue..");

getch();
}
int main()
{
int i, a, b, choice;
int passwordlength;

gotoxy(20, 3);

// Creating a Main
// menu for the user
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
printf("WELCOME TO FRIEND FINDER TOOL\n\n");
gotoxy(18, 5);

printf("**********************************");

gotoxy(20, 10);
printf("1.... CREATE AN ACCOUNT.....");

gotoxy(20, 12);
printf("2.... LOGIN....");
gotoxy(20, 14);
printf("3.... EXIT\n\n");

printf("\n\nENTER YOUR CHOICE..");

scanf("%d", &choice);

switch (choice) {
case 1:
system("cls");
printf("\n\n ENTER YOUR DETAILS CLEAR YOU CAN\'T CHANGE IT AGAIN!!");
printf("\n\n CREATE YOUR ACCOUNT HERE !!");
create_account();
break;

case 2:
login();
break;

case 3:
exit(0);
break;
getch();
}
}
