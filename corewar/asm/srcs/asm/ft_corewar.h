/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/26 14:03:33 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H

# include "op.h"
# include "../../libft/includes/libft.h"
# include <stdio.h>
# define DC DIRECT_CHAR

typedef struct		s_conv
{
	char			*line;
	int				index;
	int				bytes;
	char			haslabel;
	uint8_t			opcode;
	char			hasencoding;
	uint8_t			encoding;
	char			n_params;
	char			b_param[3];
	int				param[3];
	int				param_types[3];
	int				dir_bytes;
	int				indir_bytes;
	struct s_conv	*next;
}					t_conv;

typedef struct		s_lbl
{
	char			*name;
	int				index;
	struct s_lbl	*next;
}					t_lbl;

typedef struct		s_asm
{
	t_conv			*line;
	t_header		header;
	char			*fn;
}					t_asm;

typedef int			(*t_fn)(t_conv **, int, t_lbl*);
int					ft_fileok(char *filename);
uint8_t				ft_get_opcode(char *str);
void				write_to_cor(t_asm *data);
int					convert_file(int fd, char *fn, char *line);
int					ft_get_dir(char *val);
int					ft_get_ind(char *val);
int					ft_get_reg(char *val);
void				ft_decoding(t_conv **inst);
uint8_t				ft_get_encoding(char *str);
uint8_t				bintodec(char *bin_no);
int					ft_is_label_only(char *line);
int					ft_contains_label(char *line);
t_lbl				*create_label(char **line, int t_bytes);
void				add_label(t_lbl **lbl, t_lbl *newlbl);
void				fill_opcode_array(t_fn *func_array);
void				fill_params(t_conv **ins, char **split, t_lbl *lbls);
void				create_all_lbls(t_lbl **lbls, t_conv **iter, int t_bytes);
int					needslabel(char *split);
int					get_lbl(char *item, int index, t_lbl *lbls);
int					update(t_conv **line, int t_bytes, t_lbl *lbls, t_fn *fn);
int					get_bytes_in_line(const char *line, int bytes);

int					ft_sti(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_or(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_xor(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_and(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_live(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_lldi(t_conv **ins, int t_bytes, t_lbl *lbls);

int					ft_ld(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_st(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_add(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_sub(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_zjmp(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_ldi(t_conv **ins, int t_bytes, t_lbl *lbls);

int					ft_lld(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_lfork(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_aff(t_conv **ins, int t_bytes, t_lbl *lbls);
int					ft_fork(t_conv **ins, int t_bytes, t_lbl *lbls);
void				show_conv_before(char *line);
void				show_buffer_after(t_conv *line);
void				show_hex(t_conv *conv);
void				remove_tabs(char *line);
char				*get_fn_cor(char *fn);
void				destroy_labels(t_lbl *lbls);
void				destroy_data(t_conv *data);

int					init_struct(t_conv *temp, char **line);
int					count_all_bytes(t_asm *data);
void				cut_off_comment(char **line);
void				get_string(char *str, char *line);
int					add_line(t_conv **data, char **line);
int					get_file(int fd, t_asm *data, char *line);

void				ft_iter(t_conv **iter, int *t_bytes,
		t_lbl **lbls, t_fn fns);
void				small_hex(uint8_t octet);
void				print_hex(uint8_t octet);
void				set_val(uint8_t *line, t_asm *data,
		int lfd, uint8_t *byte);

#endif
