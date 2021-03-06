/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:02:47 by jkasongo          #+#    #+#             */
/*   Updated: 2022/06/22 19:58:37 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

// analyse only for pipe as separator
size_t	analyze_separator(t_token *token, size_t cursor, t_array *lex)
{
	t_lex_token	*lex_tok;

	if ((token->type == e_token_pipe) || (token->type == e_token_or))
	{
		lex_tok = (t_lex_token *)ft_calloc(1, sizeof(t_lex_token));
		if (token->type == e_token_or)
			lex_tok->type = e_lex_pipe_error;
		else
		{
			lex_tok->type = e_lex_pipe;
			lex_get_status_value(128);
		}
		ft_push(lex, lex_tok);
		cursor++;
	}
	return (cursor);
}

// push literal token build from tokens and push it, return cursor
size_t	analyse_lit(t_array *tokens, t_token *tok, size_t i, t_array *lex)
{
	t_lex_token	*lex_tok;
	char		*temp;

	lex_tok = (t_lex_token *)ft_calloc(1, sizeof(t_lex_token));
	lex_tok->type = e_lex_literal;
	lex_tok->value = NULL;
	while (check_if_is_literal(tok))
	{
		if ((tok->type == e_token_quote) && is_close_t_s(tokens, tok, i))
			i = a_quote_t(tokens, tok, i, lex_tok);
		else if ((tok->type == e_token_dquote) && is_close_t_s(tokens, tok, i))
			i = a_dquote_t(tokens, tok, i, lex_tok);
		else if (tok->type == e_token_variable)
			i = a_var_t(tok, i, lex_tok);
		else
		{
			temp = ft_strjoin(lex_tok->value, tok->value);
			free(lex_tok->value);
			lex_tok->value = temp;
			i++;
		}
		tok = (t_token *)ft_get_elem(tokens, i);
	}
	ft_push(lex, lex_tok);
	return (i);
}

size_t	analyse_redirection(t_token *token, size_t cursor, t_array *lex)
{
	t_lex_token	*lex_tok;

	lex_tok = (t_lex_token *)ft_calloc(1, sizeof(t_lex_token));
	lex_tok->type = e_lex_redirection;
	if ((token->type == e_token_greater)
		|| (token->type == e_token_heredoc_right))
		lex_tok->fd = STDOUT_FILENO;
	if (token->type == e_token_less)
		lex_tok->r_type = e_redirection_input;
	else if (token->type == e_token_greater)
		lex_tok->r_type = e_redirection_output;
	else if (token->type == e_token_heredoc_left)
		lex_tok->r_type = e_redirection_heredoc;
	else if (token->type == e_token_heredoc_right)
		lex_tok->r_type = e_redirection_append_out;
	else if (token->type == e_token_herestr)
		lex_tok->type = e_lex_redirection_error;
	ft_push(lex, lex_tok);
	return (cursor + 1);
}

size_t	get_analyser(t_array *tokens, t_token *tok, size_t i, t_array *lex)
{
	size_t	cursor;

	cursor = i;
	if (tok->type == e_token_space)
		cursor++;
	else if (is_minishell_redir(tok))
		cursor = analyse_redirection(tok, cursor, lex);
	else if ((tok->type == e_token_pipe) || (tok->type == e_token_or))
		cursor = analyze_separator(tok, cursor, lex);
	else
		cursor = analyse_lit(tokens, tok, cursor, lex);
	return (cursor);
}

// return t_lex_token type of struct array
t_array	*run_simple_lexer(t_array *tokens)
{
	size_t	i;
	t_array	*lex;
	t_token	*token;

	lex = ft_new_array();
	i = 0;
	token = (t_token *)ft_get_elem(tokens, i);
	lex_get_status_value(1);
	while (token->type != e_token_eof)
	{
		i = get_analyser(tokens, token, i, lex);
		token = (t_token *)ft_get_elem(tokens, i);
	}
	return (lex);
}
