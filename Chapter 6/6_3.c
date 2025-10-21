#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXBSIZE 100
#define MAXLINES 100


struct lineinfo{
    int line_no;
    struct lineinfo *next;
};
struct tnode{
    char * word;
    struct lineinfo *lines;
    struct tnode * left;
    struct tnode * right;
};

static int getWord(char *, int,int *);
static int getch(void);
static void ungetch(int);
static struct tnode *createNewNode(char *,int);
static struct tnode *addNode(struct tnode *, char *,int);
static void treeprint(struct tnode *);
static void freeTree(struct tnode *);
static void addLineOccurence(struct tnode *,int);
static struct lineinfo * createLineInfo(int);
static int buffer[MAXBSIZE];
static int fp=0;



int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int line =1;

    root = NULL;
    while(getWord(word,MAXWORD,&line)!=EOF)
        if(isalpha(word[0]))
            if(strcmp("and",word)!=0 && strcmp("the",word)!=0)
                root = addNode(root,word,line);
    treeprint(root);
    freeTree(root); 
    return 0;
}

static struct tnode *createNewNode(char * word,int line){
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
    newNode->lines = createLineInfo(line);
    newNode->right = newNode->left = NULL;
    return newNode;
}

static struct tnode *addNode(struct tnode *root, char * word,int line)
{
    int cond;

    if(!root){
        return createNewNode(word,line);
    }
    if((cond = strcmp(word, root->word))==0){
        addLineOccurence(root, line);
    }
    else if(cond<0)
        root->left = addNode(root->left,word,line);
    else   
        root->right = addNode(root->right,word,line);

    return root;

}


static int getWord(char *word,int lim,int * line){
    int c;
    char *w = word;

    while(isspace(c=getch())){
        if(c=='\n')
            (*line)++;
    }

    if(c!=EOF)
        *w++ = c;
    if(!isalpha(c)){
        if(c=='\n')
            (*line)++;
        *w='\0';
        return c;
    }
    for(;--lim>0;w++)
        if(!isalnum(*w=getch())){
            if(c=='\n')
                (*line)++;
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

static int getch(void){
    return fp>0? buffer[--fp]: getchar();
}

static void ungetch(int c){
    if(fp>=MAXBSIZE-1){
        printf("Buffer is full!!!\n");
    }else{
        buffer[fp++] = c;
    }
}

static void freeTree(struct tnode *root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root->lines);
        free(root);
    }
}

static void treeprint(struct tnode *root){
    if(root!=NULL){
        treeprint(root->left);
        printf("%s: ",root->word);
        struct lineinfo *curr = root->lines;
        while(curr){
            printf(" %d ",curr->line_no);
            curr = curr->next;
        }
        printf("\n");
        treeprint(root->right);
    }
}

static struct lineinfo * createLineInfo(int line){
    struct lineinfo *newNode = malloc(sizeof(struct lineinfo));
    if(!newNode){
        printf("Malloc failed!!\n");
        return NULL;
    }
    newNode->line_no = line;
    newNode->next = NULL;
    return newNode;


}
static void addLineOccurence(struct tnode *head,int line){
    struct lineinfo *current = head->lines;
    struct lineinfo *prev = NULL;


    while(current!=NULL){
        prev = current;
        current = current->next;
    }
    
    struct lineinfo *newLine = createLineInfo(line);
    if(!newLine) return;

    if(prev==NULL)
        head->lines = newLine;
    else
        prev->next = newLine;

}
