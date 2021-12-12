def computeP(s):
    p = [0] * len(s)
    j, i = 0, 1

    while i < len(s):
        if s[j] == s[i]:
            j += 1
            p[i] = j
            i += 1
        else:
            if j == 0:
                p[i] = 0
                i += 1
            else:
                j = p[j - 1]
    
    return p

def kmp(pattern, text):
    p = computeP(pattern)
    pattern_sz = len(pattern)
    text_sz = len(text)
    i, j = 0, 0

    while i < text_sz:
        if text[i] == pattern[j]:
            i += 1
            j += 1
            if j == pattern_sz:
                return i - j
        else:
            if j > 0:
                j = p[j - 1]
            else:
                i += 1

    return None


if __name__ == "__main__":

    pattern = "tree"
    text = "I love AVL tries, ouch i meant trees!"

    print(kmp(pattern, text))
    



