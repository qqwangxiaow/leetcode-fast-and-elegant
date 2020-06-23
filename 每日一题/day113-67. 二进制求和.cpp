class Solution {
public:
	string addBinary(string a, string b) 
	{
		int asize = a.size(), bsize = b.size();
		while (asize > bsize)//补齐
		{
			b = '0' + b;
			bsize++;
		}
		while (asize < bsize)
		{
			a = '0' + a;
			asize++;
		}
		int carry = 0;  //进位
		for (int i = asize - 1; i >= 0; i--)
		{
			int sum = a[i] - '0' + b[i] - '0' + carry;
			a[i] = (sum) % 2+'0';//本位数值
			carry = sum / 2;//进位更新
		}
		if (carry > 0)//有溢出
			a = '1' + a;
		return a;
	}
};