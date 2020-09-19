#Input - height and weight
#Processing - calculate BMI and then use the value of BMI to determine
#if user is at optimal weight (BMI between 18.5 to 25), underweight 
#(less than 18.5), or overweight (greater than 25)
#Output - Print the results describing if the user is over- or under-weight
#or at an optimal weight


def main():

    height = float(input('Enter your height in inches: '))
    weight = float(input('Enter your weight in pounds: '))
    
    def BMI(height, weight):
        BMI = (weight * 703) / (height**2)

        if (BMI < 18.5):
            print('You are underweight')
        elif (BMI > 25):
            print('You are overweight')
        else:
            print('You are at an optimal weight')

    BMI(height, weight)

main()
