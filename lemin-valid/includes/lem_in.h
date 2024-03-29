#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"
typedef struct	s_rooms
{
	int	**paths;
	int	num_of_rooms;
	char	**room_names;
	t_list	*room_name_list;
}		t_rooms;

typedef	struct	s_queue
{
	t_list	*first;
	t_list	*last;
}		t_queue;

typedef	struct	s_ant
{
	int	n;
	t_list	*path;
}		t_ant;

void	gnl(char **line);
void	add_rooms(t_rooms **rooms, int *start, int *end);
void	print_ants(int ants, int start, int end, t_rooms *rooms);
void	add_link_to_list(t_rooms **rooms, char *line);
void	free_split(char **split);
t_list	*get_paths(t_rooms *rooms, int start, int end);
int		free_with_return(char *str, int r);
void	send_error(int b);
void	delete_generic(void *content, size_t content_size);
void	delete_paths(void *content, size_t content_size);
t_rooms	*new_rooms(void);
void	add_rooms_to_array(t_rooms **rooms, int *start, int *end);
void	free_rooms(t_rooms *rooms);
t_list	*new_list(int n);
int		gfp(int *p);
t_list	*get_connecting_rooms(int visiting, t_rooms *rooms, int end);
t_list	*get_path(t_rooms *rooms, int end, int *room_pointers);
void	remove_visited(t_rooms *rooms, int start);
t_queue	*new_t_queue(void);
void	push(t_queue *queue, t_list *ta);
t_list	*pop(t_queue *queue);
int		is_empty(t_queue *queue);
t_list	*peek(t_queue *queue);
void	sort_paths(t_list **paths);
int		pop_to_visit(t_queue *to_visit);
void	find_path_capacity(t_list *paths, int ants);
void	iap(t_queue **tv, int s, int *rp, t_rooms *r);
void	get_room_pointers(int *visiting, t_rooms *rooms);
void	remove_ste_connections(t_queue *paths, t_rooms *rooms, int s, int e);

void	write_paths_file(t_list *paths, t_rooms *rooms);

#endif
