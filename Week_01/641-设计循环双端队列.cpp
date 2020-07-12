class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        printf("enter function: %s\n", __FUNCTION__);
        capacity = k;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        printf("enter function: %s\n", __FUNCTION__);
        if (size >= capacity)
            return false;
        
        DequeNode *tmpNode = new DequeNode;
        tmpNode->val = value;
        tmpNode->next = head;
        tmpNode->pre = NULL;

        if (NULL != head) {
            head->pre = tmpNode;
        }

        head = tmpNode;

        if (NULL == tail)
            tail = head;
        size += 1;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        printf("enter function: %s\n", __FUNCTION__);
        if (size >= capacity)
            return false;
        
        DequeNode *tmpNode = new DequeNode;
        tmpNode->val = value;
        tmpNode->next = NULL;
        tmpNode->pre = tail;
        
        if (NULL != tail) {
            tail->next = tmpNode;
        }
        tail = tmpNode;

        if (NULL == head)
            head = tail;
        size += 1;

        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        printf("enter function: %s\n", __FUNCTION__);
        if (NULL == head)
            return false;

        DequeNode *tmpNode = head;
        head = head->next;

        if (NULL == head)
            tail = NULL;
        else 
            head->pre = NULL;
        
        delete tmpNode;

        size -= 1;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        printf("enter function: %s\n", __FUNCTION__);
        if (NULL == tail)
            return false;

        DequeNode *tmpNode = tail;
        tail = tail->pre;

        if (NULL == tail)
            head = NULL;
        else 
            tail->next = NULL;
        
        delete tmpNode;

        size -= 1;

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        printf("enter function: %s\n", __FUNCTION__);
        if (NULL != head)
            return head->val;

        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        printf("enter function: %s\n", __FUNCTION__);
        if (NULL != tail)
            return tail->val;
        return  -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        printf("enter function: %s\n", __FUNCTION__);
        return 0 == size;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        printf("enter function: %s\n", __FUNCTION__);
        return size == capacity;
    }

private :
    typedef struct _DequeNode {
        int val;
        struct _DequeNode *next;
        struct _DequeNode *pre;
    } DequeNode;

    int capacity;
    int size;
    DequeNode *head;
    DequeNode *tail;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */