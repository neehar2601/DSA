from two_sum import two_sum


def test_basic_pair():
    assert two_sum([2, 7, 11, 15], 9) == [0, 1]


def test_no_solution_returns_empty():
    assert two_sum([1, 2, 3], 100) == []


def test_handles_negative_numbers():
    assert two_sum([-3, 4, 3, 90], 0) == [0, 2]


def test_same_value_used_twice_at_different_indices():
    assert two_sum([3, 3], 6) == [0, 1]
