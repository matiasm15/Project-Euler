require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_26'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem26 < Minitest::Test
  def test_example
    assert_equal problem_26(10), 7
  end

  def test_solution
    assert_equal problem_26, 983
  end
end
