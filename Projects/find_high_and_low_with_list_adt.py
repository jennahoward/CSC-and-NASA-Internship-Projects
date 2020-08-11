#Input - numbers for a list
#Processing - Determine the highest number and the lowest number from the
#       given list
#Output - Display the highest number and the lowest number 

def main():
    
    numbers = []
    print('Enter a number (enter -99 to end): ')
    item = float(input())
    highest = item
    lowest = item
    
    while (item != -99):
        numbers.append(item)
        if (item >= highest):
            highest = item
        elif (item <= lowest):
            lowest = item
        item = float(input('Enter a number (enter -99 to end): '))
        
    print('The highest number is: ' + str(highest))
    print('The lowest number is: ' + str(lowest))

main()

