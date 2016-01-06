require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_18'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem18 < Minitest::Test
  def test_example
    triangule = [
      [3],
      [7, 4],
      [2, 4, 6],
      [8, 5, 9, 3]
    ]

    assert_equal problem_18(triangule), 23
  end

  def test_solution
    assert_equal problem_18, 1074
  end
end
