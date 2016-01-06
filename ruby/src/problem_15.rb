# How many such routes are there through a 20×20 grid?
#
# URL: https://projecteuler.net/problem=15

require_relative '../lib/enumerable'

def problem_15(n = 20)
  (1..2 * n).prod.div((1..n).prod ** 2)
end
