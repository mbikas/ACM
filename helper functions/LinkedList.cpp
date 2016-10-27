//
//
//  LinkedList
//  This class contains the implementaion of simple LinkedList operations
//  Wriiten to solve the HackerRank LinkedList Problems:
//        https://www.hackerrank.com/domains/data-structures/linked-lists
//  Video Tutorual: https://www.youtube.com/user/mycodeschool
//  Created by Md Abu Naser Bikas on 10/10/15.
//  Copyright (c) 2015 Md Abu Naser Bikas. All rights reserved.
//


#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}


Node* Insert_In_Head(Node *head,int data)
{
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
    return head;
}

Node* Insert_In_Tail(Node *head,int data)
{
    
    //Node* newNode = new Node();
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    
    
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    
    Node* temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = newNode;
    return head;

}

Node* Insert_In_Nth_position(Node *head,int data, int position)
{
    
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next=NULL;
    
    if(position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    Node* temp2 = head;
    for(int i=0;i<position-1;i++)
    {
        temp2 = temp2->next;
    }
    newNode->next = temp2->next;
    temp2->next = newNode;
    
    return head;
}

Node* Delete(Node *head, int position)
{
    
    Node* temp1 = head;
    if(position ==0)
    {
        head = temp1->next;
        free(temp1);
        return head;
    }
    for(int i=0;i<position-1;i++)
    {
        temp1 = temp1->next;
    }
    
    Node* nthNode = temp1->next;
    temp1->next = nthNode->next;
    free(nthNode);
    return head;
}

Node* Reverse(Node* head)
{
    if(head == NULL)return head;
    
    Node *current, *prev, *next;
    
    current = head;
    prev = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
void ReversePrint(Node *head)
{
    Print(Reverse(head));
}

//return 1 if two lists have same value, 0 otherwise
int CompareLists(Node *headA, Node* headB)
{
    Node* tempA = headA;
    Node* tempB = headB;
    while(tempA != NULL || tempB != NULL)
    {
        if(tempA->next == NULL && tempB->next != NULL)return 0;
        if(tempA->next != NULL && tempB->next == NULL)return 0;
        if(tempA->data != tempB->data)return 0;
        tempA = tempA->next;
        tempB = tempB->next;
        return 1;
    }
    return 1;
}

Node* MergeLists(Node *headA, Node* headB)
{
    
    if(headA != NULL && headB == NULL)return headA;
    if(headB != NULL && headA == NULL)return headB;
    
    Node* tempB = headB;
    int position;
    while(tempB != NULL)
    {
        //get the position from A
        Node* tempA = headA;
        position = 0;
        while(tempA != NULL)
        {
            if(tempA->data >= tempB->data)
                break;
            tempA = tempA->next;
            position++;
        }
        
        //inserting the headA
        headA = Insert_In_Nth_position(headA, tempB->data, position);
        tempB = tempB->next;
    }
    
    return headA;
}

/*
 Get Nth element from the end in a linked list of integers
 Number of elements in the list will always be greater than N.
 */
int GetNode(Node *head,int positionFromTail)
{
    Node* temp = head;
    int count= 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    int position = count - positionFromTail -1;
    temp = head;
    count = 0;
    while(temp != NULL)
    {
        if (count == position)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    
    return -1;
}

/* The function removes duplicates from a sorted list */
Node* RemoveDuplicates(Node *head)
{
    // if the list is empty  return
    if(head == NULL) return head;
    
    Node* current = head;   //Pointer to traverse the linked list
    Node* next_next;        //Pointer to store the next pointer of a node to be deleted
    
    // Traverse the list till last node
    while(current->next != NULL)
    {
        if(current->data == current->next->data) //comparing current with next
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next; 
        }
    }
    
    return head;
}

/*
 Detect loop in a linked list
 Check whether the linked list has a cycle and return 1 if there is a cycle. Otherwise, return 0.
 List could be empty also
 -- this is not an efficient solution
 -- Floyd's cycle-finding algorithm  can be used here: 
 --     https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
*/
int HasCycle(Node* head)
{
    // if the list is empty  0
    if(head == NULL) return 0;
    
    Node* current = head;   //Pointer to traverse the linked list
    
    Node* traversed[105];
    int count = 0;
    
    while(current != NULL)
    {
        for(int i=0;i<count;i++)
            if(traversed[i] == current)return 1;
        
        traversed[count] = current;
        count++;
        current = current->next;
    }
    
    return 0;
}

/*
 Find merge point of two linked lists
 None of the list will be null
 Find the node at which both lists merge and return the data of that node.
*/
int FindMergeNode(Node *headA, Node *headB)
{
    
    Node* tempB = headB;
    while(tempB->next != NULL)
    {
        tempB = tempB->next;

        Node* tempA = headA;
        while(tempA->next != NULL)
        {
            tempA = tempA->next;
            if(tempA->data == tempB->data)
                return tempB->data;
        }
        
    }
    
    return -1;
}

/*
 Insert Node in a doubly sorted linked list
 After each insertion, the list should be sorted
*/
Node* SortedInsert(Node *head,int data)
{
    Node* temp = head;
    int position = 0;
    while(temp != NULL)
    {
        if(temp->data >= data){
            break;
        };
        temp = temp->next;
        position++;
    }
    head = Insert_In_Nth_position(head, data, position);
    return head;
}



struct Node* head1;
struct Node* head2;
struct Node* head3;
int main()
{
    cout << "Head1" << endl;
    head1 = Insert_In_Head(head1, 10);
    Print(head1);
    head1 = Insert_In_Head(head1, 5);
    Print(head1);
    head1 = Insert_In_Head(head1, 2);
    Print(head1);
    
    
    cout << "Head2" << endl;
    head2 = Insert_In_Tail(head2, 2);
    Print(head2);
    head2 = Insert_In_Tail(head2, 3);
    Print(head2);
    
    cout << "Head3" << endl;
    head3 = Insert_In_Nth_position(head3, 2,0); //2
    Print(head3);
    
    head3 = Insert_In_Nth_position(head3, 3,1); //2,3
    Print(head3);
    head3 = Insert_In_Nth_position(head3, 4,0); //4,2,3
    Print(head3);
    head3 = Insert_In_Nth_position(head3, 5,0); //5,4,2,3
    Print(head3);
    head3 = Delete(head3, 2); //5,4,3
    Print(head3);
    
    cout << "Reversing Head3" << " => ";
    head3 = Reverse(head3); //3,4,5
    Print(head3);
    
    cout << "Compare Head2 and Head3" << " => ";
    if(CompareLists(head2, head3) == 0) cout << "Not Same" << endl;
    else cout << "Same" << endl;
    
    cout << "Merge Head1 and head2" << endl;
    head3 = MergeLists(head3, head1);
    Print(head3);
    
    
    cout << "Geeting a node value from tail postion of Head3" << endl;
    cout << GetNode(head3, 0) << endl;
    
    cout << "Remove Duplicates from Head3" << endl;
    Print(RemoveDuplicates(head3));
    
    cout << "Find Merge Node" << endl;
    cout << FindMergeNode(head1, head3);
    
    return 0;
}
