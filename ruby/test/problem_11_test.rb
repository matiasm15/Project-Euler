require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_11'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem11 < Minitest::Test
  def test_solution
    assert_equal problem_11, 70600674
  end
end
