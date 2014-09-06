#include <iostream>
#include <vector>

int sieve_of_eratosthenes() {
	
	int m,n = 0;
	std::cin >> m;
	n = m+1;
	std::vector<bool> not_prime(n);

	for(int x = 2; x < n;) {
		std::cout << x << std::endl;
		for(int i = x; i < n; i = x+i) {
			if(x == i) {}
			else if(not_prime[i]){}
			else {
				not_prime[i] = true;
			}
		}

		++x;
		while(not_prime[x] && x < n) {
				++x;
		}
	}
	return 0;

}
