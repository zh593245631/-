class Solution {
public:
	void oddInOddEvenInEven(std::vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i < len && j < len) {
			if ((arr[i] % 2) == 0) { i += 2; continue; }//ż��λ��Ѱ�ҷ�ż��
			if ((arr[j] % 2) != 0) { j += 2; continue; }//����λ��Ѱ�ҷ�����
			swap(arr[i], arr[j]);
		}
	}
};