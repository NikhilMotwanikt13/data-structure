#include<stdio.h>
#include<conio.h>
#include<iostream>
struct node{
    bool lthread;
    struct node* l_child;
    int info;
    bool rthread;
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
        struct node * root=(struct node *)malloc(sizeof(struct node));
        root->info=key;
        root->lthread=true;
        root->rthread=true;
        root->l_child=NULL;
        root->r_child=NULL;
        return root;
    }
    struct node * ptr=root;
    while(ptr!=NULL){
        if(ptr->info==key){
            printf("key already present");
            return root;
        }
        if(ptr->info>key){
            if(ptr->lthread==false){
                ptr=ptr->l_child;
            }
            else{
                struct node * temp=(struct node *)malloc(sizeof(struct node));
                temp->info=key;
                temp->lthread=true;
                temp->rthread=true;
                temp->l_child=NULL;
                temp->r_child=NULL;
                ptr->lthread=false;
                temp->l_child=ptr->l_child;
                ptr->l_child=temp;
                temp->r_child=ptr;
                return root;
            }
        }
        if(ptr->info<key){
            if(ptr->rthread==false){
                ptr=ptr->r_child;
            }
            else{
                struct node * temp=(struct node *)malloc(sizeof(struct node));
                temp->info=key;
                temp->lthread=true;
                temp->rthread=true;
                temp->l_child=NULL;
                temp->r_child=NULL;
                ptr->rthread=false;
                temp->r_child=ptr->r_child;
                ptr->r_child=temp;
                temp->l_child=ptr;
                return root;

            }
        }
    }
}
void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    else{
        struct node * ptr=root; 
        while(ptr->lthread!=true){
            ptr=ptr->l_child;
        }
        printf("%d \n",ptr->info);
        while(ptr!=NULL){
            if(ptr->rthread==true){
                ptr=ptr->r_child;
                if(ptr!=NULL){
                    printf("%d \n",ptr->info);                        
                }
                
            }
            else{
                 ptr=ptr->r_child;
                 while(ptr->lthread!=true){
                    ptr=ptr->l_child;
                }
                printf("%d \n ",ptr->info);
            }
        }
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
}