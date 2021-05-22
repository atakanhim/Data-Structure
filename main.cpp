#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// using namespace std;
struct node {
    int x;
    node * next;
};
void show(node * roottke){
            while(roottke != NULL){
                    printf("%d \n",roottke ->x);
                    roottke = roottke ->next;
            }
}
void ekle(node * roottke,int i){
            while(roottke ->next != NULL)
                roottke = roottke ->next;
            roottke ->next = (node *)malloc(sizeof(node));
            roottke ->next ->x = i;
            roottke ->next ->next = NULL;
}

int main(){
    node * root ;
    root = (node *)malloc(sizeof(node));
    root ->x = 5;
    root ->next = NULL;
    for(int i = 0 ; i < 5; i++)
            ekle(root,i*10);
    show(root);

}