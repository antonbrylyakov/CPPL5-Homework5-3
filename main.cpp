#include <iostream>
#include <list>
#include <algorithm>

class WholeDiv3Counter
{
public:
	WholeDiv3Counter()
	{

	}

	void operator()(int v)
	{
		if (v % 3 == 0)
		{
			++m_count;
			m_sum += v;
		}
	}

	size_t getCount()
	{
		return m_count;
	}

	int getSum()
	{
		return m_sum;
	}

private:
	size_t m_count = 0;
	int m_sum = 0;
};

int main()
{
	std::list l{ 4, 1, 3, 6, 25, 54 };
	std::cout << "[IN]: ";
	std::for_each(l.begin(), l.end(), [](auto& v) { std::cout << v << " "; });
	std::cout << std::endl;
	auto counter = std::for_each(l.begin(), l.end(), WholeDiv3Counter());
	std::cout << "[OUT]: getSum() = " << counter.getSum() << std::endl;
	std::cout << "[OUT]: getCount() = " << counter.getCount() << std::endl;
}