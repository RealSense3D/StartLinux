// Hash collision
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char *name;
    char *desc;
    struct _node *next;
}node;

#define HASHSIZE 50
static node* hashtab[HASHSIZE];

void inithashtab(){
    int i;
    for(i=0;i<HASHSIZE;i++)
        hashtab[i]=NULL;
}

unsigned int hash(char *s){
    unsigned int h=0;
    for(;*s;s++)
        h=*s+h*31;
    return h%HASHSIZE;
}

node* lookup(char *n){
    unsigned int hi=hash(n);
    node* np=hashtab[hi];
    for(;np!=NULL;np=np->next){
        if(!strcmp(np->name,n))
            return np;
    }
    
    return NULL;
}

char* m_strdup(char *o){
    int l=strlen(o)+1;
    char *ns=(char*)malloc(l*sizeof(char));
    strcpy(ns,o);
    if(ns==NULL)
        return NULL;
    else
        return ns;
}

char* get(char* name){
    node* n=lookup(name);
    if(n==NULL)
        return NULL;
    else
        return n->desc;
}

int install(char* name,char* desc){
    unsigned int hi;
    node* np;
    if((np=lookup(name))==NULL){
        hi=hash(name);
        printf(">> HashID[%d](%s.%s)\n", hi, name, desc);
        np=(node*)malloc(sizeof(node));
        if(np==NULL)
            return 0;
        np->name=m_strdup(name);
        if(np->name==NULL) return 0;
        np->next=hashtab[hi];
        hashtab[hi]=np;
    }
    else
        free(np->desc);
    np->desc=m_strdup(desc);
    if(np->desc==NULL) return 0;
    
    return 1;
}

/* A pretty useless but good debugging function,
which simply displays the hashtable in (key.value) pairs
*/
void displaytable(){
    int i;
    node *t;
    for(i=0;i<HASHSIZE;i++){
        printf("%2d ", i);
        if(hashtab[i]==NULL)
            printf("()\n");
        else{
            t=hashtab[i];
            printf("(");
            for(;t!=NULL;t=t->next)
                printf("(%s.%s) ",t->name,t->desc);
            printf(".)\n");
        }
    }
}

void cleanup(){
    int i;
    node *np,*t;
    for(i=0;i<HASHSIZE;i++){
        if(hashtab[i]!=NULL){
            np=hashtab[i];
            while(np!=NULL){
                t=np->next;
                free(np->name);
                free(np->desc);
                free(np);
                np=t;
            }
        }
    }
}

main(){
    int i;
    char* names[]={ "20", "1a", "21", "1b", "22", "1c", "23", "1d"};
    char* descs[]={"v20","v1a","v21","v1b","v22","v1c","v23","v1d"};
    
    inithashtab();
    for(i=0;i<8;i++)
        install(names[i],descs[i]);

    install("hello","kitty");
    
    printf(" %s and %s\n",get("20"),get("1a"));
    
    displaytable();
    cleanup();
    return 0;
}