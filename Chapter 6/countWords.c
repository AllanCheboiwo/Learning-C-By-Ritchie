#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXBSIZE 100



struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
//getWord and all
int buffer[MAXBSIZE];
int fp=0;
int getWord(char *,int);
int getch(void);
void ungetch(int);



void treeprint(struct tnode *);
int getWord(char *,int);
struct tnode *createNewNode(char *);
struct tnode *addTree(struct tnode *root, char * word);
void freeTree(struct tnode *root);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getWord(word,MAXWORD)!=EOF)
        if(isalpha(word[0]))
            root = addTree(root,word);
    treeprint(root);
    freeTree(root); 
    return 0;
}

struct tnode *createNewNode(char * word){
    struct tnode *newNode = malloc(sizeof(struct tnode));
    if(!newNode){
        printf("Error allocating memory using malloc\n");
        return NULL;
    }
    char *c = malloc(strlen(word)+1);
    if(!c){
        printf("Error allocating memory using malloc\n");
        return NULL;        
    }
    strcpy(c,word);
    newNode->word = c;
    newNode->count =1 ;
    newNode->right = newNode->left = NULL;
    return newNode;
}

struct tnode *addTree(struct tnode *root, char * word)
{
    int cond;
    if(!root){
        return createNewNode(word);
    }
    if((cond=strcmp(word,root->word))==0)
        root->count++;
    else if(cond<0)
        root->left = addTree(root->left,word);
    else   
        root->right = addTree(root->right,word);

    return root;

}

void treeprint(struct tnode *root){
    if(root!=NULL){
        treeprint(root->left);
        printf("%4d %s\n",root->count,root->word);
        treeprint(root->right);
    }
}

void freeTree(struct tnode *root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}
int getWord(char *word,int lim){
    int c;
    char *w = word;

    while(isspace(c=getch()))
        ;
    if(c!=EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(;--lim>0;w++)
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void){
    return fp>0? buffer[--fp]: getchar();
}

void ungetch(int c){
    if(fp>=MAXBSIZE-1){
        printf("Buffer is full!!!\n");
    }else{
        buffer[fp++] = c;
    }
}
