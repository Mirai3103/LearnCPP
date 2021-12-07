#include <stdio.h>

struct doibong
{
    char name[100];
    int soluong;
    int mark;
};
void nhapcacdoibong(struct doibong cacdoibong[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("thong tin doi bong %d\n", i + 1);
        struct doibong a;
        printf("nhap ten doi: ");
        scanf("%s", &(a.name));
        printf("nhap so luong nguoi trong doi: ");
        scanf("%d", &(a.soluong));
        printf("nhap diem doi: ");
        scanf("%d", &(a.mark));
        cacdoibong[i] = a;
    }
}
int comparediem(struct doibong a, struct doibong b)
{
    return a.mark < b.mark;
}
int comparesoluong(struct doibong a, struct doibong b)
{
    return a.soluong < b.soluong;
}
int compareName(struct doibong a, struct doibong b)
{
    return toupper(a.name[0]) > toupper(b.name[0]);
}
void sort(struct doibong cacdoibong[], int n, int (*compare)(struct doibong, struct doibong))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((*compare)(cacdoibong[i], cacdoibong[j]))
            {
                struct doibong temp = cacdoibong[i];
                cacdoibong[i] = cacdoibong[j];
                cacdoibong[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("ban muon nhap may doi: ");
    scanf("%d", &n);
    struct doibong cacdoibong[n];
    nhapcacdoibong(cacdoibong, n);
    // sort(cacdoibong, n, comparediem);    // sap sep diem giam dan
    // sort(cacdoibong, n, comparesoluong); // sap sep soluong giam dan
    sort(cacdoibong, n, compareName); // sap sep ten
    for (int i = 0; i < n; i++)
    {
        printf("%s ; ", cacdoibong[i].name);
    }
    
    return 0;
}
