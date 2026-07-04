#include "Ch1.h"



std::string Add(std::string str1, std::string str2)
{
	std::string result;

	int N = str1.size() > str2.size() ? str1.size() : str2.size();

	if (str1.size() < N)
	{
		str1.insert(0, N - str1.size(), '0');
	}

	if (str2.size() < N)
	{
		str2.insert(0, N - str2.size(), '0');
	}

	int carry = 0;

	for (int t = N - 1; t >= 0; t--)
	{
		int r = (str1[t] - '0') + (str2[t] - '0') + carry;

		std::string temp = std::to_string(r);

		if (temp.size() == 2)
		{
			carry = temp[0] - '0';

			result.insert(0, 1, temp[1]);
		}
		else
		{
			carry = 0;

			result.insert(0, 1, temp[0]);
		}
	}
	
	if (carry != 0)
	{
		result.insert(0, 1, char(carry + '0'));
	}

	return result;
}

//{
//    // An edge case (별도로 처리해야 하는 특별한 경우)
//    // [안내] 코테 연습에서는 edge case도 꼼꼼하게 따져봐야 합니다.
//    //        여기서는 알고리듬에 집중하기 위해 최소한으로만 고려하겠습니다.
//    if (!str1.size() && !str2.size())
//        return "0"; // '0'은 char, "0"은 string
//
//    // 구현을 편하게 하기 위해서 두 숫자의 자리수를 맞춰줍니다.
//    // 더 짧은 쪽의 높은 자리에 0으로 채워줍니다.
//    // str1 = "1234", str2 = "56"인 경우 str2를 "0056"으로 변경
//    int N = max(str1.size(), str2.size());
//    str1.insert(0, string(N - str1.size(), '0'));
//    str2.insert(0, string(N - str2.size(), '0'));
//
//    string result(N, '0'); // 정답을 만들어서 저장해나갈 공간
//
//    int carry = 0; // 더한 결과가 10보다 클 경우 다음 자리로 넘겨줄 숫자
//    for (int i = N - 1; i >= 0; i--) // 역순 주의
//    {
//        int n1 = str1[i] - '0'; // 문자를 정수로 변환
//        int n2 = str2[i] - '0';
//
//        int sum = n1 + n2 + carry;
//        carry = sum / 10; // 다음 자리로 넘길 숫자 업데이트 
//
//        result[i] = char(sum % 10 + '0'); // 결과 저장        
//        // 디버깅용 출력
//        cout << n1 << " " << n2 << " " << carry << " " << result << endl;
//    }
//
//    // 모든 자리를 다 더한 후에는 carry만 가장 높은 자리에 추가
//    if (carry > 0)
//        result.insert(0, string(1, carry + '0'));
//
//    return result;
//}