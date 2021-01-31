// 5、合并两个有序链表（亚马逊、字节跳动在半年内面试常考）
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


// 9、加一（谷歌、字节跳动、Facebook 在半年内面试中考过）
vector<int> plusOne(vector<int>& digits) {
    int left = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        int sums = digits[i] + left;
        left = sums / 10;
        int num = sums - 10 * left;
        digits[i] = num;
    }

    if (left > 0) digits.insert(digits.begin(), left);
    return digits;
}