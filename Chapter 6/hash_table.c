#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HASHSIZE 101

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE] = {0};

static unsigned hash(char *);
static struct nlist *lookup(char *);
static struct nlist *install(char *,char*);
static void undef(char *s);

int main(){
    return 0;
}

static unsigned hash(char * s)
{
    unsigned hashval;
    for(hashval = 0 ; *s!='\0';s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

static struct nlist *lookup(char *s)
{
    struct nlist *entry;

    for(entry = hashtab[hash(s)];entry!=NULL;entry = entry->next)
        if(strcmp(entry->name,s)==0)
            return entry;
    return NULL;
}

static struct nlist *install(char * name, char *defn){
    struct nlist *entry;
    unsigned hashval;

    if((entry=lookup(name))==NULL){
        entry = (struct nlist *) malloc(sizeof(*entry));
        if(entry==NULL || (entry->name=strdup(name))==NULL)
            return NULL;
        hashval = hash(name);
        entry->next = hashtab[hashval];
        hashtab[hashval] = entry;
    }else
        free((void *) entry->defn);
    if((entry->defn=strdup(defn))==NULL)
        return NULL;
    return entry;
}

static void undef(char *s){

    unsigned hashval=hash(s);
    struct nlist *entry = hashtab[hashval];
    struct nlist *prev_entry=NULL;

    while(entry!=NULL){
        if(strcmp(entry->name,s)==0){
            if(prev_entry!=NULL)
                prev_entry->next = entry->next;
            else
                hashtab[hashval] = entry->next;
            
            free(entry->name);
            free(entry->defn);
            free(entry);
            return;
        }
        prev_entry = entry;
        entry = entry->next;
    }


}
