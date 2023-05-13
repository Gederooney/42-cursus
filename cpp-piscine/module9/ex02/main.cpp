/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:45:26 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/12 21:19:38 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>

// main.cpp
#include <ctime>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [list of numbers]" << std::endl;
		return 1;
	}

	try {
		std::stringstream ss;
		PmergeMe<int> p;

		std::list<int> l;
		std::deque<int> d;

		p.insert(l, argv + 1);
		p.insert(d, argv + 1);

		ss << "Before: ";
		ss << p.print(l);
		ss << std::endl;

		std::clock_t start = std::clock();
		p.sort(l);
		std::clock_t stop = std::clock();
		double durationL = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);

		start = std::clock();
		p.sort(d);
		stop = std::clock();
		double durationD = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);

		ss << "After: ";
		ss << p.print(l);
		ss << std::endl;

		ss << "Time to process a range of " << l.size() << " elements with std::list " << durationL << " seconds" << std::endl;
		
		ss << "Time to process a range of " << d.size() << " elements with std::deque " << durationD << " seconds" << std::endl;

		std::cout << ss.str();

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
