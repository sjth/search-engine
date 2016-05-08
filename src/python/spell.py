
class SpellCheck:
    def __init__(self):
        self.dictionary = {}
        self.common_mistakes = {}
        self.valid = {}

        print "Building Dictionary..."
        print "Generating 3-grams..."

        counter = 0

        f = open('dictionary.txt', 'r')
        for line in f:
            counter += 1
            word = line.strip().lower()
            self.valid[word] = 1
            if len(word) == 2:
                self.dictionary[word] = []
                self.dictionary[word].append(word)
            else:
                for x in xrange(len(word) - 2):
                    self.dictionary[word[x:x+3]] = []
                    self.dictionary[word[x:x+3]].append(word)

        if counter % 10000 == 0:
            print "."
        f.close()

        print "Completed!"
        print "Adding common spelling mistakes..."

        f = open('common.txt', 'r')
        for line in f:
            x = line.strip().lower().split(" ")
            self.common_mistakes[x[0]] = x[1]
        f.close()

        print "Completed!"
        print "All Set!"

    def edit_distance(self, word1, word2):
        table = [[0 for x in xrange(len(word1) + 1)] for y in xrange(len(word2) + 1)]
        for x in range(1, len(word1) + 1):
            table[x][0] = -x
        for x in range(1, len(word2) + 1):
            table[0][x] = -x
        for x in range(1, len(word1) + 1):
            for y in range(1, len(word2) + 1):
                table[x][y] = table[x - 1][y - 1] + (0 if word1[x - 1] == word2[y - 1] else -1)
                table[x][y] = max(table[x][y], table[x - 1][y] - 1)
                table[x][y] = max(table[x][y], table[x][y - 1] - 1)
        return table[len(word1)][len(word2)]

    def correct_spelling_small(self, word):
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        splits = [(word[:i], word[i:]) for i in range(len(word) + 1)]
        deletes = [a + b[1:] for a, b in splits if b]
        transposes = [a + b[1] + b[0] + b[2:] for a, b in splits if len(b)>1]
        replaces = [a + c + b[1:] for a, b in splits for c in alphabet if b]
        inserts = [a + c + b for a, b in splits for c in alphabet]
        all_words = set(deletes + transposes + replaces + inserts)
        result_set = set()
        for x in all_words:
            if self.valid[x] == 1:
                result_set.add(x)
        return result_set


#   def correct_spelling_large(self, word):
