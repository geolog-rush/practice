#include <type_traits>

// QUESTION:
//
// 4.Linked list:
// a. Remove element in linked list by specified index
// b. Add element to the end of list
// c. Reverse elements (with O(n))
// d. Delete element by it's pointer with complexity O(1)

// SOLUTION:
//
// Because of the lack of information, the list is double linked
// to support required operations.

namespace practice {

template <typename T>
class Node {
   public:
    using value_type = std::remove_cvref_t<T>;

    virtual Node* next() const = 0;
    virtual value_type getValue() const = 0;
    virtual ~Node() = default;
};

template <typename T>
class LinkedList {
   public:
    using value_type = Node<T>::value_type;

    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList(LinkedList&&) = default;
    ~LinkedList() {
        NodeImpl* current = first_;
        while (current) {
            NodeImpl* toDelete = current;
            current = current->next_;
            delete toDelete;
        }
    }

   private:
    class NodeImpl : public Node<T> {
       public:
        NodeImpl(const value_type& value) : value_{value} {}
        Node<T>* next() const override { return next_; }
        value_type getValue() const override { return value_; }

        value_type value_;
        NodeImpl* next_{};
        NodeImpl* prev_{};
    };

   public:
    void add(const value_type& value) {
        NodeImpl* newNode = new NodeImpl(value);
        if (!first_) first_ = newNode;
        if (last_) last_->next_ = newNode;

        newNode->prev_ = last_;
        last_ = newNode;
    }

    void remove(std::size_t idx) {
        if (!first_) return;

        NodeImpl* target{first_};
        std::size_t i{};
        for (; i != idx && target; ++i) target = target->next_;

        // idx is too big
        if (i != idx) return;

        remove(target);
    }

    void remove(Node<T>* targetNode) {
        NodeImpl* target{dynamic_cast<NodeImpl*>(targetNode)};
        if (!target) return;

        NodeImpl* prev = target->prev_;
        if (prev) prev->next_ = target->next_;

        NodeImpl* next = target->next_;
        if (next) next->prev_ = target->prev_;

        if (target == first_) first_ = next;
        if (target == last_) last_ = prev;

        delete target;
    }

    void reverse() {
        std::swap(first_, last_);
        NodeImpl* current = first_;
        while (current) {
            std::swap(current->next_, current->prev_);
            current = current->next_;
        }
    }

    // for testing purposes
    Node<T>* begin() const { return first_; }

   private:
    NodeImpl* first_{};
    NodeImpl* last_{};
};

}  // namespace practice
