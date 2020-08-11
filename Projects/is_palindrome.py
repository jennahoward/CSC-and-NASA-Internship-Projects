#Input - A word
#Processing - Determine if the word is a palindrome
#Output - Display if the word is a palindrome or not

import StackADT
import QueueADT

def main():

    palindrome = False
    i = 0
    word = str()
    
    def isPalindrome(word):
        palindrome = False
        comp1 = StackADT.newStack()
        comp2 = QueueADT.newQueue()
        
        i = 0
        letter = word[i]
        
        for letter in word:
            StackADT.push(comp1, letter)
            QueueADT.Enqueue(comp2, letter)
            i = i + 1

        i = 0
        letter = word[i]
        item1 = ''
        item2 = ''
        
        for letter in word:
            item1 = item1 + StackADT.pop(comp1)
            item2 = item2 + QueueADT.Dequeue(comp2)
            i = i + 1

        if (item1 == item2):
            palindrome = True
            return palindrome
        else:
            palindrome = False
            return palindrome
        
    word = str(input('Enter a word, "stop" to end: '))
    while(word != 'stop'):
        if isPalindrome(word):
            print('The word is a palindrome!')
        else:
            print('The word is NOT a palindrome.')
        word = str(input('Enter a word, "stop" to end: '))

main()
