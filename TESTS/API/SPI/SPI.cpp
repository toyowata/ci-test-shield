// Waiting for public release to enable, currently there are problems with the SD driver
#include "mbed.h"
#include "greentea-client/test_env.h"
#include "unity.h"
#include "utest.h"
#include "rtos.h"
// #include "SDFileSystem.h"

 using namespace utest::v1;

// SDFileSystem sd(D11, D12, D13, D10, "sd"); // the pinout on the mbed Cool Components workshop board

// // Test SPI via the SD File System
// void test_sd_write(){
//     mkdir("/sd/mydir", 0777);
//     FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
//     TEST_ASSERT(fp != NULL);
//     // if(fp == NULL) {
//     //     error("Could not open file for write\n");
//     // }
//     fprintf(fp, "Hello fun SD Card World!"); // TODO: add random number here to validate in next test
//     fclose(fp);
// }

void test_sd_write(){
	// Currently no SD Test written, waiting for public release to enable
	TEST_ASSERT_MESSAGE(false,"SD Tests are not supported yet, this is a placeholder for future tests.");
}

utest::v1::status_t test_setup(const size_t number_of_cases) {
    // Setup Greentea using a reasonable timeout in seconds
    GREENTEA_SETUP(40, "default_auto");
    return verbose_test_setup_handler(number_of_cases);
}

// Handle test failures, keep testing, dont stop
utest::v1::status_t greentea_failure_handler(const Case *const source, const failure_t reason) {
    greentea_case_failure_abort_handler(source, reason);
    return STATUS_CONTINUE;
}

// Test cases
 Case cases[] = {
     Case("Testing SPI via SD Write", test_sd_write,greentea_failure_handler),
 };

 Specification specification(test_setup, cases);

// // Entry point into the tests
int main() {
    return !Harness::run(specification);
}