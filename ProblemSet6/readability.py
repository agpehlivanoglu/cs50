from cs50 import get_string

def main():
    text = get_string("Text: ")
    letter, spaces, sentences = 0, 0, 0

    for i in text:
        if i.isalpha():
            letter += 1
        elif i.isspace():
            spaces += 1
        elif ord(i) == 46 or ord(i) == 33 or ord(i) == 63:
            sentences += 1

    words = spaces + 1
    L = (letter * 100) / words
    S = (sentences * 100) / words
    index = (0.0588 * L) - (0.296 * S) - 15.8
    index = round(index)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade", index)

if __name__ == "__main__":
    main()