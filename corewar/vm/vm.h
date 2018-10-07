/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:27:21 by mmayibo           #+#    #+#             */
/*   Updated: 2017/10/24 14:34:15 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <term.h>
# include <signal.h>
# include <termcap.h>
# define MAX_ERROR 1000
# define HEADER_BYTES  2192
# define MAX_ALLOWED_CHAMP 1024

enum {FALSE, TRUE};
enum {NO, YES};
enum {LIVE = 1, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD, LLDI,
	LFORK, AFF};
enum {SHOW_CHAMP, SHOW_ARENA, SHOW_CHAR, SHOW_ALL_CHAMPS, SHOW_BOTH};

typedef struct		s_instr
{
	char			size;
	int				value;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	unsigned int	player_size;
	int				playerno;
	int				alive;
	int				reg[REG_NUMBER];
	int				carry;
	unsigned char	prog[MAX_ALLOWED_CHAMP];
	int				pc;
	int				freed;
	struct s_champ	*next;
	struct s_champ	*prev;
	int				wait;
	int				run;
	int				index;
	int				id;
}					t_champ;

typedef struct		s_arena
{
	int				dump;
	int				number;
	int				last_live;
	unsigned char	arena[MEM_SIZE];
	int				cycles_to_die;
	int				players;
	char			p_name[PROG_NAME_LENGTH];
	char			p_com[COMMENT_LENGTH];
	t_champ			*champs;
	int				fd[MAX_PLAYERS];
	char			trace;
	char			visual;
	int				alive;
	int				checks;
}					t_arena;

struct termios		saved;
struct termios		edit;
typedef void		(*t_func)(int, t_arena *, t_champ *);
char				get_options(int ac, char **av, char *err, t_arena *arena);
int					exit_prog(char *message, t_arena *arena);
char				get_fds(int ac, char **av, t_arena *arena);
void				combine_error(char *buf, char *err1, char *err2);
void				read_champs(t_arena *arena);
void				dump_memory(t_arena *arena);
void				fill_arena(t_arena *arena);
void				run_cycles(t_arena *arena);
int					bytes_tonum(unsigned char *bytes, int size);
void				get_values(char op, t_instr *instr, t_arena *arena,
		t_champ *champ);
int					get_one_value(int code, int pc, unsigned char *arena,
		t_champ *champ);
void				decode(unsigned char code, unsigned char *size);
void				convert_tobigendian(unsigned char *num);
void				show_one_champ(t_champ *champ);
void				show_all_champs(t_champ **head);
int					get_reg_index(int size, int pos, unsigned char *arena);
void				add_champ(t_champ **head, t_champ *champ);
void				show_reg_operation(int *val, int size, int op);
void				add_champ(t_champ **head, t_champ *champ);
void				write_toarena(t_arena *arena, unsigned char *bytes,
		int pos, int size);
void				access_data(unsigned char *arena, int size,
		int pos, unsigned char *buf);
void				show_trace(char *message, t_arena *arena,
		t_champ *champ, char show_type);
char				inititate_wait(t_champ *champ, t_arena *arena,
		int wait, char *name);
void				init_arena(t_arena *arena);
void				set_correct_size(unsigned char *size, int len);
int					check_player(t_arena *arena);
void				ft_live(int pc, t_arena *arena, t_champ *champ);
void				ft_and(int pc, t_arena *arena, t_champ *champ);
void				ft_sti(int pc, t_arena *arena, t_champ *champ);
void				ft_ld(int pc, t_arena *arena, t_champ *champ);
void				ft_st(int pc, t_arena *areana, t_champ *champ);
void				ft_add(int pc, t_arena *arena, t_champ *champ);
void				ft_sub(int pc, t_arena *arena, t_champ *champ);
void				ft_or(int pc, t_arena *arena, t_champ *champ);
void				ft_xor(int pc, t_arena *arena, t_champ *champ);
void				ft_zjmp(int pc, t_arena *arena, t_champ *champ);
void				ft_ldi(int pc, t_arena *arena, t_champ *champ);
void				ft_fork(int pc, t_arena *arena, t_champ *champ);
void				ft_lld(int pc, t_arena *arena, t_champ *champ);
void				ft_lldi(int pc, t_arena *arena, t_champ *champ);
void				ft_lfork(int pc, t_arena *arena, t_champ *champ);
void				ft_aff(int pc, t_arena *arena, t_champ *champ);
#endif
