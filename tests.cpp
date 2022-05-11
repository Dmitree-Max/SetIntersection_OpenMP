#include "set_intersection.cpp"

#include <array>
#include <gtest/gtest.h>

#define setMaxValue 5000000

#define test_with_all_threads(func)                                 									\
	TEST_F(CommonSetIntersection, func##_1_th) {                                                        \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 1));           \
	}                                                                                                   \
	TEST_F(CommonSetIntersection, func##_2_th) {                                                        \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 2));           \
	}                                                                                                   \
	TEST_F(CommonSetIntersection, func##_4_th) {                                                        \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 4));           \
	}                                                                                                   \
	TEST_F(CommonSetIntersection, func##_8_th) {                                                        \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 8));           \
	}                                                                                                   \
	TEST_F(LowIntersection, func##_1_th) {                                                              \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 1));           \
	}                                                                                                   \
	TEST_F(LowIntersection, func##_2_th) {                                                              \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 2));           \
	}                                                                                                   \
	TEST_F(LowIntersection, func##_4_th) {                                                              \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 4));           \
	}                                                                                                   \
	TEST_F(LowIntersection, func##_8_th) {                                                              \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 8));           \
	}                                                                                                   \
	TEST_F(HighIntersection, func##_1_th) {                                                             \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 1));           \
	}                                                                                                   \
	TEST_F(HighIntersection, func##_2_th) {                                                             \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 2));           \
	}                                                                                                   \
	TEST_F(HighIntersection, func##_4_th) {                                                             \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 4));           \
	}                                                                                                   \
	TEST_F(HighIntersection, func##_8_th) {                                                             \
		ASSERT_EQ(expected_result, naiveMultiThreadSetIntersection(first, second, third, 8));           \
	}

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


test_with_all_threads(naiveMultiThreadSetIntersection);
test_with_all_threads(partioningMultiThreadSetIntersection);
test_with_all_threads(valuePartioningMultiThreadSetIntersection);
test_with_all_threads(onePassMultiThreadSetIntersection);
test_with_all_threads(onePassMultiThreadSetIntersectionSumResult);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




