#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using std::thread;

void runner(std::future<void>* start) {
	start->get();
	start->get();
	std::cout << "���!" << std::endl;
}

int main() {
	std::promise<void> p;
	std::future<void> start = p.get_future();

	thread t1(runner, &start);
	thread t2(runner, &start);
	thread t3(runner, &start);
	thread t4(runner, &start);

	// ����� cerr �� std::cout ���� �ٸ��� ���۸� ������� �ʱ� ������ �͹̳ο� �ٷ� ��µȴ�.
	std::cerr << "�غ�...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "��!" << std::endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}