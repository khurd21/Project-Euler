'''
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over
five-thousand first names, begin by sorting it into alphabetical order. Then working out
the alphabetical value for each name, multiply this value by its alphabetical position in
the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain
a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
'''

OFFSET = 64

def get_names(filename):
    with open(filename) as f:
        names = f.readline()
        names = [x[1:-1] for x in names.split(',')]
    return names


def get_score(name):
    score = 0
    for c in name:
        score += ord(c) - OFFSET
    return score


def main():
    names = sorted(get_names('22.txt'))

    sum = 0
    for itr, name in enumerate(names):
        sum += get_score(name) * (itr + 1)
    print(sum)


if __name__ == '__main__':
    main()