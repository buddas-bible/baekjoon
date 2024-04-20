#include <iostream>
#include <coroutine>

class Task
{
public:
	// 규칙 1. C++에서 정의된 규칙을 구현한 promise_type 이라는 이름의 타입이 정의되어야 한다.
	struct promise_type
	{
		std::exception_ptr exception_;

		// 사용자 정의 "코루틴 반환 객체"를 반환 한다
		Task get_return_object()
		{
			return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };
		}

		// 코루틴 최초 실행 시 호출. awaitable 객체를 반환 한다.
		std::suspend_always initial_suspend() { return {}; }

		// 코루틴 종료 시 호출. 나중에 코루틴 종료를 설명 할 때 같이 설명
		std::suspend_always final_suspend() noexcept { return {}; }

		// co_return을 사용하는 경우 구현. 나중에 코루틴 종료를 설명 할 때 같이 설명
		void return_void() noexcept { }

		// 코루틴 수행 중 예외 발생 시 호출
		void unhandled_exception() { exception_ = std::current_exception(); /* std::exit(1); */ }
	};

	// 규칙 2. std::coroutine_handle<promise_type> 타입의 멤버 변수가 있어야 한다.
	std::coroutine_handle<promise_type> co_handler;

	// 규칙 3. std::coroutine_handle<promise_type> 을 인자로 받아
	// 멤버 변수를 초기화 하는 생성자가 있어야 한다.
	Task(std::coroutine_handle<promise_type> handler) : co_handler(handler) { }

	// 규칙 4. 소멸자에서 std::coroutine_handle<promise_type> 타입의
	// 코루틴 핸들러 멤버 변수의 destroy를 호출 해야 한다.
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


// 코루틴 함수 만들기
//     규칙 1. co_await를 사용한다
//     규칙 2. 코루틴 반환 객체(Task)를 리턴한다
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