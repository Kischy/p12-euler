#pragma once


#include <algorithm>
#include <functional>


#include "factorize.h"
#include "primenumbers.h"
#include "math_helper.h"


//Only neccessary for get_minimal_number_in_vector
#include <climits>


class Divisors
{
public:

	std::vector<std::vector<unsigned long long> > get_all_factorizations(unsigned long long No_of_divisors)
	{
		calc_all_factorizations(No_of_divisors);

		return all_factorizations_vec;
	}

	unsigned long long lowest_number(unsigned long long No_of_divisors)
	{
		if (is_low_number(No_of_divisors)) return 1;

		return find_lowest(No_of_divisors);
	}



private:

	Factorize fac;
	PrimeNumbers primes;

	std::vector<std::vector<unsigned long long> > all_factorizations_vec{};


	unsigned long long find_lowest(unsigned long long No_of_divisors)
	{
		calc_all_factorizations(No_of_divisors);
		
		std::vector<unsigned long long> poss_vals;

		for (auto factorization : all_factorizations_vec)
		{
			poss_vals.push_back(get_pos_minimal_number(factorization));
		}

		return get_minimal_number_in_vector(poss_vals);
	}


	unsigned long long get_pos_minimal_number(const std::vector<unsigned long long>& factorization) 
	{
		unsigned long long pos_min = 1, prime_pos = 1;

		for (auto exponent : factorization)
		{
			pos_min *= get_pow_of_prime(prime_pos, exponent - 1);
			prime_pos++;
		}

		return pos_min;
	}

	unsigned long long get_pow_of_prime(unsigned long long prime_pos, unsigned long long exponent) 
	{
		return helper::LLPow(primes.get_prime(prime_pos), exponent);
	}

	unsigned long long get_minimal_number_in_vector(const std::vector<unsigned long long>& numbers)
	{
		unsigned long long min = ULLONG_MAX;

		for (auto number : numbers)
		{
			if (number != 0) //Skip zero, because the unsigned long long might overflow
			{
				if (number < min)
				{
					min = number;
				}
			}
		}

		return min;
	}





	bool is_low_number(unsigned long long No_of_divisors) const
	{
		if (No_of_divisors <= 2) return true;

		return false;

	}


	void calc_all_factorizations(unsigned long long No_of_divisors)
	{
		all_factorizations_vec.clear();

		std::vector<unsigned long long> prime_factors = fac.factorize(No_of_divisors);
		all_factorizations_vec = get_all_factorizations(prime_factors);


		sort_multiple_vec_ascending_first_element(all_factorizations_vec);
	}


	std::vector<std::vector<unsigned long long> > get_all_factorizations(std::vector<unsigned long long>& prime_factors) const
	{
		std::vector<std::vector<unsigned long long> > all_factors;

		sort_single_vec_descending(prime_factors);
		all_factors.push_back(prime_factors);

		std::vector<unsigned long long>::size_type index = 0, index2 = 1;
		add_all_poss_fac(all_factors, all_factors.at(0), index, index2);

		return all_factors;
	}


	void add_all_poss_fac(std::vector<std::vector<unsigned long long> >& factors, const std::vector<unsigned long long> last_factors, std::vector<unsigned long long>::size_type& current_first_index, std::vector<unsigned long long>::size_type& current_second_index) const
	{
		if (last_factors.size() <= 1) return;

		while (index_valid(last_factors, current_first_index, current_second_index))
		{
			std::vector<unsigned long long> new_factors = get_factors_for_indizes(last_factors, current_first_index, current_second_index);
			if (!is_element_of(factors, new_factors))
			{
				factors.push_back(new_factors);
				std::vector<unsigned long long>::size_type index = 0, index2 = 1;
				add_all_poss_fac(factors, factors.at(factors.size()-1), index, index2);
			}

			increase_indizes(last_factors, current_first_index, current_second_index);
		}
	}


	bool is_element_of(const std::vector<std::vector<unsigned long long> >& factors, const std::vector<unsigned long long>& to_be_tested) const
	{
		for (auto facs : factors)
		{
			if (facs == to_be_tested) return true;
		}

		return false;
	}


	std::vector<unsigned long long> get_factors_for_indizes(const std::vector<unsigned long long>& last_factors, const std::vector<unsigned long long>::size_type& current_first_index, const std::vector<unsigned long long>::size_type& current_second_index) const
	{

		unsigned long long new_val = last_factors.at(current_first_index) * last_factors.at(current_second_index);

		std::vector<unsigned long long> new_factors{ new_val };

		for (std::vector<unsigned long long>::size_type i = 0; i < last_factors.size(); ++i)
		{
			if ( (i != current_first_index) && (i != current_second_index))
			{
				new_factors.push_back(last_factors.at(i));
			}
		}

		sort_single_vec_descending(new_factors);

		return new_factors;
	}


	bool index_valid(const std::vector<unsigned long long>& factors, const std::vector<unsigned long long>::size_type& current_first_index, const std::vector<unsigned long long>::size_type& current_second_index) const
	{

		unsigned long long size = factors.size();
		if ((current_first_index > (size - 2)) && (current_second_index > (size - 1))) return false;

		return true;
	}


	void increase_indizes(const std::vector<unsigned long long>& factors, std::vector<unsigned long long>::size_type& current_first_index, std::vector<unsigned long long>::size_type& current_second_index) const
	{
		unsigned long long size = factors.size();

		if (current_second_index < (size - 1))
		{
			current_second_index++;
		}
		else
		{
			current_first_index++;
			current_second_index=current_first_index+1;
		}
	}



	void sort_single_vec_descending(std::vector<unsigned long long>& to_be_sorted) const
	{
		std::sort(to_be_sorted.begin(), to_be_sorted.end(), std::greater<unsigned long long>());
	}

	void sort_multiple_vec_ascending_first_element(std::vector<std::vector<unsigned long long> >& to_be_sorted) const
	{
		std::sort(to_be_sorted.begin(), to_be_sorted.end(), [](const std::vector<unsigned long long>& lhs, const std::vector<unsigned long long>& rhs)
		{
			return lhs.at(0) < rhs.at(0);
		});
	}





};






/*
https://stackoverflow.com/questions/34688956/find-a-smallest-number-which-has-exactly-n-divisors



Let's start with the OEIS sequence. Now any number can be expressed as product of prime powers.

enter image description here

How many divisors will it have? You can prove using combinatorics that it will have:

enter image description here

So you have to solve the equation where the expression above is equal to the number of divisions that you have. I will not write a code here, but notice that because you are looking for integer solutions, you can factor out your number of divisors.

When you will find your m_i, you can get your smallest number by sorting m_i and assigning biggest m_i to smallest prime. So if your m1 = 2, m2 = 5, m3 = 2, the number will be 2^5 * 3^2 * 5^2.
shareimprove this answer




http://www.primepuzzles.net/problems/prob_019.htm

    b) Jud McCranie, T.W.A. Baumann & Enoch Haga sent basically the same procedure to find N(d) for a given d:

        Factorize d as a product of his prime divisors: d = p1a1 * p2a2 *p3a3 *...
        convert this factorization in another arithmetically equivalent factorization, composed of non-powered monotonically decreasing and not necesarilly prime factors... (uf!...) d = p1a1 * p2a2 *p3a3 *... = b1 * b2 * b3... such that b1 ≥ b2 ≥ b3...
        You must realize that for every given d, there are several arithmetically equivalent factorizations that can be done: by example:
        if d = 16 = 24 then there are 5 equivalent factorizations: d = 2*2*2*2 = 4*2*2 = 4*4 = 8*2 = 16
        N is the minimal number resulting of computing 2b1-1 * 3b2-1 * 5b3-1 * ... for all the equivalent factorizations of d. Working the same example:
        N(16) = the minimal of these {2 * 3 * 5 * 7, 23 * 3 * 5, 23 * 33, 27 * 3, 215} = 23 * 3 * 5 = 120

Update: With numbers around 1020, pay attention to the notes by Christian Bau quoted on the same page.




*/





