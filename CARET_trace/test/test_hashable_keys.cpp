// Copyright 2021 Research Institute of Systems Planning, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "caret_trace/keys_set.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <utility>

TEST(HashableKeys, IntCase)
{
  {
    HashableKeys<int> keys(1);
    HashableKeys<int> keys_(1);
    HashableKeys<int> keys__(2);

    EXPECT_TRUE(keys.equal_to(keys_));
    EXPECT_FALSE(keys.equal_to(keys__));

    EXPECT_EQ(keys.hash(), keys_.hash());
    EXPECT_NE(keys.hash(), keys__.hash());
  }

  {
    HashableKeys<int, int, int> keys(1, 2, 3);
    HashableKeys<int, int, int> keys_(1, 2, 3);
    HashableKeys<int, int, int> keys__(2, 2, 3);

    EXPECT_TRUE(keys.equal_to(keys_));
    EXPECT_FALSE(keys.equal_to(keys__));

    EXPECT_EQ(keys.hash(), keys_.hash());
    EXPECT_NE(keys.hash(), keys__.hash());
  }
}
