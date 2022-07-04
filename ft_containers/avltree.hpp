#ifndef __AVLTREE_HPP__
#define __AVLTREE_HPP__

namespace ft {
    template<typename T>
    struct Node {
        T data;
        int bf;
        Node *parent;
        Node *left;
        Node *right;

        Node(const T &_data = T()): data(_data), bf(0), parent(NULL), left(NULL), right(NULL) { }
        template<typename pair_t>
        Node& operator=(const Node<pair_t>& origin) {
            if (this != &origin) {
                this->data = origin.data;
                this->bf = origin.bf;
                this->parent = origin.parent;
                this->left = origin.left;
                this->right = origin.right;
            }
            return *this;
        }
    };
    // non-member function for Node
    template<typename node_ptr>
    bool isLeftChild(const node_ptr& node) {
        return node == node->parent->left;
    }
    template<typename node_ptr>
    bool isRightChild(const node_ptr& node) {
        return node == node->parent->right;
    }
    template<typename node_ptr>
    node_ptr minNode(node_ptr node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    template<typename node_ptr>
    node_ptr maxNode(node_ptr node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }
    template<typename node_ptr>
    int getHeight(node_ptr node) {
        if (node == NULL)
            return 0;
        int left_height = getHeight(node->left);
        int right_height = getHeight(node->right);
        return max(left_height, right_height) + 1;
    }
    template<typename node_ptr>
    int calculateBF(node_ptr node) {
        return getHeight(node->left) - getHeight(node->right);
    }
    template<typename node_ptr>
    node_ptr getNextNode(node_ptr node) {
        if (node->right != NULL)
            return minNode(node->right);
        while (!isLeftChild(node))
            node = node->parent;
        return node->parent;
    }
    template<typename node_ptr>
    node_ptr getPrevNode(node_ptr node) {
        if (node->left != NULL)
            return maxNode(node->left);
        while (!isRightChild(node))
            node = node->parent;
        return node->parent;
    }

    template<typename Key, typename Value, typename Comp, typename Allocator>
    class AVLtree {
    public:
        typedef Key key_type;
        typedef Value mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Comp compare_type;

        typedef Node<value_type> node_type;
        typedef node_type* node_pointer;
        typedef map_iterator<value_type, node_type> iterator;
        typedef map_iterator<const value_type, node_type> const_iterator;

        typedef Allocator allocator_type;
        typedef typename allocator_type::template rebind<node_type>::other node_allocator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;        
    private:
        node_pointer _begin;
        node_pointer _end;
        compare_type _comp;
        node_allocator _alloc;
        size_type _size;
    public:
        // constructor, destructor, operator=
        AVLtree(const compare_type& comp, const allocator_type& alloc): _comp(comp), _alloc(alloc), _size(size_type()) {
            _end = makeNode(value_type());
            _begin = _end;
        }
        AVLtree(const AVLtree& copy): _comp(copy._comp), _alloc(copy._alloc), _size(size_type()) {
            _end = makeNode(value_type());
            _begin = _end;
            insert(copy.begin(), copy.end());
        }
        ~AVLtree() {
            destructNodeAll(_end);
        }
        AVLtree operator=(const AVLtree& origin) {
            if (this != &origin) {
                AVLtree tmp(origin);
                swap(tmp);
            }
            return *this;
        }
        // iterator
        iterator begin() {
            return iterator(_begin);
        }
        const_iterator begin() const {
            return const_iterator(_begin);
        }
        iterator end() {
            return iterator(_end);
        }
        const_iterator end() const {
            return const_iterator(_end);
        }
        // capacity
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            return _alloc.max_size();
        }
        bool empty() const {
            return _size == 0;
        }

        // modifier
        ft::pair<iterator, bool> insert(const value_type &value) {
            
        }


















        node_pointer getRoot() const {
            return _end->left;
        }
        void setRoot(const node_pointer node) {
            node->parent = _end;
            _end->left = node;
        }
        node_pointer makeNode(const value_type &value) {
            node_pointer node = _alloc.allocate(1);
            _alloc.construct(node, value);
            // 따로 설정 안 해줘도 생성자 불러오는 건가?
            return node;
        }
        void destructNode(node_poitner node) {
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }
        void destructNodeAll(node_pointer node) {
            if (node == NULL)
                return ;
            destructNodeAll(node->left);
            destructNodeAll(node->right);
            destructNode(node);
        }


        // node functions
        node_pointer LL(node_pointer node) {
            node_pointer child = node->left;

            node->left = child->right;
            if (child->right != NULL)
                child->right->parent = node;
            child->right = node;
            child->parent = node->parent;
            node->parent = child;
            
            return child;
        }
        node_pointer RR(node_pointer node) {
            node_pointer child = node->right;

            node->right = child->left;
            if (child->left != NULL)
                child->left->parent = node;
            child->left = node;
            child->parent = node->parent;
            node->parent = child;

            return child;
        }
        node_pointer LR(node_pointer node) {
            node->left = RR(node->left);
            return LL(node);
        }
        node_pointer RL(node_pointer node) {
            node->right = LL(node->right);
            return RR(node);
        }
        node_pointer balanceFix(node_poitner node) {
            int factor = calculateBF(node);
            if (factor > 1) {
                factor = calculateBF(node->left);
                if (factor > 1)
                    node = LL(node);
                else
                    node = LR(node);
            }
            else if (factor < -1) {
                factor = calculateBF(node->right);
                if (factor < -1)
                    node = RR(node);
                else
                    node = RL(node);
            }
            return node;
        }
        node_pointer insertNode(node_pointer node, value_type data) {
            if (node == NULL) {
                node = makeNode();
                return node;
            }
            else if (_comp(data, node->data)) {
                node->left = insertNode(node->left, data);
                node->left->parent = node;
                node = balanceFix(node);
            }
            else if (_comp(node->data, data)) {
                node->right = insert(node->right, data);
                node->right->parent = node;
                node = balanceFix(node);
            }
            return node;
        }
        

    };
}



#endif