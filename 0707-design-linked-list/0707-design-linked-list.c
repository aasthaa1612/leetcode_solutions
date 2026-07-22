typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;

Node* createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node *temp = obj->head;
    while (index--)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *newNode = createNode(val);
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *newNode = createNode(val);

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node *temp = obj->head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node *temp = obj->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node *del;

    if (index == 0) {
        del = obj->head;
        obj->head = obj->head->next;
    } else {
        Node *temp = obj->head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        del = temp->next;
        temp->next = del->next;
    }

    free(del);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *temp = obj->head;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}