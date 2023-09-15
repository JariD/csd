# To use the time in seconds later in the code
import time 

# Ask the user for input
username = input("Who dis?")
time.sleep(4)
print("Oh.. Hi " , username)
time.sleep(2)
print('Did you know your name is..')
time.sleep(2)
# len checks how many characters the name has
print(len(username), ' characters long?')
yesNo = input('')
time.sleep(2.5)
print(yesNo,"Heh..")
time.sleep(5)
# aks user for age
age = input("How old are you?")
time.sleep(1)
# This is just funny, might want to add a check within a check
print(age, "!?")
time.sleep(3)
input("you sure?")
time.sleep(5)
input("for real?")
time.sleep(1)
print("...")
time.sleep(3)
# Checks the age in string because int gives an error
print("K, if you say you are " + str(age))
time.sleep(2)
# math for checking when user will be 100 years old, here I used a subtraction with int 
#                                          within a precedence and that with string in front
print("That means you will be a centinarian in " + str(100 - int(age)) + " years.")
time.sleep(1)
#Funny ending age check, if age > 100 (could have been easier) then he must be lying right?
ageCheck = 100 - int(age)
if ageCheck < 0:
    time.sleep(3)
    print("Wait.. that means you are either really old.. Or lying to me")
else: print("cool huh?")
time.sleep(3)