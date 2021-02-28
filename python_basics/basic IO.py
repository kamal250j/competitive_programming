#Reading a single variable input
n_int = int(input())
n_string = input()
n_float = float(input())
print(n_int,n_string,n_float)

#Reading an array input separated by spaces
#The map() function takes 2 parameters, another function, and an iterable datatype. (Eg - List)
#The map() function calls another function on each element of the iterable.
#So, here we are using int() function on each element of list
#That would be map(int,[‘1’, ‘2’, ‘3’, ‘4’, ‘5’, ‘6’, ‘7’, ‘8’, ‘9’, ‘10’]).
#That would return us with <map object at 0x105938b38>.
#So, we can simply use the list() function to convert it to a list.
arr = list(map(int, input().split()))
print(arr)

#Reading an array input separated by commas
arr = list(map(int, input().split(',')))
print(arr)

#Reading input into 4 variables separated by spaces
a, b, c, d = map(int, input().split())
print(a,b,c,d)

#For creating array of vectors(lists)
no_of_rows = 2
matrix = [input().split() for i in range(no_of_rows)]
print(matrix)