#include "hello_world.hpp"

#include <gtest/gtest.h>

TEST(HelloWorld, ReturnsGreeting) {
  EXPECT_EQ(greet(), "Hello, C++23!");
}
