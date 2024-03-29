// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"


int main()
{
	LinkedList<int>* pHead = NULL;
	pHead->append(10, &pHead);
	pHead->append(3, &pHead);
	pHead->append(20, &pHead);
	pHead->append(7, &pHead);
	pHead->append(90, &pHead);
	pHead->append(30, &pHead);
	pHead->display( pHead);

	pHead->insert(2, 35, &pHead);
	pHead->display( pHead);

	pHead->insert(5, 31, &pHead);
	pHead->display( pHead);

	pHead->insert(7, 45, &pHead);
	pHead->display( pHead);

	pHead->insert(1, 100, &pHead);
	pHead->display( pHead);

	pHead->reverse_linked_list( &pHead);
	pHead->display( pHead);

	std::cout << "Recursive Reverse Linked List :: "<<std::endl;
	LinkedList<int>* p = NULL;
	LinkedList<int>* q = pHead;
	pHead->recursive_reverse_linked_list(p, q, &pHead);
	pHead->display( pHead);

	std::cout << "Merge Linked List" <<std::endl;
	LinkedList<int>* pList1 = NULL;
	pList1->append(10, &pList1);
	pList1->append(13, &pList1);
	pList1->append(25, &pList1);
	pList1->append(71, &pList1);
	pList1->append(90, &pList1);
	pList1->append(300, &pList1);
	pList1->display(pList1);


	LinkedList<int>* pList2 = NULL;
	pList2->append(30, &pList2);
	pList2->append(35, &pList2);
	pList2->append(45, &pList2);
	pList2->append(72, &pList2);
	pList2->append(91, &pList2);
	pList2->append(99, &pList2);
	pList2->display(pList2);

	LinkedList<int>* pMergedList = NULL;
	Merge(&pList1,&pList2,&pMergedList);
	pMergedList->display(pMergedList);
    return 0;
}

