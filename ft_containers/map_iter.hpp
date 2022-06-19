#ifndef __MAP_ITER_HPP__
#define __MAP_ITER_HPP__

namespace ft
{
	template<typename T, typename node_type>
	class mapIter
	{
	public:
		node_type *_node;
	
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef value_type *pointer;

		mapIter(): _node(NULL) { }
		mapIter(node_type *src)
		{
			_node = src;
		}
		mapIter(value_type &src)
		{
			this->_node = src._node;
		}
		virtual ~mapIter()
		{
			return ;
		}
		mapIter &operator=(mapIter const &rhs)
		{
			if (this != &rhs)
				this->_node = rhs._node;
			return *this;
		}

		template<typename U>
		bool operator==(const mapIter<U, node_type> &rhs) const
		{
			return this->_node == rhs._node;
		}
		template<typename U>
		bool operator!=(const mapIter<U, node_type> &rhs) const
		{
			return this->_node != rhs._node;
		}

		mapIter &operator++()
		{
			if (this->_node->right != NULL)
				this->_node = minimum(this->_node->right);
			else
			{
				node_type *child = this->_node;
				this->_node = this->_node->parent;
				while (this->_node && child == this->_node->right)
				{
					child = this->_node;
					this->_node = this->_node->parent;
				}
			}
			return *this;
		}
		mapIter operator++(int)
		{
			mapIter tmp(*this);
			++(*this);
			return tmp;
		}
		mapIter &operator--()
		{
			if (this->_node->left != NULL)
				this->_node = maximum(this->_node->left);
			else
			{
				node_type *child = this->_node;
				this->_node = this->_node->parent;
				while (this->_node && child == this->_node->left)
				{
					child = this->_node;
					this->_node = this->_node->parent;
				}
			}
			return *this;
		}
		mapIter operator--(int)
		{
			mapIter tmp(*this);
			--(*this);
			return tmp;
		}
		reference operator*() const
		{
			return _node->key;
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		operator mapIter<const value_type, node_type>() const
		{
			return mapIter<const value_type, node_type>(this->_node);
		}
	};
}



#endif