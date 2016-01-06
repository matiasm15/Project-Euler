class Integer
  def divisors
    (1..Math.sqrt(self)).select { |i| self.modulo(i).zero? }.flat_map { |i| [i, self.div(i)] }.sort.uniq
  end

  def prime?
    self.divisors.size.eql?(2)
  end
end
