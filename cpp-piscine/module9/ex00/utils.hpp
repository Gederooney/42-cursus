/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:42:59 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 14:26:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string>
# include <vector>
# include <sstream>

bool isValidDate(std::string date);
bool isDouble(std::string str);
std::string tream(std::string str);
std::vector<std::string> split(std::string str, char c);
bool isLeapYear(int year);

#endif
