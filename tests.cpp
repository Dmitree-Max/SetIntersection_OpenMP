#include "set_intersection.cpp"

#include <gtest/gtest.h>

#define setMaxValue 1000000

std::set<int> first, second, third, expected_result;

class CommonSetIntersection : public testing::Test {
public:
    static void SetUpTestSuite() {
    	first.clear();
    	second.clear();
    	third.clear();
    	expected_result.clear();

		for (int var = 0; var < setMaxValue; var += 3) {
			first.insert(var);
		}

		for (int var = 0; var < setMaxValue; var += 5) {
			second.insert(var);
		}

		for (int var = 0; var < setMaxValue; var += 7) {
			third.insert(var);
		}

		for (int var = 0; var < setMaxValue; var += 3 * 5 * 7) {
			expected_result.insert(var);
		}
	}
};


TEST_F(CommonSetIntersection, naiveSetIntersection) {
    ASSERT_EQ(expected_result, naiveSetIntersection(first, second, third));
}

TEST_F(CommonSetIntersection, onePassSetIntersection) {
    ASSERT_EQ(expected_result, onePassSetIntersection(first, second, third));
}

TEST_F(CommonSetIntersection, naiveMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(CommonSetIntersection, naiveMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(CommonSetIntersection, naiveMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(CommonSetIntersection, naiveMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(CommonSetIntersection, partioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(CommonSetIntersection, partioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(CommonSetIntersection, partioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(CommonSetIntersection, partioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(CommonSetIntersection, valuePartioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(CommonSetIntersection, valuePartioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(CommonSetIntersection, valuePartioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(CommonSetIntersection, valuePartioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersectionSumResult_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 1));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersectionSumResult_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 2));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersectionSumResult_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 4));
}

TEST_F(CommonSetIntersection, onePassMultiThreadSetIntersectionSumResult_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 8));
}

class LowIntersection : public testing::Test {
public:
    static void SetUpTestSuite() {
    	first.clear();
    	second.clear();
    	third.clear();
    	expected_result.clear();

		for (int var = 0; var < setMaxValue; var += 3) {
			first.insert(var);
		}

		for (int var = 1; var < setMaxValue; var += 3) {
			second.insert(var);
		}

		for (int var = 2; var < setMaxValue; var += 3) {
			third.insert(var);
		}
	}
};

TEST_F(LowIntersection, naiveSetIntersection) {
    ASSERT_EQ(expected_result, naiveSetIntersection(first, second, third));
}

TEST_F(LowIntersection, onePassSetIntersection) {
    ASSERT_EQ(expected_result, onePassSetIntersection(first, second, third));
}

TEST_F(LowIntersection, partioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(LowIntersection, partioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(LowIntersection, partioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(LowIntersection, partioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(LowIntersection, valuePartioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(LowIntersection, valuePartioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(LowIntersection, valuePartioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(LowIntersection, valuePartioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersectionSumResult_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 1));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersectionSumResult_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 2));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersectionSumResult_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 4));
}

TEST_F(LowIntersection, onePassMultiThreadSetIntersectionSumResult_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 8));
}

class HighIntersection : public testing::Test {
public:
    static void SetUpTestSuite() {
    	first.clear();
    	second.clear();
    	third.clear();
    	expected_result.clear();
		for (int var = 0; var < setMaxValue; var += 3) {
			first.insert(var);
		}

		for (int var = 0; var < setMaxValue; var += 3) {
			second.insert(var);
		}

		for (int var = 0; var < setMaxValue; var += 3) {
			third.insert(var);
		}
		for (int var = 0; var < setMaxValue; var += 3) {
			expected_result.insert(var);
		}
	}
};

TEST_F(HighIntersection, naiveSetIntersection) {
    ASSERT_EQ(expected_result, naiveSetIntersection(first, second, third));
}

TEST_F(HighIntersection, onePassSetIntersection) {
    ASSERT_EQ(expected_result, onePassSetIntersection(first, second, third));
}


TEST_F(HighIntersection, partioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(HighIntersection, partioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(HighIntersection, partioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(HighIntersection, partioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, partioningMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(HighIntersection, valuePartioningMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(HighIntersection, valuePartioningMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(HighIntersection, valuePartioningMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(HighIntersection, valuePartioningMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 8));
}


TEST_F(HighIntersection, onePassMultiThreadSetIntersection_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 1));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersection_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 2));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersection_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 4));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersection_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersection(first, second, third, 8));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersectionSumResult_1_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 1));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersectionSumResult_2_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 2));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersectionSumResult_4_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 4));
}

TEST_F(HighIntersection, onePassMultiThreadSetIntersectionSumResult_8_th) {
    ASSERT_EQ(expected_result, onePassMultiThreadSetIntersectionSumResult(first, second, third, 8));
}

class HugeIntersectionCommon : public testing::Test {
public:
    static void SetUpTestSuite() {
    	first.clear();
    	second.clear();
    	third.clear();
    	expected_result.clear();

		for (int var = 0; var < 5000000; var += 3) {
			first.insert(var);
		}

		for (int var = 0; var < 5000000; var += 5) {
			second.insert(var);
		}

		for (int var = 0; var < 5000000; var += 7) {
			third.insert(var);
		}

		for (int var = 0; var < 5000000; var += 7 * 5 * 3) {
			expected_result.insert(var);
		}

		std::cout << "set up finished" << std::endl;
	}
};

//TEST_F(HugeIntersectionCommon, valuePartioningMultiThreadSetIntersection_8_th) {
//	for (int i = 0; i < 100; ++i) {
//		ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 8));
//	}
//}

class HugeIntersectionLow : public testing::Test {
public:
    static void SetUpTestSuite() {
    	first.clear();
    	second.clear();
    	third.clear();
    	expected_result.clear();

		for (int var = 0; var < 5000000; var += 3) {
			first.insert(var);
		}

		for (int var = 0; var < 5000000; var += 5) {
			second.insert(var);
		}

		for (int var = 0; var < 5000000; var += 7) {
			third.insert(var);
		}

		for (int var = 0; var < 5000000; var += 3 * 5 * 7) {
			expected_result.insert(var);
		}

		std::cout << "set up finished" << std::endl;
	}
};

//TEST_F(HugeIntersectionLow, valuePartioningMultiThreadSetIntersection_8_th) {
//	for (int i = 0; i < 100; ++i) {
//		ASSERT_EQ(expected_result, valuePartioningMultiThreadSetIntersection(first, second, third, 8));
//	}
//}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




