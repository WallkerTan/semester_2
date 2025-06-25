#include <stdio.h>

struct sv
{
    int id;
    char name[20];
    int age;
};

#define sinhvien sv

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
    int k;
    printf("id muon tim: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == k)
        {
            printf("ID: %d, Ten: %s, Tuoi: %d\n", a[i].id, a[i].name, a[i].age);
            return 0;
        }
    }
    printf("khong co.\n");
    return 0;
}