#include "../circular_buffer/circular_buffer.hpp"

#include <gtest/gtest.h>

namespace
{

  static int NUMBER_OF_VALUES = 10;

  TEST(CircularBuffer, MaxSize)
  {

    CircularBuffer<int> buf(NUMBER_OF_VALUES);

    EXPECT_EQ(NUMBER_OF_VALUES, buf.get_max_size());
  }

  TEST(CircularBuffer, Size)
  {

    CircularBuffer<int> buf(NUMBER_OF_VALUES);

    for (int i = 0; i < NUMBER_OF_VALUES; i++)
    {
      buf.push(i);
    }
    EXPECT_EQ(NUMBER_OF_VALUES, buf.size());
  }

  TEST(CircularBuffer, PushAndPop)
  {

    CircularBuffer<int> buf(NUMBER_OF_VALUES);
    std::list<int> test_vector;

    for (int i = 0; i < NUMBER_OF_VALUES; i++)
    {
      test_vector.push_back(i);
      buf.push(i);
    }

    EXPECT_EQ(NUMBER_OF_VALUES, buf.size());

    for (int i = 0; i < NUMBER_OF_VALUES; i++)
    {
      EXPECT_EQ(test_vector.back(), buf.pop());
      test_vector.pop_back();
    }
  }

  TEST(CircularBuffer, PeekAll)
  {

    CircularBuffer<int> buf(NUMBER_OF_VALUES);
    std::list<int> test_vector;

    for (int i = 0; i < NUMBER_OF_VALUES; i++)
    {
      test_vector.push_back(i);
      buf.push(i);
    }

    std::list<int> result = buf.peak_all();
    EXPECT_EQ(test_vector, result);
  }

} // namespace