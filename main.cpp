#include <iostream>
#include <iperf_api.h>

using namespace std;

int main(int, char **)
{
	struct iperf_test *test;
	test = iperf_new_test();

	iperf_defaults(test);
	iperf_set_test_role(test, 'c');
	iperf_set_test_server_hostname(test, "localhost");

	iperf_set_test_reverse(test, 1);
	iperf_set_test_bytes(test, 100 * 1024 * 1024);

	iperf_run_client(test);
	iperf_free_test(test);
}
