#ifndef SET_H
#define SET_H

class Set {
public:
	Set(const int newSize);
	inline bool* getData() const { return data; };
	void insert(const int element);
	void remove(const int element);
	bool isFull() const;
	void clear();
private:
	bool * data;
	int maximumSize;
};

#endif
