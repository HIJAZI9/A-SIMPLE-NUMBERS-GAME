#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
struct info {
    char name[30];
    int number;
    int x, y;
}f1, f2;
int player1 = 0;
int player2 = 0;
void level();
void list();
void read_file(char* file_name);
void write_file(char* file_name);
void menu_write();
void menu_read();
int menu();
void main_manu();
void game(int mysteriousNumber);
void again(int inputNumber1, int inputNumber2, int mysteriousNumber);
int main()
{
    system("cls");
    printf("enter name player 1\n");
    scanf("%s", f1.name);

    printf("enter name player 2\n");
    scanf("%s", f2.name);
    system("cls");
    main_manu();

    return 0;
}
void menu_read() {
    printf("choose a File to load the data\n");
    printf("1- File 1\n");
    printf("2- File 2\n");
    printf("choice->");
    int i = 0;
    scanf("%d", &i);
    switch (i) {
    case 1: read_file("C:\\Users\\moham\\OneDrive\\Desktop\\one.txt");
        break;
    case 2:read_file("C:\\Users\\moham\\OneDrive\\Desktop\\two.txt");
        break;
    }
}
void menu_write() {
    printf("choose a File to save the data\n");
    printf("1- empty file 1\n");
    printf("2- empty file 2\n");
    printf("choice->");
    int i = 0;
    scanf("%d", &i);
    switch (i) {
    case 1: write_file("C:\\Users\\moham\\OneDrive\\Desktop\\one.txt");
        break;
    case 2:write_file("C:\\Users\\moham\\OneDrive\\Desktop\\two.txt");
        break;
    }
}
void read_file(char* file_name) {

    FILE* Number = NULL;
    Number = fopen(file_name, "r");
    char arr1[10];
    if (Number != NULL) {
        fscanf(Number, "%d %d", &f1.x, &f2.y);
        player1 = f1.x;
        player2 = f2.y;
        fclose(Number);
    }
    else {
        printf("sorry,we can not open this file\n");
        exit(1);
    }
}
void write_file(char* file_name) {
    FILE* Number = NULL;
    Number = fopen(file_name, "w");

    if (Number != NULL) {
        fprintf(Number, "%d %d", player1, player2);
        fclose(Number);
    }
    else {
        printf("sorry,we can not write in  this file\n");
        exit(1);
    }
}
void main_manu() {

    switch (menu()) {
    case 1:
        level();
        break;
    case 2:
        list();
        break;
    case 3:
        system("cls");
        return 0;
        break;
    }
}

int menu() {
    printf("1-Start Game\n");
    printf("2-win-lose List\n");
    printf("3-Exit\n");
    printf("choice->");
    int i = 0;
    scanf("%d", &i);
    return i;
}
void list() {
    system("cls");
    printf("----------------------------------\n");
    printf("|    %s    |    %s    |\n", f1.name, f2.name);
    printf("----------------------------------\n");
    printf("|%d    |  %d|\n", player1, player2);
    printf("----------------------------------\n");
    printf("1-Back\n");
    printf("2-New Game\n");
    printf("3-Save Game\n");
    printf("4-Load Game\n");

    printf("Choice->\n");
    int i = 0;
    scanf("%d", &i);
    switch (i) {
    case 1:
        system("cls");
        main_manu();
        break;
    case 2:
        player1 = 0;
        player2 = 0;
        main();
        break;
    case 3:
        menu_write();
        system("cls");
        list();
        break;
    case 4:
        menu_read();
        system("cls");
        list();
        break;
    }


}

void level() {
    int level;
    system("cls");

    printf("which level would you like to play?");
    printf("1- easy.  2-normal.");
    scanf("%d", &level);
    int mysteriousNumber;
    if (level == 1)
    {
        const max = 2, min = 0;

        srand(time(NULL));
        mysteriousNumber = (rand() % (max - min + 1)) + min;
    }

    else if (level == 2)
    {
        const max = 50, min = 0;


        srand(time(NULL));
        mysteriousNumber = (rand() % (max - min + 1)) + min;
    }
    game(mysteriousNumber);
}
void game(int mysteriousNumber) {
    int   tries = 1;

    do
    { // We request the number
        printf("what is the number %s?", f1.name);
        scanf("%d", &f1.number);
        printf("what is the number %s?", f2.name);
        scanf("%d", &f2.number);
        printf("try number %d\n", tries);
        tries += 1;

        // We compare between inputNumber and mysteriousNumber
        if (mysteriousNumber > f1.number)
            printf("greater %s!\n\n", f1.name);

        else if (mysteriousNumber < f1.number)
            printf("lesser %s !\n\n", f1.name);

        else
            printf("Bravo, %s has found the mysterious number   !!!\n\n", f1.name);


        if (mysteriousNumber > f2.number)
            printf("greater %s!\n\n", f2.name);

        else if (mysteriousNumber < f2.number)
            printf("lesser %s!\n\n", f2.name);

        else
            printf("Bravo, %s has found the mysterious number  !!!\n\n", f2.name);
        if (mysteriousNumber == f1.number)
            player1++;
        if (mysteriousNumber == f2.number)
            player2++;
    } while (mysteriousNumber != f1.number && mysteriousNumber != f2.number);

    again(f1.number, f2.number, mysteriousNumber);
}
void again(int inputNumber1, int inputNumber2, int mysteriousNumber) {
    int continuePlaying;
    do
    {


        printf("\n\nwould you like to play again? 1=yes 2=no");
        scanf("%d", &continuePlaying);
        break;



    }

    while ((mysteriousNumber == f1.number) || (mysteriousNumber == f2.name));
    if (continuePlaying == 1)
        level();
    else if (continuePlaying = 2)
        system("cls");
    main_manu();
}




