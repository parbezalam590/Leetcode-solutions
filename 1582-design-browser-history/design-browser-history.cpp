class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string st) : data(st), next(NULL), prev(NULL){};
}; class BrowserHistory {
    Node* curr;

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node *newNode = new Node(url);
        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }

    string back(int steps) {
        while(steps && curr->prev) {
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }

    string forward(int steps) {
        while(steps && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */