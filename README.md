# Prime Numbers

This is just me playing around with prime numbers and other stuff related to number theory.

## Greatest Common Divisor

```plain
gcd(x, y) =
    y == 0
    ? x
    : gcd(y, x % y);
```

## Least Common Multiple

```plain
lcm(x, y) = x * y / gcd(x, y);
```

## Sieve of Erastothenes

```plain
sieve_of_erastothenes(N):
    L = [2, ..., N];
    P = [];
    while (L is not empty):
        F = first element of L;
        append F to P;
        for j = F to N with step F:
            remove j from L;
    return P
```

## Is Prime

### Only odd numbers

```plain
is_prime(N):
    for i = 3 to sqrt(N) with step 2:
        if N % i == 0:
            return False;
    return True;
```

### Using the Sieve of Erastothenes

```plain
is_prime(N):
    P = sieve_of_erastothenes(floor(sqrt(N)));
    for p in P:
        if (N % p == 0):
            return False;
    return True;
```

## Prime Factorization

```plain
partial_factorization(N, p):
    X = N
    f = 0;
    while (X % p == 0):
        ++f;
        X /= p;
    return [X, f]
    # N = p**f * X

factorization(N):
    P = sieve_of_erastothenes(floor(sqrt(N)))
    F = map()
    X = N
    for p in P:
        if (X % p == 0):
            X, f = partial_factorization(X, p);
            F[p] = f
    if (X != 1):
        F[X] = 1 # X is prime
    return F
```

