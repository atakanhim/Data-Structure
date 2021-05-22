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
    while (roottke != NULL)
    {
        printf("%d \n", roottke->x);
        roottke = roottke->next;
    }
}
void ekle(node *roottke, int i)
{
    while (roottke->next != NULL)
        roottke = roottke->next;
    roottke->next = (node *)malloc(sizeof(node));
    roottke->next->x = i;
    roottke->next->next = NULL;
}
node *siraliEkle(node *roottke, int i)
{

    if (roottke == NULL)
    {
        roottke = (node *)malloc(sizeof(node));
        roottke->next = NULL;
        roottke->x = i;
        return roottke;
    }
    if (roottke->x > i) //roottaki degerden daha küçük deger gelirse root degişiyor
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->x = i;
        temp->next = roottke;
        return temp;
    }
    node *iter = roottke;
    while (iter->next != NULL && iter->next->x < i)
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
    root = siraliEkle(root, 300);
    root = siraliEkle(root, 200);
    root = siraliEkle(root, 100);
    root = siraliEkle(root, 400);
    root = siraliEkle(root, 350);
    show(root);
}