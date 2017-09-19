#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846
FILE *fi;           
 
struct Pizza{
              char Name[64];
              float diameter; 
              float cost; 
              float areaperdollar;
              struct Pizza * next;
              struct Pizza * prev;
};
 
int main(int argc, char *argv[]){
             
  char pizName[64];
  float diam;
  float cst;
  struct Pizza *root=NULL;
  struct Pizza *current;
  fi = fopen (argv[1], "rt");
  fseek(fi,0,SEEK_END);
  if(ftell(fi)==0){
    printf("PIZZA FILE IS EMPTY\n");
    return 0;
  }
  fseek(fi,0,SEEK_SET);
  while(fgets(pizName, 64, fi) != NULL){
    if(strcmp("DONE\n",pizName) == 0){
                 break;
    }
    struct Pizza *newpizza;
    newpizza= (struct Pizza *) malloc(sizeof(struct Pizza));
    sscanf(pizName,"%s",newpizza->Name);
    fgets(pizName, 64, fi);
    diam = atof(pizName);
    newpizza->diameter = diam;
    fgets(pizName, 64, fi);
    cst = atof(pizName);
    newpizza->cost = cst;
    if(cst==0.0 | diam == 0.0){
      newpizza->areaperdollar = 0;
    }
    else{
      newpizza->areaperdollar = (PI/4*diam*diam)/cst;
    }
    newpizza->next = NULL;
    if(root==NULL){
      root = newpizza;
      current = root;
    }
    else{
      current->next=newpizza;
      current = newpizza;
    }
  }
  bool sorted = false;
  while(!sorted){
    sorted = true;
    struct Pizza *current=root;
    char temparr[64];
    float tempppd;
    while(current->next!=NULL){
      if(current->areaperdollar<current->next->areaperdollar){
        strcpy(temparr, current->Name);
        tempppd = current->areaperdollar;
        strcpy(current->Name, current->next->Name);
        current->areaperdollar = current->next->areaperdollar;
        strcpy(current->next->Name, temparr);
        current->next->areaperdollar = tempppd;
        sorted = false;
      }
      if(current->areaperdollar == current->next->areaperdollar){
        if(strcmp(current->Name, current->next->Name)>0){
          strcpy(temparr, current->Name);
        tempppd = current->areaperdollar;
        strcpy(current->Name, current->next->Name);
        current->areaperdollar = current->next->areaperdollar;
        strcpy(current->next->Name, temparr);
        current->next->areaperdollar = tempppd;
        }
      }
      current = current->next;
    }
  }
  struct Pizza *now;
  struct Pizza *temp;
  struct Pizza *TaylorSwift;
  now = root;
  while(now){
   printf("%s %f\n",now->Name,now->areaperdollar);
   temp = now->next;
   TaylorSwift = now;
   free(TaylorSwift);
   now = temp;
  }
  fclose(fi);
  return EXIT_SUCCESS;
}