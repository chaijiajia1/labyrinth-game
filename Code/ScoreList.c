#include "headers\\ScoreList.h"

void RenewScoreList(char *name,int score)
{
    FILE  *fp=fopen("Data\\score.txt","r");	// open file/create file
    ScoreList *head=NULL;ScoreList *p=NULL;ScoreList *pf=head;
    if(fp!=NULL)	// If file opened
    {
        // get the content of the file
        while (!feof(fp)) {		// if not the file end
            p=(ScoreList*)malloc(sizeof(ScoreList));p->next=NULL;
            fscanf(fp,"%s %d\n",p->name,&p->score);
            if(pf==NULL)head=p;
            else pf->next=p;
            pf=p;
        }
    }
    fclose(fp);

    // add the new score
    p=head;
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            p->score+=score;
            break;
        }
        p=p->next;
    }
    if(p==NULL) // 
    {
        p=(ScoreList*)malloc(sizeof(ScoreList));
        strcpy(p->name,name);
        p->score=score;
        p->next=head;
        head=p;
    }
    //sort the list
    p=head;
    while(p->next!=NULL)
    {
        ScoreList *q=p->next;
        while(q!=NULL)
        {
            if(p->score<q->score)
            {
                char temp[20];
                strcpy(temp,p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,temp);
                int temp2;
                temp2=p->score;
                p->score=q->score;
                q->score=temp2;
            }
            q=q->next;
        }
        p=p->next;
    }
    //write the list to the file
    fp=fopen("Data\\score.txt","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%s %d\n",p->name,p->score);
        p=p->next;
    }
    fclose(fp);
    p=head;
    while(p!=NULL)
    {
        p=p->next;
        free(head);
        head=p;
    }
}
