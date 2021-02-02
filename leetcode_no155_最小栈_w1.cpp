/* ------------------------------------------------------------------|
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

pop、top 和 getMin 操作总是在 非空栈 上调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：28 ms, 在所有 C++ 提交中击败了88.50%的用户
*	内存消耗：15.5 MB, 在所有 C++ 提交中击败了15.08%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*	双向队列版
*
*	执行用时：16 ms, 在所有 C++ 提交中击败了99.77%的用户
*	内存消耗：15.6 MB, 在所有 C++ 提交中击败了11.22%的用户
*/
class MinStack {
public:
    /** initialize your data structure here. */
    deque<int> q;
    MinStack() {

    }

    void push(int x) {
        if (q.empty() || x <= q.front()) {
            q.push_front(x);
        }
        q.push_back(x);
    }

    void pop() {
        if (q.back() == q.front()) {
            q.pop_front();
        }
        q.pop_back();
    }

    int top() {
        return q.back();
    }

    int getMin() {
        return q.front();
    }
};
/*	stack版
*
*	执行用时：16 ms, 在所有 C++ 提交中击败了99.77%的用户
*	内存消耗：15.6 MB, 在所有 C++ 提交中击败了11.22%的用户
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> min;
    MinStack() {

    }

    void push(int x) {
        if (min.empty() || x <= min.top()) {
            min.emplace(x);
        }
        s.emplace(x);
    }

    void pop() {
        if (s.top() == min.top()) {
            min.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};


