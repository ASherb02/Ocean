#ifndef RandomDefined
#define RandomDefined

class Random
{
private:
	int seed1, seed2;

public:
	//�������������
	void initialize(void)
	{
		seed1 = 3797;
		seed2 = 2117;
	}

	void init(int s1, int s2)
	{
		seed1 = s1;
		seed2 = s2;

	}

	//������ �������
	float randReal(void);
	int NextBetween(int low, int high);
};
#endif // !RandomDefined
