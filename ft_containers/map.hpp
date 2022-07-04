#ifndef __MAP_HPP__
#define __MAP_HPP__

# include <iostream>
# include <memory>
# include <map>
# include "utils.hpp"
# include "map_iterator.hpp"
# include "iterator_traits.hpp"
# include "pair.hpp"

namespace ft {
    template<typename Key, typename Mapped, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {
    public:
        typedef Key key_type;
        typedef Mapped mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        class value_compare {

        };

        typedef ft::Node<value_type> node_type;
        typedef node_type* node_ptr;

        typedef ft::map_iterator<value_type, node_type> iterator;
        typedef ft::map_iterator<const value_type, node_type> const_iterator;
        typedef ft::reverse_iterator_tag<iterator> reverse_iterator;
        typedef ft::reverse_iterator_tag<const_iterator> const_reverse_iterator;

        typedef ptrdiff_t difference_type;
        typedef size_t size_type;        
    private:
        node_ptr _node;
        std::allocator<node_type> _allocNode;
        allocator_type _alloc;
        key_compare _k_comp;
        size_type _size;
    public:
        // constructor, destructor, operator=
        explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()): _node(0), _alloc(alloc), _k_comp(comp), _size(0) {
            _node = _allocNode.allocate(1);
            allocNode_construct(&_node);
        }
        template<typename InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type()): _node(0), _alloc(alloc), _k_comp(comp), _size(0) {
            _node = _allocNode.allocate(1);
            allocNode_construct(&_node);
            insert(first, last);
        }
        map(const map& copy): _node(0), _alloc(copy._alloc), _k_comp(copy._k_comp), _size(0) {
            _node = _allocNode.allocate(1);
            allocNode_construct(&_node);
            *this = x;
        }
        ~map() {
            clear();
            _allocNode.deallocate(_node, 1);
        }
        map& operator=(const map& origin) {

        }

        // iterator
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // capacity
        bool empty() const {
            return _size == 0;
        }
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            return _allocNode.max_size();
        }

        // element access
        mapped_type &operator[](const key_type& key) {
            if (_size != 0 && searchNode)
        }

    }



}




#endif