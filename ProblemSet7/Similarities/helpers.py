from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    samelist = []
    str1 = set(a.splitlines())
    str2 = set(b.splitlines())

    return list(str1 & str2)


def sentences(a, b):
    """Return sentences in both a and b"""

    str1 = set(sent_tokenize(a))
    str2 = set(sent_tokenize(b))

    return list(str1 & str2)


def slicer(ruler, n):

    if len(ruler) < n:
        return []

    record = []
    for i in range(len(ruler)):
        record.append(ruler[i:i+n])
        if i+n == len(ruler):
            break

    return record


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    str1 = set(slicer(a, n))
    str2 = set(slicer(b, n))

    return list(str1 & str2)



