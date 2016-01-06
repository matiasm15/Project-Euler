# How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
#
# URL: https://projecteuler.net/problem=19

require 'date'

def problem_19(fecha_inicial = Date.new(1901, 1, 1), fecha_final = Date.new(2000, 12, 31))
  cant_domingos = 0

  while fecha_final >= fecha_inicial
    fecha_inicial = fecha_inicial.next_month
    cant_domingos += 1 if fecha_inicial.sunday?
  end

  cant_domingos
end
