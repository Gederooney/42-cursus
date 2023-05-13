/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:45:26 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/13 15:39:07 by ryebadok         ###   ########.fr       */
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
		std::stringstream ss2;
		PmergeMe<int> p;

		std::list<int> l;
		std::deque<int> d;

		std::clock_t start;
		std::clock_t stop;
		double duration;

		start = std::clock();
		p.insert(l, argv + 1);
		stop = std::clock();
		duration = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);
		
		ss << "Before: ";
		ss << p.print(l);
		ss << std::endl;


		ss2 << "Time to insert a range of " << l.size() << " elements with std::list " << duration * 1000 << " miliseconds" << std::endl;

		start = std::clock();
		p.insert(d, argv + 1);
		stop = std::clock();
		duration = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);

		ss2 << "Time to insert a range of " << d.size() << " elements with std::deque " << duration * 1000 << " miliseconds" << std::endl;

		start = std::clock();
		p.sort(l);
		stop = std::clock();
		duration = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);

		ss2 << "Time to sort a range of " << l.size() << " elements with std::list " << duration * 1000 << " miliseconds" << std::endl;

		start = std::clock();
		p.sort(d);
		stop = std::clock();
		duration = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);

		ss << "After: std::list: ";
		ss << p.print(l);
		ss << std::endl;

		ss << "After: std::deque: ";
		ss << p.print(d);
		ss << std::endl;

		ss2 << "Time to sort a range of " << d.size() << " elements with std::deque " << duration * 1000 << " miliseconds" << std::endl;

		std::cout << ss.str();
		std::cout << ss2.str();

	} catch (const std::exception& e) {
		std::cerr << "Error " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
