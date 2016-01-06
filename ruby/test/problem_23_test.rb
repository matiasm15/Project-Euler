require 'minitest/reporters'
require 'minitest/autorun'
require_relative '../src/problem_23'
Minitest::Reporters.use!(Minitest::Reporters::SpecReporter.new)

class TestProblem23 < Minitest::Test
  def test_solution
    assert_equal problem_23, 4179871
  end
end
