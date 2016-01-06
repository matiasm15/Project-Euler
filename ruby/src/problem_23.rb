# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
#
# URL: https://projecteuler.net/problem=23

require_relative '../lib/integer'
require_relative '../lib/enumerable'

def problem_23(limit = 28123)
  abundant_numbers = (1..limit).select do |i|
    proper_divisors = i.divisors
    proper_divisors.delete(i)
    proper_divisors.sum > i
  end

  not_sum_abundant = (1..limit).to_a - abundant_numbers.repeated_combination(2).map { |x| x.sum }
  not_sum_abundant.sum
end
