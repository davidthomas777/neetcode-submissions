struct Node {
    int val;
    Node * next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
private: 
    Node * head = nullptr;
    Node * tail = nullptr;
public:
    LinkedList() {
    }

    int get(int index) {
        if (head == nullptr) {
            return -1;
        }
        Node * curr = head;
        int i = 0;
        while (curr != nullptr && i != index) {
            curr = curr->next;
            i++;
        }
        if (curr == nullptr) return -1;
        return curr->val;
    }

    void insertHead(int val) {
        // 2 -> 3
        // 1 -> 2 -> 3
        Node * n = new Node(val);
        n->next = head;
        head = n;
        // if list was empty before insertion
        if (tail == nullptr) tail = n;
    }
    
    void insertTail(int val) {
        Node * n = new Node(val);
        if (tail == nullptr) {
            head = tail = n;
        }
        else {
            tail->next = n;
            tail = tail->next;
        }
    }

    bool remove(int index) {
        if (index < 0 || head == nullptr) return false;

        Node * prev = nullptr;
        Node * curr = head;
        int i = 0;

        while (curr != nullptr && i != index) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        // if index is out of range
        if (curr == nullptr) return false;

        // if curr is head of list
        if (prev == nullptr) {
            head = curr->next;
        }
        else {
            prev->next = curr->next;
        }

        if (curr == tail) {
            tail = prev;
        }
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node * curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};
