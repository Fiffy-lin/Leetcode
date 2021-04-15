// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

// 你应当 保留 两个分区中每个节点的初始相对位置。

 

// 示例 1：


// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]
// 示例 2：

// 输入：head = [2,1], x = 2
// 输出：[1,2]
 

// 提示：

// 链表中节点的数目在范围 [0, 200] 内
// -100 <= Node.val <= 100
// -200 <= x <= 200

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> val,temp;
        for(ListNode* cur=head;cur;cur=cur->next)
            val.emplace_back(cur->val);
        for(int i=0;i<val.size();++i)
            if(val[i]<x)
                temp.emplace_back(val[i]);
        for(int i=0;i<val.size();++i)
            if(val[i]>=x)
                temp.emplace_back(val[i]);
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        for(int i=0;i<temp.size();++i){
            ListNode* node=new ListNode(temp[i]);
            cur->next=node;
            cur=node;
        }
        return dummy->next;
    }   
};