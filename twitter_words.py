class TrieNode:
    def __init__(self,label = None, data = None):
        self.children = dict()
        self.entry = data
        self.isEndOfWord = False

    def __getitem__(self,key):
        return self.children[ord(key) - ord('a')]

class Trie:
    def __init__(self):
        self.root = self.getNode(None)

    def getNode(self, data):
        return TrieNode(data)

    def _charToIndex(self,ch):
        #Concerts key current character into the index
        #use only 'a' through 'z' and lower case
        return ord(ch)-ord('a')

    def insert(self,key):
         
        # If not present, inserts key into trie
        # If the key is prefix of trie node, 
        # just marks leaf node
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self._charToIndex(key[level])
            
            # if current character is not present
            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode(key[level])
            pCrawl = pCrawl.children[index]
 
        # mark last node as leaf
        pCrawl.isEndOfWord = True

    def search(self, prefix):
        words = list()

        if prefix == None:
            raise ValueError('require a non Null prefix')

        top_node = self.root

        for letter in prefix:
            if letter in top_node.children:
                top_node = top_node.children[self._charToIndex(letter)]
            else:
                return words

        if top_node == self.root:
            queue = [key for key in top_node.children]
        else:
            queue = [top_node]

        while queue:
            current_node = queue.pop()
            if current_node.entry != None:
                #words.append(current_node.entry)
                queue = [key for key in current_node.children] + queue

        return words

def main():
    t = Trie()
    dict = ['super', 'hello', 'sun', 'sappy', 'sunrise', 'poop', 'shit']

    for word in dict:
        t.insert(word)

    print(t.search('s'))


main()
