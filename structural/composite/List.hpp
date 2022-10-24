#ifndef LIST_HPP
#define LIST_HPP

template <class T>
struct List
{

	List(int initSize)
		: buffer(nullptr),
		  cnt(0),
		  totalSize(0)
	{
		resize(initSize);
	}

	~List() { delete[] buffer; }

	void add(T t)
	{
		if (cnt == totalSize)
			resize(totalSize * 2);

		buffer[cnt++] = t;
	}

	int size() { return cnt; }

	T get(int index) { return buffer[index]; }

	T *begin() { return buffer; }

	T *end() { return &buffer[cnt]; }

private:
	T *buffer;
	int cnt;
	int totalSize;

	void resize(int newSize)
	{
		T *temp = new T[newSize];

		if (buffer)
		{
			for (int i = 0; i < cnt; i++)
				temp[i] = buffer[i];

			delete[] buffer;
		}

		buffer = temp;
		totalSize = newSize;
	}
};

#endif // !LIST_HPP
