/* task condition
https://leetcode.com/problems/merge-k-sorted-lists/
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
  ListNode *m_pListOut = nullptr;
  vector<ListNode*> m_lists;
public:
    ListNode *getListOut(){return m_pListOut;}

    void printList(){
        ListNode *point = m_pListOut;
        while(point != nullptr)
        {
            cout << point->val << '\t';
            point = point->next;
        }
        cout << endl;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      m_lists = lists;
      vector<ListNode*>::iterator iter;

      if(lists.empty())
        return m_pListOut;
      for(iter = lists.begin(); iter < lists.end(); iter++)
      {
        ListNode* pList = *iter;
        push_back(pList);
        //printList();
      }
      sortList();
      return m_pListOut;
    }
//-------
    void push_back(ListNode* pNode){
      if(m_pListOut == nullptr)
      {
        m_pListOut = pNode;
        return;
      }
      ListNode* point = m_pListOut;
      while(true){
        if(point->next != nullptr)
          point = point->next;
        else{
          point->next = pNode;
          break;
        }
      }
    }

    void sortList()
    {
      ListNode* pList = this->m_pListOut;
      ListNode* pListTmp;
      ListNode* pListPrev = nullptr;
      ListNode listPrev;
      //printList(m_pListOut);
      size_t uSize = size();
      for(size_t i=0; i < uSize; i++){
        while(pList != nullptr)
        {
          if(pList->next == nullptr)
            break;
          if(pList->val > pList->next->val)
          {
            pListTmp = new ListNode(pList->val, pList->next->next);
            pList = pList->next;
            pList->next = pListTmp;
            if(pListPrev != nullptr)
              pListPrev->next = pList;
            else
              m_pListOut = pList;
          }
          pListPrev = pList;
          pList = pList->next;
        }
        pList = this->m_pListOut;
      }
    }

    size_t size(){
      size_t size = 0;
      ListNode* pList = this->m_pListOut;
      while(pList != nullptr)
      {
        size++;
        pList = pList->next;
      }
      return size;
    }
};


// lists: [[1,4,5],[1,3,4],[2,6]]

int main()
{
    Solution sln;
    ListNode list11(5);
    ListNode list12(4, &list11);
    ListNode list13(1, &list12);

    cout << list13.val << '\t'
        << list13.next->val << '\t'
        << list13.next->next->val << endl;

    ListNode list21(4);
    ListNode list22(3, &list21);
    ListNode list23(1, &list22);

    cout << list23.val << '\t'
        << list23.next->val << '\t'
        << list23.next->next->val << endl;

    ListNode list31(6);
    ListNode list32(2, &list31);

    cout << list32.val << '\t'
        << list32.next->val << '\t' << endl;

    vector<ListNode *> vecLists{&list13, &list23, &list32};

    ListNode listOut;
    listOut = move(*sln.mergeKLists(vecLists));
    //ListNode* point = sln.getListOut(); //&listOut;
    ListNode* point = &listOut;

    cout << "Final list:" << endl;
    while(point != nullptr)
    {
        int iVal = point->val;
        //printf("%i \t", iVal);
        cout << iVal << '\t';

        point = point->next;
        //if(point->next == nullptr)
        //    break;
    }

    return 0;
}
