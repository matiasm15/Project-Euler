require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_28'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem28 < Minitest::Test
  def test_example
    assert_equal problem_28(5), 101
  end

  def test_solution
    assert_equal problem_28, 669171001
  end
end
