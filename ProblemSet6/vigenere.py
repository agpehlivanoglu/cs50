from cs50 import get_string
import sys


def main():
    # if argument count does not equal 2 or characters are not alphabetic, exit
    if len(sys.argv) != 2:
        print("Usage: ./vigenere keyword")
        exit(1)
    if sys.argv[1].isalpha() == False:
        print("Usage: ./vigenere keyword")
        exit(1)

    numkey = len(sys.argv[1])  # gets the total number of characters in argument
    # creating an array to store all of the character numbers
    key = []
    for i in sys.argv[1]:
        if i.isupper():
            k = ((ord(i) - ord("A")) % 26)
            key.append(k)
        elif i.islower():
            k = ((ord(i) - ord("a")) % 26)
            key.append(k)

    intext = get_string("plaintext: ")  # get plaintext from user to encrypt
    print("ciphertext: ", end="")
    j = 0

    for i in intext:  # using just one loop, but keeping track of j myself
        if j >= numkey:
            j = 0
            # If the length of the keyword is, say, 4 characters, then the last character of that keyword can be found at keyword[3]. Then, for the next character you encipher, you’ll want to use keyword[0].

        if i.isalpha() == False:  # to not changing the punctuation marks or empty spaces
            print(i, end="")
            continue
        elif i.isupper():  # to keep uppercase letters remain uppercase.
            newletter = (((ord(i) + int(key[j])) - ord("A")) % 26) + ord("A")
            print(chr(newletter), end="")
            j += 1
        elif i.islower():  # to keep lowercase letters remain lowercase.
            newletter = (((ord(i) + int(key[j])) - ord("a")) % 26) + ord("a")
            print(chr(newletter), end="")
            j += 1

    print()


if __name__ == "__main__":
    main()