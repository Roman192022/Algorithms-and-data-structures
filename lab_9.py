import logging

logging.basicConfig(level=logging.DEBUG)
logging.debug('This is a debug message!')

logging.info('Admin logged in')

class Node:
    
    def __init__(self, key = None, value = None):
        
        self.key = key
        self.value = value

class Hashtable:
    
    def __init__(self, size, colliz = 0):
        self.colliz = colliz
        self.size = size
        self.data = [Node() for _ in range(size)]
        

    def hash_func(self, key):
        return (key + 2003) % 11
        

    def put(self, key, value):
        hash_index = self.hash_func(key)
        if hash_index >= self.size:
            raise Exception('full table')

        if self.data[hash_index] and self.data[hash_index].value == None:        
            self.data[hash_index].key = key
            self.data[hash_index].value = value
            return
        
        for i in range(hash_index + 1, self.size):
            self.colliz += 1
            if self.data[i] and self.data[i].value == None:          
                self.data[i].key = key
                self.data[i].value = value
                return
            
        for i in range(0, hash_index):
            self.colliz += 1
            if self.data[i] and self.data[i].value == None:           
                self.data[i].key = key
                self.data[i].value = value
                return

    

n = 12

hash_table = Hashtable(n)
hash_list = ["tree", "snow", "sun", "wind", "spring", "winter",
        "summer", "autumn", "blue", "green", "yellow", "black"]

i = 0      
for item in hash_list:
    hash_table.put(i, item)
    i += 1

print("Hash table:")
for i in range(n):
    print(hash_table.data[i].key, "-----", hash_table.data[i].value)
          
print("Number of collisions: ", hash_table.colliz)
                     
logging.info('Admin logged out')          
