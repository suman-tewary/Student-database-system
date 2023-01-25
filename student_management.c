#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct ad
{
    char name[30];
    char department[10];
    int dsaLab, itLab, deLab, phone, age;
} x[100];
int n, i, j = 0, a = 0, sum = 0, g, flag, num;
void read();
void addStudent();
void view();
void searchStudent();
void editStudent();
void delStudent();
void show(int sno);
void write();

int main()
{
    read();
    int c, i, q;
    printf("Student Management System\n");
    while (c != 6)
    {

        printf("**Enter your choice**\n\n1. Add Student Information\n2. View Information\n3. Search\n4. Edit Student Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf("%d", &c); // choice for option
        fflush(stdin);   // making it clear
        if (c == 1)      // addStudent
        {
            system("cls");
            addStudent();
        }
        else if (c == 2) // view
        {
            system("cls");
            view();
        }
        else if (c == 3) // search
        {
            system("cls");
            searchStudent();
        }
        else if (c == 4) // editStudent
        {
            system("cls");
            editStudent();
        }
        else if (c == 5) // delete
        {
            system("cls");
            delStudent();
        }
        else if (c == 6)
        {
            system("cls");
            write();
            exit(0);
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void addStudent()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n", num); // how many inputs
    printf("How many entry do you want to add=\n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter student's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter department = ");
        gets(x[i].department);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("Enter DSA Lab Marks = ");
        scanf("%d", &x[i].dsaLab);
        fflush(stdin);
        printf("Enter IT Lab Marks = ");
        scanf("%d", &x[i].itLab);
        fflush(stdin);
        printf("Enter DE Lab Marks = ");
        scanf("%d", &x[i].deLab);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d", &x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void view()
{
    for (i = 0; i < num; i++)
    {
        show(i);
    }
}
void editStudent()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.department\n3.Age\n4.Phone no.\n5.DSA Lab Marks\n6.IT Lab Marks\n7.DE Lab Marks\n");
    printf("Option=");
    scanf("%d", &q); // option
    if (q <= 7)
    {
        printf("Enter the serial no of that student= (0 - %d)=", num - 1);
        scanf("%d", &p); // serial number
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(x[p].name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new department=");
                gets(x[p].department);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d", &x[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d", &x[p].phone);
            }
            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new DSA Lab Marks =");
                scanf("%d", &x[p].dsaLab);
            }
            else if (q == 6)
            {
                fflush(stdin);
                printf("Enter the new IT Lab Marks =");
                scanf("%d", &x[p].itLab);
            }
            else if (q == 7)
            {
                fflush(stdin);
                printf("Enter the new DE Lab Marks =");
                scanf("%d", &x[p].deLab);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void searchStudent()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.department\n4.Phone no.\n5.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the student=");
        scanf("%d", &s);
        if (s < num)
        {
            show(s);
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                show(g);
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter department = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].department) == 0)
            {
                show(g);
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }

    else if (h == 4)
    {
        int f = 1;
        printf("Enter Phone number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].phone)
            {
                show(g);
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                show(g);
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void delStudent()
{
    int f, h;
    printf("Enter the serial number of the student that you want to delete=");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove department\n4.Remove age\n5.Remove Marks\n6.Remove phone number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].department, x[f + 1].department);
                x[f].age = x[f + 1].age;
                x[f].dsaLab = x[f + 1].dsaLab;
                x[f].itLab = x[f + 1].itLab;
                x[f].deLab = x[f + 1].deLab;
                x[f].phone = x[f + 1].phone;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].department, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].dsaLab = 0;
            x[f].itLab = 0;
            x[f].deLab = 0;
        }
        else if (h == 6)
        {
            x[f].phone = 0;
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
}
void show(int sno)
{
    printf("\n");
    printf("Serial Number=%d\n", sno);
    printf("Name = ");
    puts(x[sno].name);
    printf("Department = ");
    puts(x[sno].department);
    printf("DSA Lab Marks = %d\nIT Lab Marks = %d\nDE Lab Marks = %d\nPhone number = 0%d\nAge=%d", x[sno].dsaLab, x[sno].itLab, x[sno].deLab, x[sno].phone, x[sno].age);
    printf("\n\n");
}
void read()
{
    FILE *fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("student.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
    }

    num = fread(x, sizeof(struct ad), 100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("student.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(0);
    }
    fwrite(x, sizeof(struct ad), num, fp);

    fclose(fp);
}
