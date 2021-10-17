import datetime


def is_it_prime(n):
    for d in range(2, n):
        if d * d > n:
            break
        if n % d == 0:
            return False
    return True


def main():
    """
    Create a list of prime number bools from one to a million as efficiently as possible.
    The list will be filled with bools. lst[n] should return, if n is a prime number.
    To achieve this, the Sieve of Erastothenes is implemented,
    which is way more efficient than always checking if a number is a prime.
    The Sieve of Erastothenes skips all multiples of a number that we already know is a prime.
    For example, as 2 is a prime, we know that we don't need to check all multiples of 2 (= all even numbers), 
    because they are already divisible by 1, 2 and themself (prime numbers must only have two divisors: 1 and themself).
    """
    time_start = datetime.datetime.now()
    count = 1_000_000 + 1  # 1 MILLION + 1
    # Setup: Prefill list with a million Trues. Later, if a number is not a prime, we will change it to False
    all_primes = [True] * count
    # Setup: 0 and 1 are special cases and no primes
    all_primes[0] = False
    all_primes[1] = False
    for i in range(0, count):
        # If a number is already marked as false, it has already been calculated and we can continue with the next iteration
        if not all_primes[i]:
            continue
        
        # The algorithm stops at 500_001, as the first multiple of all numbers higher than 500_000 will be over our limit of 1_000_000
        if i > count / 2:
            break
        
        # Finally, we check if a number is a prime
        if is_it_prime(i):
            # Marks all multiples of a prime as non-primes (As explained in the docstring)
            for j in range(i, count, i):
                if j > i:
                    all_primes[j] = False

    time_end = datetime.datetime.now()
    time_diff = time_end - time_start
    print(f"Time for {count} prime numbers: {time_diff}")
    print(f"Number of primes between 1 and {count}: {all_primes.count(True)}")
    return all_primes


isPrime = main()
