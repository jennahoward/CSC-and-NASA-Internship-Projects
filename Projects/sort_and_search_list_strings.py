#Input - A name to search the list once sorted
#Processing - Display the unsorted list, sort the list, then search the sorted list for the name input 
#           and display if the name is in the list or not
#Output - The unsorted list, the list sorted, and wheter the name was inlcuded in the list


def main():

    list = ['Paul', 'Aaron', 'Jacob', 'James', 'Bill', 'Sara', 'Cathy', 'Barbara', 'Amy', 'Jill']
    print('The unsorted list: ' + str(list))

    
    current = 1
    i = current
    placeFound = False
    index1 = i
    index2 = i - 1
    temp = list[index1]
    first = 0
    last = len(list) - 1
    middle = (last + first) / 2
    found = False
    target = str

    
    
    def sort(list):
        current = 1
        while (current < len(list)):
            i = current
            placeFound = False
            while (i > 0 and not placeFound):
                if (list[i] < list[i - 1]):
                    swap(list, i, i - 1)
                    i = i - 1
                else:
                    placeFound = True
            current = current + 1
        print('The sorted list: ' + str(list))
            
    def swap(list, index1, index2):
        temp = list[index1]
        list[index1] = list[index2]
        list[index2] = temp

    
    
    def search(list, target):
        target = str(input('Enter a name: '))
        first = 0
        last = len(list) - 1
        found = False
        while (last >= first and not found):
            middle = (last + first) // 2
            if (list[middle] == target):
                found = True
            else:
                if (list[middle] < target):
                    first = middle + 1
                else:   
                    last = middle - 1
        if found:
            print('That name is included in the list.')
        else:
            print('That name is not included in the list.')
        return found

    
    sort(list)

    search(list, target)

main()
