require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_15'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem15 < Minitest::Test
  def test_example
    assert_equal problem_15(2), 6
  end

  def test_solution
    assert_equal problem_15, 137846528820
  end
end
