#include<iostream>
#include<stdio.h>
#include<conio.h>
#define true 1
#define false 0
int taller=true;
struct node{
    struct node * lchild;
    int info;
    struct node * rchild;
    int balance;
};

struct node * rotateright(struct node * pptr){
    struct node * aptr=pptr->lchild;
    struct node * temp=pptr;
    if(aptr->rchild!=NULL){
        pptr->lchild=aptr->rchild;
    }
    aptr->rchild=temp;
    return aptr;
}
struct node * rotateleft(struct node * pptr){
    struct node * aptr=pptr->rchild;
    struct node * temp=pptr;
    if(aptr->lchild!=NULL){
        pptr->rchild=aptr->lchild;
    }
    aptr->lchild=temp;
    return aptr;
}
struct node * insert_left_balance(struct node * pptr){
    struct node * aptr=pptr->lchild;
    struct node * bptr;
    if(aptr->balance==1){
        pptr->balance=0;
        aptr->balance=0;
        pptr=rotateright(pptr);
        return pptr;
    }
    else{
        bptr=aptr->rchild;
        if(bptr->balance==1){
            pptr->balance=-1;
            aptr->balance=0;
            bptr->balance=0;
            pptr->lchild=rotateleft(aptr);    
            pptr=rotateright(pptr);
            return pptr;   
        }
        else if(bptr->balance==-1){
            pptr->balance=0;
            aptr->balance=1;
            bptr->balance=0;
            pptr->lchild=rotateleft(aptr);
            pptr=rotateright(pptr);
            return pptr;
        }
        else if(bptr->balance==0){
            pptr->balance=0;
            aptr->balance=0;
            bptr->balance=0;
            pptr->lchild=rotateleft(aptr);
            pptr=rotateright(pptr);
            return pptr;

        }
    }
}
struct node * insert_right_balance(struct node * pptr){
    struct node * aptr=pptr->rchild;
    struct node * bptr;
    if(aptr->balance==1){
        pptr->balance=0;
        aptr->balance=0;
        pptr=rotateleft(pptr);
        return pptr;
    }
    else{
        bptr=aptr->rchild;
        if(bptr->balance==1){
            pptr->balance=0;
            aptr->balance=-1;
            bptr->balance=0;
            pptr->rchild=rotateright(aptr);    
            pptr=rotateleft(pptr);
            return pptr;   
        }
        else if(bptr->balance==-1){
            pptr->balance=1;
            aptr->balance=0;
            bptr->balance=0;
            pptr->rchild=rotateright(aptr);
            pptr=rotateleft(pptr);
            return pptr;
        }
        else if(bptr->balance==0){
            pptr->balance=0;
            aptr->balance=0;
            bptr->balance=0;
            pptr->rchild=rotateright(aptr);
            pptr=rotateleft(pptr);
            return pptr;

        }
    }
}
struct node * insert_left_check(struct node * pptr){
    if(pptr->balance==0){
        pptr->balance=1;
    }
    if(pptr->balance==-1){
        pptr->balance=0;
        taller=false;
    }
    if(pptr->balance==1){
        pptr=insert_left_balance(pptr);
        taller=false;
    }
}
struct node * insert_right_check(struct node * pptr){
    if(pptr->balance==0){
        pptr->balance=-1;
    }
    if(pptr->balance==1){
        pptr->balance=0;
        taller=false;
    }
    if(pptr->balance==-1){
        pptr=insert_right_balance(pptr);
        taller=false;
    }
}

struct node * insert(int key,struct node * root){
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->lchild=NULL;
        root->info=key;
        root->rchild=NULL;
        root->balance=0;
        return root;
    }
    else{
        if(key>root->info){
            root->rchild=insert(key,root->rchild);
            insert_right_check(root);

        }
        else if(key<root->info){
            root->lchild=insert(key,root->lchild);
            insert_left_check(root);
        }
        else{
            printf("key already present");
        }
    return root;
    }
}
struct node * del( int key , struct node * root){
    return root;
}
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->lchild);
        printf("%d \n",root->info);
        inorder(root->rchild);
        return;
    }
}
int main(){
    int choice,key;
    struct node * root=NULL;
    
    while(1){
        printf("1.Insertion \n 2.deletion \n 3.Inorder Traversal \n 4.Exit");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the value to be inserted");
            scanf("%d",&key);
            root=insert(key,root);
            break;
        case 2:
            printf("Enter the value to be deleted");
            scanf("%d",&key);
            root=del(key,root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice");
            break;
        }
    }
    return 0;
}