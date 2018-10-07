/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:20:07 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/23 17:17:24 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include "libft.h"

# define PROG_NAME_LENGTH	(128)
# define COM_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

# define NAME_CMD_STR		".name"
# define COM_CMD_STR		".comment"

# define COM_CHAR			'#'
# define LBL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define REG_NUMBER			16
# define LBL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define T_REG				1
# define T_DIR				2
# define T_IND				2

# define FORMAT_ERROR		1
# define LBLS_ERROR			2
# define LBL_CHAR_ERROR		3
# define INSTRUCT_ERROR		4
# define MALLOC_ERROR		5
# define INDIRECT_ERROR		6
# define ARGS_ERROR			7
# define LBLS_DOUBLE_ERROR	8
# define LBL_MATCH_ERROR	9
# define NAME_ERROR			10
# define ARG_ERROR			11
# define LINES_ERROR		12
# define FILE_ERROR			13
# define LBL_ERROR			14
# define REG_ERROR			15
# define CHAMPION_ERROR		16
# define NO_ERROR			17

# define LIVE				1
# define LD					2
# define ST					3
# define ADD				4
# define SUB				5
# define AND				6
# define OR					7
# define XOR				8
# define ZJMP				9
# define LDI				10
# define STI				11
# define FORK				12
# define LLD				13
# define LLDI				14
# define LFORK				15
# define AFF				16

int							g_line;
int							g_pos;
int							g_temp;
int							g_error;

typedef struct				s_hdr
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COM_LENGTH + 1];
}							t_hdr;

typedef struct				s_label
{
	char					*name;
	unsigned int			pos;
	struct s_label			*next;
}							t_label;

char						*asm_free_join(char *line, char *file);
char						*asm_realloc(char *line, char *file, int i);
char						*morph_cor(char *champ);
char						*put_line_in_file(char *line, int i, char *file);

int							ac_check(int ac);
int							asm_error_sec(int error);
int							asm_error(int error);
int							asm_instruct_name(char *line);
int							check_arg_sec(char **line, int op);
int							check_arg(char **line, int op);
int							check_champ_name(char *champ);
int							check_comma(char **line);
int							check_direct(char **line, int op, int check);
int							check_double_label(t_label *label);
int							check_header(t_hdr *head, char *line);
int							check_indirect(char **line, int check);
int							check_label_exist(t_label *label, char *str);
int							check_label(char *str);
int							check_register(char **line, int check);
int							check_valid_line(char *line);
int							free_label(t_label *label);
int							header_pass_end(char *line, int i);
int							header_pass(char *s, int name, int com, int check);
int							instruct_name_sec(char *line);
int							match_label(t_label *label, char *str);
int							name_comment_handler(int fd, t_hdr *head);
int							parsing(char *champion, t_hdr *head, int check);
int							save_name_com(char *s, t_hdr *hd, int nme, int com);

t_hdr						*header_init(void);
t_hdr						*save_header(char *line, t_hdr *head, int check);
t_label						*label_init(t_label *label, char *line);
t_label						*parse_line(int fd, char **file);

void						display_champ_name(t_hdr *head);
void						init_global(void);

#endif
