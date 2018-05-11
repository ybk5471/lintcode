#include <iostream>
#include <string>
using namespace std;

/**
 * No.1
 * 给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符。
 * @note:a和b都是 32位 整数;可以使用位运算符;
 */
int lintcode_001(int a, int b) {
	int sum = 0;
	int carry = 0;
	while (b !=0) {
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}
	return a;
}

/**
 * 设计一个算法，计算出n阶乘中尾部零的个数
 * O(logN)的时间复杂度
 */
long lintcode_002(long n) {
	long zeros = 0;
	while (n > 0) {
		n /= 5;
		zeros += n;
	}
	return zeros;
}

/**
 * No.3
 * 计算数字k在0到n中的出现的次数，k可能是0~9的一个值
 * 例如n=12，k=1，在 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，我们发现1出现了5次 (1, 10, 11, 12)
 */
int lintcode_003(int n, int k) {
	int sum = 0;
	int degree = 1;
	while (k * gegree * 10 < n) {
		sum += degree * 10;
		++degree;
	}
	return sum;
}

/**
 * No.8
 * 给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)
 * 对于字符串 "abcdefg"
 * offset=0 => "abcdefg"
 * offset=1 => "gabcdef"
 * offset=2 => "fgabcde"
 * offset=3 => "efgabcd"
 */
void lintcode_008(string & str, int offset) {
	if (0 == str.size()) {
		return;
	}
	int start = 0, i = 0, n = 0, size = str.size();
	int aoffset = offset % size;
	char tmp;
	while (n < size) {
		++n;
		i = (i + aoffset) % size;
		if (i == start) {
			++start;
			i = start;
		} else {
			tmp = str[i];
			str[i] = str[start];
			str[start] = tmp;
		}
	}
}


int main() {
	std::cout << lintcode_001(77, 7) << std::endl;
	return 0;
}
