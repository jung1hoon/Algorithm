#include "Ch2.h"

void RomanToInt(std::string str)
{
	std::unordered_map<char, int> um{
	{'I', 1} ,{'V', 5}, {'X', 10},
	{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
	};

	int result = um[str[0]];

	for (int i = 1; i < str.length(); i++)
	{
		if (result >= um[str[i]])
		{
			result += um[str[i]];
		}
		else
		{
			result = um[str[i]] - result;
		}
	}
	
	std::cout << "Result Value : " << result << std::endl;
}

using Vertex = Graph<std::pair<int, char>>::Vertex;


