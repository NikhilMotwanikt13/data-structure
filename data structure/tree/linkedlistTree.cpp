#include<stdio.h>
#include<conio.h>
#include<iostream>
struct node{
    struct node* l_child;
    int info;
    struct node* r_child;
};
void search(struct node * root,int key){
    if(root==NULL){
        printf("key not found \n");
        return;
    }
    else{
        if(root->info==key){
            printf("key found \n");
            return;
        }
        else if(key>root->info){
            search(root->r_child,key);
            return;
        }
        else if(key<root->info){
            search(root->l_child,key);
            return;
        }
    }
}
struct node * insert(struct node * root, int key){
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->l_child=NULL;
        root->info=key;
        root->r_child=NULL;
        return root;
    }
    else if(key>root->info){
        root->r_child=insert(root->r_child,key);
        return root;
    }
    else if(key<root->info){
        root->l_child=insert(root->l_child,key);
        return root;
    }
    else if(key==root->info){
        return root;
    }
    return root;
}
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->l_child);
        printf("%d \n",root->info);
        inorder(root->r_child);
        return;
    }
}
void preorder(struct node * root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d \n",root->info);
        preorder(root->l_child);
        preorder(root->r_child);
        return;
    }
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    else{
        preorder(root->l_child);
        preorder(root->r_child);
        printf("%d \n",root->info);
        return;
    }
}
int height(struct node * root){
    int l_height=0, r_height=0;
    if(root==NULL){
        return 0;
    }
    else{
        l_height=1 + height(root->l_child);
        r_height=1 + height(root->r_child);
        if(l_height>r_height){
            return l_height;
        }
        else{
            return r_height;
        }

    }
}
void minmax(struct node * root){
    struct node * droot=root;
    while(droot != NULL){
        if(droot->l_child==NULL){
            printf(" %d \n ", droot->info);
        }
        droot=droot->l_child;
    }
    
    while(root != NULL){
        if(root->r_child==NULL){
            printf(" %d  \n", root->info);
        }
        root=root->r_child;
    }
     
    return;
}
 struct node *  del(struct node * root,int key){
    struct node * temp, *succ;
    if(root==NULL){
        printf("key not found \n");
        return(root);
    }
    else if(key<root->info){
        root->l_child=del(root->l_child,key);
    }
    else if(key>root->info){
        root->r_child=del(root->r_child,key);
    }
    else{
        if(root->l_child != NULL && root->r_child != NULL){
            succ=root->r_child;
            while(succ->l_child){
                succ=succ->l_child;
            }
            root->info=succ->info;
            root->r_child=del(root->r_child,succ->info);
        }
        else{
            temp=root;
            if(root->l_child!=NULL){
                root=root->l_child;
            }
            else if(root->r_child != NULL){
                root=root->r_child;
            }
            else 
                root=NULL;
            free(temp);
        }
    }
    return root;
 }
int main(){
    int choice,key;
    struct node* root=NULL;
    while(1){
        printf("1.Search \n 2.Insert \n 3.Delete \n 4.Preorder Traversal \n 5.Inorder Traversal \n 6.Postorder Traversal \n 7.Height Of The Tree \n 8.FInd Minimum And Maximum \n 9.Quit \n");
        printf("Enter your Choice \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the key to be searched:");
                scanf("%d",&key);
                search(root,key);
                break;
            case 2:
                printf("Enter the key to be inserted:");
                scanf("%d",&key);
                root=insert(root,key);
                break;
            case 3:
                printf("Enter the key to be deleted:");
                scanf("%d",&key);
                del(root,key);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                inorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                printf("%d \n",height(root));
                break;
            case 8:
                minmax(root);
                break;
            case 9:
                exit(1);
            default :
                printf("Wrong Choice \n ");
        }
    }
    getch();
    return 0;
}