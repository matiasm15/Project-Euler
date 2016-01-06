module Enumerable
  def prod_map(start = 1, &block)
    self.inject(start) { |prd, x| prd * block.call(x) }
  end

  def prod(start = 1)
    self.prod_map(start) { |x| x }
  end

  def sum_map(start = 0, &block)
    self.inject(start) { |sum, x| sum + block.call(x) }
  end

  def sum(start = 0)
    self.sum_map(start) { |x| x }
  end

  def max_map(&block)
    self.map(&block).max
  end

  def min_map(&block)
    self.map(&block).min
  end
end
