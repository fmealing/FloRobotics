a_string = "this is \n a string\t\tand tabbed"
print(a_string)

raw_string = r"this is \n a string\t\t and tabbed"
print(raw_string)

b_string = "This is" + chr(10) + "a string split" + chr(9) + chr(9) + "and tabbed"
print(b_string)

backslash_string = "this is a backslash \\followed by some text"
print(backslash_string)

error_string = r"this string ends with \\"
print(error_string)
