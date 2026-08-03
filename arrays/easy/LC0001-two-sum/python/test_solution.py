from solution import two_sum


def test_basic_pair():
    assert two_sum([2, 7, 11, 15], 9) == [0, 1]


def test_pair_not_at_start():
    assert two_sum([3, 2, 4], 6) == [1, 2]


def test_same_value_at_different_indices():
    """Both elements have the same value — must not reuse the same index."""
    assert two_sum([3, 3], 6) == [0, 1]


def test_negative_numbers():
    assert two_sum([-3, 4, 3, 90], 0) == [0, 2]


def test_negative_target():
    assert two_sum([-1, -2, -3, -4], -6) == [1, 3]


def test_no_solution_returns_empty():
    """Problem guarantees a solution, but the function should not crash."""
    assert two_sum([1, 2, 3], 100) == []
