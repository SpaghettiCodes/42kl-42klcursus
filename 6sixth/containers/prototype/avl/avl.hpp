#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
using namespace std;

template <class _type>
class avl_node
{
	public:
		avl_node(avl_node<_type> *prev_node) : data(), l_weight(0), r_weight(0), 
				left(nullptr), right(nullptr), prev(prev_node) { }
		
		avl_node(avl_node<_type> &ori) : data(ori.data), l_weight(ori.l_weight), r_weight(ori.r_weight), 
				left(ori.left), right(ori.right), prev(ori.prev) { }

		avl_node(avl_node<_type> *prev_node, const _type &stuff) : data(stuff), l_weight(0), r_weight(0), 
				left(nullptr), right(nullptr), prev(prev_node) { }

		avl_node<_type> *go_left()
		{ return (this->left); }

		avl_node<_type> *go_right()
		{ return (this->right); }

		void	assign_l(avl_node<_type> *ptr)
		{ left = ptr; }

		void	assign_r(avl_node<_type> *ptr)
		{ right = ptr; }

		avl_node<_type>	*get_prev()
		{ return (this->prev); }

		void	set_prev(avl_node<_type> *prev)
		{ this->prev = prev; }

		void	recal_l_weight()
		{
			avl_node *current;

			current = this;
			l_weight = 0;
			while (current->go_left())
			{
				++l_weight;
				current = current->go_left();
			}
		}

		void	recal_r_weight()
		{
			avl_node *current;

			current = this;
			r_weight = 0;
			while (current->go_right())
			{
				++r_weight;
				current = current->go_right();
			}
		}

		void	recal_weights()
		{
			this->recal_l_weight();
			this->recal_r_weight();
		}

		void	recal_all_weights()
		{
			this->recal_weights();

			if (this->go_left())
				this->go_left()->recal_all_weights();
			if (this->go_right())
				this->go_right()->recal_all_weights();
		}

		int	cal_balance_factor()
		{ return (r_weight - l_weight); }

		bool	is_balanced()
		{
			int	balance_factor = cal_balance_factor();
			return (balance_factor >= -1 && balance_factor <= 1);
		}

		_type	&getdata()
		{ return (data); }

	private:
		int				l_weight;
		int				r_weight;
		_type			data;
		avl_node<_type> *prev;
		avl_node<_type>	*left;
		avl_node<_type>	*right;
};

// left is lesser, right is larger
template <class _type>
class AVL
{
	public:
		AVL(): head(nullptr) { }

		void	delete_info()
		{ remove_all(head); }

		void	assign_new(const _type &data)
		{
			avl_node<_type>	*new_node = new avl_node<_type>(nullptr, data);
			
			if (!head){
				head = new_node;
				return ;
			}
			avl_node<_type>	*current;
			avl_node<_type>	*prev;

			current = head;
			prev = nullptr;
			while (current)
			{
				prev = current;
				current = (current->getdata() < data) ? current->go_left() : current->go_right();
			}
			new_node->set_prev(prev);
			(prev->getdata() < data) ? prev->assign_l(new_node) : prev->assign_r(new_node);
			head->recal_all_weights();
			rebalance(head);
		}

		avl_node<_type> *head	get_unbalanced(avl_node<_type> *cur)
		{
			
		}

		void	rebalance(avl_node<_type> *current)
		{
			
		}

		void	print_stuff()
		{ print_node(head, 0); }

	private:
		avl_node<_type>	*head;

		void	print_node(avl_node<_type> *current, int left_right)
		{
			if (!current)
				return ;
			cout << "prev node ( ";
			(current->get_prev() ? cout << current->get_prev() : cout << "0x000000000000");
			cout << " ) node ( " << current; 
			cout << " ) l_or_r ( ";
			(left_right) ? ( (left_right == 1) ? (cout << "right") : (cout << "left ") ) : (cout << "head ");
			cout << " ) val ( " << current->getdata();
			cout << " ) balance factor ( " << current->cal_balance_factor() << " )" << endl;
			print_node(current->go_left(), -1);
			print_node(current->go_right(), 1);
		}

		void	remove_all(avl_node<_type> *start)
		{
			if (!start)
				return ;
			remove_all(start->go_left());
			remove_all(start->go_right());

			delete start;
			start = nullptr;
		}

};

#endif