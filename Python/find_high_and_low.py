#Input - Any number
#Processing - Determine the highest number and the
#lowest number from the given inputs
#Output - Display the highest number and the lowest number 

def main():
    
    number = 0
    number = float(input('Enter a number (enter -99 to end): '))
    highest = number
    lowest = number
    
    while (number != -99):
        if (number >= highest):
            highest = number
        elif (number <= lowest):
            lowest = number
        number = float(input('Enter a number (enter -99 to end): '))
        
    print('The highest number is: ' + str(highest))
    print('The lowest number is: ' + str(lowest))

main()

