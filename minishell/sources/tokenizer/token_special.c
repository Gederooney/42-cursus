/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:02:11 by jkasongo          #+#    #+#             */
/*   Updated: 2022/06/22 18:20:51 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

/*
 * Check if we need to replace a single special shell char by a complex one
 * Return a e_token_type > 0 or 0
 * if we have succesive token of '>' '>' we replace by a single ">>"
 * if we have successive token of '$' '(' we replace by a single "$("
 */
int	ft_check_double_t(int t, t_tokeniser *lex, size_t cursor)
{
	t_token	*last_t;

	last_t = (t_token *)ft_get_elem(lex->tokens, (lex->tokens->length -1));
	if (!last_t && cursor < 1)
		return (0);
	if ((t == e_token_and) && (last_t->type == e_token_and))
		return (e_token_double_and);
	else if (t == e_token_pipe && last_t->type == e_token_pipe)
		return (e_token_or);
	else if (t == e_token_left_paren && last_t->type == e_token_dollar)
		return (e_token_subst);
	else if (t == e_token_less && last_t->type == e_token_less)
		return (e_token_heredoc_left);
	else if (t == e_token_greater && last_t->type == e_token_greater)
		return (e_token_heredoc_right);
	else if (t == e_token_less && last_t->type == e_token_heredoc_left)
		return (e_token_herestr);
	else if ((t == e_token_space) && (last_t->type == e_token_space))
		return (e_token_space);
	else if ((t == e_token_text) && (last_t->type == e_token_dollar))
		return (e_token_variable);
	return (0);
}

/*
* Replace a simple token by a complex one, eg (< by << )or (23< by < meta=23)
*/
void	custom_tok(t_token *curr, t_token *last, int cursor, char *str)
{
	curr->start_pos = last->start_pos;
	if (curr->type == e_token_variable)
	{
		curr->value = get_word_in_sentence(cursor, str, ft_strlen(str));
		curr->meta = last->value;
		curr->end_pos = cursor + ft_strlen(curr->value);
		free(last);
		return ;
	}
	else
		curr->value = ft_concat_char(last->value, str[cursor]);
	curr->end_pos = cursor + 1;
	free(last);
}
