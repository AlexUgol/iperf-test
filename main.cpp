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
	iperf_set_test_bytes(test, 200 * 1024);
	//iperf_set_test_blksize(test, 10 * 1024);
	set_protocol(test, Psctp);

	int result = iperf_run_client(test);
	if (result < 0)
	{
		cout << iperf_strerror(i_errno) << endl;
		return EXIT_FAILURE;
	}

	iperf_free_test(test);
	return EXIT_SUCCESS;
}
