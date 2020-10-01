import sys
import csv


def main():

    # if argument count does not equal 3, exit
    if len(sys.argv) != 3:
        print("Usage: incorrect number of command-line arguments")
        exit(1)

    # opening and reading .csv file
    data = open(sys.argv[1], "r")
    csv_file = csv.reader(data)
    row1 = next(csv_file)  # pulling first row
    row1.pop(0)  # getting rid of "name"

    # opening and reading txt file
    data2 = open(sys.argv[2], "r")
    DNA = data2.read().replace('\n', '')

    li = []
    Genomemax = 0

    for j in range(len(row1)):   # to loop all STR at first row
        li.append(str(Genomemax))  # adding number of longest run of consecutive repeats
        Genomemax = 0
        temp = 0
        for i in range(0, len(DNA)):
            if row1[j] == DNA[i: i+len(row1[j])]:
                temp += 1
                if row1[j] != DNA[i+len(row1[j]): i+len(row1[j])+len(row1[j])]:  # #if the next sequence isn't matching, reset counter of repeated substring
                    # checks if previous amount of repeated sequence is bigger, if not assigns maxDna to largest amount of repeating sequence
                    if temp > Genomemax:
                        Genomemax = temp
                    temp = 0
    li.append(str(Genomemax))

    # opening and reading .csv file again because we read the entire file the first time we iterated, so there is nothing left to read the second time.
    data = open(sys.argv[1], "r")
    csv_file = csv.reader(data)
    next(csv_file)

    # comparing the person's STR number with the consecutive repeats
    for row in csv_file:
        same = 0
        for i in range(1, len(li)):
            if row[i] == li[i]:
                same += 1
        if same == len(li) - 1:
            print(row[0])
            exit(0)

    print("No match")


if __name__ == "__main__":
    main()