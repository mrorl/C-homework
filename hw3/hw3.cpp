#include "hw3.h"

int_list_t::int_list_t() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

int_list_t::int_list_t(const int_list_t &other): int_list_t() {
    node_t *temp = other.head;
    while(Size != other.Size) {
        push_back(temp->data);
        if (Size != other.Size) {
            temp = temp->pNext;
        }
    }
}

int_list_t::int_list_t(size_t count, int value): int_list_t() {
    for (int i = 0; i < count; i++) {
        push_back(value);
    }
}

int_list_t::~int_list_t() {
    clear();
}

int_list_t::node_t *int_list_t::get_pos(int pos) const {
    if (pos <= Size / 2) {
        node_t *temp = this->head;
        for (int i = 0; i < pos; i++) {
            temp = temp->pNext;
        }
        return temp;
    } else {
        node_t *temp = this->tail;
        for (int i = Size-1; i > pos; i--) {
            temp = temp->pPrev;
        }
        return temp;
    }
}

int_list_t &int_list_t::operator=(const int_list_t &other) {
    int_list_t temp (other);
    swap(temp);

    return *this;
}

int int_list_t::operator[](size_t pos) {
    node_t *temp = get_pos(pos);
    return temp->data;
}

const int int_list_t::operator[](size_t pos) const {
    node_t *temp = get_pos(pos);
    return temp->data;
}

int &int_list_t::front() {
    return head->data;
}

const int int_list_t::front() const {
    return head->data;
}

int &int_list_t::back() {
    return tail->data;
}

const int int_list_t::back() const {
    return tail->data;
}

void int_list_t::clear() {
    while (Size) {
        pop_back();
    }
    head = nullptr;
    tail = nullptr;
}

size_t int_list_t::size() const {
    return Size;
}

bool int_list_t::empty() const {
    return Size == 0;
}

void int_list_t::insert(size_t pos, int new_val) {
    if (pos == 0) {
        push_front(new_val);
    } else if (pos == Size || pos > Size) {
        push_back(new_val);
    } else {
        node_t *temp = get_pos(pos-1);

        node_t *newnode_t = new node_t(new_val, temp, temp->pNext);
        temp->pNext = newnode_t;
        node_t *next = newnode_t->pNext;
        next->pPrev = newnode_t;

        Size++;
    }
}

void int_list_t::push_front(int new_val) {
    if (empty()) {
        tail = head = new node_t(new_val, head, tail);
    } else {
        node_t *temp = this->head;
        head = new node_t(new_val, nullptr, temp);
        temp->pPrev = head;
    }
    Size++;
}

void int_list_t::push_back(int new_val) {
    if (empty()) {
        head = tail = new node_t(new_val, head, tail);
    } else {
        node_t *temp = this->tail;
        tail = new node_t(new_val, temp);
        temp->pNext = tail;
    }
    Size++;
}

void int_list_t::erase(size_t pos) {
    if (pos == 0) {
        pop_front();
    } else if (pos == Size - 1) {
        pop_back();
    } else {
            node_t *temp = get_pos(pos-1);

            node_t *toDelete = temp->pNext;
            temp->pNext = toDelete->pNext;
            node_t *next = toDelete->pNext;

            delete toDelete;
            next->pPrev = temp;
        Size--;
    }
}

void int_list_t::pop_front() {
    if (Size > 1) {
        node_t *temp = head;
        head = head->pNext;
        head->pPrev = nullptr;
        delete temp;
    } else if (Size == 1) {
        node_t *temp = head;
        head = tail = head->pNext;
        delete temp;
    }
    Size--;
}

void int_list_t::pop_back() {
    if (Size > 1) {
        node_t *temp = tail;
        tail = tail->pPrev;
        tail->pNext = nullptr;
        delete temp;
    } else if (Size == 1) {
        node_t *temp = tail;
        tail = head = tail->pPrev;
        delete temp;
    }
    Size--;
}

std::istream &operator>>(std::istream &stream, int_list_t &list) {
    int temp = 0;
    list.clear();
    while (stream >> temp) {
        list.push_back(temp);
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    auto temp = list.head;
    for (int i = 0; i != list.Size; i++) {
        stream << temp->data << ' ';
        temp = temp->pNext;
    }
    return stream;
}

int_list_t int_list_t::splice(size_t start_pos, size_t count) {

    node_t *previous = get_pos(start_pos);
    node_t *end1 = previous;

    node_t *next = get_pos(start_pos + count - 1);
    node_t *end2 = next;

    int_list_t new_list;
    new_list.head = end1;
    new_list.tail = end2;
    new_list.Size = count;

    node_t *temp1 = end1->pPrev;
    node_t *temp2 = end2->pNext;

    if (start_pos == 0) {
        this->head = temp2;
        this->head->pPrev = nullptr;
    } else if (start_pos + count == this->Size) {
        this->tail = temp1;
        this->tail->pNext = nullptr;
    } else {
        temp1->pNext = temp2;
        temp2->pPrev = temp1;
    }
    this->Size = Size - count;

    new_list.head->pPrev = nullptr;
    new_list.tail->pNext = nullptr;

    return new_list;
}

int_list_t &int_list_t::merge(int_list_t &other) {
    if (!other.empty()) {

        if (this->empty()) {
            this->head = other.head;
            this->tail = other.tail;
            this->Size = other.Size;

        } else {
            this->tail->pNext = other.head;
            other.head->pPrev = this->tail;

            this->tail = other.tail;
            Size += other.Size;
        }
        other.Size = 0;
        other.head = nullptr;
        other.tail = nullptr;
    }

    return *this;
}

void int_list_t::swap(int_list_t &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(Size, other.Size);
}

void int_list_t::reverse() {
    if (!empty()) {
        node_t *temp = head;
        node_t *current;
        for (int i = 0; i < Size; i++) {
            current = temp->pNext;
            std::swap(temp->pNext, temp->pPrev);
            temp = current;
        }
        std::swap(head, tail);
    }
}

