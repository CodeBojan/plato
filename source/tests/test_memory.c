#include "unity/unity.h"
#include "types.h"
#include "memory.h"

BUFFER* test_buffer = NULL;

void setUp(){

}

void tearDown(){

}

void test_callocate(){
    BUFFER buffer;
    TEST_ASSERT_EQUAL(1, callocate(&buffer, 10));
    TEST_ASSERT_EQUAL(10, buffer._size);
}

void test_mallocate(){
    BUFFER buffer;
    TEST_ASSERT_EQUAL(1, mallocate(&buffer, 10));
    TEST_ASSERT_EQUAL(10, buffer._size);
}

void test_reallocate(){
    BUFFER buffer;
    mallocate(&buffer, 5);
    TEST_ASSERT_EQUAL(1, reallocate(&buffer, 10));
    TEST_ASSERT_NOT_EQUAL(5, buffer._size);
    TEST_ASSERT_EQUAL(10, buffer._size);
}

int main(void){
    UNITY_BEGIN();
    
    RUN_TEST(test_callocate);
    RUN_TEST(test_mallocate);
    RUN_TEST(test_reallocate);

    return UNITY_END();
}