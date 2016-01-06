# Find the product of the coefficients, a and b, for the quadratic expression that
# produces the maximum number of primes for consecutive values of n, starting with n = 0.
#
# URL: https://projecteuler.net/problem=27

require_relative '../lib/integer'
require_relative '../lib/enumerable'

def problem_27(limit = 1000)
  limit -= 1

  (-limit..limit).to_a.repeated_permutation(2).max_by { |a, b|
    (1..Float::INFINITY).take_while { |n|
      res = n ** 2 + a * n + b
      res > 1 && res.prime?
    }.size
  }.prod
end
