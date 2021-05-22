#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// using namespace std;
//Insertion
struct node
{
    int x;
    node *next;
};
void show(node *roottke)
{
    node *iter = roottke;
    printf("%d \n", iter->x);
    iter = iter->next;
    while (iter != roottke)
    {
        printf("%d \n", iter->x);
        iter = iter->next;
    }
}
void ekle(node *roottke, int i)
{
    node *iter = roottke;
    while (iter->next != roottke)
        iter = iter->next;
    iter->next = (node *)malloc(sizeof(node));
    iter->next->x = i;
    iter->next->next = roottke;
}
node *sil(node *roottke, int x)
{
    node *temp;
    node *iter = roottke;

    if (roottke->x == x)
    {
        while (iter->next != roottke)
        {
            iter = iter->next;
        }
        iter->next = roottke->next;
        free(roottke);

        return iter->next;
    }
    while (iter->next != roottke && iter->next->x != x)
    {
        iter = iter->next;
    }
    if (iter->next == roottke)
    {
        printf("sayi bulunamadı \n");
        return roottke;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return roottke;
}
node *siraliEkle(node *roottke, int i)
{

    if (roottke == NULL) // bos olma durumu
    {
        roottke = (node *)malloc(sizeof(node));
        roottke->next = roottke;
        roottke->x = i;
        return roottke;
    }
    if (roottke->x > i) //roottaki degerden daha küçük deger gelirse root degişiyor
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->x = i;
        temp->next = roottke;
        node *iter = roottke;
        while (iter != roottke)
            iter = iter->next;
        iter->next = temp;
        return temp;
    }
    //3. durum
    node *iter = roottke;
    while (iter->next != roottke && iter->next->x < i)
    {
        iter = iter->next;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = i;
    return roottke;
}

int main()
{
    int i;
    node *root;
    root = NULL;

    root = siraliEkle(root, 200);
    root = siraliEkle(root, 100);
    root = siraliEkle(root, 400);
    root = siraliEkle(root, 350);
    root = siraliEkle(root, 300);
    show(root);
    root = sil(root,350);
    show(root);

    root = sil(root,333);
}