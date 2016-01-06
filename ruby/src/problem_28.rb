# What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
#
# URL: https://projecteuler.net/problem=28

require_relative '../lib/enumerable'

def problem_28(n = 1001)
  index = 1

  (1..n.div(2)).sum_map(1) do |i|
    index += 8 * i
    4 * index - 12 * i
  end
end
