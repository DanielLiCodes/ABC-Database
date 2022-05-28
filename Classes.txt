class Database {
    private:
        String name;
}

class ArrayDatabase : public Database {
    private: 
        ArrayNode array[];
}


class LinkedListDatabase : public Database {
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
}

class HashTable : public Database {
    private:
        HashTableNode array[]; // lose
}


class DatabaseManager {
    private:
        Database databases[];
        int databaseSize;
}

class ArrayNode : public NodeStrategy {
    private:
        Node data;
        int index; //
}


class LinkedListNode : public NodeStrategy {
    private:
        LinkedListNode next; //
        LinkedListNode prev; //
        Node data;
}
