#ifndef SET_H
#define SET_H

class Set {
public:
	Set(const int newSize);
	inline bool* getData() const { return data; };
	void insert(const int element);
	int getFree();
	int GetFirstFree();
private:
	bool * data;
	int maximumSize;
};

#endif
