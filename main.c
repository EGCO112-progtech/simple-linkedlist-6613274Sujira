//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,c,d,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
    

   
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
    4.print โดยใช้ head
 */ 
    b.next = &c;
    c.next = NULL;
    c.value = 11;
    printf("%d\n", head->next->next->value);
    //printf("%p\n", c.next);

/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2) 
*/
    d.next = &a;
    d.value = 2;
    head = &d;
    printf("%d\n",head->value);
    printf("%d\n",head->next->value);
    printf("%d\n",head->next->next->value);
    printf("%d\n",head->next->next->next->value);

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything */
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value); 
          // What is missing???
            tmp = tmp->next;
        }
        printf("\n");
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)*/
       tmp = head;
         while(tmp != NULL){
            
            printf("%3d", tmp->value);
            tmp = tmp->next;

           // What is missing???
        }
        printf("\n");
    
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
     */
    head = (NodePtr)malloc(sizeof(struct node));
    tmp = head; //temp point the same with head
    // tmp -> value = 2;
    // tmp -> next = (NodePtr)molloc(sizeof(struct node)); //creat node2

    // tmp = tmp -> next; //move to node2
    // tmp -> value = 5;
    // tmp -> next = (NodePtr)molloc(sizeof(struct node));

    // mp = tmp -> next; //move to node3
    // tmp -> value = 8;
    
    for(i=2;i<=11;i+=3)
    {
        tmp -> value = i;
        if(i==11) tmp -> next = NULL;
        else
        {
            tmp -> next = (NodePtr)malloc(sizeof(struct node));
        }
        printf("%3d",tmp->value);
        tmp = tmp -> next;
    }
    printf("\n");
    

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    //  for(i=0;i<n;i++)
    //  {
    //     tmp = head;
    //     head = head -> next;
    //     free(tmp);
        
    //  }

     while(head)
     {
        tmp = head;
        head = head -> next;
        printf("%5d",tmp->value);
        free(tmp);
     }
    
    return 0;
}
