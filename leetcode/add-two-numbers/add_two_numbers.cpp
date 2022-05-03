#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *l) : val(x), next(l) {}
};

vector<ListNode> make_input(vector<int> v1, vector<int> v2) {
  ListNode *l1 = new ListNode(
      v1[0], new ListNode(v1[1], new ListNode(v1[2], new ListNode(v1[3]))));
  ListNode *l2 = new ListNode(v2[0], new ListNode(v2[1], new ListNode(v2[2])));
  vector<ListNode> input = {*l1, *l2};
  return input;
}

ListNode solve(ListNode *l1, ListNode *l2) {
  int i1 = l1->val;
  int i2 = l2->val;
  int sum = i1 + i2;
  int remainder = sum / 10;
  int value = sum - (10 * remainder);

  ListNode *ls = new ListNode(value);
  ListNode *pls = ls;

  l1 = l1->next;
  l2 = l2->next;

  while (l1 != nullptr || l2 != nullptr) {
    cout << "loop" << endl;
    i1 = l1 == nullptr ? 0 : l1->val;
    i2 = l2 == nullptr ? 0 : l2->val;

    sum = i1 + i2 + remainder;
    remainder = sum / 10;
    value = sum - (10 * remainder);

    pls->next = new ListNode(value);
    pls = pls->next;
    if (l1 != nullptr) {
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      l2 = l2->next;
    }
  }
  if (remainder != 0) {
    pls->next = new ListNode(remainder);
  }
  return *ls;
}

int main(void) {
  cout << "Problem - Add Two Numbers" << endl;
  vector<int> v1 = {2, 4, 3, 3};
  vector<int> v2 = {5, 6, 4};
  vector<ListNode> input = make_input(v1, v2);
  ListNode result = solve(&input[0], &input[1]);
  ListNode *p_result = &result;
  while (p_result != nullptr) {
    cout << p_result->val;
    p_result = p_result->next;
  }
  cout << endl;
  return 0;
}
