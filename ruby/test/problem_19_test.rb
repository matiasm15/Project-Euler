require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_19'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem19 < Minitest::Test
  def test_solution
    assert_equal problem_19, 171
  end
end
