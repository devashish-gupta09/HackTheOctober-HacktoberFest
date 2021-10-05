/*
(Case Study of Binary Tree) Write a program to implement the following Expression
tree. You are required to write the following methods.
(a) Create a Binary Tree
(b) Pre-order traversal
(c) In-order traversal
(d) Post order traversal
*/

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct tree_node
{
    int data;
    struct tree_node* left;
    struct tree_node* right;
};

typedef struct tree_node tnode;

tnode* create_binarytree(tnode* root,int data)
{
    if(root ==  NULL)
    {
        root = (tnode*)malloc(sizeof(tnode));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }


    if(root->data >= data)
    {
        root->left = create_binarytree(root->left,data);
    }
    else
    {
        root->right = create_binarytree(root->right,data);
    }

    return root;
}

void preorder_traversal(tnode* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("node data is %d\n",root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(tnode* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("node data is %d\n",root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(tnode* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("node data is %d\n",root->data);
}

int main()
{
    int option = 0;
    tnode* root = NULL;
    while(1)
    {
        system("cls");
        printf("=======================================================\n");
        printf("                         MAIN MENU\n");
        printf("=======================================================\n");
        printf("[1]Create Binary Tree\n");
        printf("[2]Preorder Traversal\n");
        printf("[3]Inorder Traversal\n");
        printf("[4]Postorder Traversal\n");
        printf("[5]Exit\n");
        fflush(stdin);
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            int data;
            char choice = 'y';
            while(choice == 'y' || choice == 'Y')
            {
                printf("Enter the Node data:\n");
                fflush(stdin);
                scanf("%d",&data);
                root = create_binarytree(root,data);
                preorder_traversal(root);
                printf("Do you want to add more nodes?\n");
                fflush(stdin);
                scanf("%c",&choice);
            }
        }
        break;
        case 2:
            preorder_traversal(root);
            break;
        case 3:
            inorder_traversal(root);
            break;
        case 4:
            postorder_traversal(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
        system("pause");
    }
    return 0;
}
