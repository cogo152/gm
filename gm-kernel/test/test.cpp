#include <gctest/core/test.hpp>

class ExceptionalTest final
{
public:
    constexpr void throwTestMethod(int first, int second, int result)
    {
        if (!(first + second == result))
        {
            throw 1;
        }
    }

    constexpr static void throwTestClassFunction(int first, int second, int result)
    {
        if (!(first + second == result))
        {
            throw 1;
        }
    }
};

constexpr inline void throwTestFreeFunction(int first, int second, int result)
{
    if (!(first + second == result))
    {
        throw 1;
    }
}

ExceptionalTest exceptionalTest;

GCTEST_CASE(assertions_success)
{
    gctest_case_config_default(assertions_success);
    gctest_case_description("testing assertions");
    gctest_case_requirement("gctest should success all valid assertions");

    gctest_case_now
    {
        assert_true(true);

        assert_false(false);

        assert_equal(1.0, 1.0);

        assert_not_equal(1.0, 2.0);

        assert_greater(2, 1);

        assert_greater_or_equal(2, 1);
        assert_greater_or_equal(2, 2);

        assert_lesser(1, 2);

        assert_lesser_or_equal(1, 2);
        assert_lesser_or_equal(2, 2);

        assert_function_throws(ExceptionalTest::throwTestClassFunction, 1, 1, 3);
        assert_function_throws(&throwTestFreeFunction, 1, 1, 3);

        assert_function_not_throws(ExceptionalTest::throwTestClassFunction, 1, 1, 2);
        assert_function_not_throws(&throwTestFreeFunction, 1, 1, 2);

        assert_method_throws(&exceptionalTest, &ExceptionalTest::throwTestMethod, 1, 1, 3);
        assert_method_not_throws(&exceptionalTest, &ExceptionalTest::throwTestMethod, 1, 1, 2);

        assert_null(nullptr);

        int *ptr = new int;
        assert_not_null(ptr);
        delete ptr;
    }
};
