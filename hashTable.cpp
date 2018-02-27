

class HashEntry {

private:

  int key;

  int value;

public:

  HashEntry(int key, int value) {

    this->key = key;

    this->value = value;

  }

 

  int getKey() {

    return key;

  }

 

  int getValue() {

    return value;

  }

};

const int TABLE_SIZE = 128;

class HashMap {

private:
  HashEntry **table;

public:
      HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
          table[i] = nullptr;
      }

      int get(int key) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
          hash = (hash + 1) % TABLE_SIZE;
          if (table[hash] == nullptr)
            return -1;
          else
            return table[hash]->getValue();
      }

      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);

            while (table[hash] != nullptr && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] != nullptr)
                  delete table[hash];
            table[hash] = new HashEntry(key, value);

      }

      ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
          if (table[i] != nullptr)
            delete table[i];

        delete[] table;
      }

};
