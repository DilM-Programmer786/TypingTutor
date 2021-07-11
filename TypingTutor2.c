#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<conio.h>
char printRandoms(int);
int i=1;
int flag=0;
int points=0;
int chances=2;
struct node {
int x_axis;
int y_axis;
char val;
struct node *next;
};
struct node *start;
void insertNode(){
    struct node *n;
    struct node *p;
    p=start;
    n=(struct node *) malloc(sizeof(struct node));
    n->val=printRandoms(1);
    n->x_axis=printRandoms2(1);
    n->y_axis=0;
    n->next=NULL;
 if(start==NULL){
start=n;
 }
 else{
   while(p->next!=NULL){
    p=p->next;
   }
   p->next=n;
 }
}
void deleteNode(){
 struct node *p;
 p=start;
 if(p!=NULL){
    start=start->next;
    free(p);
 }
}
void traversing(int a){
    insertNode();
struct node *p;
p=start;

while(!kbhit() && flag==0){
   for(int j=0;j<i;j++){
        gameScreen();
    gotoxy(p->x_axis,p->y_axis);
    printf("%c",p->val);
    p->y_axis++;
     p=p->next;
   }
   i++;
   Sleep(a);
    insertNode();
          system("cls");
     p=start;
     if(p->y_axis>=20){
        deleteNode();
        chances--;
         p=start;
        if(chances<0){
                system("cls");
              printf("\n\n\n\n\n\n\t\t\t\t   ----------You Lost!-----------\n");
        exit(0);
        }
         }
}
check();
        }
void check(){
    struct node *p;
    p=start;
    char c=getch();
      if(c==p->val){
        deleteNode();
        points+=10;
        flag=0;
        i--;
        if(points>100){
            printf("\n\n----------You Win-----------\n");
            exit(0);
        }
      }
      else if(c==27){
            printf("Game End!");
        exit(0);
      }
}

void deletion(){
    struct node *p;
    p=start;
if(start!=NULL){
  start=p->next;
  p->next=NULL;
  free(p);
}
}
char printRandoms(int count)
{
    int i,num;
    for (i = 0; i < count; i++) {
        num = (rand() % 25) + 65;
     //   printf("%d ", num);
    }
    return (char) num;
}
int printRandoms2(int count)
{
    int i,num;
    for (i = 0; i < count; i++) {
        num = (rand() % 75)+10;
     //   printf("%d ", num);
    }
    return num;
}
void main(){
   showMenu();
}
void showMenu(){
    for(int i=0;i<0;i++){
            system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tGame is Loading");
   Sleep(1000);
    printf(".");
     Sleep(1000);
    printf(".");
     Sleep(1000);
    printf(".");
}
   system("cls");
printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%-2dGame Mode For capital Letter\n",1);
printf("\n\t\t\t\t\t%-2dGame Mode For Small Letter\n",2);
printf("\n\t\t\t\t\t%-2dExpert Game Mode\n",3);
printf("\n\t\t\t\t\t%-2dEsc To Exit\n",3);
switch(getch()){
 case 49:
     {

         while(1){
         traversing(1000);
         }
         break;
     }
     case 50:
     {

          while(1){
         traversing(200);
         }
         break;
     }
}
}
void gotoxy(int x,int y){
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void gameScreen(){
gotoxy(15,20);
printf("---------------------------------------");
gotoxy(15,22);
printf("Points:%d\n",points);
gotoxy(15,23);
printf("Chances:%d\n",chances);
gotoxy(15,24);
printf("ESC To Exit:\n");
}


//void slowSpeed(){
//    system("cls");
//   struct node p;
//   p.val='B';
//   p.x_axis=5;
//   p.y_axis=0;
//   while(p.y_axis<25){
//   gotoxy(p.x_axis,p.y_axis);
//   p.y_axis++;
//   printf("%c",p.val);
//   Sleep(100);
//   system("cls");
//   }
//}

