//
//  main.c
//  LinkNode
//
//  Created by jiahui on 2019/7/22.
//  Copyright © 2019 JH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE,*PNODE;

int length(PNODE Phead);

void addpend(PNODE Phead, int data);

void addedAtFristNode(PNODE phead, int data);

void deleteNode(PNODE phead, int nodeValue);

void insertNode(PNODE phead, int value, int index);

void inversion(PNODE phead);//倒置

PNODE inversionList(PNODE phead);//倒置递归

void showAllNodes(PNODE Phead);

int main() {
    int len = 0;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
//    headNode ->data = NULL;
    pHead -> next = NULL;
    addpend(pHead, 11);
    addpend(pHead, 22);
    addpend(pHead, 33);
    addpend(pHead, 44);
    addpend(pHead, 33);
    insertNode(pHead,10,1);
    showAllNodes(pHead);
    len = length(pHead);
    
    addedAtFristNode(pHead, 33);
    addedAtFristNode(pHead, 10);
    addedAtFristNode(pHead, 8);
    addedAtFristNode(pHead, 6);
    insertNode(pHead,55,10);
    showAllNodes(pHead);
     len = length(pHead);
    
    printf("\n删除节点！33 ");
    deleteNode(pHead, 33);
    showAllNodes(pHead);
    
    printf("\n插入节点！ 18");
    insertNode(pHead,18,3);
    showAllNodes(pHead);
    len = length(pHead);
    
    printf("\n翻转链表 ！");
    inversion(pHead);
    showAllNodes(pHead);
    
//   PNODE head = inversionList(pHead);
//   showAllNodes(head);
    return 0;
}

int length(PNODE Phead) {
    if (Phead  == NULL || Phead->next == NULL) {
        printf("链表为空 ！");
        return 0;
    } else {
        int len = 1;
        PNODE pTemp = Phead ->next;
        while (pTemp ->next != NULL) {
            pTemp = pTemp ->next;
            len ++;
        }
        return len;
    }
}

void addpend(PNODE pHead, int data) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node -> next = NULL;
    NODE *tempNode = pHead;
    while (tempNode -> next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode ->next = node;
}

void addedAtFristNode(PNODE phead, int data) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->next = phead->next;
    phead ->next = node;
}

void deleteNode(PNODE phead, int nodeValue) {
    PNODE pFrontNode = phead;
    PNODE pCurrentNode = phead -> next;
    while (pCurrentNode != NULL) {
        int data = pCurrentNode ->data;
        if (data == nodeValue) {
            pFrontNode ->next = pCurrentNode->next;
            free(pCurrentNode);
        } else {
            pFrontNode = pCurrentNode;
        }
         pCurrentNode = pCurrentNode ->next;
    }
}

void insertNode(PNODE phead, int value, int index) {
    if (!phead) {
        phead = (PNODE)malloc(sizeof(NODE));
        addpend(phead, value);
    } else if (phead -> next == NULL) {
        addpend(phead, value);
    } else {
        int len = length(phead);
        if (index >= len) {
            addpend(phead, value);
        } else {
            int i = 0;
            PNODE frontNode = phead;
            PNODE current = phead->next;
            while (current != NULL) {
                if (i == index-1) {
                    PNODE node = (PNODE)malloc(sizeof(NODE));
                    frontNode ->next = node;
                    node->data = value;
                    PNODE lastNode = current;
                    node ->next = lastNode;
                    return ;
                }
                i++;
                frontNode = current;
                current = current->next;
            }
        }
    }
}

void inversion(PNODE phead) {
    if (phead == NULL || phead ->next == NULL) {
        return ;
    }
    PNODE p = phead ;
    PNODE newH = NULL;
    while (p != NULL) {
        PNODE temp = p->next;
        p ->next = newH;
        newH = p;
        p = temp;
    }
    phead  = newH;
}

PNODE inversionList(PNODE phead) {
    if (phead == NULL || phead ->next == NULL) {
        return phead;
    }
    PNODE newNode = inversionList(phead -> next);
    phead ->next ->next = phead;
    phead ->next = NULL;
    return newNode;
}


void showAllNodes(PNODE Phead) {
    printf("\n");
    if (Phead  == NULL || Phead->next == NULL) {
        printf("链表为空 ！");
    }
    PNODE pTempNode = Phead ->next;
    while (pTempNode != NULL) {
        printf("%d ->",pTempNode -> data);
        pTempNode = pTempNode ->next;
    }
    printf("\n");
}
