long int fibs[81] = {0};
long int fibonacci(int n) {
	if (n == 1 || n == 2) { // caso base
		return 1;
	} else if (fibs[n] != 0) { // caso já calculado
		return fibs[n];
	}
	fibs[n] = fibonacci(n - 1) + fibonacci(n - 2); // calcula e salva
	return fibs[n];
}