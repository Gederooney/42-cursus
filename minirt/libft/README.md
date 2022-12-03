# LIBFT | WITH PRINTF ARRAYS AND STACK | can you use Haki?

Implementation of some of the Standard C Library functions including some additional ones.

 - _If you need the 42 project without any upgrade switch on ***master branch***_
  ```shell
    git checkout master
  ```

**Makefile : CFLAGS = -Wall -Wextra -Werror -c -g** _(you can change -g)_

Addition made to the 42 project for later projects : 

- [My Arrays (Dynamic Array, Dictionary)](#Myarrays)
- [Stack](#Stack)
- [ft_printf (Printf like)](#Printf)
- Help function for normal arrays
  - [Int array addition](#IntArrays)
  - [Arrays memory](#Memory)

## <a name="Myarrays"></a>Dynamic Arrays

```c
typedef struct s_array
{
	size_t			length;
	t_array_type	type;
	t_array_node	*head;
	t_array_node	*bottom;
}	t_array;

typedef struct	s_dic_node
{
	void				*content;
	char				*key;
}	t_dic_node;
```
2 types:
 - Arrays normal
 - Dictionary (Arrays containing t_dic_node)

### Array
```c
t_array			*ft_new_array(void);
bool			ft_push(t_array *array, void *content);
void			*ft_pop(t_array *array);
bool			ft_unshift(t_array *array, void *content);
void			*ft_get_elem(t_array *array, size_t index);
void			**ft_map(t_array *array, void *(*f)(void *, int index));
bool			ft_for_each(t_array *array, void (*apply)(void *, int index));
void			*ft_del_elem(t_array *array, size_t i);
void			ft_free_d_array(t_array *array);
```

### Dictionary
```c
t_array			*ft_new_dic(void);
bool			ft_push_to_dic(t_array *array, char *key, void *content);
t_dic_node		*ft_elem_dic(t_array *array, char *key);
void			**ft_map_d(t_array *array, void *(*f)(void *, char *, size_t i));
void			ft_free_dic(t_array *array);
```
## <a name="Stack"></a>STACK

- ### CREATION
```c
typedef struct s_stack
{
	int				length;
	int				current;
	t_stack_node	*head;
	t_stack_node	*bottom;
}	t_stack;

t_stack			*create_stack(void);
```
- ### FUNCTIONS
```c
bool			push(t_stack *stack, void *content);
void			*pop(t_stack *stack);
void			*peak(t_stack *stack);
int			*map_stack(t_stack *stack, int (*apply)(void *, int index));
bool		        for_each_s(t_stack *stack, void (*apply)(void *, int i));
```
- ### Specials
```c
// swap the first 2 elements at the top of stack (nothing if stack->length <= 1)
bool			swap(t_stack *stack);
// shift up by 1 all elements of the stack return true (false if errors)
bool			rotate(t_stack *stack);
// shift down by 1 all elements of the stack return true (false if errors)
bool			reverse_rotate(t_stack *stack);
```


## <a name="Printf"></a>PRINTF

- flags 0 - + ' '
- args  %s %c %d %i %u %x %X %p
- width
- precision
```c
int		ft_printf(const char *format, ...);
```


## SIMPLE FUNCTIONS
```c
// atoi on base up to 0123456789ABCDEFGHIJK and check prefix 0b, 0B for base 2 and 0x, 0X for base 16
int		ft_atoi_base(const char *str, int base);
```

## ARRAYS
### <a name="IntArrays"></a>Additions
```c
// ability to slice an array and recieve a copy
int		*ft_slice_int(const int original[], int begin, int end);

// check if int array is sorted asc, desc or not sorted
int		type_of_sort(int arr[], int n);
bool	is_sorted_asc(int arr[], int n);
bool	is_sorted_desc(int arr[], int n);
```
### <a name="Memory"></a>Memory
```c
// ability to free splitted strings 
void		ft_free_splitted(char **arr);
void		free_array(void **array, size_t size);
void		free_stack(t_stack *stack);
```
