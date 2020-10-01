# Luhn’un Algoritması, CS50

from cs50 import get_int, get_string

def main():
    credit = get_int("Number: ")
    credit = str(credit)
    nDigits = len(credit) #  Basamak sayısını buluyoruz
    sum = 0

# sondan ikinci rakamdan başlayıp ikişer ikişer rakamları belirlemek ve toplamak için
    for d in range(nDigits, 1, -2):
        x = credit[d-2]
        y = int(x) * 2

        if y >= 10:
            y = 1 + (y % 10)

        sum += y

# sonuncu rakamdan başlayıp ikişer ikişer rakamları belirlemek ve toplamak için
    for d in range(nDigits, 0, -2):
        x = int(credit[d-1])
        y = int(x)
        sum += y

# Geçerli - Geçersiz olmasını ve Hangi şirketin kartı olduğunu belirlemek için
    if (sum % 10) == 0:

        if nDigits < 15 or nDigits > 16:
            print("INVALID")

        if nDigits == 15:
            if credit[0] == "3" and credit[1] == "4":
                print("AMEX")
            elif credit[0] == "3" and credit[1] == "7":
                print("AMEX")
            else:
                print("INVALID")

        if nDigits == 16:
            if credit[0] == "4":
                print("VISA")
            else:
                if credit[0] == "5":
                    if credit[1] == "1" or credit[1] == "2" or credit[1] == "3" or credit[1] == "4" or credit[1] == "5":
                        print("MASTERCARD")
                    else:
                        print("INVALID")

                else:
                    print("INVALID")

    else:
        print("INVALID")


if __name__ == "__main__":
    main()