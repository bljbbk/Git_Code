#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <stdio.h>

void func();
int main(int argc, char const *argv[])
{
	boost::thread t(boost::bind(func));
	t.join();
	printf("done\n");
	return 0;
}

void func()
{
	printf("hello world\n");
}
