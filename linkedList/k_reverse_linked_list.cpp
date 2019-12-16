ListNode* Solution::deleteDuplicates(ListNode* A) {
    int data = A->val;
    ListNode *prev,*current;
    vector<int> duplicates;
    prev = A;
    current = A->next;
    while(current != NULL){
        if(current->val == prev->val){
            prev->next = current->next;
            if(duplicates.empty()){
                duplicates.push_back(current->val);
            }
            else if(duplicates.back() != current->val){
                duplicates.push_back(current->val);
            }
        }else{
            prev = current; 
        }
        current = current->next;
    }
    // cout<<"This should be working"<<endl;
    ListNode *head;
    head = A;
    int i=0;
    // cout<<head->val<<endl;
    while(i < duplicates.size() && head->val == duplicates[i]){
        head = head->next;
        ++i;
    }
    
    if(head == NULL){
        return NULL;
    }
    // cout<<"LOL"<<endl;
    prev = head;
    current = head->next;
    while(current != NULL){
        if(i < duplicates.size() && current->val == duplicates[i]){
            // cout<<current->val<<endl;
            prev->next = current->next;
            ++i;
        }
        else{
            prev = prev->next;   
        }
        current = current->next;
    }
    
    return head;
}
