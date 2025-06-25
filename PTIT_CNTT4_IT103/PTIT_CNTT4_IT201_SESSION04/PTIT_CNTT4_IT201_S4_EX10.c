#include <stdio.h>
#include <ctype.h>

struct sv
{
    int id;
    char name[20];
    int age;
};

#define sinhvien sv

void toLowerCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    struct sv a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].id = i;
        printf("ten: ");
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0';
        printf("tuoi: ");
        scanf("%d", &a[i].age);
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", a[i].id, a[i].name, a[i].age);
    }
    char k[50];
    printf("ten muon tim: ");
    fgets(k, sizeof(k), stdin);
    k[strcspn(k, "\n")] = '\0';
    toLowerCase(k);
    for (int i = 0; i < n; i++)
    {

        char te[20];
        strcpy(te, a[i].name);
        toLowerCase(te);
        if (strcmp(te, k))
        {
            printf("ID: %d, Ten: %s, Tuoi: %d\n", a[i].id, a[i].name, a[i].age);
            return 0;
        }
    }

    printf("khong tim thay.\n");
    return 0;
}