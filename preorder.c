#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *lchild;
    struct tnode *rchild;
};
typedef struct tnode tnode;

tnode *create_node(int value)
{
    tnode *tn = (tnode *)malloc(sizeof(tnode));
    tn->data = value;
    tn->lchild = NULL;
    tn->rchild = NULL;
    return tn;
}

tnode *insert_recurse(tnode *p, int value)
{
    if(p == NULL)
        p = create_node(value);
    else if(value < p->data)
        p->lchild = insert_recurse(p->lchild, value);
    else if(value > p->data)
        p->rchild = insert_recurse(p->rchild, value);
    else
        printf("%d already exists\n",value);
    return p;
}

void preorder(tnode *p)
{
    if(p!=NULL)
    {
        printf("%d\n",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    tnode *root = NULL;
    int input;
    scanf("%d",&input);
    while(input != -1)
    {
        root = insert_recurse(root, input);
        scanf("%d",&input);
    }
    preorder(root);
    return 0;
}
