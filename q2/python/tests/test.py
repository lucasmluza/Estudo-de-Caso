import unittest

from circular_buffer.circular_buffer import CircularBuffer

class TestCircularBuffer(unittest.TestCase):

    def test_max_size(self):
        NUMBER_OF_VALUES = 64
        buf = CircularBuffer(NUMBER_OF_VALUES)
        self.assertEqual(buf.get_max_size(), NUMBER_OF_VALUES, 'The class did not returnd the right max size')

    def test_size(self):
        NUMBER_OF_VALUES = 256
        buf = CircularBuffer(NUMBER_OF_VALUES)
        for val in range(NUMBER_OF_VALUES):
            buf.push(val)
        self.assertEqual(buf.size(), NUMBER_OF_VALUES, 'The number of pushed elements differs from the number of elements stored')

    def test_push_and_pop(self):
        NUMBER_OF_VALUES = 256
        test_vector = list(range(0, NUMBER_OF_VALUES))
        buf = CircularBuffer(NUMBER_OF_VALUES)
        for val in test_vector:
            buf.push(val)
        self.assertEqual(buf.size(), NUMBER_OF_VALUES, 'The number of pushed elements differs from the number of elements stored')
        test_vector.reverse()
        for val in test_vector:
            self.assertEqual(buf.pop(), val, 'The pop return value is different from the expected')

    def test_peek_all(self):
        NUMBER_OF_VALUES = 128
        buf = CircularBuffer(NUMBER_OF_VALUES)
        test_vector = list(range(0, NUMBER_OF_VALUES))
        for val in test_vector:
            buf.push(val)
        self.assertEqual(buf.peek_all(), test_vector, 'The peak_all function could not retrieve the right data')

    def test_overflow(self):
        NUMBER_OF_VALUES = 16
        buf = CircularBuffer(NUMBER_OF_VALUES)
        test_vector = list(range(0, NUMBER_OF_VALUES*2))
        for val in test_vector:
            buf.push(val)
        self.assertEqual(buf.size(), NUMBER_OF_VALUES, 'The number of pushed elements differs from the number of elements stored')
        self.assertEqual(buf.peek_all(), test_vector[NUMBER_OF_VALUES:], 'The peak_all function could not retrieve the right data')

    def test_overflow_pop(self):
        NUMBER_OF_VALUES = 16
        buf = CircularBuffer(NUMBER_OF_VALUES)
        test_vector = list(range(0, NUMBER_OF_VALUES*2))
        for val in test_vector:
            buf.push(val)
        self.assertEqual(buf.size(), NUMBER_OF_VALUES, 'The number of pushed elements differs from the number of elements stored')
        for _ in range(NUMBER_OF_VALUES*2):
            buf.pop()
        self.assertEqual(buf.size(), 0, 'The number of elements should be 0')
        self.assertEqual(buf.peek_all(), [], 'The peak_all return should be an empty list')

if __name__ == '__main__':
    unittest.main()