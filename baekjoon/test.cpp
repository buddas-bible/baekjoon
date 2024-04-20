#include <iostream>
#include <coroutine>

class Task
{
public:
	// ��Ģ 1. C++���� ���ǵ� ��Ģ�� ������ promise_type �̶�� �̸��� Ÿ���� ���ǵǾ�� �Ѵ�.
	struct promise_type
	{
		std::exception_ptr exception_;

		// ����� ���� "�ڷ�ƾ ��ȯ ��ü"�� ��ȯ �Ѵ�
		Task get_return_object()
		{
			return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };
		}

		// �ڷ�ƾ ���� ���� �� ȣ��. awaitable ��ü�� ��ȯ �Ѵ�.
		std::suspend_always initial_suspend() { return {}; }

		// �ڷ�ƾ ���� �� ȣ��. ���߿� �ڷ�ƾ ���Ḧ ���� �� �� ���� ����
		std::suspend_always final_suspend() noexcept { return {}; }

		// co_return�� ����ϴ� ��� ����. ���߿� �ڷ�ƾ ���Ḧ ���� �� �� ���� ����
		void return_void() noexcept { }

		// �ڷ�ƾ ���� �� ���� �߻� �� ȣ��
		void unhandled_exception() { exception_ = std::current_exception(); /* std::exit(1); */ }
	};

	// ��Ģ 2. std::coroutine_handle<promise_type> Ÿ���� ��� ������ �־�� �Ѵ�.
	std::coroutine_handle<promise_type> co_handler;

	// ��Ģ 3. std::coroutine_handle<promise_type> �� ���ڷ� �޾�
	// ��� ������ �ʱ�ȭ �ϴ� �����ڰ� �־�� �Ѵ�.
	Task(std::coroutine_handle<promise_type> handler) : co_handler(handler) { }

	// ��Ģ 4. �Ҹ��ڿ��� std::coroutine_handle<promise_type> Ÿ����
	// �ڷ�ƾ �ڵ鷯 ��� ������ destroy�� ȣ�� �ؾ� �Ѵ�.
	~Task()
	{
		if (true == (bool)co_handler)
		{
			co_handler.destroy();
		}
	}

	bool done() { return co_handler.done(); }
	void operator()() 
	{
		co_handler();
		if (co_handler.promise().exception_)
			std::rethrow_exception(co_handler.promise().exception_);
	}
};

Task cotask_func_a()
{
	std::cout << "cotask_func_a 01" << std::endl;
	co_await std::suspend_always();
	std::cout << "cotask_func_a 02" << std::endl;
}

Task cotask_func_b()
{
	std::cout << "cotask_func_b 01" << std::endl;
	co_await std::suspend_always();
	std::cout << "cotask_func_b 02" << std::endl;
}


// �ڷ�ƾ �Լ� �����
//     ��Ģ 1. co_await�� ����Ѵ�
//     ��Ģ 2. �ڷ�ƾ ��ȯ ��ü(Task)�� �����Ѵ�
Task foo()
{
	std::cout << "foo 1" << std::endl;
	co_await std::suspend_always{};
	std::cout << "foo 2" << std::endl;
}

int main()
{
	Task cotask0 = cotask_func_a();
	Task cotask1 = cotask_func_b();

	while (!cotask0.done() || !cotask1.done())
	{
		if (!cotask0.done())
		{
			cotask0();
		}

		if (!cotask1.done())
		{
			cotask1();
		}
	}

	Task tast = foo();

	while (!tast.done())
	{
		std::cout << "main 1" << std::endl;
		tast();
		std::cout << "main 2" << std::endl;
		tast();
	}

	return 0;

}