from cs50 import get_string
import sys

def main():
    # if argument count does not equal 2, exit
    if len(sys.argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    # This returns a list of each line in the file.
    banWords = open(sys.argv[1]).read().splitlines() # Every line comes with its end of line characters (\n\r); this way the characters are removed
    # print(banWords)

    # getting a message from user
    print("What message would you like to censor?")
    text = get_string("")
    # transfer the message strings to a list
    words = text.split()

    for i in banWords:
        counter = -1   # counter variable provides us keeping track of which word we change
        for j in words:
            counter += 1
            if i == j.lower():
                for k in j:
                    j = j.replace(k, "*")
                    words[counter] = j

    # The join() method takes all items in an iterable and joins them into one string.
    newSentence = " ".join(words)
    print(newSentence)

if __name__ == "__main__":
    main()

