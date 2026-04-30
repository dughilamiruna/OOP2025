#pragma once
#include <cstring>

template<class K, class V>

class Map
{

	struct item
	{
		K key;
		V value;
	};

	item* el;
	int size, capacity;
	
	void resize()
	{
		capacity = capacity * 2;
		item* new_el = new item[capacity];

		for (int i = 0; i < size; i++)
		{
			new_el[i] = el[i];
		}

		delete[] el;
		el = new_el;
	}

	int find_index(const K& key) const
	{
		for (int i = 0; i < size; i++)
		{
			if (el[i].key == key)
			{
				return i;
			}
		}
		return -1;
	}

public:

	Map()
	{
		capacity = 16;
		size = 0;
		el = new item[capacity];
	}

	~Map()
	{
		delete[] el;
	}

	V& operator[](const K& key)
	{
		int index = find_index(key);
		if (index != -1)
		{
			return el[index].value;
		}

		if (size == capacity) resize();
		el[size].key = key;
		return el[size++].value;
	}

	void Set(const K& key, const V& value)
	{
		int index = find_index(key);
		if (index != -1)
		{
			el[index].value = value;
		}
		else
		{
			if (size == capacity)
				resize();
			el[size].key = key;
			el[size].value = value;
			size++;
		}
	}

	bool Get(const K& key, V& value) const
	{
		int index = find_index(key);
		if (index != -1)
		{
			value=el[index].value;
			return true;
		}
		return false;
	}

	int Count() const
	{
		return size;
	}
	void Clear()
	{
		delete[] el;
		capacity = 16;
		size = 0;
		el = new item[capacity];
	}

	bool Delete(const K& key)
	{
		int index = find_index(key);
		if (index != -1)
		{
			return false;
		}

		for (int i = index; i < size - 1; i++)
		{
			el[i] = el[i + 1];
		}
		size--; return true;
	}

	bool Includes(const Map<K, V>& other)
	{
		for (int i = 0; i < other.size; i++)
		{
			if (find_index(other.el[i].key) == -1)
			{
				return false;
			}
		}
		return true;
	}

	struct item_index
		{
			K& key;
			V& value;
			int index;
		};

	struct Iterator
		{
			Map& map;
			int index;

			Iterator(Map& m, int i) : map(m), index(i) {}

			bool operator!=(const Iterator& other) const
			{
				return index != other.index;
			}

			void operator++()
			{
				index++;
			}

			item_index operator*() const
			{
				return item_index{ map.el[index].key, map.el[index].value, index };
			}
		};

	Iterator begin()
		{
			return Iterator(*this, 0);
		}
	Iterator end()
		{
			return Iterator(*this, size);
		}
};