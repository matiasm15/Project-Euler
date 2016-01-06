require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_27'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem27 < Minitest::Test
  def test_solution
    assert_equal problem_27, -59231
  end
end
