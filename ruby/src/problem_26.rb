# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
#
# URL: https://projecteuler.net/problem=26

require_relative '../lib/enumerable'

def problem_26(limit = 1000)
  (2...limit).max_by do |i|
    modulo = 1
    recurring_cycle = 0
    array_divmod = []

    loop do
      divmod = (modulo * 10).divmod(i)

      index = array_divmod.find_index(divmod)
      if !index.nil?
        recurring_cycle = array_divmod.size - index
        break
      end

      array_divmod << divmod

      modulo = divmod.last
      break if modulo.zero?
    end

    # puts "#{i}: #{recurring_cycle}"

    recurring_cycle
  end
end
